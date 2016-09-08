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
				hx = gcnew vector<double>();
				hy = gcnew vector<double>();
				ang = gcnew vector<double>();
				sc = gcnew vector<double>();
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
			double pFVal;

			// Векторы оценок параметров:
			
			// Сдвига по горизонтали
			vector<double> hx;

			// Сдвига по вертикали
			vector<double> hy;

			// Угла поворота
			vector<double> ang;

			// Масштабирования
			vector<double> sc;

			/*
			
			- Выполнение итерации:
				- Заполнение локальной выборки;
				- Оценивание параметров;
				- Вычисление ФП;

			*/

	};
}