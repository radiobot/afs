#pragma once
#include "Globals.h"
#include <cliext\vector>
using namespace cliext;
#include "PlotCanvas.h"
#include "OutDataCollector.h"

namespace AFS {

	public ref class Plotter
	{
	public:
		Plotter()
		{
			pc = gcnew PlotCanvas();
		}

	public:
		PlotCanvas^ pc;
		/*
			1. ���������� "�������" ��� ��������
			2. ��������� ����������
			3. ��������� ��������
			4. ��������� ���� ��������� � ����� �������� ���� �� �����
		*/

	};
}