#pragma once
#include "Globals.h"

namespace AFS {

	public ref class MIEstimator
	{

	public:
		// Оценки параметров:		
		// Сдвиг по горизонтали
		float hx;
		// Сдвиг по вертикали
		float hy;
		// Угол поворота
		float ang;
		// Масштабирование
		float sc;

		void runEstimation(LocSamp^ lcs)
		{

		}
	};
}