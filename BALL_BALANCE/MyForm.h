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

	private: System::Windows::Forms::NumericUpDown^  txtKP;
	private: System::Windows::Forms::NumericUpDown^  txtKI;
	private: System::Windows::Forms::NumericUpDown^  txtKD;



	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button1;





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
			this->txtKP = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtKI = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtKD = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtKP))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtKI))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtKD))->BeginInit();
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
			this->txtRECEIVE->Location = System::Drawing::Point(12, 66);
			this->txtRECEIVE->Name = L"txtRECEIVE";
			this->txtRECEIVE->Size = System::Drawing::Size(121, 20);
			this->txtRECEIVE->TabIndex = 1;
			// 
			// bCONNECT
			// 
			this->bCONNECT->Location = System::Drawing::Point(139, 12);
			this->bCONNECT->Name = L"bCONNECT";
			this->bCONNECT->Size = System::Drawing::Size(106, 23);
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
			this->txtSEND->Location = System::Drawing::Point(13, 40);
			this->txtSEND->Name = L"txtSEND";
			this->txtSEND->Size = System::Drawing::Size(120, 20);
			this->txtSEND->TabIndex = 3;
			// 
			// timerUART_Receive
			// 
			this->timerUART_Receive->Tick += gcnew System::EventHandler(this, &MyForm::eUARTReceive);
			// 
			// bSEND
			// 
			this->bSEND->Location = System::Drawing::Point(139, 41);
			this->bSEND->Name = L"bSEND";
			this->bSEND->Size = System::Drawing::Size(106, 23);
			this->bSEND->TabIndex = 4;
			this->bSEND->Text = L"SEND";
			this->bSEND->UseVisualStyleBackColor = true;
			this->bSEND->Click += gcnew System::EventHandler(this, &MyForm::bSEND_Click);
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(12, 107);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(650, 289);
			this->zedGraphControl1->TabIndex = 5;
			// 
			// timerGraph
			// 
			this->timerGraph->Tick += gcnew System::EventHandler(this, &MyForm::eTimerGraph);
			// 
			// txtSetpointX
			// 
			this->txtSetpointX->Location = System::Drawing::Point(342, 17);
			this->txtSetpointX->Name = L"txtSetpointX";
			this->txtSetpointX->Size = System::Drawing::Size(62, 20);
			this->txtSetpointX->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(262, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"SET POINT X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(262, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"SET POINT Y";
			// 
			// txtSetpointY
			// 
			this->txtSetpointY->Location = System::Drawing::Point(342, 43);
			this->txtSetpointY->Name = L"txtSetpointY";
			this->txtSetpointY->Size = System::Drawing::Size(62, 20);
			this->txtSetpointY->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(417, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"POS X";
			// 
			// txtPosX
			// 
			this->txtPosX->Location = System::Drawing::Point(462, 17);
			this->txtPosX->Name = L"txtPosX";
			this->txtPosX->Size = System::Drawing::Size(62, 20);
			this->txtPosX->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(417, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"POS Y";
			// 
			// txtPosY
			// 
			this->txtPosY->Location = System::Drawing::Point(462, 43);
			this->txtPosY->Name = L"txtPosY";
			this->txtPosY->Size = System::Drawing::Size(62, 20);
			this->txtPosY->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(538, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"ERROR Y";
			// 
			// txtErrY
			// 
			this->txtErrY->Location = System::Drawing::Point(600, 41);
			this->txtErrY->Name = L"txtErrY";
			this->txtErrY->Size = System::Drawing::Size(62, 20);
			this->txtErrY->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(538, 18);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"ERROR X";
			// 
			// txtErrX
			// 
			this->txtErrX->Location = System::Drawing::Point(600, 15);
			this->txtErrX->Name = L"txtErrX";
			this->txtErrX->Size = System::Drawing::Size(62, 20);
			this->txtErrX->TabIndex = 14;
			// 
			// txtKP
			// 
			this->txtKP->Location = System::Drawing::Point(345, 73);
			this->txtKP->Name = L"txtKP";
			this->txtKP->Size = System::Drawing::Size(42, 20);
			this->txtKP->TabIndex = 18;
			// 
			// txtKI
			// 
			this->txtKI->Location = System::Drawing::Point(420, 73);
			this->txtKI->Name = L"txtKI";
			this->txtKI->Size = System::Drawing::Size(42, 20);
			this->txtKI->TabIndex = 18;
			// 
			// txtKD
			// 
			this->txtKD->Location = System::Drawing::Point(498, 73);
			this->txtKD->Name = L"txtKD";
			this->txtKD->Size = System::Drawing::Size(42, 20);
			this->txtKD->TabIndex = 18;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(318, 77);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"KP";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(393, 75);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(17, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"KI";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(471, 75);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(22, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"KD";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(67, 411);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(178, 23);
			this->button1->TabIndex = 22;
			this->button1->Text = L"START GRAPH";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(689, 509);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txtKD);
			this->Controls->Add(this->txtKI);
			this->Controls->Add(this->txtKP);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtErrY);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtErrX);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtPosY);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtPosX);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtSetpointY);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtSetpointX);
			this->Controls->Add(this->zedGraphControl1);
			this->Controls->Add(this->bSEND);
			this->Controls->Add(this->txtSEND);
			this->Controls->Add(this->bCONNECT);
			this->Controls->Add(this->txtRECEIVE);
			this->Controls->Add(this->cbCOMLIST);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtKP))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtKI))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtKD))->EndInit();
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
	public:
		double posX = 0;
		double posY = 0;
		double timeGraph = 0;
		double setpointX = 0;
		double setpointY = 0;
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
			if (1)
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
		PosXCurve = myPane->AddCurve("Pos X", PosXList, Color::Red, SymbolType::Diamond);
		PosYCurve = myPane->AddCurve("Pos Y", PosYList, Color::Blue, SymbolType::Square);
		PosXSetpointCurve = myPane->AddCurve("Pos Set point X", PosXSetpointList, Color::Yellow);
		PosYSetpointCurve = myPane->AddCurve("Pos Set point Y", PosYSetpointList, Color::Purple);

		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
	}

#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		findPorts();
		initGraph();

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

	private: System::Void eUARTSend(System::Object^  sender, System::EventArgs^  e) {
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
		if (txtSEND->Text != "" && serialPort->IsOpen == true)
		{
			serialPort->Write(txtSEND->Text);
		}
	}


	private: System::Void eTimerGraph(System::Object^  sender, System::EventArgs^  e) {

		//txtSetpointX->Text = fps.ToString();
		//draw(camera.getX(), camera.getY());
		timeGraph++;
		//posX = timeGraph;
		//posY = posX * 0.5;
		//setpointX = 0;
		//setpointY = 0;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		timerGraph->Interval = 1;
		timerGraph->Start();

	}



	};
}