#pragma once
#include "camera/camera.hpp"
#include "pid/pid.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include "eFLL/fuzzy_ball_and_plate.h"

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
#pragma region auto_code
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
	private: System::Windows::Forms::Timer^  timerProcessing;

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
	private: System::Windows::Forms::TextBox^  txtANGLE_Y;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  txtANGLE_X;







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
	private: System::Windows::Forms::Button^  bCALIB;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::TrackBar^  trackBar5;
	private: System::Windows::Forms::TrackBar^  trackBar6;
	private: System::Windows::Forms::GroupBox^  PIDX;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  bSetCrop;
private: System::Windows::Forms::Button^  bSTART_GRAPH;

private: System::Windows::Forms::Button^  bSTART_PID;
private: System::Windows::Forms::TextBox^  txtTimeProcess;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Button^  bSTART_FUZZY;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::TextBox^  txtScaleOut1;

private: System::Windows::Forms::TextBox^  txtScaleVel1;


private: System::Windows::Forms::TextBox^  txtScaleErr1;



private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::Button^  bGetBall;
private: System::Windows::Forms::Button^  bShowCam;



private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::TextBox^  txtScaleVel3;

private: System::Windows::Forms::TextBox^  txtScaleVel2;

private: System::Windows::Forms::TextBox^  txtScaleErr3;

private: System::Windows::Forms::TextBox^  txtScaleErr2;
private: System::Windows::Forms::TextBox^  txtScaleOut3;



private: System::Windows::Forms::TextBox^  txtScaleOut2;
private: System::Windows::Forms::Button^  bSetFuzzyScale;
private: System::Windows::Forms::Button^  bSetPIDFactor;
private: System::Windows::Forms::Button^  bClose;











	private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Required designer variable->
		/// </summary>
#pragma endregion

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
			this->timerProcessing = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->txtANGLE_Y = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txtANGLE_X = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtTimeProcess = (gcnew System::Windows::Forms::TextBox());
			this->bSTART_GRAPH = (gcnew System::Windows::Forms::Button());
			this->bSCROLL = (gcnew System::Windows::Forms::Button());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->txtScaleOut1 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleVel1 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleErr1 = (gcnew System::Windows::Forms::TextBox());
			this->txtKD2 = (gcnew System::Windows::Forms::TextBox());
			this->txtKP2 = (gcnew System::Windows::Forms::TextBox());
			this->txtKI2 = (gcnew System::Windows::Forms::TextBox());
			this->txtKD1 = (gcnew System::Windows::Forms::TextBox());
			this->txtKP1 = (gcnew System::Windows::Forms::TextBox());
			this->txtKI1 = (gcnew System::Windows::Forms::TextBox());
			this->bSETBALL = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->bCALIB = (gcnew System::Windows::Forms::Button());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar6 = (gcnew System::Windows::Forms::TrackBar());
			this->PIDX = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->bSTART_FUZZY = (gcnew System::Windows::Forms::Button());
			this->bSTART_PID = (gcnew System::Windows::Forms::Button());
			this->bSetCrop = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->bGetBall = (gcnew System::Windows::Forms::Button());
			this->bShowCam = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->bSetPIDFactor = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->bSetFuzzyScale = (gcnew System::Windows::Forms::Button());
			this->txtScaleVel3 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleVel2 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleErr3 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleErr2 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleOut3 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleOut2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->bClose = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->BeginInit();
			this->PIDX->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->SuspendLayout();
			// 
			// cbCOMLIST
			// 
			this->cbCOMLIST->FormattingEnabled = true;
			this->cbCOMLIST->Location = System::Drawing::Point(11, 19);
			this->cbCOMLIST->Name = L"cbCOMLIST";
			this->cbCOMLIST->Size = System::Drawing::Size(88, 21);
			this->cbCOMLIST->TabIndex = 0;
			// 
			// txtRECEIVE
			// 
			this->txtRECEIVE->Location = System::Drawing::Point(11, 80);
			this->txtRECEIVE->Name = L"txtRECEIVE";
			this->txtRECEIVE->Size = System::Drawing::Size(88, 20);
			this->txtRECEIVE->TabIndex = 1;
			// 
			// bCONNECT
			// 
			this->bCONNECT->Location = System::Drawing::Point(109, 20);
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
			this->txtSEND->Location = System::Drawing::Point(12, 48);
			this->txtSEND->Name = L"txtSEND";
			this->txtSEND->Size = System::Drawing::Size(87, 20);
			this->txtSEND->TabIndex = 3;
			this->txtSEND->Text = L"00";
			this->txtSEND->TextChanged += gcnew System::EventHandler(this, &MyForm::txtSEND_TextChanged);
			// 
			// timerUART_Receive
			// 
			this->timerUART_Receive->Tick += gcnew System::EventHandler(this, &MyForm::eUARTReceive);
			// 
			// bSEND
			// 
			this->bSEND->Location = System::Drawing::Point(109, 49);
			this->bSEND->Name = L"bSEND";
			this->bSEND->Size = System::Drawing::Size(93, 23);
			this->bSEND->TabIndex = 4;
			this->bSEND->Text = L"SEND";
			this->bSEND->UseVisualStyleBackColor = true;
			this->bSEND->Click += gcnew System::EventHandler(this, &MyForm::bSEND_Click);
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(432, 12);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(468, 310);
			this->zedGraphControl1->TabIndex = 5;
			// 
			// timerProcessing
			// 
			this->timerProcessing->Tick += gcnew System::EventHandler(this, &MyForm::etimerProcessing);
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
			this->label2->Location = System::Drawing::Point(198, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"SET POINT Y";
			// 
			// txtSetpointY
			// 
			this->txtSetpointY->Location = System::Drawing::Point(144, 28);
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
			this->label4->Location = System::Drawing::Point(198, 59);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"POS Y";
			// 
			// txtPosY
			// 
			this->txtPosY->Location = System::Drawing::Point(144, 54);
			this->txtPosY->Name = L"txtPosY";
			this->txtPosY->Size = System::Drawing::Size(46, 20);
			this->txtPosY->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(198, 85);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"ERROR Y";
			// 
			// txtErrY
			// 
			this->txtErrY->Location = System::Drawing::Point(144, 80);
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
			this->label7->Location = System::Drawing::Point(26, 50);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"KP";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(26, 78);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"KI";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(26, 105);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(22, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"KD";
			// 
			// bSTART
			// 
			this->bSTART->Location = System::Drawing::Point(6, 19);
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
			this->label10->Location = System::Drawing::Point(198, 111);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(53, 13);
			this->label10->TabIndex = 26;
			this->label10->Text = L"ANGLE Y";
			// 
			// txtANGLE_Y
			// 
			this->txtANGLE_Y->Location = System::Drawing::Point(144, 106);
			this->txtANGLE_Y->Name = L"txtANGLE_Y";
			this->txtANGLE_Y->Size = System::Drawing::Size(46, 20);
			this->txtANGLE_Y->TabIndex = 25;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(30, 109);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 13);
			this->label11->TabIndex = 24;
			this->label11->Text = L"ANGLE X";
			// 
			// txtANGLE_X
			// 
			this->txtANGLE_X->Location = System::Drawing::Point(92, 106);
			this->txtANGLE_X->Name = L"txtANGLE_X";
			this->txtANGLE_X->Size = System::Drawing::Size(46, 20);
			this->txtANGLE_X->TabIndex = 23;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(106, 51);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(21, 13);
			this->label12->TabIndex = 19;
			this->label12->Text = L"KP";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(106, 79);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(17, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"KI";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(106, 106);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(22, 13);
			this->label14->TabIndex = 21;
			this->label14->Text = L"KD";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtPosY);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->txtSetpointX);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->txtANGLE_Y);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->txtSetpointY);
			this->groupBox1->Controls->Add(this->txtANGLE_X);
			this->groupBox1->Controls->Add(this->txtTimeProcess);
			this->groupBox1->Controls->Add(this->bSTART_GRAPH);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->bSCROLL);
			this->groupBox1->Controls->Add(this->txtPosX);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->txtErrX);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->txtErrY);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Location = System::Drawing::Point(12, 134);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(280, 188);
			this->groupBox1->TabIndex = 27;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"PARAM";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(53, 164);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(91, 13);
			this->label15->TabIndex = 38;
			this->label15->Text = L"SAMPLING TIME";
			// 
			// txtTimeProcess
			// 
			this->txtTimeProcess->Location = System::Drawing::Point(150, 161);
			this->txtTimeProcess->Name = L"txtTimeProcess";
			this->txtTimeProcess->Size = System::Drawing::Size(40, 20);
			this->txtTimeProcess->TabIndex = 35;
			// 
			// bSTART_GRAPH
			// 
			this->bSTART_GRAPH->Location = System::Drawing::Point(45, 131);
			this->bSTART_GRAPH->Name = L"bSTART_GRAPH";
			this->bSTART_GRAPH->Size = System::Drawing::Size(93, 24);
			this->bSTART_GRAPH->TabIndex = 37;
			this->bSTART_GRAPH->Text = L"START GRAPH";
			this->bSTART_GRAPH->UseVisualStyleBackColor = true;
			this->bSTART_GRAPH->Click += gcnew System::EventHandler(this, &MyForm::bSTART_GRAPH_Click);
			// 
			// bSCROLL
			// 
			this->bSCROLL->Location = System::Drawing::Point(144, 132);
			this->bSCROLL->Name = L"bSCROLL";
			this->bSCROLL->Size = System::Drawing::Size(93, 23);
			this->bSCROLL->TabIndex = 22;
			this->bSCROLL->Text = L"SCROLL";
			this->bSCROLL->UseVisualStyleBackColor = true;
			this->bSCROLL->Click += gcnew System::EventHandler(this, &MyForm::bSCROLL_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(16, 88);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(54, 13);
			this->label18->TabIndex = 34;
			this->label18->Text = L"Scale Out";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(16, 65);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(52, 13);
			this->label17->TabIndex = 34;
			this->label17->Text = L"Scale Vel";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(16, 36);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(50, 13);
			this->label16->TabIndex = 34;
			this->label16->Text = L"Scale Err";
			// 
			// txtScaleOut1
			// 
			this->txtScaleOut1->Location = System::Drawing::Point(77, 88);
			this->txtScaleOut1->Name = L"txtScaleOut1";
			this->txtScaleOut1->Size = System::Drawing::Size(57, 20);
			this->txtScaleOut1->TabIndex = 33;
			this->txtScaleOut1->Text = L"10";
			// 
			// txtScaleVel1
			// 
			this->txtScaleVel1->Location = System::Drawing::Point(77, 62);
			this->txtScaleVel1->Name = L"txtScaleVel1";
			this->txtScaleVel1->Size = System::Drawing::Size(57, 20);
			this->txtScaleVel1->TabIndex = 33;
			this->txtScaleVel1->Text = L"1";
			// 
			// txtScaleErr1
			// 
			this->txtScaleErr1->Location = System::Drawing::Point(77, 36);
			this->txtScaleErr1->Name = L"txtScaleErr1";
			this->txtScaleErr1->Size = System::Drawing::Size(57, 20);
			this->txtScaleErr1->TabIndex = 33;
			this->txtScaleErr1->Text = L"1";
			// 
			// txtKD2
			// 
			this->txtKD2->Location = System::Drawing::Point(133, 99);
			this->txtKD2->Name = L"txtKD2";
			this->txtKD2->Size = System::Drawing::Size(46, 20);
			this->txtKD2->TabIndex = 32;
			// 
			// txtKP2
			// 
			this->txtKP2->Location = System::Drawing::Point(133, 47);
			this->txtKP2->Name = L"txtKP2";
			this->txtKP2->Size = System::Drawing::Size(46, 20);
			this->txtKP2->TabIndex = 30;
			// 
			// txtKI2
			// 
			this->txtKI2->Location = System::Drawing::Point(133, 73);
			this->txtKI2->Name = L"txtKI2";
			this->txtKI2->Size = System::Drawing::Size(46, 20);
			this->txtKI2->TabIndex = 31;
			// 
			// txtKD1
			// 
			this->txtKD1->Location = System::Drawing::Point(53, 99);
			this->txtKD1->Name = L"txtKD1";
			this->txtKD1->Size = System::Drawing::Size(46, 20);
			this->txtKD1->TabIndex = 29;
			// 
			// txtKP1
			// 
			this->txtKP1->Location = System::Drawing::Point(53, 47);
			this->txtKP1->Name = L"txtKP1";
			this->txtKP1->Size = System::Drawing::Size(46, 20);
			this->txtKP1->TabIndex = 27;
			// 
			// txtKI1
			// 
			this->txtKI1->Location = System::Drawing::Point(53, 73);
			this->txtKI1->Name = L"txtKI1";
			this->txtKI1->Size = System::Drawing::Size(46, 20);
			this->txtKI1->TabIndex = 28;
			// 
			// bSETBALL
			// 
			this->bSETBALL->Location = System::Drawing::Point(105, 48);
			this->bSETBALL->Name = L"bSETBALL";
			this->bSETBALL->Size = System::Drawing::Size(93, 24);
			this->bSETBALL->TabIndex = 22;
			this->bSETBALL->Text = L"SET BALL";
			this->bSETBALL->UseVisualStyleBackColor = true;
			this->bSETBALL->Click += gcnew System::EventHandler(this, &MyForm::bSETBALL_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(17, 18);
			this->trackBar1->Maximum = 1000;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(170, 45);
			this->trackBar1->TabIndex = 28;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(17, 59);
			this->trackBar2->Maximum = 1000;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(170, 45);
			this->trackBar2->TabIndex = 29;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(17, 100);
			this->trackBar3->Maximum = 10000;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(170, 45);
			this->trackBar3->TabIndex = 30;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			// 
			// bCALIB
			// 
			this->bCALIB->Location = System::Drawing::Point(7, 48);
			this->bCALIB->Name = L"bCALIB";
			this->bCALIB->Size = System::Drawing::Size(92, 24);
			this->bCALIB->TabIndex = 31;
			this->bCALIB->Text = L"CALIB";
			this->bCALIB->UseVisualStyleBackColor = true;
			this->bCALIB->Click += gcnew System::EventHandler(this, &MyForm::bCALIB_Click);
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(12, 19);
			this->trackBar4->Maximum = 1000;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(170, 45);
			this->trackBar4->TabIndex = 28;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			// 
			// trackBar5
			// 
			this->trackBar5->Location = System::Drawing::Point(12, 60);
			this->trackBar5->Maximum = 1000;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(170, 45);
			this->trackBar5->TabIndex = 29;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar5_Scroll);
			// 
			// trackBar6
			// 
			this->trackBar6->Location = System::Drawing::Point(12, 96);
			this->trackBar6->Maximum = 10000;
			this->trackBar6->Name = L"trackBar6";
			this->trackBar6->Size = System::Drawing::Size(170, 45);
			this->trackBar6->TabIndex = 30;
			this->trackBar6->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar6_Scroll);
			// 
			// PIDX
			// 
			this->PIDX->Controls->Add(this->trackBar3);
			this->PIDX->Controls->Add(this->trackBar2);
			this->PIDX->Controls->Add(this->trackBar1);
			this->PIDX->Location = System::Drawing::Point(195, 18);
			this->PIDX->Name = L"PIDX";
			this->PIDX->Size = System::Drawing::Size(197, 142);
			this->PIDX->TabIndex = 32;
			this->PIDX->TabStop = false;
			this->PIDX->Text = L"X PID PARAMS";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->trackBar6);
			this->groupBox2->Controls->Add(this->trackBar5);
			this->groupBox2->Controls->Add(this->trackBar4);
			this->groupBox2->Location = System::Drawing::Point(395, 18);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(188, 142);
			this->groupBox2->TabIndex = 33;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Y PID PARAMS";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->cbCOMLIST);
			this->groupBox3->Controls->Add(this->txtRECEIVE);
			this->groupBox3->Controls->Add(this->bCONNECT);
			this->groupBox3->Controls->Add(this->txtSEND);
			this->groupBox3->Controls->Add(this->bSEND);
			this->groupBox3->Location = System::Drawing::Point(12, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(210, 116);
			this->groupBox3->TabIndex = 34;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"CONTROL";
			// 
			// bSTART_FUZZY
			// 
			this->bSTART_FUZZY->Location = System::Drawing::Point(19, 114);
			this->bSTART_FUZZY->Name = L"bSTART_FUZZY";
			this->bSTART_FUZZY->Size = System::Drawing::Size(90, 23);
			this->bSTART_FUZZY->TabIndex = 39;
			this->bSTART_FUZZY->Text = L"START FUZZY";
			this->bSTART_FUZZY->UseVisualStyleBackColor = true;
			this->bSTART_FUZZY->Click += gcnew System::EventHandler(this, &MyForm::bSTART_FUZZY_Click);
			// 
			// bSTART_PID
			// 
			this->bSTART_PID->Location = System::Drawing::Point(6, 18);
			this->bSTART_PID->Name = L"bSTART_PID";
			this->bSTART_PID->Size = System::Drawing::Size(93, 24);
			this->bSTART_PID->TabIndex = 36;
			this->bSTART_PID->Text = L"START PID";
			this->bSTART_PID->UseVisualStyleBackColor = true;
			this->bSTART_PID->Click += gcnew System::EventHandler(this, &MyForm::bSTART_PID_Click);
			// 
			// bSetCrop
			// 
			this->bSetCrop->Location = System::Drawing::Point(6, 78);
			this->bSetCrop->Name = L"bSetCrop";
			this->bSetCrop->Size = System::Drawing::Size(93, 25);
			this->bSetCrop->TabIndex = 35;
			this->bSetCrop->Text = L"SET CROP";
			this->bSetCrop->UseVisualStyleBackColor = true;
			this->bSetCrop->Click += gcnew System::EventHandler(this, &MyForm::bSetCrop_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->bGetBall);
			this->groupBox4->Controls->Add(this->bShowCam);
			this->groupBox4->Controls->Add(this->bSTART);
			this->groupBox4->Controls->Add(this->bCALIB);
			this->groupBox4->Controls->Add(this->bSetCrop);
			this->groupBox4->Controls->Add(this->bSETBALL);
			this->groupBox4->Location = System::Drawing::Point(224, 12);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(202, 116);
			this->groupBox4->TabIndex = 35;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"CAMERA";
			// 
			// bGetBall
			// 
			this->bGetBall->Location = System::Drawing::Point(105, 78);
			this->bGetBall->Name = L"bGetBall";
			this->bGetBall->Size = System::Drawing::Size(93, 26);
			this->bGetBall->TabIndex = 37;
			this->bGetBall->Text = L"GET BALL";
			this->bGetBall->UseVisualStyleBackColor = true;
			this->bGetBall->Click += gcnew System::EventHandler(this, &MyForm::bGetBall_Click);
			// 
			// bShowCam
			// 
			this->bShowCam->Location = System::Drawing::Point(105, 19);
			this->bShowCam->Name = L"bShowCam";
			this->bShowCam->Size = System::Drawing::Size(93, 23);
			this->bShowCam->TabIndex = 36;
			this->bShowCam->Text = L"SHOW CAM";
			this->bShowCam->UseVisualStyleBackColor = true;
			this->bShowCam->Click += gcnew System::EventHandler(this, &MyForm::bShowCam_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->bSetPIDFactor);
			this->groupBox5->Controls->Add(this->bSTART_PID);
			this->groupBox5->Controls->Add(this->txtKP1);
			this->groupBox5->Controls->Add(this->label7);
			this->groupBox5->Controls->Add(this->label8);
			this->groupBox5->Controls->Add(this->label9);
			this->groupBox5->Controls->Add(this->txtKI1);
			this->groupBox5->Controls->Add(this->groupBox2);
			this->groupBox5->Controls->Add(this->txtKD2);
			this->groupBox5->Controls->Add(this->txtKD1);
			this->groupBox5->Controls->Add(this->PIDX);
			this->groupBox5->Controls->Add(this->txtKP2);
			this->groupBox5->Controls->Add(this->txtKI2);
			this->groupBox5->Controls->Add(this->label12);
			this->groupBox5->Controls->Add(this->label13);
			this->groupBox5->Controls->Add(this->label14);
			this->groupBox5->Location = System::Drawing::Point(12, 328);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(594, 169);
			this->groupBox5->TabIndex = 40;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"PID";
			// 
			// bSetPIDFactor
			// 
			this->bSetPIDFactor->Location = System::Drawing::Point(105, 18);
			this->bSetPIDFactor->Name = L"bSetPIDFactor";
			this->bSetPIDFactor->Size = System::Drawing::Size(84, 23);
			this->bSetPIDFactor->TabIndex = 37;
			this->bSetPIDFactor->Text = L"SET";
			this->bSetPIDFactor->UseVisualStyleBackColor = true;
			this->bSetPIDFactor->Click += gcnew System::EventHandler(this, &MyForm::bSetPIDFactor_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->bSetFuzzyScale);
			this->groupBox6->Controls->Add(this->bSTART_FUZZY);
			this->groupBox6->Controls->Add(this->label18);
			this->groupBox6->Controls->Add(this->txtScaleVel3);
			this->groupBox6->Controls->Add(this->txtScaleVel2);
			this->groupBox6->Controls->Add(this->txtScaleVel1);
			this->groupBox6->Controls->Add(this->txtScaleErr3);
			this->groupBox6->Controls->Add(this->txtScaleErr2);
			this->groupBox6->Controls->Add(this->txtScaleErr1);
			this->groupBox6->Controls->Add(this->label17);
			this->groupBox6->Controls->Add(this->txtScaleOut3);
			this->groupBox6->Controls->Add(this->txtScaleOut2);
			this->groupBox6->Controls->Add(this->txtScaleOut1);
			this->groupBox6->Controls->Add(this->label16);
			this->groupBox6->Location = System::Drawing::Point(625, 328);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(275, 169);
			this->groupBox6->TabIndex = 41;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"FUZZY";
			// 
			// bSetFuzzyScale
			// 
			this->bSetFuzzyScale->Location = System::Drawing::Point(119, 115);
			this->bSetFuzzyScale->Name = L"bSetFuzzyScale";
			this->bSetFuzzyScale->Size = System::Drawing::Size(84, 21);
			this->bSetFuzzyScale->TabIndex = 40;
			this->bSetFuzzyScale->Text = L"SET";
			this->bSetFuzzyScale->UseVisualStyleBackColor = true;
			this->bSetFuzzyScale->Click += gcnew System::EventHandler(this, &MyForm::bSetFuzzyScale_Click);
			// 
			// txtScaleVel3
			// 
			this->txtScaleVel3->Location = System::Drawing::Point(203, 61);
			this->txtScaleVel3->Name = L"txtScaleVel3";
			this->txtScaleVel3->Size = System::Drawing::Size(57, 20);
			this->txtScaleVel3->TabIndex = 33;
			this->txtScaleVel3->Text = L"200";
			// 
			// txtScaleVel2
			// 
			this->txtScaleVel2->Location = System::Drawing::Point(140, 61);
			this->txtScaleVel2->Name = L"txtScaleVel2";
			this->txtScaleVel2->Size = System::Drawing::Size(57, 20);
			this->txtScaleVel2->TabIndex = 33;
			this->txtScaleVel2->Text = L"1";
			// 
			// txtScaleErr3
			// 
			this->txtScaleErr3->Location = System::Drawing::Point(203, 35);
			this->txtScaleErr3->Name = L"txtScaleErr3";
			this->txtScaleErr3->Size = System::Drawing::Size(57, 20);
			this->txtScaleErr3->TabIndex = 33;
			this->txtScaleErr3->Text = L"200";
			// 
			// txtScaleErr2
			// 
			this->txtScaleErr2->Location = System::Drawing::Point(140, 35);
			this->txtScaleErr2->Name = L"txtScaleErr2";
			this->txtScaleErr2->Size = System::Drawing::Size(57, 20);
			this->txtScaleErr2->TabIndex = 33;
			this->txtScaleErr2->Text = L"1";
			// 
			// txtScaleOut3
			// 
			this->txtScaleOut3->Location = System::Drawing::Point(203, 87);
			this->txtScaleOut3->Name = L"txtScaleOut3";
			this->txtScaleOut3->Size = System::Drawing::Size(57, 20);
			this->txtScaleOut3->TabIndex = 33;
			this->txtScaleOut3->Text = L"1";
			// 
			// txtScaleOut2
			// 
			this->txtScaleOut2->Location = System::Drawing::Point(140, 87);
			this->txtScaleOut2->Name = L"txtScaleOut2";
			this->txtScaleOut2->Size = System::Drawing::Size(57, 20);
			this->txtScaleOut2->TabIndex = 33;
			this->txtScaleOut2->Text = L"10";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->button4);
			this->groupBox7->Controls->Add(this->button3);
			this->groupBox7->Controls->Add(this->label19);
			this->groupBox7->Controls->Add(this->textBox1);
			this->groupBox7->Location = System::Drawing::Point(906, 12);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(181, 79);
			this->groupBox7->TabIndex = 42;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"DATA";
			this->groupBox7->Visible = false;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(93, 45);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(80, 27);
			this->button4->TabIndex = 2;
			this->button4->Text = L"EXPORT";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 45);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(80, 27);
			this->button3->TabIndex = 2;
			this->button3->Text = L"IMPORT";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 22);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(63, 13);
			this->label19->TabIndex = 1;
			this->label19->Text = L"FILE NAME";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(75, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(98, 20);
			this->textBox1->TabIndex = 0;
			// 
			// bClose
			// 
			this->bClose->Location = System::Drawing::Point(310, 157);
			this->bClose->Name = L"bClose";
			this->bClose->Size = System::Drawing::Size(109, 36);
			this->bClose->TabIndex = 43;
			this->bClose->Text = L"CLOSE";
			this->bClose->UseVisualStyleBackColor = true;
			this->bClose->Click += gcnew System::EventHandler(this, &MyForm::bClose_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1102, 509);
			this->Controls->Add(this->bClose);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->zedGraphControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar6))->EndInit();
			this->PIDX->ResumeLayout(false);
			this->PIDX->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		//===============================================
		//=====DEFINE====================================
		GraphPane^ myPane = gcnew GraphPane();
		PointPairList^ PosXList = gcnew PointPairList();
		PointPairList^ PosYList = gcnew PointPairList();
		PointPairList^ PosXYList = gcnew PointPairList();
		
		PointPairList^ PosXSetpointList = gcnew PointPairList();
		PointPairList^ PosYSetpointList = gcnew PointPairList();
		PointPairList^ PosXYSetpointList = gcnew PointPairList();

		LineItem^ PosXCurve;
		LineItem^ PosYCurve;
		LineItem^ PosXYCurve;

		LineItem^ PosXSetpointCurve;
		LineItem^ PosYSetpointCurve;
		LineItem^ PosXYSetpointCurve;

		ZedGraph::Scale^ xScale;
		ZedGraph::Scale^ yScale;
	private:
		double posX = 0;
		double posY = 0;
		double errX = 0;
		double errY = 0;
		double timeGraph = 0;
		double setpointX = 0;
		double setpointY = 0;
		bool SCROLL_GRAPH = false;
		double pre_errX = 0;
		double pre_errY = 0;
		double velX = 0;
		double velY = 0;
		double scale_errX = 1;
		double scale_velX = 1;
		double scale_outX = 1;
		double scale_errY = 1;
		double scale_velY = 1;
		double scale_outY = 1;
		double KpX = 0;
		double KiX = 0;
		double KdX = 0;
		double KpY = 0;
		double KiY = 0;
		double KdY = 0;
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
		yScale = zedGraphControl1->GraphPane->YAxis->Scale;
		myPane->Title->Text = "X-Y GRAPH";
		myPane->XAxis->Title->Text = "X";
		myPane->YAxis->Title->Text = "Y";
		RollingPointPairList^ list1 = gcnew RollingPointPairList(2000);
		RollingPointPairList^ list2 = gcnew RollingPointPairList(2000);

		LineItem^ curve1 = myPane->AddCurve("SET-SPEED", list1, Color::Red, SymbolType::None);
		LineItem^ curve2 = myPane->AddCurve("ACT-SPEED", list2, Color::Blue, SymbolType::None);
		xScale->Max = 400;
		xScale->Min = 0;
		yScale->Max = 400;
		yScale->Min = 0;
		myPane->IsAlignGrids = true;
		zedGraphControl1->AxisChange();
	}
	private: void draw(double x, double y)
	{
		zedGraphControl1->GraphPane->CurveList->Clear();
		if (bSCROLL->Text == "SCROLL")
		{
			PosXYList->Clear();
			PosXYList->Add(x, y);
			
			PosXYSetpointList->Clear();
			PosXYSetpointList->Add(setpointX, setpointY);

			PosXYCurve = myPane->AddCurve("Ball Position", PosXYList, Color::Red, SymbolType::Circle);
			PosXYSetpointCurve = myPane->AddCurve("Set point", PosXYSetpointList, Color::Blue, SymbolType::Square);
			timeGraph = 0;
		}
		else
		{
			if (timeGraph > xScale->Max - 1)
			{
				timeGraph = 0;
				PosXList->Clear();
				PosYList->Clear();

				PosXSetpointList->Clear();
				PosYSetpointList->Clear();
			}
			PosXList->Add(timeGraph, x);
			PosYList->Add(timeGraph, y);

			PosXSetpointList->Add(timeGraph, setpointX);
			PosYSetpointList->Add(timeGraph, setpointY);

			PosXCurve = myPane->AddCurve("Pos X", PosXList, Color::Red, SymbolType::Circle);
			PosYCurve = myPane->AddCurve("Pos Y", PosYList, Color::Blue, SymbolType::Circle);
			PosXSetpointCurve = myPane->AddCurve("Pos Set point X", PosXSetpointList, Color::Red, SymbolType::Default);
			PosYSetpointCurve = myPane->AddCurve("Pos Set point Y", PosYSetpointList, Color::Blue, SymbolType::Default);

			timeGraph++;
		}
		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
	}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		findPorts();
		initGraph();
		txtSetpointX->Text = "198";
		txtSetpointY->Text = "214";
		txtErrX->Text = "0";
		txtErrY->Text = "0";
		txtSEND->Text = "@0:0$";

		txtKP1->Text = "0";
		txtKI1->Text = "0";
		txtKD1->Text = "0";
		txtKP2->Text = "0";
		txtKI2->Text = "0";
		txtKD2->Text = "0";



		camera.setSize(640, 480);
		camera.setHSVParam(0, 84, 31, 255, 153, 255);
		camera.setCropFrame(118, 16, 400, 400);
		camera.applyCropFrame();
		timerProcessing->Interval = 1;

		Init_Fuzzy();

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
			findPorts();
		}
	}

	private: System::Void eUARTSend(System::Object^  sender, System::EventArgs^  e) 
	{
		txtSEND->Text = "@" + txtANGLE_Y->Text + ":" + txtANGLE_X->Text + "$";
	}
	private: System::Void eUARTReceive(System::Object^  sender, System::EventArgs^  e) {
		if (serialPort->IsOpen == true)
		{
			txtRECEIVE->Text = serialPort->ReadLine();
		}
	}


	private: System::Void bSEND_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bSEND->Text == "SEND" && bCONNECT->Text == "DISCONNECT")
		{
			timerUART_Send->Interval = 1;
			timerUART_Send->Start(); 
			bSEND->Text = "STOP SEND";
		}
		else if (bCONNECT->Text == "CONNECT")
		{
			MessageBox::Show("Please connect port !!!");
		}
		else
		{
			bSEND->Text = "SEND";
			timerUART_Send->Stop();
		}
	}


	private: System::Void etimerProcessing(System::Object^  sender, System::EventArgs^  e) {
		camera.getFPS_start();
		camera.getFrame();
		camera.detectBall();

		posX = camera.getX();
		posY = camera.getY();

		errX = setpointX - posX;
		errY = setpointY - posY;

		velX = (errX - pre_errX)*30;
		velY = (errY - pre_errY)*30;

		pre_errX = errX;
		pre_errY = errY;

		if (bSTART_PID->Text == "STOP PID" && bSTART_FUZZY->Text == "START FUZZY")
		{
			pidX.setPIDPeriod(1 / camera.fps_);
			pidX.setPIDOutputLimit(-10, 10);
			pidX.setPIDParam(System::Convert::ToDouble(txtKP1->Text), System::Convert::ToDouble(txtKI1->Text), System::Convert::ToDouble(txtKD1->Text), 0.01);
			pidX.compute(errX);

			pidY.setPIDPeriod(1 / camera.fps_);
			pidY.setPIDOutputLimit(-10, 10);
			pidY.setPIDParam(System::Convert::ToDouble(txtKP2->Text), System::Convert::ToDouble(txtKI2->Text), System::Convert::ToDouble(txtKD2->Text), 0.01);
			pidY.compute(errY);

			txtANGLE_X->Text = ((int)pidX.getOutput(0)).ToString();
			txtANGLE_Y->Text = (-(int)pidY.getOutput(0)).ToString();
		}
		if (bSTART_PID->Text == "START PID" && bSTART_FUZZY->Text == "STOP FUZZY")
		{
			//txtANGLE_X->Text = Fuzzy_OutPut((float)errX, (float)velX, (float)scale_errX, (float)scale_velX, (float)scale_outX, -10, 10).ToString();
			txtANGLE_Y->Text = (-Fuzzy_OutPut((float)errY, (float)velY, (float)scale_errY, (float)scale_velY, (float)scale_outY, -10, 10)).ToString();
			txtANGLE_X->Text = Fuzzy_OutPut((float)200, (float)200, (float)scale_errY, (float)scale_velY, (float)scale_outY, -10, 10).ToString();
			//txtANGLE_Y->Text = (-Fuzzy_OutPut((float)200, (float)200, (float)scale_errY, (float)scale_velY, (float)scale_outY, -10, 10)).ToString();
		}
		if (camera.getErrorStr() == "Tracking Object" && bSTART_GRAPH->Text == "STOP GRAPH")
		{
			draw(posX, posY);
		}
		if (bGetBall->Text == "UNGET BALL" /* && camera.getErrorStr() == "Tracking Object" */)
		{
			txtSetpointX->Text = posX.ToString();
			txtSetpointY->Text = posY.ToString();
		}
		txtErrX->Text = errX.ToString();
		txtErrY->Text = errY.ToString();
		txtPosX->Text = posX.ToString();
		txtPosY->Text = posY.ToString();
		if (bShowCam->Text == "UNSHOW CAM")
		{
			camera.showCamera(2);
		}
		camera.getFPS_end();
		txtTimeProcess->Text = ((int)(1000 / camera.fps_)).ToString() + " ms";
	}
	private: System::Void bSTART_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bSTART->Text == "START")
		{
			timerProcessing->Start();
			bSTART->Text = "STOP";
		}
		else
		{
			bSTART->Text = "START";
			timerProcessing->Stop();
		}
		

	}

	private: System::Void bSCROLL_Click(System::Object^  sender, System::EventArgs^  e) {
		if (bSCROLL->Text == "SCROLL")
		{
			bSCROLL->Text = "BLOCK";

			myPane->Title->Text = "TIMELINE GRAPH";
			myPane->XAxis->Title->Text = "TIME";
			myPane->YAxis->Title->Text = "POSTION";
			xScale->Max = 1000;
			timeGraph = 0;
			PosXList->Clear();
			PosYList->Clear();

			PosXSetpointList->Clear();
			PosYSetpointList->Clear();
		}
		else
		{
			bSCROLL->Text = "SCROLL";

			myPane->Title->Text = "X-Y GRAPH";
			myPane->XAxis->Title->Text = "X";
			myPane->YAxis->Title->Text = "Y";
			xScale->Max = 400;
		}

	}
private: System::Void bSETBALL_Click(System::Object^  sender, System::EventArgs^  e) {
		setpointX = System::Convert::ToDouble(txtSetpointX->Text);
		setpointY = System::Convert::ToDouble(txtSetpointY->Text);
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
private: System::Void bCALIB_Click(System::Object^  sender, System::EventArgs^  e) {
	camera.createTrackbars();
}
private: System::Void txtSEND_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (txtSEND->Text != "" && serialPort->IsOpen == true)
	{
		serialPort->Write(txtSEND->Text);
	}
}
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) {
	txtKP2->Text = trackBar4->Value.ToString();
}
private: System::Void trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e) {
	txtKI2->Text = trackBar5->Value.ToString();
}
private: System::Void trackBar6_Scroll(System::Object^  sender, System::EventArgs^  e) {
	txtKD2->Text = trackBar6->Value.ToString();
}
private: System::Void bSTART_PID_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bSTART_PID->Text == "START PID")
	{
		bSTART_PID->Text = "STOP PID";
	}
	else
	{
		bSTART_PID->Text = "START PID";
	}
}
private: System::Void bSTART_GRAPH_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bSTART_GRAPH->Text == "START GRAPH")
	{
		bSTART_GRAPH->Text = "STOP GRAPH";
	}
	else
	{
		bSTART_GRAPH->Text = "START GRAPH";
	}
}
private: System::Void bSTART_FUZZY_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bSTART_FUZZY->Text == "START FUZZY")
	{
		bSTART_FUZZY->Text = "STOP FUZZY";
	}
	else
	{
		bSTART_FUZZY->Text = "START FUZZY";
	}
}
private: System::Void bSetCrop_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void bSetFuzzyScale_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtScaleErr1->Text == "" || txtScaleErr2->Text == "" || txtScaleErr3->Text == "" ||
		txtScaleErr1->Text == "0" || txtScaleErr2->Text == "0" || txtScaleErr3->Text == "0" ||
		txtScaleVel1->Text == "" || txtScaleVel2->Text == "" || txtScaleVel3->Text == "" ||
		txtScaleVel1->Text == "0" || txtScaleVel2->Text == "0" || txtScaleVel3->Text == "0" ||
		txtScaleOut1->Text == "" || txtScaleOut2->Text == "" || txtScaleOut3->Text == "" ||
		txtScaleOut1->Text == "0" || txtScaleOut2->Text == "0" || txtScaleOut3->Text == "0"
		)
	{
		MessageBox::Show("Invalid input !!!! 'All input must be not null and zero.");
	}
	else
	{
		scale_errX = System::Convert::ToDouble(txtScaleErr1->Text) / System::Convert::ToDouble(txtScaleErr3->Text);
		scale_errY = System::Convert::ToDouble(txtScaleErr2->Text) / System::Convert::ToDouble(txtScaleErr3->Text);

		scale_velX = System::Convert::ToDouble(txtScaleVel1->Text) / System::Convert::ToDouble(txtScaleVel3->Text);
		scale_velY = System::Convert::ToDouble(txtScaleVel2->Text) / System::Convert::ToDouble(txtScaleVel3->Text);

		scale_outX = System::Convert::ToDouble(txtScaleOut1->Text) / System::Convert::ToDouble(txtScaleOut3->Text);
		scale_outY = System::Convert::ToDouble(txtScaleOut2->Text) / System::Convert::ToDouble(txtScaleOut3->Text);
	}


}

private: System::Void bGetBall_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bGetBall->Text == "GET BALL")
	{
		bGetBall->Text = "UNGET BALL";
	}
	else
	{
		bGetBall->Text = "GET BALL";
	}
}

private: System::Void bShowCam_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bShowCam->Text == "SHOW CAM")
	{
		bShowCam->Text = "UNSHOW CAM";
	}
	else
	{
		bShowCam->Text = "SHOW CAM";
		camera.unshowCamera(2);
	}
}
private: System::Void bSetPIDFactor_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtKP1->Text == "" || txtKI1->Text == "" || txtKD1->Text == "" ||
		txtKP2->Text == "" || txtKI2->Text == "" || txtKD2->Text == ""
		)
	{
		MessageBox::Show("Invalid input !!!! 'All input must be not null.");
	}
	else
	{
		KpX = System::Convert::ToDouble(txtKP1->Text);
		KiX = System::Convert::ToDouble(txtKI1->Text);
		KdX = System::Convert::ToDouble(txtKD1->Text);
		KpY = System::Convert::ToDouble(txtKP2->Text);
		KiY = System::Convert::ToDouble(txtKI2->Text);
		KdY = System::Convert::ToDouble(txtKD2->Text);
	}

}
private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
};
}