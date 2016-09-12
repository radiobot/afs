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

			// ���������� ����� �� �������� �����������
			array<Point>^ srcCrd;

			// ���������� ����� �� ��������� ���������
			array<PointF>^ etCrd;

			// �������� ������� � ������ �� �������� �����������
			array<double>^ srcVals;

			// �������� ������� � ������ �� ��������� ���������
			array<double>^ etVals;
		
	};
}