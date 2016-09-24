#pragma once
#include "Globals.h"
#include "LocSamp.h"
#include "Interpolator.h"

namespace AFS {

	public ref class SKMREstimator
	{
	public:

		// Оценки параметров		
		float hx;
		float hy;
		float ang;
		float sc;

		// Матрица усиления
		static float step_hx = 0.04;
		static float step_hy = 0.04;
		static float step_ang = 0.003;
		static float step_scale = 0.001;

		Interpolator^ intp;

		void runEstimation(LocSamp^ lcs)
		{
			intp = gcnew Interpolator();

			//Пcевдоградиент
			float pg_hx = 0;
			float pg_hy = 0;
			float pg_ang = 0;
			float pg_sc = 0;

			for (int m = 0; m < Globals::OLV; m++)
			{

				float iLeft = safe_cast<float>(intp->getIntpVal(Globals::etalonFrag->intnsVls,
																lcs->etCrd[m].X - 1, lcs->etCrd[m].Y));

				float iRight = safe_cast<float>(intp->getIntpVal(Globals::etalonFrag->intnsVls,
																 lcs->etCrd[m].X + 1, lcs->etCrd[m].Y));

				float iTop = safe_cast<float>(intp->getIntpVal(Globals::etalonFrag->intnsVls,
															   lcs->etCrd[m].X - 1, lcs->etCrd[m].Y - 1));

				float iBottom = safe_cast<float>(intp->getIntpVal(Globals::etalonFrag->intnsVls,
																  lcs->etCrd[m].X - 1, lcs->etCrd[m].Y + 1));

				float iCenter = safe_cast<float>(intp->getIntpVal(Globals::etalonFrag->intnsVls,
																  lcs->etCrd[m].X, lcs->etCrd[m].Y));

				float dQ_hx = (iCenter - safe_cast<float>(lcs->srcVals[m])) * (iRight - iLeft);
				float dQ_hy = (iCenter - safe_cast<float>(lcs->srcVals[m])) * (iBottom - iTop);

				float dQ_ang_X = -(Math::Sin(ang) * (lcs->srcCrd[m].X - Globals::etalonFrag->cntr.X) 
							   + Math::Cos(ang) * (lcs->srcCrd[m].Y - Globals::etalonFrag->cntr.Y));

				float dQ_ang_Y = Math::Cos(ang) * (lcs->srcCrd[m].X - Globals::etalonFrag->cntr.X) 
							   - Math::Sin(ang) * (lcs->srcCrd[m].Y - Globals::etalonFrag->cntr.Y);
				
				float dQ_ang = (iCenter - safe_cast<float>(lcs->srcVals[m]))
							 * ((iRight - iLeft) * dQ_ang_X 
							 + (iBottom - iTop) * dQ_ang_Y);

				float dQ_sc_X = Math::Cos(ang) * (lcs->srcCrd[m].X - Globals::etalonFrag->cntr.X) 
							   - Math::Sin(ang) * (lcs->srcCrd[m].Y - Globals::etalonFrag->cntr.Y);

				float dQ_sc_Y = Math::Sin(ang) * (lcs->srcCrd[m].X - Globals::etalonFrag->cntr.X) 
							   + Math::Cos(ang) * (lcs->srcCrd[m].Y - Globals::etalonFrag->cntr.Y);

				float dQ_sc = (iCenter - safe_cast<float>(lcs->srcVals[m])) 
							 * ((iRight - iLeft) * dQ_sc_X 
							 + (iBottom - iTop) * dQ_sc_Y);

				pg_hx += dQ_hx;
				pg_hy += dQ_hy;
				pg_ang += dQ_ang;
				pg_sc += dQ_sc;
			}

			hx -= Math::Sign(pg_hx) * step_hx;
			hy -= Math::Sign(pg_hy) * step_hy;
			ang -= Math::Sign(pg_ang) * step_ang;
			sc -= Math::Sign(pg_sc) * step_scale;
		}

	};
}