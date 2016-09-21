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

			// ������������� ������ bitmap
	
		public: void LockBits()
		{
			try
			{
				// �������� ������ � ������ bitmap 
				Width = source->Width;
				Height = source->Height;

				// �������� ������ ���������� ���� ��������������� ��������
				int PixelCount = Width * Height;

				// �������� ������������� rectangle ��� ����������
				Rectangle rect = Rectangle(0, 0, Width, Height);

				// �������� ������ ������� �������� ��������� bitmap (pixel format size)
				Depth = System::Drawing::Bitmap::GetPixelFormatSize(source->PixelFormat);

				// ��������� ������� �����(���������� ����� �� ���� �������) - 8, 24, ��� 32
				if (Depth != 8 && Depth != 24 && Depth != 32)
				{
					throw gcnew ArgumentException("�������������� ������ ����������� � 8, 24 � 32 bpp.");
				}

				// ������������� bitmap � ������� bitmap data
				bmpData = source->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite,
					source->PixelFormat);

				// ������� ������ ��������� byte ��� ����������� �������� ��������
				int step = Depth / 8;
				Pixels = gcnew array<Byte>(PixelCount * step);
				Iptr = bmpData->Scan0;

				// ���������� ������ �� ��������� � ������
				System::Runtime::InteropServices::Marshal::Copy(Iptr, Pixels, 0, Pixels->Length);
			}
			catch (Exception^ ex)
			{
				throw ex;
			}
		}
	
			// �������������� ������ bitmap

		public: void UnlockBits()
		{
			try
			{
				// ���������� ������ �� ������� ������ � ���������
				System::Runtime::InteropServices::Marshal::Copy(Pixels, 0, Iptr, Pixels->Length);

				// �������������� bitmap data
				source->UnlockBits(bmpData);
			}
			catch (Exception^ ex)
			{
				throw ex;
			}
		}
		
			// �������� ���� ���������� �������
			
		public: Color GetPixel(int x, int y)
		{
			Color clr = Color::Empty;

			// �������� ���������� ��������� �����
			int cCount = Depth / 8;

			// �������� ��������� ������ ���������� �������
			int i = ((y * Width) + x) * cCount;

			if (i > Pixels->Length - cCount)
				throw gcnew IndexOutOfRangeException();

			if (Depth == 32) // �������� �������� Red, Green, Blue � Alpha ��� 32-������� �����������
			{
				Byte b = Pixels[i];
				Byte g = Pixels[i + 1];
				Byte r = Pixels[i + 2];
				Byte a = Pixels[i + 3]; // a
				clr = Color::FromArgb(a, r, g, b);
			}
			if (Depth == 24) // �������� �������� Red, Green � Blue ��� 24-������� �����������
			{
				Byte b = Pixels[i];
				Byte g = Pixels[i + 1];
				Byte r = Pixels[i + 2];
				clr = Color::FromArgb(r, g, b);
			}
			if (Depth == 8)
				// �������� �������� ����� ��� 8-������� �����������(�������� Red, Green � Blue ���������)
			{
				Byte c = Pixels[i];
				clr = Color::FromArgb(c, c, c);
			}
			return clr;
		}

		
		public: void SetPixel(int x, int y, Color color)
		{
			// �������� ����� ��������� �����
			int cCount = Depth / 8;

			// �������� ��������� ������ ���������� �������
			int i = ((y * Width) + x) * cCount;

			if (Depth == 32) // ���������� �������� ��������� Red, Green, Blue � Alpha ��� 32-������� �����������
			{
				Pixels[i] = color.B;
				Pixels[i + 1] = color.G;
				Pixels[i + 2] = color.R;
				Pixels[i + 3] = color.A;
			}
			if (Depth == 24) // ���������� �������� ��������� Red, Green � Blue ��� 24-������� �����������
			{
				Pixels[i] = color.B;
				Pixels[i + 1] = color.G;
				Pixels[i + 2] = color.R;
			}
			if (Depth == 8) // ���������� �������� ����� ��� 8-������� ����������� (�������� Red, Green � Blue ���������)
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