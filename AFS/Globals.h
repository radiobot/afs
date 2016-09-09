// Класс для хранения глобальных данных
#pragma once
#include "Frame.h"

namespace AFS {

	using namespace System::Windows::Forms;

	public ref class Globals
	{

	public:
		// Кадр исходного изображения
		static Frame^ sourcePic;

		// Кадр эталонного фрагмента
		static  Frame^ etalonFrag;

		// Параметры процесса поиска
		static int OLV;

		static int iterNum;

		static String^ pfType;

		// Генератор случайных значений, инициализируется в главном файле MyForm.h
		static Random^ rnd;
	};
}
