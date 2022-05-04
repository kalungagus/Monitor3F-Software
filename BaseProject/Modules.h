//***************************************************************************************
//                                        Modules
//***************************************************************************************
#pragma once
#include "CommDevices.h"

//***************************************************************************************
// Definição de comandos utilizados pelos módulos
//***************************************************************************************
#define CMD_RESET                0x80
#define CMD_MESSAGE              0x81
#define CMD_SET_SAMPLING_STATE   0x82
#define CMD_SEND_ECHO            0x83
#define CMD_GET_ADC_READING      0x84
#define CMD_SAMPLE_SEND          0x85

//***************************************************************************************
// Classes
//***************************************************************************************
namespace Modules
{
	using namespace System;
	using namespace System::IO;
	using namespace System::IO::Ports;
	using namespace System::Threading;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Text;
	using namespace CommDevices;

	//***********************************************************************************
	// Delegates
	//***********************************************************************************
	public delegate void ModuleReception(Object ^, array<unsigned char>^);
	public delegate void ModuleDisconnection(Object ^);

	//***********************************************************************************
	// Objects
	//***********************************************************************************
	public ref class Module
	{
		protected:
			Thread^ ReceptionThread;
			int rcvPos, rcvLimit;
			unsigned char chkSum;
			array<Byte>^ receptionBuffer;
			int dataPos = 0;
			int state = 0;

		public:
			CommLayer ^Comm;
			ModuleReception ^onReceive;
			ModuleDisconnection ^onDisconnection;

			//===========================================================================
			// Construtores
			//===========================================================================
			Module() { Comm = nullptr; rcvPos = 0; state = 0; };
			Module(CommLayer ^c) { Comm = c; rcvPos = 0; state = 0; };

			//===========================================================================
			// Propriedades
			//===========================================================================
			property bool Connected
			{
				bool get()
				{
					if (Object::ReferenceEquals(Comm, nullptr) == false)
						return(Comm->Connected);
					else
						return(false);
				}
				void set(bool state)
				{
					if (Object::ReferenceEquals(Comm, nullptr) == false)
						Comm->Connected = state;
				}
			}
			// Retorna a quantidade de dados no buffer de recepção
			property int BytesToRead
			{
				virtual int get(void)
				{
					int bytes;
					try
					{
						bytes = Comm->BytesToRead;
					}
					catch (System::IO::IOException ^)
					{
						onDisconnection(this);
					}
					return(bytes);
				}
			}

			//===========================================================================
			// Métodos
			//===========================================================================
			void Open(void)
			{
				if (Object::ReferenceEquals(Comm, nullptr) == false)
				{
					Comm->Open();
					if (Comm->Connected)
					{
						this->ReceptionThread = gcnew Thread(gcnew ThreadStart(this, &Module::ReceptionService));
						this->ReceptionThread->Start();
					}
				}
			}
			void Close(void)
			{
				try
				{
					if (Object::ReferenceEquals(Comm, nullptr) == false)
					{
						Comm->Close();
						this->ReceptionThread->Abort();
					}
				}
				catch (NullReferenceException ^) {}
			}
			// Escreve um array de caracteres no buffer de transmissão
			void Write(array<unsigned char>^ buffer, int offset, int size)
			{
				if (Object::ReferenceEquals(Comm, nullptr) == false)
					Comm->Write(buffer, offset, size);
			}
			// Lê dados presentes no buffer de recepção
			int Read(array<unsigned char>^ buffer, int offset, int size)
			{
				if (Object::ReferenceEquals(Comm, nullptr) == false)
					return (Comm->Read(buffer, offset, size));
				else
					return (0);
			}
			// Rotina de tratamento de recepção
			void ReceptionService(void)
			{
				int bytePos = 0, bytesToRead, readedBytes;
				array<unsigned char>^ header = gcnew array<Byte>(4);

				while (Comm->Connected)
				{
					try
					{
						if (Comm->BytesToRead)
						{
							readedBytes = Comm->Read(header, 0, header->Length);
							if (header[0] == 0xAA && header[1] == 0x55)
							{
								bytesToRead = BitConverter::ToUInt16(header, 2);
								receptionBuffer = gcnew array<Byte>(bytesToRead);
								readedBytes = 0;

								while (readedBytes < bytesToRead)
									readedBytes += Comm->Read(receptionBuffer, 0, receptionBuffer->Length);

								onReceive(this, receptionBuffer);
							}
						}
					}
					catch (System::IO::IOException ^)
					{
						onDisconnection(this);
						continue;
					}

					Thread::Sleep(10);
				}
			}
	};

	public ref class Pin
	{
		protected:
			String ^name;
			int id;
		public:
			Pin(int i) 
			{ 
				array<unsigned char>^ convertArray;

				id = i;
				convertArray = BitConverter::GetBytes(i);
				switch (convertArray[1])
				{
					case 0x00:
						name = String::Format("RA{0}", convertArray[0]);
						break;
					case 0x01:
						name = String::Format("RB{0}", convertArray[0]);
						break;
					case 0x02:
						name = String::Format("RC{0}", convertArray[0]);
						break;
					case 0x03:
						name = String::Format("RD{0}", convertArray[0]);
						break;
					case 0x04:
						name = String::Format("RE{0}", convertArray[0]);
						break;
					case 0x05:
						name = String::Format("RF{0}", convertArray[0]);
						break;
					case 0x06:
						name = String::Format("RG{0}", convertArray[0]);
						break;
					default:
						break;
				}
			};
			property int ID
			{
				virtual int get(void)
				{
					return(id);
				}
			}
			String ^ToString(void) override
			{
				return(name);
			}
	};
}