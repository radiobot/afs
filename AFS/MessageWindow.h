#pragma once

namespace AFS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MessageWindow
	/// </summary>
	public ref class MessageWindow : public System::Windows::Forms::Form
	{
	public:
		MessageWindow(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MessageWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^  logTextBox;
	public:
	
		// Вывод окна на экран
		void showMessage(String^ messageHeader, String^ messageBody)
		{
			Text = messageHeader;
			logTextBox->AppendText(messageBody);
			Show();
		}

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MessageWindow::typeid));
			this->logTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// logTextBox
			// 
			this->logTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->logTextBox->Location = System::Drawing::Point(0, 0);
			this->logTextBox->Name = L"logTextBox";
			this->logTextBox->Size = System::Drawing::Size(622, 433);
			this->logTextBox->TabIndex = 0;
			this->logTextBox->Text = L"";
			// 
			// MessageWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 433);
			this->Controls->Add(this->logTextBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MessageWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MessageWindow";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
