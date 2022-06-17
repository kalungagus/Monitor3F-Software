#pragma once
//*************************************************************************************************
//                                           Form principal
// Data: 14/05/2020
//*************************************************************************************************
#include "Modules.h"
#include "AnalogSignals.h"

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
	using namespace System::Configuration;
	using namespace CommDevices;
	using namespace Modules;
	using namespace AnalogSignals;

	/// <summary>
	/// Sumário para MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void) : amostra(0), squaredValueSum(gcnew array<double>(6))
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
	private: System::Windows::Forms::TabControl^  tabCtrlApplication;
	private: System::Windows::Forms::TabPage^  tabModule;



	private: System::Windows::Forms::Button^  btnConnect;
	private: System::Windows::Forms::ComboBox^  cmboxSerialPorts;
	private: System::Windows::Forms::TabPage^ tabSignal;
	private: System::Windows::Forms::TabPage^ tabCommonCmd;



	private: System::Windows::Forms::ToolStripStatusLabel^  stLabelConnection;

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
	private: System::Windows::Forms::ComboBox^ cbxResolution;
	private: System::Windows::Forms::Label^ lblResolution;
	private: System::Windows::Forms::TabPage^ tabConfig;
	private: System::Windows::Forms::TextBox^ txtSecundarioT3;
	private: System::Windows::Forms::Label^ lblSecundarioT3;
	private: System::Windows::Forms::TextBox^ txtPrimarioT3;
	private: System::Windows::Forms::Label^ lblPrimarioT3;
	private: System::Windows::Forms::TextBox^ txtSecundarioT2;
	private: System::Windows::Forms::Label^ lblSecundarioT2;
	private: System::Windows::Forms::TextBox^ txtPrimarioT2;
	private: System::Windows::Forms::Label^ lblPrimarioT2;
	private: System::Windows::Forms::TextBox^ txtSecundarioT1;
	private: System::Windows::Forms::Label^ lblSecundarioT1;
	private: System::Windows::Forms::TextBox^ txtPrimarioT1;
	private: System::Windows::Forms::Label^ lblPrimarioT1;
	private: System::Windows::Forms::TextBox^ txtSecundarioTC3;
	private: System::Windows::Forms::Label^ lblSecundarioTC3;
	private: System::Windows::Forms::TextBox^ txtPrimarioTC3;
	private: System::Windows::Forms::Label^ lblPrimarioTC3;
	private: System::Windows::Forms::TextBox^ txtSecundarioTC2;
	private: System::Windows::Forms::Label^ lblSecundarioTC2;
	private: System::Windows::Forms::TextBox^ txtPrimarioTC2;
	private: System::Windows::Forms::Label^ lblPrimarioTC2;
	private: System::Windows::Forms::TextBox^ txtSecundarioTC1;
	private: System::Windows::Forms::Label^ lblSecundarioTC1;
	private: System::Windows::Forms::TextBox^ txtPrimarioTC1;
	private: System::Windows::Forms::Label^ lblPrimarioTC1;
	private: System::Windows::Forms::GroupBox^ gpbxTrafos;
	private: System::Windows::Forms::GroupBox^ gpbxConfigRes;

	private: System::Windows::Forms::Label^ lblRes6;
	private: System::Windows::Forms::TextBox^ txtRes6;
	private: System::Windows::Forms::Label^ lblRes7;
	private: System::Windows::Forms::TextBox^ txtRes7;
	private: System::Windows::Forms::Label^ lblRes8;
	private: System::Windows::Forms::TextBox^ txtRes8;
	private: System::Windows::Forms::Label^ lblRes9;
	private: System::Windows::Forms::TextBox^ txtRes3;
	private: System::Windows::Forms::TextBox^ txtRes9;
	private: System::Windows::Forms::Label^ lblRes3;
	private: System::Windows::Forms::Label^ lblRes10;
	private: System::Windows::Forms::TextBox^ txtRes2;
	private: System::Windows::Forms::TextBox^ txtRes10;
	private: System::Windows::Forms::Label^ lblRes2;
	private: System::Windows::Forms::Label^ lblRes11;
	private: System::Windows::Forms::TextBox^ txtRes1;
	private: System::Windows::Forms::TextBox^ txtRes11;
	private: System::Windows::Forms::Label^ lblRes1;
	private: System::Windows::Forms::Label^ lblADCReading;
	private: System::Windows::Forms::Label^ lblADCReadingValue;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::SaveFileDialog^ dlgSaveCSV;
	private: System::Windows::Forms::CheckBox^ cbxPotencia3;
	private: System::Windows::Forms::CheckBox^ cbxPotencia2;
	private: System::Windows::Forms::CheckBox^ cbxPotencia1;












private: System::Windows::Forms::ToolStripStatusLabel^ stLabelNetConnection;
private: System::Windows::Forms::GroupBox^ gbxNetConnect;
private: System::Windows::Forms::Button^ btnSearch;
private: System::Windows::Forms::Button^ btnNetConnect;
private: System::Windows::Forms::TextBox^ txtPort;
private: System::Windows::Forms::Label^ lblPoint4;
private: System::Windows::Forms::Label^ lblPoint3;
private: System::Windows::Forms::Label^ lblPoint2;
private: System::Windows::Forms::Label^ lblPoint1;
private: System::Windows::Forms::TextBox^ txtIP4;
private: System::Windows::Forms::TextBox^ txtIP3;
private: System::Windows::Forms::TextBox^ txtIP2;
private: System::Windows::Forms::TextBox^ txtIP1;
private: System::Windows::Forms::Label^ lblNetConnect;
private: System::Windows::Forms::GroupBox^ gbxInstReading;
private: System::Windows::Forms::GroupBox^ gbxEcho;
private: System::Windows::Forms::Label^ lblEcho;
private: System::Windows::Forms::TextBox^ txtSendMessage;
private: System::Windows::Forms::Button^ btnSendEcho;

private: System::Windows::Forms::GroupBox^ gbxSerialConnection;
private: System::Windows::Forms::TextBox^ txtMessages;
private: System::Windows::Forms::GroupBox^ gbxNetConfig;
private: System::Windows::Forms::Button^ btnChangePassword;

private: System::Windows::Forms::TextBox^ txtPassword;

private: System::Windows::Forms::TextBox^ txtSSID;

private: System::Windows::Forms::Label^ lblPassword;
private: System::Windows::Forms::Label^ lblSSID;
private: System::Windows::Forms::Button^ btnChangeSSID;
private: System::Windows::Forms::Button^ btnReset;
private: System::Windows::Forms::NumericUpDown^ nudSamplesQty;
private: System::Windows::Forms::Label^ lblSamplesQty;
private: System::Windows::Forms::TextBox^ txtRefTC3;
private: System::Windows::Forms::Label^ lblRefTC3;



private: System::Windows::Forms::TextBox^ txtRefTC2;
private: System::Windows::Forms::Label^ lblRefTC2;



private: System::Windows::Forms::TextBox^ txtRefTC1;
private: System::Windows::Forms::Label^ lblRefTC1;



private: System::Windows::Forms::Label^ lblRefT3;
private: System::Windows::Forms::TextBox^ txtRefT3;

private: System::Windows::Forms::Label^ lblRefT2;
private: System::Windows::Forms::TextBox^ txtRefT2;

private: System::Windows::Forms::Label^ lblRefT1;
private: System::Windows::Forms::TextBox^ txtRefT1;





	private: System::ComponentModel::IContainer^ components;
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
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->stLabelConnection = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->stLabelNetConnection = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tabCtrlApplication = (gcnew System::Windows::Forms::TabControl());
			this->tabModule = (gcnew System::Windows::Forms::TabPage());
			this->gbxNetConfig = (gcnew System::Windows::Forms::GroupBox());
			this->btnChangeSSID = (gcnew System::Windows::Forms::Button());
			this->btnChangePassword = (gcnew System::Windows::Forms::Button());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtSSID = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblSSID = (gcnew System::Windows::Forms::Label());
			this->txtMessages = (gcnew System::Windows::Forms::TextBox());
			this->btnTxtClear = (gcnew System::Windows::Forms::Button());
			this->gbxSerialConnection = (gcnew System::Windows::Forms::GroupBox());
			this->cmboxSerialPorts = (gcnew System::Windows::Forms::ComboBox());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->gbxNetConnect = (gcnew System::Windows::Forms::GroupBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->btnNetConnect = (gcnew System::Windows::Forms::Button());
			this->txtPort = (gcnew System::Windows::Forms::TextBox());
			this->lblPoint4 = (gcnew System::Windows::Forms::Label());
			this->lblPoint3 = (gcnew System::Windows::Forms::Label());
			this->lblPoint2 = (gcnew System::Windows::Forms::Label());
			this->lblPoint1 = (gcnew System::Windows::Forms::Label());
			this->txtIP4 = (gcnew System::Windows::Forms::TextBox());
			this->txtIP3 = (gcnew System::Windows::Forms::TextBox());
			this->txtIP2 = (gcnew System::Windows::Forms::TextBox());
			this->txtIP1 = (gcnew System::Windows::Forms::TextBox());
			this->lblNetConnect = (gcnew System::Windows::Forms::Label());
			this->tabSignal = (gcnew System::Windows::Forms::TabPage());
			this->chtSignal = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->gpbxDAQControl = (gcnew System::Windows::Forms::GroupBox());
			this->nudSamplesQty = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblSamplesQty = (gcnew System::Windows::Forms::Label());
			this->cbxPotencia3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxPotencia2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxPotencia1 = (gcnew System::Windows::Forms::CheckBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->cbxResolution = (gcnew System::Windows::Forms::ComboBox());
			this->lblResolution = (gcnew System::Windows::Forms::Label());
			this->cbxCorrente3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxCorrente2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxCorrente1 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxTensao3 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxTensao2 = (gcnew System::Windows::Forms::CheckBox());
			this->cbxTensao1 = (gcnew System::Windows::Forms::CheckBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnGetSamples = (gcnew System::Windows::Forms::Button());
			this->tabCommonCmd = (gcnew System::Windows::Forms::TabPage());
			this->gbxEcho = (gcnew System::Windows::Forms::GroupBox());
			this->lblEcho = (gcnew System::Windows::Forms::Label());
			this->txtSendMessage = (gcnew System::Windows::Forms::TextBox());
			this->btnSendEcho = (gcnew System::Windows::Forms::Button());
			this->gbxInstReading = (gcnew System::Windows::Forms::GroupBox());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->lblADCSelection = (gcnew System::Windows::Forms::Label());
			this->lblADCReading = (gcnew System::Windows::Forms::Label());
			this->btnLeitura = (gcnew System::Windows::Forms::Button());
			this->lblADCReadingValue = (gcnew System::Windows::Forms::Label());
			this->cmboxADCSelection = (gcnew System::Windows::Forms::ComboBox());
			this->lblLeitura = (gcnew System::Windows::Forms::Label());
			this->lblAnalogReading = (gcnew System::Windows::Forms::Label());
			this->tabConfig = (gcnew System::Windows::Forms::TabPage());
			this->gpbxConfigRes = (gcnew System::Windows::Forms::GroupBox());
			this->lblRes6 = (gcnew System::Windows::Forms::Label());
			this->txtRes6 = (gcnew System::Windows::Forms::TextBox());
			this->lblRes7 = (gcnew System::Windows::Forms::Label());
			this->txtRes7 = (gcnew System::Windows::Forms::TextBox());
			this->lblRes8 = (gcnew System::Windows::Forms::Label());
			this->txtRes8 = (gcnew System::Windows::Forms::TextBox());
			this->lblRes9 = (gcnew System::Windows::Forms::Label());
			this->txtRes3 = (gcnew System::Windows::Forms::TextBox());
			this->txtRes9 = (gcnew System::Windows::Forms::TextBox());
			this->lblRes3 = (gcnew System::Windows::Forms::Label());
			this->lblRes10 = (gcnew System::Windows::Forms::Label());
			this->txtRes2 = (gcnew System::Windows::Forms::TextBox());
			this->txtRes10 = (gcnew System::Windows::Forms::TextBox());
			this->lblRes2 = (gcnew System::Windows::Forms::Label());
			this->lblRes11 = (gcnew System::Windows::Forms::Label());
			this->txtRes1 = (gcnew System::Windows::Forms::TextBox());
			this->txtRes11 = (gcnew System::Windows::Forms::TextBox());
			this->lblRes1 = (gcnew System::Windows::Forms::Label());
			this->gpbxTrafos = (gcnew System::Windows::Forms::GroupBox());
			this->txtRefTC3 = (gcnew System::Windows::Forms::TextBox());
			this->lblRefTC3 = (gcnew System::Windows::Forms::Label());
			this->txtRefTC2 = (gcnew System::Windows::Forms::TextBox());
			this->lblRefTC2 = (gcnew System::Windows::Forms::Label());
			this->txtRefTC1 = (gcnew System::Windows::Forms::TextBox());
			this->lblRefTC1 = (gcnew System::Windows::Forms::Label());
			this->lblRefT3 = (gcnew System::Windows::Forms::Label());
			this->txtRefT3 = (gcnew System::Windows::Forms::TextBox());
			this->lblRefT2 = (gcnew System::Windows::Forms::Label());
			this->txtRefT2 = (gcnew System::Windows::Forms::TextBox());
			this->lblRefT1 = (gcnew System::Windows::Forms::Label());
			this->txtRefT1 = (gcnew System::Windows::Forms::TextBox());
			this->lblPrimarioT1 = (gcnew System::Windows::Forms::Label());
			this->txtSecundarioTC3 = (gcnew System::Windows::Forms::TextBox());
			this->txtPrimarioT1 = (gcnew System::Windows::Forms::TextBox());
			this->lblSecundarioTC3 = (gcnew System::Windows::Forms::Label());
			this->lblSecundarioT1 = (gcnew System::Windows::Forms::Label());
			this->txtPrimarioTC3 = (gcnew System::Windows::Forms::TextBox());
			this->txtSecundarioT1 = (gcnew System::Windows::Forms::TextBox());
			this->lblPrimarioTC3 = (gcnew System::Windows::Forms::Label());
			this->lblPrimarioT2 = (gcnew System::Windows::Forms::Label());
			this->txtSecundarioTC2 = (gcnew System::Windows::Forms::TextBox());
			this->txtPrimarioT2 = (gcnew System::Windows::Forms::TextBox());
			this->lblSecundarioTC2 = (gcnew System::Windows::Forms::Label());
			this->lblSecundarioT2 = (gcnew System::Windows::Forms::Label());
			this->txtPrimarioTC2 = (gcnew System::Windows::Forms::TextBox());
			this->txtSecundarioT2 = (gcnew System::Windows::Forms::TextBox());
			this->lblPrimarioTC2 = (gcnew System::Windows::Forms::Label());
			this->lblPrimarioT3 = (gcnew System::Windows::Forms::Label());
			this->txtSecundarioTC1 = (gcnew System::Windows::Forms::TextBox());
			this->txtPrimarioT3 = (gcnew System::Windows::Forms::TextBox());
			this->lblSecundarioTC1 = (gcnew System::Windows::Forms::Label());
			this->lblSecundarioT3 = (gcnew System::Windows::Forms::Label());
			this->txtPrimarioTC1 = (gcnew System::Windows::Forms::TextBox());
			this->txtSecundarioT3 = (gcnew System::Windows::Forms::TextBox());
			this->lblPrimarioTC1 = (gcnew System::Windows::Forms::Label());
			this->dlgSaveCSV = (gcnew System::Windows::Forms::SaveFileDialog());
			this->statusStrip1->SuspendLayout();
			this->tabCtrlApplication->SuspendLayout();
			this->tabModule->SuspendLayout();
			this->gbxNetConfig->SuspendLayout();
			this->gbxSerialConnection->SuspendLayout();
			this->gbxNetConnect->SuspendLayout();
			this->tabSignal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chtSignal))->BeginInit();
			this->gpbxDAQControl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSamplesQty))->BeginInit();
			this->tabCommonCmd->SuspendLayout();
			this->gbxEcho->SuspendLayout();
			this->gbxInstReading->SuspendLayout();
			this->tabConfig->SuspendLayout();
			this->gpbxConfigRes->SuspendLayout();
			this->gpbxTrafos->SuspendLayout();
			this->SuspendLayout();
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->stLabelConnection,
					this->stLabelNetConnection
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 639);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 19, 0);
			this->statusStrip1->Size = System::Drawing::Size(920, 26);
			this->statusStrip1->TabIndex = 15;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// stLabelConnection
			// 
			this->stLabelConnection->Name = L"stLabelConnection";
			this->stLabelConnection->Size = System::Drawing::Size(104, 20);
			this->stLabelConnection->Text = L"Desconectado";
			// 
			// stLabelNetConnection
			// 
			this->stLabelNetConnection->Name = L"stLabelNetConnection";
			this->stLabelNetConnection->Size = System::Drawing::Size(151, 20);
			this->stLabelNetConnection->Text = L"toolStripStatusLabel1";
			// 
			// tabCtrlApplication
			// 
			this->tabCtrlApplication->Controls->Add(this->tabModule);
			this->tabCtrlApplication->Controls->Add(this->tabSignal);
			this->tabCtrlApplication->Controls->Add(this->tabCommonCmd);
			this->tabCtrlApplication->Controls->Add(this->tabConfig);
			this->tabCtrlApplication->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabCtrlApplication->Location = System::Drawing::Point(0, 0);
			this->tabCtrlApplication->Margin = System::Windows::Forms::Padding(4);
			this->tabCtrlApplication->Name = L"tabCtrlApplication";
			this->tabCtrlApplication->SelectedIndex = 0;
			this->tabCtrlApplication->Size = System::Drawing::Size(920, 639);
			this->tabCtrlApplication->TabIndex = 16;
			this->tabCtrlApplication->TabStop = false;
			// 
			// tabModule
			// 
			this->tabModule->BackColor = System::Drawing::SystemColors::Control;
			this->tabModule->Controls->Add(this->gbxNetConfig);
			this->tabModule->Controls->Add(this->txtMessages);
			this->tabModule->Controls->Add(this->btnTxtClear);
			this->tabModule->Controls->Add(this->gbxSerialConnection);
			this->tabModule->Controls->Add(this->gbxNetConnect);
			this->tabModule->Location = System::Drawing::Point(4, 25);
			this->tabModule->Margin = System::Windows::Forms::Padding(4);
			this->tabModule->Name = L"tabModule";
			this->tabModule->Padding = System::Windows::Forms::Padding(4);
			this->tabModule->Size = System::Drawing::Size(912, 610);
			this->tabModule->TabIndex = 0;
			this->tabModule->Text = L"Módulo";
			// 
			// gbxNetConfig
			// 
			this->gbxNetConfig->Controls->Add(this->btnChangeSSID);
			this->gbxNetConfig->Controls->Add(this->btnChangePassword);
			this->gbxNetConfig->Controls->Add(this->txtPassword);
			this->gbxNetConfig->Controls->Add(this->txtSSID);
			this->gbxNetConfig->Controls->Add(this->lblPassword);
			this->gbxNetConfig->Controls->Add(this->lblSSID);
			this->gbxNetConfig->Location = System::Drawing::Point(8, 93);
			this->gbxNetConfig->Name = L"gbxNetConfig";
			this->gbxNetConfig->Size = System::Drawing::Size(890, 93);
			this->gbxNetConfig->TabIndex = 26;
			this->gbxNetConfig->TabStop = false;
			this->gbxNetConfig->Text = L"Configurações de adaptador de rede";
			// 
			// btnChangeSSID
			// 
			this->btnChangeSSID->Location = System::Drawing::Point(423, 25);
			this->btnChangeSSID->Name = L"btnChangeSSID";
			this->btnChangeSSID->Size = System::Drawing::Size(190, 23);
			this->btnChangeSSID->TabIndex = 3;
			this->btnChangeSSID->Text = L"Alterar configurações";
			this->btnChangeSSID->UseVisualStyleBackColor = true;
			this->btnChangeSSID->Click += gcnew System::EventHandler(this, &MainForm::btnChangeSSID_Click);
			// 
			// btnChangePassword
			// 
			this->btnChangePassword->Location = System::Drawing::Point(423, 54);
			this->btnChangePassword->Name = L"btnChangePassword";
			this->btnChangePassword->Size = System::Drawing::Size(190, 23);
			this->btnChangePassword->TabIndex = 5;
			this->btnChangePassword->Text = L"Alterar configurações";
			this->btnChangePassword->UseVisualStyleBackColor = true;
			this->btnChangePassword->Click += gcnew System::EventHandler(this, &MainForm::btnChangePassword_Click);
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(80, 54);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(322, 22);
			this->txtPassword->TabIndex = 4;
			// 
			// txtSSID
			// 
			this->txtSSID->Location = System::Drawing::Point(80, 26);
			this->txtSSID->Name = L"txtSSID";
			this->txtSSID->Size = System::Drawing::Size(322, 22);
			this->txtSSID->TabIndex = 2;
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(22, 57);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(49, 16);
			this->lblPassword->TabIndex = 1;
			this->lblPassword->Text = L"Senha:";
			// 
			// lblSSID
			// 
			this->lblSSID->AutoSize = true;
			this->lblSSID->Location = System::Drawing::Point(22, 29);
			this->lblSSID->Name = L"lblSSID";
			this->lblSSID->Size = System::Drawing::Size(41, 16);
			this->lblSSID->TabIndex = 0;
			this->lblSSID->Text = L"SSID:";
			// 
			// txtMessages
			// 
			this->txtMessages->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtMessages->Enabled = false;
			this->txtMessages->Location = System::Drawing::Point(9, 266);
			this->txtMessages->Margin = System::Windows::Forms::Padding(4);
			this->txtMessages->Multiline = true;
			this->txtMessages->Name = L"txtMessages";
			this->txtMessages->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtMessages->Size = System::Drawing::Size(895, 302);
			this->txtMessages->TabIndex = 13;
			// 
			// btnTxtClear
			// 
			this->btnTxtClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnTxtClear->Enabled = false;
			this->btnTxtClear->Location = System::Drawing::Point(741, 575);
			this->btnTxtClear->Name = L"btnTxtClear";
			this->btnTxtClear->Size = System::Drawing::Size(163, 28);
			this->btnTxtClear->TabIndex = 14;
			this->btnTxtClear->Text = L"Limpar caixa de texto";
			this->btnTxtClear->UseVisualStyleBackColor = true;
			this->btnTxtClear->Click += gcnew System::EventHandler(this, &MainForm::btnTxtClear_Click);
			// 
			// gbxSerialConnection
			// 
			this->gbxSerialConnection->Controls->Add(this->cmboxSerialPorts);
			this->gbxSerialConnection->Controls->Add(this->btnConnect);
			this->gbxSerialConnection->Location = System::Drawing::Point(7, 7);
			this->gbxSerialConnection->Name = L"gbxSerialConnection";
			this->gbxSerialConnection->Size = System::Drawing::Size(891, 80);
			this->gbxSerialConnection->TabIndex = 25;
			this->gbxSerialConnection->TabStop = false;
			this->gbxSerialConnection->Text = L"Conexão com a placa por USB";
			// 
			// cmboxSerialPorts
			// 
			this->cmboxSerialPorts->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmboxSerialPorts->FormattingEnabled = true;
			this->cmboxSerialPorts->Location = System::Drawing::Point(18, 33);
			this->cmboxSerialPorts->Margin = System::Windows::Forms::Padding(4);
			this->cmboxSerialPorts->Name = L"cmboxSerialPorts";
			this->cmboxSerialPorts->Size = System::Drawing::Size(207, 24);
			this->cmboxSerialPorts->TabIndex = 0;
			this->cmboxSerialPorts->Click += gcnew System::EventHandler(this, &MainForm::cmboxSerialPorts_Click);
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(234, 33);
			this->btnConnect->Margin = System::Windows::Forms::Padding(4);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(113, 28);
			this->btnConnect->TabIndex = 1;
			this->btnConnect->Text = L"Conectar";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &MainForm::btnConnect_Click);
			// 
			// gbxNetConnect
			// 
			this->gbxNetConnect->Controls->Add(this->btnSearch);
			this->gbxNetConnect->Controls->Add(this->btnNetConnect);
			this->gbxNetConnect->Controls->Add(this->txtPort);
			this->gbxNetConnect->Controls->Add(this->lblPoint4);
			this->gbxNetConnect->Controls->Add(this->lblPoint3);
			this->gbxNetConnect->Controls->Add(this->lblPoint2);
			this->gbxNetConnect->Controls->Add(this->lblPoint1);
			this->gbxNetConnect->Controls->Add(this->txtIP4);
			this->gbxNetConnect->Controls->Add(this->txtIP3);
			this->gbxNetConnect->Controls->Add(this->txtIP2);
			this->gbxNetConnect->Controls->Add(this->txtIP1);
			this->gbxNetConnect->Controls->Add(this->lblNetConnect);
			this->gbxNetConnect->Location = System::Drawing::Point(9, 192);
			this->gbxNetConnect->Name = L"gbxNetConnect";
			this->gbxNetConnect->Size = System::Drawing::Size(891, 67);
			this->gbxNetConnect->TabIndex = 27;
			this->gbxNetConnect->TabStop = false;
			this->gbxNetConnect->Text = L"Conexão wireless com a placa";
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(529, 25);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(175, 23);
			this->btnSearch->TabIndex = 12;
			this->btnSearch->Text = L"Procurar e conectar";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MainForm::btnSearch_Click);
			// 
			// btnNetConnect
			// 
			this->btnNetConnect->Location = System::Drawing::Point(407, 25);
			this->btnNetConnect->Name = L"btnNetConnect";
			this->btnNetConnect->Size = System::Drawing::Size(116, 23);
			this->btnNetConnect->TabIndex = 11;
			this->btnNetConnect->Text = L"Conectar";
			this->btnNetConnect->UseVisualStyleBackColor = true;
			this->btnNetConnect->Click += gcnew System::EventHandler(this, &MainForm::btnNetConnect_Click);
			// 
			// txtPort
			// 
			this->txtPort->Location = System::Drawing::Point(327, 25);
			this->txtPort->Name = L"txtPort";
			this->txtPort->Size = System::Drawing::Size(74, 22);
			this->txtPort->TabIndex = 10;
			// 
			// lblPoint4
			// 
			this->lblPoint4->AutoSize = true;
			this->lblPoint4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoint4->Location = System::Drawing::Point(308, 26);
			this->lblPoint4->Name = L"lblPoint4";
			this->lblPoint4->Size = System::Drawing::Size(15, 20);
			this->lblPoint4->TabIndex = 8;
			this->lblPoint4->Text = L":";
			// 
			// lblPoint3
			// 
			this->lblPoint3->AutoSize = true;
			this->lblPoint3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoint3->Location = System::Drawing::Point(236, 26);
			this->lblPoint3->Name = L"lblPoint3";
			this->lblPoint3->Size = System::Drawing::Size(14, 20);
			this->lblPoint3->TabIndex = 7;
			this->lblPoint3->Text = L".";
			// 
			// lblPoint2
			// 
			this->lblPoint2->AutoSize = true;
			this->lblPoint2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoint2->Location = System::Drawing::Point(165, 26);
			this->lblPoint2->Name = L"lblPoint2";
			this->lblPoint2->Size = System::Drawing::Size(14, 20);
			this->lblPoint2->TabIndex = 6;
			this->lblPoint2->Text = L".";
			// 
			// lblPoint1
			// 
			this->lblPoint1->AutoSize = true;
			this->lblPoint1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPoint1->Location = System::Drawing::Point(95, 25);
			this->lblPoint1->Name = L"lblPoint1";
			this->lblPoint1->Size = System::Drawing::Size(14, 20);
			this->lblPoint1->TabIndex = 5;
			this->lblPoint1->Text = L".";
			// 
			// txtIP4
			// 
			this->txtIP4->Location = System::Drawing::Point(254, 25);
			this->txtIP4->Name = L"txtIP4";
			this->txtIP4->Size = System::Drawing::Size(50, 22);
			this->txtIP4->TabIndex = 9;
			// 
			// txtIP3
			// 
			this->txtIP3->Location = System::Drawing::Point(183, 25);
			this->txtIP3->Name = L"txtIP3";
			this->txtIP3->Size = System::Drawing::Size(50, 22);
			this->txtIP3->TabIndex = 8;
			// 
			// txtIP2
			// 
			this->txtIP2->Location = System::Drawing::Point(112, 25);
			this->txtIP2->Name = L"txtIP2";
			this->txtIP2->Size = System::Drawing::Size(50, 22);
			this->txtIP2->TabIndex = 7;
			// 
			// txtIP1
			// 
			this->txtIP1->Location = System::Drawing::Point(43, 25);
			this->txtIP1->Name = L"txtIP1";
			this->txtIP1->Size = System::Drawing::Size(50, 22);
			this->txtIP1->TabIndex = 6;
			// 
			// lblNetConnect
			// 
			this->lblNetConnect->AutoSize = true;
			this->lblNetConnect->Location = System::Drawing::Point(15, 28);
			this->lblNetConnect->Name = L"lblNetConnect";
			this->lblNetConnect->Size = System::Drawing::Size(22, 16);
			this->lblNetConnect->TabIndex = 0;
			this->lblNetConnect->Text = L"IP:";
			// 
			// tabSignal
			// 
			this->tabSignal->BackColor = System::Drawing::SystemColors::Control;
			this->tabSignal->Controls->Add(this->chtSignal);
			this->tabSignal->Controls->Add(this->gpbxDAQControl);
			this->tabSignal->Location = System::Drawing::Point(4, 25);
			this->tabSignal->Margin = System::Windows::Forms::Padding(4);
			this->tabSignal->Name = L"tabSignal";
			this->tabSignal->Padding = System::Windows::Forms::Padding(4);
			this->tabSignal->Size = System::Drawing::Size(912, 610);
			this->tabSignal->TabIndex = 1;
			this->tabSignal->Text = L"Amostragem de Sinais";
			// 
			// chtSignal
			// 
			this->chtSignal->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->AxisX->Minimum = 0;
			chartArea1->AxisX->Title = L"Tempo (s)";
			chartArea1->AxisY->Title = L"Valores - Tensão(V), Corrente(A), Potência(VA)";
			chartArea1->Name = L"Sinais";
			this->chtSignal->ChartAreas->Add(chartArea1);
			this->chtSignal->Enabled = false;
			legend1->Name = L"Legenda";
			this->chtSignal->Legends->Add(legend1);
			this->chtSignal->Location = System::Drawing::Point(4, 114);
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
			series7->ChartArea = L"Sinais";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series7->Legend = L"Legenda";
			series7->Name = L"Potencia1";
			series8->ChartArea = L"Sinais";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series8->Legend = L"Legenda";
			series8->Name = L"Potencia2";
			series9->ChartArea = L"Sinais";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series9->Legend = L"Legenda";
			series9->Name = L"Potencia3";
			this->chtSignal->Series->Add(series1);
			this->chtSignal->Series->Add(series2);
			this->chtSignal->Series->Add(series3);
			this->chtSignal->Series->Add(series4);
			this->chtSignal->Series->Add(series5);
			this->chtSignal->Series->Add(series6);
			this->chtSignal->Series->Add(series7);
			this->chtSignal->Series->Add(series8);
			this->chtSignal->Series->Add(series9);
			this->chtSignal->Size = System::Drawing::Size(902, 489);
			this->chtSignal->TabIndex = 29;
			this->chtSignal->TabStop = false;
			this->chtSignal->Text = L"chart1";
			// 
			// gpbxDAQControl
			// 
			this->gpbxDAQControl->Controls->Add(this->nudSamplesQty);
			this->gpbxDAQControl->Controls->Add(this->lblSamplesQty);
			this->gpbxDAQControl->Controls->Add(this->cbxPotencia3);
			this->gpbxDAQControl->Controls->Add(this->cbxPotencia2);
			this->gpbxDAQControl->Controls->Add(this->cbxPotencia1);
			this->gpbxDAQControl->Controls->Add(this->btnSave);
			this->gpbxDAQControl->Controls->Add(this->cbxResolution);
			this->gpbxDAQControl->Controls->Add(this->lblResolution);
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
			this->gpbxDAQControl->Size = System::Drawing::Size(904, 102);
			this->gpbxDAQControl->TabIndex = 28;
			this->gpbxDAQControl->TabStop = false;
			this->gpbxDAQControl->Text = L"Controle de aquisição de dados";
			// 
			// nudSamplesQty
			// 
			this->nudSamplesQty->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->nudSamplesQty->Location = System::Drawing::Point(178, 26);
			this->nudSamplesQty->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudSamplesQty->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->nudSamplesQty->Name = L"nudSamplesQty";
			this->nudSamplesQty->ReadOnly = true;
			this->nudSamplesQty->Size = System::Drawing::Size(120, 22);
			this->nudSamplesQty->TabIndex = 0;
			this->nudSamplesQty->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			// 
			// lblSamplesQty
			// 
			this->lblSamplesQty->AutoSize = true;
			this->lblSamplesQty->Location = System::Drawing::Point(7, 28);
			this->lblSamplesQty->Name = L"lblSamplesQty";
			this->lblSamplesQty->Size = System::Drawing::Size(158, 16);
			this->lblSamplesQty->TabIndex = 35;
			this->lblSamplesQty->Text = L"Quantidade de amostras:";
			// 
			// cbxPotencia3
			// 
			this->cbxPotencia3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxPotencia3->AutoSize = true;
			this->cbxPotencia3->Checked = true;
			this->cbxPotencia3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxPotencia3->Location = System::Drawing::Point(794, 73);
			this->cbxPotencia3->Name = L"cbxPotencia3";
			this->cbxPotencia3->Size = System::Drawing::Size(92, 20);
			this->cbxPotencia3->TabIndex = 13;
			this->cbxPotencia3->Text = L"Potência 3";
			this->cbxPotencia3->UseVisualStyleBackColor = true;
			this->cbxPotencia3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxPotencia3_CheckedChanged);
			// 
			// cbxPotencia2
			// 
			this->cbxPotencia2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxPotencia2->AutoSize = true;
			this->cbxPotencia2->Checked = true;
			this->cbxPotencia2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxPotencia2->Location = System::Drawing::Point(698, 73);
			this->cbxPotencia2->Name = L"cbxPotencia2";
			this->cbxPotencia2->Size = System::Drawing::Size(92, 20);
			this->cbxPotencia2->TabIndex = 12;
			this->cbxPotencia2->Text = L"Potência 2";
			this->cbxPotencia2->UseVisualStyleBackColor = true;
			this->cbxPotencia2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxPotencia2_CheckedChanged);
			// 
			// cbxPotencia1
			// 
			this->cbxPotencia1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxPotencia1->AutoSize = true;
			this->cbxPotencia1->Checked = true;
			this->cbxPotencia1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxPotencia1->Location = System::Drawing::Point(602, 73);
			this->cbxPotencia1->Name = L"cbxPotencia1";
			this->cbxPotencia1->Size = System::Drawing::Size(92, 20);
			this->cbxPotencia1->TabIndex = 11;
			this->cbxPotencia1->Text = L"Potência 1";
			this->cbxPotencia1->UseVisualStyleBackColor = true;
			this->cbxPotencia1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxPotencia1_CheckedChanged);
			// 
			// btnSave
			// 
			this->btnSave->Enabled = false;
			this->btnSave->Location = System::Drawing::Point(310, 53);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(127, 25);
			this->btnSave->TabIndex = 3;
			this->btnSave->Text = L"Salvar pontos";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
			// 
			// cbxResolution
			// 
			this->cbxResolution->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxResolution->FormattingEnabled = true;
			this->cbxResolution->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"100", L"200", L"300", L"400", L"500", L"600",
					L"700", L"800", L"900", L"1000"
			});
			this->cbxResolution->Location = System::Drawing::Point(178, 54);
			this->cbxResolution->Name = L"cbxResolution";
			this->cbxResolution->Size = System::Drawing::Size(121, 24);
			this->cbxResolution->TabIndex = 2;
			this->cbxResolution->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cbxResolution_SelectedIndexChanged);
			// 
			// lblResolution
			// 
			this->lblResolution->AutoSize = true;
			this->lblResolution->Location = System::Drawing::Point(7, 57);
			this->lblResolution->Name = L"lblResolution";
			this->lblResolution->Size = System::Drawing::Size(165, 16);
			this->lblResolution->TabIndex = 29;
			this->lblResolution->Text = L"Resolução de tempo (ms):";
			// 
			// cbxCorrente3
			// 
			this->cbxCorrente3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxCorrente3->AutoSize = true;
			this->cbxCorrente3->Checked = true;
			this->cbxCorrente3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxCorrente3->Location = System::Drawing::Point(794, 47);
			this->cbxCorrente3->Name = L"cbxCorrente3";
			this->cbxCorrente3->Size = System::Drawing::Size(90, 20);
			this->cbxCorrente3->TabIndex = 10;
			this->cbxCorrente3->Text = L"Corrente 3";
			this->cbxCorrente3->UseVisualStyleBackColor = true;
			this->cbxCorrente3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxCorrente3_CheckedChanged);
			// 
			// cbxCorrente2
			// 
			this->cbxCorrente2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxCorrente2->AutoSize = true;
			this->cbxCorrente2->Checked = true;
			this->cbxCorrente2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxCorrente2->Location = System::Drawing::Point(698, 47);
			this->cbxCorrente2->Name = L"cbxCorrente2";
			this->cbxCorrente2->Size = System::Drawing::Size(90, 20);
			this->cbxCorrente2->TabIndex = 9;
			this->cbxCorrente2->Text = L"Corrente 2";
			this->cbxCorrente2->UseVisualStyleBackColor = true;
			this->cbxCorrente2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxCorrente2_CheckedChanged);
			// 
			// cbxCorrente1
			// 
			this->cbxCorrente1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxCorrente1->AutoSize = true;
			this->cbxCorrente1->Checked = true;
			this->cbxCorrente1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxCorrente1->Location = System::Drawing::Point(602, 47);
			this->cbxCorrente1->Name = L"cbxCorrente1";
			this->cbxCorrente1->Size = System::Drawing::Size(90, 20);
			this->cbxCorrente1->TabIndex = 8;
			this->cbxCorrente1->Text = L"Corrente 1";
			this->cbxCorrente1->UseVisualStyleBackColor = true;
			this->cbxCorrente1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxCorrente1_CheckedChanged);
			// 
			// cbxTensao3
			// 
			this->cbxTensao3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxTensao3->AutoSize = true;
			this->cbxTensao3->Checked = true;
			this->cbxTensao3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxTensao3->Location = System::Drawing::Point(794, 22);
			this->cbxTensao3->Name = L"cbxTensao3";
			this->cbxTensao3->Size = System::Drawing::Size(86, 20);
			this->cbxTensao3->TabIndex = 7;
			this->cbxTensao3->Text = L"Tensão 3";
			this->cbxTensao3->UseVisualStyleBackColor = true;
			this->cbxTensao3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxTensao3_CheckedChanged);
			// 
			// cbxTensao2
			// 
			this->cbxTensao2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxTensao2->AutoSize = true;
			this->cbxTensao2->Checked = true;
			this->cbxTensao2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxTensao2->Location = System::Drawing::Point(698, 22);
			this->cbxTensao2->Name = L"cbxTensao2";
			this->cbxTensao2->Size = System::Drawing::Size(86, 20);
			this->cbxTensao2->TabIndex = 6;
			this->cbxTensao2->Text = L"Tensão 2";
			this->cbxTensao2->UseVisualStyleBackColor = true;
			this->cbxTensao2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxTensao2_CheckedChanged);
			// 
			// cbxTensao1
			// 
			this->cbxTensao1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbxTensao1->AutoSize = true;
			this->cbxTensao1->Checked = true;
			this->cbxTensao1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbxTensao1->Location = System::Drawing::Point(602, 22);
			this->cbxTensao1->Name = L"cbxTensao1";
			this->cbxTensao1->Size = System::Drawing::Size(86, 20);
			this->cbxTensao1->TabIndex = 5;
			this->cbxTensao1->Text = L"Tensão 1";
			this->cbxTensao1->UseVisualStyleBackColor = true;
			this->cbxTensao1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbxTensao1_CheckedChanged);
			// 
			// btnClear
			// 
			this->btnClear->Enabled = false;
			this->btnClear->Location = System::Drawing::Point(443, 53);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(127, 25);
			this->btnClear->TabIndex = 4;
			this->btnClear->Text = L"Limpar gráfico";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MainForm::btnClear_Click);
			// 
			// btnGetSamples
			// 
			this->btnGetSamples->Location = System::Drawing::Point(310, 24);
			this->btnGetSamples->Margin = System::Windows::Forms::Padding(4);
			this->btnGetSamples->Name = L"btnGetSamples";
			this->btnGetSamples->Size = System::Drawing::Size(127, 25);
			this->btnGetSamples->TabIndex = 1;
			this->btnGetSamples->Text = L"Adquirir amostras";
			this->btnGetSamples->UseVisualStyleBackColor = true;
			this->btnGetSamples->Click += gcnew System::EventHandler(this, &MainForm::btnGetSamples_Click);
			// 
			// tabCommonCmd
			// 
			this->tabCommonCmd->BackColor = System::Drawing::SystemColors::Control;
			this->tabCommonCmd->Controls->Add(this->gbxEcho);
			this->tabCommonCmd->Controls->Add(this->gbxInstReading);
			this->tabCommonCmd->Location = System::Drawing::Point(4, 25);
			this->tabCommonCmd->Margin = System::Windows::Forms::Padding(4);
			this->tabCommonCmd->Name = L"tabCommonCmd";
			this->tabCommonCmd->Size = System::Drawing::Size(912, 610);
			this->tabCommonCmd->TabIndex = 2;
			this->tabCommonCmd->Text = L"Comandos comuns";
			// 
			// gbxEcho
			// 
			this->gbxEcho->Controls->Add(this->lblEcho);
			this->gbxEcho->Controls->Add(this->txtSendMessage);
			this->gbxEcho->Controls->Add(this->btnSendEcho);
			this->gbxEcho->Location = System::Drawing::Point(8, 182);
			this->gbxEcho->Name = L"gbxEcho";
			this->gbxEcho->Size = System::Drawing::Size(896, 71);
			this->gbxEcho->TabIndex = 30;
			this->gbxEcho->TabStop = false;
			this->gbxEcho->Text = L"Ecoar mensagem";
			// 
			// lblEcho
			// 
			this->lblEcho->AutoSize = true;
			this->lblEcho->Enabled = false;
			this->lblEcho->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEcho->Location = System::Drawing::Point(7, 28);
			this->lblEcho->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblEcho->Name = L"lblEcho";
			this->lblEcho->Size = System::Drawing::Size(99, 20);
			this->lblEcho->TabIndex = 26;
			this->lblEcho->Text = L"Ecoar texto:";
			// 
			// txtSendMessage
			// 
			this->txtSendMessage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtSendMessage->Enabled = false;
			this->txtSendMessage->Location = System::Drawing::Point(119, 25);
			this->txtSendMessage->Margin = System::Windows::Forms::Padding(4);
			this->txtSendMessage->Name = L"txtSendMessage";
			this->txtSendMessage->Size = System::Drawing::Size(659, 22);
			this->txtSendMessage->TabIndex = 3;
			// 
			// btnSendEcho
			// 
			this->btnSendEcho->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnSendEcho->Enabled = false;
			this->btnSendEcho->Location = System::Drawing::Point(787, 22);
			this->btnSendEcho->Margin = System::Windows::Forms::Padding(4);
			this->btnSendEcho->Name = L"btnSendEcho";
			this->btnSendEcho->Size = System::Drawing::Size(100, 28);
			this->btnSendEcho->TabIndex = 4;
			this->btnSendEcho->Text = L"Enviar";
			this->btnSendEcho->UseVisualStyleBackColor = true;
			this->btnSendEcho->Click += gcnew System::EventHandler(this, &MainForm::btnSendEcho_Click);
			// 
			// gbxInstReading
			// 
			this->gbxInstReading->Controls->Add(this->btnReset);
			this->gbxInstReading->Controls->Add(this->lblADCSelection);
			this->gbxInstReading->Controls->Add(this->lblADCReading);
			this->gbxInstReading->Controls->Add(this->btnLeitura);
			this->gbxInstReading->Controls->Add(this->lblADCReadingValue);
			this->gbxInstReading->Controls->Add(this->cmboxADCSelection);
			this->gbxInstReading->Controls->Add(this->lblLeitura);
			this->gbxInstReading->Controls->Add(this->lblAnalogReading);
			this->gbxInstReading->Location = System::Drawing::Point(8, 3);
			this->gbxInstReading->Name = L"gbxInstReading";
			this->gbxInstReading->Size = System::Drawing::Size(896, 173);
			this->gbxInstReading->TabIndex = 29;
			this->gbxInstReading->TabStop = false;
			this->gbxInstReading->Text = L"Leitura instantânea";
			// 
			// btnReset
			// 
			this->btnReset->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnReset->Location = System::Drawing::Point(739, 33);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(148, 23);
			this->btnReset->TabIndex = 2;
			this->btnReset->Text = L"Resetar módulo";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &MainForm::btnReset_Click);
			// 
			// lblADCSelection
			// 
			this->lblADCSelection->AutoSize = true;
			this->lblADCSelection->Enabled = false;
			this->lblADCSelection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblADCSelection->Location = System::Drawing::Point(7, 33);
			this->lblADCSelection->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblADCSelection->Name = L"lblADCSelection";
			this->lblADCSelection->Size = System::Drawing::Size(51, 20);
			this->lblADCSelection->TabIndex = 23;
			this->lblADCSelection->Text = L"Sinal:";
			// 
			// lblADCReading
			// 
			this->lblADCReading->AutoSize = true;
			this->lblADCReading->Enabled = false;
			this->lblADCReading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblADCReading->Location = System::Drawing::Point(6, 79);
			this->lblADCReading->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblADCReading->Name = L"lblADCReading";
			this->lblADCReading->Size = System::Drawing::Size(204, 38);
			this->lblADCReading->TabIndex = 28;
			this->lblADCReading->Text = L"Leitura ADC:";
			// 
			// btnLeitura
			// 
			this->btnLeitura->Enabled = false;
			this->btnLeitura->Location = System::Drawing::Point(189, 30);
			this->btnLeitura->Margin = System::Windows::Forms::Padding(4);
			this->btnLeitura->Name = L"btnLeitura";
			this->btnLeitura->Size = System::Drawing::Size(120, 28);
			this->btnLeitura->TabIndex = 1;
			this->btnLeitura->Text = L"Obter valor";
			this->btnLeitura->UseVisualStyleBackColor = true;
			this->btnLeitura->Click += gcnew System::EventHandler(this, &MainForm::btnLeitura_Click);
			// 
			// lblADCReadingValue
			// 
			this->lblADCReadingValue->AutoSize = true;
			this->lblADCReadingValue->Enabled = false;
			this->lblADCReadingValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblADCReadingValue->ForeColor = System::Drawing::Color::Red;
			this->lblADCReadingValue->Location = System::Drawing::Point(300, 79);
			this->lblADCReadingValue->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblADCReadingValue->Name = L"lblADCReadingValue";
			this->lblADCReadingValue->Size = System::Drawing::Size(66, 38);
			this->lblADCReadingValue->TabIndex = 27;
			this->lblADCReadingValue->Text = L"\? V";
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
			this->cmboxADCSelection->Location = System::Drawing::Point(63, 30);
			this->cmboxADCSelection->Margin = System::Windows::Forms::Padding(4);
			this->cmboxADCSelection->Name = L"cmboxADCSelection";
			this->cmboxADCSelection->Size = System::Drawing::Size(117, 24);
			this->cmboxADCSelection->TabIndex = 0;
			// 
			// lblLeitura
			// 
			this->lblLeitura->AutoSize = true;
			this->lblLeitura->Enabled = false;
			this->lblLeitura->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLeitura->Location = System::Drawing::Point(6, 118);
			this->lblLeitura->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblLeitura->Name = L"lblLeitura";
			this->lblLeitura->Size = System::Drawing::Size(273, 38);
			this->lblLeitura->TabIndex = 26;
			this->lblLeitura->Text = L"Leitura Calibrada:";
			// 
			// lblAnalogReading
			// 
			this->lblAnalogReading->AutoSize = true;
			this->lblAnalogReading->Enabled = false;
			this->lblAnalogReading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblAnalogReading->ForeColor = System::Drawing::Color::Red;
			this->lblAnalogReading->Location = System::Drawing::Point(300, 118);
			this->lblAnalogReading->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblAnalogReading->Name = L"lblAnalogReading";
			this->lblAnalogReading->Size = System::Drawing::Size(66, 38);
			this->lblAnalogReading->TabIndex = 25;
			this->lblAnalogReading->Text = L"\? V";
			// 
			// tabConfig
			// 
			this->tabConfig->BackColor = System::Drawing::SystemColors::Control;
			this->tabConfig->Controls->Add(this->gpbxConfigRes);
			this->tabConfig->Controls->Add(this->gpbxTrafos);
			this->tabConfig->Location = System::Drawing::Point(4, 25);
			this->tabConfig->Name = L"tabConfig";
			this->tabConfig->Size = System::Drawing::Size(912, 610);
			this->tabConfig->TabIndex = 3;
			this->tabConfig->Text = L"Calibração de sensores";
			// 
			// gpbxConfigRes
			// 
			this->gpbxConfigRes->Controls->Add(this->lblRes6);
			this->gpbxConfigRes->Controls->Add(this->txtRes6);
			this->gpbxConfigRes->Controls->Add(this->lblRes7);
			this->gpbxConfigRes->Controls->Add(this->txtRes7);
			this->gpbxConfigRes->Controls->Add(this->lblRes8);
			this->gpbxConfigRes->Controls->Add(this->txtRes8);
			this->gpbxConfigRes->Controls->Add(this->lblRes9);
			this->gpbxConfigRes->Controls->Add(this->txtRes3);
			this->gpbxConfigRes->Controls->Add(this->txtRes9);
			this->gpbxConfigRes->Controls->Add(this->lblRes3);
			this->gpbxConfigRes->Controls->Add(this->lblRes10);
			this->gpbxConfigRes->Controls->Add(this->txtRes2);
			this->gpbxConfigRes->Controls->Add(this->txtRes10);
			this->gpbxConfigRes->Controls->Add(this->lblRes2);
			this->gpbxConfigRes->Controls->Add(this->lblRes11);
			this->gpbxConfigRes->Controls->Add(this->txtRes1);
			this->gpbxConfigRes->Controls->Add(this->txtRes11);
			this->gpbxConfigRes->Controls->Add(this->lblRes1);
			this->gpbxConfigRes->Location = System::Drawing::Point(8, 313);
			this->gpbxConfigRes->Name = L"gpbxConfigRes";
			this->gpbxConfigRes->Size = System::Drawing::Size(896, 197);
			this->gpbxConfigRes->TabIndex = 25;
			this->gpbxConfigRes->TabStop = false;
			this->gpbxConfigRes->Text = L"Configurações de resistores";
			// 
			// lblRes6
			// 
			this->lblRes6->AutoSize = true;
			this->lblRes6->Location = System::Drawing::Point(6, 24);
			this->lblRes6->Name = L"lblRes6";
			this->lblRes6->Size = System::Drawing::Size(115, 16);
			this->lblRes6->TabIndex = 24;
			this->lblRes6->Text = L"Valor R6 (kOhms):";
			// 
			// txtRes6
			// 
			this->txtRes6->Location = System::Drawing::Point(174, 18);
			this->txtRes6->Name = L"txtRes6";
			this->txtRes6->Size = System::Drawing::Size(124, 22);
			this->txtRes6->TabIndex = 18;
			this->txtRes6->Text = L"100";
			this->txtRes6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor1_ChangeValues);
			this->txtRes6->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor1_ChangeValues);
			// 
			// lblRes7
			// 
			this->lblRes7->AutoSize = true;
			this->lblRes7->Location = System::Drawing::Point(6, 52);
			this->lblRes7->Name = L"lblRes7";
			this->lblRes7->Size = System::Drawing::Size(115, 16);
			this->lblRes7->TabIndex = 26;
			this->lblRes7->Text = L"Valor R7 (kOhms):";
			// 
			// txtRes7
			// 
			this->txtRes7->Location = System::Drawing::Point(174, 46);
			this->txtRes7->Name = L"txtRes7";
			this->txtRes7->Size = System::Drawing::Size(124, 22);
			this->txtRes7->TabIndex = 19;
			this->txtRes7->Text = L"10";
			this->txtRes7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor1_ChangeValues);
			this->txtRes7->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor1_ChangeValues);
			// 
			// lblRes8
			// 
			this->lblRes8->AutoSize = true;
			this->lblRes8->Location = System::Drawing::Point(6, 80);
			this->lblRes8->Name = L"lblRes8";
			this->lblRes8->Size = System::Drawing::Size(115, 16);
			this->lblRes8->TabIndex = 28;
			this->lblRes8->Text = L"Valor R8 (kOhms):";
			// 
			// txtRes8
			// 
			this->txtRes8->Location = System::Drawing::Point(174, 74);
			this->txtRes8->Name = L"txtRes8";
			this->txtRes8->Size = System::Drawing::Size(124, 22);
			this->txtRes8->TabIndex = 20;
			this->txtRes8->Text = L"100";
			this->txtRes8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor2_ChangeValues);
			this->txtRes8->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor2_ChangeValues);
			// 
			// lblRes9
			// 
			this->lblRes9->AutoSize = true;
			this->lblRes9->Location = System::Drawing::Point(6, 108);
			this->lblRes9->Name = L"lblRes9";
			this->lblRes9->Size = System::Drawing::Size(115, 16);
			this->lblRes9->TabIndex = 30;
			this->lblRes9->Text = L"Valor R9 (kOhms):";
			// 
			// txtRes3
			// 
			this->txtRes3->Location = System::Drawing::Point(468, 74);
			this->txtRes3->Name = L"txtRes3";
			this->txtRes3->Size = System::Drawing::Size(117, 22);
			this->txtRes3->TabIndex = 26;
			this->txtRes3->Text = L"33";
			this->txtRes3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor3_ChangeValues);
			this->txtRes3->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor3_ChangeValues);
			// 
			// txtRes9
			// 
			this->txtRes9->Location = System::Drawing::Point(174, 102);
			this->txtRes9->Name = L"txtRes9";
			this->txtRes9->Size = System::Drawing::Size(124, 22);
			this->txtRes9->TabIndex = 21;
			this->txtRes9->Text = L"10";
			this->txtRes9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor2_ChangeValues);
			this->txtRes9->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor2_ChangeValues);
			// 
			// lblRes3
			// 
			this->lblRes3->AutoSize = true;
			this->lblRes3->Location = System::Drawing::Point(304, 80);
			this->lblRes3->Name = L"lblRes3";
			this->lblRes3->Size = System::Drawing::Size(108, 16);
			this->lblRes3->TabIndex = 40;
			this->lblRes3->Text = L"Valor R3 (Ohms):";
			// 
			// lblRes10
			// 
			this->lblRes10->AutoSize = true;
			this->lblRes10->Location = System::Drawing::Point(6, 136);
			this->lblRes10->Name = L"lblRes10";
			this->lblRes10->Size = System::Drawing::Size(122, 16);
			this->lblRes10->TabIndex = 32;
			this->lblRes10->Text = L"Valor R10 (kOhms):";
			// 
			// txtRes2
			// 
			this->txtRes2->Location = System::Drawing::Point(468, 46);
			this->txtRes2->Name = L"txtRes2";
			this->txtRes2->Size = System::Drawing::Size(117, 22);
			this->txtRes2->TabIndex = 25;
			this->txtRes2->Text = L"33";
			this->txtRes2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor2_ChangeValues);
			this->txtRes2->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor2_ChangeValues);
			// 
			// txtRes10
			// 
			this->txtRes10->Location = System::Drawing::Point(174, 130);
			this->txtRes10->Name = L"txtRes10";
			this->txtRes10->Size = System::Drawing::Size(124, 22);
			this->txtRes10->TabIndex = 22;
			this->txtRes10->Text = L"100";
			this->txtRes10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor3_ChangeValues);
			this->txtRes10->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor3_ChangeValues);
			// 
			// lblRes2
			// 
			this->lblRes2->AutoSize = true;
			this->lblRes2->Location = System::Drawing::Point(304, 52);
			this->lblRes2->Name = L"lblRes2";
			this->lblRes2->Size = System::Drawing::Size(108, 16);
			this->lblRes2->TabIndex = 38;
			this->lblRes2->Text = L"Valor R2 (Ohms):";
			// 
			// lblRes11
			// 
			this->lblRes11->AutoSize = true;
			this->lblRes11->Location = System::Drawing::Point(6, 164);
			this->lblRes11->Name = L"lblRes11";
			this->lblRes11->Size = System::Drawing::Size(122, 16);
			this->lblRes11->TabIndex = 34;
			this->lblRes11->Text = L"Valor R11 (kOhms):";
			// 
			// txtRes1
			// 
			this->txtRes1->Location = System::Drawing::Point(468, 18);
			this->txtRes1->Name = L"txtRes1";
			this->txtRes1->Size = System::Drawing::Size(117, 22);
			this->txtRes1->TabIndex = 24;
			this->txtRes1->Text = L"33";
			this->txtRes1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor1_ChangeValues);
			this->txtRes1->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor1_ChangeValues);
			// 
			// txtRes11
			// 
			this->txtRes11->Location = System::Drawing::Point(174, 158);
			this->txtRes11->Name = L"txtRes11";
			this->txtRes11->Size = System::Drawing::Size(124, 22);
			this->txtRes11->TabIndex = 23;
			this->txtRes11->Text = L"10";
			this->txtRes11->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor3_ChangeValues);
			this->txtRes11->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor3_ChangeValues);
			// 
			// lblRes1
			// 
			this->lblRes1->AutoSize = true;
			this->lblRes1->Location = System::Drawing::Point(304, 24);
			this->lblRes1->Name = L"lblRes1";
			this->lblRes1->Size = System::Drawing::Size(108, 16);
			this->lblRes1->TabIndex = 36;
			this->lblRes1->Text = L"Valor R1 (Ohms):";
			// 
			// gpbxTrafos
			// 
			this->gpbxTrafos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gpbxTrafos->Controls->Add(this->txtRefTC3);
			this->gpbxTrafos->Controls->Add(this->lblRefTC3);
			this->gpbxTrafos->Controls->Add(this->txtRefTC2);
			this->gpbxTrafos->Controls->Add(this->lblRefTC2);
			this->gpbxTrafos->Controls->Add(this->txtRefTC1);
			this->gpbxTrafos->Controls->Add(this->lblRefTC1);
			this->gpbxTrafos->Controls->Add(this->lblRefT3);
			this->gpbxTrafos->Controls->Add(this->txtRefT3);
			this->gpbxTrafos->Controls->Add(this->lblRefT2);
			this->gpbxTrafos->Controls->Add(this->txtRefT2);
			this->gpbxTrafos->Controls->Add(this->lblRefT1);
			this->gpbxTrafos->Controls->Add(this->txtRefT1);
			this->gpbxTrafos->Controls->Add(this->lblPrimarioT1);
			this->gpbxTrafos->Controls->Add(this->txtSecundarioTC3);
			this->gpbxTrafos->Controls->Add(this->txtPrimarioT1);
			this->gpbxTrafos->Controls->Add(this->lblSecundarioTC3);
			this->gpbxTrafos->Controls->Add(this->lblSecundarioT1);
			this->gpbxTrafos->Controls->Add(this->txtPrimarioTC3);
			this->gpbxTrafos->Controls->Add(this->txtSecundarioT1);
			this->gpbxTrafos->Controls->Add(this->lblPrimarioTC3);
			this->gpbxTrafos->Controls->Add(this->lblPrimarioT2);
			this->gpbxTrafos->Controls->Add(this->txtSecundarioTC2);
			this->gpbxTrafos->Controls->Add(this->txtPrimarioT2);
			this->gpbxTrafos->Controls->Add(this->lblSecundarioTC2);
			this->gpbxTrafos->Controls->Add(this->lblSecundarioT2);
			this->gpbxTrafos->Controls->Add(this->txtPrimarioTC2);
			this->gpbxTrafos->Controls->Add(this->txtSecundarioT2);
			this->gpbxTrafos->Controls->Add(this->lblPrimarioTC2);
			this->gpbxTrafos->Controls->Add(this->lblPrimarioT3);
			this->gpbxTrafos->Controls->Add(this->txtSecundarioTC1);
			this->gpbxTrafos->Controls->Add(this->txtPrimarioT3);
			this->gpbxTrafos->Controls->Add(this->lblSecundarioTC1);
			this->gpbxTrafos->Controls->Add(this->lblSecundarioT3);
			this->gpbxTrafos->Controls->Add(this->txtPrimarioTC1);
			this->gpbxTrafos->Controls->Add(this->txtSecundarioT3);
			this->gpbxTrafos->Controls->Add(this->lblPrimarioTC1);
			this->gpbxTrafos->Location = System::Drawing::Point(8, 3);
			this->gpbxTrafos->Name = L"gpbxTrafos";
			this->gpbxTrafos->Size = System::Drawing::Size(896, 304);
			this->gpbxTrafos->TabIndex = 24;
			this->gpbxTrafos->TabStop = false;
			this->gpbxTrafos->Text = L"Configuração de transformadores";
			// 
			// txtRefTC3
			// 
			this->txtRefTC3->Location = System::Drawing::Point(517, 266);
			this->txtRefTC3->Name = L"txtRefTC3";
			this->txtRefTC3->Size = System::Drawing::Size(68, 22);
			this->txtRefTC3->TabIndex = 17;
			this->txtRefTC3->Text = L"1,68";
			this->txtRefTC3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtRefTC3_Change);
			this->txtRefTC3->Leave += gcnew System::EventHandler(this, &MainForm::txtRefTC3_Change);
			// 
			// lblRefTC3
			// 
			this->lblRefTC3->AutoSize = true;
			this->lblRefTC3->Location = System::Drawing::Point(304, 269);
			this->lblRefTC3->Name = L"lblRefTC3";
			this->lblRefTC3->Size = System::Drawing::Size(187, 16);
			this->lblRefTC3->TabIndex = 34;
			this->lblRefTC3->Text = L"Tensão de referência TC3 (V):";
			// 
			// txtRefTC2
			// 
			this->txtRefTC2->Location = System::Drawing::Point(517, 238);
			this->txtRefTC2->Name = L"txtRefTC2";
			this->txtRefTC2->Size = System::Drawing::Size(68, 22);
			this->txtRefTC2->TabIndex = 16;
			this->txtRefTC2->Text = L"1,68";
			this->txtRefTC2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtRefTC2_Change);
			this->txtRefTC2->Leave += gcnew System::EventHandler(this, &MainForm::txtRefTC2_Change);
			// 
			// lblRefTC2
			// 
			this->lblRefTC2->AutoSize = true;
			this->lblRefTC2->Location = System::Drawing::Point(304, 241);
			this->lblRefTC2->Name = L"lblRefTC2";
			this->lblRefTC2->Size = System::Drawing::Size(187, 16);
			this->lblRefTC2->TabIndex = 32;
			this->lblRefTC2->Text = L"Tensão de referência TC2 (V):";
			// 
			// txtRefTC1
			// 
			this->txtRefTC1->Location = System::Drawing::Point(517, 210);
			this->txtRefTC1->Name = L"txtRefTC1";
			this->txtRefTC1->Size = System::Drawing::Size(68, 22);
			this->txtRefTC1->TabIndex = 15;
			this->txtRefTC1->Text = L"1,68";
			this->txtRefTC1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtRefTC1_Change);
			this->txtRefTC1->Leave += gcnew System::EventHandler(this, &MainForm::txtRefTC1_Change);
			// 
			// lblRefTC1
			// 
			this->lblRefTC1->AutoSize = true;
			this->lblRefTC1->Location = System::Drawing::Point(304, 213);
			this->lblRefTC1->Name = L"lblRefTC1";
			this->lblRefTC1->Size = System::Drawing::Size(187, 16);
			this->lblRefTC1->TabIndex = 30;
			this->lblRefTC1->Text = L"Tensão de referência TC1 (V):";
			// 
			// lblRefT3
			// 
			this->lblRefT3->AutoSize = true;
			this->lblRefT3->Location = System::Drawing::Point(6, 269);
			this->lblRefT3->Name = L"lblRefT3";
			this->lblRefT3->Size = System::Drawing::Size(178, 16);
			this->lblRefT3->TabIndex = 28;
			this->lblRefT3->Text = L"Tensão de referência T3 (V):";
			// 
			// txtRefT3
			// 
			this->txtRefT3->Location = System::Drawing::Point(230, 266);
			this->txtRefT3->Name = L"txtRefT3";
			this->txtRefT3->Size = System::Drawing::Size(68, 22);
			this->txtRefT3->TabIndex = 8;
			this->txtRefT3->Text = L"1,68";
			this->txtRefT3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtRefT3_Change);
			this->txtRefT3->Leave += gcnew System::EventHandler(this, &MainForm::txtRefT3_Change);
			// 
			// lblRefT2
			// 
			this->lblRefT2->AutoSize = true;
			this->lblRefT2->Location = System::Drawing::Point(6, 241);
			this->lblRefT2->Name = L"lblRefT2";
			this->lblRefT2->Size = System::Drawing::Size(178, 16);
			this->lblRefT2->TabIndex = 26;
			this->lblRefT2->Text = L"Tensão de referência T2 (V):";
			// 
			// txtRefT2
			// 
			this->txtRefT2->Location = System::Drawing::Point(230, 238);
			this->txtRefT2->Name = L"txtRefT2";
			this->txtRefT2->Size = System::Drawing::Size(68, 22);
			this->txtRefT2->TabIndex = 7;
			this->txtRefT2->Text = L"1,68";
			this->txtRefT2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtRefT2_Change);
			this->txtRefT2->Leave += gcnew System::EventHandler(this, &MainForm::txtRefT2_Change);
			// 
			// lblRefT1
			// 
			this->lblRefT1->AutoSize = true;
			this->lblRefT1->Location = System::Drawing::Point(6, 213);
			this->lblRefT1->Name = L"lblRefT1";
			this->lblRefT1->Size = System::Drawing::Size(178, 16);
			this->lblRefT1->TabIndex = 24;
			this->lblRefT1->Text = L"Tensão de referência T1 (V):";
			// 
			// txtRefT1
			// 
			this->txtRefT1->Location = System::Drawing::Point(230, 210);
			this->txtRefT1->Name = L"txtRefT1";
			this->txtRefT1->Size = System::Drawing::Size(68, 22);
			this->txtRefT1->TabIndex = 6;
			this->txtRefT1->Text = L"1,68";
			this->txtRefT1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::txtRefT1_Change);
			this->txtRefT1->Leave += gcnew System::EventHandler(this, &MainForm::txtRefT1_Change);
			// 
			// lblPrimarioT1
			// 
			this->lblPrimarioT1->AutoSize = true;
			this->lblPrimarioT1->Location = System::Drawing::Point(6, 29);
			this->lblPrimarioT1->Name = L"lblPrimarioT1";
			this->lblPrimarioT1->Size = System::Drawing::Size(189, 16);
			this->lblPrimarioT1->TabIndex = 0;
			this->lblPrimarioT1->Text = L"Tensão primário de T1 (Vrms):";
			// 
			// txtSecundarioTC3
			// 
			this->txtSecundarioTC3->Location = System::Drawing::Point(517, 166);
			this->txtSecundarioTC3->Name = L"txtSecundarioTC3";
			this->txtSecundarioTC3->Size = System::Drawing::Size(68, 22);
			this->txtSecundarioTC3->TabIndex = 14;
			this->txtSecundarioTC3->Text = L"0,05";
			this->txtSecundarioTC3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor3_ChangeValues);
			this->txtSecundarioTC3->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor3_ChangeValues);
			// 
			// txtPrimarioT1
			// 
			this->txtPrimarioT1->Location = System::Drawing::Point(230, 26);
			this->txtPrimarioT1->Name = L"txtPrimarioT1";
			this->txtPrimarioT1->Size = System::Drawing::Size(68, 22);
			this->txtPrimarioT1->TabIndex = 0;
			this->txtPrimarioT1->Text = L"220";
			this->txtPrimarioT1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor1_ChangeValues);
			this->txtPrimarioT1->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor1_ChangeValues);
			// 
			// lblSecundarioTC3
			// 
			this->lblSecundarioTC3->AutoSize = true;
			this->lblSecundarioTC3->Location = System::Drawing::Point(304, 169);
			this->lblSecundarioTC3->Name = L"lblSecundarioTC3";
			this->lblSecundarioTC3->Size = System::Drawing::Size(189, 16);
			this->lblSecundarioTC3->TabIndex = 22;
			this->lblSecundarioTC3->Text = L"Corrente secundário de T3 (A):";
			// 
			// lblSecundarioT1
			// 
			this->lblSecundarioT1->AutoSize = true;
			this->lblSecundarioT1->Location = System::Drawing::Point(6, 57);
			this->lblSecundarioT1->Name = L"lblSecundarioT1";
			this->lblSecundarioT1->Size = System::Drawing::Size(207, 16);
			this->lblSecundarioT1->TabIndex = 2;
			this->lblSecundarioT1->Text = L"Tensão secundário de T1 (Vrms):";
			// 
			// txtPrimarioTC3
			// 
			this->txtPrimarioTC3->Location = System::Drawing::Point(517, 138);
			this->txtPrimarioTC3->Name = L"txtPrimarioTC3";
			this->txtPrimarioTC3->Size = System::Drawing::Size(68, 22);
			this->txtPrimarioTC3->TabIndex = 13;
			this->txtPrimarioTC3->Text = L"100";
			this->txtPrimarioTC3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor3_ChangeValues);
			this->txtPrimarioTC3->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor3_ChangeValues);
			// 
			// txtSecundarioT1
			// 
			this->txtSecundarioT1->Location = System::Drawing::Point(230, 54);
			this->txtSecundarioT1->Name = L"txtSecundarioT1";
			this->txtSecundarioT1->Size = System::Drawing::Size(68, 22);
			this->txtSecundarioT1->TabIndex = 1;
			this->txtSecundarioT1->Text = L"9";
			this->txtSecundarioT1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor1_ChangeValues);
			this->txtSecundarioT1->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor1_ChangeValues);
			// 
			// lblPrimarioTC3
			// 
			this->lblPrimarioTC3->AutoSize = true;
			this->lblPrimarioTC3->Location = System::Drawing::Point(304, 141);
			this->lblPrimarioTC3->Name = L"lblPrimarioTC3";
			this->lblPrimarioTC3->Size = System::Drawing::Size(180, 16);
			this->lblPrimarioTC3->TabIndex = 20;
			this->lblPrimarioTC3->Text = L"Corrente primário de TC3 (A):";
			// 
			// lblPrimarioT2
			// 
			this->lblPrimarioT2->AutoSize = true;
			this->lblPrimarioT2->Location = System::Drawing::Point(6, 85);
			this->lblPrimarioT2->Name = L"lblPrimarioT2";
			this->lblPrimarioT2->Size = System::Drawing::Size(189, 16);
			this->lblPrimarioT2->TabIndex = 4;
			this->lblPrimarioT2->Text = L"Tensão primário de T2 (Vrms):";
			// 
			// txtSecundarioTC2
			// 
			this->txtSecundarioTC2->Location = System::Drawing::Point(517, 110);
			this->txtSecundarioTC2->Name = L"txtSecundarioTC2";
			this->txtSecundarioTC2->Size = System::Drawing::Size(68, 22);
			this->txtSecundarioTC2->TabIndex = 12;
			this->txtSecundarioTC2->Text = L"0,05";
			this->txtSecundarioTC2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor2_ChangeValues);
			this->txtSecundarioTC2->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor2_ChangeValues);
			// 
			// txtPrimarioT2
			// 
			this->txtPrimarioT2->Location = System::Drawing::Point(230, 82);
			this->txtPrimarioT2->Name = L"txtPrimarioT2";
			this->txtPrimarioT2->Size = System::Drawing::Size(68, 22);
			this->txtPrimarioT2->TabIndex = 2;
			this->txtPrimarioT2->Text = L"220";
			this->txtPrimarioT2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor2_ChangeValues);
			this->txtPrimarioT2->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor2_ChangeValues);
			// 
			// lblSecundarioTC2
			// 
			this->lblSecundarioTC2->AutoSize = true;
			this->lblSecundarioTC2->Location = System::Drawing::Point(304, 113);
			this->lblSecundarioTC2->Name = L"lblSecundarioTC2";
			this->lblSecundarioTC2->Size = System::Drawing::Size(198, 16);
			this->lblSecundarioTC2->TabIndex = 18;
			this->lblSecundarioTC2->Text = L"Corrente secundário de TC2 (A):";
			// 
			// lblSecundarioT2
			// 
			this->lblSecundarioT2->AutoSize = true;
			this->lblSecundarioT2->Location = System::Drawing::Point(6, 113);
			this->lblSecundarioT2->Name = L"lblSecundarioT2";
			this->lblSecundarioT2->Size = System::Drawing::Size(207, 16);
			this->lblSecundarioT2->TabIndex = 6;
			this->lblSecundarioT2->Text = L"Tensão secundário de T2 (Vrms):";
			// 
			// txtPrimarioTC2
			// 
			this->txtPrimarioTC2->Location = System::Drawing::Point(517, 82);
			this->txtPrimarioTC2->Name = L"txtPrimarioTC2";
			this->txtPrimarioTC2->Size = System::Drawing::Size(68, 22);
			this->txtPrimarioTC2->TabIndex = 11;
			this->txtPrimarioTC2->Text = L"100";
			this->txtPrimarioTC2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor2_ChangeValues);
			this->txtPrimarioTC2->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor2_ChangeValues);
			// 
			// txtSecundarioT2
			// 
			this->txtSecundarioT2->Location = System::Drawing::Point(230, 110);
			this->txtSecundarioT2->Name = L"txtSecundarioT2";
			this->txtSecundarioT2->Size = System::Drawing::Size(68, 22);
			this->txtSecundarioT2->TabIndex = 3;
			this->txtSecundarioT2->Text = L"9";
			this->txtSecundarioT2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor2_ChangeValues);
			this->txtSecundarioT2->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor2_ChangeValues);
			// 
			// lblPrimarioTC2
			// 
			this->lblPrimarioTC2->AutoSize = true;
			this->lblPrimarioTC2->Location = System::Drawing::Point(304, 85);
			this->lblPrimarioTC2->Name = L"lblPrimarioTC2";
			this->lblPrimarioTC2->Size = System::Drawing::Size(180, 16);
			this->lblPrimarioTC2->TabIndex = 16;
			this->lblPrimarioTC2->Text = L"Corrente primário de TC2 (A):";
			// 
			// lblPrimarioT3
			// 
			this->lblPrimarioT3->AutoSize = true;
			this->lblPrimarioT3->Location = System::Drawing::Point(6, 141);
			this->lblPrimarioT3->Name = L"lblPrimarioT3";
			this->lblPrimarioT3->Size = System::Drawing::Size(189, 16);
			this->lblPrimarioT3->TabIndex = 8;
			this->lblPrimarioT3->Text = L"Tensão primário de T3 (Vrms):";
			// 
			// txtSecundarioTC1
			// 
			this->txtSecundarioTC1->Location = System::Drawing::Point(517, 54);
			this->txtSecundarioTC1->Name = L"txtSecundarioTC1";
			this->txtSecundarioTC1->Size = System::Drawing::Size(68, 22);
			this->txtSecundarioTC1->TabIndex = 10;
			this->txtSecundarioTC1->Text = L"0,05";
			this->txtSecundarioTC1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor1_ChangeValues);
			this->txtSecundarioTC1->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor1_ChangeValues);
			// 
			// txtPrimarioT3
			// 
			this->txtPrimarioT3->Location = System::Drawing::Point(230, 138);
			this->txtPrimarioT3->Name = L"txtPrimarioT3";
			this->txtPrimarioT3->Size = System::Drawing::Size(68, 22);
			this->txtPrimarioT3->TabIndex = 4;
			this->txtPrimarioT3->Text = L"220";
			this->txtPrimarioT3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor3_ChangeValues);
			this->txtPrimarioT3->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor3_ChangeValues);
			// 
			// lblSecundarioTC1
			// 
			this->lblSecundarioTC1->AutoSize = true;
			this->lblSecundarioTC1->Location = System::Drawing::Point(304, 57);
			this->lblSecundarioTC1->Name = L"lblSecundarioTC1";
			this->lblSecundarioTC1->Size = System::Drawing::Size(198, 16);
			this->lblSecundarioTC1->TabIndex = 14;
			this->lblSecundarioTC1->Text = L"Corrente secundário de TC1 (A):";
			// 
			// lblSecundarioT3
			// 
			this->lblSecundarioT3->AutoSize = true;
			this->lblSecundarioT3->Location = System::Drawing::Point(6, 169);
			this->lblSecundarioT3->Name = L"lblSecundarioT3";
			this->lblSecundarioT3->Size = System::Drawing::Size(207, 16);
			this->lblSecundarioT3->TabIndex = 10;
			this->lblSecundarioT3->Text = L"Tensão secundário de T3 (Vrms):";
			// 
			// txtPrimarioTC1
			// 
			this->txtPrimarioTC1->Location = System::Drawing::Point(517, 26);
			this->txtPrimarioTC1->Name = L"txtPrimarioTC1";
			this->txtPrimarioTC1->Size = System::Drawing::Size(68, 22);
			this->txtPrimarioTC1->TabIndex = 9;
			this->txtPrimarioTC1->Text = L"100";
			this->txtPrimarioTC1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::CurrentSensor1_ChangeValues);
			this->txtPrimarioTC1->Leave += gcnew System::EventHandler(this, &MainForm::CurrentSensor1_ChangeValues);
			// 
			// txtSecundarioT3
			// 
			this->txtSecundarioT3->Location = System::Drawing::Point(230, 166);
			this->txtSecundarioT3->Name = L"txtSecundarioT3";
			this->txtSecundarioT3->Size = System::Drawing::Size(68, 22);
			this->txtSecundarioT3->TabIndex = 5;
			this->txtSecundarioT3->Text = L"9";
			this->txtSecundarioT3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::VoltageSensor3_ChangeValues);
			this->txtSecundarioT3->Leave += gcnew System::EventHandler(this, &MainForm::VoltageSensor3_ChangeValues);
			// 
			// lblPrimarioTC1
			// 
			this->lblPrimarioTC1->AutoSize = true;
			this->lblPrimarioTC1->Location = System::Drawing::Point(304, 29);
			this->lblPrimarioTC1->Name = L"lblPrimarioTC1";
			this->lblPrimarioTC1->Size = System::Drawing::Size(180, 16);
			this->lblPrimarioTC1->TabIndex = 12;
			this->lblPrimarioTC1->Text = L"Corrente primário de TC1 (A):";
			// 
			// dlgSaveCSV
			// 
			this->dlgSaveCSV->Filter = L"Arquivos CSV | *.csv";
			this->dlgSaveCSV->InitialDirectory = L".";
			this->dlgSaveCSV->Title = L"Salvar pontos atuais";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(920, 665);
			this->Controls->Add(this->tabCtrlApplication);
			this->Controls->Add(this->statusStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"Projeto de amostragem de potência trifásica";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->tabCtrlApplication->ResumeLayout(false);
			this->tabModule->ResumeLayout(false);
			this->tabModule->PerformLayout();
			this->gbxNetConfig->ResumeLayout(false);
			this->gbxNetConfig->PerformLayout();
			this->gbxSerialConnection->ResumeLayout(false);
			this->gbxNetConnect->ResumeLayout(false);
			this->gbxNetConnect->PerformLayout();
			this->tabSignal->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chtSignal))->EndInit();
			this->gpbxDAQControl->ResumeLayout(false);
			this->gpbxDAQControl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudSamplesQty))->EndInit();
			this->tabCommonCmd->ResumeLayout(false);
			this->gbxEcho->ResumeLayout(false);
			this->gbxEcho->PerformLayout();
			this->gbxInstReading->ResumeLayout(false);
			this->gbxInstReading->PerformLayout();
			this->tabConfig->ResumeLayout(false);
			this->gpbxConfigRes->ResumeLayout(false);
			this->gpbxConfigRes->PerformLayout();
			this->gpbxTrafos->ResumeLayout(false);
			this->gpbxTrafos->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			Module ^device, ^tcpDevice;
			array<double> ^squaredValueSum;
			unsigned long long amostra;
			unsigned long updateAtSample;
			float T1rel, T2rel, T3rel,TC1rel, TC2rel, TC3rel;
			float T1ref, T2ref, T3ref, TC1ref, TC2ref, TC3ref;
			BindingList<float> ^SamplesT1, ^SamplesT2, ^SamplesT3, ^SamplesTC1, ^SamplesTC2, ^SamplesTC3;

			System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e)
			{
				loadTxtIfConfigExists(txtPrimarioT1);
				loadTxtIfConfigExists(txtSecundarioT1);
				loadTxtIfConfigExists(txtRes6);
				loadTxtIfConfigExists(txtRes7);
				loadTxtIfConfigExists(txtRefT1);
				T1rel = getVoltageSensorRate(txtPrimarioT1, txtSecundarioT1, txtRes6, txtRes7);
				T1ref = getFloatFromTxBox(txtRefT1);

				loadTxtIfConfigExists(txtPrimarioT2);
				loadTxtIfConfigExists(txtSecundarioT2);
				loadTxtIfConfigExists(txtRes8);
				loadTxtIfConfigExists(txtRes9);
				loadTxtIfConfigExists(txtRefT2);
				T2rel = getVoltageSensorRate(txtPrimarioT2, txtSecundarioT2, txtRes8, txtRes9);
				T2ref = getFloatFromTxBox(txtRefT2);

				loadTxtIfConfigExists(txtPrimarioT3);
				loadTxtIfConfigExists(txtSecundarioT3);
				loadTxtIfConfigExists(txtRes10);
				loadTxtIfConfigExists(txtRes11);
				loadTxtIfConfigExists(txtRefT3);
				T3rel = getVoltageSensorRate(txtPrimarioT3, txtSecundarioT3, txtRes10, txtRes11);
				T3ref = getFloatFromTxBox(txtRefT3);

				loadTxtIfConfigExists(txtPrimarioTC1);
				loadTxtIfConfigExists(txtSecundarioTC1);
				loadTxtIfConfigExists(txtRes1);
				loadTxtIfConfigExists(txtRefTC1);
				TC1rel = getCurrentSensorRate(txtPrimarioTC1, txtSecundarioTC1, txtRes1);
				TC1ref = getFloatFromTxBox(txtRefTC1);

				loadTxtIfConfigExists(txtPrimarioTC2);
				loadTxtIfConfigExists(txtSecundarioTC2);
				loadTxtIfConfigExists(txtRes2);
				loadTxtIfConfigExists(txtRefTC2);
				TC2rel = getCurrentSensorRate(txtPrimarioTC2, txtSecundarioTC2, txtRes2);
				TC2ref = getFloatFromTxBox(txtRefTC2);

				loadTxtIfConfigExists(txtPrimarioTC3);
				loadTxtIfConfigExists(txtSecundarioTC3);
				loadTxtIfConfigExists(txtRes3);
				loadTxtIfConfigExists(txtRefTC3);
				TC3rel = getCurrentSensorRate(txtPrimarioTC3, txtSecundarioTC3, txtRes3);
				TC3ref = getFloatFromTxBox(txtRefTC3);

				loadChkBoxIfConfigExists(cbxTensao1);
				loadChkBoxIfConfigExists(cbxTensao2);
				loadChkBoxIfConfigExists(cbxTensao3);

				loadChkBoxIfConfigExists(cbxCorrente1);
				loadChkBoxIfConfigExists(cbxCorrente2);
				loadChkBoxIfConfigExists(cbxCorrente3);

				loadChkBoxIfConfigExists(cbxPotencia1);
				loadChkBoxIfConfigExists(cbxPotencia2);
				loadChkBoxIfConfigExists(cbxPotencia3);

				loadTxtIfConfigExists(txtIP1);
				loadTxtIfConfigExists(txtIP2);
				loadTxtIfConfigExists(txtIP3);
				loadTxtIfConfigExists(txtIP4);
				loadTxtIfConfigExists(txtPort);

				loadNumUpDownIfConfigExists(nudSamplesQty);

				SamplesT1 = gcnew BindingList<float>();
			    SamplesT2 = gcnew BindingList<float>(); 
				SamplesT3 = gcnew BindingList<float>(); 
				SamplesTC1 = gcnew BindingList<float>();
				SamplesTC2 = gcnew BindingList<float>(); 
				SamplesTC3 = gcnew BindingList<float>();

				loadComboBoxIfConfigExists(cbxResolution, 4);
				loadComboBoxIfConfigExists(cmboxADCSelection, 0);
				updateAtSample = Convert::ToUInt32(cbxResolution->Items[cbxResolution->SelectedIndex]);
				setInterfaceState();
			}

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
					virtualComm->BaudRate = 115200;
					device = gcnew Module(virtualComm);
					device->onReceive += gcnew ModuleReception(this, &MainForm::ReceptionHandler);
					device->onDisconnection += gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);
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
						array<unsigned char>^ buffer = gcnew array<unsigned char>(4);

						setInterfaceState();

						buffer[0] = 0xAA;
						buffer[1] = 0x55;
						// Tamanho do campo de dados
						buffer[2] = 0x01;
						// Comando
						buffer[3] = CMD_GET_SSID;

						try
						{
							device->Write(buffer, 0, buffer->Length);
						}
						catch (IOException^) {}

						buffer[3] = CMD_GET_PASSWORD;

						try
						{
							device->Write(buffer, 0, buffer->Length);
						}
						catch (IOException^) {}
					}
				}
				else
				{
					device->Close();
					device = nullptr;
					setInterfaceState();
				}
			}

			System::Void btnNetConnect_Click(System::Object^ sender, System::EventArgs^ e)
			{
				if (btnNetConnect->Text == "Conectar")
				{
					TCPIP4Device ^ipPort = getTCPIP4DeviceFromTextboxes(txtIP1, txtIP2, txtIP3, txtIP4, txtPort);
					tcpDevice = gcnew Module(ipPort);
					tcpDevice->onReceive += gcnew ModuleReception(this, &MainForm::ReceptionHandler);
					tcpDevice->onDisconnection += gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);

					try
					{
						tcpDevice->Open();
					}
					catch (System::SystemException ^e)
					{
						MessageBox::Show(e->Message, "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
					if (tcpDevice->Connected)
					{
						saveTxtToConfig(txtIP1);
						saveTxtToConfig(txtIP2);
						saveTxtToConfig(txtIP3);
						saveTxtToConfig(txtIP4);
						saveTxtToConfig(txtPort);

						setInterfaceState();
					}
				}
				else
				{
					tcpDevice->Close();
					tcpDevice = nullptr;
					setInterfaceState();
				}
			}

			System::Void btnSearch_Click(System::Object^ sender, System::EventArgs^ e)
			{
				UdpClient^ udpSender;
				IPEndPoint^ eqptEndPoint;
				array<unsigned char>^ tempBuffer = gcnew array<unsigned char>(3);
				array<unsigned char>^ packet;
				bool found = false;

				try
				{
					udpSender = gcnew UdpClient(30000);
					eqptEndPoint = gcnew IPEndPoint(IPAddress::Broadcast, 30000);
					tempBuffer[0] = 'I';
					tempBuffer[1] = 'F';
					tempBuffer[2] = 'G';
					udpSender->EnableBroadcast = true;

					udpSender->Send(tempBuffer, tempBuffer->Length, eqptEndPoint);
				}
				catch (SocketException^)
				{
					MessageBox::Show("Porta já está em uso.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
				Thread::Sleep(500);
				while (udpSender->Available && found == false)
				{
					packet = udpSender->Receive(eqptEndPoint);
					if (packet->Length == 7 && packet[0] == 'I' && packet[1] == 'F' && packet[2] == 'G')
					{
						found = true;
					}
				}
				udpSender->Close();
				
				if (found)
				{
					txtIP1->Text = String::Format("{0}", packet[3]);
					txtIP2->Text = String::Format("{0}", packet[4]);
					txtIP3->Text = String::Format("{0}", packet[5]);
					txtIP4->Text = String::Format("{0}", packet[6]); 
					txtPort->Text = "5000";
					TCPIP4Device^ ipPort = getTCPIP4DeviceFromTextboxes(txtIP1, txtIP2, txtIP3, txtIP4, txtPort);
					tcpDevice = gcnew Module(ipPort);
					tcpDevice->onReceive += gcnew ModuleReception(this, &MainForm::ReceptionHandler);
					tcpDevice->onDisconnection += gcnew ModuleDisconnection(this, &MainForm::DisconnectionHandler);

					try
					{
						tcpDevice->Open();
					}
					catch (System::SystemException^ e)
					{
						MessageBox::Show(e->Message, "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}
					if (tcpDevice->Connected)
					{
						saveTxtToConfig(txtIP1);
						saveTxtToConfig(txtIP2);
						saveTxtToConfig(txtIP3);
						saveTxtToConfig(txtIP4);
						saveTxtToConfig(txtPort);

						setInterfaceState();
					}
				}
				else
				{
					MessageBox::Show("Nenhum dispositivo de captura de sinais foi encontrado na rede wireless.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}

			void setInterfaceState(void)
			{
				bool deviceState = (device != nullptr && device->Connected) ? true : false;
				bool tcpDeviceState = (tcpDevice != nullptr && tcpDevice->Connected) ? true : false;

				if (deviceState || tcpDeviceState)
				{
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
					lblADCReading->Enabled = true;
					lblADCReadingValue->Enabled = true;
					btnTxtClear->Enabled = true;
					btnClear->Enabled = true;
					btnSave->Enabled = true;
					btnReset->Enabled = true;

				}
				else
				{
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
					lblADCReading->Enabled = false;
					lblADCReadingValue->Enabled = false;
					btnTxtClear->Enabled = false;
					btnClear->Enabled = false;
					btnSave->Enabled = false;
					btnReset->Enabled = false;
				}

				if (deviceState)
				{
					btnConnect->Text = "Desconectar";
					stLabelConnection->Text = "USB: Conectado";
					cmboxSerialPorts->Enabled = false;
					gbxNetConfig->Enabled = true;
				}
				else
				{
					btnConnect->Text = "Conectar";
					stLabelConnection->Text = "USB: Desconectado";
					cmboxSerialPorts->Enabled = true;
					gbxNetConfig->Enabled = false;
				}

				if (tcpDeviceState)
				{
					btnNetConnect->Text = "Desconectar";
					stLabelNetConnection->Text = "Net: Conectado";
					btnSearch->Enabled = false;
					txtIP1->Enabled = false;
					txtIP2->Enabled = false;
					txtIP3->Enabled = false;
					txtIP4->Enabled = false;
					txtPort->Enabled = false;
				}
				else
				{
					btnNetConnect->Text = "Conectar";
					stLabelNetConnection->Text = "Net: Desconectado";
					btnSearch->Enabled = true;
					txtIP1->Enabled = true;
					txtIP2->Enabled = true;
					txtIP3->Enabled = true;
					txtIP4->Enabled = true;
					txtPort->Enabled = true;
				}
			}

			TCPIP4Device^ MainForm::getTCPIP4DeviceFromTextboxes(TextBox^ txtBx1, TextBox^ txtBx2, TextBox^ txtBx3, TextBox^ txtBx4, TextBox^ txtPNum)
			{
				TCPIP4Device^ newComm;

				try
				{
					Int32::Parse(txtBx1->Text);
					Int32::Parse(txtBx2->Text);
					Int32::Parse(txtBx3->Text);
					Int32::Parse(txtBx4->Text);
					Int32::Parse(txtPNum->Text);
				}
				catch (...)
				{
					MessageBox::Show("IP ou porta informados são inválidos.", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
				newComm = gcnew TCPIP4Device();
				newComm->IP = gcnew String(txtBx1->Text + L"." + txtBx2->Text + L"." + txtBx3->Text + L"." + txtBx4->Text);
				newComm->PortNumber = Convert::ToInt32(txtPNum->Text);

				return(newComm);
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
					float adcVal, analogVal;

					switch (buffer[0])
					{
						case CMD_MESSAGE:
							txtMessages->Text += Encoding::ASCII->GetString(buffer, 1, buffer->Length - 1);
							break;
						case CMD_GET_SSID:
							txtSSID->Text = Encoding::ASCII->GetString(buffer, 1, buffer->Length - 1);
							break;
						case CMD_GET_PASSWORD:
							txtPassword->Text = Encoding::ASCII->GetString(buffer, 1, buffer->Length - 1);
							break;
						case CMD_SAMPLE_SEND:
							analogVal = getSampleValueFromInt(safe_cast<UInt16>(buffer[1]) + safe_cast<UInt16>((buffer[2] & 0x0F) << 8), T1ref, T1rel);
							SamplesT1->Add(analogVal);
							squaredValueSum[0] += analogVal * analogVal;
							analogVal = getSampleValueFromInt(safe_cast<UInt16>((buffer[2] >> 4) & 0x0F) + safe_cast<UInt16>(buffer[3] << 4), T2ref, T2rel);
							SamplesT2->Add(analogVal);
							squaredValueSum[1] += analogVal * analogVal;
							analogVal = getSampleValueFromInt(safe_cast<UInt16>(buffer[4]) + safe_cast<UInt16>((buffer[5] & 0x0F) << 8), T3ref, T3rel);
							SamplesT3->Add(analogVal);
							squaredValueSum[2] += analogVal * analogVal;
							analogVal = getSampleValueFromInt(safe_cast<UInt16>((buffer[5] >> 4) & 0x0F) + safe_cast<UInt16>(buffer[6] << 4), TC1ref, TC1rel);
							SamplesTC1->Add(analogVal);
							squaredValueSum[3] += analogVal * analogVal;
							analogVal = getSampleValueFromInt(safe_cast<UInt16>(buffer[7]) + safe_cast<UInt16>((buffer[8] & 0x0F) << 8), TC2ref, TC2rel);
							SamplesTC2->Add(analogVal);
							squaredValueSum[4] += analogVal * analogVal;
							analogVal = getSampleValueFromInt(safe_cast<UInt16>((buffer[8] >> 4) & 0x0F) + safe_cast<UInt16>(buffer[9] << 4), TC3ref, TC3rel);
							SamplesTC3->Add(analogVal);
							squaredValueSum[5] += analogVal * analogVal;
							amostra++;

							if (amostra == 20 || (amostra % updateAtSample) == 0)
							{
								double vrms, irms;
								double samplingTime = TAXA_AMOSTRAGEM * amostra;
								// Interrompe a atualização do gráfico temporariamente
							    // para adicionar novos pontos
								chtSignal->Series["Tensao1"]->Points->SuspendUpdates();
								chtSignal->Series["Tensao2"]->Points->SuspendUpdates();
								chtSignal->Series["Tensao3"]->Points->SuspendUpdates();

								chtSignal->Series["Corrente1"]->Points->SuspendUpdates();
								chtSignal->Series["Corrente2"]->Points->SuspendUpdates();
								chtSignal->Series["Corrente3"]->Points->SuspendUpdates();

								chtSignal->Series["Potencia1"]->Points->SuspendUpdates();
								chtSignal->Series["Potencia2"]->Points->SuspendUpdates();
								chtSignal->Series["Potencia3"]->Points->SuspendUpdates();

								vrms = Math::Sqrt(squaredValueSum[0] / amostra);
								irms = Math::Sqrt(squaredValueSum[3] / amostra);
								chtSignal->Series["Tensao1"]->Points->AddXY(samplingTime,vrms);
								chtSignal->Series["Corrente1"]->Points->AddXY(samplingTime,irms);
								chtSignal->Series["Potencia1"]->Points->AddXY(samplingTime,vrms*irms);

								vrms = Math::Sqrt(squaredValueSum[1] / amostra);
								irms = Math::Sqrt(squaredValueSum[4] / amostra);
								chtSignal->Series["Tensao2"]->Points->AddXY(samplingTime,vrms);
								chtSignal->Series["Corrente2"]->Points->AddXY(samplingTime,irms);
								chtSignal->Series["Potencia2"]->Points->AddXY(samplingTime,vrms * irms);
								
								vrms = Math::Sqrt(squaredValueSum[2] / amostra);
								irms = Math::Sqrt(squaredValueSum[5] / amostra);
								chtSignal->Series["Tensao3"]->Points->AddXY(samplingTime,vrms);
								chtSignal->Series["Corrente3"]->Points->AddXY(samplingTime,irms);
								chtSignal->Series["Potencia3"]->Points->AddXY(samplingTime,vrms * irms);

								// Restaura a atualização do gráfico
								chtSignal->Series["Tensao1"]->Points->ResumeUpdates();
								chtSignal->Series["Tensao2"]->Points->ResumeUpdates();
								chtSignal->Series["Tensao3"]->Points->ResumeUpdates();

								chtSignal->Series["Corrente1"]->Points->ResumeUpdates();
								chtSignal->Series["Corrente2"]->Points->ResumeUpdates();
								chtSignal->Series["Corrente3"]->Points->ResumeUpdates();

								chtSignal->Series["Potencia1"]->Points->ResumeUpdates();
								chtSignal->Series["Potencia2"]->Points->ResumeUpdates();
								chtSignal->Series["Potencia3"]->Points->ResumeUpdates();
							}
							break;
						case CMD_GET_ADC_READING:
							adcVal = BitConverter::ToUInt16(buffer, 1) * (3.3f/4096.0f);
							analogVal = BitConverter::ToUInt16(buffer, 3) / 1000.0f;
							
							switch (cmboxADCSelection->SelectedIndex)
							{
								case 0:
									lblADCReadingValue->Text = String::Format("{0:F2} V", adcVal);
									lblAnalogReading->Text = String::Format("{0:F2} V", analogVal);
									break;
								case 1:
									lblADCReadingValue->Text = String::Format("{0:F2} V", adcVal);
									lblAnalogReading->Text = String::Format("{0:F2} V", analogVal);
									break;
								case 2:
									lblADCReadingValue->Text = String::Format("{0:F2} V", adcVal);
									lblAnalogReading->Text = String::Format("{0:F2} V", analogVal);
									break;
								case 3:
									lblADCReadingValue->Text = String::Format("{0:F2} V", adcVal);
									lblAnalogReading->Text = String::Format("{0:F2} V", analogVal);
									break;
								case 4:
									lblADCReadingValue->Text = String::Format("{0:F2} V", adcVal);
									lblAnalogReading->Text = String::Format("{0:F2} V", analogVal);
									break;
								case 5:
									lblADCReadingValue->Text = String::Format("{0:F2} V", adcVal);
									lblAnalogReading->Text = String::Format("{0:F2} V", analogVal);
									break;
							}
							break;
						default:
							break;
					}
				}
			}

			float getSampleValueFromInt(UInt16 value, float refVoltage, float convertionRate)
			{
				float result = safe_cast<float>(Math::Round(((value / 1000.0f) - refVoltage) * convertionRate, 2));
				
				return(result);
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
				Module^ priorityDevice;

				if (device != nullptr && device->Connected)
					priorityDevice = device;
				if (tcpDevice != nullptr && tcpDevice->Connected)
					priorityDevice = tcpDevice;

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^buffer = gcnew array<unsigned char>(txtSendMessage->Text->Length + 4);
					array<unsigned char>^message = Encoding::ASCII->GetBytes(txtSendMessage->Text);

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = safe_cast<unsigned char>(txtSendMessage->Text->Length + 1);
					// Comando
					buffer[3] = CMD_SEND_ECHO;
					// Texto para envio
					for (int i = 0; i < message->Length; i++)
						buffer[4 + i] = message[i];

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
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
				tcpDevice->Close();
			}

			System::Void btnGetSamples_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				Module^ priorityDevice;
				array<unsigned char>^ tempByteArray;

				if (device != nullptr && device->Connected)
					priorityDevice = device;
				if (tcpDevice != nullptr && tcpDevice->Connected)
					priorityDevice = tcpDevice;

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^buffer = gcnew array<unsigned char>(7);
					UInt16 quantSamples;
					squaredValueSum = gcnew array<double>(6);
					amostra = 0;

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 0x04;
					// Comando
					buffer[3] = CMD_SET_SAMPLING_STATE;
					buffer[4] = 1;
					quantSamples = Convert::ToUInt16(nudSamplesQty->Text);
					tempByteArray = BitConverter::GetBytes(quantSamples);
					buffer[5] = tempByteArray[0];
					buffer[6] = tempByteArray[1];

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException ^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					}

					saveNumUpDownToConfig(nudSamplesQty);
				}
			}

			System::Void btnLeitura_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				if (cmboxADCSelection->SelectedIndex != -1)
				{
					Module^ priorityDevice;

					if (device != nullptr && device->Connected)
						priorityDevice = device;
					if (tcpDevice != nullptr && tcpDevice->Connected)
						priorityDevice = tcpDevice;

					if (priorityDevice != nullptr && priorityDevice->Connected)
					{
						array<unsigned char>^ buffer = gcnew array<unsigned char>(5);

						buffer[0] = 0xAA;
						buffer[1] = 0x55;
						// Tamanho do campo de dados
						buffer[2] = 0x02;
						// Comando
						buffer[3] = CMD_GET_ADC_READING;
						buffer[4] = safe_cast<Byte>(cmboxADCSelection->SelectedIndex);

						try
						{
							priorityDevice->Write(buffer, 0, buffer->Length);
						}
						catch (IOException^)
						{
							MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						}

						saveComboBoxToConfig(cmboxADCSelection);
					}
				}
				else
				{
					MessageBox::Show("Selecinar um ADC para leitura", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				}
			}

			System::Void btnReset_Click(System::Object^ sender, System::EventArgs^ e)
			{
				Module^ priorityDevice;

				if (device != nullptr && device->Connected)
					priorityDevice = device;
				if (tcpDevice != nullptr && tcpDevice->Connected)
					priorityDevice = tcpDevice;

				if (priorityDevice != nullptr && priorityDevice->Connected)
				{
					array<unsigned char>^ buffer = gcnew array<unsigned char>(4);

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 0x01;
					// Comando
					buffer[3] = CMD_RESET;

					try
					{
						priorityDevice->Write(buffer, 0, buffer->Length);
					}
					catch (IOException^)
					{
						MessageBox::Show("Mensagem não pôde ser enviada", "Erro", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;
					}

					Thread::Sleep(1500);

					if (tcpDevice != nullptr && tcpDevice->Connected)
					{
						tcpDevice->Close();
						setInterfaceState();
					}
				}
			}

			System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				amostra = 0;
				squaredValueSum = gcnew array<double>(6);

				chtSignal->Series["Tensao1"]->Points->Clear();
				chtSignal->Series["Tensao2"]->Points->Clear();
				chtSignal->Series["Tensao3"]->Points->Clear();

				chtSignal->Series["Corrente1"]->Points->Clear();
				chtSignal->Series["Corrente2"]->Points->Clear();
				chtSignal->Series["Corrente3"]->Points->Clear();

				chtSignal->Series["Potencia1"]->Points->Clear();
				chtSignal->Series["Potencia2"]->Points->Clear();
				chtSignal->Series["Potencia3"]->Points->Clear();

				SamplesT1 = gcnew BindingList<float>();
				SamplesT2 = gcnew BindingList<float>();
				SamplesT3 = gcnew BindingList<float>();
				SamplesTC1 = gcnew BindingList<float>();
				SamplesTC2 = gcnew BindingList<float>();
				SamplesTC3 = gcnew BindingList<float>();

				if (device != nullptr)
				{
					device->Clear();
				}
			}

			System::Void btnTxtClear_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				txtMessages->Clear();
			}

			System::Void cbxTensao1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Tensao1"]->Enabled = cbxTensao1->Checked;
				saveChkBoxToConfig(cbxTensao1);
			}

			System::Void cbxCorrente1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Corrente1"]->Enabled = cbxCorrente1->Checked;
				saveChkBoxToConfig(cbxCorrente1);
			}

			System::Void cbxTensao2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Tensao2"]->Enabled = cbxTensao2->Checked;
				saveChkBoxToConfig(cbxTensao2);
			}

			System::Void cbxCorrente2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Corrente2"]->Enabled = cbxCorrente2->Checked;
				saveChkBoxToConfig(cbxCorrente2);
			}

			System::Void cbxTensao3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Tensao3"]->Enabled = cbxTensao3->Checked;
				saveChkBoxToConfig(cbxTensao3);
			}

			System::Void cbxCorrente3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				chtSignal->Series["Corrente3"]->Enabled = cbxCorrente3->Checked;
				saveChkBoxToConfig(cbxCorrente3);
			}

			System::Void cbxPotencia1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
			{
				chtSignal->Series["Potencia1"]->Enabled = cbxPotencia1->Checked;
				saveChkBoxToConfig(cbxPotencia1);
			}

			System::Void cbxPotencia2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
			{
				chtSignal->Series["Potencia2"]->Enabled = cbxPotencia2->Checked;
				saveChkBoxToConfig(cbxPotencia2);
			}

			System::Void cbxPotencia3_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
			{
				chtSignal->Series["Potencia3"]->Enabled = cbxPotencia3->Checked;
				saveChkBoxToConfig(cbxPotencia3);
			}

			System::Void VoltageSensor1_ChangeValues(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
			{
				if (e->KeyChar == 13)
				{
					T1rel = getVoltageSensorRate(txtPrimarioT1, txtSecundarioT1, txtRes6, txtRes7);
					
					saveTxtToConfig(txtPrimarioT1);
					saveTxtToConfig(txtSecundarioT1);
					saveTxtToConfig(txtRes6);
					saveTxtToConfig(txtRes7);
				}
			}

			System::Void VoltageSensor1_ChangeValues(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getVoltageSensorRate(txtPrimarioT1, txtSecundarioT1, txtRes6, txtRes7);

				if (Math::Abs(tempValue - T1rel) >= 0.001f)
				{
					T1rel = tempValue;
					saveTxtToConfig(txtPrimarioT1);
					saveTxtToConfig(txtSecundarioT1);
					saveTxtToConfig(txtRes6);
					saveTxtToConfig(txtRes7);
				}
			}

			System::Void VoltageSensor2_ChangeValues(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					T2rel = getVoltageSensorRate(txtPrimarioT2, txtSecundarioT2, txtRes8, txtRes9);

					saveTxtToConfig(txtPrimarioT2);
					saveTxtToConfig(txtSecundarioT2);
					saveTxtToConfig(txtRes8);
					saveTxtToConfig(txtRes9);
				}
			}

			System::Void VoltageSensor2_ChangeValues(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getVoltageSensorRate(txtPrimarioT2, txtSecundarioT2, txtRes8, txtRes9);

				if (Math::Abs(tempValue - T2rel) >= 0.001f)
				{
					T2rel = tempValue;
					saveTxtToConfig(txtPrimarioT2);
					saveTxtToConfig(txtSecundarioT2);
					saveTxtToConfig(txtRes8);
					saveTxtToConfig(txtRes9);
				}
			}

			System::Void VoltageSensor3_ChangeValues(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					T3rel = getVoltageSensorRate(txtPrimarioT3, txtSecundarioT3, txtRes10, txtRes11);

					saveTxtToConfig(txtPrimarioT3);
					saveTxtToConfig(txtSecundarioT3);
					saveTxtToConfig(txtRes10);
					saveTxtToConfig(txtRes11);
				}
			}

			System::Void VoltageSensor3_ChangeValues(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = T3rel = getVoltageSensorRate(txtPrimarioT3, txtSecundarioT3, txtRes10, txtRes11);

				if (Math::Abs(tempValue - T3rel) >= 0.001f)
				{
					T3rel = tempValue;
					saveTxtToConfig(txtPrimarioT3);
					saveTxtToConfig(txtSecundarioT3);
					saveTxtToConfig(txtRes10);
					saveTxtToConfig(txtRes11);
				}
			}

			System::Void CurrentSensor1_ChangeValues(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					TC1rel = getCurrentSensorRate(txtPrimarioTC1, txtSecundarioTC1, txtRes1);

					saveTxtToConfig(txtPrimarioTC1);
					saveTxtToConfig(txtSecundarioTC1);
					saveTxtToConfig(txtRes1);
				}
			}

			System::Void CurrentSensor1_ChangeValues(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getCurrentSensorRate(txtPrimarioTC1, txtSecundarioTC1, txtRes1);

				if (Math::Abs(tempValue - TC1rel) >= 0.001f)
				{
					TC1rel = tempValue;
					saveTxtToConfig(txtPrimarioTC1);
					saveTxtToConfig(txtSecundarioTC1);
					saveTxtToConfig(txtRes1);
				}
			}

			System::Void CurrentSensor2_ChangeValues(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					TC2rel = getCurrentSensorRate(txtPrimarioTC2, txtSecundarioTC2, txtRes2);

					saveTxtToConfig(txtPrimarioTC2);
					saveTxtToConfig(txtSecundarioTC2);
					saveTxtToConfig(txtRes2);
				}
			}

			System::Void CurrentSensor2_ChangeValues(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getCurrentSensorRate(txtPrimarioTC2, txtSecundarioTC2, txtRes2);

				if (Math::Abs(tempValue - TC2rel) >= 0.001f)
				{
					TC2rel = tempValue;
					saveTxtToConfig(txtPrimarioTC2);
					saveTxtToConfig(txtSecundarioTC2);
					saveTxtToConfig(txtRes2);
				}
			}

			System::Void CurrentSensor3_ChangeValues(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					TC3rel = getCurrentSensorRate(txtPrimarioTC3, txtSecundarioTC3, txtRes3);

					saveTxtToConfig(txtPrimarioTC3);
					saveTxtToConfig(txtSecundarioTC3);
					saveTxtToConfig(txtRes3);
				}
			}

			System::Void CurrentSensor3_ChangeValues(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getCurrentSensorRate(txtPrimarioTC3, txtSecundarioTC3, txtRes3);

				if (Math::Abs(tempValue - TC3rel) >= 0.001f)
				{
					TC3rel = tempValue;
					saveTxtToConfig(txtPrimarioTC3);
					saveTxtToConfig(txtSecundarioTC3);
					saveTxtToConfig(txtRes3);
				}
			}

			float getVoltageSensorRate(TextBox^ txtPrimary, TextBox^ txtSecondary, TextBox^ txtResMajor, TextBox^ txtResMinor)
			{
				float tranformerRelation, divisionRelation;

				try
				{
					tranformerRelation = Convert::ToSingle(txtSecondary->Text) / Convert::ToSingle(txtPrimary->Text);
					divisionRelation = (Convert::ToSingle(txtResMajor->Text) + Convert::ToSingle(txtResMinor->Text)) / Convert::ToSingle(txtResMinor->Text);
				}
				catch (...)
				{
					tranformerRelation = divisionRelation = 1.0f;
				}

				return(tranformerRelation * divisionRelation);
			}

			float getCurrentSensorRate(TextBox^ txtPrimary, TextBox^ txtSecondary, TextBox^ txtRes)
			{
				float convertionRelation;

				try
				{
					convertionRelation = Convert::ToSingle(txtSecondary->Text) / (Convert::ToSingle(txtPrimary->Text) * Convert::ToSingle(txtRes->Text));
				}
				catch (...)
				{
					convertionRelation = 1.0f;
				}

				return(convertionRelation);
			}

			System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				if (dlgSaveCSV->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					String^ header = gcnew String("Tempo;Tensao1;Tensao2;Tensao3;Corrente1;Corrente2;Corrente3;Potencia instantanea 1;Potencia instantanea 2;Potencia instantanea 3\r\n");
					String^ csvBody = gcnew String("");
					String^ csvResult = gcnew String("");
					Encoding^ u8 = Encoding::UTF8;
					FileStream^ analiseFile;
					BinaryWriter^ writeFile;
					int size = SamplesT1->Count;

					size = (size > SamplesT2->Count) ? SamplesT2->Count : size;
					size = (size > SamplesT3->Count) ? SamplesT3->Count : size;
					size = (size > SamplesTC1->Count) ? SamplesTC1->Count : size;
					size = (size > SamplesTC2->Count) ? SamplesTC2->Count : size;
					size = (size > SamplesTC3->Count) ? SamplesTC3->Count : size;
					for (int pointer = 0; pointer < size; pointer += 8)
					{
						csvBody += String::Format("{0};", pointer);
						csvBody += String::Format("{0};{1};{2};", SamplesT1[pointer], SamplesT2[pointer], SamplesT3[pointer]);
						csvBody += String::Format("{0};{1};{2};", SamplesTC1[pointer], SamplesTC2[pointer], SamplesTC3[pointer]);
						csvBody += String::Format("{0};{1};{2};\r\n", SamplesT1[pointer]*SamplesTC1[pointer], SamplesT2[pointer]*SamplesTC2[pointer], SamplesT3[pointer]*SamplesTC3[pointer]);
					}

					csvResult = header + csvBody;
					analiseFile = gcnew FileStream(dlgSaveCSV->FileName, FileMode::Create);
					writeFile = gcnew BinaryWriter(analiseFile);
					writeFile->Write(u8->GetBytes(csvResult));
					analiseFile->Close();
				}
			}

			float getFloatFromTxBox(TextBox^ txtBox)
			{
				float value;

				try
				{
					value = Convert::ToSingle(txtBox->Text);
				}
				catch (...)
				{
					value = 0.0f;
				}

				return value;
			}

			void loadNumUpDownIfConfigExists(NumericUpDown^ numUpDown)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[numUpDown->Name] != nullptr)
					numUpDown->Text = System::Configuration::ConfigurationManager::AppSettings[numUpDown->Name];
			}

			void saveNumUpDownToConfig(NumericUpDown^ numUpDown)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(numUpDown->Name);
				config->AppSettings->Settings->Add(numUpDown->Name, numUpDown->Text);
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			void loadTxtIfConfigExists(TextBox^ txtBox)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[txtBox->Name] != nullptr)
					txtBox->Text = System::Configuration::ConfigurationManager::AppSettings[txtBox->Name];
			}

			void saveTxtToConfig(TextBox^ txtBox)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(txtBox->Name);
				config->AppSettings->Settings->Add(txtBox->Name, txtBox->Text);
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			void loadChkBoxIfConfigExists(CheckBox^ chkBox)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[chkBox->Name] != nullptr)
					chkBox->Checked = Convert::ToBoolean(System::Configuration::ConfigurationManager::AppSettings[chkBox->Name]);
			}

			void saveChkBoxToConfig(CheckBox^ chkBox)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(chkBox->Name);
				config->AppSettings->Settings->Add(chkBox->Name, Convert::ToString(chkBox->Checked));
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			void loadComboBoxIfConfigExists(ComboBox^ cmbBox, Int32 defaultValue)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[cmbBox->Name] != nullptr)
					cmbBox->SelectedIndex = Convert::ToInt32(System::Configuration::ConfigurationManager::AppSettings[cmbBox->Name]);
				else
					cmbBox->SelectedIndex = defaultValue;
			}

			void loadComboBoxTextIfConfigExists(ComboBox^ cmbBox)
			{
				if (System::Configuration::ConfigurationManager::AppSettings[cmbBox->Name] != nullptr)
				{
					String^ text = System::Configuration::ConfigurationManager::AppSettings[cmbBox->Name];
					cmbBox->Items->Add(text);
					cmbBox->SelectedIndex = cmbBox->FindStringExact(text);
				}
				else
					cmbBox->Text = "";
			}

			void saveComboBoxToConfig(ComboBox^ cmbBox)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(cmbBox->Name);
				config->AppSettings->Settings->Add(cmbBox->Name, Convert::ToString(cmbBox->SelectedIndex));
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			void saveComboBoxTextToConfig(ComboBox^ cmbBox)
			{
				System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);

				config->AppSettings->Settings->Remove(cmbBox->Name);
				config->AppSettings->Settings->Add(cmbBox->Name, Convert::ToString(cmbBox->Text));
				config->Save(ConfigurationSaveMode::Modified);
				ConfigurationManager::RefreshSection("appSettings");
			}

			System::Void btnChangePassword_Click(System::Object^ sender, System::EventArgs^ e)
			{
				if (device->Connected)
				{
					array<unsigned char>^ password = Encoding::ASCII->GetBytes(txtPassword->Text);
					array<unsigned char>^ buffer = gcnew array<unsigned char>(4 + password->Length);

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 1 + password->Length;
					// Comando
					buffer[3] = CMD_SEND_PASSWORD;

					// Password
					for (int i = 0; i < password->Length; i++)
						buffer[4 + i] = password[i];

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
			System::Void btnChangeSSID_Click(System::Object^ sender, System::EventArgs^ e) 
			{
				if (device->Connected)
				{
					array<unsigned char>^ ssid = Encoding::ASCII->GetBytes(txtSSID->Text);
					array<unsigned char>^ buffer = gcnew array<unsigned char>(4 + ssid->Length);

					buffer[0] = 0xAA;
					buffer[1] = 0x55;
					// Tamanho do campo de dados
					buffer[2] = 1 + ssid->Length;
					// Comando
					buffer[3] = CMD_SEND_SSID;

					// SSID
					for (int i = 0; i < ssid->Length; i++)
						buffer[4 + i] = ssid[i];

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
			System::Void cbxResolution_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
			{
				updateAtSample = Convert::ToUInt32(cbxResolution->Items[cbxResolution->SelectedIndex]);
				saveComboBoxToConfig(cbxResolution);
			}

			System::Void txtRefT1_Change(System::Object^ sender, System::EventArgs^ e) 
			{
				float tempValue = getFloatFromTxBox(txtRefT1);

				if (Math::Abs(tempValue - T1ref) >= 0.001f)
				{
					T1ref = tempValue;
					saveTxtToConfig(txtRefT1);
				}
			}

			System::Void txtRefT1_Change(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					T1ref = getFloatFromTxBox(txtRefT1);

					saveTxtToConfig(txtRefT1);
				}
			}

			System::Void txtRefT2_Change(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getFloatFromTxBox(txtRefT2);

				if (Math::Abs(tempValue - T2ref) >= 0.001f)
				{
					T2ref = tempValue;
					saveTxtToConfig(txtRefT2);
				}
			}

			System::Void txtRefT2_Change(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					T2ref = getFloatFromTxBox(txtRefT2);

					saveTxtToConfig(txtRefT2);
				}
			}

			System::Void txtRefT3_Change(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getFloatFromTxBox(txtRefT3);

				if (Math::Abs(tempValue - T3ref) >= 0.001f)
				{
					T3ref = tempValue;
					saveTxtToConfig(txtRefT3);
				}
			}

			System::Void txtRefT3_Change(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					T3ref = getFloatFromTxBox(txtRefT3);

					saveTxtToConfig(txtRefT3);
				}
			}

			System::Void txtRefTC1_Change(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getFloatFromTxBox(txtRefTC1);

				if (Math::Abs(tempValue - TC1ref) >= 0.001f)
				{
					TC1ref = tempValue;
					saveTxtToConfig(txtRefTC1);
				}
			}

			System::Void txtRefTC1_Change(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					TC1ref = getFloatFromTxBox(txtRefTC1);

					saveTxtToConfig(txtRefTC1);
				}
			}

			System::Void txtRefTC2_Change(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getFloatFromTxBox(txtRefTC2);

				if (Math::Abs(tempValue - TC2ref) >= 0.001f)
				{
					TC2ref = tempValue;
					saveTxtToConfig(txtRefTC2);
				}
			}

			System::Void txtRefTC2_Change(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					TC2ref = getFloatFromTxBox(txtRefTC2);

					saveTxtToConfig(txtRefTC2);
				}
			}

			System::Void txtRefTC3_Change(System::Object^ sender, System::EventArgs^ e)
			{
				float tempValue = getFloatFromTxBox(txtRefTC3);

				if (Math::Abs(tempValue - TC3ref) >= 0.001f)
				{
					TC3ref = tempValue;
					saveTxtToConfig(txtRefTC3);
				}
			}

			System::Void txtRefTC3_Change(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
			{
				if (e->KeyChar == 13)
				{
					TC3ref = getFloatFromTxBox(txtRefTC3);

					saveTxtToConfig(txtRefTC3);
				}
			}
};
}
