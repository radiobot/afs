#pragma once
#include "Globals.h"
#include "Interpolator.h"
#include "LocSamp.h"
#include "SKMREstimator.h"
#include "VKMKEstimator.h"
#include "MIEstimator.h"
#include "SKMRCalculator.h"
#include "VKMKCalculator.h"
#include "MICalculator.h"
#include <cliext\vector>
using namespace cliext;

namespace AFS {

	public ref class PGP
	{
		public:
			PGP()
			{
				intp = gcnew Interpolator();
				lcs = gcnew LocSamp();
				hxVals = gcnew vector<double>();
				hyVals = gcnew vector<double>();
			}

		public:

			// ������������ ����������
			Interpolator^ intp;
			// ��������� �������
			LocSamp^ lcs;

			// ������� ������ ����������
			vector<double> hxVals;
			vector<double> hyVals;

			// ������ �������� �������
			array<double, 2>^ intnsVals;

			// ���������� ��������
			double itNum;
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
				itNum++;
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
				String^ obFunc = Globals::pfType;
				if (obFunc == "����")
				{
					// ������� ������ ��������
					SKMREstimator^ skEst = gcnew SKMREstimator();

					// �������� �������� ��������� ������� �� ������� ��������
					// ����� ���������� �������� � ��������� ������ �
				    // ��������� �������� ������ �� ������� ��������
					skEst->runEstimation(lcs);

					// �������� �������� ������ ������� ���
					hx += skEst->hx;
					hy += skEst->hy;
					ang += skEst->ang;
					sc += skEst->sc;
				}
				else if (obFunc == "����")
				{
					VKMKEstimator^ vkEst = gcnew VKMKEstimator();
					vkEst->runEstimation(lcs);

					hx += vkEst->hx;
					hy += vkEst->hy;
					ang += vkEst->ang;
					sc += vkEst->sc;
				}
				else
				{
					MIEstimator^ miEst = gcnew MIEstimator();

					miEst->runEstimation(lcs);

					hx += miEst->hx;
					hy += miEst->hy;
					ang += miEst->ang;
					sc += miEst->sc;
				}
				hxVals.push_back(hx);
				hyVals.push_back(hy);
			}

			// ���������� �������� ��
			void getPFValue()
			{
				String^ priorFunc = Globals::pfType;
				if (priorFunc == "����")
				{
					// ������� ������ ��������
					SKMRCalculator^ skpf = gcnew SKMRCalculator();

					// �������� �������� ��������� ������� �� ������� ��������
					// ����� ���������� �������� � ��������� ������ �
					// ��������� �������� ������ �� ������� ��������
					pF += skpf->getSKMR(lcs);

				}
				else if (priorFunc == "����")
				{
					VKMKCalculator^ vkpf = gcnew VKMKCalculator();
					pF += vkpf->getVKMK(lcs);
				}
				else
				{
					MICalculator^ mipf = gcnew MICalculator();
					pF += mipf->getMI(lcs);
				}
			}
	};
}