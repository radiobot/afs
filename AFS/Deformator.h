#pragma once
#include "Frame.h"

namespace AFS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл¤ Deformator
	/// </summary>
	public ref class Deformator : public System::Windows::Forms::Form
	{
	public:
		Deformator(Frame^ defIm)
		{
			InitializeComponent();
			this->defIm = defIm;
			defPicBox->Image = defIm->img;
			SetParamDefaults();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Deformator()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		Frame^ defIm;

	public:
		void SetParamDefaults()
		{
			// Сдвиг по горизонтали
			hxTxtBox->Text = String::Format("{0}", 4);

			// Сдвиг по вертикали
			hyTxtBox->Text = String::Format("{0}", 3);

			// Угол поворота
			angTxtBox->Text = (0).ToString();

			//  оэффициент масштаба
			scTxtBox->Text = String::Format("{0}", 1);
		}

		double HX;
		double HY;
		double ANG;
		double SC;

		void GetParams()
		{
			HX = Double::Parse(hxTxtBox->Text);
			HY = Double::Parse(hyTxtBox->Text);
			ANG = Double::Parse(angTxtBox->Text)* 3.142 / 180;
			SC = Double::Parse(scTxtBox->Text);
		}

		//ћетод дл¤ получени¤ интерполированных значений
		double Intp(array<double, 2>^ mas, double x, double y)
		{
			int x_f = safe_cast<int>(Math::Floor(x));
			int x_c = safe_cast<int>(Math::Ceiling(x));
			int y_f = safe_cast<int>(Math::Floor(y));
			int y_c = safe_cast<int>(Math::Ceiling(y));
			return mas[x_f, y_f] + (x - x_f) * (mas[x_c, y_f] - mas[x_f, y_f]) + (y - y_f) * (mas[x_f, y_c] - mas[x_f, y_f]) + (x - x_f) * (y - y_f) * (mas[x_c, y_c] + mas[x_f, y_f] - mas[x_c, y_f] - mas[x_f, y_c]);
		}

		void Deform()
		{
			array<double, 2>^ defMas = gcnew array<double, 2>(defIm->sz.X, defIm->sz.Y);

			for (int i = 0; i < defIm->sz.X; i++)
			{
				for (int j = 0; j < defIm->sz.Y; j++)
				{
					double x_def = 1 / SC
						* (Math::Cos(ANG)
							* (i - defIm->cntr.X)
							- Math::Sin(ANG)
							* (j - defIm->cntr.Y))
							+ HX
							+ defIm->cntr.X;

					double y_def = 1 / SC
						* (Math::Sin(ANG)
							* (i - defIm->cntr.X)
							+ Math::Cos(ANG)
							* (j - defIm->cntr.Y))
							+ HY
							+ defIm->cntr.Y;

					if ((x_def > 0) && (x_def < defIm->sz.X - 1)
						&& (y_def > 0) && (y_def < defIm->sz.Y - 1))
					{
						defMas[i, j] = Intp(defIm->intnsVls, x_def, y_def);
					}
				}
			}

			defIm->intnsVls = defMas;

			defIm->cnvArPic();

			defPicBox->Image = defIm->img;
		}

	private: System::Windows::Forms::PictureBox^  defPicBox;
	
	private: System::Windows::Forms::TextBox^  hxTxtBox;
	private: System::Windows::Forms::TextBox^  hyTxtBox;
	private: System::Windows::Forms::TextBox^  angTxtBox;
	private: System::Windows::Forms::TextBox^  scTxtBox;

	private: System::Windows::Forms::Label^  hxLbl;
	private: System::Windows::Forms::Label^  hyLbl;
	private: System::Windows::Forms::Label^  angLbl;
	private: System::Windows::Forms::Label^  scLbl;
	
	private: System::Windows::Forms::Button^  defButton;
	private: System::Windows::Forms::Button^  okButton;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл¤ поддержки конструктора Ч не измен¤йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
		this->defPicBox = (gcnew System::Windows::Forms::PictureBox());
		this->hxTxtBox = (gcnew System::Windows::Forms::TextBox());
		this->hxLbl = (gcnew System::Windows::Forms::Label());
		this->hyLbl = (gcnew System::Windows::Forms::Label());
		this->hyTxtBox = (gcnew System::Windows::Forms::TextBox());
		this->scLbl = (gcnew System::Windows::Forms::Label());
		this->scTxtBox = (gcnew System::Windows::Forms::TextBox());
		this->angLbl = (gcnew System::Windows::Forms::Label());
		this->angTxtBox = (gcnew System::Windows::Forms::TextBox());
		this->defButton = (gcnew System::Windows::Forms::Button());
		this->okButton = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->defPicBox))->BeginInit();
		this->SuspendLayout();
		// 
		// defPicBox
		// 
		this->defPicBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->defPicBox->Location = System::Drawing::Point(9, 10);
		this->defPicBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
		this->defPicBox->Name = L"defPicBox";
		this->defPicBox->Size = System::Drawing::Size(307, 333);
		this->defPicBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->defPicBox->TabIndex = 0;
		this->defPicBox->TabStop = false;
		// 
		// hxTxtBox
		// 
		this->hxTxtBox->Location = System::Drawing::Point(359, 10);
		this->hxTxtBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
		this->hxTxtBox->Name = L"hxTxtBox";
		this->hxTxtBox->Size = System::Drawing::Size(74, 20);
		this->hxTxtBox->TabIndex = 1;
		// 
		// hxLbl
		// 
		this->hxLbl->AutoSize = true;
		this->hxLbl->Location = System::Drawing::Point(324, 12);
		this->hxLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->hxLbl->Name = L"hxLbl";
		this->hxLbl->Size = System::Drawing::Size(24, 13);
		this->hxLbl->TabIndex = 2;
		this->hxLbl->Text = L"hx: ";
		// 
		// hyLbl
		// 
		this->hyLbl->AutoSize = true;
		this->hyLbl->Location = System::Drawing::Point(324, 42);
		this->hyLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->hyLbl->Name = L"hyLbl";
		this->hyLbl->Size = System::Drawing::Size(24, 13);
		this->hyLbl->TabIndex = 4;
		this->hyLbl->Text = L"hy: ";
		// 
		// hyTxtBox
		// 
		this->hyTxtBox->Location = System::Drawing::Point(359, 40);
		this->hyTxtBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
		this->hyTxtBox->Name = L"hyTxtBox";
		this->hyTxtBox->Size = System::Drawing::Size(74, 20);
		this->hyTxtBox->TabIndex = 3;
		// 
		// scLbl
		// 
		this->scLbl->AutoSize = true;
		this->scLbl->Location = System::Drawing::Point(324, 103);
		this->scLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->scLbl->Name = L"scLbl";
		this->scLbl->Size = System::Drawing::Size(24, 13);
		this->scLbl->TabIndex = 8;
		this->scLbl->Text = L"sc: ";
		// 
		// scTxtBox
		// 
		this->scTxtBox->Location = System::Drawing::Point(359, 101);
		this->scTxtBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
		this->scTxtBox->Name = L"scTxtBox";
		this->scTxtBox->Size = System::Drawing::Size(74, 20);
		this->scTxtBox->TabIndex = 7;
		// 
		// angLbl
		// 
		this->angLbl->AutoSize = true;
		this->angLbl->Location = System::Drawing::Point(324, 73);
		this->angLbl->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
		this->angLbl->Name = L"angLbl";
		this->angLbl->Size = System::Drawing::Size(31, 13);
		this->angLbl->TabIndex = 6;
		this->angLbl->Text = L"ang: ";
		// 
		// angTxtBox
		// 
		this->angTxtBox->Location = System::Drawing::Point(359, 71);
		this->angTxtBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
		this->angTxtBox->Name = L"angTxtBox";
		this->angTxtBox->Size = System::Drawing::Size(74, 20);
		this->angTxtBox->TabIndex = 5;
		// 
		// defButton
		// 
		this->defButton->Location = System::Drawing::Point(326, 135);
		this->defButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
		this->defButton->Name = L"defButton";
		this->defButton->Size = System::Drawing::Size(107, 31);
		this->defButton->TabIndex = 9;
		this->defButton->Text = L"Деформировать";
		this->defButton->UseVisualStyleBackColor = true;
		this->defButton->Click += gcnew System::EventHandler(this, &Deformator::defButton_Click);
		// 
		// okButton
		// 
		this->okButton->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->okButton->Location = System::Drawing::Point(326, 180);
		this->okButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
		this->okButton->Name = L"okButton";
		this->okButton->Size = System::Drawing::Size(107, 31);
		this->okButton->TabIndex = 10;
		this->okButton->Text = L"OK";
		this->okButton->UseVisualStyleBackColor = true;
		// 
		// Deformator
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(444, 352);
		this->Controls->Add(this->okButton);
		this->Controls->Add(this->defButton);
		this->Controls->Add(this->scLbl);
		this->Controls->Add(this->scTxtBox);
		this->Controls->Add(this->angLbl);
		this->Controls->Add(this->angTxtBox);
		this->Controls->Add(this->hyLbl);
		this->Controls->Add(this->hyTxtBox);
		this->Controls->Add(this->hxLbl);
		this->Controls->Add(this->hxTxtBox);
		this->Controls->Add(this->defPicBox);
		this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
		this->Name = L"Deformator";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Деформация изображения";
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->defPicBox))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
	private: System::Void defButton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		GetParams();
		Deform();
	}
};
}
