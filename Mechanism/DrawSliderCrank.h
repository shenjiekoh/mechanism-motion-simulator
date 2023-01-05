#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <gl/glut.h>
#include <cmath>
#include <iostream>
#include "Mechanism.h"
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glaux.lib")
#pragma comment(lib,"glut32.lib")

namespace Mechanism {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DrawSliderCrank
	/// </summary>
	public ref class DrawSliderCrank : public System::Windows::Forms::Form
	{
	public:
		DrawSliderCrank(SliderCrank& sc)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			// Get Handle
			m_hWnd = (HWND)this->panel1->Handle.ToInt32();
			m_hDC = ::GetDC(m_hWnd);

			// Set pixel format
			PIXELFORMATDESCRIPTOR pfd;
			ZeroMemory(&pfd, sizeof(pfd));
			pfd.nSize = sizeof(pfd);
			pfd.nVersion = 1;
			pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pfd.iPixelType = PFD_TYPE_RGBA;
			pfd.cColorBits = 32;
			pfd.cDepthBits = 32;
			pfd.iLayerType = PFD_MAIN_PLANE;
			int nFormat = ::ChoosePixelFormat(m_hDC, &pfd);
			::SetPixelFormat(m_hDC, nFormat, &pfd);

			// Create OpenGL Rendering Context
			m_hRC = ::wglCreateContext(m_hDC);
			if (m_hRC == 0)
				MessageBox::Show("Create Render Context Error");

			// Assign OpenGL Rendering Context
			if (::wglMakeCurrent(m_hDC, m_hRC) == false)
				MessageBox::Show("wglMakeCurrent Error");

			double* r = sc.getLength();
			r1 = r[0];
			r2 = r[1];
			r3 = r[2];
			double* c = sc.getCoupler();
			r5 = c[0];
			r6 = c[1];
			omega = sc.Omega();
			timer1->Interval = 10;
			timer1->Enabled = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DrawSliderCrank()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		HWND m_hWnd;
		HDC  m_hDC;
		HGLRC m_hRC;
		int width;
		int height;
		System::Drawing::Size OpenGLSize;

		double r1 = 0;
		double r2 = 0;
		double r3 = 0;
		double r5 = 0;
		double r6 = 0;
		double theta2 = 0;
		double theta3 = 0;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::GroupBox^ positionGroupBox;

	private: System::Windows::Forms::Label^ x1Label;
	private: System::Windows::Forms::TextBox^ x1TextBox;
	private: System::Windows::Forms::TextBox^ y1TextBox;



	private: System::Windows::Forms::Label^ y1Label;
	private: System::Windows::Forms::TextBox^ y3TextBox;


	private: System::Windows::Forms::Label^ y3Label;

	private: System::Windows::Forms::TextBox^ x3TextBox;

	private: System::Windows::Forms::Label^ x3Label;

	private: System::Windows::Forms::TextBox^ y2TextBox;

	private: System::Windows::Forms::Label^ y2Label;

	private: System::Windows::Forms::TextBox^ x2TextBox;

	private: System::Windows::Forms::Label^ x2Label;
private: System::Windows::Forms::TextBox^ r4TextBox;


private: System::Windows::Forms::Label^ r4Label;

private: System::Windows::Forms::TextBox^ theta3TextBox;

private: System::Windows::Forms::Label^ theta3Label;

private: System::Windows::Forms::TextBox^ theta2TextBox;

private: System::Windows::Forms::Label^ theta2Label;
private: System::Windows::Forms::GroupBox^ velGroupBox;
private: System::Windows::Forms::TextBox^ r4dTextBox;

private: System::Windows::Forms::Label^ r4dLabel;

private: System::Windows::Forms::TextBox^ theta3dTextBox;

private: System::Windows::Forms::Label^ theta3dLabel;
private: System::Windows::Forms::GroupBox^ accelGroupBox;
private: System::Windows::Forms::TextBox^ r4ddTextBox;



private: System::Windows::Forms::Label^ r4ddLabel;

private: System::Windows::Forms::TextBox^ theta3ddTextBox;

private: System::Windows::Forms::Label^ theta3ddLabel;
private: System::Windows::Forms::Button^ pauseButton;
private: System::Windows::Forms::GroupBox^ propGroupBox;
private: System::Windows::Forms::TextBox^ trTextBox;

private: System::Windows::Forms::Label^ trLabel;
private: System::Windows::Forms::TextBox^ strokeTextBox;

private: System::Windows::Forms::Label^ strokeLabel;
private: System::Windows::Forms::TextBox^ ycTextBox;
private: System::Windows::Forms::Label^ ycLabel;
private: System::Windows::Forms::TextBox^ xcTextBox;
private: System::Windows::Forms::Label^ xcLabel;
private: System::Windows::Forms::TextBox^ ycdTextBox;
private: System::Windows::Forms::Label^ ycdLabel;
private: System::Windows::Forms::TextBox^ xcdTextBox;
private: System::Windows::Forms::Label^ xcdLabel;
private: System::Windows::Forms::TextBox^ ycddTextBox;
private: System::Windows::Forms::Label^ ycddLabel;
private: System::Windows::Forms::TextBox^ xcddTextBox;
private: System::Windows::Forms::Label^ xcddLabel;
private: System::Windows::Forms::CheckBox^ drawCurveCheckBox;




		   double omega = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->positionGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->r4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->r4Label = (gcnew System::Windows::Forms::Label());
			this->theta3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta3Label = (gcnew System::Windows::Forms::Label());
			this->theta2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta2Label = (gcnew System::Windows::Forms::Label());
			this->y3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y3Label = (gcnew System::Windows::Forms::Label());
			this->x3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x3Label = (gcnew System::Windows::Forms::Label());
			this->y2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y2Label = (gcnew System::Windows::Forms::Label());
			this->x2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x2Label = (gcnew System::Windows::Forms::Label());
			this->y1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y1Label = (gcnew System::Windows::Forms::Label());
			this->x1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x1Label = (gcnew System::Windows::Forms::Label());
			this->velGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->r4dTextBox = (gcnew System::Windows::Forms::TextBox());
			this->r4dLabel = (gcnew System::Windows::Forms::Label());
			this->theta3dTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta3dLabel = (gcnew System::Windows::Forms::Label());
			this->accelGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->r4ddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->r4ddLabel = (gcnew System::Windows::Forms::Label());
			this->theta3ddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta3ddLabel = (gcnew System::Windows::Forms::Label());
			this->pauseButton = (gcnew System::Windows::Forms::Button());
			this->propGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->trTextBox = (gcnew System::Windows::Forms::TextBox());
			this->trLabel = (gcnew System::Windows::Forms::Label());
			this->strokeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->strokeLabel = (gcnew System::Windows::Forms::Label());
			this->ycTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ycLabel = (gcnew System::Windows::Forms::Label());
			this->xcTextBox = (gcnew System::Windows::Forms::TextBox());
			this->xcLabel = (gcnew System::Windows::Forms::Label());
			this->ycdTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ycdLabel = (gcnew System::Windows::Forms::Label());
			this->xcdTextBox = (gcnew System::Windows::Forms::TextBox());
			this->xcdLabel = (gcnew System::Windows::Forms::Label());
			this->ycddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ycddLabel = (gcnew System::Windows::Forms::Label());
			this->xcddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->xcddLabel = (gcnew System::Windows::Forms::Label());
			this->drawCurveCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->positionGroupBox->SuspendLayout();
			this->velGroupBox->SuspendLayout();
			this->accelGroupBox->SuspendLayout();
			this->propGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(674, 674);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &DrawSliderCrank::timer1_Tick);
			// 
			// positionGroupBox
			// 
			this->positionGroupBox->Controls->Add(this->ycTextBox);
			this->positionGroupBox->Controls->Add(this->ycLabel);
			this->positionGroupBox->Controls->Add(this->xcTextBox);
			this->positionGroupBox->Controls->Add(this->xcLabel);
			this->positionGroupBox->Controls->Add(this->r4TextBox);
			this->positionGroupBox->Controls->Add(this->r4Label);
			this->positionGroupBox->Controls->Add(this->theta3TextBox);
			this->positionGroupBox->Controls->Add(this->theta3Label);
			this->positionGroupBox->Controls->Add(this->theta2TextBox);
			this->positionGroupBox->Controls->Add(this->theta2Label);
			this->positionGroupBox->Controls->Add(this->y3TextBox);
			this->positionGroupBox->Controls->Add(this->y3Label);
			this->positionGroupBox->Controls->Add(this->x3TextBox);
			this->positionGroupBox->Controls->Add(this->x3Label);
			this->positionGroupBox->Controls->Add(this->y2TextBox);
			this->positionGroupBox->Controls->Add(this->y2Label);
			this->positionGroupBox->Controls->Add(this->x2TextBox);
			this->positionGroupBox->Controls->Add(this->x2Label);
			this->positionGroupBox->Controls->Add(this->y1TextBox);
			this->positionGroupBox->Controls->Add(this->y1Label);
			this->positionGroupBox->Controls->Add(this->x1TextBox);
			this->positionGroupBox->Controls->Add(this->x1Label);
			this->positionGroupBox->Location = System::Drawing::Point(691, 27);
			this->positionGroupBox->Name = L"positionGroupBox";
			this->positionGroupBox->Size = System::Drawing::Size(338, 236);
			this->positionGroupBox->TabIndex = 1;
			this->positionGroupBox->TabStop = false;
			this->positionGroupBox->Text = L"Position (mm or degree)";
			// 
			// r4TextBox
			// 
			this->r4TextBox->Location = System::Drawing::Point(56, 164);
			this->r4TextBox->Name = L"r4TextBox";
			this->r4TextBox->ReadOnly = true;
			this->r4TextBox->Size = System::Drawing::Size(100, 22);
			this->r4TextBox->TabIndex = 17;
			this->r4TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// r4Label
			// 
			this->r4Label->AutoSize = true;
			this->r4Label->Location = System::Drawing::Point(27, 167);
			this->r4Label->Name = L"r4Label";
			this->r4Label->Size = System::Drawing::Size(21, 17);
			this->r4Label->TabIndex = 16;
			this->r4Label->Text = L"r4";
			// 
			// theta3TextBox
			// 
			this->theta3TextBox->Location = System::Drawing::Point(236, 130);
			this->theta3TextBox->Name = L"theta3TextBox";
			this->theta3TextBox->ReadOnly = true;
			this->theta3TextBox->Size = System::Drawing::Size(82, 22);
			this->theta3TextBox->TabIndex = 15;
			this->theta3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta3Label
			// 
			this->theta3Label->AutoSize = true;
			this->theta3Label->Location = System::Drawing::Point(189, 133);
			this->theta3Label->Name = L"theta3Label";
			this->theta3Label->Size = System::Drawing::Size(48, 17);
			this->theta3Label->TabIndex = 14;
			this->theta3Label->Text = L"theta3";
			// 
			// theta2TextBox
			// 
			this->theta2TextBox->Location = System::Drawing::Point(72, 130);
			this->theta2TextBox->Name = L"theta2TextBox";
			this->theta2TextBox->ReadOnly = true;
			this->theta2TextBox->Size = System::Drawing::Size(82, 22);
			this->theta2TextBox->TabIndex = 13;
			this->theta2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta2Label
			// 
			this->theta2Label->AutoSize = true;
			this->theta2Label->Location = System::Drawing::Point(25, 133);
			this->theta2Label->Name = L"theta2Label";
			this->theta2Label->Size = System::Drawing::Size(48, 17);
			this->theta2Label->TabIndex = 12;
			this->theta2Label->Text = L"theta2";
			// 
			// y3TextBox
			// 
			this->y3TextBox->Location = System::Drawing::Point(218, 96);
			this->y3TextBox->Name = L"y3TextBox";
			this->y3TextBox->ReadOnly = true;
			this->y3TextBox->Size = System::Drawing::Size(100, 22);
			this->y3TextBox->TabIndex = 11;
			this->y3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y3Label
			// 
			this->y3Label->AutoSize = true;
			this->y3Label->Location = System::Drawing::Point(189, 99);
			this->y3Label->Name = L"y3Label";
			this->y3Label->Size = System::Drawing::Size(23, 17);
			this->y3Label->TabIndex = 10;
			this->y3Label->Text = L"y3";
			// 
			// x3TextBox
			// 
			this->x3TextBox->Location = System::Drawing::Point(54, 96);
			this->x3TextBox->Name = L"x3TextBox";
			this->x3TextBox->ReadOnly = true;
			this->x3TextBox->Size = System::Drawing::Size(100, 22);
			this->x3TextBox->TabIndex = 9;
			this->x3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x3Label
			// 
			this->x3Label->AutoSize = true;
			this->x3Label->Location = System::Drawing::Point(25, 99);
			this->x3Label->Name = L"x3Label";
			this->x3Label->Size = System::Drawing::Size(22, 17);
			this->x3Label->TabIndex = 8;
			this->x3Label->Text = L"x3";
			// 
			// y2TextBox
			// 
			this->y2TextBox->Location = System::Drawing::Point(218, 62);
			this->y2TextBox->Name = L"y2TextBox";
			this->y2TextBox->ReadOnly = true;
			this->y2TextBox->Size = System::Drawing::Size(100, 22);
			this->y2TextBox->TabIndex = 7;
			this->y2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y2Label
			// 
			this->y2Label->AutoSize = true;
			this->y2Label->Location = System::Drawing::Point(189, 65);
			this->y2Label->Name = L"y2Label";
			this->y2Label->Size = System::Drawing::Size(23, 17);
			this->y2Label->TabIndex = 6;
			this->y2Label->Text = L"y2";
			// 
			// x2TextBox
			// 
			this->x2TextBox->Location = System::Drawing::Point(54, 62);
			this->x2TextBox->Name = L"x2TextBox";
			this->x2TextBox->ReadOnly = true;
			this->x2TextBox->Size = System::Drawing::Size(100, 22);
			this->x2TextBox->TabIndex = 5;
			this->x2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x2Label
			// 
			this->x2Label->AutoSize = true;
			this->x2Label->Location = System::Drawing::Point(25, 65);
			this->x2Label->Name = L"x2Label";
			this->x2Label->Size = System::Drawing::Size(22, 17);
			this->x2Label->TabIndex = 4;
			this->x2Label->Text = L"x2";
			// 
			// y1TextBox
			// 
			this->y1TextBox->Location = System::Drawing::Point(218, 28);
			this->y1TextBox->Name = L"y1TextBox";
			this->y1TextBox->ReadOnly = true;
			this->y1TextBox->Size = System::Drawing::Size(100, 22);
			this->y1TextBox->TabIndex = 3;
			this->y1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y1Label
			// 
			this->y1Label->AutoSize = true;
			this->y1Label->Location = System::Drawing::Point(189, 31);
			this->y1Label->Name = L"y1Label";
			this->y1Label->Size = System::Drawing::Size(23, 17);
			this->y1Label->TabIndex = 2;
			this->y1Label->Text = L"y1";
			// 
			// x1TextBox
			// 
			this->x1TextBox->Location = System::Drawing::Point(54, 28);
			this->x1TextBox->Name = L"x1TextBox";
			this->x1TextBox->ReadOnly = true;
			this->x1TextBox->Size = System::Drawing::Size(100, 22);
			this->x1TextBox->TabIndex = 1;
			this->x1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x1Label
			// 
			this->x1Label->AutoSize = true;
			this->x1Label->Location = System::Drawing::Point(25, 31);
			this->x1Label->Name = L"x1Label";
			this->x1Label->Size = System::Drawing::Size(22, 17);
			this->x1Label->TabIndex = 0;
			this->x1Label->Text = L"x1";
			// 
			// velGroupBox
			// 
			this->velGroupBox->Controls->Add(this->ycdTextBox);
			this->velGroupBox->Controls->Add(this->ycdLabel);
			this->velGroupBox->Controls->Add(this->xcdTextBox);
			this->velGroupBox->Controls->Add(this->xcdLabel);
			this->velGroupBox->Controls->Add(this->r4dTextBox);
			this->velGroupBox->Controls->Add(this->r4dLabel);
			this->velGroupBox->Controls->Add(this->theta3dTextBox);
			this->velGroupBox->Controls->Add(this->theta3dLabel);
			this->velGroupBox->Location = System::Drawing::Point(691, 269);
			this->velGroupBox->Name = L"velGroupBox";
			this->velGroupBox->Size = System::Drawing::Size(338, 98);
			this->velGroupBox->TabIndex = 2;
			this->velGroupBox->TabStop = false;
			this->velGroupBox->Text = L"Linear/Angular Velocity (mm/s or rad/s)";
			// 
			// r4dTextBox
			// 
			this->r4dTextBox->Location = System::Drawing::Point(218, 30);
			this->r4dTextBox->Name = L"r4dTextBox";
			this->r4dTextBox->ReadOnly = true;
			this->r4dTextBox->Size = System::Drawing::Size(98, 22);
			this->r4dTextBox->TabIndex = 19;
			this->r4dTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// r4dLabel
			// 
			this->r4dLabel->AutoSize = true;
			this->r4dLabel->Location = System::Drawing::Point(189, 33);
			this->r4dLabel->Name = L"r4dLabel";
			this->r4dLabel->Size = System::Drawing::Size(29, 17);
			this->r4dLabel->TabIndex = 18;
			this->r4dLabel->Text = L"r4d";
			// 
			// theta3dTextBox
			// 
			this->theta3dTextBox->Location = System::Drawing::Point(70, 30);
			this->theta3dTextBox->Name = L"theta3dTextBox";
			this->theta3dTextBox->ReadOnly = true;
			this->theta3dTextBox->Size = System::Drawing::Size(84, 22);
			this->theta3dTextBox->TabIndex = 17;
			this->theta3dTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta3dLabel
			// 
			this->theta3dLabel->AutoSize = true;
			this->theta3dLabel->Location = System::Drawing::Point(8, 33);
			this->theta3dLabel->Name = L"theta3dLabel";
			this->theta3dLabel->Size = System::Drawing::Size(56, 17);
			this->theta3dLabel->TabIndex = 16;
			this->theta3dLabel->Text = L"theta3d";
			// 
			// accelGroupBox
			// 
			this->accelGroupBox->Controls->Add(this->ycddTextBox);
			this->accelGroupBox->Controls->Add(this->r4ddTextBox);
			this->accelGroupBox->Controls->Add(this->ycddLabel);
			this->accelGroupBox->Controls->Add(this->r4ddLabel);
			this->accelGroupBox->Controls->Add(this->xcddTextBox);
			this->accelGroupBox->Controls->Add(this->xcddLabel);
			this->accelGroupBox->Controls->Add(this->theta3ddTextBox);
			this->accelGroupBox->Controls->Add(this->theta3ddLabel);
			this->accelGroupBox->Location = System::Drawing::Point(691, 373);
			this->accelGroupBox->Name = L"accelGroupBox";
			this->accelGroupBox->Size = System::Drawing::Size(338, 98);
			this->accelGroupBox->TabIndex = 3;
			this->accelGroupBox->TabStop = false;
			this->accelGroupBox->Text = L"Linear/Angular Acceleration (mm/s2 or rad/s2)";
			// 
			// r4ddTextBox
			// 
			this->r4ddTextBox->Location = System::Drawing::Point(220, 34);
			this->r4ddTextBox->Name = L"r4ddTextBox";
			this->r4ddTextBox->ReadOnly = true;
			this->r4ddTextBox->Size = System::Drawing::Size(98, 22);
			this->r4ddTextBox->TabIndex = 23;
			this->r4ddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// r4ddLabel
			// 
			this->r4ddLabel->AutoSize = true;
			this->r4ddLabel->Location = System::Drawing::Point(183, 37);
			this->r4ddLabel->Name = L"r4ddLabel";
			this->r4ddLabel->Size = System::Drawing::Size(37, 17);
			this->r4ddLabel->TabIndex = 22;
			this->r4ddLabel->Text = L"r4dd";
			// 
			// theta3ddTextBox
			// 
			this->theta3ddTextBox->Location = System::Drawing::Point(72, 34);
			this->theta3ddTextBox->Name = L"theta3ddTextBox";
			this->theta3ddTextBox->ReadOnly = true;
			this->theta3ddTextBox->Size = System::Drawing::Size(84, 22);
			this->theta3ddTextBox->TabIndex = 21;
			this->theta3ddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta3ddLabel
			// 
			this->theta3ddLabel->AutoSize = true;
			this->theta3ddLabel->Location = System::Drawing::Point(10, 37);
			this->theta3ddLabel->Name = L"theta3ddLabel";
			this->theta3ddLabel->Size = System::Drawing::Size(64, 17);
			this->theta3ddLabel->TabIndex = 20;
			this->theta3ddLabel->Text = L"theta3dd";
			// 
			// pauseButton
			// 
			this->pauseButton->Location = System::Drawing::Point(801, 576);
			this->pauseButton->Name = L"pauseButton";
			this->pauseButton->Size = System::Drawing::Size(144, 35);
			this->pauseButton->TabIndex = 4;
			this->pauseButton->Text = L"Pause";
			this->pauseButton->UseVisualStyleBackColor = true;
			this->pauseButton->Click += gcnew System::EventHandler(this, &DrawSliderCrank::pauseButton_Click);
			// 
			// propGroupBox
			// 
			this->propGroupBox->Controls->Add(this->trTextBox);
			this->propGroupBox->Controls->Add(this->trLabel);
			this->propGroupBox->Controls->Add(this->strokeTextBox);
			this->propGroupBox->Controls->Add(this->strokeLabel);
			this->propGroupBox->Location = System::Drawing::Point(691, 477);
			this->propGroupBox->Name = L"propGroupBox";
			this->propGroupBox->Size = System::Drawing::Size(338, 79);
			this->propGroupBox->TabIndex = 24;
			this->propGroupBox->TabStop = false;
			this->propGroupBox->Text = L"Mechanism Properties";
			// 
			// trTextBox
			// 
			this->trTextBox->Location = System::Drawing::Point(220, 37);
			this->trTextBox->Name = L"trTextBox";
			this->trTextBox->ReadOnly = true;
			this->trTextBox->Size = System::Drawing::Size(98, 22);
			this->trTextBox->TabIndex = 23;
			this->trTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// trLabel
			// 
			this->trLabel->AutoSize = true;
			this->trLabel->Location = System::Drawing::Point(183, 37);
			this->trLabel->Name = L"trLabel";
			this->trLabel->Size = System::Drawing::Size(35, 17);
			this->trLabel->TabIndex = 22;
			this->trLabel->Text = L"T.R.";
			// 
			// strokeTextBox
			// 
			this->strokeTextBox->Location = System::Drawing::Point(72, 34);
			this->strokeTextBox->Name = L"strokeTextBox";
			this->strokeTextBox->ReadOnly = true;
			this->strokeTextBox->Size = System::Drawing::Size(84, 22);
			this->strokeTextBox->TabIndex = 21;
			this->strokeTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// strokeLabel
			// 
			this->strokeLabel->AutoSize = true;
			this->strokeLabel->Location = System::Drawing::Point(10, 37);
			this->strokeLabel->Name = L"strokeLabel";
			this->strokeLabel->Size = System::Drawing::Size(49, 17);
			this->strokeLabel->TabIndex = 20;
			this->strokeLabel->Text = L"Stroke";
			// 
			// ycTextBox
			// 
			this->ycTextBox->Location = System::Drawing::Point(218, 198);
			this->ycTextBox->Name = L"ycTextBox";
			this->ycTextBox->ReadOnly = true;
			this->ycTextBox->Size = System::Drawing::Size(100, 22);
			this->ycTextBox->TabIndex = 21;
			this->ycTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ycLabel
			// 
			this->ycLabel->AutoSize = true;
			this->ycLabel->Location = System::Drawing::Point(189, 201);
			this->ycLabel->Name = L"ycLabel";
			this->ycLabel->Size = System::Drawing::Size(22, 17);
			this->ycLabel->TabIndex = 20;
			this->ycLabel->Text = L"yc";
			// 
			// xcTextBox
			// 
			this->xcTextBox->Location = System::Drawing::Point(54, 198);
			this->xcTextBox->Name = L"xcTextBox";
			this->xcTextBox->ReadOnly = true;
			this->xcTextBox->Size = System::Drawing::Size(100, 22);
			this->xcTextBox->TabIndex = 19;
			this->xcTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// xcLabel
			// 
			this->xcLabel->AutoSize = true;
			this->xcLabel->Location = System::Drawing::Point(25, 201);
			this->xcLabel->Name = L"xcLabel";
			this->xcLabel->Size = System::Drawing::Size(21, 17);
			this->xcLabel->TabIndex = 18;
			this->xcLabel->Text = L"xc";
			// 
			// ycdTextBox
			// 
			this->ycdTextBox->Location = System::Drawing::Point(218, 58);
			this->ycdTextBox->Name = L"ycdTextBox";
			this->ycdTextBox->ReadOnly = true;
			this->ycdTextBox->Size = System::Drawing::Size(98, 22);
			this->ycdTextBox->TabIndex = 23;
			this->ycdTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ycdLabel
			// 
			this->ycdLabel->AutoSize = true;
			this->ycdLabel->Location = System::Drawing::Point(189, 61);
			this->ycdLabel->Name = L"ycdLabel";
			this->ycdLabel->Size = System::Drawing::Size(30, 17);
			this->ycdLabel->TabIndex = 22;
			this->ycdLabel->Text = L"ycd";
			// 
			// xcdTextBox
			// 
			this->xcdTextBox->Location = System::Drawing::Point(70, 58);
			this->xcdTextBox->Name = L"xcdTextBox";
			this->xcdTextBox->ReadOnly = true;
			this->xcdTextBox->Size = System::Drawing::Size(84, 22);
			this->xcdTextBox->TabIndex = 21;
			this->xcdTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// xcdLabel
			// 
			this->xcdLabel->AutoSize = true;
			this->xcdLabel->Location = System::Drawing::Point(8, 61);
			this->xcdLabel->Name = L"xcdLabel";
			this->xcdLabel->Size = System::Drawing::Size(29, 17);
			this->xcdLabel->TabIndex = 20;
			this->xcdLabel->Text = L"xcd";
			// 
			// ycddTextBox
			// 
			this->ycddTextBox->Location = System::Drawing::Point(220, 62);
			this->ycddTextBox->Name = L"ycddTextBox";
			this->ycddTextBox->ReadOnly = true;
			this->ycddTextBox->Size = System::Drawing::Size(98, 22);
			this->ycddTextBox->TabIndex = 27;
			this->ycddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// ycddLabel
			// 
			this->ycddLabel->AutoSize = true;
			this->ycddLabel->Location = System::Drawing::Point(182, 65);
			this->ycddLabel->Name = L"ycddLabel";
			this->ycddLabel->Size = System::Drawing::Size(38, 17);
			this->ycddLabel->TabIndex = 26;
			this->ycddLabel->Text = L"ycdd";
			// 
			// xcddTextBox
			// 
			this->xcddTextBox->Location = System::Drawing::Point(72, 62);
			this->xcddTextBox->Name = L"xcddTextBox";
			this->xcddTextBox->ReadOnly = true;
			this->xcddTextBox->Size = System::Drawing::Size(84, 22);
			this->xcddTextBox->TabIndex = 25;
			this->xcddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// xcddLabel
			// 
			this->xcddLabel->AutoSize = true;
			this->xcddLabel->Location = System::Drawing::Point(10, 65);
			this->xcddLabel->Name = L"xcddLabel";
			this->xcddLabel->Size = System::Drawing::Size(37, 17);
			this->xcddLabel->TabIndex = 24;
			this->xcddLabel->Text = L"xcdd";
			// 
			// drawCurveCheckBox
			// 
			this->drawCurveCheckBox->AutoSize = true;
			this->drawCurveCheckBox->Location = System::Drawing::Point(691, 627);
			this->drawCurveCheckBox->Name = L"drawCurveCheckBox";
			this->drawCurveCheckBox->Size = System::Drawing::Size(152, 21);
			this->drawCurveCheckBox->TabIndex = 41;
			this->drawCurveCheckBox->Text = L"Draw coupler curve";
			this->drawCurveCheckBox->UseVisualStyleBackColor = true;
			// 
			// DrawSliderCrank
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1062, 673);
			this->Controls->Add(this->drawCurveCheckBox);
			this->Controls->Add(this->propGroupBox);
			this->Controls->Add(this->pauseButton);
			this->Controls->Add(this->accelGroupBox);
			this->Controls->Add(this->velGroupBox);
			this->Controls->Add(this->positionGroupBox);
			this->Controls->Add(this->panel1);
			this->Name = L"DrawSliderCrank";
			this->Text = L"Simulation Result";
			this->positionGroupBox->ResumeLayout(false);
			this->positionGroupBox->PerformLayout();
			this->velGroupBox->ResumeLayout(false);
			this->velGroupBox->PerformLayout();
			this->accelGroupBox->ResumeLayout(false);
			this->accelGroupBox->PerformLayout();
			this->propGroupBox->ResumeLayout(false);
			this->propGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		double nRange = r3 * 2;
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		if (drawCurveCheckBox->Checked == false)
			glClear(GL_COLOR_BUFFER_BIT);
		width = panel1->Width;
		height = panel1->Height;
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (width <= height)
			glOrtho(-nRange, nRange, -nRange * height / width, nRange * height / width, -nRange, nRange);
		else
			glOrtho(-nRange * width / height, nRange * width / height, -nRange, nRange, -nRange, nRange);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		const double PI = atan(1.0) * 4;
		const double dtr = PI / 180;
		double step = omega / (1000 / timer1->Interval);
		theta2 += step;
		if (theta2 >= 2 * PI) theta2 -= 2 * PI;
		if (theta2 < 0) theta2 += 2 * PI;

		double x1 = 0;
		double y1 = 0;
		double x2 = x1 + r2 * cos(theta2);
		double y2 = y1 + r2 * sin(theta2);
		theta3 = PI - asin((r2 * sin(theta2) - r1) / r3);
		double r4 = r2 * cos(theta2) - r3 * cos(theta3);
		double x3 = x1 + r4;
		double y3 = y1 + r1;
		double xc = x2 - r5 * cos(theta3) + r6 * sin(theta3);
		double yc = y2 - r5 * sin(theta3) - r6 * cos(theta3);

		double r[3] = { r1,r2,r3 };
		double c[2] = { r5,r6 };
		SliderCrank sc(r, c, omega, 0);
		double theta[2] = { theta2,theta3 };
		double rthetad[2];
		sc.Velocity(rthetad, theta);	// get {r4d, theta3d}
		double rthetadd[2];
		double thetad[2] = { omega, rthetad[1] };
		sc.Acceleration(rthetadd, theta, thetad);	// get {r4dd, theta3dd}
		double theta3d = rthetad[1];
		double vc[2];
		sc.couplerPointVelocity(vc, theta, theta3d);	// get {xcd, ycd}
		double theta3dd = rthetadd[1];
		double ac[2];
		sc.couplerPointAcceleration(ac, theta, theta3d, theta3dd);	// get {xcdd, ycdd}

		double stroke = sc.stroke();
		double time_ratio = sc.time_ratio();

		glTranslatef(-r3 / 2, 0.0, 0.0);
		double slider_w = r3 / 4;
		double slider_h = slider_w / 2;
		if (drawCurveCheckBox->Checked == false)
		{
			glBegin(GL_QUADS);
			glColor3f(0.0, 0.0, 1.0);
			glVertex2f(x3 - slider_w / 2, y3 - slider_h / 2);
			glVertex2f(x3 + slider_w / 2, y3 - slider_h / 2);
			glVertex2f(x3 + slider_w / 2, y3 + slider_h / 2);
			glVertex2f(x3 - slider_w / 2, y3 + slider_h / 2);
			glEnd();

			glBegin(GL_LINES);
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(x1, y1);
			glVertex2f(x2, y2);

			glColor3f(0.0, 1.0, 0.0);
			glVertex2f(x2, y2);
			glVertex2f(x3, y3);

			glVertex2f(x2 - r5 * cos(theta3), y2 - r5 * sin(theta3));
			glVertex2f(xc, yc);

			glColor3f(1.0, 1.0, 1.0);
			glLineWidth(4);
			glVertex2f(sqrt(pow(r3 - r2, 2) - r1 * r1) - slider_w, r1 - slider_h / 2);
			glVertex2f(sqrt(pow(r3 + r2, 2) - r1 * r1) + slider_w, r1 - slider_h / 2);
			glEnd();
		}
		else
		{
			glPointSize(2);
			glBegin(GL_POINTS);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(xc, yc);
			glEnd();
		}
		
		glFlush();
		SwapBuffers(m_hDC);

		x1TextBox->Text = x1.ToString("N4");
		y1TextBox->Text = y1.ToString("N4");
		x2TextBox->Text = x2.ToString("N4");
		y2TextBox->Text = y2.ToString("N4");
		x3TextBox->Text = x3.ToString("N4");
		y3TextBox->Text = y3.ToString("N4");
		theta2TextBox->Text = (theta2 / dtr).ToString("N4");
		theta3TextBox->Text = (theta3 / dtr).ToString("N4");
		r4TextBox->Text = r4.ToString("N4");
		xcTextBox->Text = xc.ToString("N4");
		ycTextBox->Text = yc.ToString("N4");
		theta3dTextBox->Text = rthetad[1].ToString("N4");
		r4dTextBox->Text = rthetad[0].ToString("N4");
		xcdTextBox->Text = vc[0].ToString("N4");
		ycdTextBox->Text = vc[1].ToString("N4");
		theta3ddTextBox->Text = rthetadd[1].ToString("N4");
		r4ddTextBox->Text = rthetadd[0].ToString("N4");
		xcddTextBox->Text = ac[0].ToString("N4");
		ycddTextBox->Text = ac[1].ToString("N4");
		strokeTextBox->Text = stroke.ToString("N4");
		trTextBox->Text = time_ratio.ToString("N4");
	}
private: System::Void pauseButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (pauseButton->Text == "Pause")
	{
		timer1->Stop();
		pauseButton->Text = "Resume";
	}
	else
	{
		timer1->Start();
		pauseButton->Text = "Pause";
	}
}
};
}
