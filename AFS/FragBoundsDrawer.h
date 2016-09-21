#pragma once
#include "Globals.h"

namespace AFS {

	public ref class FragBoundsDrawer
	{
	public:
		FragBoundsDrawer(PictureBox^ pbx)
		{
			this->pbx = pbx;
		}

	public:
		PictureBox^ pbx;

		array<PointF>^ crnCrds;

		void getFragCrnrs(Point Vindex)
		{
			PointF centrFrag;
			centrFrag.X = (safe_cast<float>(Globals::etalonFrag->sz.X) - 1) / 2;
			centrFrag.Y = (safe_cast<float>(Globals::etalonFrag->sz.Y) - 1) / 2;

			crnCrds = gcnew array<PointF>(4);

			centrFrag.X += Globals::etalonFrag->sz.X * Vindex.X;
			centrFrag.Y += Globals::etalonFrag->sz.Y * Vindex.Y;

			crnCrds[0].X = centrFrag.X - Globals::etalonFrag->sz.X / 2; 
			crnCrds[0].Y = centrFrag.Y - Globals::etalonFrag->sz.Y / 2;

			crnCrds[1].X = centrFrag.X + Globals::etalonFrag->sz.X / 2; 
			crnCrds[1].Y = centrFrag.Y - Globals::etalonFrag->sz.Y / 2;

			crnCrds[2].X = centrFrag.X + Globals::etalonFrag->sz.X / 2; 
			crnCrds[2].Y = centrFrag.Y + Globals::etalonFrag->sz.Y / 2;

			crnCrds[3].X = centrFrag.X - Globals::etalonFrag->sz.X / 2; 
			crnCrds[3].Y = centrFrag.Y + Globals::etalonFrag->sz.Y / 2;
		}

		void drawFragBounds()
		{
			Pen^ gPen = gcnew Pen(Color::Red, 3.0f);

			Bitmap^ Z = gcnew Bitmap(Globals::sourcePic->img);

			Graphics::FromImage(Z)->DrawPolygon(gPen, crnCrds);

			pbx->Image = Z;

			pbx->Refresh();
		}

	};
}
