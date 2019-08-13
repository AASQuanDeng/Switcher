#pragma once
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <io.h>
#include <UrlMon.h>
#include <string>
#include "FormAbout.h"

#pragma comment(lib,"User32.lib") 
#pragma comment(lib,"shell32.lib")

using namespace std;
string AASVersion, XYLVersion, HeadOfAAS, AddonVersion;

namespace Switcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	ifstream in;
	bool ActivateStatus = FALSE;
	string Error[10] = { "ʧ��","ʧ��","ʧ��","ʧ��","ʧ��" ,"ʧ��" ,"ʧ��" ,"ʧ��" ,"ʧ��" ,"ʧ��" };

	int CDECL MessageBoxPrintf(char icontype, TCHAR *szCaption, TCHAR *szFormat, ...)
	{
		TCHAR szBuffer[1024];
		va_list pArgList;
		va_start(pArgList, szFormat);
		_vsntprintf(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);
		va_end(pArgList);
		if (icontype == 'i')
			return ::MessageBox(NULL, szBuffer, szCaption, MB_ICONINFORMATION);
		if (icontype == '!')
			return ::MessageBox(NULL, szBuffer, szCaption, MB_ICONWARNING);
		if (icontype == '?')
			return ::MessageBox(NULL, szBuffer, szCaption, MB_ICONQUESTION);
		if (icontype == 'x')
			return ::MessageBox(NULL, szBuffer, szCaption, MB_ICONERROR);
		if (icontype == ' ')
			return ::MessageBox(NULL, szBuffer, szCaption, NULL);
	}

	void SwitcherActivateJudgeFunc()
	{
		string KeyUsed;
		bool VerifyPoints[3] = { 0 };
		in.open(".\\Resources\\Activate.sact");
		in >> KeyUsed;
		in.close();
		for (int i = 1; i <= 9; i++)
		{
			if (KeyUsed[i] == 'U')
				VerifyPoints[0] = TRUE;
			if (KeyUsed[i] == 'S')
				VerifyPoints[1] = TRUE;
			if (KeyUsed[i] == 'A')
				VerifyPoints[2] = TRUE;
		}
		if (KeyUsed.size() == 11
			&& KeyUsed[0] == '{'
			&& KeyUsed[10] == '}'
			&& VerifyPoints[0]
			&& VerifyPoints[1]
			&& VerifyPoints[2])
			ActivateStatus = TRUE;
		else ActivateStatus = FALSE;
	}

	bool BeforeStart()
	{
		if (ActivateStatus == FALSE)
		{
			int GoActivate = ::MessageBox(
				NULL, 
				"δ����\n�Ƿ��������", 
				"����", 
				MB_ICONERROR | MB_YESNO);
			if (GoActivate == IDYES)
			{
				ShellExecute(
					NULL, 
					TEXT("runas"), 
					TEXT(".\\Resources\\Activator.exe"), 
					NULL, 
					NULL, 
					SW_SHOWNORMAL);
				exit(0);
			}
			return FALSE;
		}
		return TRUE;
	}

	bool CheckError()
	{
		bool tot = TRUE;
		if ((_access(".\\Resources\\Activator.exe", 0)) != -1)
			Error[0] = "�ɹ�";
		if ((_access(".\\Resources\\support.html", 0)) != -1)
			Error[1] = "�ɹ�";
		if ((_access(".\\Resources\\Updater.exe", 0)) != -1)
			Error[2] = "�ɹ�";
		if ((_access(".\\Resources\\addon.sver", 0)) != -1)
			Error[3] = "�ɹ�";
		if ((_access(".\\Resources\\AAS.exe", 0)) != -1)
			Error[4] = "�ɹ�";
		if ((_access(".\\Resources\\av.sver", 0)) != -1)
			Error[5] = "�ɹ�";
		if ((_access(".\\Resources\\xyl.exe", 0)) != -1)
			Error[6] = "�ɹ�";
		if ((_access(".\\Resources\\xv.sver", 0)) != -1)
			Error[7] = "�ɹ�";
		if ((_access(".\\Resources\\Activate.sact", 0)) != -1)
			Error[8] = "�ɹ�";
		if ((_access(".\\config\\server", 0)) != -1)
			Error[9] = "�ɹ�";
		for (int i = 0; i <= 9; i++)
		{
			if (Error[i] == "ʧ��")
			{
				tot = FALSE;
				break;
			}
		}
		return tot;
	}

	/// <summary>
	/// MyForm ժҪ
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  Title;
	private: System::Windows::Forms::PictureBox^  AASICON;
	private: System::Windows::Forms::PictureBox^  XYLICON;
	private: System::Windows::Forms::Button^  About;
	private: System::Windows::Forms::Button^  CheckForUpdate;
	private: System::Windows::Forms::Button^  Support;



	private: System::Windows::Forms::Label^  ActivateStatusShow;
	private: System::Windows::Forms::Label^  ServerShow;
	private: System::Windows::Forms::Label^ ErrorPointer;


	protected:

	protected:



	protected:


	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ�޸�
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Title = (gcnew System::Windows::Forms::PictureBox());
			this->AASICON = (gcnew System::Windows::Forms::PictureBox());
			this->XYLICON = (gcnew System::Windows::Forms::PictureBox());
			this->About = (gcnew System::Windows::Forms::Button());
			this->CheckForUpdate = (gcnew System::Windows::Forms::Button());
			this->Support = (gcnew System::Windows::Forms::Button());
			this->ActivateStatusShow = (gcnew System::Windows::Forms::Label());
			this->ServerShow = (gcnew System::Windows::Forms::Label());
			this->ErrorPointer = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Title))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AASICON))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XYLICON))->BeginInit();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Title.Image")));
			this->Title->Location = System::Drawing::Point(0, 0);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(385, 96);
			this->Title->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Title->TabIndex = 0;
			this->Title->TabStop = false;
			// 
			// AASICON
			// 
			this->AASICON->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AASICON.Image")));
			this->AASICON->Location = System::Drawing::Point(50, 136);
			this->AASICON->Name = L"AASICON";
			this->AASICON->Size = System::Drawing::Size(100, 100);
			this->AASICON->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->AASICON->TabIndex = 1;
			this->AASICON->TabStop = false;
			this->AASICON->Click += gcnew System::EventHandler(this, &MyForm::AASICON_Click);
			// 
			// XYLICON
			// 
			this->XYLICON->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"XYLICON.Image")));
			this->XYLICON->Location = System::Drawing::Point(232, 136);
			this->XYLICON->Name = L"XYLICON";
			this->XYLICON->Size = System::Drawing::Size(100, 100);
			this->XYLICON->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->XYLICON->TabIndex = 2;
			this->XYLICON->TabStop = false;
			this->XYLICON->Click += gcnew System::EventHandler(this, &MyForm::XYLICON_Click);
			// 
			// About
			// 
			this->About->Font = (gcnew System::Drawing::Font(L"΢���ź�", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->About->Location = System::Drawing::Point(12, 304);
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(100, 23);
			this->About->TabIndex = 3;
			this->About->Text = L"����";
			this->About->UseVisualStyleBackColor = true;
			this->About->Click += gcnew System::EventHandler(this, &MyForm::About_Click);
			// 
			// CheckForUpdate
			// 
			this->CheckForUpdate->Font = (gcnew System::Drawing::Font(L"΢���ź�", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->CheckForUpdate->Location = System::Drawing::Point(141, 304);
			this->CheckForUpdate->Name = L"CheckForUpdate";
			this->CheckForUpdate->Size = System::Drawing::Size(100, 23);
			this->CheckForUpdate->TabIndex = 4;
			this->CheckForUpdate->Text = L"������";
			this->CheckForUpdate->UseVisualStyleBackColor = true;
			this->CheckForUpdate->Click += gcnew System::EventHandler(this, &MyForm::CheckForUpdate_Click);
			// 
			// Support
			// 
			this->Support->Font = (gcnew System::Drawing::Font(L"΢���ź�", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Support->Location = System::Drawing::Point(272, 304);
			this->Support->Name = L"Support";
			this->Support->Size = System::Drawing::Size(100, 23);
			this->Support->TabIndex = 5;
			this->Support->Text = L"������֧��";
			this->Support->UseVisualStyleBackColor = true;
			this->Support->Click += gcnew System::EventHandler(this, &MyForm::Support_Click);
			// 
			// ActivateStatusShow
			// 
			this->ActivateStatusShow->AutoSize = true;
			this->ActivateStatusShow->Font = (gcnew System::Drawing::Font(L"΢���ź�", 7));
			this->ActivateStatusShow->Location = System::Drawing::Point(296, 342);
			this->ActivateStatusShow->Name = L"ActivateStatusShow";
			this->ActivateStatusShow->Size = System::Drawing::Size(78, 16);
			this->ActivateStatusShow->TabIndex = 6;
			this->ActivateStatusShow->Text = L"����״̬��δ֪";
			this->ActivateStatusShow->Click += gcnew System::EventHandler(this, &MyForm::ActivateStatusShow_Click);
			// 
			// ServerShow
			// 
			this->ServerShow->AutoSize = true;
			this->ServerShow->Font = (gcnew System::Drawing::Font(L"΢���ź�", 7));
			this->ServerShow->Location = System::Drawing::Point(12, 342);
			this->ServerShow->Name = L"ServerShow";
			this->ServerShow->Size = System::Drawing::Size(88, 16);
			this->ServerShow->TabIndex = 7;
			this->ServerShow->Text = L"���·�������δ֪";
			this->ServerShow->Click += gcnew System::EventHandler(this, &MyForm::ServerShow_Click);
			// 
			// ErrorPointer
			// 
			this->ErrorPointer->AutoSize = true;
			this->ErrorPointer->Font = (gcnew System::Drawing::Font(L"΢���ź�", 7));
			this->ErrorPointer->Location = System::Drawing::Point(142, 342);
			this->ErrorPointer->Name = L"ErrorPointer";
			this->ErrorPointer->Size = System::Drawing::Size(105, 16);
			this->ErrorPointer->TabIndex = 8;
			this->ErrorPointer->Text = L"����ָʾ��UNKNOW";
			this->ErrorPointer->Click += gcnew System::EventHandler(this, &MyForm::ErrorPointer_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(384, 361);
			this->Controls->Add(this->ErrorPointer);
			this->Controls->Add(this->ServerShow);
			this->Controls->Add(this->ActivateStatusShow);
			this->Controls->Add(this->Support);
			this->Controls->Add(this->CheckForUpdate);
			this->Controls->Add(this->About);
			this->Controls->Add(this->XYLICON);
			this->Controls->Add(this->AASICON);
			this->Controls->Add(this->Title);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"״̬δ֪";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Title))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AASICON))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XYLICON))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->Text = L"������";
		in.open(".\\Resources\\av.sver");
		in >> HeadOfAAS >> AASVersion;
		in.close();
		in.open(".\\Resources\\xv.sver");
		in >> XYLVersion;
		in.close();
		in.open(".\\Resources\\addon.sver");
		in >> AddonVersion;
		in.close();
		in.open(".\\config\\server");
		string Server;
		in >> Server;
		in.close();
		if (Server == "Github")
			this->ServerShow->Text = L"���·�������Github";
		if (Server == "Gitee")
			this->ServerShow->Text = L"���·�������Gitee";
		SwitcherActivateJudgeFunc();
		if (ActivateStatus == TRUE)
		{
			this->ActivateStatusShow->Text = L"����״̬���Ѽ���";
			this->Text = "Switcher";
		}
		else
		{
			::MessageBox(
				NULL,
				"��ʹ�õ� Switcher ����δ������ܽ�������\n����ʹ��ǰ�ȼ�����Ƕ���������ߵ����ء�",
				"�������ǵ���������ܺ���",
				MB_ICONSTOP);
			this->ActivateStatusShow->Text = L"����״̬��δ����";
			this->Text = L"δ����� Switcher";
		}
		if (CheckError())
			this->ErrorPointer->Text = L"����ָʾ��һ������";
		else
			this->ErrorPointer->Text = L"����ָʾ�����ڴ���";
	}
	private: System::Void AASICON_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Error[4] == "ʧ��")
			::MessageBox(NULL, "AAS �����򲻴���", "����", MB_ICONERROR);
		ShellExecute(
			NULL,
			"open",
			".\\Resources\\AAS.exe",
			NULL,
			NULL,
			SW_SHOWNORMAL);		
	}
	private: System::Void XYLICON_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Error[6] == "ʧ��")
			::MessageBox(NULL, "Ф���ֵĹ��� �����򲻴���", "����", MB_ICONERROR);
		ShellExecute(
			NULL,
			"runas",
			".\\Resources\\xyl.exe",
			NULL,
			NULL,
			SW_SHOWNORMAL);
	}
	private: System::Void About_Click(System::Object^  sender, System::EventArgs^  e) {
		FormAbout().ShowDialog();
	}
	private: System::Void CheckForUpdate_Click(System::Object^  sender, System::EventArgs^  e) {
		if ((_access(".\\config\\Demo", 0)) != -1 && ActivateStatus == FALSE)
		{
			int Choice = ::MessageBox(NULL, "����Ҫʹ�����ð�� Updater ���� AAS �� Ф���ֵĹ���", "ע��", MB_ICONEXCLAMATION | MB_OKCANCEL);
			if (Choice == IDOK)
			{
				ShellExecute(
					NULL,
					TEXT("runas"),
					TEXT(".\\Resources\\Updater.exe"),
					"T",
					NULL,
					SW_SHOWNORMAL);
				exit(0);
			}
			else return;
		}
		if (BeforeStart())
		{
			DeleteFile(".\\config\\DEMO");
			int Choice = ::MessageBox(NULL, "��Ҫ�������и��³����ڸ��¹������벻Ҫ�� Switcher\n�����߸������������ߵķ����� ( Github/Gitee )����Ҫ�Ϻõ��������ӣ�������ʹ�����߸��£�", "ע��", MB_ICONEXCLAMATION | MB_OKCANCEL);
			if (Choice == IDOK)
			{
				ShellExecute(
					NULL,
					TEXT("runas"),
					TEXT(".\\Resources\\Updater.exe"),
					"N",
					NULL,
					SW_SHOWNORMAL);
				exit(0);
			}
		}
	}
	private: System::Void Support_Click(System::Object^  sender, System::EventArgs^  e) {
		int Choice = ::MessageBox(NULL, "�Ƿ���ʾ���߰����ĵ���", "��ʾ", MB_ICONQUESTION | MB_YESNOCANCEL);
		if(Choice==IDYES)
			ShellExecute(
				NULL,
				"open",
				"https://aasquandeng.github.io/",
				NULL,
				NULL,
				SW_SHOWNORMAL);
		if(Choice==IDNO)
			ShellExecute(
				NULL,
				"open",
				".\\Resources\\support.html",
				NULL,
				NULL,
				SW_SHOWNORMAL);

	}
	private: System::Void ServerShow_Click(System::Object^  sender, System::EventArgs^  e) {
		int Choice = ::MessageBox(
			NULL,
			"����ָ�л����·�������",
			"��ʾ",
			MB_ICONQUESTION | MB_YESNO);
		if (Choice == IDYES)
		{
			string Server;
			in.open(".\\config\\server");
			in >> Server;
			in.close();
			ofstream out;
			out.open(".\\config\\server");
			if (Server == "Github")
				out << "Gitee" << endl;
			else out << "Github" << endl;
		}
		in.open(".\\config\\server");
		string Server;
		in >> Server;
		in.close();
		if (Server == "Github")
			this->ServerShow->Text = L"���·�������Github";
		if (Server == "Gitee")
			this->ServerShow->Text = L"���·�������Gitee";
	}
	private: System::Void ActivateStatusShow_Click(System::Object^  sender, System::EventArgs^  e) {
		int Choice = ::MessageBox(
			NULL,
			"����ָ���� Switcher ��",
			"��ʾ",
			MB_ICONQUESTION|MB_YESNO);
		if (Choice == IDYES)
		{
			ShellExecute(
				NULL,
				"runas",
				".\\Resources\\Activator.exe",
				NULL,
				NULL,
				SW_SHOWNORMAL);
			exit(0);
		}
	}
	private: System::Void ErrorPointer_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBoxPrintf('i', "Switcher ������", "�������\n1. ���� ����� Activator.exe��%s\n2. ���� ���߰�����֧����ҳ support.html��%s\n3. ���� �������� Updater.exe��%s\n4. ���� ���Ӹ��°汾�ţ�%s\n5. ���� AAS ������%s\n6. ���� AAS �汾�ţ�%s\n7. ���� Ф���ֵĹ��� ������%s\n8. ���� Ф���ֵĹ��� �汾�ţ�%s\n9. ���ʼ�����֤�ִ���%s\n10. ���ʷ��������ã�%s", Error[0].c_str(), Error[1].c_str(), Error[2].c_str(), Error[3].c_str(), Error[4].c_str(), Error[5].c_str(), Error[6].c_str(), Error[7].c_str(), Error[8].c_str(), Error[9].c_str());
	}
};
}
