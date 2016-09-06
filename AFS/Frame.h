#pragma once
#include "MasPicConvn.h"

namespace AFS
{
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class Frame
	{
	public:
		// ������
		// ������ ����������� - Bitmap:
		Bitmap^ img;

		// ������ �������� ������� �����������:
		array<double, 2>^ intnsVls;

		// �������������� �������������� �����:
		// ����� � ������:
		Point sz;
		
		// ���������� ������ �����:
		PointF cntr;

		// ������
		
		// ����� ����� ����������� �� ������� �����
		void getPicFile()
		{
			OpenFileDialog^  opnFlDlg;
			DialogResult^ dlgRslt;

			opnFlDlg = gcnew OpenFileDialog();
			opnFlDlg->Filter = "Image files|*.jpg; *.bmp; *.tiff; *.png";
			dlgRslt = DialogResult::OK;
			if (opnFlDlg->ShowDialog() == DialogResult::OK)
			{
				img = gcnew Bitmap(opnFlDlg->FileName);
			}
		}

		// ���������� ������������� ����� �����������
		void getFrmPrms()
		{
			sz.X = img->Width;
			sz.Y = img->Height;

			cntr.X = safe_cast<float>((sz.X - 1)) / 2;
			cntr.Y = safe_cast<float>((sz.Y - 1)) / 2;
		}

		// ����������� �� ������� Bitmap � ������ �������� ������� � ��������
		void cnvArPic()
		{
			MasPicConvn^ mpconvr = gcnew MasPicConvn(img);
			img = mpconvr->MasToPic(intnsVls);
		}

		void cnvPicAr()
		{
			MasPicConvn^ pmconvr = gcnew MasPicConvn(img);
			intnsVls = pmconvr->PicToMas();
		}

	};
}


