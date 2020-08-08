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
	string ErrorEN[10] = { "Failed","Failed" ,"Failed" ,"Failed" ,"Failed" ,"Failed" ,"Failed" ,"Failed" ,"Failed" ,"Failed" };
	LCID lcid = GetSystemDefaultLangID();

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
			int GoActivate;
			if (lcid == 2052)
			{
				GoActivate = ::MessageBox(
					NULL,
					"δ����\n�Ƿ��������",
					"����",
					MB_ICONERROR | MB_YESNO);
			}
			else
			{
				GoActivate = ::MessageBox(
					NULL,
					"Switcher is not activated\nGo Activate?",
					"Error",
					MB_ICONERROR | MB_YESNO);
			}
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
		{
			Error[0] = "�ɹ�";
			ErrorEN[0] = "Success";
		}
		if ((_access(".\\Resources\\support.html", 0)) != -1)
		{
			Error[1] = "�ɹ�";
			ErrorEN[1] = "Success";
		}
		if ((_access(".\\Resources\\Updater.exe", 0)) != -1)
		{
			Error[2] = "�ɹ�";
			ErrorEN[2] = "Success";
		}
		if ((_access(".\\Resources\\addon.sver", 0)) != -1)
		{
			Error[3] = "�ɹ�";
			ErrorEN[3] = "Success";
		}
		if ((_access(".\\Resources\\AAS.exe", 0)) != -1)
		{
			Error[4] = "�ɹ�";
			ErrorEN[4] = "Success";
		}
		if ((_access(".\\Resources\\av.sver", 0)) != -1)
		{
			Error[5] = "�ɹ�";
			ErrorEN[5] = "Success";
		}
		if ((_access(".\\Resources\\xyl.exe", 0)) != -1)
		{
			Error[6] = "�ɹ�";
			ErrorEN[6] = "Success";
		}
		if ((_access(".\\Resources\\xv.sver", 0)) != -1)
		{
			Error[7] = "�ɹ�";
			ErrorEN[7] = "Success";
		}
		if ((_access(".\\Resources\\Activate.sact", 0)) != -1)
		{
			Error[8] = "�ɹ�";
			ErrorEN[8] = "Success";
		}
		if ((_access(".\\config\\server", 0)) != -1)
		{
			Error[9] = "�ɹ�";
			ErrorEN[9] = "Success";
		}
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
			resources->ApplyResources(this->Title, L"Title");
			this->Title->Name = L"Title";
			this->Title->TabStop = false;
			// 
			// AASICON
			// 
			resources->ApplyResources(this->AASICON, L"AASICON");
			this->AASICON->Name = L"AASICON";
			this->AASICON->TabStop = false;
			this->AASICON->Click += gcnew System::EventHandler(this, &MyForm::AASICON_Click);
			// 
			// XYLICON
			// 
			resources->ApplyResources(this->XYLICON, L"XYLICON");
			this->XYLICON->Name = L"XYLICON";
			this->XYLICON->TabStop = false;
			this->XYLICON->Click += gcnew System::EventHandler(this, &MyForm::XYLICON_Click);
			// 
			// About
			// 
			resources->ApplyResources(this->About, L"About");
			this->About->Name = L"About";
			this->About->UseVisualStyleBackColor = true;
			this->About->Click += gcnew System::EventHandler(this, &MyForm::About_Click);
			// 
			// CheckForUpdate
			// 
			resources->ApplyResources(this->CheckForUpdate, L"CheckForUpdate");
			this->CheckForUpdate->Name = L"CheckForUpdate";
			this->CheckForUpdate->UseVisualStyleBackColor = true;
			this->CheckForUpdate->Click += gcnew System::EventHandler(this, &MyForm::CheckForUpdate_Click);
			// 
			// Support
			// 
			resources->ApplyResources(this->Support, L"Support");
			this->Support->Name = L"Support";
			this->Support->UseVisualStyleBackColor = true;
			this->Support->Click += gcnew System::EventHandler(this, &MyForm::Support_Click);
			// 
			// ActivateStatusShow
			// 
			resources->ApplyResources(this->ActivateStatusShow, L"ActivateStatusShow");
			this->ActivateStatusShow->Name = L"ActivateStatusShow";
			this->ActivateStatusShow->Click += gcnew System::EventHandler(this, &MyForm::ActivateStatusShow_Click);
			// 
			// ServerShow
			// 
			resources->ApplyResources(this->ServerShow, L"ServerShow");
			this->ServerShow->Name = L"ServerShow";
			this->ServerShow->Click += gcnew System::EventHandler(this, &MyForm::ServerShow_Click);
			// 
			// ErrorPointer
			// 
			resources->ApplyResources(this->ErrorPointer, L"ErrorPointer");
			this->ErrorPointer->Name = L"ErrorPointer";
			this->ErrorPointer->Click += gcnew System::EventHandler(this, &MyForm::ErrorPointer_Click);
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->ErrorPointer);
			this->Controls->Add(this->ServerShow);
			this->Controls->Add(this->ActivateStatusShow);
			this->Controls->Add(this->Support);
			this->Controls->Add(this->CheckForUpdate);
			this->Controls->Add(this->About);
			this->Controls->Add(this->XYLICON);
			this->Controls->Add(this->AASICON);
			this->Controls->Add(this->Title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Title))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AASICON))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XYLICON))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		if (lcid == 2052)
			this->Text = L"������...";
		else this->Text = L"Loading...";
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
		{
			if (lcid == 2052)
				this->ServerShow->Text = L"���·�������Github";
			else
				this->ServerShow->Text = "Updater Server: Github";
		}
		if (Server == "Gitee")
		{
			if(lcid==2052)
				this->ServerShow->Text = L"���·�������Gitee";
			else
				this->ServerShow->Text = "Updater Server: Gitee";
		}
		SwitcherActivateJudgeFunc();
		if (ActivateStatus == TRUE)
		{
			if (lcid == 2052)
				this->ActivateStatusShow->Text = L"����״̬���Ѽ���";
			else this->ActivateStatusShow->Text = "Activated";
			this->Text = "Switcher";
		}
		else
		{
			if (lcid == 2052)
			{
				::MessageBox(
					NULL,
					"��ʹ�õ� Switcher ����δ������ܽ�������\n����ʹ��ǰ�ȼ�����Ƕ���������ߵ����ء�",
					"�������ǵ���������ܺ���",
					MB_ICONSTOP);
				this->ActivateStatusShow->Text = L"����״̬��δ����";
				this->Text = L"δ����� Switcher";
			}
			else
			{
				::MessageBox(
					NULL,
					"This copy of Switcher is not activated, some of the features may not work before getting activated.\nPlease activate Switcher first, this is a way of showing your respect to the developer.",
					"You're using a copy of not activated Switcher.",
					MB_ICONSTOP);
				this->ActivateStatusShow->Text = L"Not Activated";
				this->Text = L"Switcher - Not Activated";
			}
			
		}
		if (CheckError())
		{
			if (lcid == 2052)
				this->ErrorPointer->Text = L"����ָʾ��һ������";
			else this->ErrorPointer->Text = L"Nothing is wrong";
		}
		else
		{
			if(lcid==2052)
				this->ErrorPointer->Text = L"����ָʾ�����ڴ���";
			else this->ErrorPointer->Text = L"Something is wrong";
		}
	}
	private: System::Void AASICON_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Error[4] == "ʧ��")
		{
			if(lcid==2052)
				::MessageBox(NULL, "AAS �����򲻴���", "����", MB_ICONERROR);
			else
				::MessageBox(NULL, "AAS main executable file doesn't exist", "Error", MB_ICONERROR);
		}
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
		{
			if (lcid == 2052)
				::MessageBox(NULL, "Ф���ֵĹ��� �����򲻴���", "����", MB_ICONERROR);
			else
				::MessageBox(NULL, "The Story of XYL main executable file doesn't exist", "Error", MB_ICONERROR);
		}
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
			int Choice;
			if (lcid == 2052)
				Choice = ::MessageBox(NULL, "����Ҫʹ�����ð�� Updater ���� AAS �� Ф���ֵĹ���", "ע��", MB_ICONEXCLAMATION | MB_OKCANCEL);
			else Choice = ::MessageBox(NULL, "You are going to use Updater (in trial mode) to download AAS and The Story of XYL.", "Attention", MB_ICONEXCLAMATION | MB_OKCANCEL);
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
			int Choice;
			if(lcid==2052)
				Choice = ::MessageBox(NULL, "��Ҫ�������и��³����ڸ��¹������벻Ҫ�� Switcher\n�����߸������������ߵķ����� ( Github/Gitee )����Ҫ�Ϻõ��������ӣ�������ʹ�����߸��£�", "ע��", MB_ICONEXCLAMATION | MB_OKCANCEL);
			else
				Choice = ::MessageBox(NULL, "About to open Updater, do not open Switcher while updating.\nOnline update needs a good network connection, please use offline update packages otherwise.", "Attention", MB_ICONEXCLAMATION | MB_OKCANCEL);
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
		int Choice;
		if (lcid == 2052)
			Choice = ::MessageBox(NULL, "�Ƿ���ʾ���߰����ĵ���", "��ʾ", MB_ICONQUESTION | MB_YESNOCANCEL);
		else Choice = ::MessageBox(NULL, "Show online support document?", "Question", MB_ICONQUESTION | MB_YESNOCANCEL);
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
		int Choice;
		if(lcid==2052)
			Choice = ::MessageBox(
				NULL,
				"����ָ�л����·�������",
				"��ʾ",
				MB_ICONQUESTION | MB_YESNO);
		else
			Choice = ::MessageBox(
				NULL,
				"Did you mean switching the Updater Server?",
				"Question",
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
		{
			if(lcid==2052)
				this->ServerShow->Text = L"���·�������Github";
			else
				this->ServerShow->Text = L"Updater Server: Github";
		}
		if (Server == "Gitee")
		{
			if (lcid == 2052)
				this->ServerShow->Text = L"���·�������Gitee";
			else
				this->ServerShow->Text = L"Updater Server: Gitee";
		}
	}
	private: System::Void ActivateStatusShow_Click(System::Object^  sender, System::EventArgs^  e) {
		int Choice;
		if(lcid==2052)
			Choice = ::MessageBox(
				NULL,
				"����ָ���� Switcher ��",
				"��ʾ",
				MB_ICONQUESTION | MB_YESNO);
		else
			Choice = ::MessageBox(
				NULL,
				"Did you mean activating Switcher?",
				"Question",
				MB_ICONQUESTION | MB_YESNO);
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
		if (lcid == 2052)
			MessageBoxPrintf('i', "Switcher ������", "�������\n1. ���� ����� Activator.exe��%s\n2. ���� ���߰�����֧����ҳ support.html��%s\n3. ���� �������� Updater.exe��%s\n4. ���� ���Ӹ��°汾�ţ�%s\n5. ���� AAS ������%s\n6. ���� AAS �汾�ţ�%s\n7. ���� Ф���ֵĹ��� ������%s\n8. ���� Ф���ֵĹ��� �汾�ţ�%s\n9. ���ʼ�����֤�ִ���%s\n10. ���ʷ��������ã�%s", Error[0].c_str(), Error[1].c_str(), Error[2].c_str(), Error[3].c_str(), Error[4].c_str(), Error[5].c_str(), Error[6].c_str(), Error[7].c_str(), Error[8].c_str(), Error[9].c_str());
		else
			MessageBoxPrintf('i', "Switcher Error Check", "Result:\n1. Access Activate tool Activator.exe: %s\n2. Access offline support document support.html: %s\n3. Access online update tool Updater.exe: %s\n4. Access Add-on Update version file: %s\n5. Access AAS main executable file: %s\n6. Access AAS version file: %s\n7. Access The Story of XYL main executable file: %s\n8. Access The Story of XYL version file: %s\n9. Access activate status verification file: %s\n10. Access Updater Server config: %s", ErrorEN[0].c_str(), ErrorEN[1].c_str(), ErrorEN[2].c_str(), ErrorEN[3].c_str(), ErrorEN[4].c_str(), ErrorEN[5].c_str(), ErrorEN[6].c_str(), ErrorEN[7].c_str(), ErrorEN[8].c_str(), ErrorEN[9].c_str());
	}
};
}
