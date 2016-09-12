#pragma once
#include "Globals.h"
#include "Grid.h"
#include <cliext\vector>
using namespace cliext;

namespace AFS {

	public ref class OutDataCollector
	{
	public:
		OutDataCollector(Grid^ node)
		{
			numItDistr = gcnew array<int>(node->ttlNodeCnt);
			pFValDistr = gcnew array<double>(node->ttlNodeCnt);
			numItDistrRanged = gcnew array<int>(node->ttlNodeCnt);
			pFValDistrRanged = gcnew array<double>(node->ttlNodeCnt);
			hxVals = gcnew vector<double>();
			hyVals = gcnew vector<double>();
		}

	public:

		// Сбор данных:
		// Количество итераций
		array<int>^ numItDistr;

		// Значения ФП
		array<double>^ pFValDistr;

		// Отранжированные значения количества итераций
		array<int>^ numItDistrRanged;

		// Отранжированные значения ФП
		array<double>^ pFValDistrRanged;

		// Векторы значений оценок параметров для V-ПГП
		vector<double> hxVals;
		vector<double> hyVals;

		// Обработка:
		// Получение данных из сетки ПГП
		void getGridData(Grid^ node)
		{

		}

		// Сортировка одномерного массива по убыванию
		void rangeArrays()
		{

		}
	};
}