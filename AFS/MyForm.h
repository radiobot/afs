#pragma once
#include "MessageWindow.h"

namespace AFS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  loadSourceImage;
	protected:



	private: System::Windows::Forms::ToolStripMenuItem^  detectFragment;
	private: System::Windows::Forms::ToolStripMenuItem^  showPlots;

	private: System::Windows::Forms::PictureBox^  mainPictureBox;
	private: System::Windows::Forms::PictureBox^  etalonPictureBox;
	private: System::Windows::Forms::PictureBox^  foundPictureBox;
	public: System::Windows::Forms::RichTextBox^  logBox;
	private:

	private: System::Windows::Forms::ToolStripMenuItem^  loadEtalonFragment;
	private: System::Windows::Forms::ToolStripMenuItem^  showHelp;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->loadSourceImage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadEtalonFragment = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->detectFragment = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showPlots = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->etalonPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->foundPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->logBox = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->etalonPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->foundPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->loadSourceImage, this->loadEtalonFragment,
					this->detectFragment, this->showPlots, this->showHelp
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip->Size = System::Drawing::Size(782, 28);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// loadSourceImage
			// 
			this->loadSourceImage->Name = L"loadSourceImage";
			this->loadSourceImage->Size = System::Drawing::Size(189, 24);
			this->loadSourceImage->Text = L"&Загрузить изображение";
			this->loadSourceImage->Click += gcnew System::EventHandler(this, &MyForm::loadSourceImage_Click);
			// 
			// loadEtalonFragment
			// 
			this->loadEtalonFragment->Name = L"loadEtalonFragment";
			this->loadEtalonFragment->Size = System::Drawing::Size(160, 24);
			this->loadEtalonFragment->Text = L"&Загрузить фрагмент";
			this->loadEtalonFragment->Click += gcnew System::EventHandler(this, &MyForm::loadEtalonFragment_Click);
			// 
			// detectFragment
			// 
			this->detectFragment->Name = L"detectFragment";
			this->detectFragment->Size = System::Drawing::Size(135, 24);
			this->detectFragment->Text = L"&Найти фрагмент";
			this->detectFragment->Click += gcnew System::EventHandler(this, &MyForm::detectFragment_Click);
			// 
			// showPlots
			// 
			this->showPlots->Name = L"showPlots";
			this->showPlots->Size = System::Drawing::Size(141, 24);
			this->showPlots->Text = L"&Вывести графики";
			this->showPlots->Click += gcnew System::EventHandler(this, &MyForm::showPlots_Click);
			// 
			// showHelp
			// 
			this->showHelp->Name = L"showHelp";
			this->showHelp->Size = System::Drawing::Size(79, 24);
			this->showHelp->Text = L"&Справка";
			this->showHelp->Click += gcnew System::EventHandler(this, &MyForm::showHelp_Click);
			// 
			// mainPictureBox
			// 
			this->mainPictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mainPictureBox->Location = System::Drawing::Point(218, 40);
			this->mainPictureBox->Name = L"mainPictureBox";
			this->mainPictureBox->Size = System::Drawing::Size(552, 502);
			this->mainPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->mainPictureBox->TabIndex = 1;
			this->mainPictureBox->TabStop = false;
			// 
			// etalonPictureBox
			// 
			this->etalonPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->etalonPictureBox->Location = System::Drawing::Point(12, 40);
			this->etalonPictureBox->Name = L"etalonPictureBox";
			this->etalonPictureBox->Size = System::Drawing::Size(200, 200);
			this->etalonPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->etalonPictureBox->TabIndex = 2;
			this->etalonPictureBox->TabStop = false;
			// 
			// foundPictureBox
			// 
			this->foundPictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->foundPictureBox->Location = System::Drawing::Point(12, 246);
			this->foundPictureBox->Name = L"foundPictureBox";
			this->foundPictureBox->Size = System::Drawing::Size(200, 200);
			this->foundPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->foundPictureBox->TabIndex = 3;
			this->foundPictureBox->TabStop = false;
			// 
			// logBox
			// 
			this->logBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->logBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->logBox->Location = System::Drawing::Point(12, 452);
			this->logBox->Name = L"logBox";
			this->logBox->ReadOnly = true;
			this->logBox->Size = System::Drawing::Size(200, 90);
			this->logBox->TabIndex = 4;
			this->logBox->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 554);
			this->Controls->Add(this->logBox);
			this->Controls->Add(this->foundPictureBox);
			this->Controls->Add(this->etalonPictureBox);
			this->Controls->Add(this->mainPictureBox);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"MyForm";
			this->Text = L"Автоматический поиск фрагмента";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->etalonPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->foundPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		System::Void loadSourceImage_Click(System::Object^  sender, System::EventArgs^  e) 
		{

		}

	private: 
		System::Void loadEtalonFragment_Click(System::Object^  sender, System::EventArgs^  e) 
		{

		}

	private: 
		System::Void detectFragment_Click(System::Object^  sender, System::EventArgs^  e) 
		{

		}

	private: 
		System::Void showPlots_Click(System::Object^  sender, System::EventArgs^  e) 
		{

		}

	private: 
		System::Void showHelp_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			MessageWindow^ msw = gcnew MessageWindow();
			msw->showMessage("О программе", "Программа поиска фрагмента версии 1.0");
		}
};
}
