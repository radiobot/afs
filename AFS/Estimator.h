#pragma once
#include "Globals.h"

namespace AFS {

	public ref class Estimator
	{
	public:
		Estimator()
		{

		}

	public:

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
		void runEstimation()
		{

		}

		
	};
}