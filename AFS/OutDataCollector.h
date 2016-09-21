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
			numItDistr = gcnew array<double>(node->ttlNodeCnt);
			pFValDistr = gcnew array<double>(node->ttlNodeCnt);
			numItDistrRanged = gcnew array<double>(node->ttlNodeCnt);
			pFValDistrRanged = gcnew array<double>(node->ttlNodeCnt);
			hxVals = gcnew vector<double>();
			hyVals = gcnew vector<double>();
			angVals = gcnew vector<double>();
			scVals = gcnew vector<double>();
		}

	public:

		// Сбор данных:
		// Количество итераций
		array<double>^ numItDistr;

		// Значения ФП
		array<double>^ pFValDistr;

		// Отранжированные значения количества итераций
		array<double>^ numItDistrRanged;

		// Отранжированные значения ФП
		array<double>^ pFValDistrRanged;

		// Векторы значений оценок параметров для V-ПГП
		vector<double> hxVals;
		vector<double> hyVals;
		vector<double> angVals;
		vector<double> scVals;

		// Обработка:
		// Получение данных из сетки ПГП
		void getGridData(Grid^ node)
		{
			for (int z = 0; z < node->grSz.X; z++)
			{
				for (int k = 0; k < node->grSz.Y; k++)
				{
					pFValDistr[k + z * node->grSz.Y] = node->node[z, k]->pF;
					numItDistr[k + z * node->grSz.Y] = node->node[z, k]->itNum;
				}
			}
		}

		// Сортировка одномерного массива по убыванию
		void getRangedArray(array<double>^ mas, array<double>^ rmas)
		{
			double temp;

			mas->CopyTo(rmas, 0);

			for (int i = 0; i < rmas->GetLength(0) - 1; i++)
			{
				for (int j = i + 1; j < rmas->GetLength(0); j++)
				{
					if (rmas[i] < rmas[j])
					{
						temp = rmas[i];
						rmas[i] = rmas[j];
						rmas[j] = temp;
					}
				}
			}
		}

		void getOutData(Grid^ node)
		{
			getGridData(node);
			getRangedArray(pFValDistr, pFValDistrRanged);
			getRangedArray(numItDistr, numItDistrRanged);
			hxVals = node->node[node->verIndex.X, node->verIndex.Y]->hxVals;
			hyVals = node->node[node->verIndex.X, node->verIndex.Y]->hyVals;
			angVals = node->node[node->verIndex.X, node->verIndex.Y]->angVals;
			scVals = node->node[node->verIndex.X, node->verIndex.Y]->scVals;
		}

	};
}