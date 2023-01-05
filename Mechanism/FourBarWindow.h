#pragma once
#include <cmath>
#include "Mechanism.h"
#include "DrawFourBar.h"
#include "HelpWindow1.h"

namespace Mechanism {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FourBarWindow
	/// </summary>
	public ref class FourBarWindow : public System::Windows::Forms::Form
	{
	public:
		FourBarWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			tbArr = gcnew array<TextBox^>{r1TextBox, r2TextBox, r3TextBox,
				r4TextBox, theta1TextBox, inputTextBox, r5TextBox, r6TextBox};
			errorArr = gcnew array<Label^>{errorLabel1, errorLabel2, errorLabel3,
				errorLabel4, errorLabel5, errorLabel6, errorLabel7, errorLabel8 };
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FourBarWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ parameterGroupBox;
	private: System::Windows::Forms::Label^ r4Label;

	private: System::Windows::Forms::Label^ r3Label;

	private: System::Windows::Forms::Label^ r2Label;

	private: System::Windows::Forms::Label^ r1Label;
	private: System::Windows::Forms::Label^ lengthLabel;
	private: System::Windows::Forms::Label^ r4UnitLabel;

	private: System::Windows::Forms::Label^ r3UnitLabel;


	private: System::Windows::Forms::Label^ r2UnitLabel;


	private: System::Windows::Forms::Label^ r1UnitLabel;


	private: System::Windows::Forms::TextBox^ r4TextBox;
	private: System::Windows::Forms::TextBox^ r3TextBox;
	private: System::Windows::Forms::TextBox^ r2TextBox;
	private: System::Windows::Forms::TextBox^ r1TextBox;




	private: System::Windows::Forms::Label^ theta1UnitLabel;


	private: System::Windows::Forms::Label^ theta1Label;
	private: System::Windows::Forms::TextBox^ theta1TextBox;


	private: System::Windows::Forms::Label^ angleLabel;
	private: System::Windows::Forms::RadioButton^ cmRadioButton;
	private: System::Windows::Forms::RadioButton^ mmRadioButton;
	private: System::Windows::Forms::Label^ selectUnitLabel;
	private: System::Windows::Forms::GroupBox^ inputGroupBox;
	private: System::Windows::Forms::Label^ noteLabel;

	private: System::Windows::Forms::TextBox^ inputTextBox;
	private: System::Windows::Forms::Label^ angularSpeedLabel;
	private: System::Windows::Forms::RadioButton^ rpmRadioButton;
	private: System::Windows::Forms::RadioButton^ radRadioButton;
	private: System::Windows::Forms::RadioButton^ degreeRadioButton;
	private: System::Windows::Forms::Label^ selectInputLabel;
	private: System::Windows::Forms::Label^ inputUnitLabel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ descriptionGroupBox;
	private: System::Windows::Forms::Label^ description;

	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::Button^ backButton;
	private: System::Windows::Forms::Button^ ResetButton;
	private: System::Windows::Forms::Label^ errorLabel5;
	private: System::Windows::Forms::Label^ errorLabel4;
	private: System::Windows::Forms::Label^ errorLabel3;
	private: System::Windows::Forms::Label^ errorLabel2;
	private: System::Windows::Forms::Label^ errorLabel1;
	private: System::Windows::Forms::Label^ errorLabel6;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		double r1;
		double r2;
		double r3;
		double r4;
		double theta1;
		double omega;
		double r5;
		double r6;
		array<TextBox^>^ tbArr;
private: System::Windows::Forms::Label^ errorLabel8;

private: System::Windows::Forms::Label^ errorLabel7;
private: System::Windows::Forms::Label^ r6UnitLabel;

private: System::Windows::Forms::TextBox^ r6TextBox;


private: System::Windows::Forms::Label^ r6Label;
private: System::Windows::Forms::Label^ r5UnitLabel;



private: System::Windows::Forms::TextBox^ r5TextBox;



private: System::Windows::Forms::Label^ r5Label;



private: System::Windows::Forms::Label^ couplerLabel;
private: System::Windows::Forms::Button^ helpButton;


	   array<Label^>^ errorArr;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FourBarWindow::typeid));
			this->parameterGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->helpButton = (gcnew System::Windows::Forms::Button());
			this->errorLabel8 = (gcnew System::Windows::Forms::Label());
			this->errorLabel7 = (gcnew System::Windows::Forms::Label());
			this->r6UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r6Label = (gcnew System::Windows::Forms::Label());
			this->r5UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r5Label = (gcnew System::Windows::Forms::Label());
			this->couplerLabel = (gcnew System::Windows::Forms::Label());
			this->errorLabel5 = (gcnew System::Windows::Forms::Label());
			this->errorLabel4 = (gcnew System::Windows::Forms::Label());
			this->errorLabel3 = (gcnew System::Windows::Forms::Label());
			this->errorLabel2 = (gcnew System::Windows::Forms::Label());
			this->errorLabel1 = (gcnew System::Windows::Forms::Label());
			this->theta1UnitLabel = (gcnew System::Windows::Forms::Label());
			this->theta1Label = (gcnew System::Windows::Forms::Label());
			this->theta1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->angleLabel = (gcnew System::Windows::Forms::Label());
			this->cmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->mmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->selectUnitLabel = (gcnew System::Windows::Forms::Label());
			this->r4UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r3UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r2UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r1UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r4Label = (gcnew System::Windows::Forms::Label());
			this->r3Label = (gcnew System::Windows::Forms::Label());
			this->r2Label = (gcnew System::Windows::Forms::Label());
			this->r1Label = (gcnew System::Windows::Forms::Label());
			this->lengthLabel = (gcnew System::Windows::Forms::Label());
			this->inputGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->errorLabel6 = (gcnew System::Windows::Forms::Label());
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
			this->ResetButton = (gcnew System::Windows::Forms::Button());
			this->parameterGroupBox->SuspendLayout();
			this->inputGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->descriptionGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// parameterGroupBox
			// 
			this->parameterGroupBox->Controls->Add(this->helpButton);
			this->parameterGroupBox->Controls->Add(this->errorLabel8);
			this->parameterGroupBox->Controls->Add(this->errorLabel7);
			this->parameterGroupBox->Controls->Add(this->r6UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r6TextBox);
			this->parameterGroupBox->Controls->Add(this->r6Label);
			this->parameterGroupBox->Controls->Add(this->r5UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r5TextBox);
			this->parameterGroupBox->Controls->Add(this->r5Label);
			this->parameterGroupBox->Controls->Add(this->couplerLabel);
			this->parameterGroupBox->Controls->Add(this->errorLabel5);
			this->parameterGroupBox->Controls->Add(this->errorLabel4);
			this->parameterGroupBox->Controls->Add(this->errorLabel3);
			this->parameterGroupBox->Controls->Add(this->errorLabel2);
			this->parameterGroupBox->Controls->Add(this->errorLabel1);
			this->parameterGroupBox->Controls->Add(this->theta1UnitLabel);
			this->parameterGroupBox->Controls->Add(this->theta1Label);
			this->parameterGroupBox->Controls->Add(this->theta1TextBox);
			this->parameterGroupBox->Controls->Add(this->angleLabel);
			this->parameterGroupBox->Controls->Add(this->cmRadioButton);
			this->parameterGroupBox->Controls->Add(this->mmRadioButton);
			this->parameterGroupBox->Controls->Add(this->selectUnitLabel);
			this->parameterGroupBox->Controls->Add(this->r4UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r3UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r2UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r1UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r4TextBox);
			this->parameterGroupBox->Controls->Add(this->r3TextBox);
			this->parameterGroupBox->Controls->Add(this->r2TextBox);
			this->parameterGroupBox->Controls->Add(this->r1TextBox);
			this->parameterGroupBox->Controls->Add(this->r4Label);
			this->parameterGroupBox->Controls->Add(this->r3Label);
			this->parameterGroupBox->Controls->Add(this->r2Label);
			this->parameterGroupBox->Controls->Add(this->r1Label);
			this->parameterGroupBox->Controls->Add(this->lengthLabel);
			this->parameterGroupBox->Location = System::Drawing::Point(25, 25);
			this->parameterGroupBox->Name = L"parameterGroupBox";
			this->parameterGroupBox->Size = System::Drawing::Size(450, 400);
			this->parameterGroupBox->TabIndex = 0;
			this->parameterGroupBox->TabStop = false;
			this->parameterGroupBox->Text = L"Mechanism Parameters";
			// 
			// helpButton
			// 
			this->helpButton->Location = System::Drawing::Point(370, 356);
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(74, 24);
			this->helpButton->TabIndex = 34;
			this->helpButton->Text = L"Help";
			this->helpButton->UseVisualStyleBackColor = true;
			this->helpButton->Click += gcnew System::EventHandler(this, &FourBarWindow::helpButton_Click);
			// 
			// errorLabel8
			// 
			this->errorLabel8->AutoSize = true;
			this->errorLabel8->ForeColor = System::Drawing::Color::Red;
			this->errorLabel8->Location = System::Drawing::Point(229, 380);
			this->errorLabel8->Name = L"errorLabel8";
			this->errorLabel8->Size = System::Drawing::Size(83, 17);
			this->errorLabel8->TabIndex = 33;
			this->errorLabel8->Text = L"Invalid input";
			this->errorLabel8->Visible = false;
			// 
			// errorLabel7
			// 
			this->errorLabel7->AutoSize = true;
			this->errorLabel7->ForeColor = System::Drawing::Color::Red;
			this->errorLabel7->Location = System::Drawing::Point(42, 380);
			this->errorLabel7->Name = L"errorLabel7";
			this->errorLabel7->Size = System::Drawing::Size(83, 17);
			this->errorLabel7->TabIndex = 32;
			this->errorLabel7->Text = L"Invalid input";
			this->errorLabel7->Visible = false;
			// 
			// r6UnitLabel
			// 
			this->r6UnitLabel->AutoSize = true;
			this->r6UnitLabel->Location = System::Drawing::Point(333, 360);
			this->r6UnitLabel->Name = L"r6UnitLabel";
			this->r6UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r6UnitLabel->TabIndex = 31;
			this->r6UnitLabel->Text = L"mm";
			// 
			// r6TextBox
			// 
			this->r6TextBox->Location = System::Drawing::Point(227, 357);
			this->r6TextBox->Name = L"r6TextBox";
			this->r6TextBox->Size = System::Drawing::Size(100, 22);
			this->r6TextBox->TabIndex = 30;
			this->r6TextBox->TextChanged += gcnew System::EventHandler(this, &FourBarWindow::TextBox_TextChanged);
			// 
			// r6Label
			// 
			this->r6Label->AutoSize = true;
			this->r6Label->Location = System::Drawing::Point(195, 360);
			this->r6Label->Name = L"r6Label";
			this->r6Label->Size = System::Drawing::Size(25, 17);
			this->r6Label->TabIndex = 29;
			this->r6Label->Text = L"r6:";
			// 
			// r5UnitLabel
			// 
			this->r5UnitLabel->AutoSize = true;
			this->r5UnitLabel->Location = System::Drawing::Point(149, 360);
			this->r5UnitLabel->Name = L"r5UnitLabel";
			this->r5UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r5UnitLabel->TabIndex = 28;
			this->r5UnitLabel->Text = L"mm";
			// 
			// r5TextBox
			// 
			this->r5TextBox->Location = System::Drawing::Point(43, 357);
			this->r5TextBox->Name = L"r5TextBox";
			this->r5TextBox->Size = System::Drawing::Size(100, 22);
			this->r5TextBox->TabIndex = 27;
			this->r5TextBox->TextChanged += gcnew System::EventHandler(this, &FourBarWindow::TextBox_TextChanged);
			// 
			// r5Label
			// 
			this->r5Label->AutoSize = true;
			this->r5Label->Location = System::Drawing::Point(11, 360);
			this->r5Label->Name = L"r5Label";
			this->r5Label->Size = System::Drawing::Size(25, 17);
			this->r5Label->TabIndex = 26;
			this->r5Label->Text = L"r5:";
			// 
			// couplerLabel
			// 
			this->couplerLabel->AutoSize = true;
			this->couplerLabel->Location = System::Drawing::Point(10, 337);
			this->couplerLabel->Name = L"couplerLabel";
			this->couplerLabel->Size = System::Drawing::Size(174, 17);
			this->couplerLabel->TabIndex = 25;
			this->couplerLabel->Text = L"Coupler point coordinates:";
			// 
			// errorLabel5
			// 
			this->errorLabel5->AutoSize = true;
			this->errorLabel5->ForeColor = System::Drawing::Color::Red;
			this->errorLabel5->Location = System::Drawing::Point(316, 291);
			this->errorLabel5->Name = L"errorLabel5";
			this->errorLabel5->Size = System::Drawing::Size(83, 17);
			this->errorLabel5->TabIndex = 24;
			this->errorLabel5->Text = L"Invalid input";
			this->errorLabel5->Visible = false;
			// 
			// errorLabel4
			// 
			this->errorLabel4->AutoSize = true;
			this->errorLabel4->ForeColor = System::Drawing::Color::Red;
			this->errorLabel4->Location = System::Drawing::Point(274, 216);
			this->errorLabel4->Name = L"errorLabel4";
			this->errorLabel4->Size = System::Drawing::Size(83, 17);
			this->errorLabel4->TabIndex = 23;
			this->errorLabel4->Text = L"Invalid input";
			this->errorLabel4->Visible = false;
			// 
			// errorLabel3
			// 
			this->errorLabel3->AutoSize = true;
			this->errorLabel3->ForeColor = System::Drawing::Color::Red;
			this->errorLabel3->Location = System::Drawing::Point(274, 167);
			this->errorLabel3->Name = L"errorLabel3";
			this->errorLabel3->Size = System::Drawing::Size(83, 17);
			this->errorLabel3->TabIndex = 22;
			this->errorLabel3->Text = L"Invalid input";
			this->errorLabel3->Visible = false;
			// 
			// errorLabel2
			// 
			this->errorLabel2->AutoSize = true;
			this->errorLabel2->ForeColor = System::Drawing::Color::Red;
			this->errorLabel2->Location = System::Drawing::Point(274, 118);
			this->errorLabel2->Name = L"errorLabel2";
			this->errorLabel2->Size = System::Drawing::Size(83, 17);
			this->errorLabel2->TabIndex = 21;
			this->errorLabel2->Text = L"Invalid input";
			this->errorLabel2->Visible = false;
			// 
			// errorLabel1
			// 
			this->errorLabel1->AutoSize = true;
			this->errorLabel1->ForeColor = System::Drawing::Color::Red;
			this->errorLabel1->Location = System::Drawing::Point(274, 69);
			this->errorLabel1->Name = L"errorLabel1";
			this->errorLabel1->Size = System::Drawing::Size(83, 17);
			this->errorLabel1->TabIndex = 20;
			this->errorLabel1->Text = L"Invalid input";
			this->errorLabel1->Visible = false;
			// 
			// theta1UnitLabel
			// 
			this->theta1UnitLabel->AutoSize = true;
			this->theta1UnitLabel->Location = System::Drawing::Point(239, 291);
			this->theta1UnitLabel->Name = L"theta1UnitLabel";
			this->theta1UnitLabel->Size = System::Drawing::Size(73, 17);
			this->theta1UnitLabel->TabIndex = 19;
			this->theta1UnitLabel->Text = L"° (degree)";
			// 
			// theta1Label
			// 
			this->theta1Label->AutoSize = true;
			this->theta1Label->Location = System::Drawing::Point(7, 295);
			this->theta1Label->Name = L"theta1Label";
			this->theta1Label->Size = System::Drawing::Size(52, 17);
			this->theta1Label->TabIndex = 18;
			this->theta1Label->Text = L"theta1:";
			// 
			// theta1TextBox
			// 
			this->theta1TextBox->Location = System::Drawing::Point(90, 291);
			this->theta1TextBox->Name = L"theta1TextBox";
			this->theta1TextBox->Size = System::Drawing::Size(138, 22);
			this->theta1TextBox->TabIndex = 17;
			this->theta1TextBox->TextChanged += gcnew System::EventHandler(this, &FourBarWindow::TextBox_TextChanged);
			// 
			// angleLabel
			// 
			this->angleLabel->AutoSize = true;
			this->angleLabel->Location = System::Drawing::Point(6, 258);
			this->angleLabel->Name = L"angleLabel";
			this->angleLabel->Size = System::Drawing::Size(108, 17);
			this->angleLabel->TabIndex = 16;
			this->angleLabel->Text = L"Base link angle:";
			// 
			// cmRadioButton
			// 
			this->cmRadioButton->AutoSize = true;
			this->cmRadioButton->Location = System::Drawing::Point(383, 21);
			this->cmRadioButton->Name = L"cmRadioButton";
			this->cmRadioButton->Size = System::Drawing::Size(47, 21);
			this->cmRadioButton->TabIndex = 15;
			this->cmRadioButton->Text = L"cm";
			this->cmRadioButton->UseVisualStyleBackColor = true;
			// 
			// mmRadioButton
			// 
			this->mmRadioButton->AutoSize = true;
			this->mmRadioButton->Checked = true;
			this->mmRadioButton->Location = System::Drawing::Point(326, 21);
			this->mmRadioButton->Name = L"mmRadioButton";
			this->mmRadioButton->Size = System::Drawing::Size(51, 21);
			this->mmRadioButton->TabIndex = 14;
			this->mmRadioButton->TabStop = true;
			this->mmRadioButton->Text = L"mm";
			this->mmRadioButton->UseVisualStyleBackColor = true;
			this->mmRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FourBarWindow::mmRadioButton_CheckedChanged);
			// 
			// selectUnitLabel
			// 
			this->selectUnitLabel->AutoSize = true;
			this->selectUnitLabel->Location = System::Drawing::Point(283, 23);
			this->selectUnitLabel->Name = L"selectUnitLabel";
			this->selectUnitLabel->Size = System::Drawing::Size(37, 17);
			this->selectUnitLabel->TabIndex = 13;
			this->selectUnitLabel->Text = L"Unit:";
			// 
			// r4UnitLabel
			// 
			this->r4UnitLabel->AutoSize = true;
			this->r4UnitLabel->Location = System::Drawing::Point(238, 216);
			this->r4UnitLabel->Name = L"r4UnitLabel";
			this->r4UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r4UnitLabel->TabIndex = 12;
			this->r4UnitLabel->Text = L"mm";
			// 
			// r3UnitLabel
			// 
			this->r3UnitLabel->AutoSize = true;
			this->r3UnitLabel->Location = System::Drawing::Point(238, 167);
			this->r3UnitLabel->Name = L"r3UnitLabel";
			this->r3UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r3UnitLabel->TabIndex = 11;
			this->r3UnitLabel->Text = L"mm";
			// 
			// r2UnitLabel
			// 
			this->r2UnitLabel->AutoSize = true;
			this->r2UnitLabel->Location = System::Drawing::Point(238, 118);
			this->r2UnitLabel->Name = L"r2UnitLabel";
			this->r2UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r2UnitLabel->TabIndex = 10;
			this->r2UnitLabel->Text = L"mm";
			// 
			// r1UnitLabel
			// 
			this->r1UnitLabel->AutoSize = true;
			this->r1UnitLabel->Location = System::Drawing::Point(238, 69);
			this->r1UnitLabel->Name = L"r1UnitLabel";
			this->r1UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r1UnitLabel->TabIndex = 9;
			this->r1UnitLabel->Text = L"mm";
			// 
			// r4TextBox
			// 
			this->r4TextBox->Location = System::Drawing::Point(89, 213);
			this->r4TextBox->Name = L"r4TextBox";
			this->r4TextBox->Size = System::Drawing::Size(138, 22);
			this->r4TextBox->TabIndex = 8;
			this->r4TextBox->TextChanged += gcnew System::EventHandler(this, &FourBarWindow::TextBox_TextChanged);
			// 
			// r3TextBox
			// 
			this->r3TextBox->Location = System::Drawing::Point(89, 164);
			this->r3TextBox->Name = L"r3TextBox";
			this->r3TextBox->Size = System::Drawing::Size(138, 22);
			this->r3TextBox->TabIndex = 7;
			this->r3TextBox->TextChanged += gcnew System::EventHandler(this, &FourBarWindow::TextBox_TextChanged);
			// 
			// r2TextBox
			// 
			this->r2TextBox->Location = System::Drawing::Point(89, 115);
			this->r2TextBox->Name = L"r2TextBox";
			this->r2TextBox->Size = System::Drawing::Size(138, 22);
			this->r2TextBox->TabIndex = 6;
			this->r2TextBox->TextChanged += gcnew System::EventHandler(this, &FourBarWindow::TextBox_TextChanged);
			// 
			// r1TextBox
			// 
			this->r1TextBox->Location = System::Drawing::Point(89, 66);
			this->r1TextBox->Name = L"r1TextBox";
			this->r1TextBox->Size = System::Drawing::Size(138, 22);
			this->r1TextBox->TabIndex = 5;
			this->r1TextBox->TextChanged += gcnew System::EventHandler(this, &FourBarWindow::TextBox_TextChanged);
			// 
			// r4Label
			// 
			this->r4Label->AutoSize = true;
			this->r4Label->Location = System::Drawing::Point(6, 216);
			this->r4Label->Name = L"r4Label";
			this->r4Label->Size = System::Drawing::Size(77, 17);
			this->r4Label->TabIndex = 4;
			this->r4Label->Text = L"Link 4 (r4):";
			// 
			// r3Label
			// 
			this->r3Label->AutoSize = true;
			this->r3Label->Location = System::Drawing::Point(6, 167);
			this->r3Label->Name = L"r3Label";
			this->r3Label->Size = System::Drawing::Size(77, 17);
			this->r3Label->TabIndex = 3;
			this->r3Label->Text = L"Link 3 (r3):";
			// 
			// r2Label
			// 
			this->r2Label->AutoSize = true;
			this->r2Label->Location = System::Drawing::Point(6, 118);
			this->r2Label->Name = L"r2Label";
			this->r2Label->Size = System::Drawing::Size(77, 17);
			this->r2Label->TabIndex = 2;
			this->r2Label->Text = L"Link 2 (r2):";
			// 
			// r1Label
			// 
			this->r1Label->AutoSize = true;
			this->r1Label->Location = System::Drawing::Point(6, 69);
			this->r1Label->Name = L"r1Label";
			this->r1Label->Size = System::Drawing::Size(77, 17);
			this->r1Label->TabIndex = 1;
			this->r1Label->Text = L"Link 1 (r1):";
			// 
			// lengthLabel
			// 
			this->lengthLabel->AutoSize = true;
			this->lengthLabel->Location = System::Drawing::Point(6, 34);
			this->lengthLabel->Name = L"lengthLabel";
			this->lengthLabel->Size = System::Drawing::Size(56, 17);
			this->lengthLabel->TabIndex = 0;
			this->lengthLabel->Text = L"Length:";
			// 
			// inputGroupBox
			// 
			this->inputGroupBox->Controls->Add(this->errorLabel6);
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
			this->inputGroupBox->Size = System::Drawing::Size(450, 100);
			this->inputGroupBox->TabIndex = 1;
			this->inputGroupBox->TabStop = false;
			this->inputGroupBox->Text = L"Input Angular Velocity";
			// 
			// errorLabel6
			// 
			this->errorLabel6->AutoSize = true;
			this->errorLabel6->ForeColor = System::Drawing::Color::Red;
			this->errorLabel6->Location = System::Drawing::Point(206, 31);
			this->errorLabel6->Name = L"errorLabel6";
			this->errorLabel6->Size = System::Drawing::Size(83, 17);
			this->errorLabel6->TabIndex = 25;
			this->errorLabel6->Text = L"Invalid input";
			this->errorLabel6->Visible = false;
			// 
			// rpmRadioButton
			// 
			this->rpmRadioButton->AutoSize = true;
			this->rpmRadioButton->Location = System::Drawing::Point(359, 75);
			this->rpmRadioButton->Name = L"rpmRadioButton";
			this->rpmRadioButton->Size = System::Drawing::Size(53, 21);
			this->rpmRadioButton->TabIndex = 17;
			this->rpmRadioButton->Text = L"rpm";
			this->rpmRadioButton->UseVisualStyleBackColor = true;
			this->rpmRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FourBarWindow::rpmRadioButton_CheckedChanged);
			// 
			// radRadioButton
			// 
			this->radRadioButton->AutoSize = true;
			this->radRadioButton->Location = System::Drawing::Point(359, 48);
			this->radRadioButton->Name = L"radRadioButton";
			this->radRadioButton->Size = System::Drawing::Size(61, 21);
			this->radRadioButton->TabIndex = 16;
			this->radRadioButton->Text = L"rad/s";
			this->radRadioButton->UseVisualStyleBackColor = true;
			this->radRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FourBarWindow::radRadioButton_CheckedChanged);
			// 
			// degreeRadioButton
			// 
			this->degreeRadioButton->AutoSize = true;
			this->degreeRadioButton->Checked = true;
			this->degreeRadioButton->Location = System::Drawing::Point(359, 21);
			this->degreeRadioButton->Name = L"degreeRadioButton";
			this->degreeRadioButton->Size = System::Drawing::Size(85, 21);
			this->degreeRadioButton->TabIndex = 15;
			this->degreeRadioButton->TabStop = true;
			this->degreeRadioButton->Text = L"degree/s";
			this->degreeRadioButton->UseVisualStyleBackColor = true;
			this->degreeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &FourBarWindow::degreeRadioButton_CheckedChanged);
			// 
			// selectInputLabel
			// 
			this->selectInputLabel->AutoSize = true;
			this->selectInputLabel->Location = System::Drawing::Point(316, 21);
			this->selectInputLabel->Name = L"selectInputLabel";
			this->selectInputLabel->Size = System::Drawing::Size(37, 17);
			this->selectInputLabel->TabIndex = 14;
			this->selectInputLabel->Text = L"Unit:";
			// 
			// inputUnitLabel
			// 
			this->inputUnitLabel->AutoSize = true;
			this->inputUnitLabel->Location = System::Drawing::Point(239, 65);
			this->inputUnitLabel->Name = L"inputUnitLabel";
			this->inputUnitLabel->Size = System::Drawing::Size(64, 17);
			this->inputUnitLabel->TabIndex = 3;
			this->inputUnitLabel->Text = L"degree/s";
			// 
			// inputTextBox
			// 
			this->inputTextBox->Location = System::Drawing::Point(124, 62);
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(104, 22);
			this->inputTextBox->TabIndex = 2;
			this->inputTextBox->TextChanged += gcnew System::EventHandler(this, &FourBarWindow::TextBox_TextChanged);
			// 
			// angularSpeedLabel
			// 
			this->angularSpeedLabel->AutoSize = true;
			this->angularSpeedLabel->Location = System::Drawing::Point(13, 62);
			this->angularSpeedLabel->Name = L"angularSpeedLabel";
			this->angularSpeedLabel->Size = System::Drawing::Size(104, 17);
			this->angularSpeedLabel->TabIndex = 1;
			this->angularSpeedLabel->Text = L"Angular speed:";
			// 
			// noteLabel
			// 
			this->noteLabel->AutoSize = true;
			this->noteLabel->Location = System::Drawing::Point(10, 31);
			this->noteLabel->Name = L"noteLabel";
			this->noteLabel->Size = System::Drawing::Size(190, 17);
			this->noteLabel->TabIndex = 0;
			this->noteLabel->Text = L"Positive: CCW, Negative: CW";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(504, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(546, 295);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// descriptionGroupBox
			// 
			this->descriptionGroupBox->Controls->Add(this->description);
			this->descriptionGroupBox->Location = System::Drawing::Point(504, 326);
			this->descriptionGroupBox->Name = L"descriptionGroupBox";
			this->descriptionGroupBox->Size = System::Drawing::Size(546, 220);
			this->descriptionGroupBox->TabIndex = 3;
			this->descriptionGroupBox->TabStop = false;
			this->descriptionGroupBox->Text = L"Description";
			// 
			// description
			// 
			this->description->AutoSize = true;
			this->description->Location = System::Drawing::Point(6, 18);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(498, 187);
			this->description->TabIndex = 0;
			this->description->Text = resources->GetString(L"description.Text");
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(463, 580);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(150, 30);
			this->okButton->TabIndex = 4;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &FourBarWindow::okButton_Click);
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(252, 580);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(150, 30);
			this->backButton->TabIndex = 5;
			this->backButton->Text = L"<  Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &FourBarWindow::backButton_Click);
			// 
			// ResetButton
			// 
			this->ResetButton->Location = System::Drawing::Point(674, 580);
			this->ResetButton->Name = L"ResetButton";
			this->ResetButton->Size = System::Drawing::Size(150, 30);
			this->ResetButton->TabIndex = 6;
			this->ResetButton->Text = L"Reset";
			this->ResetButton->UseVisualStyleBackColor = true;
			this->ResetButton->Click += gcnew System::EventHandler(this, &FourBarWindow::ResetButton_Click);
			// 
			// FourBarWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1062, 673);
			this->Controls->Add(this->ResetButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->descriptionGroupBox);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->inputGroupBox);
			this->Controls->Add(this->parameterGroupBox);
			this->Name = L"FourBarWindow";
			this->Text = L"Four Bar Linkage";
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
	}
	else
	{
		r1UnitLabel->Text = "cm";
		r2UnitLabel->Text = "cm";
		r3UnitLabel->Text = "cm";
		r4UnitLabel->Text = "cm";
		r5UnitLabel->Text = "cm";
		r6UnitLabel->Text = "cm";
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
private: System::Void ResetButton_Click(System::Object^ sender, System::EventArgs^ e) 
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
		else if (Convert::ToDouble(input) < 0 && index < 4)
			errorArr[index]->Visible = true;
		else
			errorArr[index]->Visible = false;
	}
	else
	{
		errorArr[index]->Visible = false;
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
		theta1 = value;
		break;
	case 5:
		omega = value;
		break;
	case 6:
		r5 = value;
		break;
	case 7:
		r6 = value;
		break;
	}
	array<double>^ r = { r1,r2,r3,r4 };
	Array::Sort(r);
	if (r[0] + r[1] + r[2] < r[3])
		okButton->Enabled = false;
	else if (r[0] + r[3] > r[1] + r[2])
		if (!(r[0] == r3))
			okButton->Enabled = false;
		else
			okButton->Enabled = true;
	else
		okButton->Enabled = true;
}
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
	}
	double omega2 = omega;
	if (degreeRadioButton->Checked == true)
		omega2 *= dtr;
	if (rpmRadioButton->Checked == true)
		omega2 = omega2 * 2 * PI / 60;

	double r[4] = { r1,r2,r3,r4 };
	double c[2] = { r5,r6 };
	FourBar fb(r, c, omega2, 0);
	DrawFourBar^ dlg = gcnew DrawFourBar(fb, theta1 * dtr);
	dlg->ShowDialog();

}
private: System::Void helpButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	HelpWindow1^ dlg = gcnew HelpWindow1();
	dlg->Show();
}
};
}
