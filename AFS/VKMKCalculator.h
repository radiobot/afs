#pragma once
#include "LocSamp.h"

namespace AFS {

	public ref class VKMKCalculator
	{
	public:

		double getVKMK(LocSamp^ lcs)
		{
			double PF = 0;

			for (int m = 0; m < Globals::OLV; m++)
			{
				double dif = lcs->etVals[m] - lcs->srcVals[m];
				PF += Math::Pow(dif, 2) / Globals::OLV;

			}

			return PF;
		}

	};
}