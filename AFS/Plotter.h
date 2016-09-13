#pragma once
#include "Globals.h"
#include <cliext\vector>
using namespace cliext;
#include "PlotCanvas.h"
#include "OutDataCollector.h"

namespace AFS {

	public ref class Plotter
	{
	public:
		Plotter()
		{
			pc = gcnew PlotCanvas();
		}

	public:
		PlotCanvas^ pc;
		/*
			1. Подготовка "холстов" для графиков
			2. Отрисовка гистограмм
			3. Отрисовка графиков
			4. Отрисовка всех элементов и вывод главного окна на экран
		*/

	};
}