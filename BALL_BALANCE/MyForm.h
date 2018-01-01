#pragma once
#include "camera/camera.hpp"
//#include "pid/pid.hpp"
#include <sstream>
#include <string>
#include <iostream>
//#include "eFLL/fuzzy_ball_and_plate.h"
//#include "structure/iofile.hpp"
#include<fstream>



namespace BALL_BALANCE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Collections::Generic;
	using namespace ZedGraph;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	Camera camera(0);
	//PID pidX;
	//PID pidY;

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


	private: System::Windows::Forms::Timer^  timerProcessing;

	private: System::Windows::Forms::TextBox^  txtSetpointX;

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TextBox^  txtSetpointY;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtPosX;


	private: System::Windows::Forms::TextBox^  txtPosY;


	private: System::Windows::Forms::TextBox^  txtErrY;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txtErrX;










	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  bSTART_CAM;






	private: System::Windows::Forms::TextBox^  txtANGLE_Y;


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




	private: System::Windows::Forms::Button^  bCALIB;







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





private: System::Windows::Forms::Button^  bShowCam;














private: System::Windows::Forms::TextBox^  txtScaleVel2;
private: System::Windows::Forms::TextBox^  txtScaleFuzzy;



private: System::Windows::Forms::TextBox^  txtScaleErr2;




private: System::Windows::Forms::TextBox^  txtScaleOut2;
private: System::Windows::Forms::Button^  bSetFuzzyScaleXY;
private: System::Windows::Forms::Button^  bSetPIDFactor;

private: System::Windows::Forms::TrackBar^  tbAngleX;
private: System::Windows::Forms::TrackBar^  tbAngleY;
private: System::Windows::Forms::TabControl^  tabControlController;

private: System::Windows::Forms::TabPage^  tabPage1;
private: System::Windows::Forms::TabPage^  tabPage2;










private: System::Windows::Forms::TabPage^  tabPage5;
private: System::Windows::Forms::TabPage^  tabPage;



private: System::Windows::Forms::TabPage^  tabPage6;











private: System::Windows::Forms::Label^  label5;










private: System::Windows::Forms::TextBox^  txtDisplayAngle6;


private: System::Windows::Forms::TextBox^  txtDisplayAngle5;

private: System::Windows::Forms::TextBox^  txtDisplayAngle4;

private: System::Windows::Forms::TextBox^  txtDisplayAngle3;

private: System::Windows::Forms::TextBox^  txtDisplayAngle2;

private: System::Windows::Forms::TextBox^  txtDisplayAngle1;
private: System::Windows::Forms::Button^  bClearGraph;





































private: System::Windows::Forms::TextBox^  txtDErrY;


private: System::Windows::Forms::TextBox^  txtDErrX;

private: System::Windows::Forms::Label^  label21;






private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label29;

private: System::Windows::Forms::TextBox^  txtSamplingRate;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::TabPage^  tabPageMOREGRAPH;
private: ZedGraph::ZedGraphControl^  zedGraphMore;
private: System::Windows::Forms::TabPage^  tabPageTIMEGRAPH;

private: ZedGraph::ZedGraphControl^  zedGraphTime;

private: System::Windows::Forms::TabPage^  tabPageXYGRAPH;
private: ZedGraph::ZedGraphControl^  zedGraphXY;
private: System::Windows::Forms::TabControl^  tabControlGraph;





private: System::Windows::Forms::Timer^  timerTracking;



private: System::Windows::Forms::Timer^  timerCamera;
private: System::Windows::Forms::Timer^  timerDisplay;
private: System::Windows::Forms::GroupBox^  groupBox2;

private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::TextBox^  txtSpeedChangePoint;
private: System::Windows::Forms::TextBox^  txtNumOfPoint;
private: System::Windows::Forms::TextBox^  txtCenterCircleY;

private: System::Windows::Forms::Button^  bSTART_TRACK;
private: System::Windows::Forms::TextBox^  txtCenterCircleX;

private: System::Windows::Forms::TextBox^  txtSetSPY;
private: System::Windows::Forms::TextBox^  txtSetSPX;
private: System::Windows::Forms::Button^  bImportTrajectory;
private: System::Windows::Forms::Button^  bSETBALL;
private: System::Windows::Forms::RadioButton^  radioOther;

private: System::Windows::Forms::RadioButton^  radioCircle;

private: System::Windows::Forms::RadioButton^  radioPoint;

private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::TextBox^  txtRadiusCircle;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::TextBox^  txtScalePID;
private: System::Windows::Forms::Label^  label19;

private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label20;













































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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->cbCOMLIST = (gcnew System::Windows::Forms::ComboBox());
			this->txtRECEIVE = (gcnew System::Windows::Forms::TextBox());
			this->bCONNECT = (gcnew System::Windows::Forms::Button());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->timerUART_Send = (gcnew System::Windows::Forms::Timer(this->components));
			this->txtSEND = (gcnew System::Windows::Forms::TextBox());
			this->timerUART_Receive = (gcnew System::Windows::Forms::Timer(this->components));
			this->bSEND = (gcnew System::Windows::Forms::Button());
			this->timerProcessing = (gcnew System::Windows::Forms::Timer(this->components));
			this->txtSetpointX = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtSetpointY = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtPosX = (gcnew System::Windows::Forms::TextBox());
			this->txtPosY = (gcnew System::Windows::Forms::TextBox());
			this->txtErrY = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtErrX = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->bSTART_CAM = (gcnew System::Windows::Forms::Button());
			this->txtANGLE_Y = (gcnew System::Windows::Forms::TextBox());
			this->txtANGLE_X = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtSamplingRate = (gcnew System::Windows::Forms::TextBox());
			this->txtDErrY = (gcnew System::Windows::Forms::TextBox());
			this->txtDErrX = (gcnew System::Windows::Forms::TextBox());
			this->txtTimeProcess = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
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
			this->bCALIB = (gcnew System::Windows::Forms::Button());
			this->bSTART_FUZZY = (gcnew System::Windows::Forms::Button());
			this->bSTART_PID = (gcnew System::Windows::Forms::Button());
			this->bShowCam = (gcnew System::Windows::Forms::Button());
			this->bSetPIDFactor = (gcnew System::Windows::Forms::Button());
			this->bSetFuzzyScaleXY = (gcnew System::Windows::Forms::Button());
			this->txtScaleVel2 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleFuzzy = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleErr2 = (gcnew System::Windows::Forms::TextBox());
			this->txtScaleOut2 = (gcnew System::Windows::Forms::TextBox());
			this->tbAngleX = (gcnew System::Windows::Forms::TrackBar());
			this->tbAngleY = (gcnew System::Windows::Forms::TrackBar());
			this->tabControlController = (gcnew System::Windows::Forms::TabControl());
			this->tabPage = (gcnew System::Windows::Forms::TabPage());
			this->bClearGraph = (gcnew System::Windows::Forms::Button());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->txtDisplayAngle2 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->txtDisplayAngle1 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->txtDisplayAngle3 = (gcnew System::Windows::Forms::TextBox());
			this->txtDisplayAngle6 = (gcnew System::Windows::Forms::TextBox());
			this->txtDisplayAngle4 = (gcnew System::Windows::Forms::TextBox());
			this->txtDisplayAngle5 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->txtSpeedChangePoint = (gcnew System::Windows::Forms::TextBox());
			this->txtNumOfPoint = (gcnew System::Windows::Forms::TextBox());
			this->txtRadiusCircle = (gcnew System::Windows::Forms::TextBox());
			this->txtCenterCircleY = (gcnew System::Windows::Forms::TextBox());
			this->bSTART_TRACK = (gcnew System::Windows::Forms::Button());
			this->txtCenterCircleX = (gcnew System::Windows::Forms::TextBox());
			this->txtSetSPY = (gcnew System::Windows::Forms::TextBox());
			this->txtSetSPX = (gcnew System::Windows::Forms::TextBox());
			this->bImportTrajectory = (gcnew System::Windows::Forms::Button());
			this->bSETBALL = (gcnew System::Windows::Forms::Button());
			this->radioOther = (gcnew System::Windows::Forms::RadioButton());
			this->radioCircle = (gcnew System::Windows::Forms::RadioButton());
			this->radioPoint = (gcnew System::Windows::Forms::RadioButton());
			this->tabPageMOREGRAPH = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphMore = (gcnew ZedGraph::ZedGraphControl());
			this->tabPageTIMEGRAPH = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphTime = (gcnew ZedGraph::ZedGraphControl());
			this->tabPageXYGRAPH = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphXY = (gcnew ZedGraph::ZedGraphControl());
			this->tabControlGraph = (gcnew System::Windows::Forms::TabControl());
			this->timerTracking = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerCamera = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerDisplay = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->txtScalePID = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAngleX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAngleY))->BeginInit();
			this->tabControlController->SuspendLayout();
			this->tabPage->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabPageMOREGRAPH->SuspendLayout();
			this->tabPageTIMEGRAPH->SuspendLayout();
			this->tabPageXYGRAPH->SuspendLayout();
			this->tabControlGraph->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// cbCOMLIST
			// 
			this->cbCOMLIST->FormattingEnabled = true;
			this->cbCOMLIST->Location = System::Drawing::Point(9, 20);
			this->cbCOMLIST->Name = L"cbCOMLIST";
			this->cbCOMLIST->Size = System::Drawing::Size(73, 21);
			this->cbCOMLIST->TabIndex = 0;
			// 
			// txtRECEIVE
			// 
			this->txtRECEIVE->Location = System::Drawing::Point(9, 75);
			this->txtRECEIVE->Name = L"txtRECEIVE";
			this->txtRECEIVE->Size = System::Drawing::Size(254, 20);
			this->txtRECEIVE->TabIndex = 1;
			// 
			// bCONNECT
			// 
			this->bCONNECT->Location = System::Drawing::Point(88, 17);
			this->bCONNECT->Name = L"bCONNECT";
			this->bCONNECT->Size = System::Drawing::Size(87, 24);
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
			this->txtSEND->Location = System::Drawing::Point(9, 49);
			this->txtSEND->Name = L"txtSEND";
			this->txtSEND->Size = System::Drawing::Size(254, 20);
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
			this->bSEND->Location = System::Drawing::Point(181, 16);
			this->bSEND->Name = L"bSEND";
			this->bSEND->Size = System::Drawing::Size(82, 25);
			this->bSEND->TabIndex = 4;
			this->bSEND->Text = L"SEND";
			this->bSEND->UseVisualStyleBackColor = true;
			this->bSEND->Click += gcnew System::EventHandler(this, &MyForm::bSEND_Click);
			// 
			// txtSetpointX
			// 
			this->txtSetpointX->Location = System::Drawing::Point(136, 27);
			this->txtSetpointX->Name = L"txtSetpointX";
			this->txtSetpointX->Size = System::Drawing::Size(64, 20);
			this->txtSetpointX->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"SET POINT X - Y";
			// 
			// txtSetpointY
			// 
			this->txtSetpointY->Location = System::Drawing::Point(206, 27);
			this->txtSetpointY->Name = L"txtSetpointY";
			this->txtSetpointY->Size = System::Drawing::Size(61, 20);
			this->txtSetpointY->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"POS X - Y";
			// 
			// txtPosX
			// 
			this->txtPosX->Location = System::Drawing::Point(136, 53);
			this->txtPosX->Name = L"txtPosX";
			this->txtPosX->Size = System::Drawing::Size(64, 20);
			this->txtPosX->TabIndex = 10;
			// 
			// txtPosY
			// 
			this->txtPosY->Location = System::Drawing::Point(206, 53);
			this->txtPosY->Name = L"txtPosY";
			this->txtPosY->Size = System::Drawing::Size(61, 20);
			this->txtPosY->TabIndex = 12;
			// 
			// txtErrY
			// 
			this->txtErrY->Location = System::Drawing::Point(206, 79);
			this->txtErrY->Name = L"txtErrY";
			this->txtErrY->Size = System::Drawing::Size(61, 20);
			this->txtErrY->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 82);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"ERROR X - Y";
			// 
			// txtErrX
			// 
			this->txtErrX->Location = System::Drawing::Point(136, 79);
			this->txtErrX->Name = L"txtErrX";
			this->txtErrX->Size = System::Drawing::Size(64, 20);
			this->txtErrX->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(14, 62);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(27, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"KpX";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(14, 90);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(23, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"KiX";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(14, 117);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(27, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"KdX";
			// 
			// bSTART_CAM
			// 
			this->bSTART_CAM->Location = System::Drawing::Point(9, 101);
			this->bSTART_CAM->Name = L"bSTART_CAM";
			this->bSTART_CAM->Size = System::Drawing::Size(129, 23);
			this->bSTART_CAM->TabIndex = 22;
			this->bSTART_CAM->Text = L"START CAM";
			this->bSTART_CAM->UseVisualStyleBackColor = true;
			this->bSTART_CAM->Click += gcnew System::EventHandler(this, &MyForm::bSTART_CAM_Click);
			// 
			// txtANGLE_Y
			// 
			this->txtANGLE_Y->Location = System::Drawing::Point(206, 132);
			this->txtANGLE_Y->Name = L"txtANGLE_Y";
			this->txtANGLE_Y->Size = System::Drawing::Size(61, 20);
			this->txtANGLE_Y->TabIndex = 25;
			// 
			// txtANGLE_X
			// 
			this->txtANGLE_X->Location = System::Drawing::Point(136, 132);
			this->txtANGLE_X->Name = L"txtANGLE_X";
			this->txtANGLE_X->Size = System::Drawing::Size(64, 20);
			this->txtANGLE_X->TabIndex = 23;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(141, 63);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(27, 13);
			this->label12->TabIndex = 19;
			this->label12->Text = L"KpY";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(141, 91);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(23, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"KiY";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(141, 118);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(27, 13);
			this->label14->TabIndex = 21;
			this->label14->Text = L"KdY";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtSamplingRate);
			this->groupBox1->Controls->Add(this->txtDErrY);
			this->groupBox1->Controls->Add(this->txtDErrX);
			this->groupBox1->Controls->Add(this->txtTimeProcess);
			this->groupBox1->Controls->Add(this->label21);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->txtPosY);
			this->groupBox1->Controls->Add(this->txtSetpointX);
			this->groupBox1->Controls->Add(this->label34);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->txtANGLE_Y);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->txtSetpointY);
			this->groupBox1->Controls->Add(this->txtANGLE_X);
			this->groupBox1->Controls->Add(this->txtPosX);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->txtErrX);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->txtErrY);
			this->groupBox1->Location = System::Drawing::Point(12, 476);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(273, 212);
			this->groupBox1->TabIndex = 27;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"PARAM";
			// 
			// txtSamplingRate
			// 
			this->txtSamplingRate->Location = System::Drawing::Point(206, 158);
			this->txtSamplingRate->Name = L"txtSamplingRate";
			this->txtSamplingRate->Size = System::Drawing::Size(61, 20);
			this->txtSamplingRate->TabIndex = 42;
			// 
			// txtDErrY
			// 
			this->txtDErrY->Location = System::Drawing::Point(206, 105);
			this->txtDErrY->Name = L"txtDErrY";
			this->txtDErrY->Size = System::Drawing::Size(61, 20);
			this->txtDErrY->TabIndex = 41;
			// 
			// txtDErrX
			// 
			this->txtDErrX->Location = System::Drawing::Point(136, 105);
			this->txtDErrX->Name = L"txtDErrX";
			this->txtDErrX->Size = System::Drawing::Size(64, 20);
			this->txtDErrX->TabIndex = 40;
			// 
			// txtTimeProcess
			// 
			this->txtTimeProcess->Location = System::Drawing::Point(206, 185);
			this->txtTimeProcess->Name = L"txtTimeProcess";
			this->txtTimeProcess->Size = System::Drawing::Size(61, 20);
			this->txtTimeProcess->TabIndex = 35;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(12, 108);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(95, 13);
			this->label21->TabIndex = 24;
			this->label21->Text = L"DERIV  ERR X - Y";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 134);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L"ANGLE X - Y";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(12, 186);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(106, 13);
			this->label34->TabIndex = 38;
			this->label34->Text = L"PROCESSING TIME";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(12, 160);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(102, 13);
			this->label15->TabIndex = 38;
			this->label15->Text = L"POINTS / UPDATE";
			// 
			// bSTART_GRAPH
			// 
			this->bSTART_GRAPH->Location = System::Drawing::Point(144, 101);
			this->bSTART_GRAPH->Name = L"bSTART_GRAPH";
			this->bSTART_GRAPH->Size = System::Drawing::Size(119, 24);
			this->bSTART_GRAPH->TabIndex = 37;
			this->bSTART_GRAPH->Text = L"START GRAPH";
			this->bSTART_GRAPH->UseVisualStyleBackColor = true;
			this->bSTART_GRAPH->Click += gcnew System::EventHandler(this, &MyForm::bSTART_GRAPH_Click);
			// 
			// bSCROLL
			// 
			this->bSCROLL->Location = System::Drawing::Point(144, 131);
			this->bSCROLL->Name = L"bSCROLL";
			this->bSCROLL->Size = System::Drawing::Size(119, 23);
			this->bSCROLL->TabIndex = 22;
			this->bSCROLL->Text = L"SLIDE";
			this->bSCROLL->UseVisualStyleBackColor = true;
			this->bSCROLL->Click += gcnew System::EventHandler(this, &MyForm::bSCROLL_Click);
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(19, 111);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(27, 13);
			this->label18->TabIndex = 34;
			this->label18->Text = L"KuX";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(19, 88);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(27, 13);
			this->label17->TabIndex = 34;
			this->label17->Text = L"KdX";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(19, 59);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(27, 13);
			this->label16->TabIndex = 34;
			this->label16->Text = L"KpX";
			// 
			// txtScaleOut1
			// 
			this->txtScaleOut1->Location = System::Drawing::Point(66, 111);
			this->txtScaleOut1->Name = L"txtScaleOut1";
			this->txtScaleOut1->Size = System::Drawing::Size(71, 20);
			this->txtScaleOut1->TabIndex = 33;
			this->txtScaleOut1->Text = L"10";
			// 
			// txtScaleVel1
			// 
			this->txtScaleVel1->Location = System::Drawing::Point(66, 85);
			this->txtScaleVel1->Name = L"txtScaleVel1";
			this->txtScaleVel1->Size = System::Drawing::Size(71, 20);
			this->txtScaleVel1->TabIndex = 33;
			this->txtScaleVel1->Text = L"1";
			// 
			// txtScaleErr1
			// 
			this->txtScaleErr1->Location = System::Drawing::Point(66, 59);
			this->txtScaleErr1->Name = L"txtScaleErr1";
			this->txtScaleErr1->Size = System::Drawing::Size(71, 20);
			this->txtScaleErr1->TabIndex = 33;
			this->txtScaleErr1->Text = L"1";
			// 
			// txtKD2
			// 
			this->txtKD2->Location = System::Drawing::Point(169, 111);
			this->txtKD2->Name = L"txtKD2";
			this->txtKD2->Size = System::Drawing::Size(83, 20);
			this->txtKD2->TabIndex = 32;
			// 
			// txtKP2
			// 
			this->txtKP2->Location = System::Drawing::Point(169, 59);
			this->txtKP2->Name = L"txtKP2";
			this->txtKP2->Size = System::Drawing::Size(83, 20);
			this->txtKP2->TabIndex = 30;
			// 
			// txtKI2
			// 
			this->txtKI2->Location = System::Drawing::Point(169, 85);
			this->txtKI2->Name = L"txtKI2";
			this->txtKI2->Size = System::Drawing::Size(83, 20);
			this->txtKI2->TabIndex = 31;
			// 
			// txtKD1
			// 
			this->txtKD1->Location = System::Drawing::Point(41, 111);
			this->txtKD1->Name = L"txtKD1";
			this->txtKD1->Size = System::Drawing::Size(85, 20);
			this->txtKD1->TabIndex = 29;
			// 
			// txtKP1
			// 
			this->txtKP1->Location = System::Drawing::Point(41, 59);
			this->txtKP1->Name = L"txtKP1";
			this->txtKP1->Size = System::Drawing::Size(85, 20);
			this->txtKP1->TabIndex = 27;
			// 
			// txtKI1
			// 
			this->txtKI1->Location = System::Drawing::Point(41, 85);
			this->txtKI1->Name = L"txtKI1";
			this->txtKI1->Size = System::Drawing::Size(85, 20);
			this->txtKI1->TabIndex = 28;
			// 
			// bCALIB
			// 
			this->bCALIB->Location = System::Drawing::Point(9, 160);
			this->bCALIB->Name = L"bCALIB";
			this->bCALIB->Size = System::Drawing::Size(128, 25);
			this->bCALIB->TabIndex = 31;
			this->bCALIB->Text = L"CALIB";
			this->bCALIB->UseVisualStyleBackColor = true;
			this->bCALIB->Click += gcnew System::EventHandler(this, &MyForm::bCALIB_Click);
			// 
			// bSTART_FUZZY
			// 
			this->bSTART_FUZZY->Location = System::Drawing::Point(6, 7);
			this->bSTART_FUZZY->Name = L"bSTART_FUZZY";
			this->bSTART_FUZZY->Size = System::Drawing::Size(133, 43);
			this->bSTART_FUZZY->TabIndex = 39;
			this->bSTART_FUZZY->Text = L"START FUZZY";
			this->bSTART_FUZZY->UseVisualStyleBackColor = true;
			this->bSTART_FUZZY->Click += gcnew System::EventHandler(this, &MyForm::bSTART_FUZZY_Click);
			// 
			// bSTART_PID
			// 
			this->bSTART_PID->Location = System::Drawing::Point(4, 6);
			this->bSTART_PID->Name = L"bSTART_PID";
			this->bSTART_PID->Size = System::Drawing::Size(133, 39);
			this->bSTART_PID->TabIndex = 36;
			this->bSTART_PID->Text = L"START PID";
			this->bSTART_PID->UseVisualStyleBackColor = true;
			this->bSTART_PID->Click += gcnew System::EventHandler(this, &MyForm::bSTART_PID_Click);
			// 
			// bShowCam
			// 
			this->bShowCam->Location = System::Drawing::Point(9, 130);
			this->bShowCam->Name = L"bShowCam";
			this->bShowCam->Size = System::Drawing::Size(129, 24);
			this->bShowCam->TabIndex = 36;
			this->bShowCam->Text = L"SHOW CAM";
			this->bShowCam->UseVisualStyleBackColor = true;
			this->bShowCam->Click += gcnew System::EventHandler(this, &MyForm::bShowCam_Click);
			// 
			// bSetPIDFactor
			// 
			this->bSetPIDFactor->Location = System::Drawing::Point(143, 6);
			this->bSetPIDFactor->Name = L"bSetPIDFactor";
			this->bSetPIDFactor->Size = System::Drawing::Size(120, 38);
			this->bSetPIDFactor->TabIndex = 37;
			this->bSetPIDFactor->Text = L"SET";
			this->bSetPIDFactor->UseVisualStyleBackColor = true;
			this->bSetPIDFactor->Click += gcnew System::EventHandler(this, &MyForm::bSetPIDFactor_Click);
			// 
			// bSetFuzzyScaleXY
			// 
			this->bSetFuzzyScaleXY->Location = System::Drawing::Point(143, 6);
			this->bSetFuzzyScaleXY->Name = L"bSetFuzzyScaleXY";
			this->bSetFuzzyScaleXY->Size = System::Drawing::Size(120, 43);
			this->bSetFuzzyScaleXY->TabIndex = 40;
			this->bSetFuzzyScaleXY->Text = L"SET";
			this->bSetFuzzyScaleXY->UseVisualStyleBackColor = true;
			this->bSetFuzzyScaleXY->Click += gcnew System::EventHandler(this, &MyForm::bSetFuzzyScaleXY_Click);
			// 
			// txtScaleVel2
			// 
			this->txtScaleVel2->Location = System::Drawing::Point(190, 82);
			this->txtScaleVel2->Name = L"txtScaleVel2";
			this->txtScaleVel2->Size = System::Drawing::Size(69, 20);
			this->txtScaleVel2->TabIndex = 33;
			this->txtScaleVel2->Text = L"1";
			// 
			// txtScaleFuzzy
			// 
			this->txtScaleFuzzy->Location = System::Drawing::Point(80, 137);
			this->txtScaleFuzzy->Name = L"txtScaleFuzzy";
			this->txtScaleFuzzy->Size = System::Drawing::Size(57, 20);
			this->txtScaleFuzzy->TabIndex = 33;
			this->txtScaleFuzzy->Text = L"10000";
			// 
			// txtScaleErr2
			// 
			this->txtScaleErr2->Location = System::Drawing::Point(190, 56);
			this->txtScaleErr2->Name = L"txtScaleErr2";
			this->txtScaleErr2->Size = System::Drawing::Size(69, 20);
			this->txtScaleErr2->TabIndex = 33;
			this->txtScaleErr2->Text = L"1";
			// 
			// txtScaleOut2
			// 
			this->txtScaleOut2->Location = System::Drawing::Point(190, 108);
			this->txtScaleOut2->Name = L"txtScaleOut2";
			this->txtScaleOut2->Size = System::Drawing::Size(69, 20);
			this->txtScaleOut2->TabIndex = 33;
			this->txtScaleOut2->Text = L"10";
			// 
			// tbAngleX
			// 
			this->tbAngleX->LargeChange = 1;
			this->tbAngleX->Location = System::Drawing::Point(6, 13);
			this->tbAngleX->Minimum = -10;
			this->tbAngleX->Name = L"tbAngleX";
			this->tbAngleX->Size = System::Drawing::Size(132, 45);
			this->tbAngleX->TabIndex = 44;
			this->tbAngleX->Scroll += gcnew System::EventHandler(this, &MyForm::tbAngleX_Scroll);
			// 
			// tbAngleY
			// 
			this->tbAngleY->LargeChange = 1;
			this->tbAngleY->Location = System::Drawing::Point(144, 13);
			this->tbAngleY->Minimum = -10;
			this->tbAngleY->Name = L"tbAngleY";
			this->tbAngleY->Size = System::Drawing::Size(114, 45);
			this->tbAngleY->TabIndex = 44;
			this->tbAngleY->Scroll += gcnew System::EventHandler(this, &MyForm::tbAngleY_Scroll);
			// 
			// tabControlController
			// 
			this->tabControlController->Controls->Add(this->tabPage);
			this->tabControlController->Controls->Add(this->tabPage5);
			this->tabControlController->Controls->Add(this->tabPage1);
			this->tabControlController->Controls->Add(this->tabPage2);
			this->tabControlController->Controls->Add(this->tabPage6);
			this->tabControlController->Location = System::Drawing::Point(12, 233);
			this->tabControlController->Name = L"tabControlController";
			this->tabControlController->SelectedIndex = 0;
			this->tabControlController->Size = System::Drawing::Size(277, 237);
			this->tabControlController->TabIndex = 45;
			// 
			// tabPage
			// 
			this->tabPage->Controls->Add(this->bClearGraph);
			this->tabPage->Controls->Add(this->bSTART_GRAPH);
			this->tabPage->Controls->Add(this->bCALIB);
			this->tabPage->Controls->Add(this->bSCROLL);
			this->tabPage->Controls->Add(this->bSTART_CAM);
			this->tabPage->Controls->Add(this->cbCOMLIST);
			this->tabPage->Controls->Add(this->bShowCam);
			this->tabPage->Controls->Add(this->bCONNECT);
			this->tabPage->Controls->Add(this->txtRECEIVE);
			this->tabPage->Controls->Add(this->bSEND);
			this->tabPage->Controls->Add(this->txtSEND);
			this->tabPage->Location = System::Drawing::Point(4, 22);
			this->tabPage->Name = L"tabPage";
			this->tabPage->Padding = System::Windows::Forms::Padding(3);
			this->tabPage->Size = System::Drawing::Size(269, 211);
			this->tabPage->TabIndex = 3;
			this->tabPage->Text = L"SETTING";
			this->tabPage->UseVisualStyleBackColor = true;
			// 
			// bClearGraph
			// 
			this->bClearGraph->Location = System::Drawing::Point(144, 160);
			this->bClearGraph->Name = L"bClearGraph";
			this->bClearGraph->Size = System::Drawing::Size(119, 25);
			this->bClearGraph->TabIndex = 49;
			this->bClearGraph->Text = L"CLEAR";
			this->bClearGraph->UseVisualStyleBackColor = true;
			this->bClearGraph->Click += gcnew System::EventHandler(this, &MyForm::bClearGraph_Click);
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->label30);
			this->tabPage5->Controls->Add(this->tbAngleX);
			this->tabPage5->Controls->Add(this->label33);
			this->tabPage5->Controls->Add(this->tbAngleY);
			this->tabPage5->Controls->Add(this->label32);
			this->tabPage5->Controls->Add(this->label31);
			this->tabPage5->Controls->Add(this->txtDisplayAngle2);
			this->tabPage5->Controls->Add(this->label29);
			this->tabPage5->Controls->Add(this->txtDisplayAngle1);
			this->tabPage5->Controls->Add(this->label28);
			this->tabPage5->Controls->Add(this->txtDisplayAngle3);
			this->tabPage5->Controls->Add(this->txtDisplayAngle6);
			this->tabPage5->Controls->Add(this->txtDisplayAngle4);
			this->tabPage5->Controls->Add(this->txtDisplayAngle5);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(269, 211);
			this->tabPage5->TabIndex = 2;
			this->tabPage5->Text = L"MANUAL";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(13, 119);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(52, 13);
			this->label30->TabIndex = 49;
			this->label30->Text = L"THETA 3";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(148, 119);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(52, 13);
			this->label33->TabIndex = 49;
			this->label33->Text = L"THETA 6";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(148, 93);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(52, 13);
			this->label32->TabIndex = 49;
			this->label32->Text = L"THETA 5";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(148, 67);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(52, 13);
			this->label31->TabIndex = 49;
			this->label31->Text = L"THETA 4";
			// 
			// txtDisplayAngle2
			// 
			this->txtDisplayAngle2->Location = System::Drawing::Point(72, 90);
			this->txtDisplayAngle2->Name = L"txtDisplayAngle2";
			this->txtDisplayAngle2->Size = System::Drawing::Size(66, 20);
			this->txtDisplayAngle2->TabIndex = 0;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(13, 93);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(52, 13);
			this->label29->TabIndex = 49;
			this->label29->Text = L"THETA 2";
			// 
			// txtDisplayAngle1
			// 
			this->txtDisplayAngle1->Location = System::Drawing::Point(72, 64);
			this->txtDisplayAngle1->Name = L"txtDisplayAngle1";
			this->txtDisplayAngle1->Size = System::Drawing::Size(66, 20);
			this->txtDisplayAngle1->TabIndex = 0;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(13, 67);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(52, 13);
			this->label28->TabIndex = 49;
			this->label28->Text = L"THETA 1";
			// 
			// txtDisplayAngle3
			// 
			this->txtDisplayAngle3->Location = System::Drawing::Point(71, 116);
			this->txtDisplayAngle3->Name = L"txtDisplayAngle3";
			this->txtDisplayAngle3->Size = System::Drawing::Size(66, 20);
			this->txtDisplayAngle3->TabIndex = 0;
			// 
			// txtDisplayAngle6
			// 
			this->txtDisplayAngle6->Location = System::Drawing::Point(206, 116);
			this->txtDisplayAngle6->Name = L"txtDisplayAngle6";
			this->txtDisplayAngle6->Size = System::Drawing::Size(52, 20);
			this->txtDisplayAngle6->TabIndex = 0;
			// 
			// txtDisplayAngle4
			// 
			this->txtDisplayAngle4->Location = System::Drawing::Point(206, 64);
			this->txtDisplayAngle4->Name = L"txtDisplayAngle4";
			this->txtDisplayAngle4->Size = System::Drawing::Size(52, 20);
			this->txtDisplayAngle4->TabIndex = 0;
			// 
			// txtDisplayAngle5
			// 
			this->txtDisplayAngle5->Location = System::Drawing::Point(206, 90);
			this->txtDisplayAngle5->Name = L"txtDisplayAngle5";
			this->txtDisplayAngle5->Size = System::Drawing::Size(52, 20);
			this->txtDisplayAngle5->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label22);
			this->tabPage1->Controls->Add(this->txtScalePID);
			this->tabPage1->Controls->Add(this->bSetPIDFactor);
			this->tabPage1->Controls->Add(this->bSTART_PID);
			this->tabPage1->Controls->Add(this->txtKD2);
			this->tabPage1->Controls->Add(this->txtKP1);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->txtKI2);
			this->tabPage1->Controls->Add(this->txtKI1);
			this->tabPage1->Controls->Add(this->txtKP2);
			this->tabPage1->Controls->Add(this->txtKD1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(269, 211);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"PID";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->bSetFuzzyScaleXY);
			this->tabPage2->Controls->Add(this->bSTART_FUZZY);
			this->tabPage2->Controls->Add(this->label19);
			this->tabPage2->Controls->Add(this->label20);
			this->tabPage2->Controls->Add(this->label18);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->txtScaleOut1);
			this->tabPage2->Controls->Add(this->txtScaleVel2);
			this->tabPage2->Controls->Add(this->txtScaleOut2);
			this->tabPage2->Controls->Add(this->txtScaleVel1);
			this->tabPage2->Controls->Add(this->txtScaleFuzzy);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->txtScaleErr2);
			this->tabPage2->Controls->Add(this->txtScaleErr1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(269, 211);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"FUZZY";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->groupBox2);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(269, 211);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"TRACKING";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label35);
			this->groupBox2->Controls->Add(this->txtSpeedChangePoint);
			this->groupBox2->Controls->Add(this->txtNumOfPoint);
			this->groupBox2->Controls->Add(this->txtRadiusCircle);
			this->groupBox2->Controls->Add(this->txtCenterCircleY);
			this->groupBox2->Controls->Add(this->bSTART_TRACK);
			this->groupBox2->Controls->Add(this->txtCenterCircleX);
			this->groupBox2->Controls->Add(this->txtSetSPY);
			this->groupBox2->Controls->Add(this->txtSetSPX);
			this->groupBox2->Controls->Add(this->bImportTrajectory);
			this->groupBox2->Controls->Add(this->bSETBALL);
			this->groupBox2->Controls->Add(this->radioOther);
			this->groupBox2->Controls->Add(this->radioCircle);
			this->groupBox2->Controls->Add(this->radioPoint);
			this->groupBox2->Location = System::Drawing::Point(6, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(256, 198);
			this->groupBox2->TabIndex = 49;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"TRAJECTORY";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(34, 113);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(83, 13);
			this->label4->TabIndex = 53;
			this->label4->Text = L"NO OF POINTS";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 139);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 13);
			this->label2->TabIndex = 53;
			this->label2->Text = L"SPEED OF MOVE";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(71, 56);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(170, 13);
			this->label35->TabIndex = 53;
			this->label35->Text = L"OFFSET POINT       -       RADIUS";
			// 
			// txtSpeedChangePoint
			// 
			this->txtSpeedChangePoint->Location = System::Drawing::Point(137, 136);
			this->txtSpeedChangePoint->Name = L"txtSpeedChangePoint";
			this->txtSpeedChangePoint->Size = System::Drawing::Size(113, 20);
			this->txtSpeedChangePoint->TabIndex = 53;
			// 
			// txtNumOfPoint
			// 
			this->txtNumOfPoint->Location = System::Drawing::Point(137, 110);
			this->txtNumOfPoint->Name = L"txtNumOfPoint";
			this->txtNumOfPoint->Size = System::Drawing::Size(49, 20);
			this->txtNumOfPoint->TabIndex = 52;
			// 
			// txtRadiusCircle
			// 
			this->txtRadiusCircle->Location = System::Drawing::Point(192, 72);
			this->txtRadiusCircle->Name = L"txtRadiusCircle";
			this->txtRadiusCircle->Size = System::Drawing::Size(45, 20);
			this->txtRadiusCircle->TabIndex = 50;
			// 
			// txtCenterCircleY
			// 
			this->txtCenterCircleY->Location = System::Drawing::Point(123, 72);
			this->txtCenterCircleY->Name = L"txtCenterCircleY";
			this->txtCenterCircleY->Size = System::Drawing::Size(45, 20);
			this->txtCenterCircleY->TabIndex = 50;
			// 
			// bSTART_TRACK
			// 
			this->bSTART_TRACK->Location = System::Drawing::Point(12, 161);
			this->bSTART_TRACK->Name = L"bSTART_TRACK";
			this->bSTART_TRACK->Size = System::Drawing::Size(119, 29);
			this->bSTART_TRACK->TabIndex = 52;
			this->bSTART_TRACK->Text = L"START TRACK";
			this->bSTART_TRACK->UseVisualStyleBackColor = true;
			this->bSTART_TRACK->Click += gcnew System::EventHandler(this, &MyForm::bSTART_TRACK_Click);
			// 
			// txtCenterCircleX
			// 
			this->txtCenterCircleX->Location = System::Drawing::Point(74, 72);
			this->txtCenterCircleX->Name = L"txtCenterCircleX";
			this->txtCenterCircleX->Size = System::Drawing::Size(43, 20);
			this->txtCenterCircleX->TabIndex = 49;
			// 
			// txtSetSPY
			// 
			this->txtSetSPY->Location = System::Drawing::Point(123, 19);
			this->txtSetSPY->Name = L"txtSetSPY";
			this->txtSetSPY->Size = System::Drawing::Size(45, 20);
			this->txtSetSPY->TabIndex = 50;
			// 
			// txtSetSPX
			// 
			this->txtSetSPX->Location = System::Drawing::Point(74, 19);
			this->txtSetSPX->Name = L"txtSetSPX";
			this->txtSetSPX->Size = System::Drawing::Size(43, 20);
			this->txtSetSPX->TabIndex = 49;
			// 
			// bImportTrajectory
			// 
			this->bImportTrajectory->Location = System::Drawing::Point(192, 109);
			this->bImportTrajectory->Name = L"bImportTrajectory";
			this->bImportTrajectory->Size = System::Drawing::Size(58, 21);
			this->bImportTrajectory->TabIndex = 51;
			this->bImportTrajectory->Text = L"IMPORT";
			this->bImportTrajectory->UseVisualStyleBackColor = true;
			this->bImportTrajectory->Click += gcnew System::EventHandler(this, &MyForm::bImportTrajectory_Click);
			// 
			// bSETBALL
			// 
			this->bSETBALL->Location = System::Drawing::Point(137, 161);
			this->bSETBALL->Name = L"bSETBALL";
			this->bSETBALL->Size = System::Drawing::Size(113, 29);
			this->bSETBALL->TabIndex = 48;
			this->bSETBALL->Text = L"SET";
			this->bSETBALL->UseVisualStyleBackColor = true;
			this->bSETBALL->Click += gcnew System::EventHandler(this, &MyForm::bSETBALL_Click);
			// 
			// radioOther
			// 
			this->radioOther->AutoSize = true;
			this->radioOther->Checked = true;
			this->radioOther->Location = System::Drawing::Point(13, 93);
			this->radioOther->Name = L"radioOther";
			this->radioOther->Size = System::Drawing::Size(51, 17);
			this->radioOther->TabIndex = 47;
			this->radioOther->TabStop = true;
			this->radioOther->Text = L"Other";
			this->radioOther->UseVisualStyleBackColor = true;
			this->radioOther->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioOther_CheckedChanged);
			// 
			// radioCircle
			// 
			this->radioCircle->AutoSize = true;
			this->radioCircle->Location = System::Drawing::Point(13, 42);
			this->radioCircle->Name = L"radioCircle";
			this->radioCircle->Size = System::Drawing::Size(51, 17);
			this->radioCircle->TabIndex = 47;
			this->radioCircle->Text = L"Circle";
			this->radioCircle->UseVisualStyleBackColor = true;
			this->radioCircle->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioCircle_CheckedChanged);
			// 
			// radioPoint
			// 
			this->radioPoint->AutoSize = true;
			this->radioPoint->Location = System::Drawing::Point(13, 19);
			this->radioPoint->Name = L"radioPoint";
			this->radioPoint->Size = System::Drawing::Size(49, 17);
			this->radioPoint->TabIndex = 47;
			this->radioPoint->Text = L"Point";
			this->radioPoint->UseVisualStyleBackColor = true;
			this->radioPoint->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// tabPageMOREGRAPH
			// 
			this->tabPageMOREGRAPH->Controls->Add(this->zedGraphMore);
			this->tabPageMOREGRAPH->Location = System::Drawing::Point(4, 22);
			this->tabPageMOREGRAPH->Name = L"tabPageMOREGRAPH";
			this->tabPageMOREGRAPH->Padding = System::Windows::Forms::Padding(3);
			this->tabPageMOREGRAPH->Size = System::Drawing::Size(637, 654);
			this->tabPageMOREGRAPH->TabIndex = 2;
			this->tabPageMOREGRAPH->Text = L"MORE GRAPH";
			this->tabPageMOREGRAPH->UseVisualStyleBackColor = true;
			// 
			// zedGraphMore
			// 
			this->zedGraphMore->Location = System::Drawing::Point(6, 6);
			this->zedGraphMore->Name = L"zedGraphMore";
			this->zedGraphMore->ScrollGrace = 0;
			this->zedGraphMore->ScrollMaxX = 0;
			this->zedGraphMore->ScrollMaxY = 0;
			this->zedGraphMore->ScrollMaxY2 = 0;
			this->zedGraphMore->ScrollMinX = 0;
			this->zedGraphMore->ScrollMinY = 0;
			this->zedGraphMore->ScrollMinY2 = 0;
			this->zedGraphMore->Size = System::Drawing::Size(625, 630);
			this->zedGraphMore->TabIndex = 0;
			// 
			// tabPageTIMEGRAPH
			// 
			this->tabPageTIMEGRAPH->Controls->Add(this->zedGraphTime);
			this->tabPageTIMEGRAPH->Location = System::Drawing::Point(4, 22);
			this->tabPageTIMEGRAPH->Name = L"tabPageTIMEGRAPH";
			this->tabPageTIMEGRAPH->Padding = System::Windows::Forms::Padding(3);
			this->tabPageTIMEGRAPH->Size = System::Drawing::Size(637, 654);
			this->tabPageTIMEGRAPH->TabIndex = 1;
			this->tabPageTIMEGRAPH->Text = L"TIME GRAPH";
			this->tabPageTIMEGRAPH->UseVisualStyleBackColor = true;
			// 
			// zedGraphTime
			// 
			this->zedGraphTime->Location = System::Drawing::Point(6, 6);
			this->zedGraphTime->Name = L"zedGraphTime";
			this->zedGraphTime->ScrollGrace = 0;
			this->zedGraphTime->ScrollMaxX = 0;
			this->zedGraphTime->ScrollMaxY = 0;
			this->zedGraphTime->ScrollMaxY2 = 0;
			this->zedGraphTime->ScrollMinX = 0;
			this->zedGraphTime->ScrollMinY = 0;
			this->zedGraphTime->ScrollMinY2 = 0;
			this->zedGraphTime->Size = System::Drawing::Size(625, 637);
			this->zedGraphTime->TabIndex = 0;
			// 
			// tabPageXYGRAPH
			// 
			this->tabPageXYGRAPH->Controls->Add(this->zedGraphXY);
			this->tabPageXYGRAPH->Location = System::Drawing::Point(4, 22);
			this->tabPageXYGRAPH->Name = L"tabPageXYGRAPH";
			this->tabPageXYGRAPH->Padding = System::Windows::Forms::Padding(3);
			this->tabPageXYGRAPH->Size = System::Drawing::Size(637, 654);
			this->tabPageXYGRAPH->TabIndex = 0;
			this->tabPageXYGRAPH->Text = L"XY GRAPH";
			this->tabPageXYGRAPH->UseVisualStyleBackColor = true;
			// 
			// zedGraphXY
			// 
			this->zedGraphXY->Location = System::Drawing::Point(11, 9);
			this->zedGraphXY->Name = L"zedGraphXY";
			this->zedGraphXY->ScrollGrace = 0;
			this->zedGraphXY->ScrollMaxX = 0;
			this->zedGraphXY->ScrollMaxY = 0;
			this->zedGraphXY->ScrollMaxY2 = 0;
			this->zedGraphXY->ScrollMinX = 0;
			this->zedGraphXY->ScrollMinY = 0;
			this->zedGraphXY->ScrollMinY2 = 0;
			this->zedGraphXY->Size = System::Drawing::Size(610, 627);
			this->zedGraphXY->TabIndex = 5;
			// 
			// tabControlGraph
			// 
			this->tabControlGraph->Controls->Add(this->tabPageXYGRAPH);
			this->tabControlGraph->Controls->Add(this->tabPageTIMEGRAPH);
			this->tabControlGraph->Controls->Add(this->tabPageMOREGRAPH);
			this->tabControlGraph->Location = System::Drawing::Point(295, 12);
			this->tabControlGraph->Name = L"tabControlGraph";
			this->tabControlGraph->SelectedIndex = 0;
			this->tabControlGraph->Size = System::Drawing::Size(645, 680);
			this->tabControlGraph->TabIndex = 46;
			// 
			// timerTracking
			// 
			this->timerTracking->Interval = 1000;
			this->timerTracking->Tick += gcnew System::EventHandler(this, &MyForm::timerTracking_Tick);
			// 
			// timerCamera
			// 
			this->timerCamera->Tick += gcnew System::EventHandler(this, &MyForm::timerCamera_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(277, 215);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 47;
			this->pictureBox1->TabStop = false;
			// 
			// txtScalePID
			// 
			this->txtScalePID->Location = System::Drawing::Point(59, 137);
			this->txtScalePID->Name = L"txtScalePID";
			this->txtScalePID->Size = System::Drawing::Size(67, 20);
			this->txtScalePID->TabIndex = 38;
			this->txtScalePID->Text = L"10000";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(143, 88);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(27, 13);
			this->label10->TabIndex = 34;
			this->label10->Text = L"KdY";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(143, 59);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(27, 13);
			this->label11->TabIndex = 34;
			this->label11->Text = L"KpY";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(143, 111);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(27, 13);
			this->label19->TabIndex = 34;
			this->label19->Text = L"KuY";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(19, 140);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(61, 13);
			this->label20->TabIndex = 34;
			this->label20->Text = L"Scale Input";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(19, 140);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(34, 13);
			this->label22->TabIndex = 39;
			this->label22->Text = L"Scale";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(949, 712);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->tabControlGraph);
			this->Controls->Add(this->tabControlController);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"  ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAngleX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbAngleY))->EndInit();
			this->tabControlController->ResumeLayout(false);
			this->tabPage->ResumeLayout(false);
			this->tabPage->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabPageMOREGRAPH->ResumeLayout(false);
			this->tabPageTIMEGRAPH->ResumeLayout(false);
			this->tabPageXYGRAPH->ResumeLayout(false);
			this->tabControlGraph->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		//===============================================
		//=====DEFINE====================================

		// First, clear out any old GraphPane's from the MasterPane collection
		MasterPane^ masterXY = gcnew MasterPane();
		MasterPane^ masterMore = gcnew MasterPane();
		MasterPane^ masterTime = gcnew MasterPane();
		// Add all the GraphPanes to the MasterPane

		GraphPane^ myPaneXY = gcnew GraphPane();
		GraphPane^ myPaneX = gcnew GraphPane();
		GraphPane^ myPaneY = gcnew GraphPane();
		GraphPane^ myPaneEX = gcnew GraphPane();
		GraphPane^ myPaneEY = gcnew GraphPane();
		GraphPane^ myPaneDEX = gcnew GraphPane();
		GraphPane^ myPaneDEY = gcnew GraphPane();
		GraphPane^ myPaneUX = gcnew GraphPane();
		GraphPane^ myPaneUY = gcnew GraphPane();

		PointPairList^ PosXList = gcnew PointPairList();
		PointPairList^ PosYList = gcnew PointPairList();
		PointPairList^ PosXYList = gcnew PointPairList();
		PointPairList^ PosEXList = gcnew PointPairList();
		PointPairList^ PosEYList = gcnew PointPairList();
		PointPairList^ PosDEXList = gcnew PointPairList();
		PointPairList^ PosDEYList = gcnew PointPairList();
		PointPairList^ PosUXList = gcnew PointPairList();
		PointPairList^ PosUYList = gcnew PointPairList();
		
		PointPairList^ PosXSetpointList = gcnew PointPairList();
		PointPairList^ PosYSetpointList = gcnew PointPairList();
		PointPairList^ PosXYSetpointList = gcnew PointPairList();
		PointPairList^ PosTrajectoryList = gcnew PointPairList();

		LineItem^ PosXCurve;
		LineItem^ PosYCurve;
		LineItem^ PosXYCurve;
		LineItem^ PosEXCurve;
		LineItem^ PosEYCurve;
		LineItem^ PosDEXCurve;
		LineItem^ PosDEYCurve;
		LineItem^ PosUXCurve;
		LineItem^ PosUYCurve;

		LineItem^ PosXSetpointCurve;
		LineItem^ PosYSetpointCurve;
		LineItem^ PosXYSetpointCurve;
		LineItem^ PosTrajectoryCurve;


	private:
		double posX = 0;
		double posY = 0;
		double errX = 0;
		double errY = 0;
		double pre_errX = 0;
		double pre_errY = 0;
		double velX = 0;
		double velY = 0;
		double angleX = 0;
		double angleY = 0;
		int timeGraph = 0;
		double setpointX = 0;
		double setpointY = 0;
		double scale_errX = 1;
		double scale_errY = 1;
		double scale_velX = 1;
		double scale_velY = 1;
		double scale_outX = 1;
		double scale_outY = 1;
		double KpX = 0;
		double KiX = 0;
		double KdX = 0;
		double KpY = 0;
		double KiY = 0;
		double KdY = 0;
		int processTime = 0;
		int samplingRate = 1;
		int maxTimeDisplay = 500;
		int maxTimeCount = 2000;
		double scale_input = 10000;
		//string data_in_file[2] = { "aaasdaa","aaa" };
		//List<String^>^ dinosaurs = gcnew List<String^>();

		const float  PI_F = 3.14f;
		int numOfPoint = 0;
		int speedChangePoint = 1000;
		int circleOffsetX = 0;
		int circleOffsetY = 0;
		int circleRadius = 0;
		List<int>^ trajectoryData1 = gcnew List<int>();
		List<int>^ trajectoryData2 = gcnew List<int>();
		int mode = 0; // 0 : none, 1 : PID, 2 : Fuzzy, 3 : Mannual
		//===============================================
		//=======CODE START HERE=========================
#pragma region Declare function 
	private: void findPorts(void)
	{
		// get port names
		array<Object^>^ objectArray = serialPort->GetPortNames();
		// add string array to combobox
		if (objectArray->Length > 0)
		{
			cbCOMLIST->Items->Clear();
			cbCOMLIST->Items->AddRange(objectArray);
			cbCOMLIST->SelectedIndex = 0;
		}
		
	}
	
#pragma endregion

#pragma region PLOTTING GRAPH

	private: void initGraph(void)
	{
		masterXY = zedGraphXY->MasterPane;
		masterTime = zedGraphTime->MasterPane;
		masterMore = zedGraphMore->MasterPane;
		masterXY->PaneList->Clear();
		masterTime->PaneList->Clear();
		masterMore->PaneList->Clear();


		masterXY->Add(myPaneXY);
		masterTime->Add(myPaneX);
		masterTime->Add(myPaneY);
		masterMore->Add(myPaneEX);
		masterMore->Add(myPaneEY);
		masterMore->Add(myPaneDEX);
		masterMore->Add(myPaneDEY);
		masterMore->Add(myPaneUX);
		masterMore->Add(myPaneUY);

		// Refigure the axis ranges for the GraphPanes
		zedGraphXY->AxisChange();
		zedGraphTime->AxisChange();
		zedGraphMore->AxisChange();

		Graphics^ g = this->CreateGraphics();
		masterXY->SetLayout(g, PaneLayout::SquareRowPreferred);
		masterTime->SetLayout(g, PaneLayout::SquareRowPreferred);
		masterMore->SetLayout(g, PaneLayout::SquareRowPreferred);
		//==================================================

		initScale();
	}
	private: void initScale(void) {
		//==================================================
		myPaneXY->Title->Text = "X-Y GRAPH";
		myPaneXY->Title->FontSpec->Size = 25;
		myPaneXY->Title->IsVisible = true;
		myPaneXY->XAxis->Title->Text = "X";
		myPaneXY->YAxis->Title->Text = "Y";
		myPaneXY->XAxis->Title->FontSpec->Size = 25;
		myPaneXY->YAxis->Title->FontSpec->Size = 25;
		myPaneXY->XAxis->Scale->FontSpec->Size = 25;
		myPaneXY->YAxis->Scale->FontSpec->Size = 25;
		myPaneXY->YAxis->Scale->Max = 400;
		myPaneXY->YAxis->Scale->Min = 0;
		myPaneXY->XAxis->Scale->Max = 400;
		myPaneXY->XAxis->Scale->Min = 0;
		myPaneXY->XAxis->Scale->FontSpec->Size = 25;
		myPaneXY->YAxis->Scale->FontSpec->Size = 25;

		myPaneX->Title->Text = "X-TIME GRAPH";
		myPaneX->Title->FontSpec->Size = 25;
		myPaneX->Title->IsVisible = true;
		myPaneX->XAxis->Title->Text = "TIME";
		myPaneX->YAxis->Title->Text = "X";
		myPaneX->XAxis->Title->FontSpec->Size = 25;
		myPaneX->YAxis->Title->FontSpec->Size = 25;
		myPaneX->XAxis->Scale->FontSpec->Size = 25;
		myPaneX->YAxis->Scale->FontSpec->Size = 25;
		myPaneX->YAxis->Scale->Max = 400;
		myPaneX->YAxis->Scale->Min = 0;
		myPaneX->XAxis->Scale->Max = maxTimeDisplay;
		myPaneX->XAxis->Scale->Min = 0;
		myPaneX->XAxis->Scale->FontSpec->Size = 25;
		myPaneX->YAxis->Scale->FontSpec->Size = 25;

		myPaneY->Title->Text = "Y-TIME GRAPH";
		myPaneY->Title->FontSpec->Size = 25;
		myPaneY->Title->IsVisible = true;
		myPaneY->XAxis->Title->Text = "TIME";
		myPaneY->YAxis->Title->Text = "Y";
		myPaneY->XAxis->Title->FontSpec->Size = 25;
		myPaneY->YAxis->Title->FontSpec->Size = 25;
		myPaneY->XAxis->Scale->FontSpec->Size = 25;
		myPaneY->YAxis->Scale->FontSpec->Size = 25;
		myPaneY->YAxis->Scale->Max = 400;
		myPaneY->YAxis->Scale->Min = 0;
		myPaneY->XAxis->Scale->Max = maxTimeDisplay;
		myPaneY->XAxis->Scale->Min = 0;
		myPaneY->XAxis->Scale->FontSpec->Size = 25;
		myPaneY->YAxis->Scale->FontSpec->Size = 25;

		myPaneEX->Title->Text = "EX-TIME GRAPH";
		myPaneEX->Title->FontSpec->Size = 25;
		myPaneEX->Title->IsVisible = true;
		myPaneEX->XAxis->Title->Text = "TIME";
		myPaneEX->YAxis->Title->Text = "EX";
		myPaneEX->XAxis->Title->FontSpec->Size = 25;
		myPaneEX->YAxis->Title->FontSpec->Size = 25;
		myPaneEX->XAxis->Scale->FontSpec->Size = 25;
		myPaneEX->YAxis->Scale->FontSpec->Size = 25;

		myPaneEY->Title->Text = "EY-TIME GRAPH";
		myPaneEY->Title->FontSpec->Size = 25;
		myPaneEY->Title->IsVisible = true;
		myPaneEY->XAxis->Title->Text = "TIME";
		myPaneEY->YAxis->Title->Text = "EY";
		myPaneEY->XAxis->Title->FontSpec->Size = 25;
		myPaneEY->YAxis->Title->FontSpec->Size = 25;
		myPaneEY->XAxis->Scale->FontSpec->Size = 25;
		myPaneEY->YAxis->Scale->FontSpec->Size = 25;

		myPaneDEX->Title->Text = "DEX-TIME GRAPH";
		myPaneDEX->Title->FontSpec->Size = 25;
		myPaneDEX->Title->IsVisible = true;
		myPaneDEX->XAxis->Title->Text = "TIME";
		myPaneDEX->YAxis->Title->Text = "DEX";
		myPaneDEX->XAxis->Title->FontSpec->Size = 25;
		myPaneDEX->YAxis->Title->FontSpec->Size = 25;
		myPaneDEX->XAxis->Scale->FontSpec->Size = 25;
		myPaneDEX->YAxis->Scale->FontSpec->Size = 25;

		myPaneDEY->Title->Text = "DEY-TIME GRAPH";
		myPaneDEY->Title->FontSpec->Size = 25;
		myPaneDEY->Title->IsVisible = true;
		myPaneDEY->XAxis->Title->Text = "TIME";
		myPaneDEY->YAxis->Title->Text = "DEY";
		myPaneDEY->XAxis->Title->FontSpec->Size = 25;
		myPaneDEY->YAxis->Title->FontSpec->Size = 25;
		myPaneDEY->XAxis->Scale->FontSpec->Size = 25;
		myPaneDEY->YAxis->Scale->FontSpec->Size = 25;

		myPaneUX->Title->Text = "UX-TIME GRAPH";
		myPaneUX->Title->FontSpec->Size = 25;
		myPaneUX->Title->IsVisible = true;
		myPaneUX->XAxis->Title->Text = "TIME";
		myPaneUX->YAxis->Title->Text = "UX";
		myPaneUX->XAxis->Title->FontSpec->Size = 25;
		myPaneUX->YAxis->Title->FontSpec->Size = 25;
		myPaneUX->XAxis->Scale->FontSpec->Size = 25;
		myPaneUX->YAxis->Scale->FontSpec->Size = 25;
		myPaneUX->YAxis->Scale->Max = 10;
		myPaneUX->YAxis->Scale->Min = -10;
		myPaneUX->XAxis->Scale->Max = maxTimeDisplay;
		myPaneUX->XAxis->Scale->Min = 0;
		myPaneUX->XAxis->Scale->FontSpec->Size = 25;
		myPaneUX->YAxis->Scale->FontSpec->Size = 25;

		myPaneUY->Title->Text = "UY-TIME GRAPH";
		myPaneUY->Title->FontSpec->Size = 25;
		myPaneUY->Title->IsVisible = true;
		myPaneUY->XAxis->Title->Text = "TIME";
		myPaneUY->YAxis->Title->Text = "UY";
		myPaneUY->XAxis->Title->FontSpec->Size = 25;
		myPaneUY->YAxis->Title->FontSpec->Size = 25;
		myPaneUY->YAxis->Scale->Max = 10;
		myPaneUY->YAxis->Scale->Min = -10;
		myPaneUY->XAxis->Scale->Max = maxTimeDisplay;
		myPaneUY->XAxis->Scale->Min = 0;
		myPaneUY->XAxis->Scale->FontSpec->Size = 25;
		myPaneUY->YAxis->Scale->FontSpec->Size = 25;
		//==================================================
		//====================================================

		zedGraphXY->AxisChange();
		zedGraphTime->AxisChange();
		zedGraphMore->AxisChange();
	}
	private: void updateGraph(void)
	{
//		zedGraphXY->Refresh();
		zedGraphTime->Refresh();
		zedGraphMore->Refresh();
	}
	private: void drawXY(double x, double y)
	{
		myPaneXY->CurveList->Clear();
		if (bSCROLL->Text == "SLIDE" || timeGraph*10>=maxTimeCount)
		{
			PosXYList->Clear();
		}
		PosXYList->Add(x, y);
			
		PosXYSetpointList->Clear();
		PosXYSetpointList->Add(setpointX, setpointY);

		PosXYCurve = myPaneXY->AddCurve("Ball Position", PosXYList, Color::Red, SymbolType::Square);
		PosXYSetpointCurve = myPaneXY->AddCurve("Set point", PosXYSetpointList, Color::Blue, SymbolType::Square);
		if (numOfPoint != 0)
		{
			PosTrajectoryCurve = myPaneXY->AddCurve("Trajectory", PosTrajectoryList, Color::Blue, SymbolType::None);
		}
		//zedGraphXY->AxisChange();
		//zedGraphXY->Invalidate();
		zedGraphXY->Refresh();
	}
	private: void drawXYT(double x, double y)
	{
		myPaneX->CurveList->Clear();
		myPaneY->CurveList->Clear();
		if (timeGraph > myPaneX->XAxis->Scale->Max - 1)
		{
			if (bSCROLL->Text == "BLOCK")
			{
				myPaneX->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max + 1;
				myPaneX->XAxis->Scale->Min = myPaneX->XAxis->Scale->Max - maxTimeDisplay;
				myPaneY->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max;
				myPaneY->XAxis->Scale->Min = myPaneX->XAxis->Scale->Min;
			}
			else
			{
				myPaneX->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max + 1;
				myPaneX->XAxis->Scale->Min = 0;
				myPaneY->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max;
				myPaneY->XAxis->Scale->Min = myPaneX->XAxis->Scale->Min;
			}
		}
		PosXList->Add(timeGraph, x);
		PosYList->Add(timeGraph, y);

		PosXSetpointList->Add(timeGraph, setpointX);
		PosYSetpointList->Add(timeGraph, setpointY);

		PosXCurve = myPaneX->AddCurve("Pos X", PosXList, Color::Red, SymbolType::None);
		PosXSetpointCurve = myPaneX->AddCurve("Pos Set point X", PosXSetpointList, Color::Blue, SymbolType::None);

		PosYCurve = myPaneY->AddCurve("Pos Y", PosYList, Color::Red, SymbolType::None);
		PosYSetpointCurve = myPaneY->AddCurve("Pos Set point Y", PosYSetpointList, Color::Blue, SymbolType::None);

		//if (timeGraph >= maxTimeCount)
		//{
		//	PosXList->Clear();
		//	PosYList->Clear();
		//	PosXSetpointList->Clear();
		//	PosYSetpointList->Clear();
		//}
		//timeGraph++;

		//zedGraphTime->AxisChange();
		//zedGraphTime->Invalidate();
//		zedGraphTime->Refresh();
	}
	private: void drawMORE(double ex, double ey, double dex, double dey, double ux, double uy)
	{
		myPaneEX->CurveList->Clear();
		myPaneEY->CurveList->Clear();
		myPaneDEX->CurveList->Clear();
		myPaneDEY->CurveList->Clear();
		myPaneUX->CurveList->Clear();
		myPaneUY->CurveList->Clear();

		myPaneEX->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max;
		myPaneEX->XAxis->Scale->Min = myPaneX->XAxis->Scale->Min;
		myPaneEY->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max;
		myPaneEY->XAxis->Scale->Min = myPaneX->XAxis->Scale->Min;
		myPaneDEX->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max;
		myPaneDEX->XAxis->Scale->Min = myPaneX->XAxis->Scale->Min;
		myPaneDEY->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max;
		myPaneDEY->XAxis->Scale->Min = myPaneX->XAxis->Scale->Min;
		myPaneUX->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max;
		myPaneUX->XAxis->Scale->Min = myPaneX->XAxis->Scale->Min;
		myPaneUY->XAxis->Scale->Max = myPaneX->XAxis->Scale->Max;
		myPaneUY->XAxis->Scale->Min = myPaneX->XAxis->Scale->Min;



		PosEXList->Add(timeGraph, ex);
		PosEYList->Add(timeGraph, ey);
		PosDEXList->Add(timeGraph, dex);
		PosDEYList->Add(timeGraph, dey);
		PosUXList->Add(timeGraph, ux);
		PosUYList->Add(timeGraph, uy);

		PosEXCurve = myPaneEX->AddCurve("Pos EX", PosEXList, Color::Red, SymbolType::None);
		PosEYCurve = myPaneEY->AddCurve("Pos EY", PosEYList, Color::Red, SymbolType::None);
		PosDEXCurve = myPaneDEX->AddCurve("Pos DEX", PosDEXList, Color::Red, SymbolType::None);
		PosDEYCurve = myPaneDEY->AddCurve("Pos DEY", PosDEYList, Color::Red, SymbolType::None);
		PosUXCurve = myPaneUX->AddCurve("Pos UX", PosUXList, Color::Red, SymbolType::None);
		PosUYCurve = myPaneUY->AddCurve("Pos UY", PosUYList, Color::Red, SymbolType::None);


		//if (timeGraph >= maxTimeCount)
		//{
		//	//timeGraph = 0;
		//	PosEXList->Clear();
		//	PosEYList->Clear();
		//	PosDEXList->Clear();
		//	PosDEYList->Clear();
		//	PosUXList->Clear();
		//	PosUYList->Clear();
		//}


		//timeGraph++;
		zedGraphMore->AxisChange();
//		zedGraphMore->Invalidate();
//		zedGraphMore->Refresh();
	}
	private: void clearGraph(void)
	{
		myPaneXY->CurveList->Clear();
		PosXYList->Clear();
		PosXYSetpointList->Clear();
		PosTrajectoryList->Clear();

		myPaneX->CurveList->Clear();
		myPaneY->CurveList->Clear();
		PosXList->Clear();
		PosYList->Clear();
		PosXSetpointList->Clear();
		PosYSetpointList->Clear();

		myPaneEX->CurveList->Clear();
		myPaneEY->CurveList->Clear();
		myPaneDEX->CurveList->Clear();
		myPaneDEY->CurveList->Clear();
		myPaneUX->CurveList->Clear();
		myPaneUY->CurveList->Clear();

		PosEXList->Clear();
		PosEYList->Clear();
		PosDEXList->Clear();
		PosDEYList->Clear();
		PosUXList->Clear();
		PosUYList->Clear();

		timeGraph = 0;
	}
	private: void initTrajectory(void)
	{
		PosTrajectoryList->Clear();
		for (int i = 0; i < numOfPoint; i++) 
		{
			PosTrajectoryList->Add(trajectoryData1[i], trajectoryData2[i]);
		}
		PosTrajectoryList->Add(trajectoryData1[0], trajectoryData2[0]);
		
	}
#pragma endregion
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		findPorts();
		initGraph();
		
		camera.setSize(640, 480);
		camera.setHSVParam(0, 84, 100, 255, 153, 255);
		camera.setCropFrame(118, 16, 400, 400);
		camera.applyCropFrame();
		timerCamera->Interval = 1;
		timerUART_Send->Interval = 1;
		timerUART_Receive->Interval = 1;
		txtSamplingRate->Text = "15";
//		Init_Fuzzy();

		radioPoint->Checked = true;
		if (radioPoint->Checked == true)
		{
			txtSetSPX->Enabled = true;
			txtSetSPY->Enabled = true;

			txtCenterCircleX->Enabled = false;
			txtCenterCircleY->Enabled = false;
			txtRadiusCircle->Enabled = false;

			txtNumOfPoint->Enabled = false;
			bImportTrajectory->Enabled = false;
			txtSpeedChangePoint->Enabled = false;

			bSTART_TRACK->Enabled = false;
		}
	}

private: System::Void txtSEND_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (txtSEND->Text != "" && serialPort->IsOpen == true)
	{
		serialPort->Write(txtSEND->Text);
	}
}

private: System::Void tbAngleX_Scroll(System::Object^  sender, System::EventArgs^  e) {
	mode = 3;
	bSTART_FUZZY->Text = "START FUZZY";
	bSTART_PID->Text = "START PID";
	angleX = tbAngleX->Value;
}

private: System::Void tbAngleY_Scroll(System::Object^  sender, System::EventArgs^  e) {
	mode = 3;
	bSTART_FUZZY->Text = "START FUZZY";
	bSTART_PID->Text = "START PID";
	angleY = tbAngleY->Value;
}


#pragma region timer_event
private: System::Void timerCamera_Tick(System::Object^  sender, System::EventArgs^  e) {
			 camera.getFPS_start();
			 camera.getFrame();
			 camera.detectBall();

			 posX = camera.getX();
			 posY = camera.getY();

			 //errX = setpointX - posX;
			 //errY = setpointY - posY;

			 //velX = (errX - pre_errX) * 1000 / samplingRate;
			 //velY = (errY - pre_errY) * 1000 / samplingRate;

			 //pre_errX = errX;
			 //pre_errY = errY;

			 //if (bSTART_PID->Text == "STOP PID" && bSTART_FUZZY->Text == "START FUZZY")
			 //{
				// pidX.setPIDPeriod(1000 / samplingRate);
				// pidX.setPIDOutputLimit(-10, 10);
				// pidX.setPIDParam(System::Convert::ToDouble(txtKP1->Text), System::Convert::ToDouble(txtKI1->Text), System::Convert::ToDouble(txtKD1->Text), 0.01);
				// pidX.compute(errX);

				// pidY.setPIDPeriod(1000 / samplingRate);
				// pidY.setPIDOutputLimit(-10, 10);
				// pidY.setPIDParam(System::Convert::ToDouble(txtKP2->Text), System::Convert::ToDouble(txtKI2->Text), System::Convert::ToDouble(txtKD2->Text), 0.01);
				// pidY.compute(errY);

				// txtANGLE_X->Text = ((int)pidX.getOutput(0)).ToString();
				// txtANGLE_Y->Text = (-(int)pidY.getOutput(0)).ToString();
			 //}
			 //if (bSTART_PID->Text == "START PID" && bSTART_FUZZY->Text == "STOP FUZZY")
			 //{
				// angleX = Fuzzy_OutPut((float)errX, (float)velX, (float)scale_errX, (float)scale_velX, (float)scale_outX, -10, 10);
				// angleY = (-Fuzzy_OutPut((float)errY, (float)velY, (float)scale_errY, (float)scale_velY, (float)scale_outY, -10, 10));
				// //txtANGLE_X->Text = Fuzzy_OutPut((float)200, (float)200, (float)scale_errX, (float)scale_velX, (float)scale_outX, -10, 10).ToString();
				// //txtANGLE_Y->Text = (-Fuzzy_OutPut((float)200, (float)200, (float)scale_errY, (float)scale_velY, (float)scale_outY, -10, 10)).ToString();
			 //}
			 if (bShowCam->Text == "UNSHOW CAM")
			 {
				 camera.showCamera(2);
			 }
			 
			 txtSetpointX->Text = setpointX.ToString();
			 txtSetpointY->Text = setpointY.ToString();
			 txtPosX->Text = posX.ToString();
			 txtPosY->Text = posY.ToString();
			 txtErrX->Text = errX.ToString();
			 txtErrY->Text = errY.ToString();
			 txtPosX->Text = posX.ToString();
			 txtPosY->Text = posY.ToString();
			 txtDErrX->Text = ((int)velX).ToString();
			 txtDErrY->Text = ((int)velY).ToString();
			 txtANGLE_X->Text = angleX.ToString();
			 txtANGLE_Y->Text = angleY.ToString();
			
			
			 if (bSTART_GRAPH->Text == "STOP GRAPH")
			 {
				 drawXY(posX, posY);
				 drawXYT(posX, posY);
				 drawMORE(errX, errY, velX, velY, angleX, angleY);
				 timeGraph++;
				 if (txtSamplingRate->Text != "" && System::Convert::ToInt32(txtSamplingRate->Text) != 0)
				 {
					 samplingRate = System::Convert::ToInt32(txtSamplingRate->Text);
				 }
				 else
				 {
					 samplingRate = 1;
				 }
				 if ((int)(timeGraph) % samplingRate == 0)
				 {
					 updateGraph();
				 }
				 if (timeGraph > maxTimeCount)
				 {
					 timeGraph = 0;
					 clearGraph();
				 }
			 }

			 camera.getFPS_end();
			 processTime = ((int)(1000 / camera.fps_));
			 txtTimeProcess->Text = processTime.ToString() + " ms";
		 }
private: System::Void eUARTSend(System::Object^  sender, System::EventArgs^  e)
{
	if (mode == 1) //PID
	{
		txtSEND->Text = "@" + setpointX + ":" + setpointY + ":" + posX + ":" + posY + ":" + KpX + ":" + KdX + ":" + KiX + ":" +KpY + ":" + KdY + ":" + KiY + ":" + scale_input + ":" + mode + "$";
	}
	else if (mode == 2)//Fuzzy
	{
		txtSEND->Text = "@" + setpointX + ":" + setpointY + ":" + posX + ":" + posY + ":" + scale_errX + ":" + scale_velX + ":" + scale_outX + ":" + +scale_errY + ":" + scale_velY + ":" + scale_outY + ":" + scale_input + ":" + mode + "$";
	}
	else if (mode == 3) //Manual
	{
		txtSEND->Text = "@" + angleX + ":" + angleY + ":" + 3 + ":" + 4 + ":" + 5 + ":" + 6 + ":" + 7 + ":" + 8 + ":" + 9+ ":" + 10 + ":" + 11 + ":" +  mode +"$";
	}
	else
	{ }
	
	
	
}
private: System::Void eUARTReceive(System::Object^  sender, System::EventArgs^  e) {
		if (serialPort->IsOpen == true && serialPort->BytesToRead > 0)
		{
			String^ line = serialPort->ReadExisting();
			String^ delimStr = "@:$";
			array<Char>^ delimiter = delimStr->ToCharArray();
			array<String^>^ words;
			
			words = line->Split(delimiter);
			//txtRECEIVE->Text = "";
			//for (int word = 0; word < words->Length; word++)
			//	txtRECEIVE->Text = txtRECEIVE->Text + words[word] + " ";
			if (words->Length == 14)
			{
				errX = System::Convert::ToInt32(words[1]);
				errY = System::Convert::ToInt32(words[2]);

				velX = System::Convert::ToInt32(words[3]);
				velY = System::Convert::ToInt32(words[4]);

				angleX = System::Convert::ToInt32(words[5]);
				angleY = System::Convert::ToInt32(words[6]);
		
				txtDisplayAngle1->Text = words[7];
				txtDisplayAngle2->Text = words[8];
				txtDisplayAngle3->Text = words[9];
				txtDisplayAngle4->Text = words[10];
				txtDisplayAngle5->Text = words[11];
				txtDisplayAngle6->Text = words[12];
			}
			txtRECEIVE->Text = line;
			
		}
	}
private: System::Void timerTracking_Tick(System::Object^  sender, System::EventArgs^  e) {
	static int currentPoint = 0;
	if (bSTART_TRACK->Text == "STOP TRACK" && numOfPoint != 0)
	{
		if (currentPoint < numOfPoint)
		{
			setpointX = trajectoryData1[currentPoint];
			setpointY = trajectoryData2[currentPoint];
			currentPoint++;
		}
		else
		{
			currentPoint = 0;
		}
	}
}



#pragma endregion


#pragma region button_event
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
//		MessageBox::Show("PLEASE CHOOSE PORT !!!!! ^_^ ");
		findPorts();
	}
}
private: System::Void bSEND_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bSEND->Text == "SEND" && bCONNECT->Text == "DISCONNECT")
	{
		timerUART_Send->Start();
		timerUART_Receive->Start();
		bSEND->Text = "STOP SEND";
	}
	else if (bCONNECT->Text == "CONNECT")
	{
	//	MessageBox::Show("Please connect port !!!");
	}
	else
	{
		bSEND->Text = "SEND";
		timerUART_Send->Stop();
		timerUART_Receive->Stop();
	}
}

private: System::Void bSCROLL_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bSCROLL->Text == "SLIDE")
	{
		bSCROLL->Text = "BLOCK";
	}
	else
	{
		bSCROLL->Text = "SLIDE";
	}

}

private: System::Void bSETBALL_Click(System::Object^  sender, System::EventArgs^  e) {
	if (radioPoint->Checked == true)
	{
		setpointX = System::Convert::ToDouble(txtSetSPX->Text);
		setpointY = System::Convert::ToDouble(txtSetSPY->Text);
	}
	else if (radioCircle->Checked == true)
	{
		numOfPoint = 100;
		circleOffsetX = System::Convert::ToInt32(txtCenterCircleX->Text);
		circleOffsetY = System::Convert::ToInt32(txtCenterCircleY->Text);
		circleRadius = System::Convert::ToInt32(txtRadiusCircle->Text);

		trajectoryData1->Clear();
		trajectoryData2->Clear();
		int t = 0;
		for (int i = 0; i < numOfPoint; i++)
		{
			trajectoryData1->Add(circleOffsetX + circleRadius * sin((float)2 * t * PI_F / numOfPoint));
			trajectoryData2->Add(circleOffsetY + circleRadius * cos((float)2 * t * PI_F / numOfPoint));
			t++;
		}
		speedChangePoint = System::Convert::ToInt32(txtSpeedChangePoint->Text);
		timerTracking->Interval = speedChangePoint;
		initTrajectory();
	}
	else if (radioOther->Checked == true)
	{
		speedChangePoint = System::Convert::ToInt32(txtSpeedChangePoint->Text);
		timerTracking->Interval = speedChangePoint;
		initTrajectory();
	}
	else
	{

	}


}
private: System::Void bCALIB_Click(System::Object^  sender, System::EventArgs^  e) {
	camera.createTrackbars();
}
private: System::Void bSTART_PID_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bSTART_PID->Text == "START PID")
	{
		bSTART_PID->Text = "STOP PID";
		bSTART_FUZZY->Text = "START FUZZY";
		mode = 1;
	}
	else
	{
		bSTART_PID->Text = "START PID";
		mode = 0;
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
		bSTART_PID->Text = "START PID";
		mode = 2;
	}
	else
	{
		bSTART_FUZZY->Text = "START FUZZY";
		mode = 0;
	}
}
private: System::Void bSetFuzzyScaleXY_Click(System::Object^  sender, System::EventArgs^  e) {
	if (txtScaleErr1->Text == "" || txtScaleErr2->Text == "" || txtScaleFuzzy->Text == "" ||
		txtScaleErr1->Text == "0" || txtScaleErr2->Text == "0" || txtScaleFuzzy->Text == "0" ||
		txtScaleVel1->Text == "" || txtScaleVel2->Text == "" ||
		txtScaleVel1->Text == "0" || txtScaleVel2->Text == "0" ||
		txtScaleOut1->Text == "" || txtScaleOut2->Text == "" || 
		txtScaleOut1->Text == "0" || txtScaleOut2->Text == "0"
		)
	{
		MessageBox::Show("Invalid input !!!! 'All input must be not null and zero.");
	}
	else
	{
		scale_errX = System::Convert::ToDouble(txtScaleErr1->Text);
		scale_errY = System::Convert::ToDouble(txtScaleErr2->Text);

		scale_velX = System::Convert::ToDouble(txtScaleVel1->Text);
		scale_velY = System::Convert::ToDouble(txtScaleVel2->Text);

		scale_outX = System::Convert::ToDouble(txtScaleOut1->Text);
		scale_outY = System::Convert::ToDouble(txtScaleOut2->Text);

		scale_input = System::Convert::ToDouble(txtScaleFuzzy->Text);
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
		txtKP2->Text == "" || txtKI2->Text == "" || txtKD2->Text == "" || txtScalePID->Text == "" || txtScalePID->Text == "0"
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
		scale_input = System::Convert::ToDouble(txtScalePID->Text);
	}

}
private: System::Void bClose_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}


private: System::Void bSTART_CAM_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bSTART_CAM->Text == "START CAM")
	{
		bSTART_CAM->Text = "STOP CAM";
		timerCamera->Start();
		timerDisplay->Start();
	}
	else
	{
		bSTART_CAM->Text = "START CAM";
		timerCamera->Stop();
		timerDisplay->Stop();
	}
}




private: System::Void bClearGraph_Click(System::Object^  sender, System::EventArgs^  e) {
	clearGraph();
	initScale();
}

private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioPoint->Checked == true)
	{
		numOfPoint = 0;
		txtSetSPX->Enabled = true;
		txtSetSPY->Enabled = true;

		txtCenterCircleX->Enabled = false;
		txtCenterCircleY->Enabled = false;
		txtRadiusCircle->Enabled = false;

		txtNumOfPoint->Enabled = false;
		bImportTrajectory->Enabled = false;
		txtSpeedChangePoint->Enabled = false;
		bSTART_TRACK->Enabled = false;
		bSTART_TRACK->Text = "START TRACK";
		timerTracking->Stop();
	}
}
private: System::Void radioCircle_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioCircle->Checked == true)
	{
		txtSetSPX->Enabled = false;
		txtSetSPY->Enabled = false;

		txtCenterCircleX->Enabled = true;
		txtCenterCircleY->Enabled = true;
		txtRadiusCircle->Enabled = true;

		txtNumOfPoint->Enabled = false;
		bImportTrajectory->Enabled = false;
		txtSpeedChangePoint->Enabled = true;
		bSTART_TRACK->Enabled = true;
		bSTART_TRACK->Text = "START TRACK";
		timerTracking->Stop();
	}
}
private: System::Void radioOther_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioOther->Checked == true)
	{
		txtSetSPX->Enabled = false;
		txtSetSPY->Enabled = false;

		txtCenterCircleX->Enabled = false;
		txtCenterCircleY->Enabled = false;
		txtRadiusCircle->Enabled = false;

		txtNumOfPoint->Enabled = true;
		bImportTrajectory->Enabled = true;
		txtSpeedChangePoint->Enabled = true;
		bSTART_TRACK->Enabled = true;
		bSTART_TRACK->Text = "START TRACK";
		timerTracking->Stop();
	}
}
private: System::Void bImportTrajectory_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ openFilePlan = gcnew OpenFileDialog();
	openFilePlan->InitialDirectory = Directory::GetCurrentDirectory();
	openFilePlan->Filter = "Text File|*.txt";
	openFilePlan->Title = "Load setting file";
	openFilePlan->ShowDialog();

	// If the file name is not an empty string open it for saving.  
	if (openFilePlan->FileName != "")
	{
		try
		{
			StreamReader^ din = File::OpenText(openFilePlan->FileName);
			//1st element is num of points, 2nd element is time change to next point, 3rd to end is (x,y)
			// a b
			// b c
			// ....

			numOfPoint = System::Convert::ToInt32(din->ReadLine());
			speedChangePoint = System::Convert::ToInt32(din->ReadLine());
			trajectoryData1->Clear();
			trajectoryData2->Clear();
			for (int i = 0; i < numOfPoint; i++)
			{
				trajectoryData1->Add(System::Convert::ToInt32(din->ReadLine()));
				trajectoryData2->Add(System::Convert::ToInt32(din->ReadLine()));
			}
			txtNumOfPoint->Text = numOfPoint.ToString();
			txtSpeedChangePoint->Text = speedChangePoint.ToString();
			din->Close();
//			initTrajectory();
		}
		catch (Exception^ e)
		{
			if (dynamic_cast<FileNotFoundException^>(e))
				MessageBox::Show("file '{0}' not found", openFilePlan->FileName);
			else
				MessageBox::Show("problem reading file '{0}'", openFilePlan->FileName);
		}
	}
}
private: System::Void bSTART_TRACK_Click(System::Object^  sender, System::EventArgs^  e) {
	if (bSTART_TRACK->Text == "START TRACK")
	{
		bSTART_TRACK->Text = "STOP TRACK";
		timerTracking->Start();
	}
	else
	{
		bSTART_TRACK->Text = "START TRACK";
		timerTracking->Stop();
	}
}

#pragma endregion
};
}