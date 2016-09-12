#pragma once
#include "Globals.h"
#include "PGP.h"

namespace AFS {

	public ref class VerIndexCalculator
	{

	public:
		Point getVeritasIndex(array<PGP^,2>^ grid)
		{
			Point VerIndex;

			if (Globals::pfType == "ัสฬะ")
			{
				VerIndex.X = getMinIndex(grid).X;
				VerIndex.Y = getMinIndex(grid).Y;
			}
			else 
			{
				VerIndex.X = getMaxIndex(grid).X;
				VerIndex.Y = getMaxIndex(grid).Y;
			}

			return VerIndex;
		}

		Point getMaxIndex(array<PGP^, 2>^ grid)
		{
			Point max;
			double maxVal = grid[0, 0]->pF;
			for (int i = 0; i < grid->GetLength(0); i++)
			{
				for (int j = 0; j < grid->GetLength(1); j++)
				{
					if (grid[i, j]->pF > maxVal)
					{
						max.X = i;
						max.Y = j;
						maxVal = grid[i, j]->pF;
					}
				}
			}
			return max;
		}

		Point getMinIndex(array<PGP^, 2>^ grid)
		{
			Point min;
			double minVal = grid[0, 0]->pF;
			for (int i = 0; i < grid->GetLength(0); i++)
			{
				for (int j = 0; j < grid->GetLength(1); j++)
				{
					if (grid[i, j]->pF < minVal)
					{
						min.X = i;
						min.Y = j;
						minVal = grid[i, j]->pF;
					}
				}
			}
			return min;
		}

		Point getMaxIterIndex(array<PGP^, 2>^ grid)
		{
			Point max;
			double maxVal = grid[0, 0]->itNum;
			for (int i = 0; i < grid->GetLength(0); i++)
			{
				for (int j = 0; j < grid->GetLength(1); j++)
				{
					if (grid[i, j]->itNum > maxVal)
					{
						max.X = i;
						max.Y = j;
						maxVal = grid[i, j]->itNum;
					}
				}
			}
			return max;
		}

	};
}