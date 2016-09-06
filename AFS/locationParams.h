#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace AFS {

	public ref class locationParams : public System::Windows::Forms::Form
	{
	public:
		locationParams(void)
		{
			InitializeComponent();

			PFTypeComboBox->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~locationParams()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  OKButton;
	private: System::Windows::Forms::Label^  OLVLabel;
	public: System::Windows::Forms::TextBox^  OLVCntTextBox;
	public: System::Windows::Forms::TextBox^  itCntTextBox;
	private: System::Windows::Forms::Label^  itCntLabel;
	public: System::Windows::Forms::ComboBox^  PFTypeComboBox;
	private: System::Windows::Forms::Label^  PFTypeLabel;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->OKButton = (gcnew System::Windows::Forms::Button());
			this->OLVLabel = (gcnew System::Windows::Forms::Label());
			this->OLVCntTextBox = (gcnew System::Windows::Forms::TextBox());
			this->itCntTextBox = (gcnew System::Windows::Forms::TextBox());
			this->itCntLabel = (gcnew System::Windows::Forms::Label());
			this->PFTypeComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->PFTypeLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// OKButton
			// 
			this->OKButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->OKButton->Location = System::Drawing::Point(319, 6);
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size(50, 92);
			this->OKButton->TabIndex = 0;
			this->OKButton->Text = L"OK";
			this->OKButton->UseVisualStyleBackColor = true;
			// 
			// OLVLabel
			// 
			this->OLVLabel->AutoSize = true;
			this->OLVLabel->Location = System::Drawing::Point(12, 9);
			this->OLVLabel->Name = L"OLVLabel";
			this->OLVLabel->Size = System::Drawing::Size(191, 17);
			this->OLVLabel->TabIndex = 1;
			this->OLVLabel->Text = L"Объём локальной выборки:";
			// 
			// OLVCntTextBox
			// 
			this->OLVCntTextBox->Location = System::Drawing::Point(209, 6);
			this->OLVCntTextBox->Name = L"OLVCntTextBox";
			this->OLVCntTextBox->Size = System::Drawing::Size(100, 22);
			this->OLVCntTextBox->TabIndex = 2;
			this->OLVCntTextBox->Text = L"75";
			this->OLVCntTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// itCntTextBox
			// 
			this->itCntTextBox->Location = System::Drawing::Point(209, 40);
			this->itCntTextBox->Name = L"itCntTextBox";
			this->itCntTextBox->Size = System::Drawing::Size(100, 22);
			this->itCntTextBox->TabIndex = 4;
			this->itCntTextBox->Text = L"400";
			this->itCntTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// itCntLabel
			// 
			this->itCntLabel->AutoSize = true;
			this->itCntLabel->Location = System::Drawing::Point(12, 43);
			this->itCntLabel->Name = L"itCntLabel";
			this->itCntLabel->Size = System::Drawing::Size(157, 17);
			this->itCntLabel->TabIndex = 3;
			this->itCntLabel->Text = L"Количество итераций:";
			// 
			// PFTypeComboBox
			// 
			this->PFTypeComboBox->FormattingEnabled = true;
			this->PFTypeComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"СКМР", L"ВКМК", L"ВИ"});
			this->PFTypeComboBox->Location = System::Drawing::Point(209, 74);
			this->PFTypeComboBox->Name = L"PFTypeComboBox";
			this->PFTypeComboBox->Size = System::Drawing::Size(100, 24);
			this->PFTypeComboBox->TabIndex = 5;
			// 
			// PFTypeLabel
			// 
			this->PFTypeLabel->AutoSize = true;
			this->PFTypeLabel->Location = System::Drawing::Point(12, 77);
			this->PFTypeLabel->Name = L"PFTypeLabel";
			this->PFTypeLabel->Size = System::Drawing::Size(180, 17);
			this->PFTypeLabel->TabIndex = 6;
			this->PFTypeLabel->Text = L"Тип функции приоритета:";
			// 
			// locationParams
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(381, 111);
			this->ControlBox = false;
			this->Controls->Add(this->PFTypeLabel);
			this->Controls->Add(this->PFTypeComboBox);
			this->Controls->Add(this->itCntTextBox);
			this->Controls->Add(this->itCntLabel);
			this->Controls->Add(this->OLVCntTextBox);
			this->Controls->Add(this->OLVLabel);
			this->Controls->Add(this->OKButton);
			this->Name = L"locationParams";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Параметры алгоритма поиска";
			this->ResumeLayout(false);
			this->PerformLayout();

			}
#pragma endregion
	};
}
