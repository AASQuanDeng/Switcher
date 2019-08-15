#pragma once
#include <fstream>
#include <string>
#include <Windows.h>
#include <shellapi.h>
#include <cstdlib>
#include "Credits.h"
#pragma comment(lib,"advapi32.lib")

namespace Switcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Runtime::InteropServices;


	/// <summary>
	/// FormAbout 摘要
	/// </summary>
	public ref class FormAbout : public System::Windows::Forms::Form
	{
	public:
		FormAbout(void)
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
		~FormAbout()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ SWIICO;
	protected:
	private: System::Windows::Forms::Label^ AboutHead;
	private: System::Windows::Forms::Label^ VersionSWI;
	private: System::Windows::Forms::Label^ VersionINFO;
	private: System::Windows::Forms::Label^ addonver;
	private: System::Windows::Forms::Label^ AASVer;
	private: System::Windows::Forms::Label^ AASHEADL;
	private: System::Windows::Forms::Label^ XYLVer;

	private: System::Windows::Forms::Label^ COPYR;
	private: System::Windows::Forms::Label^ OpenSource;
	private: System::Windows::Forms::Label^ Apache_LIC;
	private: System::Windows::Forms::Button^ Show_CREDITS;
	private: System::Windows::Forms::Label^ According;
	private: System::Windows::Forms::Label^ Username;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormAbout::typeid));
			this->SWIICO = (gcnew System::Windows::Forms::PictureBox());
			this->AboutHead = (gcnew System::Windows::Forms::Label());
			this->VersionSWI = (gcnew System::Windows::Forms::Label());
			this->VersionINFO = (gcnew System::Windows::Forms::Label());
			this->addonver = (gcnew System::Windows::Forms::Label());
			this->AASVer = (gcnew System::Windows::Forms::Label());
			this->AASHEADL = (gcnew System::Windows::Forms::Label());
			this->XYLVer = (gcnew System::Windows::Forms::Label());
			this->COPYR = (gcnew System::Windows::Forms::Label());
			this->OpenSource = (gcnew System::Windows::Forms::Label());
			this->Apache_LIC = (gcnew System::Windows::Forms::Label());
			this->Show_CREDITS = (gcnew System::Windows::Forms::Button());
			this->According = (gcnew System::Windows::Forms::Label());
			this->Username = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SWIICO))->BeginInit();
			this->SuspendLayout();
			// 
			// SWIICO
			// 
			this->SWIICO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SWIICO.Image")));
			this->SWIICO->Location = System::Drawing::Point(12, 12);
			this->SWIICO->Name = L"SWIICO";
			this->SWIICO->Size = System::Drawing::Size(125, 125);
			this->SWIICO->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->SWIICO->TabIndex = 0;
			this->SWIICO->TabStop = false;
			// 
			// AboutHead
			// 
			this->AboutHead->AutoSize = true;
			this->AboutHead->Font = (gcnew System::Drawing::Font(L"微软雅黑", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->AboutHead->Location = System::Drawing::Point(169, 35);
			this->AboutHead->Name = L"AboutHead";
			this->AboutHead->Size = System::Drawing::Size(244, 46);
			this->AboutHead->TabIndex = 1;
			this->AboutHead->Text = L"Switcher LTS";
			// 
			// VersionSWI
			// 
			this->VersionSWI->AutoSize = true;
			this->VersionSWI->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10));
			this->VersionSWI->Location = System::Drawing::Point(174, 81);
			this->VersionSWI->Name = L"VersionSWI";
			this->VersionSWI->Size = System::Drawing::Size(139, 40);
			this->VersionSWI->TabIndex = 2;
			this->VersionSWI->Text = L"Build 1908 Beta 2\r\n内部版本 190800.0.2";
			// 
			// VersionINFO
			// 
			this->VersionINFO->AutoSize = true;
			this->VersionINFO->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->VersionINFO->Location = System::Drawing::Point(8, 149);
			this->VersionINFO->Name = L"VersionINFO";
			this->VersionINFO->Size = System::Drawing::Size(97, 80);
			this->VersionINFO->TabIndex = 3;
			this->VersionINFO->Text = L"组件版本：\r\n附加更新 No.\r\nAAS \r\n肖亚林的故事 ";
			// 
			// addonver
			// 
			this->addonver->AutoSize = true;
			this->addonver->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->addonver->Location = System::Drawing::Point(95, 167);
			this->addonver->Name = L"addonver";
			this->addonver->Size = System::Drawing::Size(75, 20);
			this->addonver->TabIndex = 4;
			this->addonver->Text = L"UNKNOW";
			// 
			// AASVer
			// 
			this->AASVer->AutoSize = true;
			this->AASVer->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->AASVer->Location = System::Drawing::Point(85, 185);
			this->AASVer->Name = L"AASVer";
			this->AASVer->Size = System::Drawing::Size(75, 20);
			this->AASVer->TabIndex = 5;
			this->AASVer->Text = L"UNKNOW";
			// 
			// AASHEADL
			// 
			this->AASHEADL->AutoSize = true;
			this->AASHEADL->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->AASHEADL->Location = System::Drawing::Point(41, 185);
			this->AASHEADL->Name = L"AASHEADL";
			this->AASHEADL->Size = System::Drawing::Size(75, 20);
			this->AASHEADL->TabIndex = 6;
			this->AASHEADL->Text = L"UNKNOW";
			// 
			// XYLVer
			// 
			this->XYLVer->AutoSize = true;
			this->XYLVer->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->XYLVer->Location = System::Drawing::Point(98, 204);
			this->XYLVer->Name = L"XYLVer";
			this->XYLVer->Size = System::Drawing::Size(75, 20);
			this->XYLVer->TabIndex = 7;
			this->XYLVer->Text = L"UNKNOW";
			// 
			// COPYR
			// 
			this->COPYR->AutoSize = true;
			this->COPYR->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->COPYR->Location = System::Drawing::Point(9, 275);
			this->COPYR->Name = L"COPYR";
			this->COPYR->Size = System::Drawing::Size(153, 34);
			this->COPYR->TabIndex = 9;
			this->COPYR->Text = L"Copyleft (ɔ) 2019 TCTDD,\r\nAll Rights Reserved.";
			// 
			// OpenSource
			// 
			this->OpenSource->AutoSize = true;
			this->OpenSource->Cursor = System::Windows::Forms::Cursors::Hand;
			this->OpenSource->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->OpenSource->ForeColor = System::Drawing::Color::Blue;
			this->OpenSource->Location = System::Drawing::Point(229, 149);
			this->OpenSource->Name = L"OpenSource";
			this->OpenSource->Size = System::Drawing::Size(188, 34);
			this->OpenSource->TabIndex = 10;
			this->OpenSource->Text = L"Switcher Open Source Licenses\r\nSwitcher Blogs";
			this->OpenSource->Click += gcnew System::EventHandler(this, &FormAbout::OpenSource_Click);
			// 
			// Apache_LIC
			// 
			this->Apache_LIC->AutoSize = true;
			this->Apache_LIC->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Apache_LIC->Location = System::Drawing::Point(179, 275);
			this->Apache_LIC->Name = L"Apache_LIC";
			this->Apache_LIC->Size = System::Drawing::Size(238, 17);
			this->Apache_LIC->TabIndex = 11;
			this->Apache_LIC->Text = L"This software obeys Apache License 2.0";
			// 
			// Show_CREDITS
			// 
			this->Show_CREDITS->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Show_CREDITS->Location = System::Drawing::Point(342, 295);
			this->Show_CREDITS->Name = L"Show_CREDITS";
			this->Show_CREDITS->Size = System::Drawing::Size(75, 23);
			this->Show_CREDITS->TabIndex = 12;
			this->Show_CREDITS->Text = L"致谢";
			this->Show_CREDITS->UseVisualStyleBackColor = true;
			this->Show_CREDITS->Click += gcnew System::EventHandler(this, &FormAbout::Show_CREDITS_Click);
			// 
			// According
			// 
			this->According->AutoSize = true;
			this->According->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->According->Location = System::Drawing::Point(229, 190);
			this->According->Name = L"According";
			this->According->Size = System::Drawing::Size(168, 34);
			this->According->TabIndex = 13;
			this->According->Text = L"根据 Switcher 授权条例\r\n许可以下用户使用 Switcher：";
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Username->Location = System::Drawing::Point(229, 224);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(67, 17);
			this->Username->TabIndex = 14;
			this->Username->Text = L"UNKNOW";
			// 
			// FormAbout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(429, 327);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->According);
			this->Controls->Add(this->Show_CREDITS);
			this->Controls->Add(this->Apache_LIC);
			this->Controls->Add(this->OpenSource);
			this->Controls->Add(this->COPYR);
			this->Controls->Add(this->XYLVer);
			this->Controls->Add(this->AASHEADL);
			this->Controls->Add(this->AASVer);
			this->Controls->Add(this->addonver);
			this->Controls->Add(this->VersionINFO);
			this->Controls->Add(this->VersionSWI);
			this->Controls->Add(this->AboutHead);
			this->Controls->Add(this->SWIICO);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormAbout";
			this->Text = L"关于 Switcher";
			this->Load += gcnew System::EventHandler(this, &FormAbout::FormAbout_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SWIICO))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormAbout_Load(System::Object^ sender, System::EventArgs^ e) {
		std::string AASVersion, XYLVersion, HeadOfAAS, AddonVersion;
		ifstream in;
		in.open(".\\Resources\\av.sver");
		in >> HeadOfAAS >> AASVersion;
		in.close();
		in.open(".\\Resources\\xv.sver");
		in >> XYLVersion;
		in.close();
		in.open(".\\Resources\\addon.sver");
		in >> AddonVersion;
		in.close();
		this->addonver->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)AddonVersion.c_str());
		this->AASHEADL->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)HeadOfAAS.c_str());
		this->AASVer->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)AASVersion.c_str());
		this->XYLVer->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)XYLVersion.c_str());
		string strBuffer = { 0 };
		DWORD dwSize = 256;
		GetUserName(const_cast<char*>(strBuffer.c_str()), &dwSize);
		this->Username->Text= Marshal::PtrToStringAnsi((IntPtr)(char*)strBuffer.c_str());
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
			;
		else
			this->Username->Text = "Not Activated";
	}
	private: System::Void OpenSource_Click(System::Object^ sender, System::EventArgs^ e) {
		ShellExecute(NULL, "open", "https://aasquandeng.github.io/", NULL, NULL, SW_SHOW);
	}
private: System::Void Show_CREDITS_Click(System::Object^ sender, System::EventArgs^ e) {
	Credits().ShowDialog();
}
};
}
