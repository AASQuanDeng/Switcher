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






	private: System::Windows::Forms::Label^ COPYR;
	private: System::Windows::Forms::Label^ OpenSource;
	private: System::Windows::Forms::Label^ Apache_LIC;
	private: System::Windows::Forms::Button^ Show_CREDITS;
	private: System::Windows::Forms::Label^ According;
	private: System::Windows::Forms::Label^ Username;
	private: System::Windows::Forms::Button^ About_close;
	private: System::Windows::Forms::Label^ Version_info_head;
	private: System::Windows::Forms::Label^ addonverlabel;
	private: System::Windows::Forms::Label^ aasverlabel;
	private: System::Windows::Forms::Label^ xylverlabel;



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
			this->COPYR = (gcnew System::Windows::Forms::Label());
			this->OpenSource = (gcnew System::Windows::Forms::Label());
			this->Apache_LIC = (gcnew System::Windows::Forms::Label());
			this->Show_CREDITS = (gcnew System::Windows::Forms::Button());
			this->According = (gcnew System::Windows::Forms::Label());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->About_close = (gcnew System::Windows::Forms::Button());
			this->Version_info_head = (gcnew System::Windows::Forms::Label());
			this->addonverlabel = (gcnew System::Windows::Forms::Label());
			this->aasverlabel = (gcnew System::Windows::Forms::Label());
			this->xylverlabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SWIICO))->BeginInit();
			this->SuspendLayout();
			// 
			// SWIICO
			// 
			resources->ApplyResources(this->SWIICO, L"SWIICO");
			this->SWIICO->Name = L"SWIICO";
			this->SWIICO->TabStop = false;
			// 
			// AboutHead
			// 
			resources->ApplyResources(this->AboutHead, L"AboutHead");
			this->AboutHead->Name = L"AboutHead";
			// 
			// VersionSWI
			// 
			resources->ApplyResources(this->VersionSWI, L"VersionSWI");
			this->VersionSWI->Name = L"VersionSWI";
			// 
			// COPYR
			// 
			resources->ApplyResources(this->COPYR, L"COPYR");
			this->COPYR->Name = L"COPYR";
			// 
			// OpenSource
			// 
			resources->ApplyResources(this->OpenSource, L"OpenSource");
			this->OpenSource->Cursor = System::Windows::Forms::Cursors::Hand;
			this->OpenSource->ForeColor = System::Drawing::Color::Blue;
			this->OpenSource->Name = L"OpenSource";
			this->OpenSource->Click += gcnew System::EventHandler(this, &FormAbout::OpenSource_Click);
			// 
			// Apache_LIC
			// 
			resources->ApplyResources(this->Apache_LIC, L"Apache_LIC");
			this->Apache_LIC->Name = L"Apache_LIC";
			// 
			// Show_CREDITS
			// 
			resources->ApplyResources(this->Show_CREDITS, L"Show_CREDITS");
			this->Show_CREDITS->Name = L"Show_CREDITS";
			this->Show_CREDITS->UseVisualStyleBackColor = true;
			this->Show_CREDITS->Click += gcnew System::EventHandler(this, &FormAbout::Show_CREDITS_Click);
			// 
			// According
			// 
			resources->ApplyResources(this->According, L"According");
			this->According->Name = L"According";
			// 
			// Username
			// 
			resources->ApplyResources(this->Username, L"Username");
			this->Username->Name = L"Username";
			// 
			// About_close
			// 
			resources->ApplyResources(this->About_close, L"About_close");
			this->About_close->Name = L"About_close";
			this->About_close->UseVisualStyleBackColor = true;
			this->About_close->Click += gcnew System::EventHandler(this, &FormAbout::About_close_Click);
			// 
			// Version_info_head
			// 
			resources->ApplyResources(this->Version_info_head, L"Version_info_head");
			this->Version_info_head->Name = L"Version_info_head";
			// 
			// addonverlabel
			// 
			resources->ApplyResources(this->addonverlabel, L"addonverlabel");
			this->addonverlabel->Name = L"addonverlabel";
			// 
			// aasverlabel
			// 
			resources->ApplyResources(this->aasverlabel, L"aasverlabel");
			this->aasverlabel->Name = L"aasverlabel";
			// 
			// xylverlabel
			// 
			resources->ApplyResources(this->xylverlabel, L"xylverlabel");
			this->xylverlabel->Name = L"xylverlabel";
			// 
			// FormAbout
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->xylverlabel);
			this->Controls->Add(this->aasverlabel);
			this->Controls->Add(this->addonverlabel);
			this->Controls->Add(this->Version_info_head);
			this->Controls->Add(this->About_close);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->According);
			this->Controls->Add(this->Show_CREDITS);
			this->Controls->Add(this->Apache_LIC);
			this->Controls->Add(this->OpenSource);
			this->Controls->Add(this->COPYR);
			this->Controls->Add(this->VersionSWI);
			this->Controls->Add(this->AboutHead);
			this->Controls->Add(this->SWIICO);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormAbout";
			this->Load += gcnew System::EventHandler(this, &FormAbout::FormAbout_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SWIICO))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormAbout_Load(System::Object^ sender, System::EventArgs^ e) {
		string AASVersion, XYLVersion, HeadOfAAS, AddonVersion;
		string AASVersionLabel = "AAS            ", XYLVersionLabel = "肖亚林的故事           ", AddonVersionLabel = "附加更新 No.   ";
		string XYLVersionLabelEN = "The Story of XYL      ", AddonVersionLabelEN = "Add-on Update No.   ";
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
		int ahsize = HeadOfAAS.size();
		int avsize = AASVersion.size();
		int xvsize = XYLVersion.size();
		for (int i = 0; i < ahsize; i++)
		{
			AASVersionLabel[i + 4] = HeadOfAAS[i];
		}
		for (int i = 0; i < avsize; i++)
		{
			AASVersionLabel[i + 5 + ahsize] = AASVersion[i];
		}
		for (int i = 0; i < xvsize; i++)
		{
			XYLVersionLabel[i + 13] = XYLVersion[i];
			XYLVersionLabelEN[i + 17] = XYLVersion[i];
		}
		AddonVersionLabel[13] = AddonVersion[0];
		AddonVersionLabel[14] = AddonVersion[1];
		AddonVersionLabelEN[18] = AddonVersion[0];
		AddonVersionLabelEN[19] = AddonVersion[1];
		if (GetSystemDefaultLangID() == 2052)
		{
			this->aasverlabel->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)AASVersionLabel.c_str());
			this->xylverlabel->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)XYLVersionLabel.c_str());
			this->addonverlabel->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)AddonVersionLabel.c_str());
		}
		else
		{
			this->aasverlabel->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)AASVersionLabel.c_str());
			this->xylverlabel->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)XYLVersionLabelEN.c_str());
			this->addonverlabel->Text = Marshal::PtrToStringAnsi((IntPtr)(char*)AddonVersionLabelEN.c_str());
		}
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
		{
			if (GetSystemDefaultLangID() == 2052)
			{
				this->Username->Text = "未激活";
			}
			else this->Username->Text = "Not Activated";
		}
	}
	private: System::Void OpenSource_Click(System::Object^ sender, System::EventArgs^ e) {
		ShellExecute(NULL, "open", "https://aasquandeng.github.io/", NULL, NULL, SW_SHOW);
	}
private: System::Void Show_CREDITS_Click(System::Object^ sender, System::EventArgs^ e) {
	Credits().ShowDialog();
}
private: System::Void About_close_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
