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

			// Массив значений яркости
			array<double, 2>^ intnsVals;

			// Интерполяция билинейная
			Interpolator^ intp;

			// Локальная выборка
			LocSamp^ lcs;

			// Количество итераций
			int itNum;

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

			}

			// Вычисление значения ФП
			void getPFValue()
			{

			}
	};
}