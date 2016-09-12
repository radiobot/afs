#pragma once

namespace AFS {

	using namespace System::Drawing;
	using namespace System;

	public ref class Interpolator
	{
		public:
			double getIntpVal(array<double, 2>^ mas, float x, float y)
						{
							int x_f = safe_cast<int>(Math::Floor(x));
							int x_c = safe_cast<int>(Math::Ceiling(x));
							int y_f = safe_cast<int>(Math::Floor(y));
							int y_c = safe_cast<int>(Math::Ceiling(y));

							Point N; // размеры массива-фрагмента

							N.X = mas->GetLength(0);
							N.Y = mas->GetLength(1);

							if((x_f > 0 )&&(x_f < N.X - 1 )&&(x_c > 0 )&&(x_c < N.X - 1 )&&
							   (y_f > 0 )&&(y_f < N.Y - 1 )&&(y_c > 0 )&&(y_c < N.Y - 1 ))
								{
									return mas[x_f, y_f] + (x - x_f) * (mas[x_c, y_f] 
									- mas[x_f, y_f]) + (y - y_f) * (mas[x_f, y_c] 
									- mas[x_f,y_f]) + (x - x_f) * (y - y_f) * (mas[x_c, y_c] 
									+ mas[x_f, y_f] - mas[x_c, y_f] - mas[x_f, y_c]);
								}

							else return 0;
						}
	};
}