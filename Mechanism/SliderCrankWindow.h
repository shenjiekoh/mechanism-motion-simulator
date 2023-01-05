#pragma once
#include "DrawSliderCrank.h"
#include "HelpWindow2.h"
#include <cmath>

namespace Mechanism {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SliderCrankWindow
	/// </summary>
	public ref class SliderCrankWindow : public System::Windows::Forms::Form
	{
	public:
		SliderCrankWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			tbArr = gcnew array<TextBox^>{r1TextBox, r2TextBox, r3TextBox, 
				inputTextBox, r5TextBox, r6TextBox};
			errorArr = gcnew array<Label^>{errorLabel1, errorLabel2, errorLabel3, 
				errorLabel4, errorLabel5, errorLabel6 };
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SliderCrankWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ parameterGroupBox;
	private: System::Windows::Forms::Label^ selectUnitLabel;
	private: System::Windows::Forms::RadioButton^ cmRadioButton;
	private: System::Windows::Forms::RadioButton^ mmRadioButton;
	private: System::Windows::Forms::Label^ lengthLabel;
	private: System::Windows::Forms::Label^ r1Label;
	private: System::Windows::Forms::TextBox^ r1TextBox;
	private: System::Windows::Forms::Label^ r3UnitLabel;



	private: System::Windows::Forms::Label^ r2UnitLabel;

	private: System::Windows::Forms::Label^ r1UnitLabel;

	private: System::Windows::Forms::TextBox^ r3TextBox;

	private: System::Windows::Forms::Label^ r3Label;
	private: System::Windows::Forms::TextBox^ r2TextBox;


	private: System::Windows::Forms::Label^ r2Label;
	private: System::Windows::Forms::GroupBox^ inputGroupBox;
	private: System::Windows::Forms::Label^ noteLabel;
	private: System::Windows::Forms::Label^ angularSpeedLabel;
	private: System::Windows::Forms::TextBox^ inputTextBox;
	private: System::Windows::Forms::Label^ selectInputLabel;
	private: System::Windows::Forms::Label^ inputUnitLabel;

	private: System::Windows::Forms::RadioButton^ rpmRadioButton;
	private: System::Windows::Forms::RadioButton^ radRadioButton;
	private: System::Windows::Forms::RadioButton^ degreeRadioButton;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ descriptionGroupBox;
	private: System::Windows::Forms::Label^ description;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::Button^ backButton;
	private: System::Windows::Forms::Button^ resetButton;
	private: System::Windows::Forms::Label^ errorLabel3;
	private: System::Windows::Forms::Label^ errorLabel2;
	private: System::Windows::Forms::Label^ errorLabel1;
	private: System::Windows::Forms::Label^ errorLabel4;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		double r1;
		double r2;
		double r3;
		double omega;
		double r5;
		double r6;
		array<TextBox^>^ tbArr;
	private: System::Windows::Forms::Button^ helpButton;
	private: System::Windows::Forms::Label^ errorLabel6;

	private: System::Windows::Forms::Label^ errorLabel5;
	private: System::Windows::Forms::Label^ r6UnitLabel;


	private: System::Windows::Forms::TextBox^ r6TextBox;

	private: System::Windows::Forms::Label^ r6Label;
	private: System::Windows::Forms::Label^ r5UnitLabel;


	private: System::Windows::Forms::TextBox^ r5TextBox;

	private: System::Windows::Forms::Label^ r5Label;

	private: System::Windows::Forms::Label^ couplerLabel;
		   array<Label^>^ errorArr;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SliderCrankWindow::typeid));
			this->parameterGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->helpButton = (gcnew System::Windows::Forms::Button());
			this->errorLabel6 = (gcnew System::Windows::Forms::Label());
			this->errorLabel5 = (gcnew System::Windows::Forms::Label());
			this->r6UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r6Label = (gcnew System::Windows::Forms::Label());
			this->r5UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r5Label = (gcnew System::Windows::Forms::Label());
			this->couplerLabel = (gcnew System::Windows::Forms::Label());
			this->errorLabel3 = (gcnew System::Windows::Forms::Label());
			this->errorLabel2 = (gcnew System::Windows::Forms::Label());
			this->errorLabel1 = (gcnew System::Windows::Forms::Label());
			this->r3UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r2UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r1UnitLabel = (gcnew System::Windows::Forms::Label());
			this->r3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r3Label = (gcnew System::Windows::Forms::Label());
			this->r2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r2Label = (gcnew System::Windows::Forms::Label());
			this->r1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r1Label = (gcnew System::Windows::Forms::Label());
			this->lengthLabel = (gcnew System::Windows::Forms::Label());
			this->cmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->mmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->selectUnitLabel = (gcnew System::Windows::Forms::Label());
			this->inputGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->errorLabel4 = (gcnew System::Windows::Forms::Label());
			this->inputUnitLabel = (gcnew System::Windows::Forms::Label());
			this->rpmRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->radRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->degreeRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->selectInputLabel = (gcnew System::Windows::Forms::Label());
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
			this->parameterGroupBox->Controls->Add(this->helpButton);
			this->parameterGroupBox->Controls->Add(this->errorLabel6);
			this->parameterGroupBox->Controls->Add(this->errorLabel5);
			this->parameterGroupBox->Controls->Add(this->r6UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r6TextBox);
			this->parameterGroupBox->Controls->Add(this->r6Label);
			this->parameterGroupBox->Controls->Add(this->r5UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r5TextBox);
			this->parameterGroupBox->Controls->Add(this->r5Label);
			this->parameterGroupBox->Controls->Add(this->couplerLabel);
			this->parameterGroupBox->Controls->Add(this->errorLabel3);
			this->parameterGroupBox->Controls->Add(this->errorLabel2);
			this->parameterGroupBox->Controls->Add(this->errorLabel1);
			this->parameterGroupBox->Controls->Add(this->r3UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r2UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r1UnitLabel);
			this->parameterGroupBox->Controls->Add(this->r3TextBox);
			this->parameterGroupBox->Controls->Add(this->r3Label);
			this->parameterGroupBox->Controls->Add(this->r2TextBox);
			this->parameterGroupBox->Controls->Add(this->r2Label);
			this->parameterGroupBox->Controls->Add(this->r1TextBox);
			this->parameterGroupBox->Controls->Add(this->r1Label);
			this->parameterGroupBox->Controls->Add(this->lengthLabel);
			this->parameterGroupBox->Controls->Add(this->cmRadioButton);
			this->parameterGroupBox->Controls->Add(this->mmRadioButton);
			this->parameterGroupBox->Controls->Add(this->selectUnitLabel);
			this->parameterGroupBox->Location = System::Drawing::Point(25, 25);
			this->parameterGroupBox->Name = L"parameterGroupBox";
			this->parameterGroupBox->Size = System::Drawing::Size(450, 337);
			this->parameterGroupBox->TabIndex = 0;
			this->parameterGroupBox->TabStop = false;
			this->parameterGroupBox->Text = L"Mechanism Parameters";
			// 
			// helpButton
			// 
			this->helpButton->Location = System::Drawing::Point(369, 269);
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(74, 24);
			this->helpButton->TabIndex = 44;
			this->helpButton->Text = L"Help";
			this->helpButton->UseVisualStyleBackColor = true;
			this->helpButton->Click += gcnew System::EventHandler(this, &SliderCrankWindow::helpButton_Click);
			// 
			// errorLabel6
			// 
			this->errorLabel6->AutoSize = true;
			this->errorLabel6->ForeColor = System::Drawing::Color::Red;
			this->errorLabel6->Location = System::Drawing::Point(228, 293);
			this->errorLabel6->Name = L"errorLabel6";
			this->errorLabel6->Size = System::Drawing::Size(83, 17);
			this->errorLabel6->TabIndex = 43;
			this->errorLabel6->Text = L"Invalid input";
			this->errorLabel6->Visible = false;
			// 
			// errorLabel5
			// 
			this->errorLabel5->AutoSize = true;
			this->errorLabel5->ForeColor = System::Drawing::Color::Red;
			this->errorLabel5->Location = System::Drawing::Point(41, 293);
			this->errorLabel5->Name = L"errorLabel5";
			this->errorLabel5->Size = System::Drawing::Size(83, 17);
			this->errorLabel5->TabIndex = 42;
			this->errorLabel5->Text = L"Invalid input";
			this->errorLabel5->Visible = false;
			// 
			// r6UnitLabel
			// 
			this->r6UnitLabel->AutoSize = true;
			this->r6UnitLabel->Location = System::Drawing::Point(332, 273);
			this->r6UnitLabel->Name = L"r6UnitLabel";
			this->r6UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r6UnitLabel->TabIndex = 41;
			this->r6UnitLabel->Text = L"mm";
			// 
			// r6TextBox
			// 
			this->r6TextBox->Location = System::Drawing::Point(226, 270);
			this->r6TextBox->Name = L"r6TextBox";
			this->r6TextBox->Size = System::Drawing::Size(100, 22);
			this->r6TextBox->TabIndex = 40;
			this->r6TextBox->TextChanged += gcnew System::EventHandler(this, &SliderCrankWindow::TextBox_TextChanged);
			// 
			// r6Label
			// 
			this->r6Label->AutoSize = true;
			this->r6Label->Location = System::Drawing::Point(194, 273);
			this->r6Label->Name = L"r6Label";
			this->r6Label->Size = System::Drawing::Size(25, 17);
			this->r6Label->TabIndex = 39;
			this->r6Label->Text = L"r6:";
			// 
			// r5UnitLabel
			// 
			this->r5UnitLabel->AutoSize = true;
			this->r5UnitLabel->Location = System::Drawing::Point(148, 273);
			this->r5UnitLabel->Name = L"r5UnitLabel";
			this->r5UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r5UnitLabel->TabIndex = 38;
			this->r5UnitLabel->Text = L"mm";
			// 
			// r5TextBox
			// 
			this->r5TextBox->Location = System::Drawing::Point(42, 270);
			this->r5TextBox->Name = L"r5TextBox";
			this->r5TextBox->Size = System::Drawing::Size(100, 22);
			this->r5TextBox->TabIndex = 37;
			this->r5TextBox->TextChanged += gcnew System::EventHandler(this, &SliderCrankWindow::TextBox_TextChanged);
			// 
			// r5Label
			// 
			this->r5Label->AutoSize = true;
			this->r5Label->Location = System::Drawing::Point(10, 273);
			this->r5Label->Name = L"r5Label";
			this->r5Label->Size = System::Drawing::Size(25, 17);
			this->r5Label->TabIndex = 36;
			this->r5Label->Text = L"r5:";
			// 
			// couplerLabel
			// 
			this->couplerLabel->AutoSize = true;
			this->couplerLabel->Location = System::Drawing::Point(9, 241);
			this->couplerLabel->Name = L"couplerLabel";
			this->couplerLabel->Size = System::Drawing::Size(174, 17);
			this->couplerLabel->TabIndex = 35;
			this->couplerLabel->Text = L"Coupler point coordinates:";
			// 
			// errorLabel3
			// 
			this->errorLabel3->AutoSize = true;
			this->errorLabel3->BackColor = System::Drawing::SystemColors::Control;
			this->errorLabel3->ForeColor = System::Drawing::Color::Red;
			this->errorLabel3->Location = System::Drawing::Point(281, 191);
			this->errorLabel3->Name = L"errorLabel3";
			this->errorLabel3->Size = System::Drawing::Size(87, 17);
			this->errorLabel3->TabIndex = 15;
			this->errorLabel3->Text = L"Invalid input.";
			this->errorLabel3->Visible = false;
			// 
			// errorLabel2
			// 
			this->errorLabel2->AutoSize = true;
			this->errorLabel2->BackColor = System::Drawing::SystemColors::Control;
			this->errorLabel2->ForeColor = System::Drawing::Color::Red;
			this->errorLabel2->Location = System::Drawing::Point(281, 142);
			this->errorLabel2->Name = L"errorLabel2";
			this->errorLabel2->Size = System::Drawing::Size(87, 17);
			this->errorLabel2->TabIndex = 14;
			this->errorLabel2->Text = L"Invalid input.";
			this->errorLabel2->Visible = false;
			// 
			// errorLabel1
			// 
			this->errorLabel1->AutoSize = true;
			this->errorLabel1->BackColor = System::Drawing::SystemColors::Control;
			this->errorLabel1->ForeColor = System::Drawing::Color::Red;
			this->errorLabel1->Location = System::Drawing::Point(281, 93);
			this->errorLabel1->Name = L"errorLabel1";
			this->errorLabel1->Size = System::Drawing::Size(87, 17);
			this->errorLabel1->TabIndex = 13;
			this->errorLabel1->Text = L"Invalid input.";
			this->errorLabel1->Visible = false;
			// 
			// r3UnitLabel
			// 
			this->r3UnitLabel->AutoSize = true;
			this->r3UnitLabel->Location = System::Drawing::Point(245, 191);
			this->r3UnitLabel->Name = L"r3UnitLabel";
			this->r3UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r3UnitLabel->TabIndex = 12;
			this->r3UnitLabel->Text = L"mm";
			// 
			// r2UnitLabel
			// 
			this->r2UnitLabel->AutoSize = true;
			this->r2UnitLabel->Location = System::Drawing::Point(245, 142);
			this->r2UnitLabel->Name = L"r2UnitLabel";
			this->r2UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r2UnitLabel->TabIndex = 11;
			this->r2UnitLabel->Text = L"mm";
			// 
			// r1UnitLabel
			// 
			this->r1UnitLabel->AutoSize = true;
			this->r1UnitLabel->Location = System::Drawing::Point(245, 93);
			this->r1UnitLabel->Name = L"r1UnitLabel";
			this->r1UnitLabel->Size = System::Drawing::Size(30, 17);
			this->r1UnitLabel->TabIndex = 10;
			this->r1UnitLabel->Text = L"mm";
			// 
			// r3TextBox
			// 
			this->r3TextBox->Location = System::Drawing::Point(101, 188);
			this->r3TextBox->Name = L"r3TextBox";
			this->r3TextBox->Size = System::Drawing::Size(138, 22);
			this->r3TextBox->TabIndex = 9;
			this->r3TextBox->TextChanged += gcnew System::EventHandler(this, &SliderCrankWindow::TextBox_TextChanged);
			// 
			// r3Label
			// 
			this->r3Label->AutoSize = true;
			this->r3Label->Location = System::Drawing::Point(6, 191);
			this->r3Label->Name = L"r3Label";
			this->r3Label->Size = System::Drawing::Size(88, 17);
			this->r3Label->TabIndex = 8;
			this->r3Label->Text = L"Coupler (r3):";
			// 
			// r2TextBox
			// 
			this->r2TextBox->Location = System::Drawing::Point(101, 139);
			this->r2TextBox->Name = L"r2TextBox";
			this->r2TextBox->Size = System::Drawing::Size(138, 22);
			this->r2TextBox->TabIndex = 7;
			this->r2TextBox->TextChanged += gcnew System::EventHandler(this, &SliderCrankWindow::TextBox_TextChanged);
			// 
			// r2Label
			// 
			this->r2Label->AutoSize = true;
			this->r2Label->Location = System::Drawing::Point(6, 142);
			this->r2Label->Name = L"r2Label";
			this->r2Label->Size = System::Drawing::Size(76, 17);
			this->r2Label->TabIndex = 6;
			this->r2Label->Text = L"Crank (r2):";
			// 
			// r1TextBox
			// 
			this->r1TextBox->Location = System::Drawing::Point(101, 90);
			this->r1TextBox->Name = L"r1TextBox";
			this->r1TextBox->Size = System::Drawing::Size(138, 22);
			this->r1TextBox->TabIndex = 5;
			this->r1TextBox->TextChanged += gcnew System::EventHandler(this, &SliderCrankWindow::TextBox_TextChanged);
			// 
			// r1Label
			// 
			this->r1Label->AutoSize = true;
			this->r1Label->Location = System::Drawing::Point(6, 93);
			this->r1Label->Name = L"r1Label";
			this->r1Label->Size = System::Drawing::Size(77, 17);
			this->r1Label->TabIndex = 4;
			this->r1Label->Text = L"Offset (r1):";
			// 
			// lengthLabel
			// 
			this->lengthLabel->AutoSize = true;
			this->lengthLabel->Location = System::Drawing::Point(7, 52);
			this->lengthLabel->Name = L"lengthLabel";
			this->lengthLabel->Size = System::Drawing::Size(56, 17);
			this->lengthLabel->TabIndex = 3;
			this->lengthLabel->Text = L"Length:";
			// 
			// cmRadioButton
			// 
			this->cmRadioButton->AutoSize = true;
			this->cmRadioButton->Location = System::Drawing::Point(383, 21);
			this->cmRadioButton->Name = L"cmRadioButton";
			this->cmRadioButton->Size = System::Drawing::Size(47, 21);
			this->cmRadioButton->TabIndex = 2;
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
			this->mmRadioButton->TabIndex = 1;
			this->mmRadioButton->TabStop = true;
			this->mmRadioButton->Text = L"mm";
			this->mmRadioButton->UseVisualStyleBackColor = true;
			this->mmRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SliderCrankWindow::mmRadioButton_CheckedChanged);
			// 
			// selectUnitLabel
			// 
			this->selectUnitLabel->AutoSize = true;
			this->selectUnitLabel->Location = System::Drawing::Point(283, 23);
			this->selectUnitLabel->Name = L"selectUnitLabel";
			this->selectUnitLabel->Size = System::Drawing::Size(37, 17);
			this->selectUnitLabel->TabIndex = 0;
			this->selectUnitLabel->Text = L"Unit:";
			// 
			// inputGroupBox
			// 
			this->inputGroupBox->Controls->Add(this->errorLabel4);
			this->inputGroupBox->Controls->Add(this->inputUnitLabel);
			this->inputGroupBox->Controls->Add(this->rpmRadioButton);
			this->inputGroupBox->Controls->Add(this->radRadioButton);
			this->inputGroupBox->Controls->Add(this->degreeRadioButton);
			this->inputGroupBox->Controls->Add(this->selectInputLabel);
			this->inputGroupBox->Controls->Add(this->inputTextBox);
			this->inputGroupBox->Controls->Add(this->angularSpeedLabel);
			this->inputGroupBox->Controls->Add(this->noteLabel);
			this->inputGroupBox->Location = System::Drawing::Point(25, 379);
			this->inputGroupBox->Name = L"inputGroupBox";
			this->inputGroupBox->Size = System::Drawing::Size(450, 154);
			this->inputGroupBox->TabIndex = 1;
			this->inputGroupBox->TabStop = false;
			this->inputGroupBox->Text = L"Input Angular Velocity";
			// 
			// errorLabel4
			// 
			this->errorLabel4->AutoSize = true;
			this->errorLabel4->BackColor = System::Drawing::SystemColors::Control;
			this->errorLabel4->ForeColor = System::Drawing::Color::Red;
			this->errorLabel4->Location = System::Drawing::Point(130, 117);
			this->errorLabel4->Name = L"errorLabel4";
			this->errorLabel4->Size = System::Drawing::Size(87, 17);
			this->errorLabel4->TabIndex = 16;
			this->errorLabel4->Text = L"Invalid input.";
			this->errorLabel4->Visible = false;
			// 
			// inputUnitLabel
			// 
			this->inputUnitLabel->AutoSize = true;
			this->inputUnitLabel->Location = System::Drawing::Point(244, 87);
			this->inputUnitLabel->Name = L"inputUnitLabel";
			this->inputUnitLabel->Size = System::Drawing::Size(64, 17);
			this->inputUnitLabel->TabIndex = 7;
			this->inputUnitLabel->Text = L"degree/s";
			// 
			// rpmRadioButton
			// 
			this->rpmRadioButton->AutoSize = true;
			this->rpmRadioButton->Location = System::Drawing::Point(345, 92);
			this->rpmRadioButton->Name = L"rpmRadioButton";
			this->rpmRadioButton->Size = System::Drawing::Size(53, 21);
			this->rpmRadioButton->TabIndex = 6;
			this->rpmRadioButton->Text = L"rpm";
			this->rpmRadioButton->UseVisualStyleBackColor = true;
			this->rpmRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SliderCrankWindow::rpmRadioButton_CheckedChanged);
			// 
			// radRadioButton
			// 
			this->radRadioButton->AutoSize = true;
			this->radRadioButton->Location = System::Drawing::Point(345, 65);
			this->radRadioButton->Name = L"radRadioButton";
			this->radRadioButton->Size = System::Drawing::Size(61, 21);
			this->radRadioButton->TabIndex = 5;
			this->radRadioButton->Text = L"rad/s";
			this->radRadioButton->UseVisualStyleBackColor = true;
			this->radRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SliderCrankWindow::radRadioButton_CheckedChanged);
			// 
			// degreeRadioButton
			// 
			this->degreeRadioButton->AutoSize = true;
			this->degreeRadioButton->Checked = true;
			this->degreeRadioButton->Location = System::Drawing::Point(345, 38);
			this->degreeRadioButton->Name = L"degreeRadioButton";
			this->degreeRadioButton->Size = System::Drawing::Size(85, 21);
			this->degreeRadioButton->TabIndex = 4;
			this->degreeRadioButton->TabStop = true;
			this->degreeRadioButton->Text = L"degree/s";
			this->degreeRadioButton->UseVisualStyleBackColor = true;
			this->degreeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SliderCrankWindow::degreeRadioButton_CheckedChanged);
			// 
			// selectInputLabel
			// 
			this->selectInputLabel->AutoSize = true;
			this->selectInputLabel->Location = System::Drawing::Point(301, 37);
			this->selectInputLabel->Name = L"selectInputLabel";
			this->selectInputLabel->Size = System::Drawing::Size(37, 17);
			this->selectInputLabel->TabIndex = 3;
			this->selectInputLabel->Text = L"Unit:";
			// 
			// inputTextBox
			// 
			this->inputTextBox->Location = System::Drawing::Point(120, 87);
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(115, 22);
			this->inputTextBox->TabIndex = 2;
			this->inputTextBox->TextChanged += gcnew System::EventHandler(this, &SliderCrankWindow::TextBox_TextChanged);
			// 
			// angularSpeedLabel
			// 
			this->angularSpeedLabel->AutoSize = true;
			this->angularSpeedLabel->Location = System::Drawing::Point(9, 87);
			this->angularSpeedLabel->Name = L"angularSpeedLabel";
			this->angularSpeedLabel->Size = System::Drawing::Size(104, 17);
			this->angularSpeedLabel->TabIndex = 1;
			this->angularSpeedLabel->Text = L"Angular speed:";
			// 
			// noteLabel
			// 
			this->noteLabel->AutoSize = true;
			this->noteLabel->Location = System::Drawing::Point(6, 38);
			this->noteLabel->Name = L"noteLabel";
			this->noteLabel->Size = System::Drawing::Size(190, 17);
			this->noteLabel->TabIndex = 0;
			this->noteLabel->Text = L"Positive: CCW, Negative: CW";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(508, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(527, 337);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// descriptionGroupBox
			// 
			this->descriptionGroupBox->Controls->Add(this->description);
			this->descriptionGroupBox->Location = System::Drawing::Point(508, 384);
			this->descriptionGroupBox->Name = L"descriptionGroupBox";
			this->descriptionGroupBox->Size = System::Drawing::Size(527, 149);
			this->descriptionGroupBox->TabIndex = 3;
			this->descriptionGroupBox->TabStop = false;
			this->descriptionGroupBox->Text = L"Description";
			// 
			// description
			// 
			this->description->AutoSize = true;
			this->description->Location = System::Drawing::Point(6, 30);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(470, 102);
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
			this->okButton->Click += gcnew System::EventHandler(this, &SliderCrankWindow::okButton_Click);
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(252, 580);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(150, 30);
			this->backButton->TabIndex = 5;
			this->backButton->Text = L"<  Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &SliderCrankWindow::backButton_Click);
			// 
			// resetButton
			// 
			this->resetButton->Location = System::Drawing::Point(674, 580);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(150, 30);
			this->resetButton->TabIndex = 6;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &SliderCrankWindow::resetButton_Click);
			// 
			// SliderCrankWindow
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
			this->Name = L"SliderCrankWindow";
			this->Text = L"Slider Crank Mechanism";
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
			r5UnitLabel->Text = "mm";
			r6UnitLabel->Text = "mm";
		}
		else
		{
			r1UnitLabel->Text = "cm";
			r2UnitLabel->Text = "cm";
			r3UnitLabel->Text = "cm";
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
			else if (Convert::ToDouble(input) < 0 && (index == 1 || index == 2))
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
			omega = value;
			break;
		case 4:
			r5 = value;
			break;
		case 5:
			r6 = value;
			break;
		}

		if (abs(r1) > r2 + r3 || !(r2 < r3 && abs(r1) <= r3 - r2))
			okButton->Enabled = false;
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
			r5 *= 10.0;
			r6 *= 10.0;
		}
		double omega2 = omega;
		if (degreeRadioButton->Checked == true)
			omega2 *= dtr;
		if (rpmRadioButton->Checked == true)
			omega2 = omega2 * 2 * PI / 60;
		double r[4] = { r1,r2,r3 };
		double c[2] = { r5,r6 };
		SliderCrank fb(r, c, omega2, 0);
		DrawSliderCrank^ dlg = gcnew DrawSliderCrank(fb);
		dlg->ShowDialog();
	}
private: System::Void helpButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	HelpWindow2^ dlg = gcnew HelpWindow2();
	dlg->Show();
}
};
}
