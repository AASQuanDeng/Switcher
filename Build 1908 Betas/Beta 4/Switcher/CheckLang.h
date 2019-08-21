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

namespace Switcher {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// CheckLang 摘要
	/// </summary>
	public ref class CheckLang : public System::Windows::Forms::Form
	{
	public:
		CheckLang(void)
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
		~CheckLang()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ DontShow;
	protected:
	private: System::Windows::Forms::Label^ SorryText;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ CheckLangOK;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CheckLang::typeid));
			this->DontShow = (gcnew System::Windows::Forms::CheckBox());
			this->SorryText = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->CheckLangOK = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// DontShow
			// 
			this->DontShow->AutoSize = true;
			this->DontShow->Checked = true;
			this->DontShow->CheckState = System::Windows::Forms::CheckState::Checked;
			this->DontShow->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DontShow->Location = System::Drawing::Point(12, 200);
			this->DontShow->Name = L"DontShow";
			this->DontShow->Size = System::Drawing::Size(125, 19);
			this->DontShow->TabIndex = 0;
			this->DontShow->Text = L"Do not show again";
			this->DontShow->UseVisualStyleBackColor = true;
			// 
			// SorryText
			// 
			this->SorryText->AutoSize = true;
			this->SorryText->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SorryText->Location = System::Drawing::Point(68, 109);
			this->SorryText->Name = L"SorryText";
			this->SorryText->Size = System::Drawing::Size(466, 38);
			this->SorryText->TabIndex = 1;
			this->SorryText->Text = L"We are sorry but Switchet does not provide your language.\r\nYou can use the Englis"
				L"h version. We are trying to support more languages.";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 102);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(27, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(488, 40);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Language Does\'t Support Warning";
			// 
			// CheckLangOK
			// 
			this->CheckLangOK->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckLangOK->Location = System::Drawing::Point(457, 226);
			this->CheckLangOK->Name = L"CheckLangOK";
			this->CheckLangOK->Size = System::Drawing::Size(75, 23);
			this->CheckLangOK->TabIndex = 4;
			this->CheckLangOK->Text = L"OK";
			this->CheckLangOK->UseVisualStyleBackColor = true;
			this->CheckLangOK->Click += gcnew System::EventHandler(this, &CheckLang::CheckLangOK_Click);
			// 
			// CheckLang
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(544, 261);
			this->Controls->Add(this->CheckLangOK);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->SorryText);
			this->Controls->Add(this->DontShow);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CheckLang";
			this->Text = L"Warning";
			this->Load += gcnew System::EventHandler(this, &CheckLang::CheckLang_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CheckLang_Load(System::Object^ sender, System::EventArgs^ e) {
		LCID langid = GetSystemDefaultLangID();
		if (langid == 2052 || langid == 1033)
		{
			this->Close();
		}
		else
		{
			if (_access(".\\config\\nolangcheck", 0) != -1)
			{
				this->Close();
			}
		}
	}
private: System::Void CheckLangOK_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->DontShow->Checked)
	{
		ofstream out;
		out.open(".\\config\\nolangcheck");
		out.close();
	}
	this->Close();
}
};
}
