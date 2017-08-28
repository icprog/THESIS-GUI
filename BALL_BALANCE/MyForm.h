#pragma once
#include "camera/camera.hpp"
#include "pid/pid.hpp"
#include <sstream>
#include <string>
#include <iostream>


namespace BALL_BALANCE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	using namespace ZedGraph;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	Camera camera(0);
	PID pidX;
	PID pidY;
	
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
		/// Clean up any resources being used->
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  cbCOMLIST;
	private: System::Windows::Forms::TextBox^  txtRECEIVE;

	protected:

	private: System::Windows::Forms::Button^  bCONNECT;
	private: System::IO::Ports::SerialPort^  serialPort;
	private: System::Windows::Forms::Timer^  timerUART_Send;
	private: System::Windows::Forms::TextBox^  txtSEND;
	private: System::Windows::Forms::Timer^  timerUART_Receive;
	private: System::Windows::Forms::Button^  bSEND;
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::Timer^  timerGraph;
	private: System::Windows::Forms::TextBox^  txtSetpointX;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtSetpointY;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtPosX;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtPosY;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtErrY;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtErrX;










	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  bSTART;


	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  txtPIDY;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  txtPIDX;






	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  bSCROLL;
	private: System::Windows::Forms::TextBox^  txtKD2;
	private: System::Windows::Forms::TextBox^  txtKP2;
	private: System::Windows::Forms::TextBox^  txtKI2;
	private: System::Windows::Forms::TextBox^  txtKD1;
	private: System::Windows::Forms::TextBox^  txtKP1;
	private: System::Windows::Forms::TextBox^  txtKI1;
	private: System::Windows::Forms::Button^  bSETBALL;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::TrackBar^  trackBar3;





	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Required designer variable->
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor->
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->cbCOMLIST = (gcnew System::Windows::Forms::ComboBox());
			this->txtRECEIVE = (gcnew System::Windows::Forms::TextBox());
			this->bCONNECT = (gcnew System::Windows::Forms::Button());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->timerUART_Send = (gcnew System::Windows::Forms::Timer(this->components));
			this->txtSEND = (gcnew System::Windows::Forms::TextBox());
			this->timerUART_Receive = (gcnew System::Windows::Forms::Timer(this->components));
			this->bSEND = (gcnew System::Windows::Forms::Button());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->timerGraph = (gcnew System::Windows::Forms::Timer(this->components));
			this->txtSetpointX = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtSetpointY = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtPosX = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtPosY = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtErrY = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtErrX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->bSTART = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtPIDY = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtPIDX = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtKD2 = (gcnew System::Windows::Forms::TextBox());
			this->txtKP2 = (gcnew System::Windows::Forms::TextBox());
			this->txtKI2 = (gcnew System::Windows::Forms::TextBox());
			this->txtKD1 = (gcnew System::Windows::Forms::TextBox());
			this->txtKP1 = (gcnew System::Windows::Forms::TextBox());
			this->txtKI1 = (gcnew System::Windows::Forms::TextBox());
			this->bSCROLL = (gcnew System::Windows::Forms::Button());
			this->bSETBALL = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->SuspendLayout();
			// 
			// cbCOMLIST
			// 
			this->cbCOMLIST->FormattingEnabled = true;
			this->cbCOMLIST->Location = System::Drawing::Point(12, 12);
			this->cbCOMLIST->Name = L"cbCOMLIST";
			this->cbCOMLIST->Size = System::Drawing::Size(121, 21);
			this->cbCOMLIST->TabIndex = 0;
			// 
			// txtRECEIVE
			// 
			this->txtRECEIVE->Location = System::Drawing::Point(12, 73);
			this->txtRECEIVE->Name = L"txtRECEIVE";
			this->txtRECEIVE->Size = System::Drawing::Size(121, 20);
			this->txtRECEIVE->TabIndex = 1;
			// 
			// bCONNECT
			// 
			this->bCONNECT->Location = System::Drawing::Point(139, 12);
			this->bCONNECT->Name = L"bCONNECT";
			this->bCONNECT->Size = System::Drawing::Size(93, 23);
			this->bCONNECT->TabIndex = 2;
			this->bCONNECT->Text = L"CONNECT";
			this->bCONNECT->UseVisualStyleBackColor = true;
			this->bCONNECT->Click += gcnew System::EventHandler(this, &MyForm::bCONNECT_Click);
			// 
			// serialPort
			// 
			this->serialPort->BaudRate = 115200;
			// 
			// timerUART_Send
			// 
			this->timerUART_Send->Tick += gcnew System::EventHandler(this, &MyForm::eUARTSend);
			// 
			// txtSEND
			// 
			this->txtSEND->Location = System::Drawing::Point(13, 41);
			this->txtSEND->Name = L"txtSEND";
			this->txtSEND->Size = System::Drawing::Size(120, 20);
			this->txtSEND->TabIndex = 3;
			this->txtSEND->Text = L"90:60:120:90:90:110$";
			// 
			// timerUART_Receive
			// 
			this->timerUART_Receive->Tick += gcnew System::EventHandler(this, &MyForm::eUARTReceive);
			// 
			// bSEND
			// 
			this->bSEND->Location = System::Drawing::Point(139, 41);
			this->bSEND->Name = L"bSEND";
			this->bSEND->Size = System::Drawing::Size(93, 23);
			this->bSEND->TabIndex = 4;
			this->bSEND->Text = L"SEND";
			this->bSEND->UseVisualStyleBackColor = true;
			this->bSEND->Click += gcnew System::EventHandler(this, &MyForm::bSEND_Click);
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(327, 10);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(615, 316);
			this->zedGraphControl1->TabIndex = 5;
			// 
			// timerGraph
			// 
			this->timerGraph->Tick += gcnew System::EventHandler(this, &MyForm::eTimerGraph);
			// 
			// txtSetpointX
			// 
			this->txtSetpointX->Location = System::Drawing::Point(92, 28);
			this->txtSetpointX->Name = L"txtSetpointX";
			this->txtSetpointX->Size = System::Drawing::Size(46, 20);
			this->txtSetpointX->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"SET POINT X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(163, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"SET POINT Y";
			// 
			// txtSetpointY
			// 
			this->txtSetpointY->Location = System::Drawing::Point(243, 28);
			this->txtSetpointY->Name = L"txtSetpointY";
			this->txtSetpointY->Size = System::Drawing::Size(46, 20);
			this->txtSetpointY->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(47, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"POS X";
			// 
			// txtPosX
			// 
			this->txtPosX->Location = System::Drawing::Point(92, 54);
			this->txtPosX->Name = L"txtPosX";
			this->txtPosX->Size = System::Drawing::Size(46, 20);
			this->txtPosX->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(198, 57);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"POS Y";
			// 
			// txtPosY
			// 
			this->txtPosY->Location = System::Drawing::Point(243, 54);
			this->txtPosY->Name = L"txtPosY";
			this->txtPosY->Size = System::Drawing::Size(46, 20);
			this->txtPosY->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(181, 83);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"ERROR Y";
			// 
			// txtErrY
			// 
			this->txtErrY->Location = System::Drawing::Point(243, 80);
			this->txtErrY->Name = L"txtErrY";
			this->txtErrY->Size = System::Drawing::Size(46, 20);
			this->txtErrY->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(30, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"ERROR X";
			// 
			// txtErrX
			// 
			this->txtErrX->Location = System::Drawing::Point(92, 80);
			this->txtErrX->Name = L"txtErrX";
			this->txtErrX->Size = System::Drawing::Size(46, 20);
			this->txtErrX->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(65, 135);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"KP";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(65, 163);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"KI";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(65, 190);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(22, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"KD";
			// 
			// bSTART
			// 
			this->bSTART->Location = System::Drawing::Point(139, 70);
			this->bSTART->Name = L"bSTART";
			this->bSTART->Size = System::Drawing::Size(93, 23);
			this->bSTART->TabIndex = 22;
			this->bSTART->Text = L"START";
			this->bSTART->UseVisualStyleBackColor = true;
			this->bSTART->Click += gcnew System::EventHandler(this, &MyForm::bSTART_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(202, 109);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(35, 13);
			this->label10->TabIndex = 26;
			this->label10->Text = L"PID Y";
			// 
			// txtPIDY
			// 
			this->txtPIDY->Location = System::Drawing::Point(243, 106);
			this->txtPIDY->Name = L"txtPIDY";
			this->txtPIDY->Size = System::Drawing::Size(46, 20);
			this->txtPIDY->TabIndex = 25;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(51, 109);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(35, 13);
			this->label11->TabIndex = 24;
			this->label11->Text = L"PID X";
			// 
			// txtPIDX
			// 
			this->txtPIDX->Location = System::Drawing::Point(92, 106);
			this->txtPIDX->Name = L"txtPIDX";
			this->txtPIDX->Size = System::Drawing::Size(46, 20);
			this->txtPIDX->TabIndex = 23;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(216, 136);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(21, 13);
			this->label12->TabIndex = 19;
			this->label12->Text = L"KP";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(216, 164);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(17, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"KI";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(216, 191);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(22, 13);
			this->label14->TabIndex = 21;
			this->label14->Text = L"KD";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtKD2);
			this->groupBox1->Controls->Add(this->txtKP2);
			this->groupBox1->Controls->Add(this->txtKI2);
			this->groupBox1->Controls->Add(this->txtKD1);
			this->groupBox1->Controls->Add(this->txtKP1);
			this->groupBox1->Controls->Add(this->txtKI1);
			this->groupBox1->Controls->Add(this->txtPosY);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->txtSetpointX);
			this->groupBox1->Controls->Add(this->txtPIDY);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->txtSetpointY);
			this->groupBox1->Controls->Add(this->txtPIDX);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->txtPosX);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->txtErrX);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->txtErrY);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Location = System::Drawing::Point(13, 99);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(308, 227);
			this->groupBox1->TabIndex = 27;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"PARAM";
			// 
			// txtKD2
			// 
			this->txtKD2->Location = System::Drawing::Point(243, 184);
			this->txtKD2->Name = L"txtKD2";
			this->txtKD2->Size = System::Drawing::Size(46, 20);
			this->txtKD2->TabIndex = 32;
			// 
			// txtKP2
			// 
			this->txtKP2->Location = System::Drawing::Point(243, 132);
			this->txtKP2->Name = L"txtKP2";
			this->txtKP2->Size = System::Drawing::Size(46, 20);
			this->txtKP2->TabIndex = 30;
			// 
			// txtKI2
			// 
			this->txtKI2->Location = System::Drawing::Point(243, 158);
			this->txtKI2->Name = L"txtKI2";
			this->txtKI2->Size = System::Drawing::Size(46, 20);
			this->txtKI2->TabIndex = 31;
			// 
			// txtKD1
			// 
			this->txtKD1->Location = System::Drawing::Point(92, 184);
			this->txtKD1->Name = L"txtKD1";
			this->txtKD1->Size = System::Drawing::Size(46, 20);
			this->txtKD1->TabIndex = 29;
			// 
			// txtKP1
			// 
			this->txtKP1->Location = System::Drawing::Point(92, 132);
			this->txtKP1->Name = L"txtKP1";
			this->txtKP1->Size = System::Drawing::Size(46, 20);
			this->txtKP1->TabIndex = 27;
			// 
			// txtKI1
			// 
			this->txtKI1->Location = System::Drawing::Point(92, 158);
			this->txtKI1->Name = L"txtKI1";
			this->txtKI1->Size = System::Drawing::Size(46, 20);
			this->txtKI1->TabIndex = 28;
			// 
			// bSCROLL
			// 
			this->bSCROLL->Location = System::Drawing::Point(238, 70);
			this->bSCROLL->Name = L"bSCROLL";
			this->bSCROLL->Size = System::Drawing::Size(83, 23);
			this->bSCROLL->TabIndex = 22;
			this->bSCROLL->Text = L"SCROLL";
			this->bSCROLL->UseVisualStyleBackColor = true;
			this->bSCROLL->Click += gcnew System::EventHandler(this, &MyForm::bSCROLL_Click);
			// 
			// bSETBALL
			// 
			this->bSETBALL->Location = System::Drawing::Point(238, 41);
			this->bSETBALL->Name = L"bSETBALL";
			this->bSETBALL->Size = System::Drawing::Size(83, 23);
			this->bSETBALL->TabIndex = 22;
			this->bSETBALL->Text = L"SET BALL";
			this->bSETBALL->UseVisualStyleBackColor = true;
			this->bSETBALL->Click += gcnew System::EventHandler(this, &MyForm::bSETBALL_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(13, 332);
			this->trackBar1->Maximum = 1000;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(308, 45);
			this->trackBar1->TabIndex = 28;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(13, 373);
			this->trackBar2->Maximum = 1000;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(308, 45);
			this->trackBar2->TabIndex = 29;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(13, 409);
			this->trackBar3->Maximum = 10000;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(308, 45);
			this->trackBar3->TabIndex = 30;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(954, 466);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->bSETBALL);
			this->Controls->Add(this->bSCROLL);
			this->Controls->Add(this->bSTART);
			this->Controls->Add(this->zedGraphControl1);
			this->Controls->Add(this->bSEND);
			this->Controls->Add(this->txtSEND);
			this->Controls->Add(this->bCONNECT);
			this->Controls->Add(this->txtRECEIVE);
			this->Controls->Add(this->cbCOMLIST);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//===============================================
		//=====DEFINE====================================
		GraphPane^ myPane = gcnew GraphPane();
		PointPairList^ PosXList = gcnew PointPairList();
		PointPairList^ PosYList = gcnew PointPairList();
		PointPairList^ PosXSetpointList = gcnew PointPairList();
		PointPairList^ PosYSetpointList = gcnew PointPairList();
		LineItem^ PosXCurve;
		LineItem^ PosYCurve;
		LineItem^ PosXSetpointCurve;
		LineItem^ PosYSetpointCurve;

		ZedGraph::Scale^ xScale;
	private:
		double posX = 0;
		double posY = 0;
		double errX = 0;
		double errY = 0;
		double timeGraph = 0;
		double setpointX = 0;
		double setpointY = 0;
		bool SCROLL_GRAPH = false;

		//===============================================
		//=======CODE START HERE=========================

#pragma region Declare function 
	private: void findPorts(void)
	{
		// get port names
		array<Object^>^ objectArray = serialPort->GetPortNames();
		// add string array to combobox
		cbCOMLIST->Items->AddRange(objectArray);
	}

#pragma endregion

#pragma region PLOTTING GRAPH

	private: void initGraph()
	{
		myPane = zedGraphControl1->GraphPane;
		xScale = zedGraphControl1->GraphPane->XAxis->Scale;
		myPane->Title->Text = "SPEED-MOTOR";
		myPane->XAxis->Title->Text = "SEC(s)";
		myPane->YAxis->Title->Text = "RPM(v/p)";
		RollingPointPairList^ list1 = gcnew RollingPointPairList(6000);
		RollingPointPairList^ list2 = gcnew RollingPointPairList(6000);

		LineItem^ curve1 = myPane->AddCurve("SET-SPEED", list1, Color::Red, SymbolType::None);
		LineItem^ curve2 = myPane->AddCurve("ACT-SPEED", list2, Color::Blue, SymbolType::None);
		myPane->XAxis->Scale->Min = 0;
		myPane->XAxis->Scale->Max = 30;
		myPane->XAxis->Scale->MinorStep = 1;
		myPane->XAxis->Scale->MajorStep = 5;
		zedGraphControl1->AxisChange();
	}
	private: void draw(double x, double y)
	{
		if (timeGraph > xScale->Max - xScale->MajorStep)
		{
			if (SCROLL_GRAPH)
			{
				xScale->Max = timeGraph + xScale->MajorStep;
				xScale->Min = xScale->Max - 30.0;
			}
			else
			{
				xScale->Max = timeGraph + xScale->MajorStep;
				xScale->Min = 0;
			}
		}
		zedGraphControl1->GraphPane->CurveList->Clear();

		PosXList->Add(timeGraph, x);
		PosYList->Add(timeGraph, y);
		PosXSetpointList->Add(timeGraph, setpointX);
		PosYSetpointList->Add(timeGraph, setpointY);
		PosXCurve = myPane->AddCurve("Pos X", PosXList, Color::Red, SymbolType::Plus);
		PosYCurve = myPane->AddCurve("Pos Y", PosYList, Color::Red, SymbolType::Circle);
		PosXSetpointCurve = myPane->AddCurve("Pos Set point X", PosXSetpointList, Color::Blue, SymbolType::Plus);
		PosYSetpointCurve = myPane->AddCurve("Pos Set point Y", PosYSetpointList, Color::Blue, SymbolType::Circle);
		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
	}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		findPorts();
		initGraph();
		txtSetpointX->Text = "190";
		txtSetpointY->Text = "130";
		txtErrX->Text = "0";
		txtErrY->Text = "0";
		txtSEND->Text = "90:60:150:90:120:110$";
		txtKP1->Text = "25";
		txtKI1->Text = "0";
		txtKD1->Text = "1500";

		txtKP2->Text = "0";
		txtKI2->Text = "0";
		txtKD2->Text = "0";


	}
	private: System::Void bCONNECT_Click(System::Object^  sender, System::EventArgs^  e) {
		if (cbCOMLIST->Text != "")
		{
			if (bCONNECT->Text == "CONNECT")
			{
				bCONNECT->Text = "DISCONNECT";
				cbCOMLIST->Enabled = false;
				serialPort->PortName = cbCOMLIST->Text;
				serialPort->Open();
				//timerUART_Receive->Start();
				//timerUART_Send->Start();
			}
			else
			{
				bCONNECT->Text = "CONNECT";
				cbCOMLIST->Enabled = true;
				serialPort->Close();
				//timerUART_Receive->Stop();
				//timerUART_Send->Stop();
			}
		}
		else
		{
			MessageBox::Show("PLEASE CHOOSE PORT !!!!! ^_^ ");
		}
	}

	private: System::Void eUARTSend(System::Object^  sender, System::EventArgs^  e) 
	{
		pidX.setPIDParam(System::Convert::ToDouble(txtKP1->Text), System::Convert::ToDouble(txtKI1->Text), System::Convert::ToDouble(txtKD1->Text), 100);
		pidX.setPIDPeriod(5);
		pidX.setPIDOutputLimit(-20, 20);
		pidX.compute(errX);

		pidY.setPIDParam(System::Convert::ToDouble(txtKP2->Text), System::Convert::ToDouble(txtKI2->Text), System::Convert::ToDouble(txtKD2->Text), 100);
		pidY.setPIDPeriod(5);
		pidY.setPIDOutputLimit(-7, 7);
		pidY.compute(errY);

		txtPIDX->Text = (220 - (int)pidX.getOutput(110)).ToString();
		txtPIDY->Text = ((int)pidY.getOutput(120)).ToString();

		txtSEND->Text = "@90:60:150:90:" + txtPIDY->Text + ":" + txtPIDX->Text + "$";
		if (txtSEND->Text != "" && serialPort->IsOpen == true)
		{
			serialPort->Write(txtSEND->Text);
		}
	}
	private: System::Void eUARTReceive(System::Object^  sender, System::EventArgs^  e) {
		if (serialPort->IsOpen == true)
		{
			txtRECEIVE->Text = serialPort->ReadLine();
		}
	}


	private: System::Void bSEND_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bSEND->Text == "SEND")
		{
			timerUART_Send->Interval = 5;
			timerUART_Send->Start();
			bSEND->Text = "STOP SEND";
		}
		else
		{
			bSEND->Text = "START";
			timerUART_Send->Stop();
		}
	}


	private: System::Void eTimerGraph(System::Object^  sender, System::EventArgs^  e) {
		camera.getFPS_start();
		camera.getFrame();
		camera.detectBall();

		posX = camera.getX();
		posY = camera.getY();
		setpointX = System::Convert::ToDouble(txtSetpointX->Text);
		setpointY = System::Convert::ToDouble(txtSetpointY->Text);
		errX = setpointX - posX;
		errY = setpointY - posX;
			
		txtErrX->Text = errX.ToString();
		txtErrY->Text = errY.ToString();
		txtPosX->Text = posX.ToString();
		txtPosY->Text = posY.ToString();

		if (camera.getErrorStr() == "Tracking Object")
		{
			draw(posX, posY);
			timeGraph++;
		}
		camera.showCamera(1);
		camera.getFPS_end();
	}
	private: System::Void bSTART_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bSTART->Text == "START")
		{
			camera.setSize(640, 480);
			camera.setHSVParam(0, 84, 138, 255, 180, 255);
			//camera.createTrackbars();
			timerGraph->Interval = 1;
			timerGraph->Start();
			bSTART->Text = "STOP";
		}
		else
		{
			bSTART->Text = "START";
			timerGraph->Stop();
		}
		

	}

	private: System::Void bSCROLL_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bSCROLL->Text == "SCROLL")
		{
			SCROLL_GRAPH = true;
			bSCROLL->Text = "BLOCK";
		}
		else
		{
			SCROLL_GRAPH = false;
			bSCROLL->Text = "SCROLL";
		}

	}
private: System::Void bSETBALL_Click(System::Object^  sender, System::EventArgs^  e) {
	if (camera.getErrorStr() == "Tracking Object")
	{
		txtSetpointX->Text = posX.ToString();
		txtSetpointY->Text = posY.ToString();
	}
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	txtKP1->Text = trackBar1->Value.ToString();
}
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
	txtKI1->Text = trackBar2->Value.ToString();
}
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {
	txtKD1->Text = trackBar3->Value.ToString();
}
};
}