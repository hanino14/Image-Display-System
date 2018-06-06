#pragma once

#include "OpenGL.h"

int getrot(int, int);
static int sliderv;




namespace OpenGL_on_a_Windows_Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;



	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			HWND hwndChild1, hwndChild2, hwndChild3, hwndChild4;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			hwndChild1 = (HWND)pictureBox1->Handle.ToPointer();
			hwndChild2 = (HWND)pictureBox2->Handle.ToPointer();
			hwndChild3 = (HWND)pictureBox3->Handle.ToPointer();
			hwndChild4 = (HWND)pictureBox4->Handle.ToPointer();
			//400
			OpenGL = gcnew COpenGL(this,800, 800, hwndChild1, hwndChild2, hwndChild3, hwndChild4);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::HScrollBar^  hScrollBar2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::HScrollBar^  hScrollBar3;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::GroupBox^  View;
	private: System::Windows::Forms::RadioButton^  radioButtonBotRight;
	private: System::Windows::Forms::RadioButton^  radioButtonBotLeft;
	private: System::Windows::Forms::RadioButton^  radioButtonTopRight;
	private: System::Windows::Forms::RadioButton^  radioButtonTopLeft;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::HScrollBar^  hScrollBar4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;








	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar3 = (gcnew System::Windows::Forms::HScrollBar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->hScrollBar4 = (gcnew System::Windows::Forms::HScrollBar());
			this->View = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonBotRight = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonBotLeft = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonTopRight = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonTopLeft = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel1->SuspendLayout();
			this->View->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->button1->Location = System::Drawing::Point(66, 805);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(52, 226);
			this->hScrollBar1->Maximum = 360;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(175, 24);
			this->hScrollBar1->TabIndex = 1;
			this->hScrollBar1->Value = 45;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::hScrollBar1_Scroll);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->radioButton1->Location = System::Drawing::Point(58, 29);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(55, 21);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->Text = L"Axial";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->radioButton2->Location = System::Drawing::Point(58, 56);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(75, 21);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Coronal";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->radioButton3->Location = System::Drawing::Point(58, 83);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(69, 21);
			this->radioButton3->TabIndex = 5;
			this->radioButton3->Text = L"Sagital";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->groupBox1->Location = System::Drawing::Point(48, 475);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox1->Size = System::Drawing::Size(191, 127);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label1->Location = System::Drawing::Point(107, 204);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 22);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Rotation";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(50, 156);
			this->trackBar1->Maximum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(172, 45);
			this->trackBar1->TabIndex = 8;
			this->trackBar1->TickFrequency = 10;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label2->Location = System::Drawing::Point(107, 131);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 22);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Alpha";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label3->Location = System::Drawing::Point(107, 264);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 22);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Depth";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// hScrollBar2
			// 
			this->hScrollBar2->Location = System::Drawing::Point(52, 286);
			this->hScrollBar2->Name = L"hScrollBar2";
			this->hScrollBar2->Size = System::Drawing::Size(175, 24);
			this->hScrollBar2->TabIndex = 10;
			this->hScrollBar2->Value = 30;
			this->hScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::hScrollBar2_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label4->Location = System::Drawing::Point(107, 322);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 22);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Thick";
			// 
			// hScrollBar3
			// 
			this->hScrollBar3->Location = System::Drawing::Point(52, 344);
			this->hScrollBar3->Minimum = 2;
			this->hScrollBar3->Name = L"hScrollBar3";
			this->hScrollBar3->Size = System::Drawing::Size(175, 24);
			this->hScrollBar3->TabIndex = 12;
			this->hScrollBar3->Value = 5;
			this->hScrollBar3->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::hScrollBar3_Scroll);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->hScrollBar4);
			this->panel1->Controls->Add(this->View);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->hScrollBar3);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->hScrollBar2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->trackBar1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Controls->Add(this->hScrollBar1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(885, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(265, 933);
			this->panel1->TabIndex = 14;
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.75F));
			this->label13->ForeColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(14, 25);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(244, 49);
			this->label13->TabIndex = 22;
			this->label13->Text = L"Controls";
			this->label13->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label9->Location = System::Drawing::Point(117, 615);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 22);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Pane";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label8->Location = System::Drawing::Point(117, 456);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(44, 22);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Axis";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label6->Location = System::Drawing::Point(107, 386);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 22);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Zoom";
			// 
			// hScrollBar4
			// 
			this->hScrollBar4->Location = System::Drawing::Point(52, 408);
			this->hScrollBar4->Name = L"hScrollBar4";
			this->hScrollBar4->Size = System::Drawing::Size(175, 24);
			this->hScrollBar4->TabIndex = 16;
			this->hScrollBar4->Value = 30;
			this->hScrollBar4->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::hScrollBar4_Scroll);
			// 
			// View
			// 
			this->View->Controls->Add(this->radioButtonBotRight);
			this->View->Controls->Add(this->radioButtonBotLeft);
			this->View->Controls->Add(this->radioButtonTopRight);
			this->View->Controls->Add(this->radioButtonTopLeft);
			this->View->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->View->Location = System::Drawing::Point(48, 633);
			this->View->Name = L"View";
			this->View->Size = System::Drawing::Size(191, 133);
			this->View->TabIndex = 14;
			this->View->TabStop = false;
			// 
			// radioButtonBotRight
			// 
			this->radioButtonBotRight->AutoSize = true;
			this->radioButtonBotRight->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButtonBotRight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->radioButtonBotRight->Location = System::Drawing::Point(6, 98);
			this->radioButtonBotRight->Name = L"radioButtonBotRight";
			this->radioButtonBotRight->Size = System::Drawing::Size(166, 21);
			this->radioButtonBotRight->TabIndex = 3;
			this->radioButtonBotRight->Text = L"Pane 4 (Bottom Right)";
			this->radioButtonBotRight->UseVisualStyleBackColor = true;
			this->radioButtonBotRight->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButtonBotRight_CheckedChanged);
			// 
			// radioButtonBotLeft
			// 
			this->radioButtonBotLeft->AutoSize = true;
			this->radioButtonBotLeft->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButtonBotLeft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->radioButtonBotLeft->Location = System::Drawing::Point(6, 71);
			this->radioButtonBotLeft->Name = L"radioButtonBotLeft";
			this->radioButtonBotLeft->Size = System::Drawing::Size(157, 21);
			this->radioButtonBotLeft->TabIndex = 2;
			this->radioButtonBotLeft->Text = L"Pane 3 (Bottom Left)";
			this->radioButtonBotLeft->UseVisualStyleBackColor = true;
			this->radioButtonBotLeft->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButtonBotLeft_CheckedChanged);
			// 
			// radioButtonTopRight
			// 
			this->radioButtonTopRight->AutoSize = true;
			this->radioButtonTopRight->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButtonTopRight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->radioButtonTopRight->Location = System::Drawing::Point(6, 44);
			this->radioButtonTopRight->Name = L"radioButtonTopRight";
			this->radioButtonTopRight->Size = System::Drawing::Size(147, 21);
			this->radioButtonTopRight->TabIndex = 1;
			this->radioButtonTopRight->Text = L"Pane 2 (Top Right)";
			this->radioButtonTopRight->UseVisualStyleBackColor = true;
			this->radioButtonTopRight->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButtonTopRight_CheckedChanged);
			// 
			// radioButtonTopLeft
			// 
			this->radioButtonTopLeft->AutoSize = true;
			this->radioButtonTopLeft->Checked = true;
			this->radioButtonTopLeft->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButtonTopLeft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->radioButtonTopLeft->Location = System::Drawing::Point(6, 17);
			this->radioButtonTopLeft->Name = L"radioButtonTopLeft";
			this->radioButtonTopLeft->Size = System::Drawing::Size(138, 21);
			this->radioButtonTopLeft->TabIndex = 0;
			this->radioButtonTopLeft->TabStop = true;
			this->radioButtonTopLeft->Text = L"Pane 1 (Top Left)";
			this->radioButtonTopLeft->UseVisualStyleBackColor = true;
			this->radioButtonTopLeft->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButtonTopLeft_CheckedChanged);
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.75F));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(228, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(389, 35);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Image Display System";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox1->Location = System::Drawing::Point(12, 92);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox2->Location = System::Drawing::Point(450, 92);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(400, 400);
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox3->Location = System::Drawing::Point(12, 545);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(400, 400);
			this->pictureBox3->TabIndex = 17;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox4->Location = System::Drawing::Point(450, 545);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(400, 400);
			this->pictureBox4->TabIndex = 18;
			this->pictureBox4->TabStop = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::MidnightBlue;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label7->ForeColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->label7->Location = System::Drawing::Point(12, 54);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 24);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Pane 1";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::MidnightBlue;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label10->ForeColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->label10->Location = System::Drawing::Point(450, 515);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(69, 24);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Pane 4";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::MidnightBlue;
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label11->ForeColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->label11->Location = System::Drawing::Point(12, 515);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(69, 24);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Pane 3";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::MidnightBlue;
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->label12->ForeColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->label12->Location = System::Drawing::Point(450, 54);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(69, 24);
			this->label12->TabIndex = 21;
			this->label12->Text = L"Pane 2";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSlateGray;
			this->ClientSize = System::Drawing::Size(1162, 961);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"OpenGL on a Windows Form using Managed C++";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->View->ResumeLayout(false);
			this->View->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);
		OpenGL->Render();
		OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		exit(0);
	}
	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		int i = this->hScrollBar1->Value;
		getrot(1, i);
	}


	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		g_axis[0] = 1.;
		g_axis[1] = 0.;
		g_axis[2] = 0.;
		Display();
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		g_axis[0] = 0.;
		g_axis[1] = 1.;
		g_axis[2] = 0.;
		Display();
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		g_axis[0] = 0.;
		g_axis[1] = 0.;
		g_axis[2] = 1.;
		Display();
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
		g_alpha = (float)this->trackBar1->Value / 100.;
		Display();
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void hScrollBar3_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		g_thick = this->hScrollBar3->Value / 100.;
		Display();
	}
	private: System::Void hScrollBar2_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		g_depth = this->hScrollBar2->Value / 100.;
		Display();
	}

	private: System::Void mousedown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Point mouseDownLocation = Point(e->X, e->Y);
		float x = e->X; int y = e->Y;
		//drawstuff(e->X, e->Y);
	}



private: System::Void radioButtonTopLeft_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	int g_context;
	if (this->radioButtonTopLeft->Checked == 1)
		{
		g_context = 1;
		SetPane(g_context);
		}
}
	private: System::Void radioButtonTopRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		int g_context;
		if (this->radioButtonTopRight->Checked == 1)
			{
			g_context = 2;
			SetPane(g_context);
			}
}
private: System::Void radioButtonBotLeft_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	int g_context;
	if (this->radioButtonBotLeft->Checked == 1)
	{
		g_context = 3;
		SetPane(g_context);
	}
}
private: System::Void radioButtonBotRight_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	int g_context;
	if (this->radioButtonBotRight->Checked == 1)
	{
		g_context = 4;
		SetPane(g_context);
	}
}



private: System::Void hScrollBar4_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
	g_Zoom = this->hScrollBar4->Value / 25.;
	Display();
}


};
}


int getrot(int setget, int val)
{
	//
	//hwndChild1 = (HWND)pictureBox1->Handle.ToPointer();
	if (setget)
		sliderv = val;
	else
		return sliderv;

}