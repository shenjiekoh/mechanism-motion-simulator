#pragma once
#include <cmath>
#include "Mechanism.h"
#include "DrawSixBar.h"

namespace Mechanism {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SixBarWindow
	/// </summary>
	public ref class SixBarWindow : public System::Windows::Forms::Form
	{
	public:
		SixBarWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			tbArr = gcnew array<TextBox^>{r1TextBox, r2TextBox, r3TextBox,
				r4TextBox, r5TextBox, r6TextBox, r7TextBox, r8TextBox, inputTextBox};
			errorArr = gcnew array<Label^>{errorLabel1, errorLabel2, errorLabel3,
				errorLabel4, errorLabel5, errorLabel6, errorLabel7, errorLabel8, errorLabel9 };
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SixBarWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ parameterGroupBox;
	private: System::Windows::Forms::TextBox^ r1TextBox;

	private: System::Windows::Forms::Label^ r1Label;

	private: System::Windows::Forms::Label^ lengthLabel;
	private: System::Windows::Forms::TextBox^ r8TextBox;

	private: System::Windows::Forms::Label^ r8Label;

	private: System::Windows::Forms::TextBox^ r7TextBox;

	private: System::Windows::Forms::Label^ r7Label;

	private: System::Windows::Forms::TextBox^ r6TextBox;

	private: System::Windows::Forms::Label^ r6Label;

	private: System::Windows::Forms::TextBox^ r5TextBox;

	private: System::Windows::Forms::Label^ r5Label;

	private: System::Windows::Forms::TextBox^ r4TextBox;

	private: System::Windows::Forms::Label^ r4Label;

	private: System::Windows::Forms::TextBox^ r3TextBox;

	private: System::Windows::Forms::Label^ r3Label;

	private: System::Windows::Forms::TextBox^ r2TextBox;

	private: System::Windows::Forms::Label^ r2Label;
	private: System::Windows::Forms::RadioButton^ cmRadioButton;



	private: System::Windows::Forms::RadioButton^ mmRadioButton;

	private: System::Windows::Forms::Label^ unitLabel;
	private: System::Windows::Forms::Label^ r8UnitLabel;
	private: System::Windows::Forms::Label^ r7UnitLabel;
	private: System::Windows::Forms::Label^ r6UnitLabel;
	private: System::Windows::Forms::Label^ r5UnitLabel;
	private: System::Windows::Forms::Label^ r4UnitLabel;
	private: System::Windows::Forms::Label^ r3UnitLabel;
	private: System::Windows::Forms::Label^ r2UnitLabel;
	private: System::Windows::Forms::Label^ r1UnitLabel;
	private: System::Windows::Forms::GroupBox^ inputGroupBox;
	private: System::Windows::Forms::Label^ noteLabel;
	private: System::Windows::Forms::Label^ angularSpeedLabel;
	private: System::Windows::Forms::TextBox^ inputTextBox;
	private: System::Windows::Forms::Label^ inputUnitLabel;
	private: System::Windows::Forms::Label^ selectInputLabel;
	private: System::Windows::Forms::RadioButton^ rpmRadioButton;
	private: System::Windows::Forms::RadioButton^ radRadioButton;
	private: System::Windows::Forms::RadioButton^ degreeRadioButton;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ descriptionGroupBox;
	private: System::Windows::Forms::Label^ description;
	private: System::Windows::Forms::Label^ errorLabel1;
	private: System::Windows::Forms::Label^ errorLabel8;
	private: System::Windows::Forms::Label^ errorLabel7;
	private: System::Windows::Forms::Label^ errorLabel6;
	private: System::Windows::Forms::Label^ errorLabel5;
	private: System::Windows::Forms::Label^ errorLabel4;
	private: System::Windows::Forms::Label^ errorLabel3;
	private: System::Windows::Forms::Label^ errorLabel2;
	private: System::Windows::Forms::Label^ errorLabel9;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::Button^ backButton;
	private: System::Windows::Forms::Button^ resetButton;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		double r1;
		double r2;
		double r3;
		double r4;
		double r5;
		double r6;
		double r7;
		double r8;
		double omega;
		array<TextBox^>^ tbArr;
		array<Label^>^ errorArr;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SixBarWindow::typeid));
			this->parameterGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->errorLabel8 = (gcnew System::Windows::Forms::Label());
			this->errorLabel7 = (gcnew System::Windows::Forms::Label());
			this->errorLabel6 = (gcnew System::Windows::Forms::Label());
			this->errorLabel5 = (gcnew System::Windows::Forms::Label());
			this->errorLabel4 = (gcnew System::Windows::Forms::Label());
			this->errorLabel3 = (gcnew System::Windows::Forms::Label());
			this->errorLabel2 = (gcnew System::Windows::Forms::Label());
			this->errorLabel1 = (gcnew System::Windows::Forms::Label());
			this->r8UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r7UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r6UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r5UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r4UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r3UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r2UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r1UnitLabel = (gcnew System::Windows::Forms::Label());
			this->cmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->mmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->unitLabel = (gcnew System::Windows::Forms::Label());
			this->r8TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r8Label = (gcnew System::Windows::Forms::Label());
			this->r7TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r7Label = (gcnew System::Windows::Forms::Label());
			this->r6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r6Label = (gcnew System::Windows::Forms::Label());
			this->r5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r5Label = (gcnew System::Windows::Forms::Label());
			this->r4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r4Label = (gcnew System::Windows::Forms::Label());
			this->r3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r3Label = (gcnew System::Windows::Forms::Label());
			this->r2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r2Label = (gcnew System::Windows::Forms::Label());
			this->r1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r1Label = (gcnew System::Windows::Forms::Label());
			this->lengthLabel = (gcnew System::Windows::Forms::Label());
			this->inputGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->errorLabel9 = (gcnew System::Windows::Forms::Label());
			this->rpmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->radRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->degreeRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->selectInputLabel = (gcnew System::Windows::Forms::Label());
			this->inputUnitLabel = (gcnew System::Windows::Forms::Label());
			this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->angularSpeedLabel = (gcnew System::Windows::Forms::Label());
			this->noteLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->descriptionGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->description = (gcnew System::Windows::Forms::Label());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			this->parameterGroupBox->SuspendLayout();
			this->inputGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->descriptionGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// parameterGroupBox
			// 
			this->parameterGroupBox->Controls->Add(this->errorLabel8);
			this->parameterGroupBox->Controls->Add(this->errorLabel7);
			this->parameterGroupBox->Controls->Add(this->errorLabel6);
			this->parameterGroupBox->Controls->Add(this->errorLabel5);
			this->parameterGroupBox->Controls->Add(this->errorLabel4);
			this->parameterGroupBox->Controls->Add(this->errorLabel3);
			this->parameterGroupBox->Controls->Add(this->errorLabel2);
			this->parameterGroupBox->Controls->Add(this->errorLabel1);
			this->parameterGroupBox->Controls->Add(this->r8UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r7UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r6UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r5UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r4UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r3UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r2UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r1UnitLabel);
			this->parameterGroupBox->Controls->Add(this->cmRadioButton);
			this->parameterGroupBox->Controls->Add(this->mmRadioButton);
			this->parameterGroupBox->Controls->Add(this->unitLabel);
			this->parameterGroupBox->Controls->Add(this->r8TextBox);
			this->parameterGroupBox->Controls->Add(this->r8Label);
			this->parameterGroupBox->Controls->Add(this->r7TextBox);
			this->parameterGroupBox->Controls->Add(this->r7Label);
			this->parameterGroupBox->Controls->Add(this->r6TextBox);
			this->parameterGroupBox->Controls->Add(this->r6Label);
			this->parameterGroupBox->Controls->Add(this->r5TextBox);
			this->parameterGroupBox->Controls->Add(this->r5Label);
			this->parameterGroupBox->Controls->Add(this->r4TextBox);
			this->parameterGroupBox->Controls->Add(this->r4Label);
			this->parameterGroupBox->Controls->Add(this->r3TextBox);
			this->parameterGroupBox->Controls->Add(this->r3Label);
			this->parameterGroupBox->Controls->Add(this->r2TextBox);
			this->parameterGroupBox->Controls->Add(this->r2Label);
			this->parameterGroupBox->Controls->Add(this->r1TextBox);
			this->parameterGroupBox->Controls->Add(this->r1Label);
			this->parameterGroupBox->Controls->Add(this->lengthLabel);
			this->parameterGroupBox->Location = System::Drawing::Point(25, 25);
			this->parameterGroupBox->Name = L"parameterGroupBox";
			this->parameterGroupBox->Size = System::Drawing::Size(483, 395);
			this->parameterGroupBox->TabIndex = 0;
			this->parameterGroupBox->TabStop = false;
			this->parameterGroupBox->Text = L"Mechanism Parameters";
			// 
			// errorLabel8
			// 
			this->errorLabel8->AutoSize = true;
			this->errorLabel8->ForeColor = System::Drawing::Color::Red;
			this->errorLabel8->Location = System::Drawing::Point(333, 351);
			this->errorLabel8->Name = L"errorLabel8";
			this->errorLabel8->Size = System::Drawing::Size(87, 17);
			this->errorLabel8->TabIndex = 36;
			this->errorLabel8->Text = L"Invalid input.";
			this->errorLabel8->Visible = false;
			// 
			// errorLabel7
			// 
			this->errorLabel7->AutoSize = true;
			this->errorLabel7->ForeColor = System::Drawing::Color::Red;
			this->errorLabel7->Location = System::Drawing::Point(332, 272);
			this->errorLabel7->Name = L"errorLabel7";
			this->errorLabel7->Size = System::Drawing::Size(87, 17);
			this->errorLabel7->TabIndex = 35;
			this->errorLabel7->Text = L"Invalid input.";
			this->errorLabel7->Visible = false;
			// 
			// errorLabel6
			// 
			this->errorLabel6->AutoSize = true;
			this->errorLabel6->ForeColor = System::Drawing::Color::Red;
			this->errorLabel6->Location = System::Drawing::Point(333, 193);
			this->errorLabel6->Name = L"errorLabel6";
			this->errorLabel6->Size = System::Drawing::Size(87, 17);
			this->errorLabel6->TabIndex = 34;
			this->errorLabel6->Text = L"Invalid input.";
			this->errorLabel6->Visible = false;
			// 
			// errorLabel5
			// 
			this->errorLabel5->AutoSize = true;
			this->errorLabel5->ForeColor = System::Drawing::Color::Red;
			this->errorLabel5->Location = System::Drawing::Point(333, 114);
			this->errorLabel5->Name = L"errorLabel5";
			this->errorLabel5->Size = System::Drawing::Size(87, 17);
			this->errorLabel5->TabIndex = 33;
			this->errorLabel5->Text = L"Invalid input.";
			this->errorLabel5->Visible = false;
			// 
			// errorLabel4
			// 
			this->errorLabel4->AutoSize = true;
			this->errorLabel4->ForeColor = System::Drawing::Color::Red;
			this->errorLabel4->Location = System::Drawing::Point(93, 351);
			this->errorLabel4->Name = L"errorLabel4";
			this->errorLabel4->Size = System::Drawing::Size(87, 17);
			this->errorLabel4->TabIndex = 32;
			this->errorLabel4->Text = L"Invalid input.";
			this->errorLabel4->Visible = false;
			// 
			// errorLabel3
			// 
			this->errorLabel3->AutoSize = true;
			this->errorLabel3->ForeColor = System::Drawing::Color::Red;
			this->errorLabel3->Location = System::Drawing::Point(92, 272);
			this->errorLabel3->Name = L"errorLabel3";
			this->errorLabel3->Size = System::Drawing::Size(87, 17);
			this->errorLabel3->TabIndex = 31;
			this->errorLabel3->Text = L"Invalid input.";
			this->errorLabel3->Visible = false;
			// 
			// errorLabel2
			// 
			this->errorLabel2->AutoSize = true;
			this->errorLabel2->ForeColor = System::Drawing::Color::Red;
			this->errorLabel2->Location = System::Drawing::Point(93, 193);
			this->errorLabel2->Name = L"errorLabel2";
			this->errorLabel2->Size = System::Drawing::Size(87, 17);
			this->errorLabel2->TabIndex = 30;
			this->errorLabel2->Text = L"Invalid input.";
			this->errorLabel2->Visible = false;
			// 
			// errorLabel1
			// 
			this->errorLabel1->AutoSize = true;
			this->errorLabel1->ForeColor = System::Drawing::Color::Red;
			this->errorLabel1->Location = System::Drawing::Point(93, 114);
			this->errorLabel1->Name = L"errorLabel1";
			this->errorLabel1->Size = System::Drawing::Size(87, 17);
			this->errorLabel1->TabIndex = 29;
			this->errorLabel1->Text = L"Invalid input.";
			this->errorLabel1->Visible = false;
			// 
			// r8UnitLabel
			// 
			this->r8UnitLabel->AutoSize = true;
			this->r8UnitLabel->Location = System::Drawing::Point(441, 329);
			this->r8UnitLabel->Name = L"r8UnitLabel";
			this->r8UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r8UnitLabel->TabIndex = 28;
			this->r8UnitLabel->Text = L"mm";
			// 
			// r7UnitLabel
			// 
			this->r7UnitLabel->AutoSize = true;
			this->r7UnitLabel->Location = System::Drawing::Point(441, 250);
			this->r7UnitLabel->Name = L"r7UnitLabel";
			this->r7UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r7UnitLabel->TabIndex = 27;
			this->r7UnitLabel->Text = L"mm";
			// 
			// r6UnitLabel
			// 
			this->r6UnitLabel->AutoSize = true;
			this->r6UnitLabel->Location = System::Drawing::Point(441, 171);
			this->r6UnitLabel->Name = L"r6UnitLabel";
			this->r6UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r6UnitLabel->TabIndex = 26;
			this->r6UnitLabel->Text = L"mm";
			// 
			// r5UnitLabel
			// 
			this->r5UnitLabel->AutoSize = true;
			this->r5UnitLabel->Location = System::Drawing::Point(441, 92);
			this->r5UnitLabel->Name = L"r5UnitLabel";
			this->r5UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r5UnitLabel->TabIndex = 25;
			this->r5UnitLabel->Text = L"mm";
			// 
			// r4UnitLabel
			// 
			this->r4UnitLabel->AutoSize = true;
			this->r4UnitLabel->Location = System::Drawing::Point(201, 329);
			this->r4UnitLabel->Name = L"r4UnitLabel";
			this->r4UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r4UnitLabel->TabIndex = 24;
			this->r4UnitLabel->Text = L"mm";
			// 
			// r3UnitLabel
			// 
			this->r3UnitLabel->AutoSize = true;
			this->r3UnitLabel->Location = System::Drawing::Point(201, 250);
			this->r3UnitLabel->Name = L"r3UnitLabel";
			this->r3UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r3UnitLabel->TabIndex = 23;
			this->r3UnitLabel->Text = L"mm";
			// 
			// r2UnitLabel
			// 
			this->r2UnitLabel->AutoSize = true;
			this->r2UnitLabel->Location = System::Drawing::Point(201, 171);
			this->r2UnitLabel->Name = L"r2UnitLabel";
			this->r2UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r2UnitLabel->TabIndex = 22;
			this->r2UnitLabel->Text = L"mm";
			// 
			// r1UnitLabel
			// 
			this->r1UnitLabel->AutoSize = true;
			this->r1UnitLabel->Location = System::Drawing::Point(202, 92);
			this->r1UnitLabel->Name = L"r1UnitLabel";
			this->r1UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r1UnitLabel->TabIndex = 21;
			this->r1UnitLabel->Text = L"mm";
			// 
			// cmRadioButton
			// 
			this->cmRadioButton->AutoSize = true;
			this->cmRadioButton->Location = System::Drawing::Point(424, 21);
			this->cmRadioButton->Name = L"cmRadioButton";
			this->cmRadioButton->Size = System::Drawing::Size(47, 21);
			this->cmRadioButton->TabIndex = 20;
			this->cmRadioButton->Text = L"cm";
			this->cmRadioButton->UseVisualStyleBackColor = true;
			// 
			// mmRadioButton
			// 
			this->mmRadioButton->AutoSize = true;
			this->mmRadioButton->Checked = true;
			this->mmRadioButton->Location = System::Drawing::Point(371, 21);
			this->mmRadioButton->Name = L"mmRadioButton";
			this->mmRadioButton->Size = System::Drawing::Size(51, 21);
			this->mmRadioButton->TabIndex = 19;
			this->mmRadioButton->TabStop = true;
			this->mmRadioButton->Text = L"mm";
			this->mmRadioButton->UseVisualStyleBackColor = true;
			this->mmRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SixBarWindow::mmRadioButton_CheckedChanged);
			// 
			// unitLabel
			// 
			this->unitLabel->AutoSize = true;
			this->unitLabel->Location = System::Drawing::Point(328, 23);
			this->unitLabel->Name = L"unitLabel";
			this->unitLabel->Size = System::Drawing::Size(37, 17);
			this->unitLabel->TabIndex = 18;
			this->unitLabel->Text = L"Unit:";
			// 
			// r8TextBox
			// 
			this->r8TextBox->Location = System::Drawing::Point(336, 326);
			this->r8TextBox->Name = L"r8TextBox";
			this->r8TextBox->Size = System::Drawing::Size(100, 22);
			this->r8TextBox->TabIndex = 17;
			this->r8TextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// r8Label
			// 
			this->r8Label->AutoSize = true;
			this->r8Label->Location = System::Drawing::Point(253, 329);
			this->r8Label->Name = L"r8Label";
			this->r8Label->Size = System::Drawing::Size(77, 17);
			this->r8Label->TabIndex = 16;
			this->r8Label->Text = L"Link 8 (r8):";
			// 
			// r7TextBox
			// 
			this->r7TextBox->Location = System::Drawing::Point(335, 247);
			this->r7TextBox->Name = L"r7TextBox";
			this->r7TextBox->Size = System::Drawing::Size(100, 22);
			this->r7TextBox->TabIndex = 15;
			this->r7TextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// r7Label
			// 
			this->r7Label->AutoSize = true;
			this->r7Label->Location = System::Drawing::Point(252, 250);
			this->r7Label->Name = L"r7Label";
			this->r7Label->Size = System::Drawing::Size(77, 17);
			this->r7Label->TabIndex = 14;
			this->r7Label->Text = L"Link 7 (r7):";
			// 
			// r6TextBox
			// 
			this->r6TextBox->Location = System::Drawing::Point(335, 168);
			this->r6TextBox->Name = L"r6TextBox";
			this->r6TextBox->Size = System::Drawing::Size(100, 22);
			this->r6TextBox->TabIndex = 13;
			this->r6TextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// r6Label
			// 
			this->r6Label->AutoSize = true;
			this->r6Label->Location = System::Drawing::Point(252, 171);
			this->r6Label->Name = L"r6Label";
			this->r6Label->Size = System::Drawing::Size(77, 17);
			this->r6Label->TabIndex = 12;
			this->r6Label->Text = L"Link 6 (r6):";
			// 
			// r5TextBox
			// 
			this->r5TextBox->Location = System::Drawing::Point(335, 89);
			this->r5TextBox->Name = L"r5TextBox";
			this->r5TextBox->Size = System::Drawing::Size(100, 22);
			this->r5TextBox->TabIndex = 11;
			this->r5TextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// r5Label
			// 
			this->r5Label->AutoSize = true;
			this->r5Label->Location = System::Drawing::Point(252, 92);
			this->r5Label->Name = L"r5Label";
			this->r5Label->Size = System::Drawing::Size(77, 17);
			this->r5Label->TabIndex = 10;
			this->r5Label->Text = L"Link 5 (r5):";
			// 
			// r4TextBox
			// 
			this->r4TextBox->Location = System::Drawing::Point(96, 326);
			this->r4TextBox->Name = L"r4TextBox";
			this->r4TextBox->Size = System::Drawing::Size(100, 22);
			this->r4TextBox->TabIndex = 9;
			this->r4TextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// r4Label
			// 
			this->r4Label->AutoSize = true;
			this->r4Label->Location = System::Drawing::Point(13, 329);
			this->r4Label->Name = L"r4Label";
			this->r4Label->Size = System::Drawing::Size(77, 17);
			this->r4Label->TabIndex = 8;
			this->r4Label->Text = L"Link 4 (r4):";
			// 
			// r3TextBox
			// 
			this->r3TextBox->Location = System::Drawing::Point(96, 247);
			this->r3TextBox->Name = L"r3TextBox";
			this->r3TextBox->Size = System::Drawing::Size(100, 22);
			this->r3TextBox->TabIndex = 7;
			this->r3TextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// r3Label
			// 
			this->r3Label->AutoSize = true;
			this->r3Label->Location = System::Drawing::Point(13, 250);
			this->r3Label->Name = L"r3Label";
			this->r3Label->Size = System::Drawing::Size(77, 17);
			this->r3Label->TabIndex = 6;
			this->r3Label->Text = L"Link 3 (r3):";
			// 
			// r2TextBox
			// 
			this->r2TextBox->Location = System::Drawing::Point(95, 168);
			this->r2TextBox->Name = L"r2TextBox";
			this->r2TextBox->Size = System::Drawing::Size(100, 22);
			this->r2TextBox->TabIndex = 5;
			this->r2TextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// r2Label
			// 
			this->r2Label->AutoSize = true;
			this->r2Label->Location = System::Drawing::Point(13, 171);
			this->r2Label->Name = L"r2Label";
			this->r2Label->Size = System::Drawing::Size(77, 17);
			this->r2Label->TabIndex = 4;
			this->r2Label->Text = L"Link 2 (r2):";
			// 
			// r1TextBox
			// 
			this->r1TextBox->Location = System::Drawing::Point(96, 89);
			this->r1TextBox->Name = L"r1TextBox";
			this->r1TextBox->Size = System::Drawing::Size(100, 22);
			this->r1TextBox->TabIndex = 3;
			this->r1TextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// r1Label
			// 
			this->r1Label->AutoSize = true;
			this->r1Label->Location = System::Drawing::Point(13, 92);
			this->r1Label->Name = L"r1Label";
			this->r1Label->Size = System::Drawing::Size(77, 17);
			this->r1Label->TabIndex = 2;
			this->r1Label->Text = L"Link 1 (r1):";
			// 
			// lengthLabel
			// 
			this->lengthLabel->AutoSize = true;
			this->lengthLabel->Location = System::Drawing::Point(13, 56);
			this->lengthLabel->Name = L"lengthLabel";
			this->lengthLabel->Size = System::Drawing::Size(56, 17);
			this->lengthLabel->TabIndex = 1;
			this->lengthLabel->Text = L"Length:";
			// 
			// inputGroupBox
			// 
			this->inputGroupBox->Controls->Add(this->errorLabel9);
			this->inputGroupBox->Controls->Add(this->rpmRadioButton);
			this->inputGroupBox->Controls->Add(this->radRadioButton);
			this->inputGroupBox->Controls->Add(this->degreeRadioButton);
			this->inputGroupBox->Controls->Add(this->selectInputLabel);
			this->inputGroupBox->Controls->Add(this->inputUnitLabel);
			this->inputGroupBox->Controls->Add(this->inputTextBox);
			this->inputGroupBox->Controls->Add(this->angularSpeedLabel);
			this->inputGroupBox->Controls->Add(this->noteLabel);
			this->inputGroupBox->Location = System::Drawing::Point(25, 446);
			this->inputGroupBox->Name = L"inputGroupBox";
			this->inputGroupBox->Size = System::Drawing::Size(483, 109);
			this->inputGroupBox->TabIndex = 1;
			this->inputGroupBox->TabStop = false;
			this->inputGroupBox->Text = L"Input Angular Velocity";
			// 
			// errorLabel9
			// 
			this->errorLabel9->AutoSize = true;
			this->errorLabel9->ForeColor = System::Drawing::Color::Red;
			this->errorLabel9->Location = System::Drawing::Point(292, 66);
			this->errorLabel9->Name = L"errorLabel9";
			this->errorLabel9->Size = System::Drawing::Size(87, 17);
			this->errorLabel9->TabIndex = 37;
			this->errorLabel9->Text = L"Invalid input.";
			this->errorLabel9->Visible = false;
			// 
			// rpmRadioButton
			// 
			this->rpmRadioButton->AutoSize = true;
			this->rpmRadioButton->Location = System::Drawing::Point(393, 74);
			this->rpmRadioButton->Name = L"rpmRadioButton";
			this->rpmRadioButton->Size = System::Drawing::Size(53, 21);
			this->rpmRadioButton->TabIndex = 7;
			this->rpmRadioButton->Text = L"rpm";
			this->rpmRadioButton->UseVisualStyleBackColor = true;
			this->rpmRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SixBarWindow::rpmRadioButton_CheckedChanged);
			// 
			// radRadioButton
			// 
			this->radRadioButton->AutoSize = true;
			this->radRadioButton->Location = System::Drawing::Point(393, 46);
			this->radRadioButton->Name = L"radRadioButton";
			this->radRadioButton->Size = System::Drawing::Size(61, 21);
			this->radRadioButton->TabIndex = 6;
			this->radRadioButton->Text = L"rad/s";
			this->radRadioButton->UseVisualStyleBackColor = true;
			this->radRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SixBarWindow::radRadioButton_CheckedChanged);
			// 
			// degreeRadioButton
			// 
			this->degreeRadioButton->AutoSize = true;
			this->degreeRadioButton->Checked = true;
			this->degreeRadioButton->Location = System::Drawing::Point(393, 18);
			this->degreeRadioButton->Name = L"degreeRadioButton";
			this->degreeRadioButton->Size = System::Drawing::Size(85, 21);
			this->degreeRadioButton->TabIndex = 5;
			this->degreeRadioButton->TabStop = true;
			this->degreeRadioButton->Text = L"degree/s";
			this->degreeRadioButton->UseVisualStyleBackColor = true;
			this->degreeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SixBarWindow::degreeRadioButton_CheckedChanged);
			// 
			// selectInputLabel
			// 
			this->selectInputLabel->AutoSize = true;
			this->selectInputLabel->Location = System::Drawing::Point(349, 18);
			this->selectInputLabel->Name = L"selectInputLabel";
			this->selectInputLabel->Size = System::Drawing::Size(37, 17);
			this->selectInputLabel->TabIndex = 4;
			this->selectInputLabel->Text = L"Unit:";
			// 
			// inputUnitLabel
			// 
			this->inputUnitLabel->AutoSize = true;
			this->inputUnitLabel->Location = System::Drawing::Point(227, 66);
			this->inputUnitLabel->Name = L"inputUnitLabel";
			this->inputUnitLabel->Size = System::Drawing::Size(64, 17);
			this->inputUnitLabel->TabIndex = 3;
			this->inputUnitLabel->Text = L"degree/s";
			// 
			// inputTextBox
			// 
			this->inputTextBox->Location = System::Drawing::Point(120, 66);
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(100, 22);
			this->inputTextBox->TabIndex = 2;
			this->inputTextBox->TextChanged += gcnew System::EventHandler(this, &SixBarWindow::TextBox_TextChanged);
			// 
			// angularSpeedLabel
			// 
			this->angularSpeedLabel->AutoSize = true;
			this->angularSpeedLabel->Location = System::Drawing::Point(7, 66);
			this->angularSpeedLabel->Name = L"angularSpeedLabel";
			this->angularSpeedLabel->Size = System::Drawing::Size(106, 17);
			this->angularSpeedLabel->TabIndex = 1;
			this->angularSpeedLabel->Text = L"Angular Speed:";
			// 
			// noteLabel
			// 
			this->noteLabel->AutoSize = true;
			this->noteLabel->Location = System::Drawing::Point(5, 29);
			this->noteLabel->Name = L"noteLabel";
			this->noteLabel->Size = System::Drawing::Size(190, 17);
			this->noteLabel->TabIndex = 0;
			this->noteLabel->Text = L"Positive: CCW, Negative: CW";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(541, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 348);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// descriptionGroupBox
			// 
			this->descriptionGroupBox->Controls->Add(this->description);
			this->descriptionGroupBox->Location = System::Drawing::Point(541, 390);
			this->descriptionGroupBox->Name = L"descriptionGroupBox";
			this->descriptionGroupBox->Size = System::Drawing::Size(500, 165);
			this->descriptionGroupBox->TabIndex = 3;
			this->descriptionGroupBox->TabStop = false;
			this->descriptionGroupBox->Text = L"Description";
			// 
			// description
			// 
			this->description->AutoSize = true;
			this->description->Location = System::Drawing::Point(6, 23);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(486, 136);
			this->description->TabIndex = 0;
			this->description->Text = resources->GetString(L"description.Text");
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(465, 580);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(150, 30);
			this->okButton->TabIndex = 4;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &SixBarWindow::okButton_Click);
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(255, 580);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(150, 30);
			this->backButton->TabIndex = 5;
			this->backButton->Text = L"<  Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &SixBarWindow::backButton_Click);
			// 
			// resetButton
			// 
			this->resetButton->Location = System::Drawing::Point(680, 580);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(150, 30);
			this->resetButton->TabIndex = 6;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &SixBarWindow::resetButton_Click);
			// 
			// SixBarWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1062, 673);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->descriptionGroupBox);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->inputGroupBox);
			this->Controls->Add(this->parameterGroupBox);
			this->Name = L"SixBarWindow";
			this->Text = L"Six Bar Linkage";
			this->parameterGroupBox->ResumeLayout(false);
			this->parameterGroupBox->PerformLayout();
			this->inputGroupBox->ResumeLayout(false);
			this->inputGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->descriptionGroupBox->ResumeLayout(false);
			this->descriptionGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion




	private: System::Void mmRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (mmRadioButton->Checked == true)
		{
			r1UnitLabel->Text = "mm";
			r2UnitLabel->Text = "mm";
			r3UnitLabel->Text = "mm";
			r4UnitLabel->Text = "mm";
			r5UnitLabel->Text = "mm";
			r6UnitLabel->Text = "mm";
			r7UnitLabel->Text = "mm";
			r8UnitLabel->Text = "mm";
		}
		else
		{
			r1UnitLabel->Text = "cm";
			r2UnitLabel->Text = "cm";
			r3UnitLabel->Text = "cm";
			r4UnitLabel->Text = "cm";
			r5UnitLabel->Text = "cm";
			r6UnitLabel->Text = "cm";
			r7UnitLabel->Text = "cm";
			r8UnitLabel->Text = "cm";
		}
	}
	private: System::Void degreeRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (degreeRadioButton->Checked == true)
			inputUnitLabel->Text = "degree/s";
		else if (radRadioButton->Checked == true)
			inputUnitLabel->Text = "rad/s";
		else
			inputUnitLabel->Text = "rpm";
	}
	private: System::Void radRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (degreeRadioButton->Checked == true)
			inputUnitLabel->Text = "degree/s";
		else if (radRadioButton->Checked == true)
			inputUnitLabel->Text = "rad/s";
		else
			inputUnitLabel->Text = "rpm";
	}
	private: System::Void rpmRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (degreeRadioButton->Checked == true)
			inputUnitLabel->Text = "degree/s";
		else if (radRadioButton->Checked == true)
			inputUnitLabel->Text = "rad/s";
		else
			inputUnitLabel->Text = "rpm";
	}
	private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		for each (TextBox ^ tb in tbArr)
			tb->Text = String::Empty;
		mmRadioButton->Checked = true;
		degreeRadioButton->Checked = true;
	}
	private: System::Void TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		TextBox^ tb = safe_cast<TextBox^>(sender);
		String^ input = tb->Text;
		double value;
		int index = Array::IndexOf(tbArr, tb);

		if (input != String::Empty)
		{
			if (!Double::TryParse(input, value))
				errorArr[index]->Visible = true;
			else if (Convert::ToDouble(input) < 0 && index < 8)
				errorArr[index]->Visible = true;
			//okButton->Enabled = false;
		}
		else
		{
			errorArr[index]->Visible = false;
			//okButton->Enabled = true;
		}

		switch (index)
		{
		case 0:
			r1 = value;
			break;
		case 1:
			r2 = value;
			break;
		case 2:
			r3 = value;
			break;
		case 3:
			r4 = value;
			break;
		case 4:
			r5 = value;
			break;
		case 5:
			r6 = value;
			break;
		case 6:
			r7 = value;
			break;
		case 7:
			r8 = value;
			break;
		case 8:
			omega = value;
			break;
		}
		array<double>^ r = { r1,r2,r3,r4 };
		Array::Sort(r);
		if (r[0] + r[1] + r[2] < r[3] || !(r[0] + r[3] < r[1] + r[2] && r[0] == r2)) // Loop 2 is assmebled
			okButton->Enabled = false;
		else
			okButton->Enabled = true;
	};
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		const double PI = atan(1.0) * 4;
		const double dtr = PI / 180;
		if (cmRadioButton->Checked == true)
		{
			r1 *= 10.0;
			r2 *= 10.0;
			r3 *= 10.0;
			r4 *= 10.0;
			r5 *= 10.0;
			r6 *= 10.0;
			r7 *= 10.0;
			r8 *= 10.0;
		}
		double omega2 = omega;
		if (degreeRadioButton->Checked == true)
			omega2 *= dtr;
		if (rpmRadioButton->Checked == true)
			omega2 = omega2 * 2 * PI / 60;
		double r[8] = { r1,r2,r3,r4,r5,r6,r7,r8 };
		SixBar sb(r, omega2, 0);
		DrawSixBar^ dlg = gcnew DrawSixBar(sb);
		dlg->ShowDialog();
	}
	};
}
