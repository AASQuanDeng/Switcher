#pragma once

namespace Switcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Credits ժҪ
	/// </summary>
	public ref class Credits : public System::Windows::Forms::Form
	{
	public:
		Credits(void)
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Credits::typeid));
			this->Credits_IMG = (gcnew System::Windows::Forms::PictureBox());
			this->Credits_TIT = (gcnew System::Windows::Forms::Label());
			this->Credits_ART = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Credits_IMG))->BeginInit();
			this->SuspendLayout();
			// 
			// Credits_IMG
			// 
			this->Credits_IMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Credits_IMG.Image")));
			this->Credits_IMG->Location = System::Drawing::Point(12, 12);
			this->Credits_IMG->Name = L"Credits_IMG";
			this->Credits_IMG->Size = System::Drawing::Size(100, 100);
			this->Credits_IMG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Credits_IMG->TabIndex = 0;
			this->Credits_IMG->TabStop = false;
			// 
			// Credits_TIT
			// 
			this->Credits_TIT->AutoSize = true;
			this->Credits_TIT->Font = (gcnew System::Drawing::Font(L"΢���ź�", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Credits_TIT->Location = System::Drawing::Point(181, 42);
			this->Credits_TIT->Name = L"Credits_TIT";
			this->Credits_TIT->Size = System::Drawing::Size(120, 39);
			this->Credits_TIT->TabIndex = 1;
			this->Credits_TIT->Text = L"Credits";
			// 
			// Credits_ART
			// 
			this->Credits_ART->AutoSize = true;
			this->Credits_ART->Font = (gcnew System::Drawing::Font(L"΢���ź�", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->Credits_ART->Location = System::Drawing::Point(12, 115);
			this->Credits_ART->Name = L"Credits_ART";
			this->Credits_ART->Size = System::Drawing::Size(463, 187);
			this->Credits_ART->TabIndex = 2;
			this->Credits_ART->Text = resources->GetString(L"Credits_ART.Text");
			// 
			// Credits
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(483, 306);
			this->Controls->Add(this->Credits_ART);
			this->Controls->Add(this->Credits_TIT);
			this->Controls->Add(this->Credits_IMG);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Credits";
			this->Text = L"Credits";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Credits_IMG))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
