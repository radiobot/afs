#pragma once
#include "Globals.h"
#include "Interpolator.h"
#include "LocSamp.h"
#include <cliext/vector>
using namespace cliext;

namespace AFS {

	public ref class PGP
	{
		public:
			PGP()
			{
				hx = gcnew vector<double>();
				hy = gcnew vector<double>();
				ang = gcnew vector<double>();
				sc = gcnew vector<double>();
				intp = gcnew Interpolator();
				lcs = gcnew LocSamp();
			}

		public:

			// ������ �������� �������
			array<double, 2>^ intnsVals;

			// ������������ ����������
			Interpolator^ intp;

			// ��������� �������
			LocSamp^ lcs;

			// ���������� ��������
			int itNum;

			// �������� ��
			double pFVal;

			// ������� ������ ����������:
			
			// ������ �� �����������
			vector<double> hx;

			// ������ �� ���������
			vector<double> hy;

			// ���� ��������
			vector<double> ang;

			// ���������������
			vector<double> sc;

			/*
			
			- ���������� ��������:
				- ���������� ��������� �������;
				- ���������� ����������;
				- ���������� ��;

			*/

	};
}