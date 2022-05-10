#pragma once
//*************************************************************************************************
//                                           Form principal
// Data: 14/05/2020
//*************************************************************************************************
#include "Modules.h"

// A expressão aqui é resultado de V_fase * (9V/200V) * (10k/100k)
// Onde:
// 220V -> Tensão do primário do transformador de isolação
// 9V   -> Tensão do secundário do transformador de isolação
// 10k  -> Resistor do circuito de divisão de tensão do sensor (fixo)
// 100k -> Ajuste do trimpot do circuito de divisão de tensão do sensor (máx 100k)
constexpr auto RELACAO_TRANSFORMACAO = (2200.0f/9.0f);
constexpr auto ZERO_VOLT_VALUE = 1.68f;
constexpr auto TAXA_AMOSTRAGEM = (1 / 1000.0f);

namespace BaseProject 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	using namespace System::Text;
	using namespace CommDevices;
	using namespace Modules;

	/// <summary>
	/// Sumário para MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	protected:
	private: System::Windows::Forms::TabControl^  tabCtrlApplication;
	private: System::Windows::Forms::TabPage^  tabModule;
	private: System::Windows::Forms::TextBox^  txtSendMessage;
	private: System::Windows::Forms::Button^  btnSendEcho;
	private: System::Windows::Forms::TextBox^  txtMessages;
	private: System::Windows::Forms::Button^  btnConnect;
	private: System::Windows::Forms::ComboBox^  cmboxSerialPorts;
	private: System::Windows::Forms::TabPage^  tabDAQ;
	private: System::Windows::Forms::TabPage^  tabADC;
	private: System::Windows::Forms::ToolStripStatusLabel^  stLabelConnection;
	private: System::Windows::Forms::Label^  lblEcho;
	private: System::Windows::Forms::Button^  btnGetSamples;
	private: System::Windows::Forms::Button^  btnLeitura;
	private: System::Windows::Forms::GroupBox^  gpbxDAQControl;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chtSignal;
	private: System::Windows::Forms::ComboBox^  cmboxADCSelection;
	private: System::Windows::Forms::Label^  lblADCSelection;
	private: System::Windows::Forms::Label^  lblLeitura;
	private: System::Windows::Forms::Label^  lblAnalogReading;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnTxtClear;
	private: System::Windows::Forms::CheckBox^ cbxTensao1;
	private: System::Windows::Forms::CheckBox^ cbxCorrente3;
	private: System::Windows::Forms::CheckBox^ cbxCorrente2;
	private: System::Windows::Forms::CheckBox^ cbxCorrente1;
	private: System::Windows::Forms::CheckBox^ cbxTensao3;
	private: System::Windows::Forms::CheckBox^ cbxTensao2;
	private: System::ComponentModel::IContainer^  components;
	protected:
	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->stLabelConnection = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tabCtrlApplication = (gcnew System::Windows::Forms::TabControl());
			this->tabModule = (gcnew System::Windows::Forms::TabPage());
			this->btnTxtClear = (gcnew System::Windows::Forms::Button());
			this->lblEcho = (gcnew System::Windows::Forms::Label());
			this->txtSendMessage = (gcnew System::Windows::Forms::TextBox());
			this->btnSendEcho = (gcnew System::Windows::Forms::Button());
			this->txtMessages = (gcnew System::Windows::Forms::TextBox());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->cmboxSerialPorts = (gcnew System::Windows::Forms::ComboBox());
			this->tabDAQ = (gcnew System::Windows::Forms::TabPage());
			this->chtSignal = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->gpbxDAQControl = (gcnew System::Windows::Forms::GroupBox());
			this->cbxCorrente3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxCorrente2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxCorrente1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxTensao3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxTensao2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxTensao1 = (gcnew System::Windows::Forms::CheckBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnGetSamples = (gcnew System::Windows::Forms::Button());
			this->tabADC = (gcnew System::Windows::Forms::TabPage());
			this->lblLeitura = (gcnew System::Windows::Forms::Label());
			this->lblAnalogReading = (gcnew System::Windows::Forms::Label());
			this->cmboxADCSelection = (gcnew System::Windows::Forms::ComboBox());
			this->lblADCSelection = (gcnew System::Windows::Forms::Label());
			this->btnLeitura = (gcnew System::Windows::Forms::Button());
			this->statusStrip1->SuspendLayout();
			this->tabCtrlApplication->SuspendLayout();
			this->tabModule->SuspendLayout();
			this->tabDAQ->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chtSignal))->BeginInit();
			this->gpbxDAQControl->SuspendLayout();
			this->tabADC->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->stLabelConnection });
			this->statusStrip1->Location = System::Drawing::Point(0, 472);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 19, 0);
			this->statusStrip1->Size = System::Drawing::Size(917, 26);
			this->statusStrip1->TabIndex = 15;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// stLabelConnection
			// 
			this->stLabelConnection->Name = L"stLabelConnection";
			this->stLabelConnection->Size = System::Drawing::Size(104, 20);
			this->stLabelConnection->Text = L"Desconectado";
			// 
			// tabCtrlApplication
			// 
			this->tabCtrlApplication->Controls->Add(this->tabModule);
			this->tabCtrlApplication->Controls->Add(this->tabDAQ);
			this->tabCtrlApplication->Controls->Add(this->tabADC);
			this->tabCtrlApplication->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabCtrlApplication->Location = System::Drawing::Point(0, 0);
			this->tabCtrlApplication->Margin = System::Windows::Forms::Padding(4);
			this->tabCtrlApplication->Name = L"tabCtrlApplication";
			this->tabCtrlApplication->SelectedIndex = 0;
			this->tabCtrlApplication->Size = System::Drawing::Size(917, 472);
			this->tabCtrlApplication->TabIndex = 16;
			// 
			// tabModule
			// 
			this->tabModule->BackColor = System::Drawing::SystemColors::Control;
			this->tabModule->Controls->Add(this->btnTxtClear);
			this->tabModule->Controls->Add(this->lblEcho);
			this->tabModule->Controls->Add(this->txtSendMessage);
			this->tabModule->Controls->Add(this->btnSendEcho);
			this->tabModule->Controls->Add(this->txtMessages);
			this->tabModule->Controls->Add(this->btnConnect);
			this->tabModule->Controls->Add(this->cmboxSerialPorts);
			this->tabModule->Location = System::Drawing::Point(4, 25);
			this->tabModule->Margin = System::Windows::Forms::Padding(4);
			this->tabModule->Name = L"tabModule";
			this->tabModule->Padding = System::Windows::Forms::Padding(4);
			this->tabModule->Size = System::Drawing::Size(909, 443);
			this->tabModule->TabIndex = 0;
			this->tabModule->Text = L"Módulo";
			// 
			// btnTxtClear
			// 
			this->btnTxtClear->Enabled = false;
			this->btnTxtClear->Location = System::Drawing::Point(356, 11);
			this->btnTxtClear->Name = L"btnTxtClear";
			this->btnTxtClear->Size = System::Drawing::Size(163, 28);
			this->btnTxtClear->TabIndex = 23;
			this->btnTxtClear->Text = L"Limpar caixa de texto";
			this->btnTxtClear->UseVisualStyleBackColor = true;
			this->btnTxtClear->Click += gcnew System::EventHandler(this, &MainForm::btnTxtClear_Click);
			// 
			// lblEcho
			// 
			this->lblEcho->AutoSize = true;
			this->lblEcho->Enabled = false;
			this->lblEcho->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEcho->Location = System::Drawing::Point(16, 47);
			this->lblEcho->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblEcho->Name = L"lblEcho";
			this->lblEcho->Size = System::Drawing::Size(99, 20);
			this->lblEcho->TabIndex = 22;
			this->lblEcho->Text = L"Ecoar texto:";
			// 
			// txtSendMessage
			// 
			this->txtSendMessage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtSendMessage->Enabled = false;
			this->txtSendMessage->Location = System::Drawing::Point(128, 44);
			this->txtSendMessage->Margin = System::Windows::Forms::Padding(4);
			this->txtSendMessage->Name = L"txtSendMessage";
			this->txtSendMessage->Size = System::Drawing::Size(659, 22);
			this->txtSendMessage->TabIndex = 19;
			// 
			// btnSendEcho
			// 
			this->btnSendEcho->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSendEcho->Enabled = false;
			this->btnSendEcho->Location = System::Drawing::Point(796, 41);
			this->btnSendEcho->Margin = System::Windows::Forms::Padding(4);
			this->btnSendEcho->Name = L"btnSendEcho";
			this->btnSendEcho->Size = System::Drawing::Size(100, 28);
			this->btnSendEcho->TabIndex = 18;
			this->btnSendEcho->Text = L"Enviar";
			this->btnSendEcho->UseVisualStyleBackColor = true;
			this->btnSendEcho->Click += gcnew System::EventHandler(this, &MainForm::btnSendEcho_Click);
			// 
			// txtMessages
			// 
			this->txtMessages->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtMessages->Enabled = false;
			this->txtMessages->Location = System::Drawing::Point(20, 76);
			this->txtMessages->Margin = System::Windows::Forms::Padding(4);
			this->txtMessages->Multiline = true;
			this->txtMessages->Name = L"txtMessages";
			this->txtMessages->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtMessages->Size = System::Drawing::Size(875, 355);
			this->txtMessages->TabIndex = 17;
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(236, 11);
			this->btnConnect->Margin = System::Windows::Forms::Padding(4);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(113, 28);
			this->btnConnect->TabIndex = 16;
			this->btnConnect->Text = L"Conectar";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &MainForm::btnConnect_Click);
			// 
			// cmboxSerialPorts
			// 
			this->cmboxSerialPorts->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmboxSerialPorts->FormattingEnabled = true;
			this->cmboxSerialPorts->Location = System::Drawing::Point(20, 11);
			this->cmboxSerialPorts->Margin = System::Windows::Forms::Padding(4);
			this->cmboxSerialPorts->Name = L"cmboxSerialPorts";
			this->cmboxSerialPorts->Size = System::Drawing::Size(207, 24);
			this->cmboxSerialPorts->TabIndex = 15;
			this->cmboxSerialPorts->Click += gcnew System::EventHandler(this, &MainForm::cmboxSerialPorts_Click);
			// 
			// tabDAQ
			// 
			this->tabDAQ->BackColor = System::Drawing::SystemColors::Control;
			this->tabDAQ->Controls->Add(this->chtSignal);
			this->tabDAQ->Controls->Add(this->gpbxDAQControl);
			this->tabDAQ->Location = System::Drawing::Point(4, 25);
			this->tabDAQ->Margin = System::Windows::Forms::Padding(4);
			this->tabDAQ->Name = L"tabDAQ";
			this->tabDAQ->Padding = System::Windows::Forms::Padding(4);
			this->tabDAQ->Size = System::Drawing::Size(909, 443);
			this->tabDAQ->TabIndex = 1;
			this->tabDAQ->Text = L"Sinais";
			// 
			// chtSignal
			// 
			this->chtSignal->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisX->Title = L"Tempo (s)";
			chartArea1->AxisY->Title = L"Tensão (V)";
			chartArea1->Name = L"Sinais";
			this->chtSignal->ChartAreas->Add(chartArea1);
			this->chtSignal->Enabled = false;
			legend1->Name = L"Legenda";
			this->chtSignal->Legends->Add(legend1);
			this->chtSignal->Location = System::Drawing::Point(4, 90);
			this->chtSignal->Margin = System::Windows::Forms::Padding(4);
			this->chtSignal->Name = L"chtSignal";
			series1->ChartArea = L"Sinais";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legenda";
			series1->Name = L"Tensao1";
			series2->ChartArea = L"Sinais";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legenda";
			series2->Name = L"Tensao2";
			series3->ChartArea = L"Sinais";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Legend = L"Legenda";
			series3->Name = L"Tensao3";
			series4->ChartArea = L"Sinais";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legenda";
			series4->Name = L"Corrente1";
			series5->ChartArea = L"Sinais";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series5->Legend = L"Legenda";
			series5->Name = L"Corrente2";
			series6->ChartArea = L"Sinais";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series6->Legend = L"Legenda";
			series6->Name = L"Corrente3";
			this->chtSignal->Series->Add(series1);
			this->chtSignal->Series->Add(series2);
			this->chtSignal->Series->Add(series3);
			this->chtSignal->Series->Add(series4);
			this->chtSignal->Series->Add(series5);
			this->chtSignal->Series->Add(series6);
			this->chtSignal->Size = System::Drawing::Size(899, 346);
			this->chtSignal->TabIndex = 29;
			this->chtSignal->Text = L"chart1";
			// 
			// gpbxDAQControl
			// 
			this->gpbxDAQControl->Controls->Add(this->cbxCorrente3);
			this->gpbxDAQControl->Controls->Add(this->cbxCorrente2);
			this->gpbxDAQControl->Controls->Add(this->cbxCorrente1);
			this->gpbxDAQControl->Controls->Add(this->cbxTensao3);
			this->gpbxDAQControl->Controls->Add(this->cbxTensao2);
			this->gpbxDAQControl->Controls->Add(this->cbxTensao1);
			this->gpbxDAQControl->Controls->Add(this->btnClear);
			this->gpbxDAQControl->Controls->Add(this->btnGetSamples);
			this->gpbxDAQControl->Dock = System::Windows::Forms::DockStyle::Top;
			this->gpbxDAQControl->Enabled = false;
			this->gpbxDAQControl->Location = System::Drawing::Point(4, 4);
			this->gpbxDAQControl->Margin = System::Windows::Forms::Padding(4);
			this->gpbxDAQControl->Name = L"gpbxDAQControl";
			this->gpbxDAQControl->Padding = System::Windows::Forms::Padding(4);
			this->gpbxDAQControl->Size = System::Drawing::Size(901, 78);
			this->gpbxDAQControl->TabIndex = 28;
			this->gpbxDAQControl->TabStop = false;
			this->gpbxDAQControl->Text = L"Controle de aquisição de dados";
			// 
			// cbxCorrente3
			// 
			this->cbxCorrente3->AutoSize = true;
			this->cbxCorrente3->Checked = true;
			this->cbxCorrente3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxCorrente3->Location = System::Drawing::Point(640, 47);
			this->cbxCorrente3->Name = L"cbxCorrente3";
			this->cbxCorrente3->Size = System::Drawing::Size(90, 20);
			this->cbxCorrente3->TabIndex = 28;
			this->cbxCorrente3->Text = L"Corrente 3";
			this->cbxCorrente3->UseVisualStyleBackColor = true;
			this->cbxCorrente3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxCorrente3_CheckedChanged);
			// 
			// cbxCorrente2
			// 
			this->cbxCorrente2->AutoSize = true;
			this->cbxCorrente2->Checked = true;
			this->cbxCorrente2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxCorrente2->Location = System::Drawing::Point(544, 47);
			this->cbxCorrente2->Name = L"cbxCorrente2";
			this->cbxCorrente2->Size = System::Drawing::Size(90, 20);
			this->cbxCorrente2->TabIndex = 27;
			this->cbxCorrente2->Text = L"Corrente 2";
			this->cbxCorrente2->UseVisualStyleBackColor = true;
			this->cbxCorrente2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxCorrente2_CheckedChanged);
			// 
			// cbxCorrente1
			// 
			this->cbxCorrente1->AutoSize = true;
			this->cbxCorrente1->Checked = true;
			this->cbxCorrente1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxCorrente1->Location = System::Drawing::Point(448, 47);
			this->cbxCorrente1->Name = L"cbxCorrente1";
			this->cbxCorrente1->Size = System::Drawing::Size(90, 20);
			this->cbxCorrente1->TabIndex = 26;
			this->cbxCorrente1->Text = L"Corrente 1";
			this->cbxCorrente1->UseVisualStyleBackColor = true;
			this->cbxCorrente1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxCorrente1_CheckedChanged);
			// 
			// cbxTensao3
			// 
			this->cbxTensao3->AutoSize = true;
			this->cbxTensao3->Checked = true;
			this->cbxTensao3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxTensao3->Location = System::Drawing::Point(640, 22);
			this->cbxTensao3->Name = L"cbxTensao3";
			this->cbxTensao3->Size = System::Drawing::Size(86, 20);
			this->cbxTensao3->TabIndex = 25;
			this->cbxTensao3->Text = L"Tensão 3";
			this->cbxTensao3->UseVisualStyleBackColor = true;
			this->cbxTensao3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxTensao3_CheckedChanged);
			// 
			// cbxTensao2
			// 
			this->cbxTensao2->AutoSize = true;
			this->cbxTensao2->Checked = true;
			this->cbxTensao2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxTensao2->Location = System::Drawing::Point(544, 22);
			this->cbxTensao2->Name = L"cbxTensao2";
			this->cbxTensao2->Size = System::Drawing::Size(86, 20);
			this->cbxTensao2->TabIndex = 24;
			this->cbxTensao2->Text = L"Tensão 2";
			this->cbxTensao2->UseVisualStyleBackColor = true;
			this->cbxTensao2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxTensao2_CheckedChanged);
			// 
			// cbxTensao1
			// 
			this->cbxTensao1->AutoSize = true;
			this->cbxTensao1->Checked = true;
			this->cbxTensao1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxTensao1->Location = System::Drawing::Point(448, 22);
			this->cbxTensao1->Name = L"cbxTensao1";
			this->cbxTensao1->Size = System::Drawing::Size(86, 20);
			this->cbxTensao1->TabIndex = 23;
			this->cbxTensao1->Text = L"Tensão 1";
			this->cbxTensao1->UseVisualStyleBackColor = true;
			this->cbxTensao1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxTensao1_CheckedChanged);
			// 
			// btnClear
			// 
			this->btnClear->Enabled = false;
			this->btnClear->Location = System::Drawing::Point(221, 23);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(166, 28);
			this->btnClear->TabIndex = 22;
			this->btnClear->Text = L"Limpar gráfico";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::btnClear_Click);
			// 
			// btnGetSamples
			// 
			this->btnGetSamples->Location = System::Drawing::Point(8, 23);
			this->btnGetSamples->Margin = System::Windows::Forms::Padding(4);
			this->btnGetSamples->Name = L"btnGetSamples";
			this->btnGetSamples->Size = System::Drawing::Size(206, 28);
			this->btnGetSamples->TabIndex = 21;
			this->btnGetSamples->Text = L"Adquirir amostras";
			this->btnGetSamples->UseVisualStyleBackColor = true;
			this->btnGetSamples->Click += gcnew System::EventHandler(this, &MainForm::btnGetSamples_Click);
			// 
			// tabADC
			// 
			this->tabADC->BackColor = System::Drawing::SystemColors::Control;
			this->tabADC->Controls->Add(this->lblLeitura);
			this->tabADC->Controls->Add(this->lblAnalogReading);
			this->tabADC->Controls->Add(this->cmboxADCSelection);
			this->tabADC->Controls->Add(this->lblADCSelection);
			this->tabADC->Controls->Add(this->btnLeitura);
			this->tabADC->Location = System::Drawing::Point(4, 25);
			this->tabADC->Margin = System::Windows::Forms::Padding(4);
			this->tabADC->Name = L"tabADC";
			this->tabADC->Size = System::Drawing::Size(909, 443);
			this->tabADC->TabIndex = 2;
			this->tabADC->Text = L"Leitura instantânea";
			// 
			// lblLeitura
			// 
			this->lblLeitura->AutoSize = true;
			this->lblLeitura->Enabled = false;
			this->lblLeitura->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLeitura->Location = System::Drawing::Point(4, 64);
			this->lblLeitura->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblLeitura->Name = L"lblLeitura";
			this->lblLeitura->Size = System::Drawing::Size(303, 91);
			this->lblLeitura->TabIndex = 26;
			this->lblLeitura->Text = L"Leitura:";
			// 
			// lblAnalogReading
			// 
			this->lblAnalogReading->AutoSize = true;
			this->lblAnalogReading->Enabled = false;
			this->lblAnalogReading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAnalogReading->ForeColor = System::Drawing::Color::Red;
			this->lblAnalogReading->Location = System::Drawing::Point(341, 64);
			this->lblAnalogReading->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblAnalogReading->Name = L"lblAnalogReading";
			this->lblAnalogReading->Size = System::Drawing::Size(157, 91);
			this->lblAnalogReading->TabIndex = 25;
			this->lblAnalogReading->Text = L"\? V";
			// 
			// cmboxADCSelection
			// 
			this->cmboxADCSelection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmboxADCSelection->Enabled = false;
			this->cmboxADCSelection->FormattingEnabled = true;
			this->cmboxADCSelection->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Tensão 1", L"Tensão 2", L"Tensão 3",
					L"Corrente 1", L"Corrente 2", L"Corrente 3"
			});
			this->cmboxADCSelection->Location = System::Drawing::Point(67, 7);
			this->cmboxADCSelection->Margin = System::Windows::Forms::Padding(4);
			this->cmboxADCSelection->Name = L"cmboxADCSelection";
			this->cmboxADCSelection->Size = System::Drawing::Size(117, 24);
			this->cmboxADCSelection->TabIndex = 24;
			// 
			// lblADCSelection
			// 
			this->lblADCSelection->AutoSize = true;
			this->lblADCSelection->Enabled = false;
			this->lblADCSelection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblADCSelection->Location = System::Drawing::Point(11, 10);
			this->lblADCSelection->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblADCSelection->Name = L"lblADCSelection";
			this->lblADCSelection->Size = System::Drawing::Size(51, 20);
			this->lblADCSelection->TabIndex = 23;
			this->lblADCSelection->Text = L"Sinal:";
			// 
			// btnLeitura
			// 
			this->btnLeitura->Enabled = false;
			this->btnLeitura->Location = System::Drawing::Point(193, 7);
			this->btnLeitura->Margin = System::Windows::Forms::Padding(4);
			this->btnLeitura->Name = L"btnLeitura";
			this->btnLeitura->Size = System::Drawing::Size(120, 28);
			this->btnLeitura->TabIndex = 22;
			this->btnLeitura->Text = L"Obter valor";
			this->btnLeitura->UseVisualStyleBackColor = true;
			this->btnLeitura->Click += gcnew System::EventHandler(this, &MainForm::btnLeitura_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(917, 498);
			this->Controls->Add(this->tabCtrlApplication);
			this->Controls->Add(this->statusStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"Projeto de amostragem de potência trifásica";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->tabCtrlApplication->ResumeLayout(false);
			this->tabModule->ResumeLayout(false);
			this->tabModule->PerformLayout();
			this->tabDAQ->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chtSignal))->EndInit();
			this->gpbxDAQControl->ResumeLayout(false);
			this->gpbxDAQControl->PerformLayout();
			this->tabADC->ResumeLayout(false);
			this->tabADC->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			Module ^device;
			unsigned long long amostra;

			System::Void cmboxSerialPorts_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				array<String ^> ^portNames = SerialPort::GetPortNames();

				cmboxSerialPorts->Items->Clear();
				for each(String ^name in portNames)
					cmboxSerialPorts->Items->Add(name);
			}
			System::Void btnConnect_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (btnConnect->Text == "Conectar")
				{
					USBDevice ^virtualComm = gcnew USBDevice((String ^)cmboxSerialPorts->Items[cmboxSerialPorts->SelectedIndex]);
					device = gcnew Module(virtualComm);
					try
					{
						device->Open();
					}
					catch (UnauthorizedAccessException ^)
					{
						MessageBox::Show("Porta não pode ser aberta", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
					catch (ArgumentException ^)
					{
						MessageBox::Show("Nome de porta inválido", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
					catch (IOException ^)
					{
						MessageBox::Show("Porta encontra-se em estado inválido", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
					catch (InvalidOperationException ^)
					{
						MessageBox::Show("Porta já está aberta", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}
					if (device->Connected)
					{
						btnConnect->Text = "Desconectar";
						stLabelConnection->Text = "Conectado";
						device->onReceive += gcnew ModuleReception(this, &MainForm::ReceptionHandler);
						device->onDisconnection += gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);
						cmboxSerialPorts->Enabled = false;

						lblEcho->Enabled = true;
						txtSendMessage->Enabled = true;
						btnSendEcho->Enabled = true;
						txtMessages->Enabled = true;
						gpbxDAQControl->Enabled = true;
						chtSignal->Enabled = true;
						lblADCSelection->Enabled = true;
						cmboxADCSelection->Enabled = true;
						btnLeitura->Enabled = true;
						lblLeitura->Enabled = true;
						lblAnalogReading->Enabled = true;
						btnTxtClear->Enabled = true;
						btnClear->Enabled = true;
					}
				}
				else
				{
					device->Close();
					device = nullptr;
					btnConnect->Text = "Conectar";
					stLabelConnection->Text = "Desconectado";
					cmboxSerialPorts->Enabled = true;

					lblEcho->Enabled = false;
					txtSendMessage->Enabled = false;
					btnSendEcho->Enabled = false;
					txtMessages->Enabled = false;
					gpbxDAQControl->Enabled = false;
					chtSignal->Enabled = false;
					lblADCSelection->Enabled = false;
					cmboxADCSelection->Enabled = false;
					btnLeitura->Enabled = false;
					lblLeitura->Enabled = false;
					lblAnalogReading->Enabled = false;
					btnTxtClear->Enabled = false;
					btnClear->Enabled = false;
				}
			}
			System::Void ReceptionHandler(Object ^eqp, array<unsigned char>^buffer)
			{
				if (txtMessages->InvokeRequired)
				{
					array<Object^>^ myArgArray = { eqp, buffer };
					ModuleReception ^action = gcnew ModuleReception(this, &MainForm::ReceptionHandler);
					this->Invoke(action, myArgArray);
				}
				else
				{
					float tmpFloat;

					switch (buffer[0])
					{
						case CMD_MESSAGE:
							txtMessages->Text += Encoding::ASCII->GetString(buffer, 1, buffer->Length - 1);
							break;
						case CMD_SAMPLE_SEND:
							// Interrompe a atualização do gráfico temporariamente
							// para adicionar novos pontos
							chtSignal->Series["Tensao1"]->Points->SuspendUpdates();
							chtSignal->Series["Tensao2"]->Points->SuspendUpdates();
							chtSignal->Series["Tensao3"]->Points->SuspendUpdates();

							chtSignal->Series["Corrente1"]->Points->SuspendUpdates();
							chtSignal->Series["Corrente2"]->Points->SuspendUpdates();
							chtSignal->Series["Corrente3"]->Points->SuspendUpdates();

							// Adicionando os pontos enviados
							chtSignal->Series["Tensao1"]->Points->AddXY(amostra * TAXA_AMOSTRAGEM, ((BitConverter::ToUInt16(buffer, 1) / 1000.0f) - ZERO_VOLT_VALUE) * RELACAO_TRANSFORMACAO);
							chtSignal->Series["Tensao2"]->Points->AddXY(amostra * TAXA_AMOSTRAGEM, ((BitConverter::ToUInt16(buffer, 3) / 1000.0f) - ZERO_VOLT_VALUE) * RELACAO_TRANSFORMACAO);
							chtSignal->Series["Tensao3"]->Points->AddXY(amostra * TAXA_AMOSTRAGEM, ((BitConverter::ToUInt16(buffer, 5) / 1000.0f) - ZERO_VOLT_VALUE) * RELACAO_TRANSFORMACAO);

							chtSignal->Series["Corrente1"]->Points->AddXY(amostra * TAXA_AMOSTRAGEM, BitConverter::ToUInt16(buffer, 7) / 1000.0f);
							chtSignal->Series["Corrente2"]->Points->AddXY(amostra * TAXA_AMOSTRAGEM, BitConverter::ToUInt16(buffer, 9) / 1000.0f);
							chtSignal->Series["Corrente3"]->Points->AddXY(amostra * TAXA_AMOSTRAGEM, BitConverter::ToUInt16(buffer, 11) / 1000.0f);

							// Restaura a atualização do gráfico
							chtSignal->Series["Tensao1"]->Points->ResumeUpdates();
							chtSignal->Series["Tensao2"]->Points->ResumeUpdates();
							chtSignal->Series["Tensao3"]->Points->ResumeUpdates();

							chtSignal->Series["Corrente1"]->Points->ResumeUpdates();
							chtSignal->Series["Corrente2"]->Points->ResumeUpdates();
							chtSignal->Series["Corrente3"]->Points->ResumeUpdates();

							amostra++;
							break;
						case CMD_GET_ADC_READING:
							tmpFloat = BitConverter::ToUInt16(buffer, 1) / 1000.0f;
							
							switch (cmboxADCSelection->SelectedIndex)
							{
								case 0:
									lblAnalogReading->Text = String::Format("{0:F2} V", tmpFloat);
									break;
								case 1:
									lblAnalogReading->Text = String::Format("{0:F2} V", tmpFloat);
									break;
								case 2:
									lblAnalogReading->Text = String::Format("{0:F2} V", tmpFloat);
									break;
								case 3:
									lblAnalogReading->Text = String::Format("{0:F2} A", tmpFloat);
									break;
								case 4:
									lblAnalogReading->Text = String::Format("{0:F2} A", tmpFloat);
									break;
								case 5:
									lblAnalogReading->Text = String::Format("{0:F2} A", tmpFloat);
									break;
							}
							break;
						default:
							break;
					}
				}
			}
			System::Void DisconnectionHandler(Object ^eqp)
			{
				if (btnConnect->InvokeRequired)
				{
					array<Object^>^ myArgArray = { eqp };
					ModuleDisconnection ^action = gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);
					this->Invoke(action, myArgArray);
				}
				else
				{
					btnConnect->Text = "Conectar";
					stLabelConnection->Text = "Desconectado";
					cmboxSerialPorts->Enabled = true;
					lblEcho->Enabled = false;
					txtSendMessage->Enabled = false;
					btnSendEcho->Enabled = false;
					txtMessages->Enabled = false;
					gpbxDAQControl->Enabled = false;
					chtSignal->Enabled = false;
					lblADCSelection->Enabled = false;
					cmboxADCSelection->Enabled = false;
					btnLeitura->Enabled = false;
					lblLeitura->Enabled = false;
					lblAnalogReading->Enabled = false;
				}
			}
			System::Void btnSendEcho_Click(System::Object^  sender, System::EventArgs^  e)
			{
				if (device->Connected)
				{
					array<unsigned char>^buffer = gcnew array<unsigned char>(txtSendMessage->Text->Length + 5);
					array<unsigned char>^message = Encoding::ASCII->GetBytes(txtSendMessage->Text);
					array<unsigned char>^ convertArray;

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					convertArray = BitConverter::GetBytes(txtSendMessage->Text->Length + 1);
					buffer[2] = convertArray[0];
					buffer[3] = convertArray[1];
					// Comando
					buffer[4] = CMD_SEND_ECHO;
					// Texto para envio
					for (int i = 0; i < message->Length; i++)
						buffer[5 + i] = message[i];

					try
					{
						device->Write(buffer, 0, buffer->Length);
					}
					catch (IOException ^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
			}
			System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
			{
				device->Close();
				device = nullptr;
			}
			System::Void btnGetSamples_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (device->Connected)
				{
					array<unsigned char>^buffer = gcnew array<unsigned char>(6);
					amostra = 0;

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 0x02;
					buffer[3] = 0x00;
					// Comando
					buffer[4] = CMD_SET_SAMPLING_STATE;
					buffer[5] = (btnGetSamples->Text == "Adquirir amostras") ? 1 : 0;

					try
					{
						device->Write(buffer, 0, buffer->Length);
						btnGetSamples->Text = (btnGetSamples->Text == "Adquirir amostras") ? "Parar amostragem" : "Adquirir amostras";
					}
					catch (IOException ^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
				}
			}
			System::Void btnLeitura_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (cmboxADCSelection->SelectedIndex != -1)
				{
					if (device->Connected)
					{
						array<unsigned char>^ buffer = gcnew array<unsigned char>(6);

						buffer[0] = 0xAA;
						buffer[1] = 0x55;
						// Tamanho do campo de dados
						buffer[2] = 0x02;
						buffer[3] = 0x00;
						// Comando
						buffer[4] = CMD_GET_ADC_READING;
						buffer[5] = safe_cast<Byte>(cmboxADCSelection->SelectedIndex);

						try
						{
							device->Write(buffer, 0, buffer->Length);
						}
						catch (IOException^)
						{
							MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						}
					}
				}
				else
				{
					MessageBox::Show("Selecinar um ADC para leitura", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
			}
			System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Tensao1"]->Points->Clear();
				chtSignal->Series["Tensao2"]->Points->Clear();
				chtSignal->Series["Tensao3"]->Points->Clear();

				chtSignal->Series["Corrente1"]->Points->Clear();
				chtSignal->Series["Corrente2"]->Points->Clear();
				chtSignal->Series["Corrente3"]->Points->Clear();
			}
			System::Void btnTxtClear_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				txtMessages->Clear();
			}
			System::Void cbxTensao1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Tensao1"]->Enabled = cbxTensao1->Checked;
			}
			System::Void cbxCorrente1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Corrente1"]->Enabled = cbxCorrente1->Checked;
			}
			System::Void cbxTensao2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Tensao2"]->Enabled = cbxTensao2->Checked;
			}
			System::Void cbxCorrente2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Corrente2"]->Enabled = cbxCorrente2->Checked;
			}
			System::Void cbxTensao3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Tensao3"]->Enabled = cbxTensao3->Checked;
			}
			System::Void cbxCorrente3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Corrente3"]->Enabled = cbxCorrente3->Checked;
			}
};
}
