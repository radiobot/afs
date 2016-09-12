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
			numItDistr = gcnew array<int>(node->ttlNodeCnt);
			pFValDistr = gcnew array<double>(node->ttlNodeCnt);
			numItDistrRanged = gcnew array<int>(node->ttlNodeCnt);
			pFValDistrRanged = gcnew array<double>(node->ttlNodeCnt);
			hxVals = gcnew vector<double>();
			hyVals = gcnew vector<double>();
		}

	public:

		// ���� ������:
		// ���������� ��������
		array<int>^ numItDistr;

		// �������� ��
		array<double>^ pFValDistr;

		// ��������������� �������� ���������� ��������
		array<int>^ numItDistrRanged;

		// ��������������� �������� ��
		array<double>^ pFValDistrRanged;

		// ������� �������� ������ ���������� ��� V-���
		vector<double> hxVals;
		vector<double> hyVals;

		// ���������:
		// ��������� ������ �� ����� ���
		void getGridData(Grid^ node)
		{

		}

		// ���������� ����������� ������� �� ��������
		void rangeArrays()
		{

		}
	};
}