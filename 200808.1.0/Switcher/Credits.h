#pragma once

namespace Switcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Credits 摘要
	/// </summary>
	public ref class Credits : public System::Windows::Forms::Form
	{
	public:
		Credits(void)
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
		~Credits()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ Credits_IMG;
	protected:
	private: System::Windows::Forms::Label^ Credits_TIT;
	private: System::Windows::Forms::Label^ Credits_ART;
	private: System::Windows::Forms::Button^ Credits_close;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Credits::typeid));
			this->Credits_IMG = (gcnew System::Windows::Forms::PictureBox());
			this->Credits_TIT = (gcnew System::Windows::Forms::Label());
			this->Credits_ART = (gcnew System::Windows::Forms::Label());
			this->Credits_close = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Credits_IMG))->BeginInit();
			this->SuspendLayout();
			// 
			// Credits_IMG
			// 
			resources->ApplyResources(this->Credits_IMG, L"Credits_IMG");
			this->Credits_IMG->Name = L"Credits_IMG";
			this->Credits_IMG->TabStop = false;
			// 
			// Credits_TIT
			// 
			resources->ApplyResources(this->Credits_TIT, L"Credits_TIT");
			this->Credits_TIT->Name = L"Credits_TIT";
			// 
			// Credits_ART
			// 
			resources->ApplyResources(this->Credits_ART, L"Credits_ART");
			this->Credits_ART->Name = L"Credits_ART";
			// 
			// Credits_close
			// 
			resources->ApplyResources(this->Credits_close, L"Credits_close");
			this->Credits_close->Name = L"Credits_close";
			this->Credits_close->UseVisualStyleBackColor = true;
			this->Credits_close->Click += gcnew System::EventHandler(this, &Credits::Credits_close_Click);
			// 
			// Credits
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->Credits_close);
			this->Controls->Add(this->Credits_ART);
			this->Controls->Add(this->Credits_TIT);
			this->Controls->Add(this->Credits_IMG);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Credits";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Credits_IMG))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Credits_close_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
