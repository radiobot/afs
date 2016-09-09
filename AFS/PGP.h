#pragma once
#include "Globals.h"
#include "Interpolator.h"
#include "LocSamp.h"
#include <cliext/vector>
using namespace cliext;

namespace AFS {

	public ref class PGP
	{
		public:
			PGP()
			{
				intp = gcnew Interpolator();
				lcs = gcnew LocSamp();
			}

		public:

			// ������ �������� �������
			array<double, 2>^ intnsVals;

			// ������������ ����������
			Interpolator^ intp;

			// ��������� �������
			LocSamp^ lcs;

			// ���������� ��������
			int itNum;

			// �������� ��
			double pF;

			// ������� ������ ����������:
			
			// ����� �� �����������
			float hx;

			// ����� �� ���������
			float hy;

			// ���� ��������
			float ang;

			// ���������������
			float sc;

			// ���������� ��������:
			void runIteration()
			{
				getLocSamp();
				getEstims();
				getPFValue();
			}

			// ���������� ��������� �������
			void getLocSamp()
			{
				for (int m = 0; m < Globals::OLV; m++)
				{
					// ��������� ��������� ����� �� ��������� �����������
					lcs->srcCrd[m].X = Globals::rnd->Next(Globals::etalonFrag->sz.X);
					lcs->srcCrd[m].Y = Globals::rnd->Next(Globals::etalonFrag->sz.Y);

					// ��������� �������� ������� ����� �� ��������� �����������
					lcs->srcVals[m] = intnsVals[lcs->srcCrd[m].X, lcs->srcCrd[m].Y];

					// ���������� ��������� ����� ���������� ���������
					lcs->etCrd[m].X = safe_cast<float>(lcs->srcCrd[m].X) + hx;
					lcs->etCrd[m].Y = safe_cast<float>(lcs->srcCrd[m].Y) + hy;

					// ���������� �������� ������� ����� ���������� ���������
					lcs->etVals[m] = intp->getIntpVal(Globals::etalonFrag->intnsVls, 
													  lcs->etCrd[m].X, lcs->etCrd[m].Y);
				}
				
			}
			
			// ���������� ����������
			void getEstims()
			{

			}

			// ���������� �������� ��
			void getPFValue()
			{

			}
	};
}