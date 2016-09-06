// Класс для управления вводом данных
#pragma once
#include "Frame.h"
#include "Globals.h"
#include "Deformator.h"
#include "locationParams.h"

namespace AFS {

	using namespace System::Windows::Forms;

	public ref class DataLoader
	{

	public:

		// Загрузка кадра исходного изображения
		void getSourceImage(PictureBox^ pBox)
		{
			Globals::sourcePic = gcnew Frame();
			Globals::sourcePic->getPicFile();
			Globals::sourcePic->getFrmPrms();
			Globals::sourcePic->cnvPicAr();
			pBox->Image = Globals::sourcePic->img;
		}

		// Загрузка кадра эталонного фрагмента
		void getEtalonFragment(PictureBox^ pBox)
		{
			Globals::etalonFrag = gcnew Frame();
			Globals::etalonFrag->getPicFile();
			Globals::etalonFrag->getFrmPrms();
			Globals::etalonFrag->cnvPicAr();
			Deformator^ dfr = gcnew Deformator(Globals::etalonFrag);
			if(dfr->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Globals::etalonFrag = dfr->defIm;
			}
			pBox->Image = Globals::etalonFrag->img;
		}

		// Получение параметров процесса поиска
		void getLocationParams()
		{
			locationParams^ locp = gcnew locationParams();
			if(locp->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Globals::OLV = 
			}
		}
	};
}
