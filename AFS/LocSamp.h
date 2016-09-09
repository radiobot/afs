#pragma once
#include "Globals.h"

namespace AFS {

	using namespace System::Drawing;

	public ref class LocSamp
	{
		public:
			LocSamp()
			{
				srcCrd = gcnew array<Point>(Globals::OLV);
				etCrd = gcnew array<PointF>(Globals::OLV);
				srcVals = gcnew array<double>(Globals::OLV);
				etVals = gcnew array<double>(Globals::OLV);
			}

		public:

			// координаты точек на исходном изображении
			array<Point>^ srcCrd;

			// координаты точек на эталонном фрагменте
			array<PointF>^ etCrd;

			// значени€ €ркости в точках на исходном изображении
			array<double>^ srcVals;

			// значени€ €ркости в точках на эталонном фрагменте
			array<double>^ etVals;
		
	};
}