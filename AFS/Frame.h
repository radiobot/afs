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
		// Данные
		// Объект изображения - Bitmap:
		Bitmap^ img;

		// Массив значений яркости изображения:
		array<double, 2>^ intnsVls;

		// Геометрические характеристики кадра:
		// Длина и ширина:
		Point sz;
		
		// Координаты центра кадра:
		PointF cntr;

		// Методы
		
		// Выбор файла изображения на жестком диске
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

		// Считывание характеристик кадра изображения
		void getFrmPrms()
		{
			sz.X = img->Width;
			sz.Y = img->Height;

			cntr.X = safe_cast<float>((sz.X - 1)) / 2;
			cntr.Y = safe_cast<float>((sz.Y - 1)) / 2;
		}

		// Конвертация из объекта Bitmap в массив значений яркости и наоборот
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


