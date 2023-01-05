#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#include <gl/glut.h>
#include <cmath>
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
	/// Summary for DrawFourBar
	/// </summary>
	public ref class DrawFourBar : public System::Windows::Forms::Form
	{
	public:
		DrawFourBar(FourBar& fb, const double theta1)
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
			double* r = fb.getLength();
			this->r1 = r[0];
			this->r2 = r[1];
			this->r3 = r[2];
			this->r4 = r[3];
			double* c = fb.getCoupler();
			this->r6 = c[0];
			this->r7 = c[1];
			this->theta1 = theta1;
			this->omega = fb.Omega();
			this->fullRotation = fb.getRotation();
			if (fullRotation)
				theta2 = 0;
			else
			{
				array<double>^ r = { r1,r2,r3,r4 };
				Array::Sort(r);
				if (r3 == r[0] && r[0] + r[3] < r[1] + r[2])
					alpha1 = acos((pow(r1, 2) + pow(r2, 2) - pow(r4 - r3, 2)) / (2 * r1 * r2));
				else
					alpha1 = acos((pow(r1, 2) + pow(r2 + r3, 2) - pow(r4, 2)) / (2 * (r2 + r3) * r1));
				alpha2 = acos((pow(r1, 2) + pow(r2, 2) - pow(r3 + r4, 2)) / (2 * r1 * r2));
				theta2 = alpha1;
			}
			timer1->Interval = 10;
			timer1->Enabled = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DrawFourBar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		/// HWND m_hWnd;
		HWND m_hWnd;
		HDC  m_hDC;
		HGLRC m_hRC;
		int width;
		int height;
		System::Drawing::Size OpenGLSize;
	private: System::Windows::Forms::Panel^ panel1;
		   double r1 = 0;
		   double r2 = 0;
		   double r3 = 0;
		   double r4 = 0;
		   double theta1 = 0;
		   double theta2 = 0;
		   double theta3 = 0;
		   double theta4 = 0;
		   double omega = 0;
		   double r6 = 0;
		   double r7 = 0;
		   bool fullRotation = true;
		   double alpha1;

	private: System::Windows::Forms::Label^ x1Label;
	private: System::Windows::Forms::TextBox^ x1TextBox;
	private: System::Windows::Forms::TextBox^ y1TextBox;


	private: System::Windows::Forms::Label^ y1Label;
	private: System::Windows::Forms::TextBox^ y2TextBox;

	private: System::Windows::Forms::Label^ y2Label;
	private: System::Windows::Forms::TextBox^ x2TextBox;

	private: System::Windows::Forms::Label^ x2Label;
	private: System::Windows::Forms::TextBox^ y3TextBox;

	private: System::Windows::Forms::Label^ y3Label;
	private: System::Windows::Forms::TextBox^ x3TextBox;

	private: System::Windows::Forms::Label^ x3Label;
	private: System::Windows::Forms::TextBox^ y4TextBox;

	private: System::Windows::Forms::Label^ y4Label;
	private: System::Windows::Forms::TextBox^ x4TextBox;

	private: System::Windows::Forms::Label^ x4Label;
	private: System::Windows::Forms::Label^ theta2Label;
	private: System::Windows::Forms::TextBox^ theta2TextBox;
	private: System::Windows::Forms::TextBox^ theta3TextBox;
	private: System::Windows::Forms::Label^ theta3Label;
	private: System::Windows::Forms::TextBox^ theta4TextBox;
	private: System::Windows::Forms::Label^ theta4Label;
	private: System::Windows::Forms::TextBox^ theta1TextBox;
	private: System::Windows::Forms::Label^ theta1Label;


		   double alpha2;
	private: System::Windows::Forms::Label^ theta3dLabel;
	private: System::Windows::Forms::TextBox^ theta3dTextBox;
	private: System::Windows::Forms::TextBox^ theta4dTextBox;
	private: System::Windows::Forms::Label^ thete4dLabel;
	private: System::Windows::Forms::GroupBox^ posGroupBox;
	private: System::Windows::Forms::GroupBox^ velGroupBox;
	private: System::Windows::Forms::GroupBox^ accelGroupBox;
	private: System::Windows::Forms::TextBox^ theta4ddTextBox;
	private: System::Windows::Forms::Label^ theta3ddLabel;
	private: System::Windows::Forms::TextBox^ theta3ddTextBox;
	private: System::Windows::Forms::Label^ theta4dLabel;
	private: System::Windows::Forms::Button^ pauseButton;
private: System::Windows::Forms::CheckBox^ drawCurveCheckBox;

private: System::Windows::Forms::Label^ xcLabel;
private: System::Windows::Forms::TextBox^ xcTextBox;
private: System::Windows::Forms::Label^ ycLabel;
private: System::Windows::Forms::TextBox^ ycTextBox;
private: System::Windows::Forms::TextBox^ ycdTextBox;
private: System::Windows::Forms::Label^ xcdLabel;
private: System::Windows::Forms::TextBox^ xcdTextBox;
private: System::Windows::Forms::Label^ ycdLabel;
private: System::Windows::Forms::TextBox^ ycddTextBox;

private: System::Windows::Forms::Label^ xcddLabel;
private: System::Windows::Forms::TextBox^ xcddTextBox;

private: System::Windows::Forms::Label^ ycddLabel;



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->x1Label = (gcnew System::Windows::Forms::Label());
			   this->x1TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->y1TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->y1Label = (gcnew System::Windows::Forms::Label());
			   this->y2TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->y2Label = (gcnew System::Windows::Forms::Label());
			   this->x2TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->x2Label = (gcnew System::Windows::Forms::Label());
			   this->y3TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->y3Label = (gcnew System::Windows::Forms::Label());
			   this->x3TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->x3Label = (gcnew System::Windows::Forms::Label());
			   this->y4TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->y4Label = (gcnew System::Windows::Forms::Label());
			   this->x4TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->x4Label = (gcnew System::Windows::Forms::Label());
			   this->theta2Label = (gcnew System::Windows::Forms::Label());
			   this->theta2TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->theta3TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->theta3Label = (gcnew System::Windows::Forms::Label());
			   this->theta4TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->theta4Label = (gcnew System::Windows::Forms::Label());
			   this->theta1TextBox = (gcnew System::Windows::Forms::TextBox());
			   this->theta1Label = (gcnew System::Windows::Forms::Label());
			   this->theta3dLabel = (gcnew System::Windows::Forms::Label());
			   this->theta3dTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->theta4dTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->thete4dLabel = (gcnew System::Windows::Forms::Label());
			   this->posGroupBox = (gcnew System::Windows::Forms::GroupBox());
			   this->xcLabel = (gcnew System::Windows::Forms::Label());
			   this->xcTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->ycLabel = (gcnew System::Windows::Forms::Label());
			   this->ycTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->velGroupBox = (gcnew System::Windows::Forms::GroupBox());
			   this->ycdTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->xcdLabel = (gcnew System::Windows::Forms::Label());
			   this->xcdTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->ycdLabel = (gcnew System::Windows::Forms::Label());
			   this->accelGroupBox = (gcnew System::Windows::Forms::GroupBox());
			   this->ycddTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->xcddLabel = (gcnew System::Windows::Forms::Label());
			   this->xcddTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->ycddLabel = (gcnew System::Windows::Forms::Label());
			   this->theta4ddTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->theta3ddLabel = (gcnew System::Windows::Forms::Label());
			   this->theta3ddTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->theta4dLabel = (gcnew System::Windows::Forms::Label());
			   this->pauseButton = (gcnew System::Windows::Forms::Button());
			   this->drawCurveCheckBox = (gcnew System::Windows::Forms::CheckBox());
			   this->posGroupBox->SuspendLayout();
			   this->velGroupBox->SuspendLayout();
			   this->accelGroupBox->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &DrawFourBar::timer1_Tick);
			   // 
			   // panel1
			   // 
			   this->panel1->Location = System::Drawing::Point(0, 0);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(674, 674);
			   this->panel1->TabIndex = 0;
			   // 
			   // x1Label
			   // 
			   this->x1Label->AutoSize = true;
			   this->x1Label->Location = System::Drawing::Point(25, 31);
			   this->x1Label->Name = L"x1Label";
			   this->x1Label->Size = System::Drawing::Size(22, 17);
			   this->x1Label->TabIndex = 2;
			   this->x1Label->Text = L"x1";
			   // 
			   // x1TextBox
			   // 
			   this->x1TextBox->Location = System::Drawing::Point(54, 28);
			   this->x1TextBox->Name = L"x1TextBox";
			   this->x1TextBox->ReadOnly = true;
			   this->x1TextBox->Size = System::Drawing::Size(100, 22);
			   this->x1TextBox->TabIndex = 3;
			   this->x1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // y1TextBox
			   // 
			   this->y1TextBox->Location = System::Drawing::Point(218, 28);
			   this->y1TextBox->Name = L"y1TextBox";
			   this->y1TextBox->ReadOnly = true;
			   this->y1TextBox->Size = System::Drawing::Size(100, 22);
			   this->y1TextBox->TabIndex = 5;
			   this->y1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // y1Label
			   // 
			   this->y1Label->AutoSize = true;
			   this->y1Label->Location = System::Drawing::Point(189, 31);
			   this->y1Label->Name = L"y1Label";
			   this->y1Label->Size = System::Drawing::Size(23, 17);
			   this->y1Label->TabIndex = 4;
			   this->y1Label->Text = L"y1";
			   // 
			   // y2TextBox
			   // 
			   this->y2TextBox->Location = System::Drawing::Point(218, 71);
			   this->y2TextBox->Name = L"y2TextBox";
			   this->y2TextBox->ReadOnly = true;
			   this->y2TextBox->Size = System::Drawing::Size(100, 22);
			   this->y2TextBox->TabIndex = 9;
			   this->y2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // y2Label
			   // 
			   this->y2Label->AutoSize = true;
			   this->y2Label->Location = System::Drawing::Point(189, 74);
			   this->y2Label->Name = L"y2Label";
			   this->y2Label->Size = System::Drawing::Size(23, 17);
			   this->y2Label->TabIndex = 8;
			   this->y2Label->Text = L"y2";
			   // 
			   // x2TextBox
			   // 
			   this->x2TextBox->Location = System::Drawing::Point(54, 71);
			   this->x2TextBox->Name = L"x2TextBox";
			   this->x2TextBox->ReadOnly = true;
			   this->x2TextBox->Size = System::Drawing::Size(100, 22);
			   this->x2TextBox->TabIndex = 7;
			   this->x2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // x2Label
			   // 
			   this->x2Label->AutoSize = true;
			   this->x2Label->Location = System::Drawing::Point(25, 74);
			   this->x2Label->Name = L"x2Label";
			   this->x2Label->Size = System::Drawing::Size(22, 17);
			   this->x2Label->TabIndex = 6;
			   this->x2Label->Text = L"x2";
			   // 
			   // y3TextBox
			   // 
			   this->y3TextBox->Location = System::Drawing::Point(218, 114);
			   this->y3TextBox->Name = L"y3TextBox";
			   this->y3TextBox->ReadOnly = true;
			   this->y3TextBox->Size = System::Drawing::Size(100, 22);
			   this->y3TextBox->TabIndex = 13;
			   this->y3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // y3Label
			   // 
			   this->y3Label->AutoSize = true;
			   this->y3Label->Location = System::Drawing::Point(189, 117);
			   this->y3Label->Name = L"y3Label";
			   this->y3Label->Size = System::Drawing::Size(23, 17);
			   this->y3Label->TabIndex = 12;
			   this->y3Label->Text = L"y3";
			   // 
			   // x3TextBox
			   // 
			   this->x3TextBox->Location = System::Drawing::Point(54, 114);
			   this->x3TextBox->Name = L"x3TextBox";
			   this->x3TextBox->ReadOnly = true;
			   this->x3TextBox->Size = System::Drawing::Size(100, 22);
			   this->x3TextBox->TabIndex = 11;
			   this->x3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // x3Label
			   // 
			   this->x3Label->AutoSize = true;
			   this->x3Label->Location = System::Drawing::Point(25, 117);
			   this->x3Label->Name = L"x3Label";
			   this->x3Label->Size = System::Drawing::Size(22, 17);
			   this->x3Label->TabIndex = 10;
			   this->x3Label->Text = L"x3";
			   // 
			   // y4TextBox
			   // 
			   this->y4TextBox->Location = System::Drawing::Point(218, 157);
			   this->y4TextBox->Name = L"y4TextBox";
			   this->y4TextBox->ReadOnly = true;
			   this->y4TextBox->Size = System::Drawing::Size(100, 22);
			   this->y4TextBox->TabIndex = 17;
			   this->y4TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // y4Label
			   // 
			   this->y4Label->AutoSize = true;
			   this->y4Label->Location = System::Drawing::Point(189, 160);
			   this->y4Label->Name = L"y4Label";
			   this->y4Label->Size = System::Drawing::Size(23, 17);
			   this->y4Label->TabIndex = 16;
			   this->y4Label->Text = L"y4";
			   // 
			   // x4TextBox
			   // 
			   this->x4TextBox->Location = System::Drawing::Point(54, 157);
			   this->x4TextBox->Name = L"x4TextBox";
			   this->x4TextBox->ReadOnly = true;
			   this->x4TextBox->Size = System::Drawing::Size(100, 22);
			   this->x4TextBox->TabIndex = 15;
			   this->x4TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // x4Label
			   // 
			   this->x4Label->AutoSize = true;
			   this->x4Label->Location = System::Drawing::Point(25, 160);
			   this->x4Label->Name = L"x4Label";
			   this->x4Label->Size = System::Drawing::Size(22, 17);
			   this->x4Label->TabIndex = 14;
			   this->x4Label->Text = L"x4";
			   // 
			   // theta2Label
			   // 
			   this->theta2Label->AutoSize = true;
			   this->theta2Label->Location = System::Drawing::Point(189, 246);
			   this->theta2Label->Name = L"theta2Label";
			   this->theta2Label->Size = System::Drawing::Size(48, 17);
			   this->theta2Label->TabIndex = 18;
			   this->theta2Label->Text = L"theta2";
			   // 
			   // theta2TextBox
			   // 
			   this->theta2TextBox->Location = System::Drawing::Point(244, 243);
			   this->theta2TextBox->Name = L"theta2TextBox";
			   this->theta2TextBox->ReadOnly = true;
			   this->theta2TextBox->Size = System::Drawing::Size(75, 22);
			   this->theta2TextBox->TabIndex = 19;
			   this->theta2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // theta3TextBox
			   // 
			   this->theta3TextBox->Location = System::Drawing::Point(79, 286);
			   this->theta3TextBox->Name = L"theta3TextBox";
			   this->theta3TextBox->ReadOnly = true;
			   this->theta3TextBox->Size = System::Drawing::Size(76, 22);
			   this->theta3TextBox->TabIndex = 21;
			   this->theta3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // theta3Label
			   // 
			   this->theta3Label->AutoSize = true;
			   this->theta3Label->Location = System::Drawing::Point(24, 289);
			   this->theta3Label->Name = L"theta3Label";
			   this->theta3Label->Size = System::Drawing::Size(48, 17);
			   this->theta3Label->TabIndex = 20;
			   this->theta3Label->Text = L"theta3";
			   // 
			   // theta4TextBox
			   // 
			   this->theta4TextBox->Location = System::Drawing::Point(243, 286);
			   this->theta4TextBox->Name = L"theta4TextBox";
			   this->theta4TextBox->ReadOnly = true;
			   this->theta4TextBox->Size = System::Drawing::Size(76, 22);
			   this->theta4TextBox->TabIndex = 23;
			   this->theta4TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // theta4Label
			   // 
			   this->theta4Label->AutoSize = true;
			   this->theta4Label->Location = System::Drawing::Point(188, 289);
			   this->theta4Label->Name = L"theta4Label";
			   this->theta4Label->Size = System::Drawing::Size(48, 17);
			   this->theta4Label->TabIndex = 22;
			   this->theta4Label->Text = L"theta4";
			   // 
			   // theta1TextBox
			   // 
			   this->theta1TextBox->Location = System::Drawing::Point(80, 243);
			   this->theta1TextBox->Name = L"theta1TextBox";
			   this->theta1TextBox->ReadOnly = true;
			   this->theta1TextBox->Size = System::Drawing::Size(75, 22);
			   this->theta1TextBox->TabIndex = 25;
			   this->theta1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // theta1Label
			   // 
			   this->theta1Label->AutoSize = true;
			   this->theta1Label->Location = System::Drawing::Point(25, 246);
			   this->theta1Label->Name = L"theta1Label";
			   this->theta1Label->Size = System::Drawing::Size(48, 17);
			   this->theta1Label->TabIndex = 24;
			   this->theta1Label->Text = L"theta1";
			   // 
			   // theta3dLabel
			   // 
			   this->theta3dLabel->AutoSize = true;
			   this->theta3dLabel->Location = System::Drawing::Point(12, 41);
			   this->theta3dLabel->Name = L"theta3dLabel";
			   this->theta3dLabel->Size = System::Drawing::Size(56, 17);
			   this->theta3dLabel->TabIndex = 27;
			   this->theta3dLabel->Text = L"theta3d";
			   // 
			   // theta3dTextBox
			   // 
			   this->theta3dTextBox->Location = System::Drawing::Point(74, 38);
			   this->theta3dTextBox->Name = L"theta3dTextBox";
			   this->theta3dTextBox->ReadOnly = true;
			   this->theta3dTextBox->Size = System::Drawing::Size(80, 22);
			   this->theta3dTextBox->TabIndex = 28;
			   this->theta3dTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // theta4dTextBox
			   // 
			   this->theta4dTextBox->Location = System::Drawing::Point(238, 38);
			   this->theta4dTextBox->Name = L"theta4dTextBox";
			   this->theta4dTextBox->ReadOnly = true;
			   this->theta4dTextBox->Size = System::Drawing::Size(80, 22);
			   this->theta4dTextBox->TabIndex = 30;
			   this->theta4dTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // thete4dLabel
			   // 
			   this->thete4dLabel->AutoSize = true;
			   this->thete4dLabel->Location = System::Drawing::Point(176, 41);
			   this->thete4dLabel->Name = L"thete4dLabel";
			   this->thete4dLabel->Size = System::Drawing::Size(56, 17);
			   this->thete4dLabel->TabIndex = 29;
			   this->thete4dLabel->Text = L"theta4d";
			   // 
			   // posGroupBox
			   // 
			   this->posGroupBox->Controls->Add(this->xcLabel);
			   this->posGroupBox->Controls->Add(this->xcTextBox);
			   this->posGroupBox->Controls->Add(this->ycLabel);
			   this->posGroupBox->Controls->Add(this->ycTextBox);
			   this->posGroupBox->Controls->Add(this->x2TextBox);
			   this->posGroupBox->Controls->Add(this->x1Label);
			   this->posGroupBox->Controls->Add(this->x1TextBox);
			   this->posGroupBox->Controls->Add(this->y1Label);
			   this->posGroupBox->Controls->Add(this->y1TextBox);
			   this->posGroupBox->Controls->Add(this->x2Label);
			   this->posGroupBox->Controls->Add(this->y2Label);
			   this->posGroupBox->Controls->Add(this->y2TextBox);
			   this->posGroupBox->Controls->Add(this->x3Label);
			   this->posGroupBox->Controls->Add(this->x3TextBox);
			   this->posGroupBox->Controls->Add(this->theta1TextBox);
			   this->posGroupBox->Controls->Add(this->y3Label);
			   this->posGroupBox->Controls->Add(this->theta1Label);
			   this->posGroupBox->Controls->Add(this->y3TextBox);
			   this->posGroupBox->Controls->Add(this->theta4TextBox);
			   this->posGroupBox->Controls->Add(this->x4Label);
			   this->posGroupBox->Controls->Add(this->theta4Label);
			   this->posGroupBox->Controls->Add(this->x4TextBox);
			   this->posGroupBox->Controls->Add(this->theta3TextBox);
			   this->posGroupBox->Controls->Add(this->y4Label);
			   this->posGroupBox->Controls->Add(this->theta3Label);
			   this->posGroupBox->Controls->Add(this->y4TextBox);
			   this->posGroupBox->Controls->Add(this->theta2TextBox);
			   this->posGroupBox->Controls->Add(this->theta2Label);
			   this->posGroupBox->Location = System::Drawing::Point(691, 27);
			   this->posGroupBox->Name = L"posGroupBox";
			   this->posGroupBox->Size = System::Drawing::Size(338, 325);
			   this->posGroupBox->TabIndex = 0;
			   this->posGroupBox->TabStop = false;
			   this->posGroupBox->Text = L"Position (mm or degree)";
			   // 
			   // xcLabel
			   // 
			   this->xcLabel->AutoSize = true;
			   this->xcLabel->Location = System::Drawing::Point(25, 203);
			   this->xcLabel->Name = L"xcLabel";
			   this->xcLabel->Size = System::Drawing::Size(21, 17);
			   this->xcLabel->TabIndex = 26;
			   this->xcLabel->Text = L"xc";
			   // 
			   // xcTextBox
			   // 
			   this->xcTextBox->Location = System::Drawing::Point(54, 200);
			   this->xcTextBox->Name = L"xcTextBox";
			   this->xcTextBox->ReadOnly = true;
			   this->xcTextBox->Size = System::Drawing::Size(100, 22);
			   this->xcTextBox->TabIndex = 27;
			   this->xcTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // ycLabel
			   // 
			   this->ycLabel->AutoSize = true;
			   this->ycLabel->Location = System::Drawing::Point(189, 203);
			   this->ycLabel->Name = L"ycLabel";
			   this->ycLabel->Size = System::Drawing::Size(22, 17);
			   this->ycLabel->TabIndex = 28;
			   this->ycLabel->Text = L"yc";
			   // 
			   // ycTextBox
			   // 
			   this->ycTextBox->Location = System::Drawing::Point(218, 200);
			   this->ycTextBox->Name = L"ycTextBox";
			   this->ycTextBox->ReadOnly = true;
			   this->ycTextBox->Size = System::Drawing::Size(100, 22);
			   this->ycTextBox->TabIndex = 29;
			   this->ycTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // velGroupBox
			   // 
			   this->velGroupBox->Controls->Add(this->ycdTextBox);
			   this->velGroupBox->Controls->Add(this->xcdLabel);
			   this->velGroupBox->Controls->Add(this->xcdTextBox);
			   this->velGroupBox->Controls->Add(this->ycdLabel);
			   this->velGroupBox->Controls->Add(this->theta4dTextBox);
			   this->velGroupBox->Controls->Add(this->theta3dLabel);
			   this->velGroupBox->Controls->Add(this->theta3dTextBox);
			   this->velGroupBox->Controls->Add(this->thete4dLabel);
			   this->velGroupBox->Location = System::Drawing::Point(691, 367);
			   this->velGroupBox->Name = L"velGroupBox";
			   this->velGroupBox->Size = System::Drawing::Size(338, 98);
			   this->velGroupBox->TabIndex = 36;
			   this->velGroupBox->TabStop = false;
			   this->velGroupBox->Text = L"Angular/Linear Velocity (rad/s or mm/s)";
			   // 
			   // ycdTextBox
			   // 
			   this->ycdTextBox->Location = System::Drawing::Point(238, 66);
			   this->ycdTextBox->Name = L"ycdTextBox";
			   this->ycdTextBox->ReadOnly = true;
			   this->ycdTextBox->Size = System::Drawing::Size(80, 22);
			   this->ycdTextBox->TabIndex = 34;
			   this->ycdTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // xcdLabel
			   // 
			   this->xcdLabel->AutoSize = true;
			   this->xcdLabel->Location = System::Drawing::Point(12, 69);
			   this->xcdLabel->Name = L"xcdLabel";
			   this->xcdLabel->Size = System::Drawing::Size(29, 17);
			   this->xcdLabel->TabIndex = 31;
			   this->xcdLabel->Text = L"xcd";
			   // 
			   // xcdTextBox
			   // 
			   this->xcdTextBox->Location = System::Drawing::Point(74, 66);
			   this->xcdTextBox->Name = L"xcdTextBox";
			   this->xcdTextBox->ReadOnly = true;
			   this->xcdTextBox->Size = System::Drawing::Size(80, 22);
			   this->xcdTextBox->TabIndex = 32;
			   this->xcdTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // ycdLabel
			   // 
			   this->ycdLabel->AutoSize = true;
			   this->ycdLabel->Location = System::Drawing::Point(176, 69);
			   this->ycdLabel->Name = L"ycdLabel";
			   this->ycdLabel->Size = System::Drawing::Size(30, 17);
			   this->ycdLabel->TabIndex = 33;
			   this->ycdLabel->Text = L"ycd";
			   // 
			   // accelGroupBox
			   // 
			   this->accelGroupBox->Controls->Add(this->ycddTextBox);
			   this->accelGroupBox->Controls->Add(this->xcddLabel);
			   this->accelGroupBox->Controls->Add(this->xcddTextBox);
			   this->accelGroupBox->Controls->Add(this->ycddLabel);
			   this->accelGroupBox->Controls->Add(this->theta4ddTextBox);
			   this->accelGroupBox->Controls->Add(this->theta3ddLabel);
			   this->accelGroupBox->Controls->Add(this->theta3ddTextBox);
			   this->accelGroupBox->Controls->Add(this->theta4dLabel);
			   this->accelGroupBox->Location = System::Drawing::Point(691, 482);
			   this->accelGroupBox->Name = L"accelGroupBox";
			   this->accelGroupBox->Size = System::Drawing::Size(338, 100);
			   this->accelGroupBox->TabIndex = 37;
			   this->accelGroupBox->TabStop = false;
			   this->accelGroupBox->Text = L"Angular/Linear Acceleration (rad/s2 or mm/s2)";
			   // 
			   // ycddTextBox
			   // 
			   this->ycddTextBox->Location = System::Drawing::Point(238, 66);
			   this->ycddTextBox->Name = L"ycddTextBox";
			   this->ycddTextBox->ReadOnly = true;
			   this->ycddTextBox->Size = System::Drawing::Size(80, 22);
			   this->ycddTextBox->TabIndex = 34;
			   this->ycddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // xcddLabel
			   // 
			   this->xcddLabel->AutoSize = true;
			   this->xcddLabel->Location = System::Drawing::Point(7, 69);
			   this->xcddLabel->Name = L"xcddLabel";
			   this->xcddLabel->Size = System::Drawing::Size(37, 17);
			   this->xcddLabel->TabIndex = 31;
			   this->xcddLabel->Text = L"xcdd";
			   // 
			   // xcddTextBox
			   // 
			   this->xcddTextBox->Location = System::Drawing::Point(74, 66);
			   this->xcddTextBox->Name = L"xcddTextBox";
			   this->xcddTextBox->ReadOnly = true;
			   this->xcddTextBox->Size = System::Drawing::Size(80, 22);
			   this->xcddTextBox->TabIndex = 32;
			   this->xcddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // ycddLabel
			   // 
			   this->ycddLabel->AutoSize = true;
			   this->ycddLabel->Location = System::Drawing::Point(172, 69);
			   this->ycddLabel->Name = L"ycddLabel";
			   this->ycddLabel->Size = System::Drawing::Size(38, 17);
			   this->ycddLabel->TabIndex = 33;
			   this->ycddLabel->Text = L"ycdd";
			   // 
			   // theta4ddTextBox
			   // 
			   this->theta4ddTextBox->Location = System::Drawing::Point(238, 38);
			   this->theta4ddTextBox->Name = L"theta4ddTextBox";
			   this->theta4ddTextBox->ReadOnly = true;
			   this->theta4ddTextBox->Size = System::Drawing::Size(80, 22);
			   this->theta4ddTextBox->TabIndex = 30;
			   this->theta4ddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // theta3ddLabel
			   // 
			   this->theta3ddLabel->AutoSize = true;
			   this->theta3ddLabel->Location = System::Drawing::Point(7, 41);
			   this->theta3ddLabel->Name = L"theta3ddLabel";
			   this->theta3ddLabel->Size = System::Drawing::Size(64, 17);
			   this->theta3ddLabel->TabIndex = 27;
			   this->theta3ddLabel->Text = L"theta3dd";
			   // 
			   // theta3ddTextBox
			   // 
			   this->theta3ddTextBox->Location = System::Drawing::Point(74, 38);
			   this->theta3ddTextBox->Name = L"theta3ddTextBox";
			   this->theta3ddTextBox->ReadOnly = true;
			   this->theta3ddTextBox->Size = System::Drawing::Size(80, 22);
			   this->theta3ddTextBox->TabIndex = 28;
			   this->theta3ddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			   // 
			   // theta4dLabel
			   // 
			   this->theta4dLabel->AutoSize = true;
			   this->theta4dLabel->Location = System::Drawing::Point(172, 41);
			   this->theta4dLabel->Name = L"theta4dLabel";
			   this->theta4dLabel->Size = System::Drawing::Size(64, 17);
			   this->theta4dLabel->TabIndex = 29;
			   this->theta4dLabel->Text = L"theta4dd";
			   // 
			   // pauseButton
			   // 
			   this->pauseButton->Location = System::Drawing::Point(783, 599);
			   this->pauseButton->Name = L"pauseButton";
			   this->pauseButton->Size = System::Drawing::Size(144, 35);
			   this->pauseButton->TabIndex = 38;
			   this->pauseButton->Text = L"Pause";
			   this->pauseButton->UseVisualStyleBackColor = true;
			   this->pauseButton->Click += gcnew System::EventHandler(this, &DrawFourBar::pauseButton_Click);
			   // 
			   // drawCurveCheckBox
			   // 
			   this->drawCurveCheckBox->AutoSize = true;
			   this->drawCurveCheckBox->Location = System::Drawing::Point(691, 640);
			   this->drawCurveCheckBox->Name = L"drawCurveCheckBox";
			   this->drawCurveCheckBox->Size = System::Drawing::Size(152, 21);
			   this->drawCurveCheckBox->TabIndex = 39;
			   this->drawCurveCheckBox->Text = L"Draw coupler curve";
			   this->drawCurveCheckBox->UseVisualStyleBackColor = true;
			   // 
			   // DrawFourBar
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1062, 673);
			   this->Controls->Add(this->drawCurveCheckBox);
			   this->Controls->Add(this->pauseButton);
			   this->Controls->Add(this->accelGroupBox);
			   this->Controls->Add(this->velGroupBox);
			   this->Controls->Add(this->posGroupBox);
			   this->Controls->Add(this->panel1);
			   this->Name = L"DrawFourBar";
			   this->Text = L"Simulation Result";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &DrawFourBar::DrawFourBar_FormClosing);
			   this->posGroupBox->ResumeLayout(false);
			   this->posGroupBox->PerformLayout();
			   this->velGroupBox->ResumeLayout(false);
			   this->velGroupBox->PerformLayout();
			   this->accelGroupBox->ResumeLayout(false);
			   this->accelGroupBox->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		double nRange = r1 * 1.5;
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
		double x4 = x1 + r1;
		double y4 = y1;

		double h1 = r1 / r2;
		double h2 = r1 / r3;
		double h3 = r1 / r4;
		double h4 = (-pow(r1, 2) - pow(r2, 2) - pow(r3, 2) + pow(r4, 2)) / (2 * r2 * r3);
		double h5 = (pow(r1, 2) + pow(r2, 2) - pow(r3, 2) + pow(r4, 2)) / (2 * r2 * r4);

		double a = -h1 + (1 + h2) * cos(theta2) + h4;
		double b = -2 * sin(theta2);
		double c = h1 - (1 - h2) * cos(theta2) + h4;
		double d = -h1 + (1 - h3) * cos(theta2) + h5;
		double f = h1 - (1 + h3) * cos(theta2) + h5;

		static int n;
		if (!fullRotation)
		{
			array<double>^ r = { r1,r2,r3,r4 };
			Array::Sort(r);
			if (r3 == r[0] && r[0] + r[3] < r[1] + r[2])
			{
				if (theta2 + 0.1 * dtr >= alpha2 && omega > 0)
					n = 1;
				else if (theta2 - 0.1 * dtr < alpha1 && omega < 0)
					n = 0;
			}
			else
				n = 0;
		}
		else
			n = 0;
		theta4 = 2 * atan2((-b - pow(-1, n) * sqrt(b * b - 4 * d * f)), (2 * d));
		if (r1 == r3 && r2 == r4)
			theta4 = theta2;
		theta3 = atan2(-r2 * sin(theta2) + r4 * sin(theta4), r1 - r2 * cos(theta2) + r4 * cos(theta4));

		if (theta3 >= 2 * PI) theta3 -= 2 * PI;
		if (theta3 < 0) theta3 += 2 * PI;
		if (theta4 >= 2 * PI) theta4 -= 2 * PI;
		if (theta4 < 0) theta4 += 2 * PI;

		double x3 = x2 + r3 * cos(theta3);
		double y3 = y2 + r3 * sin(theta3);

		double xc = r2 * cos(theta2) + r6 * cos(theta3) - r7 * sin(theta3);
		double yc = r2 * sin(theta2) + r6 * sin(theta3) + r7 * cos(theta3);

		double r[4] = { r1,r2,r3,r4 };
		double coupler[2] = { r6,r7 };
		FourBar fb(r, coupler, omega, 0);
		double theta[3] = { theta2,theta3,theta4 };
		double thetad[2];
		fb.Velocity(thetad, theta);	// get {theta3d, theta4d}
		double thetadd[2];
		fb.Acceleration(thetadd, theta, thetad);	// get {theta3dd, theta4dd}
		double vc[2];
		fb.couplerPointVelocity(vc, theta, thetad);	// get {xcd, ycd}
		double ac[2];
		fb.couplerPointAcceleration(ac, theta, thetad, thetadd);	// get {xcdd, ycdd}

		glRotatef(theta1 / dtr, 0.0f, 0.0f, 1.0f);
		glTranslatef(-r1 / 2, 0.0, 0.0);

		if (drawCurveCheckBox->Checked == false)
		{
			glBegin(GL_LINES);
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(x1, y1);
			glVertex2f(x2, y2);

			glColor3f(0.0, 1.0, 0.0);
			glVertex2f(x2, y2);
			glVertex2f(x3, y3);

			glColor3f(0.0, 0.0, 1.0);
			glVertex2f(x3, y3);
			glVertex2f(x4, y4);

			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(x4, y4);
			glVertex2f(x1, y1);

			glColor3f(0.0, 1.0, 0.0);
			glVertex2f(x2 + r6 * cos(theta3), y2 + r6 * sin(theta3));
			glVertex2f(xc, yc);
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

		if (!fullRotation)
			if (theta2 + 0.1 * dtr >= alpha2 || theta2 - 0.1 * dtr <= alpha1)
				omega *= -1;

		double x1r = x1 * cos(theta1) + y1 * (-sin(theta1));
		double y1r = x1 * sin(theta1) + y1 * cos(theta1);
		double x2r = x2 * cos(theta1) + y2 * (-sin(theta1));
		double y2r = x2 * sin(theta1) + y2 * cos(theta1);
		double x3r = x3 * cos(theta1) + y3 * (-sin(theta1));
		double y3r = x3 * sin(theta1) + y3 * cos(theta1);
		double x4r = x4 * cos(theta1) + y4 * (-sin(theta1));
		double y4r = x4 * sin(theta1) + y4 * cos(theta1);
		double xcr = xc * cos(theta1) + yc * (-sin(theta1));
		double ycr = xc * sin(theta1) + yc * cos(theta1);

		x1TextBox->Text = x1r.ToString("N4");
		y1TextBox->Text = y1r.ToString("N4");
		x2TextBox->Text = x2r.ToString("N4");
		y2TextBox->Text = y2r.ToString("N4");
		x3TextBox->Text = x3r.ToString("N4");
		y3TextBox->Text = y3r.ToString("N4");
		x4TextBox->Text = x4r.ToString("N4");
		y4TextBox->Text = y4r.ToString("N4");
		xcTextBox->Text = xcr.ToString("N4");
		ycTextBox->Text = ycr.ToString("N4");
		theta1TextBox->Text = (theta1 / dtr).ToString("N4");
		theta2TextBox->Text = ((theta2 + theta1) / dtr).ToString("N4");
		theta3TextBox->Text = ((theta3 + theta1) / dtr).ToString("N4");
		theta4TextBox->Text = ((theta4 + theta1) / dtr).ToString("N4");
		theta3dTextBox->Text = thetad[0].ToString("N4");
		theta4dTextBox->Text = thetad[1].ToString("N4");
		xcdTextBox->Text = vc[0].ToString("N4");
		ycdTextBox->Text = vc[1].ToString("N4");
		theta3ddTextBox->Text = thetadd[0].ToString("N4");
		theta4ddTextBox->Text = thetadd[1].ToString("N4");
		xcddTextBox->Text = ac[0].ToString("N4");
		ycddTextBox->Text = ac[1].ToString("N4");
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
	private: System::Void DrawFourBar_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		timer1->Enabled = false;
		e->Cancel = true;
		this->Hide();
	}
};
}
