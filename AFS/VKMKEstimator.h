#pragma once
#include "Globals.h"

namespace AFS {

	public ref class VKMKEstimator
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