#pragma once

namespace AFS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::TabPage^  pFDistrTab;
	private: System::Windows::Forms::TableLayoutPanel^  tablePFDistr;
	private: System::Windows::Forms::TabPage^  itNumDistrTab;
	private: System::Windows::Forms::TableLayoutPanel^  tableItNumDistr;
	private: System::Windows::Forms::TabPage^  estConvTab;
	private: System::Windows::Forms::TableLayoutPanel^  tableConvEstPlots;

	public: ZedGraph::ZedGraphControl^  zedGraphPFDistr;
	public: ZedGraph::ZedGraphControl^  zedGraphPFDistrRanged;
	public: ZedGraph::ZedGraphControl^  zedGraphItNumDistr;
	public: ZedGraph::ZedGraphControl^  zedGraphItNumDistrRanged;
	public: ZedGraph::ZedGraphControl^  zedGraphConvHX;
	public: ZedGraph::ZedGraphControl^  zedGraphConvHY;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->pFDistrTab = (gcnew System::Windows::Forms::TabPage());
			this->itNumDistrTab = (gcnew System::Windows::Forms::TabPage());
			this->estConvTab = (gcnew System::Windows::Forms::TabPage());
			this->tablePFDistr = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableItNumDistr = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableConvEstPlots = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->zedGraphPFDistr = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphPFDistrRanged = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphItNumDistr = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphItNumDistrRanged = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphConvHX = (gcnew ZedGraph::ZedGraphControl());
			this->zedGraphConvHY = (gcnew ZedGraph::ZedGraphControl());
			this->tabControl->SuspendLayout();
			this->pFDistrTab->SuspendLayout();
			this->itNumDistrTab->SuspendLayout();
			this->estConvTab->SuspendLayout();
			this->tablePFDistr->SuspendLayout();
			this->tableItNumDistr->SuspendLayout();
			this->tableConvEstPlots->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->pFDistrTab);
			this->tabControl->Controls->Add(this->itNumDistrTab);
			this->tabControl->Controls->Add(this->estConvTab);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(732, 853);
			this->tabControl->TabIndex = 0;
			// 
			// pFDistrTab
			// 
			this->pFDistrTab->Controls->Add(this->tablePFDistr);
			this->pFDistrTab->Location = System::Drawing::Point(4, 25);
			this->pFDistrTab->Name = L"pFDistrTab";
			this->pFDistrTab->Padding = System::Windows::Forms::Padding(3);
			this->pFDistrTab->Size = System::Drawing::Size(724, 824);
			this->pFDistrTab->TabIndex = 0;
			this->pFDistrTab->Text = L"Распределение функции приоритета";
			this->pFDistrTab->UseVisualStyleBackColor = true;
			// 
			// itNumDistrTab
			// 
			this->itNumDistrTab->Controls->Add(this->tableItNumDistr);
			this->itNumDistrTab->Location = System::Drawing::Point(4, 25);
			this->itNumDistrTab->Name = L"itNumDistrTab";
			this->itNumDistrTab->Padding = System::Windows::Forms::Padding(3);
			this->itNumDistrTab->Size = System::Drawing::Size(724, 824);
			this->itNumDistrTab->TabIndex = 1;
			this->itNumDistrTab->Text = L"Распределение по числу итераций";
			this->itNumDistrTab->UseVisualStyleBackColor = true;
			// 
			// estConvTab
			// 
			this->estConvTab->Controls->Add(this->tableConvEstPlots);
			this->estConvTab->Location = System::Drawing::Point(4, 25);
			this->estConvTab->Name = L"estConvTab";
			this->estConvTab->Size = System::Drawing::Size(724, 824);
			this->estConvTab->TabIndex = 2;
			this->estConvTab->Text = L"Сходимость оценок параметров";
			this->estConvTab->UseVisualStyleBackColor = true;
			// 
			// tablePFDistr
			// 
			this->tablePFDistr->ColumnCount = 1;
			this->tablePFDistr->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tablePFDistr->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tablePFDistr->Controls->Add(this->zedGraphPFDistr, 0, 0);
			this->tablePFDistr->Controls->Add(this->zedGraphPFDistrRanged, 0, 1);
			this->tablePFDistr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tablePFDistr->Location = System::Drawing::Point(3, 3);
			this->tablePFDistr->Name = L"tablePFDistr";
			this->tablePFDistr->RowCount = 2;
			this->tablePFDistr->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tablePFDistr->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tablePFDistr->Size = System::Drawing::Size(718, 818);
			this->tablePFDistr->TabIndex = 0;
			// 
			// tableItNumDistr
			// 
			this->tableItNumDistr->ColumnCount = 1;
			this->tableItNumDistr->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableItNumDistr->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableItNumDistr->Controls->Add(this->zedGraphItNumDistr, 0, 0);
			this->tableItNumDistr->Controls->Add(this->zedGraphItNumDistrRanged, 0, 1);
			this->tableItNumDistr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableItNumDistr->Location = System::Drawing::Point(3, 3);
			this->tableItNumDistr->Name = L"tableItNumDistr";
			this->tableItNumDistr->RowCount = 2;
			this->tableItNumDistr->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableItNumDistr->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableItNumDistr->Size = System::Drawing::Size(718, 818);
			this->tableItNumDistr->TabIndex = 0;
			// 
			// tableConvEstPlots
			// 
			this->tableConvEstPlots->ColumnCount = 1;
			this->tableConvEstPlots->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableConvEstPlots->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableConvEstPlots->Controls->Add(this->zedGraphConvHX, 0, 0);
			this->tableConvEstPlots->Controls->Add(this->zedGraphConvHY, 0, 1);
			this->tableConvEstPlots->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableConvEstPlots->Location = System::Drawing::Point(0, 0);
			this->tableConvEstPlots->Name = L"tableConvEstPlots";
			this->tableConvEstPlots->RowCount = 2;
			this->tableConvEstPlots->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableConvEstPlots->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableConvEstPlots->Size = System::Drawing::Size(724, 824);
			this->tableConvEstPlots->TabIndex = 0;
			// 
			// zedGraphPFDistr
			// 
			this->zedGraphPFDistr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphPFDistr->IsShowPointValues = false;
			this->zedGraphPFDistr->Location = System::Drawing::Point(3, 3);
			this->zedGraphPFDistr->Name = L"zedGraphPFDistr";
			this->zedGraphPFDistr->PointValueFormat = L"G";
			this->zedGraphPFDistr->Size = System::Drawing::Size(712, 403);
			this->zedGraphPFDistr->TabIndex = 0;
			// 
			// zedGraphPFDistrRanged
			// 
			this->zedGraphPFDistrRanged->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphPFDistrRanged->IsShowPointValues = false;
			this->zedGraphPFDistrRanged->Location = System::Drawing::Point(3, 412);
			this->zedGraphPFDistrRanged->Name = L"zedGraphPFDistrRanged";
			this->zedGraphPFDistrRanged->PointValueFormat = L"G";
			this->zedGraphPFDistrRanged->Size = System::Drawing::Size(712, 403);
			this->zedGraphPFDistrRanged->TabIndex = 1;
			// 
			// zedGraphItNumDistr
			// 
			this->zedGraphItNumDistr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphItNumDistr->IsShowPointValues = false;
			this->zedGraphItNumDistr->Location = System::Drawing::Point(3, 3);
			this->zedGraphItNumDistr->Name = L"zedGraphItNumDistr";
			this->zedGraphItNumDistr->PointValueFormat = L"G";
			this->zedGraphItNumDistr->Size = System::Drawing::Size(712, 403);
			this->zedGraphItNumDistr->TabIndex = 0;
			// 
			// zedGraphItNumDistrRanged
			// 
			this->zedGraphItNumDistrRanged->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphItNumDistrRanged->IsShowPointValues = false;
			this->zedGraphItNumDistrRanged->Location = System::Drawing::Point(3, 412);
			this->zedGraphItNumDistrRanged->Name = L"zedGraphItNumDistrRanged";
			this->zedGraphItNumDistrRanged->PointValueFormat = L"G";
			this->zedGraphItNumDistrRanged->Size = System::Drawing::Size(712, 403);
			this->zedGraphItNumDistrRanged->TabIndex = 1;
			// 
			// zedGraphConvHX
			// 
			this->zedGraphConvHX->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphConvHX->IsShowPointValues = false;
			this->zedGraphConvHX->Location = System::Drawing::Point(3, 3);
			this->zedGraphConvHX->Name = L"zedGraphConvHX";
			this->zedGraphConvHX->PointValueFormat = L"G";
			this->zedGraphConvHX->Size = System::Drawing::Size(718, 406);
			this->zedGraphConvHX->TabIndex = 0;
			// 
			// zedGraphConvHY
			// 
			this->zedGraphConvHY->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zedGraphConvHY->IsShowPointValues = false;
			this->zedGraphConvHY->Location = System::Drawing::Point(3, 415);
			this->zedGraphConvHY->Name = L"zedGraphConvHY";
			this->zedGraphConvHY->PointValueFormat = L"G";
			this->zedGraphConvHY->Size = System::Drawing::Size(718, 406);
			this->zedGraphConvHY->TabIndex = 1;
			// 
			// PlotCanvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 853);
			this->Controls->Add(this->tabControl);
			this->Name = L"PlotCanvas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Графики результирующих зависимостей";
			this->tabControl->ResumeLayout(false);
			this->pFDistrTab->ResumeLayout(false);
			this->itNumDistrTab->ResumeLayout(false);
			this->estConvTab->ResumeLayout(false);
			this->tablePFDistr->ResumeLayout(false);
			this->tableItNumDistr->ResumeLayout(false);
			this->tableConvEstPlots->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
