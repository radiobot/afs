#pragma once
#include "PGP.h"
#include "VerIndexCalculator.h"

namespace AFS {

	public ref class Grid
	{
	public:
		Grid()
		{
			vic = gcnew VerIndexCalculator();
		}

	public:
		
		// ������ �������� ���
		array<PGP^, 2>^ node;

		// ����� ����� ����� �����
		int ttlNodeCnt;

		// ���������� ����� ����� �� ����������� (X) � ��������� (Y)
		Point grSz;

		// ������������� ����� ���
		void initGrid()
		{
			// ���������� ������� �����
			grSz.X = Globals::sourcePic->sz.X / Globals::etalonFrag->sz.X;
			grSz.Y = Globals::sourcePic->sz.Y / Globals::etalonFrag->sz.Y;

			ttlNodeCnt = grSz.X * grSz.Y;

			// ������������� ������� ��� �� �����
			node = gcnew array<PGP^, 2>(grSz.X, grSz.Y);

			// ������������� ��� � ������ ���� �����
			for (int i = 0; i < grSz.X; i++)
			{
				for (int j = 0; j < grSz.Y; j++)
				{
					node[i, j] = gcnew PGP();
					node[i, j]->intnsVals = gcnew array<double, 2>(Globals::etalonFrag->sz.X, Globals::etalonFrag->sz.Y);

					// ���������� ������� �������� ������� ������ ���
					Point srcIndx;
					for (int u = 0; u < Globals::etalonFrag->sz.X; u++)
					{
						for (int v = 0; v < Globals::etalonFrag->sz.Y; v++)
						{
							srcIndx.X = u + i * Globals::etalonFrag->sz.X;
							srcIndx.Y = v + j * Globals::etalonFrag->sz.Y;
							node[i, j]->intnsVals[u, v] = Globals::sourcePic->intnsVls[srcIndx.X, srcIndx.Y];
						}
					}
				}
			}
		}

		// ������ "��������" ���������
		Point verIndex;

		// ������ ������ ��� ���������� ������� "��������" ��� �� ������� ��������
		VerIndexCalculator^ vic;

		// ��������� ����� ���� ����� c ����������� ������� ����������
		void primaryGridBypass()
		{
			for (int i = 0; i < grSz.X; i++)
			{
				for (int j = 0; j < grSz.Y; j++)
				{
					node[i, j]->runIteration();
				}
			}
			verIndex.X = vic->getVeritasIndex(node).X;
			verIndex.Y = vic->getVeritasIndex(node).Y;
		}

		// ����������� "��������" ��������� �� ������������������ �����
		void detectVeritasPGP()
		{
			for (int t = 0; t < Globals::iterNum; t++)
			{
				node[verIndex.X, verIndex.Y]->runIteration();

				verIndex.X = vic->getVeritasIndex(node).X;
				verIndex.Y = vic->getVeritasIndex(node).Y;
			}

			verIndex.X = vic->getMaxIterIndex(node).X;
			verIndex.Y = vic->getMaxIterIndex(node).Y;
		}

		// ����� "��������" ���������
		void getVeritasPGP()
		{
			initGrid();
			primaryGridBypass();
			detectVeritasPGP();
		}

	};
}