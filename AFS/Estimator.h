#pragma once
#include "Globals.h"

namespace AFS {

	public ref class Estimator
	{
	public:
		Estimator()
		{

		}

	public:

		// ������� ������ ����������:		
		// ����� �� �����������
		float hx;
		// ����� �� ���������
		float hy;
		// ���� ��������
		float ang;
		// ���������������
		float sc;

		// ���������� ��������:
		void runEstimation()
		{

		}

		
	};
}