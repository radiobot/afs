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

			// Интерполяция билинейная
			Interpolator^ intp;
			// Локальная выборка
			LocSamp^ lcs;

			// векторы оценок параметров
			vector<double> hxVals;
			vector<double> hyVals;

			// Массив значений яркости
			array<double, 2>^ intnsVals;

			// Количество итераций
			double itNum;
			// Значение ФП
			double pF;

			// Векторы оценок параметров:		
			// Сдвиг по горизонтали
			float hx;
			// Сдвиг по вертикали
			float hy;
			// Угол поворота
			float ang;
			// Масштабирование
			float sc;

			// Выполнение итерации:
			void runIteration()
			{
				getLocSamp();
				getEstims();
				getPFValue();
				itNum++;
			}

			// Заполнение локальной выборки
			void getLocSamp()
			{
				for (int m = 0; m < Globals::OLV; m++)
				{
					// Получение координат точек из исходного изображения
					lcs->srcCrd[m].X = Globals::rnd->Next(Globals::etalonFrag->sz.X);
					lcs->srcCrd[m].Y = Globals::rnd->Next(Globals::etalonFrag->sz.Y);

					// Получение значения яркости точки из исходного изображения
					lcs->srcVals[m] = intnsVals[lcs->srcCrd[m].X, lcs->srcCrd[m].Y];

					// Вычисление координат точек эталонного фрагмента
					lcs->etCrd[m].X = safe_cast<float>(lcs->srcCrd[m].X) + hx;
					lcs->etCrd[m].Y = safe_cast<float>(lcs->srcCrd[m].Y) + hy;

					// Вычисление значения яркости точки эталонного фрагмента
					lcs->etVals[m] = intp->getIntpVal(Globals::etalonFrag->intnsVls, 
													  lcs->etCrd[m].X, lcs->etCrd[m].Y);
				}
				
			}
			
			// Оценивание параметров
			void getEstims()
			{	
				String^ obFunc = Globals::pfType;
				if (obFunc == "СКМР")
				{
					// Создать объект оценщика
					SKMREstimator^ skEst = gcnew SKMREstimator();

					// Получить значения локальной выборки на текущей итерации
					// через формальный параметр в заголовке метода и
				    // вычислить значения оценок на текущей итерации
					skEst->runEstimation(lcs);

					// Передать значения оценок объекту ПГП
					hx += skEst->hx;
					hy += skEst->hy;
					ang += skEst->ang;
					sc += skEst->sc;
				}
				else if (obFunc == "ВКМК")
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

			// Вычисление значения ФП
			void getPFValue()
			{
				String^ priorFunc = Globals::pfType;
				if (priorFunc == "СКМР")
				{
					// Создать объект оценщика
					SKMRCalculator^ skpf = gcnew SKMRCalculator();

					// Получить значения локальной выборки на текущей итерации
					// через формальный параметр в заголовке метода и
					// вычислить значения оценок на текущей итерации
					pF += skpf->getSKMR(lcs);

				}
				else if (priorFunc == "ВКМК")
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