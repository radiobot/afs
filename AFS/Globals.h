// ����� ��� �������� ���������� ������
#pragma once
#include "Frame.h"

namespace AFS {

	using namespace System::Windows::Forms;

	public ref class Globals
	{

	public:
		// ���� ��������� �����������
		static Frame^ sourcePic;

		// ���� ���������� ���������
		static  Frame^ etalonFrag;

		// ��������� �������� ������
		static int OLV;

		static int iterNum;

		static String^ pfType;

		// ��������� ��������� ��������, ���������������� � ������� ����� MyForm.h
		static Random^ rnd;
	};
}
