#pragma once

namespace AFS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class MasPicConvn
    {
		public: MasPicConvn(Bitmap^ source)
		{
			this->source = source;
		}

		public: Bitmap^ source;
				IntPtr Iptr;

				System::Drawing::Imaging::BitmapData^ bmpData;

				array<Byte>^ Pixels;

				int Depth;
				int Width;
				int Height;

			// Заблокировать данные bitmap
	
		public: void LockBits()
		{
			try
			{
				// Получить ширину и высоту bitmap 
				Width = source->Width;
				Height = source->Height;

				// Получить полное количество всех заблокированных пикселей
				int PixelCount = Width * Height;

				// Получить прямоугольник rectangle для блокировки
				Rectangle rect = Rectangle(0, 0, Width, Height);

				// Получить размер формата пикселей исходного bitmap (pixel format size)
				Depth = System::Drawing::Bitmap::GetPixelFormatSize(source->PixelFormat);

				// Проверить глубину цвета(количество битов на один пиксель) - 8, 24, или 32
				if (Depth != 8 && Depth != 24 && Depth != 32)
				{
					throw gcnew ArgumentException("Поддерживаются только изображения с 8, 24 и 32 bpp.");
				}

				// Заблокировать bitmap и вернуть bitmap data
				bmpData = source->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite,
					source->PixelFormat);

				// Создать массив элементов byte для копирования значений пикселей
				int step = Depth / 8;
				Pixels = gcnew array<Byte>(PixelCount * step);
				Iptr = bmpData->Scan0;

				// Копировать данные из указателя в массив
				System::Runtime::InteropServices::Marshal::Copy(Iptr, Pixels, 0, Pixels->Length);
			}
			catch (Exception^ ex)
			{
				throw ex;
			}
		}
	
			// Разблокировать данные bitmap

		public: void UnlockBits()
		{
			try
			{
				// Копировать данные из массива байтов в указатель
				System::Runtime::InteropServices::Marshal::Copy(Pixels, 0, Iptr, Pixels->Length);

				// Разблокировать bitmap data
				source->UnlockBits(bmpData);
			}
			catch (Exception^ ex)
			{
				throw ex;
			}
		}
		
			// Получить цвет указанного пикселя
			
		public: Color GetPixel(int x, int y)
		{
			Color clr = Color::Empty;

			// Получить количество компонент цвета
			int cCount = Depth / 8;

			// Получить начальный индекс указанного пикселя
			int i = ((y * Width) + x) * cCount;

			if (i > Pixels->Length - cCount)
				throw gcnew IndexOutOfRangeException();

			if (Depth == 32) // Получить значения Red, Green, Blue и Alpha для 32-битного изображения
			{
				Byte b = Pixels[i];
				Byte g = Pixels[i + 1];
				Byte r = Pixels[i + 2];
				Byte a = Pixels[i + 3]; // a
				clr = Color::FromArgb(a, r, g, b);
			}
			if (Depth == 24) // Получить значения Red, Green и Blue для 24-битного изображения
			{
				Byte b = Pixels[i];
				Byte g = Pixels[i + 1];
				Byte r = Pixels[i + 2];
				clr = Color::FromArgb(r, g, b);
			}
			if (Depth == 8)
				// Получить значения цвета для 8-битного изображения(Значения Red, Green и Blue одинаковы)
			{
				Byte c = Pixels[i];
				clr = Color::FromArgb(c, c, c);
			}
			return clr;
		}

		
		public: void SetPixel(int x, int y, Color color)
		{
			// Получить число компонент цвета
			int cCount = Depth / 8;

			// Получить начальный индекс указанного пикселя
			int i = ((y * Width) + x) * cCount;

			if (Depth == 32) // Установить значения компонент Red, Green, Blue и Alpha для 32-битного изображения
			{
				Pixels[i] = color.B;
				Pixels[i + 1] = color.G;
				Pixels[i + 2] = color.R;
				Pixels[i + 3] = color.A;
			}
			if (Depth == 24) // Установить значения компонент Red, Green и Blue для 24-битного изображения
			{
				Pixels[i] = color.B;
				Pixels[i + 1] = color.G;
				Pixels[i + 2] = color.R;
			}
			if (Depth == 8) // Установить значения цвета для 8-битного изображения (значения Red, Green и Blue одинаковы)
			{
				Pixels[i] = color.B;
			}
		}

		
		public: array<double,2>^ PicToMas()
		{
			LockBits();
			Point N;
			N.X = source->Width;
			N.Y = source->Height;
			array<double, 2>^ mas = gcnew array<double,2>(N.X, N.Y);
			for (int i = 0; i < N.X; i++)
			{
				for (int j = 0; j < N.Y; j++)
				{
					Color clr = GetPixel(i, j);
					mas[i, j] = 0.299*clr.R + 0.587*clr.G + 0.114*clr.B;
				}
			}
			UnlockBits();
			return mas;
		}
		
		public: Bitmap^ MasToPic(array<double,2>^ mas)
		{
			Point N;
			N.X = mas->GetLength(0);
			N.Y = mas->GetLength(1);
			LockBits();
			for (int i = 0; i < N.X; i++)
			{
				for (int j = 0; j < N.Y; j++)
				{
					int d = safe_cast<int>(Math::Ceiling(mas[i, j]));
					SetPixel(i, j, Color::FromArgb(d, d, d));
				}
			}
			UnlockBits();
			return source;
		}
    
	};
}