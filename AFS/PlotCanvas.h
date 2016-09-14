#pragma once

namespace AFS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Сводка для PlotCanvas
	/// </summary>
	public ref class PlotCanvas : public System::Windows::Forms::Form
	{
	public:
		PlotCanvas(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			getPreparedCanvas();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PlotCanvas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl;

	private: System::Windows::Forms::TabPage^  tabPageDistr;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutDistr;

	private: System::Windows::Forms::TabPage^  tabPageConvergence;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutConvergence;

	public: ZedGraph::ZedGraphControl^  zedGraphItNumDistrRanged;
	public: ZedGraph::ZedGraphControl^  zedGraphPFDistrRanged;
	public: ZedGraph::ZedGraphControl^  zedGraphItNumDistr;
	public: ZedGraph::ZedGraphControl^  zedGraphPFDistr;
	public: ZedGraph::ZedGraphControl^  zedGraphConvergenceSC;
	public: ZedGraph::ZedGraphControl^  zedGraphConvergenceANG;
	public: ZedGraph::ZedGraphControl^  zedGraphConvergenceHY;
	public: ZedGraph::ZedGraphControl^  zedGraphConvergenceHX;
	private: System::ComponentModel::Container ^components;

	public: void prepGraphCanvasZG(ZedGraphControl^ zG, String^ grTitle, String^ OXName, String^ OYName)
	{
		// Получим панель для рисования
		GraphPane^ pane = zG->GraphPane;

		// Очистим список кривых на тот случай, если до этого сигналы уже были нарисованы
		pane->CurveList->Clear();

		// Изменим текст заголовка графика
		pane->Title = grTitle;

		// Изменим тест надписи по оси X
		pane->XAxis->Title = OXName;

		// Изменим тест надписи по оси Y
		pane->YAxis->Title = OYName;

		// Включаем отображение сетки напротив крупных рисок по оси X
		pane->XAxis->GridDashOn = true;

		// Длина штрихов равна 10 пикселям, ... 
		pane->XAxis->GridDashOn = 10;

		// затем 5 пикселей - пропуск
		pane->XAxis->GridDashOff = 5;

		// Включаем отображение сетки напротив крупных рисок по оси Y
		pane->YAxis->GridDashOn = true;

		// Аналогично задаем вид пунктирной линии для крупных рисок по оси Y
		pane->YAxis->GridDashOn = 10;
		pane->YAxis->GridDashOff = 5;

		// Устанавливаем интересующий нас интервал по оси X
		pane->XAxis->Min = -0.5;

		// Вызываем метод AxisChange(), чтобы обновить данные об осях. 
		// В противном случае на рисунке будет показана только часть графика, 
		// которая умещается в интервалы по осям, установленные по умолчанию
		zG->AxisChange();

		// Обновляем график
		zG->Invalidate();
	}

	public: void getPreparedCanvas()
		{
			prepGraphCanvasZG(zedGraphPFDistr, "Распределение функции приоритета", "№ ПГП", "Значение ФП");
			prepGraphCanvasZG(zedGraphPFDistrRanged, "Распределение функции приоритета (по убыванию)", "№ ПГП", "Значение ФП");
			prepGraphCanvasZG(zedGraphItNumDistr, "Распределение количества итераций", "№ ПГП", "Количество итераций");
			prepGraphCanvasZG(zedGraphItNumDistrRanged, "Распределение количества итераций (по убыванию)", "№ ПГП", "Количество итераций");
			prepGraphCanvasZG(zedGraphConvergenceHX, "Сходимость оценок сдвига по горизонтали", "№ итерации", "Значение оценки");
			prepGraphCanvasZG(zedGraphConvergenceHY, "Сходимость оценок сдвига по вертикали", "№ итерации", "Значение оценки");
			prepGraphCanvasZG(zedGraphConvergenceANG, "Сходимость оценок угла поворота", "№ итерации", "Значение оценки");
			prepGraphCanvasZG(zedGraphConvergenceSC, "Сходимость оценок масштабирования", "№ итерации", "Значение оценки");
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageDistr = (gcnew System::Windows::Forms::TabPage());
			this->tabPageConvergence = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutDistr = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->zedGraphPFDistr = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphItNumDistr = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphPFDistrRanged = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphItNumDistrRanged = (gcnew ZedGraph::ZedGraphControl());
			this->tableLayoutConvergence = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->zedGraphConvergenceSC = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphConvergenceANG = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphConvergenceHY = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphConvergenceHX = (gcnew ZedGraph::ZedGraphControl());
			this->tabControl->SuspendLayout();
			this->tabPageDistr->SuspendLayout();
			this->tabPageConvergence->SuspendLayout();
			this->tableLayoutDistr->SuspendLayout();
			this->tableLayoutConvergence->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPageDistr);
			this->tabControl->Controls->Add(this->tabPageConvergence);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(1006, 753);
			this->tabControl->TabIndex = 0;
			// 
			// tabPageDistr
			// 
			this->tabPageDistr->Controls->Add(this->tableLayoutDistr);
			this->tabPageDistr->Location = System::Drawing::Point(4, 25);
			this->tabPageDistr->Name = L"tabPageDistr";
			this->tabPageDistr->Padding = System::Windows::Forms::Padding(3);
			this->tabPageDistr->Size = System::Drawing::Size(998, 724);
			this->tabPageDistr->TabIndex = 0;
			this->tabPageDistr->Text = L"Распределения значений ФП и количества итераций";
			this->tabPageDistr->UseVisualStyleBackColor = true;
			// 
			// tabPageConvergence
			// 
			this->tabPageConvergence->Controls->Add(this->tableLayoutConvergence);
			this->tabPageConvergence->Location = System::Drawing::Point(4, 25);
			this->tabPageConvergence->Name = L"tabPageConvergence";
			this->tabPageConvergence->Padding = System::Windows::Forms::Padding(3);
			this->tabPageConvergence->Size = System::Drawing::Size(998, 724);
			this->tabPageConvergence->TabIndex = 1;
			this->tabPageConvergence->Text = L"Сходимость оценок параметров ""истинной"" ПГП";
			this->tabPageConvergence->UseVisualStyleBackColor = true;
			// 
			// tableLayoutDistr
			// 
			this->tableLayoutDistr->ColumnCount = 2;
			this->tableLayoutDistr->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutDistr->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutDistr->Controls->Add(this->zedGraphItNumDistrRanged, 1, 1);
			this->tableLayoutDistr->Controls->Add(this->zedGraphPFDistrRanged, 0, 1);
			this->tableLayoutDistr->Controls->Add(this->zedGraphItNumDistr, 1, 0);
			this->tableLayoutDistr->Controls->Add(this->zedGraphPFDistr, 0, 0);
			this->tableLayoutDistr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutDistr->Location = System::Drawing::Point(3, 3);
			this->tableLayoutDistr->Name = L"tableLayoutDistr";
			this->tableLayoutDistr->RowCount = 2;
			this->tableLayoutDistr->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutDistr->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutDistr->Size = System::Drawing::Size(992, 718);
			this->tableLayoutDistr->TabIndex = 0;
			// 
			// zedGraphPFDistr
			// 
			this->zedGraphPFDistr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphPFDistr->IsShowPointValues = false;
			this->zedGraphPFDistr->Location = System::Drawing::Point(3, 3);
			this->zedGraphPFDistr->Name = L"zedGraphPFDistr";
			this->zedGraphPFDistr->PointValueFormat = L"G";
			this->zedGraphPFDistr->Size = System::Drawing::Size(490, 353);
			this->zedGraphPFDistr->TabIndex = 0;
			// 
			// zedGraphItNumDistr
			// 
			this->zedGraphItNumDistr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphItNumDistr->IsShowPointValues = false;
			this->zedGraphItNumDistr->Location = System::Drawing::Point(499, 3);
			this->zedGraphItNumDistr->Name = L"zedGraphItNumDistr";
			this->zedGraphItNumDistr->PointValueFormat = L"G";
			this->zedGraphItNumDistr->Size = System::Drawing::Size(490, 353);
			this->zedGraphItNumDistr->TabIndex = 1;
			// 
			// zedGraphPFDistrRanged
			// 
			this->zedGraphPFDistrRanged->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphPFDistrRanged->IsShowPointValues = false;
			this->zedGraphPFDistrRanged->Location = System::Drawing::Point(3, 362);
			this->zedGraphPFDistrRanged->Name = L"zedGraphPFDistrRanged";
			this->zedGraphPFDistrRanged->PointValueFormat = L"G";
			this->zedGraphPFDistrRanged->Size = System::Drawing::Size(490, 353);
			this->zedGraphPFDistrRanged->TabIndex = 2;
			// 
			// zedGraphItNumDistrRanged
			// 
			this->zedGraphItNumDistrRanged->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphItNumDistrRanged->IsShowPointValues = false;
			this->zedGraphItNumDistrRanged->Location = System::Drawing::Point(499, 362);
			this->zedGraphItNumDistrRanged->Name = L"zedGraphItNumDistrRanged";
			this->zedGraphItNumDistrRanged->PointValueFormat = L"G";
			this->zedGraphItNumDistrRanged->Size = System::Drawing::Size(490, 353);
			this->zedGraphItNumDistrRanged->TabIndex = 3;
			// 
			// tableLayoutConvergence
			// 
			this->tableLayoutConvergence->ColumnCount = 2;
			this->tableLayoutConvergence->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutConvergence->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutConvergence->Controls->Add(this->zedGraphConvergenceSC, 1, 1);
			this->tableLayoutConvergence->Controls->Add(this->zedGraphConvergenceANG, 0, 1);
			this->tableLayoutConvergence->Controls->Add(this->zedGraphConvergenceHY, 1, 0);
			this->tableLayoutConvergence->Controls->Add(this->zedGraphConvergenceHX, 0, 0);
			this->tableLayoutConvergence->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutConvergence->Location = System::Drawing::Point(3, 3);
			this->tableLayoutConvergence->Name = L"tableLayoutConvergence";
			this->tableLayoutConvergence->RowCount = 2;
			this->tableLayoutConvergence->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutConvergence->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutConvergence->Size = System::Drawing::Size(992, 718);
			this->tableLayoutConvergence->TabIndex = 1;
			// 
			// zedGraphConvergenceSC
			// 
			this->zedGraphConvergenceSC->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphConvergenceSC->IsShowPointValues = false;
			this->zedGraphConvergenceSC->Location = System::Drawing::Point(499, 362);
			this->zedGraphConvergenceSC->Name = L"zedGraphConvergenceSC";
			this->zedGraphConvergenceSC->PointValueFormat = L"G";
			this->zedGraphConvergenceSC->Size = System::Drawing::Size(490, 353);
			this->zedGraphConvergenceSC->TabIndex = 3;
			// 
			// zedGraphConvergenceANG
			// 
			this->zedGraphConvergenceANG->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphConvergenceANG->IsShowPointValues = false;
			this->zedGraphConvergenceANG->Location = System::Drawing::Point(3, 362);
			this->zedGraphConvergenceANG->Name = L"zedGraphConvergenceANG";
			this->zedGraphConvergenceANG->PointValueFormat = L"G";
			this->zedGraphConvergenceANG->Size = System::Drawing::Size(490, 353);
			this->zedGraphConvergenceANG->TabIndex = 2;
			// 
			// zedGraphConvergenceHY
			// 
			this->zedGraphConvergenceHY->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphConvergenceHY->IsShowPointValues = false;
			this->zedGraphConvergenceHY->Location = System::Drawing::Point(499, 3);
			this->zedGraphConvergenceHY->Name = L"zedGraphConvergenceHY";
			this->zedGraphConvergenceHY->PointValueFormat = L"G";
			this->zedGraphConvergenceHY->Size = System::Drawing::Size(490, 353);
			this->zedGraphConvergenceHY->TabIndex = 1;
			// 
			// zedGraphConvergenceHX
			// 
			this->zedGraphConvergenceHX->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphConvergenceHX->IsShowPointValues = false;
			this->zedGraphConvergenceHX->Location = System::Drawing::Point(3, 3);
			this->zedGraphConvergenceHX->Name = L"zedGraphConvergenceHX";
			this->zedGraphConvergenceHX->PointValueFormat = L"G";
			this->zedGraphConvergenceHX->Size = System::Drawing::Size(490, 353);
			this->zedGraphConvergenceHX->TabIndex = 0;
			// 
			// PlotCanvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1006, 753);
			this->Controls->Add(this->tabControl);
			this->Name = L"PlotCanvas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Графики результирующих зависимостей";
			this->tabControl->ResumeLayout(false);
			this->tabPageDistr->ResumeLayout(false);
			this->tabPageConvergence->ResumeLayout(false);
			this->tableLayoutDistr->ResumeLayout(false);
			this->tableLayoutConvergence->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
