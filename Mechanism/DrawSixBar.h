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
	/// Summary for DrawSixBar
	/// </summary>
	public ref class DrawSixBar : public System::Windows::Forms::Form
	{
	public:
		DrawSixBar(SixBar& sb)
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

			double* r = sb.getLength();
			r1 = r[0];
			r2 = r[1];
			r3 = r[2];
			r4 = r[3];
			r5 = r[4];
			r6 = r[5];
			r7 = r[6];
			r8 = r[7];
			this->omega = sb.Omega();
			timer1->Interval = 10;
			timer1->Enabled = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DrawSixBar()
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
		double r4 = 0;
		double r5 = 0;
		double r6 = 0;
		double r7 = 0;
		double r8 = 0;
		double theta2 = 0;
		double theta3 = 0;
		double theta4 = 0;
		double theta6 = 0;
		double theta7 = 0;
		double theta8 = 0;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::GroupBox^ posGroupBox;
	private: System::Windows::Forms::Label^ theta7Label;
	private: System::Windows::Forms::TextBox^ theta7TextBox;
	private: System::Windows::Forms::Label^ theta8Label;
	private: System::Windows::Forms::TextBox^ theta8TextBox;
	private: System::Windows::Forms::TextBox^ theta3TextBox;
	private: System::Windows::Forms::Label^ theta3Label;
	private: System::Windows::Forms::TextBox^ x6TextBox;
	private: System::Windows::Forms::Label^ theta4Label;
	private: System::Windows::Forms::Label^ x5Label;
	private: System::Windows::Forms::TextBox^ theta4TextBox;
	private: System::Windows::Forms::TextBox^ x5TextBox;
	private: System::Windows::Forms::Label^ theta6Label;
	private: System::Windows::Forms::Label^ y5Label;
	private: System::Windows::Forms::TextBox^ theta6TextBox;
	private: System::Windows::Forms::TextBox^ y5TextBox;
	private: System::Windows::Forms::Label^ theta2Label;
	private: System::Windows::Forms::Label^ x6Label;
	private: System::Windows::Forms::TextBox^ theta2TextBox;
	private: System::Windows::Forms::Label^ y6Label;
	private: System::Windows::Forms::TextBox^ y6TextBox;
	private: System::Windows::Forms::Label^ x7Label;
	private: System::Windows::Forms::TextBox^ x7TextBox;
	private: System::Windows::Forms::Label^ y7Label;
	private: System::Windows::Forms::TextBox^ y7TextBox;
	private: System::Windows::Forms::Label^ x8Label;
	private: System::Windows::Forms::TextBox^ x8TextBox;
	private: System::Windows::Forms::Label^ y8Label;
	private: System::Windows::Forms::TextBox^ y8TextBox;
	private: System::Windows::Forms::TextBox^ x2TextBox;
	private: System::Windows::Forms::Label^ x1Label;
	private: System::Windows::Forms::TextBox^ x1TextBox;
	private: System::Windows::Forms::Label^ y1Label;
	private: System::Windows::Forms::TextBox^ y1TextBox;
	private: System::Windows::Forms::Label^ x2Label;
	private: System::Windows::Forms::Label^ y2Label;
	private: System::Windows::Forms::TextBox^ y2TextBox;
	private: System::Windows::Forms::Label^ x3Label;
	private: System::Windows::Forms::TextBox^ x3TextBox;
	private: System::Windows::Forms::Label^ y3Label;
	private: System::Windows::Forms::TextBox^ y3TextBox;
	private: System::Windows::Forms::Label^ x4Label;
	private: System::Windows::Forms::TextBox^ x4TextBox;
	private: System::Windows::Forms::Label^ y4Label;
	private: System::Windows::Forms::TextBox^ y4TextBox;
private: System::Windows::Forms::GroupBox^ velGroupBox;

private: System::Windows::Forms::TextBox^ theta8dTextBox;
private: System::Windows::Forms::Label^ theta7dLabel;
private: System::Windows::Forms::TextBox^ theta7dTextBox;
private: System::Windows::Forms::Label^ theta8dLabel;
private: System::Windows::Forms::TextBox^ theta4dTextBox;
private: System::Windows::Forms::Label^ theta3dLabel;
private: System::Windows::Forms::TextBox^ theta3dTextBox;
private: System::Windows::Forms::Label^ thete4dLabel;
private: System::Windows::Forms::GroupBox^ accelGroupBox;
private: System::Windows::Forms::TextBox^ theta8ddTextBox;
private: System::Windows::Forms::Label^ theta7ddLabel;
private: System::Windows::Forms::TextBox^ theta7ddTextBox;
private: System::Windows::Forms::Label^ theta8ddLabel;
private: System::Windows::Forms::TextBox^ theta4ddTextBox;
private: System::Windows::Forms::Label^ theta3ddLabel;
private: System::Windows::Forms::TextBox^ theta3ddTextBox;
private: System::Windows::Forms::Label^ theta4dLabel;
private: System::Windows::Forms::Button^ pauseButton;





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
			this->posGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->theta7Label = (gcnew System::Windows::Forms::Label());
			this->theta7TextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta8Label = (gcnew System::Windows::Forms::Label());
			this->theta8TextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta3Label = (gcnew System::Windows::Forms::Label());
			this->x6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta4Label = (gcnew System::Windows::Forms::Label());
			this->x5Label = (gcnew System::Windows::Forms::Label());
			this->theta4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta6Label = (gcnew System::Windows::Forms::Label());
			this->y5Label = (gcnew System::Windows::Forms::Label());
			this->theta6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y5TextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta2Label = (gcnew System::Windows::Forms::Label());
			this->x6Label = (gcnew System::Windows::Forms::Label());
			this->theta2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y6Label = (gcnew System::Windows::Forms::Label());
			this->y6TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x7Label = (gcnew System::Windows::Forms::Label());
			this->x7TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y7Label = (gcnew System::Windows::Forms::Label());
			this->y7TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x8Label = (gcnew System::Windows::Forms::Label());
			this->x8TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y8Label = (gcnew System::Windows::Forms::Label());
			this->y8TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x1Label = (gcnew System::Windows::Forms::Label());
			this->x1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y1Label = (gcnew System::Windows::Forms::Label());
			this->y1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x2Label = (gcnew System::Windows::Forms::Label());
			this->y2Label = (gcnew System::Windows::Forms::Label());
			this->y2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x3Label = (gcnew System::Windows::Forms::Label());
			this->x3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y3Label = (gcnew System::Windows::Forms::Label());
			this->y3TextBox = (gcnew System::Windows::Forms::TextBox());
			this->x4Label = (gcnew System::Windows::Forms::Label());
			this->x4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->y4Label = (gcnew System::Windows::Forms::Label());
			this->y4TextBox = (gcnew System::Windows::Forms::TextBox());
			this->velGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->theta8dTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta7dLabel = (gcnew System::Windows::Forms::Label());
			this->theta7dTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta8dLabel = (gcnew System::Windows::Forms::Label());
			this->theta4dTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta3dLabel = (gcnew System::Windows::Forms::Label());
			this->theta3dTextBox = (gcnew System::Windows::Forms::TextBox());
			this->thete4dLabel = (gcnew System::Windows::Forms::Label());
			this->accelGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->theta8ddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta7ddLabel = (gcnew System::Windows::Forms::Label());
			this->theta7ddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta8ddLabel = (gcnew System::Windows::Forms::Label());
			this->theta4ddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta3ddLabel = (gcnew System::Windows::Forms::Label());
			this->theta3ddTextBox = (gcnew System::Windows::Forms::TextBox());
			this->theta4dLabel = (gcnew System::Windows::Forms::Label());
			this->pauseButton = (gcnew System::Windows::Forms::Button());
			this->posGroupBox->SuspendLayout();
			this->velGroupBox->SuspendLayout();
			this->accelGroupBox->SuspendLayout();
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
			this->timer1->Tick += gcnew System::EventHandler(this, &DrawSixBar::timer1_Tick);
			// 
			// posGroupBox
			// 
			this->posGroupBox->Controls->Add(this->theta7Label);
			this->posGroupBox->Controls->Add(this->theta7TextBox);
			this->posGroupBox->Controls->Add(this->theta8Label);
			this->posGroupBox->Controls->Add(this->theta8TextBox);
			this->posGroupBox->Controls->Add(this->theta3TextBox);
			this->posGroupBox->Controls->Add(this->theta3Label);
			this->posGroupBox->Controls->Add(this->x6TextBox);
			this->posGroupBox->Controls->Add(this->theta4Label);
			this->posGroupBox->Controls->Add(this->x5Label);
			this->posGroupBox->Controls->Add(this->theta4TextBox);
			this->posGroupBox->Controls->Add(this->x5TextBox);
			this->posGroupBox->Controls->Add(this->theta6Label);
			this->posGroupBox->Controls->Add(this->y5Label);
			this->posGroupBox->Controls->Add(this->theta6TextBox);
			this->posGroupBox->Controls->Add(this->y5TextBox);
			this->posGroupBox->Controls->Add(this->theta2Label);
			this->posGroupBox->Controls->Add(this->x6Label);
			this->posGroupBox->Controls->Add(this->theta2TextBox);
			this->posGroupBox->Controls->Add(this->y6Label);
			this->posGroupBox->Controls->Add(this->y6TextBox);
			this->posGroupBox->Controls->Add(this->x7Label);
			this->posGroupBox->Controls->Add(this->x7TextBox);
			this->posGroupBox->Controls->Add(this->y7Label);
			this->posGroupBox->Controls->Add(this->y7TextBox);
			this->posGroupBox->Controls->Add(this->x8Label);
			this->posGroupBox->Controls->Add(this->x8TextBox);
			this->posGroupBox->Controls->Add(this->y8Label);
			this->posGroupBox->Controls->Add(this->y8TextBox);
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
			this->posGroupBox->Controls->Add(this->y3Label);
			this->posGroupBox->Controls->Add(this->y3TextBox);
			this->posGroupBox->Controls->Add(this->x4Label);
			this->posGroupBox->Controls->Add(this->x4TextBox);
			this->posGroupBox->Controls->Add(this->y4Label);
			this->posGroupBox->Controls->Add(this->y4TextBox);
			this->posGroupBox->Location = System::Drawing::Point(691, 13);
			this->posGroupBox->Name = L"posGroupBox";
			this->posGroupBox->Size = System::Drawing::Size(341, 351);
			this->posGroupBox->TabIndex = 1;
			this->posGroupBox->TabStop = false;
			this->posGroupBox->Text = L"Position (mm or degree)";
			// 
			// theta7Label
			// 
			this->theta7Label->AutoSize = true;
			this->theta7Label->Location = System::Drawing::Point(21, 316);
			this->theta7Label->Name = L"theta7Label";
			this->theta7Label->Size = System::Drawing::Size(48, 17);
			this->theta7Label->TabIndex = 66;
			this->theta7Label->Text = L"theta7";
			// 
			// theta7TextBox
			// 
			this->theta7TextBox->Location = System::Drawing::Point(76, 316);
			this->theta7TextBox->Name = L"theta7TextBox";
			this->theta7TextBox->ReadOnly = true;
			this->theta7TextBox->Size = System::Drawing::Size(76, 22);
			this->theta7TextBox->TabIndex = 67;
			this->theta7TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta8Label
			// 
			this->theta8Label->AutoSize = true;
			this->theta8Label->Location = System::Drawing::Point(185, 316);
			this->theta8Label->Name = L"theta8Label";
			this->theta8Label->Size = System::Drawing::Size(48, 17);
			this->theta8Label->TabIndex = 68;
			this->theta8Label->Text = L"theta8";
			// 
			// theta8TextBox
			// 
			this->theta8TextBox->Location = System::Drawing::Point(240, 316);
			this->theta8TextBox->Name = L"theta8TextBox";
			this->theta8TextBox->ReadOnly = true;
			this->theta8TextBox->Size = System::Drawing::Size(76, 22);
			this->theta8TextBox->TabIndex = 69;
			this->theta8TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta3TextBox
			// 
			this->theta3TextBox->Location = System::Drawing::Point(240, 260);
			this->theta3TextBox->Name = L"theta3TextBox";
			this->theta3TextBox->ReadOnly = true;
			this->theta3TextBox->Size = System::Drawing::Size(75, 22);
			this->theta3TextBox->TabIndex = 43;
			this->theta3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta3Label
			// 
			this->theta3Label->AutoSize = true;
			this->theta3Label->Location = System::Drawing::Point(185, 260);
			this->theta3Label->Name = L"theta3Label";
			this->theta3Label->Size = System::Drawing::Size(48, 17);
			this->theta3Label->TabIndex = 42;
			this->theta3Label->Text = L"theta3";
			// 
			// x6TextBox
			// 
			this->x6TextBox->Location = System::Drawing::Point(51, 176);
			this->x6TextBox->Name = L"x6TextBox";
			this->x6TextBox->ReadOnly = true;
			this->x6TextBox->Size = System::Drawing::Size(100, 22);
			this->x6TextBox->TabIndex = 55;
			this->x6TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta4Label
			// 
			this->theta4Label->AutoSize = true;
			this->theta4Label->Location = System::Drawing::Point(20, 288);
			this->theta4Label->Name = L"theta4Label";
			this->theta4Label->Size = System::Drawing::Size(48, 17);
			this->theta4Label->TabIndex = 44;
			this->theta4Label->Text = L"theta4";
			// 
			// x5Label
			// 
			this->x5Label->AutoSize = true;
			this->x5Label->Location = System::Drawing::Point(22, 151);
			this->x5Label->Name = L"x5Label";
			this->x5Label->Size = System::Drawing::Size(22, 17);
			this->x5Label->TabIndex = 50;
			this->x5Label->Text = L"x5";
			// 
			// theta4TextBox
			// 
			this->theta4TextBox->Location = System::Drawing::Point(75, 288);
			this->theta4TextBox->Name = L"theta4TextBox";
			this->theta4TextBox->ReadOnly = true;
			this->theta4TextBox->Size = System::Drawing::Size(76, 22);
			this->theta4TextBox->TabIndex = 45;
			this->theta4TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x5TextBox
			// 
			this->x5TextBox->Location = System::Drawing::Point(51, 148);
			this->x5TextBox->Name = L"x5TextBox";
			this->x5TextBox->ReadOnly = true;
			this->x5TextBox->Size = System::Drawing::Size(100, 22);
			this->x5TextBox->TabIndex = 51;
			this->x5TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta6Label
			// 
			this->theta6Label->AutoSize = true;
			this->theta6Label->Location = System::Drawing::Point(184, 288);
			this->theta6Label->Name = L"theta6Label";
			this->theta6Label->Size = System::Drawing::Size(48, 17);
			this->theta6Label->TabIndex = 46;
			this->theta6Label->Text = L"theta6";
			// 
			// y5Label
			// 
			this->y5Label->AutoSize = true;
			this->y5Label->Location = System::Drawing::Point(186, 151);
			this->y5Label->Name = L"y5Label";
			this->y5Label->Size = System::Drawing::Size(23, 17);
			this->y5Label->TabIndex = 52;
			this->y5Label->Text = L"y5";
			// 
			// theta6TextBox
			// 
			this->theta6TextBox->Location = System::Drawing::Point(239, 288);
			this->theta6TextBox->Name = L"theta6TextBox";
			this->theta6TextBox->ReadOnly = true;
			this->theta6TextBox->Size = System::Drawing::Size(76, 22);
			this->theta6TextBox->TabIndex = 47;
			this->theta6TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y5TextBox
			// 
			this->y5TextBox->Location = System::Drawing::Point(215, 148);
			this->y5TextBox->Name = L"y5TextBox";
			this->y5TextBox->ReadOnly = true;
			this->y5TextBox->Size = System::Drawing::Size(100, 22);
			this->y5TextBox->TabIndex = 53;
			this->y5TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta2Label
			// 
			this->theta2Label->AutoSize = true;
			this->theta2Label->Location = System::Drawing::Point(21, 260);
			this->theta2Label->Name = L"theta2Label";
			this->theta2Label->Size = System::Drawing::Size(48, 17);
			this->theta2Label->TabIndex = 48;
			this->theta2Label->Text = L"theta2";
			// 
			// x6Label
			// 
			this->x6Label->AutoSize = true;
			this->x6Label->Location = System::Drawing::Point(22, 179);
			this->x6Label->Name = L"x6Label";
			this->x6Label->Size = System::Drawing::Size(22, 17);
			this->x6Label->TabIndex = 54;
			this->x6Label->Text = L"x6";
			// 
			// theta2TextBox
			// 
			this->theta2TextBox->Location = System::Drawing::Point(76, 260);
			this->theta2TextBox->Name = L"theta2TextBox";
			this->theta2TextBox->ReadOnly = true;
			this->theta2TextBox->Size = System::Drawing::Size(75, 22);
			this->theta2TextBox->TabIndex = 49;
			this->theta2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y6Label
			// 
			this->y6Label->AutoSize = true;
			this->y6Label->Location = System::Drawing::Point(186, 179);
			this->y6Label->Name = L"y6Label";
			this->y6Label->Size = System::Drawing::Size(23, 17);
			this->y6Label->TabIndex = 56;
			this->y6Label->Text = L"y6";
			// 
			// y6TextBox
			// 
			this->y6TextBox->Location = System::Drawing::Point(215, 176);
			this->y6TextBox->Name = L"y6TextBox";
			this->y6TextBox->ReadOnly = true;
			this->y6TextBox->Size = System::Drawing::Size(100, 22);
			this->y6TextBox->TabIndex = 57;
			this->y6TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x7Label
			// 
			this->x7Label->AutoSize = true;
			this->x7Label->Location = System::Drawing::Point(22, 207);
			this->x7Label->Name = L"x7Label";
			this->x7Label->Size = System::Drawing::Size(22, 17);
			this->x7Label->TabIndex = 58;
			this->x7Label->Text = L"x7";
			// 
			// x7TextBox
			// 
			this->x7TextBox->Location = System::Drawing::Point(51, 204);
			this->x7TextBox->Name = L"x7TextBox";
			this->x7TextBox->ReadOnly = true;
			this->x7TextBox->Size = System::Drawing::Size(100, 22);
			this->x7TextBox->TabIndex = 59;
			this->x7TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y7Label
			// 
			this->y7Label->AutoSize = true;
			this->y7Label->Location = System::Drawing::Point(186, 207);
			this->y7Label->Name = L"y7Label";
			this->y7Label->Size = System::Drawing::Size(23, 17);
			this->y7Label->TabIndex = 60;
			this->y7Label->Text = L"y7";
			// 
			// y7TextBox
			// 
			this->y7TextBox->Location = System::Drawing::Point(215, 204);
			this->y7TextBox->Name = L"y7TextBox";
			this->y7TextBox->ReadOnly = true;
			this->y7TextBox->Size = System::Drawing::Size(100, 22);
			this->y7TextBox->TabIndex = 61;
			this->y7TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x8Label
			// 
			this->x8Label->AutoSize = true;
			this->x8Label->Location = System::Drawing::Point(22, 235);
			this->x8Label->Name = L"x8Label";
			this->x8Label->Size = System::Drawing::Size(22, 17);
			this->x8Label->TabIndex = 62;
			this->x8Label->Text = L"x8";
			// 
			// x8TextBox
			// 
			this->x8TextBox->Location = System::Drawing::Point(51, 232);
			this->x8TextBox->Name = L"x8TextBox";
			this->x8TextBox->ReadOnly = true;
			this->x8TextBox->Size = System::Drawing::Size(100, 22);
			this->x8TextBox->TabIndex = 63;
			this->x8TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y8Label
			// 
			this->y8Label->AutoSize = true;
			this->y8Label->Location = System::Drawing::Point(186, 235);
			this->y8Label->Name = L"y8Label";
			this->y8Label->Size = System::Drawing::Size(23, 17);
			this->y8Label->TabIndex = 64;
			this->y8Label->Text = L"y8";
			// 
			// y8TextBox
			// 
			this->y8TextBox->Location = System::Drawing::Point(215, 232);
			this->y8TextBox->Name = L"y8TextBox";
			this->y8TextBox->ReadOnly = true;
			this->y8TextBox->Size = System::Drawing::Size(100, 22);
			this->y8TextBox->TabIndex = 65;
			this->y8TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x2TextBox
			// 
			this->x2TextBox->Location = System::Drawing::Point(51, 64);
			this->x2TextBox->Name = L"x2TextBox";
			this->x2TextBox->ReadOnly = true;
			this->x2TextBox->Size = System::Drawing::Size(100, 22);
			this->x2TextBox->TabIndex = 31;
			this->x2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x1Label
			// 
			this->x1Label->AutoSize = true;
			this->x1Label->Location = System::Drawing::Point(22, 39);
			this->x1Label->Name = L"x1Label";
			this->x1Label->Size = System::Drawing::Size(22, 17);
			this->x1Label->TabIndex = 26;
			this->x1Label->Text = L"x1";
			// 
			// x1TextBox
			// 
			this->x1TextBox->Location = System::Drawing::Point(51, 36);
			this->x1TextBox->Name = L"x1TextBox";
			this->x1TextBox->ReadOnly = true;
			this->x1TextBox->Size = System::Drawing::Size(100, 22);
			this->x1TextBox->TabIndex = 27;
			this->x1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y1Label
			// 
			this->y1Label->AutoSize = true;
			this->y1Label->Location = System::Drawing::Point(186, 39);
			this->y1Label->Name = L"y1Label";
			this->y1Label->Size = System::Drawing::Size(23, 17);
			this->y1Label->TabIndex = 28;
			this->y1Label->Text = L"y1";
			// 
			// y1TextBox
			// 
			this->y1TextBox->Location = System::Drawing::Point(215, 36);
			this->y1TextBox->Name = L"y1TextBox";
			this->y1TextBox->ReadOnly = true;
			this->y1TextBox->Size = System::Drawing::Size(100, 22);
			this->y1TextBox->TabIndex = 29;
			this->y1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x2Label
			// 
			this->x2Label->AutoSize = true;
			this->x2Label->Location = System::Drawing::Point(22, 67);
			this->x2Label->Name = L"x2Label";
			this->x2Label->Size = System::Drawing::Size(22, 17);
			this->x2Label->TabIndex = 30;
			this->x2Label->Text = L"x2";
			// 
			// y2Label
			// 
			this->y2Label->AutoSize = true;
			this->y2Label->Location = System::Drawing::Point(186, 67);
			this->y2Label->Name = L"y2Label";
			this->y2Label->Size = System::Drawing::Size(23, 17);
			this->y2Label->TabIndex = 32;
			this->y2Label->Text = L"y2";
			// 
			// y2TextBox
			// 
			this->y2TextBox->Location = System::Drawing::Point(215, 64);
			this->y2TextBox->Name = L"y2TextBox";
			this->y2TextBox->ReadOnly = true;
			this->y2TextBox->Size = System::Drawing::Size(100, 22);
			this->y2TextBox->TabIndex = 33;
			this->y2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x3Label
			// 
			this->x3Label->AutoSize = true;
			this->x3Label->Location = System::Drawing::Point(22, 95);
			this->x3Label->Name = L"x3Label";
			this->x3Label->Size = System::Drawing::Size(22, 17);
			this->x3Label->TabIndex = 34;
			this->x3Label->Text = L"x3";
			// 
			// x3TextBox
			// 
			this->x3TextBox->Location = System::Drawing::Point(51, 92);
			this->x3TextBox->Name = L"x3TextBox";
			this->x3TextBox->ReadOnly = true;
			this->x3TextBox->Size = System::Drawing::Size(100, 22);
			this->x3TextBox->TabIndex = 35;
			this->x3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y3Label
			// 
			this->y3Label->AutoSize = true;
			this->y3Label->Location = System::Drawing::Point(186, 95);
			this->y3Label->Name = L"y3Label";
			this->y3Label->Size = System::Drawing::Size(23, 17);
			this->y3Label->TabIndex = 36;
			this->y3Label->Text = L"y3";
			// 
			// y3TextBox
			// 
			this->y3TextBox->Location = System::Drawing::Point(215, 92);
			this->y3TextBox->Name = L"y3TextBox";
			this->y3TextBox->ReadOnly = true;
			this->y3TextBox->Size = System::Drawing::Size(100, 22);
			this->y3TextBox->TabIndex = 37;
			this->y3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// x4Label
			// 
			this->x4Label->AutoSize = true;
			this->x4Label->Location = System::Drawing::Point(22, 123);
			this->x4Label->Name = L"x4Label";
			this->x4Label->Size = System::Drawing::Size(22, 17);
			this->x4Label->TabIndex = 38;
			this->x4Label->Text = L"x4";
			// 
			// x4TextBox
			// 
			this->x4TextBox->Location = System::Drawing::Point(51, 120);
			this->x4TextBox->Name = L"x4TextBox";
			this->x4TextBox->ReadOnly = true;
			this->x4TextBox->Size = System::Drawing::Size(100, 22);
			this->x4TextBox->TabIndex = 39;
			this->x4TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// y4Label
			// 
			this->y4Label->AutoSize = true;
			this->y4Label->Location = System::Drawing::Point(186, 123);
			this->y4Label->Name = L"y4Label";
			this->y4Label->Size = System::Drawing::Size(23, 17);
			this->y4Label->TabIndex = 40;
			this->y4Label->Text = L"y4";
			// 
			// y4TextBox
			// 
			this->y4TextBox->Location = System::Drawing::Point(215, 120);
			this->y4TextBox->Name = L"y4TextBox";
			this->y4TextBox->ReadOnly = true;
			this->y4TextBox->Size = System::Drawing::Size(100, 22);
			this->y4TextBox->TabIndex = 41;
			this->y4TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// velGroupBox
			// 
			this->velGroupBox->Controls->Add(this->theta8dTextBox);
			this->velGroupBox->Controls->Add(this->theta7dLabel);
			this->velGroupBox->Controls->Add(this->theta7dTextBox);
			this->velGroupBox->Controls->Add(this->theta8dLabel);
			this->velGroupBox->Controls->Add(this->theta4dTextBox);
			this->velGroupBox->Controls->Add(this->theta3dLabel);
			this->velGroupBox->Controls->Add(this->theta3dTextBox);
			this->velGroupBox->Controls->Add(this->thete4dLabel);
			this->velGroupBox->Location = System::Drawing::Point(691, 371);
			this->velGroupBox->Name = L"velGroupBox";
			this->velGroupBox->Size = System::Drawing::Size(341, 91);
			this->velGroupBox->TabIndex = 2;
			this->velGroupBox->TabStop = false;
			this->velGroupBox->Text = L"Angular Velocity (rad/s)";
			// 
			// theta8dTextBox
			// 
			this->theta8dTextBox->Location = System::Drawing::Point(240, 58);
			this->theta8dTextBox->Name = L"theta8dTextBox";
			this->theta8dTextBox->ReadOnly = true;
			this->theta8dTextBox->Size = System::Drawing::Size(80, 22);
			this->theta8dTextBox->TabIndex = 38;
			this->theta8dTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta7dLabel
			// 
			this->theta7dLabel->AutoSize = true;
			this->theta7dLabel->Location = System::Drawing::Point(14, 61);
			this->theta7dLabel->Name = L"theta7dLabel";
			this->theta7dLabel->Size = System::Drawing::Size(56, 17);
			this->theta7dLabel->TabIndex = 35;
			this->theta7dLabel->Text = L"theta7d";
			// 
			// theta7dTextBox
			// 
			this->theta7dTextBox->Location = System::Drawing::Point(76, 58);
			this->theta7dTextBox->Name = L"theta7dTextBox";
			this->theta7dTextBox->ReadOnly = true;
			this->theta7dTextBox->Size = System::Drawing::Size(80, 22);
			this->theta7dTextBox->TabIndex = 36;
			this->theta7dTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta8dLabel
			// 
			this->theta8dLabel->AutoSize = true;
			this->theta8dLabel->Location = System::Drawing::Point(178, 61);
			this->theta8dLabel->Name = L"theta8dLabel";
			this->theta8dLabel->Size = System::Drawing::Size(56, 17);
			this->theta8dLabel->TabIndex = 37;
			this->theta8dLabel->Text = L"theta8d";
			// 
			// theta4dTextBox
			// 
			this->theta4dTextBox->Location = System::Drawing::Point(240, 30);
			this->theta4dTextBox->Name = L"theta4dTextBox";
			this->theta4dTextBox->ReadOnly = true;
			this->theta4dTextBox->Size = System::Drawing::Size(80, 22);
			this->theta4dTextBox->TabIndex = 34;
			this->theta4dTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta3dLabel
			// 
			this->theta3dLabel->AutoSize = true;
			this->theta3dLabel->Location = System::Drawing::Point(14, 33);
			this->theta3dLabel->Name = L"theta3dLabel";
			this->theta3dLabel->Size = System::Drawing::Size(56, 17);
			this->theta3dLabel->TabIndex = 31;
			this->theta3dLabel->Text = L"theta3d";
			// 
			// theta3dTextBox
			// 
			this->theta3dTextBox->Location = System::Drawing::Point(76, 30);
			this->theta3dTextBox->Name = L"theta3dTextBox";
			this->theta3dTextBox->ReadOnly = true;
			this->theta3dTextBox->Size = System::Drawing::Size(80, 22);
			this->theta3dTextBox->TabIndex = 32;
			this->theta3dTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// thete4dLabel
			// 
			this->thete4dLabel->AutoSize = true;
			this->thete4dLabel->Location = System::Drawing::Point(178, 33);
			this->thete4dLabel->Name = L"thete4dLabel";
			this->thete4dLabel->Size = System::Drawing::Size(56, 17);
			this->thete4dLabel->TabIndex = 33;
			this->thete4dLabel->Text = L"theta4d";
			// 
			// accelGroupBox
			// 
			this->accelGroupBox->Controls->Add(this->theta8ddTextBox);
			this->accelGroupBox->Controls->Add(this->theta7ddLabel);
			this->accelGroupBox->Controls->Add(this->theta7ddTextBox);
			this->accelGroupBox->Controls->Add(this->theta8ddLabel);
			this->accelGroupBox->Controls->Add(this->theta4ddTextBox);
			this->accelGroupBox->Controls->Add(this->theta3ddLabel);
			this->accelGroupBox->Controls->Add(this->theta3ddTextBox);
			this->accelGroupBox->Controls->Add(this->theta4dLabel);
			this->accelGroupBox->Location = System::Drawing::Point(691, 469);
			this->accelGroupBox->Name = L"accelGroupBox";
			this->accelGroupBox->Size = System::Drawing::Size(341, 100);
			this->accelGroupBox->TabIndex = 3;
			this->accelGroupBox->TabStop = false;
			this->accelGroupBox->Text = L"Angular Acceleration (rad/s2)";
			// 
			// theta8ddTextBox
			// 
			this->theta8ddTextBox->Location = System::Drawing::Point(240, 59);
			this->theta8ddTextBox->Name = L"theta8ddTextBox";
			this->theta8ddTextBox->ReadOnly = true;
			this->theta8ddTextBox->Size = System::Drawing::Size(80, 22);
			this->theta8ddTextBox->TabIndex = 38;
			this->theta8ddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta7ddLabel
			// 
			this->theta7ddLabel->AutoSize = true;
			this->theta7ddLabel->Location = System::Drawing::Point(9, 62);
			this->theta7ddLabel->Name = L"theta7ddLabel";
			this->theta7ddLabel->Size = System::Drawing::Size(64, 17);
			this->theta7ddLabel->TabIndex = 35;
			this->theta7ddLabel->Text = L"theta7dd";
			// 
			// theta7ddTextBox
			// 
			this->theta7ddTextBox->Location = System::Drawing::Point(76, 59);
			this->theta7ddTextBox->Name = L"theta7ddTextBox";
			this->theta7ddTextBox->ReadOnly = true;
			this->theta7ddTextBox->Size = System::Drawing::Size(80, 22);
			this->theta7ddTextBox->TabIndex = 36;
			this->theta7ddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta8ddLabel
			// 
			this->theta8ddLabel->AutoSize = true;
			this->theta8ddLabel->Location = System::Drawing::Point(174, 62);
			this->theta8ddLabel->Name = L"theta8ddLabel";
			this->theta8ddLabel->Size = System::Drawing::Size(64, 17);
			this->theta8ddLabel->TabIndex = 37;
			this->theta8ddLabel->Text = L"theta8dd";
			// 
			// theta4ddTextBox
			// 
			this->theta4ddTextBox->Location = System::Drawing::Point(240, 31);
			this->theta4ddTextBox->Name = L"theta4ddTextBox";
			this->theta4ddTextBox->ReadOnly = true;
			this->theta4ddTextBox->Size = System::Drawing::Size(80, 22);
			this->theta4ddTextBox->TabIndex = 34;
			this->theta4ddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta3ddLabel
			// 
			this->theta3ddLabel->AutoSize = true;
			this->theta3ddLabel->Location = System::Drawing::Point(9, 34);
			this->theta3ddLabel->Name = L"theta3ddLabel";
			this->theta3ddLabel->Size = System::Drawing::Size(64, 17);
			this->theta3ddLabel->TabIndex = 31;
			this->theta3ddLabel->Text = L"theta3dd";
			// 
			// theta3ddTextBox
			// 
			this->theta3ddTextBox->Location = System::Drawing::Point(76, 31);
			this->theta3ddTextBox->Name = L"theta3ddTextBox";
			this->theta3ddTextBox->ReadOnly = true;
			this->theta3ddTextBox->Size = System::Drawing::Size(80, 22);
			this->theta3ddTextBox->TabIndex = 32;
			this->theta3ddTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// theta4dLabel
			// 
			this->theta4dLabel->AutoSize = true;
			this->theta4dLabel->Location = System::Drawing::Point(174, 34);
			this->theta4dLabel->Name = L"theta4dLabel";
			this->theta4dLabel->Size = System::Drawing::Size(64, 17);
			this->theta4dLabel->TabIndex = 33;
			this->theta4dLabel->Text = L"theta4dd";
			// 
			// pauseButton
			// 
			this->pauseButton->Location = System::Drawing::Point(797, 596);
			this->pauseButton->Name = L"pauseButton";
			this->pauseButton->Size = System::Drawing::Size(144, 35);
			this->pauseButton->TabIndex = 39;
			this->pauseButton->Text = L"Pause";
			this->pauseButton->UseVisualStyleBackColor = true;
			this->pauseButton->Click += gcnew System::EventHandler(this, &DrawSixBar::pauseButton_Click);
			// 
			// DrawSixBar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1062, 673);
			this->Controls->Add(this->pauseButton);
			this->Controls->Add(this->accelGroupBox);
			this->Controls->Add(this->velGroupBox);
			this->Controls->Add(this->posGroupBox);
			this->Controls->Add(this->panel1);
			this->Name = L"DrawSixBar";
			this->Text = L"Simulation Result";
			this->posGroupBox->ResumeLayout(false);
			this->posGroupBox->PerformLayout();
			this->velGroupBox->ResumeLayout(false);
			this->velGroupBox->PerformLayout();
			this->accelGroupBox->ResumeLayout(false);
			this->accelGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		double nRange = (r1 + r5);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

		theta4 = 2 * atan2((-b - sqrt(b * b - 4 * d * f)), (2 * d));
		theta3 = atan2(-r2 * sin(theta2) + r4 * sin(theta4), r1 - r2 * cos(theta2) + r4 * cos(theta4));
		double x3 = x2 + r3 * cos(theta3);
		double y3 = y2 + r3 * sin(theta3);

		double x5 = x4;
		double y5 = y4;
		theta6 = theta4;
		double x6 = x5 + r6 * cos(theta6);
		double y6 = y5 + r6 * sin(theta6);
		double x8 = x5 + r5;
		double y8 = y5;

		double h6 = r5 / r6;
		double h7 = r5 / r7;
		double h8 = r5 / r8;
		double h9 = (-pow(r5, 2) - pow(r6, 2) - pow(r7, 2) + pow(r8, 2)) / (2 * r6 * r7);
		double h10 = (pow(r5, 2) + pow(r6, 2) - pow(r7, 2) + pow(r8, 2)) / (2 * r6 * r8);

		double g = -h6 + (1 + h7) * cos(theta6) + h9;
		double h = -2 * sin(theta6);
		double i = h6 - (1 - h7) * cos(theta6) + h9;
		double j = -h6 + (1 - h8) * cos(theta6) + h10;
		double k = h6 - (1 + h8) * cos(theta6) + h10;

		theta8 = 2 * atan2((-h - sqrt(h * h - 4 * j * k)), (2 * j));
		theta7 = atan2(-r6 * sin(theta6) + r8 * sin(theta8), r5 - r6 * cos(theta6) + r8 * cos(theta8));
		double x7 = x6 + r7 * cos(theta7);
		double y7 = y6 + r7 * sin(theta7);

		if (theta2 >= 2 * PI) theta2 -= 2 * PI;
		if (theta2 < 0) theta2 += 2 * PI;
		if (theta3 >= 2 * PI) theta3 -= 2 * PI;
		if (theta3 < 0) theta3 += 2 * PI;
		if (theta4 >= 2 * PI) theta4 -= 2 * PI;
		if (theta4 < 0) theta4 += 2 * PI;
		if (theta6 >= 2 * PI) theta6 -= 2 * PI;
		if (theta6 < 0) theta6 += 2 * PI;
		if (theta7 >= 2 * PI) theta7 -= 2 * PI;
		if (theta7 < 0) theta7 += 2 * PI;
		if (theta8 >= 2 * PI) theta8 -= 2 * PI;
		if (theta8 < 0) theta8 += 2 * PI;

		double r[8] = { r1,r2,r3,r4,r5,r6,r7,r8 };
		SixBar sb(r, omega, 0);
		double theta[6] = { theta2,theta3,theta4,theta6,theta7,theta8 };
		double thetad[4];
		sb.Velocity(thetad, theta);	// get {theta3d, theta4d, theta7d, theta8d}
		double thetadd[4];
		sb.Acceleration(thetadd, theta, thetad);	// get {theta3dd, theta4dd, theta7dd, theta8dd}

		glTranslatef(-(r1 + r5) / 2, 0.0, 0.0);

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

		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(x5, y5);
		glVertex2f(x6, y6);

		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(x6, y6);
		glVertex2f(x7, y7);

		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(x7, y7);
		glVertex2f(x8, y8);

		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(x8, y8);
		glVertex2f(x5, y5);
		glEnd();

		glFlush();
		SwapBuffers(m_hDC);

		x1TextBox->Text = x1.ToString("N4");
		y1TextBox->Text = y1.ToString("N4");
		x2TextBox->Text = x2.ToString("N4");
		y2TextBox->Text = y2.ToString("N4");
		x3TextBox->Text = x3.ToString("N4");
		y3TextBox->Text = y3.ToString("N4");
		x4TextBox->Text = x4.ToString("N4");
		y4TextBox->Text = y4.ToString("N4");
		x5TextBox->Text = x5.ToString("N4");
		y5TextBox->Text = y5.ToString("N4");
		x6TextBox->Text = x6.ToString("N4");
		y6TextBox->Text = y6.ToString("N4");
		x7TextBox->Text = x7.ToString("N4");
		y7TextBox->Text = y7.ToString("N4");
		x8TextBox->Text = x8.ToString("N4");
		y8TextBox->Text = y8.ToString("N4");
		theta2TextBox->Text = (theta2 / dtr).ToString("N4");
		theta3TextBox->Text = (theta3 / dtr).ToString("N4");
		theta4TextBox->Text = (theta4 / dtr).ToString("N4");
		theta6TextBox->Text = (theta6 / dtr).ToString("N4");
		theta7TextBox->Text = (theta7 / dtr).ToString("N4");
		theta8TextBox->Text = (theta8 / dtr).ToString("N4");
		theta3dTextBox->Text = thetad[0].ToString("N4");
		theta4dTextBox->Text = thetad[1].ToString("N4");
		theta7dTextBox->Text = thetad[2].ToString("N4");
		theta8dTextBox->Text = thetad[3].ToString("N4");
		theta3ddTextBox->Text = thetadd[0].ToString("N4");
		theta4ddTextBox->Text = thetadd[1].ToString("N4");
		theta7ddTextBox->Text = thetadd[2].ToString("N4");
		theta8ddTextBox->Text = thetadd[3].ToString("N4");
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
