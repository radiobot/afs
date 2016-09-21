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
		Plotter(OutDataCollector^ odc)
		{
			pc = gcnew PlotCanvas();
			this->odc = odc;
		}

	public:
		PlotCanvas^ pc;

		OutDataCollector^ odc;

		void drawDistributionHists()
		{
			drawHist(pc->zedGraphPFDistr, odc->pFValDistr);
			drawHist(pc->zedGraphPFDistrRanged, odc->pFValDistrRanged);
			drawHist(pc->zedGraphItNumDistr, odc->numItDistr);
			drawHist(pc->zedGraphItNumDistrRanged, odc->numItDistrRanged);
		}

		void drawConvergencePlots()
		{
			drawPlot(pc->zedGraphConvergenceHX, odc->hxVals);
			drawPlot(pc->zedGraphConvergenceHY, odc->hyVals);
		}

		void showPaintedCanvas()
		{
			drawDistributionHists();
			drawConvergencePlots();
			pc->Show();
		}

		void drawHist( ZedGraphControl^ zG, array <double>^ histBarVals)
			{
				// Получим панель для рисования
				GraphPane^ pane = zG->GraphPane;

				pane->XAxis->Max = histBarVals->GetLength(0)-0.5;

				// Массив значений по оси ОХ
				array<double>^ histBarValsLine = gcnew array<double>(histBarVals->GetLength(0));
				
				for(int m = 1; m < histBarVals->GetLength(0); m++)
					{
						histBarValsLine[m] = histBarValsLine[m-1] + 1;
					}

				BarItem^ bar = pane->AddBar(nullptr, histBarValsLine, histBarVals, Color::Green);

				pane->MinClusterGap = 0.0f;

				bar->Bar->Fill->Type = FillType::Solid;

				zG->AxisChange();

				zG->Invalidate();
			}

		void drawPlot(ZedGraphControl^ zG, vector<double> estVals)
			{
				// Получим панель для рисования
				GraphPane^ pane = zG->GraphPane;

				// Устанавливаем интервалы по оси X
				pane->XAxis->Min = 0;
				pane->XAxis->Max = estVals.size();

				PointPairList^ list = gcnew PointPairList();

				for (int x = 0; x < estVals.size(); x++)
				{
					list->Add (x, estVals[x]);
				}

				LineItem^ myCurve = pane->AddCurve(nullptr, list, Color::Blue, SymbolType::None);

				myCurve->Line->Width = 3;
				
				myCurve->Line->IsSmooth = true;

				zG->AxisChange();

				zG->Invalidate();
			}

	};
}