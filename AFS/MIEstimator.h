#pragma once
#include "Globals.h"

namespace AFS {

	public ref class MIEstimator
	{

	public:
		// ������ ����������:		
		// ����� �� �����������
		float hx;
		// ����� �� ���������
		float hy;
		// ���� ��������
		float ang;
		// ���������������
		float sc;

		void runEstimation(LocSamp^ lcs)
		{

		}
	};
}