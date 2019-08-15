#pragma once
//#include "MyForm.h"
#include <fstream>
#include <cstring>
#include <Windows.h>
#include <shellapi.h>

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
	private: System::Windows::Forms::Label^ Credits;
	private: System::Windows::Forms::Label^ COPYR;
	private: System::Windows::Forms::Label^ OpenSource;



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
			this->Credits = (gcnew System::Windows::Forms::Label());
			this->COPYR = (gcnew System::Windows::Forms::Label());
			this->OpenSource = (gcnew System::Windows::Forms::Label());
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
			this->VersionSWI->Text = L"Build 1908\r\n内部版本 190800.0.1";
			// 
			// VersionINFO
			// 
			this->VersionINFO->AutoSize = true;
			this->VersionINFO->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->VersionINFO->Location = System::Drawing::Point(21, 151);
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
			this->addonver->Location = System::Drawing::Point(108, 169);
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
			this->AASVer->Location = System::Drawing::Point(98, 187);
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
			this->AASHEADL->Location = System::Drawing::Point(54, 187);
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
			this->XYLVer->Location = System::Drawing::Point(111, 206);
			this->XYLVer->Name = L"XYLVer";
			this->XYLVer->Size = System::Drawing::Size(75, 20);
			this->XYLVer->TabIndex = 7;
			this->XYLVer->Text = L"UNKNOW";
			// 
			// Credits
			// 
			this->Credits->AutoSize = true;
			this->Credits->Font = (gcnew System::Drawing::Font(L"微软雅黑", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Credits->Location = System::Drawing::Point(189, 151);
			this->Credits->Name = L"Credits";
			this->Credits->Size = System::Drawing::Size(340, 120);
			this->Credits->TabIndex = 8;
			this->Credits->Text = L"致谢：\r\nAAS @AAS_Final End K\r\n肖亚林的故事 @有益于\r\nSwitcher Main Executable @小dāi同学\r\nVC++ Co"
				L"mpiler Microsoft Visual Studio 2019\r\nIcons Disign The Congruent Triangles Icon G"
				L"roup";
			// 
			// COPYR
			// 
			this->COPYR->AutoSize = true;
			this->COPYR->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->COPYR->Location = System::Drawing::Point(22, 289);
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
			this->OpenSource->Location = System::Drawing::Point(22, 268);
			this->OpenSource->Name = L"OpenSource";
			this->OpenSource->Size = System::Drawing::Size(144, 17);
			this->OpenSource->TabIndex = 10;
			this->OpenSource->Text = L"Switcher 开源条款与条件";
			this->OpenSource->Click += gcnew System::EventHandler(this, &FormAbout::OpenSource_Click);
			// 
			// FormAbout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(529, 327);
			this->Controls->Add(this->OpenSource);
			this->Controls->Add(this->COPYR);
			this->Controls->Add(this->Credits);
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
	}
	private: System::Void OpenSource_Click(System::Object^ sender, System::EventArgs^ e) {
		ShellExecute(NULL, "open", "https://aasquandeng.github.io/Switcher/OpenSourceLicense.html", NULL, NULL, SW_SHOW);
	}
};
}
