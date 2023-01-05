#pragma once
#include "FourBarWindow.h"
#include "SliderCrankWindow.h"
#include "SixBarWindow.h"

namespace Mechanism {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titleLabel;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ mechanismComboBox;
	private: System::Windows::Forms::Button^ okButton;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->mechanismComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->BackColor = System::Drawing::SystemColors::Control;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->Location = System::Drawing::Point(100, 94);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(381, 32);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"Mechanism Motion Simulator";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(125, 165);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Select mechanism:";
			// 
			// mechanismComboBox
			// 
			this->mechanismComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->mechanismComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->mechanismComboBox->FormattingEnabled = true;
			this->mechanismComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Four-bar linkage", L"Six-bar linkage",
					L"Slider crank"
			});
			this->mechanismComboBox->Location = System::Drawing::Point(257, 161);
			this->mechanismComboBox->Name = L"mechanismComboBox";
			this->mechanismComboBox->Size = System::Drawing::Size(179, 24);
			this->mechanismComboBox->TabIndex = 2;
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(222, 236);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(140, 34);
			this->okButton->TabIndex = 3;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &MainWindow::okButton_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 353);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->mechanismComboBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->titleLabel);
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Mechanism Motion Simulator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (mechanismComboBox->Text == "Four-bar linkage")
		{
			FourBarWindow^ dlg = gcnew FourBarWindow();
			dlg->ShowDialog();
		}
		else if (mechanismComboBox->Text == "Six-bar linkage")
		{
			SixBarWindow^ dlg = gcnew SixBarWindow();
			dlg->ShowDialog();
		}
		else if (mechanismComboBox->Text == "Slider crank")
		{
			SliderCrankWindow^ dlg = gcnew SliderCrankWindow();
			dlg->ShowDialog();
		}
	}
	};
}
