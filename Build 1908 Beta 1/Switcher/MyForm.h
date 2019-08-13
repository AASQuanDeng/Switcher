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
	string Error[10] = { "失败","失败","失败","失败","失败" ,"失败" ,"失败" ,"失败" ,"失败" ,"失败" };

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
				"未激活\n是否立即激活？", 
				"错误", 
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
			Error[0] = "成功";
		if ((_access(".\\Resources\\support.html", 0)) != -1)
			Error[1] = "成功";
		if ((_access(".\\Resources\\Updater.exe", 0)) != -1)
			Error[2] = "成功";
		if ((_access(".\\Resources\\addon.sver", 0)) != -1)
			Error[3] = "成功";
		if ((_access(".\\Resources\\AAS.exe", 0)) != -1)
			Error[4] = "成功";
		if ((_access(".\\Resources\\av.sver", 0)) != -1)
			Error[5] = "成功";
		if ((_access(".\\Resources\\xyl.exe", 0)) != -1)
			Error[6] = "成功";
		if ((_access(".\\Resources\\xv.sver", 0)) != -1)
			Error[7] = "成功";
		if ((_access(".\\Resources\\Activate.sact", 0)) != -1)
			Error[8] = "成功";
		if ((_access(".\\config\\server", 0)) != -1)
			Error[9] = "成功";
		for (int i = 0; i <= 9; i++)
		{
			if (Error[i] == "失败")
			{
				tot = FALSE;
				break;
			}
		}
		return tot;
	}

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
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
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
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
			this->About->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->About->Location = System::Drawing::Point(12, 304);
			this->About->Name = L"About";
			this->About->Size = System::Drawing::Size(100, 23);
			this->About->TabIndex = 3;
			this->About->Text = L"关于";
			this->About->UseVisualStyleBackColor = true;
			this->About->Click += gcnew System::EventHandler(this, &MyForm::About_Click);
			// 
			// CheckForUpdate
			// 
			this->CheckForUpdate->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->CheckForUpdate->Location = System::Drawing::Point(141, 304);
			this->CheckForUpdate->Name = L"CheckForUpdate";
			this->CheckForUpdate->Size = System::Drawing::Size(100, 23);
			this->CheckForUpdate->TabIndex = 4;
			this->CheckForUpdate->Text = L"检查更新";
			this->CheckForUpdate->UseVisualStyleBackColor = true;
			this->CheckForUpdate->Click += gcnew System::EventHandler(this, &MyForm::CheckForUpdate_Click);
			// 
			// Support
			// 
			this->Support->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Support->Location = System::Drawing::Point(272, 304);
			this->Support->Name = L"Support";
			this->Support->Size = System::Drawing::Size(100, 23);
			this->Support->TabIndex = 5;
			this->Support->Text = L"帮助与支持";
			this->Support->UseVisualStyleBackColor = true;
			this->Support->Click += gcnew System::EventHandler(this, &MyForm::Support_Click);
			// 
			// ActivateStatusShow
			// 
			this->ActivateStatusShow->AutoSize = true;
			this->ActivateStatusShow->Font = (gcnew System::Drawing::Font(L"微软雅黑", 7));
			this->ActivateStatusShow->Location = System::Drawing::Point(296, 342);
			this->ActivateStatusShow->Name = L"ActivateStatusShow";
			this->ActivateStatusShow->Size = System::Drawing::Size(78, 16);
			this->ActivateStatusShow->TabIndex = 6;
			this->ActivateStatusShow->Text = L"激活状态：未知";
			this->ActivateStatusShow->Click += gcnew System::EventHandler(this, &MyForm::ActivateStatusShow_Click);
			// 
			// ServerShow
			// 
			this->ServerShow->AutoSize = true;
			this->ServerShow->Font = (gcnew System::Drawing::Font(L"微软雅黑", 7));
			this->ServerShow->Location = System::Drawing::Point(12, 342);
			this->ServerShow->Name = L"ServerShow";
			this->ServerShow->Size = System::Drawing::Size(88, 16);
			this->ServerShow->TabIndex = 7;
			this->ServerShow->Text = L"更新服务器：未知";
			this->ServerShow->Click += gcnew System::EventHandler(this, &MyForm::ServerShow_Click);
			// 
			// ErrorPointer
			// 
			this->ErrorPointer->AutoSize = true;
			this->ErrorPointer->Font = (gcnew System::Drawing::Font(L"微软雅黑", 7));
			this->ErrorPointer->Location = System::Drawing::Point(142, 342);
			this->ErrorPointer->Name = L"ErrorPointer";
			this->ErrorPointer->Size = System::Drawing::Size(105, 16);
			this->ErrorPointer->TabIndex = 8;
			this->ErrorPointer->Text = L"错误指示：UNKNOW";
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
			this->Text = L"状态未知";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Title))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AASICON))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XYLICON))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->Text = L"加载中";
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
			this->ServerShow->Text = L"更新服务器：Github";
		if (Server == "Gitee")
			this->ServerShow->Text = L"更新服务器：Gitee";
		SwitcherActivateJudgeFunc();
		if (ActivateStatus == TRUE)
		{
			this->ActivateStatusShow->Text = L"激活状态：已激活";
			this->Text = "Switcher";
		}
		else
		{
			::MessageBox(
				NULL,
				"您使用的 Switcher 副本未激活，功能将会受限\n请在使用前先激活，这是对软件开发者的尊重。",
				"您可能是盗版软件的受害者",
				MB_ICONSTOP);
			this->ActivateStatusShow->Text = L"激活状态：未激活";
			this->Text = L"未激活的 Switcher";
		}
		if (CheckError())
			this->ErrorPointer->Text = L"错误指示：一切正常";
		else
			this->ErrorPointer->Text = L"错误指示：存在错误";
	}
	private: System::Void AASICON_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Error[4] == "失败")
			::MessageBox(NULL, "AAS 主程序不存在", "错误", MB_ICONERROR);
		ShellExecute(
			NULL,
			"open",
			".\\Resources\\AAS.exe",
			NULL,
			NULL,
			SW_SHOWNORMAL);		
	}
	private: System::Void XYLICON_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Error[6] == "失败")
			::MessageBox(NULL, "肖亚林的故事 主程序不存在", "错误", MB_ICONERROR);
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
			int Choice = ::MessageBox(NULL, "您将要使用试用版的 Updater 下载 AAS 和 肖亚林的故事", "注意", MB_ICONEXCLAMATION | MB_OKCANCEL);
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
			int Choice = ::MessageBox(NULL, "将要打开命令行更新程序，在更新过程中请不要打开 Switcher\n（在线更新依赖于在线的服务器 ( Github/Gitee )，需要较好的网络连接，否则，请使用离线更新）", "注意", MB_ICONEXCLAMATION | MB_OKCANCEL);
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
		int Choice = ::MessageBox(NULL, "是否显示在线帮助文档？", "提示", MB_ICONQUESTION | MB_YESNOCANCEL);
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
			"您是指切换更新服务器吗？",
			"提示",
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
			this->ServerShow->Text = L"更新服务器：Github";
		if (Server == "Gitee")
			this->ServerShow->Text = L"更新服务器：Gitee";
	}
	private: System::Void ActivateStatusShow_Click(System::Object^  sender, System::EventArgs^  e) {
		int Choice = ::MessageBox(
			NULL,
			"您是指激活 Switcher 吗？",
			"提示",
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
		MessageBoxPrintf('i', "Switcher 错误检查", "检查结果：\n1. 访问 激活工具 Activator.exe：%s\n2. 访问 离线帮助与支持网页 support.html：%s\n3. 访问 升级工具 Updater.exe：%s\n4. 访问 附加更新版本号：%s\n5. 访问 AAS 主程序：%s\n6. 访问 AAS 版本号：%s\n7. 访问 肖亚林的故事 主程序：%s\n8. 访问 肖亚林的故事 版本号：%s\n9. 访问激活验证字串：%s\n10. 访问服务器配置：%s", Error[0].c_str(), Error[1].c_str(), Error[2].c_str(), Error[3].c_str(), Error[4].c_str(), Error[5].c_str(), Error[6].c_str(), Error[7].c_str(), Error[8].c_str(), Error[9].c_str());
	}
};
}
