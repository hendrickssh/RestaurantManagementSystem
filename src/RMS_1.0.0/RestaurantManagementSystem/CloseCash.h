//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Popup GUI for wait staff to enter a cash amount in ServerClose
//---------------------------------------------------------------------

#pragma once
#include <iomanip>
#include <sstream>

namespace RestaurantManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CloseCash
	/// </summary>
	public ref class CloseCash : public System::Windows::Forms::Form
	{
	public:
		CloseCash(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

   private: String ^ payment;
   private: String ^ total;
   private: Form ^ form;
   public:
      CloseCash(Form ^ form, String ^ total)
      {
         InitializeComponent();
         this->form = form;
         this->total = total;
      }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CloseCash()
		{
			if (components)
			{
				delete components;
			}
		}

   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::TextBox^  textInput;
   protected:
   private: System::Windows::Forms::Button^  buttonEnter;
   private: System::Windows::Forms::Button^  buttonClear;
   private: System::Windows::Forms::Button^  buttonNum0;
   private: System::Windows::Forms::Button^  buttonNum9;
   private: System::Windows::Forms::Button^  buttonNum8;
   private: System::Windows::Forms::Button^  buttonNum7;
   private: System::Windows::Forms::Button^  buttonNum6;
   private: System::Windows::Forms::Button^  buttonNum5;
   private: System::Windows::Forms::Button^  buttonNum4;
   private: System::Windows::Forms::Button^  buttonNum3;
   private: System::Windows::Forms::Button^  buttonNum2;
   private: System::Windows::Forms::Button^  buttonNum1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         this->textInput = (gcnew System::Windows::Forms::TextBox());
         this->buttonEnter = (gcnew System::Windows::Forms::Button());
         this->buttonClear = (gcnew System::Windows::Forms::Button());
         this->buttonNum0 = (gcnew System::Windows::Forms::Button());
         this->buttonNum9 = (gcnew System::Windows::Forms::Button());
         this->buttonNum8 = (gcnew System::Windows::Forms::Button());
         this->buttonNum7 = (gcnew System::Windows::Forms::Button());
         this->buttonNum6 = (gcnew System::Windows::Forms::Button());
         this->buttonNum5 = (gcnew System::Windows::Forms::Button());
         this->buttonNum4 = (gcnew System::Windows::Forms::Button());
         this->buttonNum3 = (gcnew System::Windows::Forms::Button());
         this->buttonNum2 = (gcnew System::Windows::Forms::Button());
         this->buttonNum1 = (gcnew System::Windows::Forms::Button());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->SuspendLayout();
         // 
         // textInput
         // 
         this->textInput->BackColor = System::Drawing::SystemColors::Control;
         this->textInput->BorderStyle = System::Windows::Forms::BorderStyle::None;
         this->textInput->Enabled = false;
         this->textInput->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->textInput->Location = System::Drawing::Point(54, 80);
         this->textInput->MaxLength = 4;
         this->textInput->Name = L"textInput";
         this->textInput->ReadOnly = true;
         this->textInput->Size = System::Drawing::Size(237, 26);
         this->textInput->TabIndex = 39;
         this->textInput->TabStop = false;
         this->textInput->Text = L"$0.00";
         this->textInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
         this->textInput->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonEnter
         // 
         this->buttonEnter->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonEnter->ForeColor = System::Drawing::Color::SeaGreen;
         this->buttonEnter->Location = System::Drawing::Point(216, 366);
         this->buttonEnter->Name = L"buttonEnter";
         this->buttonEnter->Size = System::Drawing::Size(75, 75);
         this->buttonEnter->TabIndex = 38;
         this->buttonEnter->Text = L"Enter";
         this->buttonEnter->UseVisualStyleBackColor = true;
         this->buttonEnter->Click += gcnew System::EventHandler(this, &CloseCash::buttonEnter_Click);
         // 
         // buttonClear
         // 
         this->buttonClear->Font = (gcnew System::Drawing::Font(L"Cambria", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonClear->ForeColor = System::Drawing::Color::Red;
         this->buttonClear->Location = System::Drawing::Point(54, 366);
         this->buttonClear->Name = L"buttonClear";
         this->buttonClear->Size = System::Drawing::Size(75, 75);
         this->buttonClear->TabIndex = 37;
         this->buttonClear->Text = L"Clear";
         this->buttonClear->UseVisualStyleBackColor = true;
         this->buttonClear->Click += gcnew System::EventHandler(this, &CloseCash::buttonClear_Click);
         // 
         // buttonNum0
         // 
         this->buttonNum0->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum0->Location = System::Drawing::Point(135, 366);
         this->buttonNum0->Name = L"buttonNum0";
         this->buttonNum0->Size = System::Drawing::Size(75, 75);
         this->buttonNum0->TabIndex = 36;
         this->buttonNum0->Text = L"0";
         this->buttonNum0->UseVisualStyleBackColor = true;
         this->buttonNum0->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum9
         // 
         this->buttonNum9->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum9->Location = System::Drawing::Point(216, 285);
         this->buttonNum9->Name = L"buttonNum9";
         this->buttonNum9->Size = System::Drawing::Size(75, 75);
         this->buttonNum9->TabIndex = 35;
         this->buttonNum9->Text = L"9";
         this->buttonNum9->UseVisualStyleBackColor = true;
         this->buttonNum9->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum8
         // 
         this->buttonNum8->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum8->Location = System::Drawing::Point(135, 285);
         this->buttonNum8->Name = L"buttonNum8";
         this->buttonNum8->Size = System::Drawing::Size(75, 75);
         this->buttonNum8->TabIndex = 34;
         this->buttonNum8->Text = L"8";
         this->buttonNum8->UseVisualStyleBackColor = true;
         this->buttonNum8->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum7
         // 
         this->buttonNum7->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum7->Location = System::Drawing::Point(54, 285);
         this->buttonNum7->Name = L"buttonNum7";
         this->buttonNum7->Size = System::Drawing::Size(75, 75);
         this->buttonNum7->TabIndex = 33;
         this->buttonNum7->Text = L"7";
         this->buttonNum7->UseVisualStyleBackColor = true;
         this->buttonNum7->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum6
         // 
         this->buttonNum6->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum6->Location = System::Drawing::Point(216, 204);
         this->buttonNum6->Name = L"buttonNum6";
         this->buttonNum6->Size = System::Drawing::Size(75, 75);
         this->buttonNum6->TabIndex = 32;
         this->buttonNum6->Text = L"6";
         this->buttonNum6->UseVisualStyleBackColor = true;
         this->buttonNum6->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum5
         // 
         this->buttonNum5->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum5->Location = System::Drawing::Point(135, 204);
         this->buttonNum5->Name = L"buttonNum5";
         this->buttonNum5->Size = System::Drawing::Size(75, 75);
         this->buttonNum5->TabIndex = 31;
         this->buttonNum5->Text = L"5";
         this->buttonNum5->UseVisualStyleBackColor = true;
         this->buttonNum5->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum4
         // 
         this->buttonNum4->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum4->Location = System::Drawing::Point(54, 204);
         this->buttonNum4->Name = L"buttonNum4";
         this->buttonNum4->Size = System::Drawing::Size(75, 75);
         this->buttonNum4->TabIndex = 30;
         this->buttonNum4->Text = L"4";
         this->buttonNum4->UseVisualStyleBackColor = true;
         this->buttonNum4->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum3
         // 
         this->buttonNum3->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum3->Location = System::Drawing::Point(216, 123);
         this->buttonNum3->Name = L"buttonNum3";
         this->buttonNum3->Size = System::Drawing::Size(75, 75);
         this->buttonNum3->TabIndex = 29;
         this->buttonNum3->Text = L"3";
         this->buttonNum3->UseVisualStyleBackColor = true;
         this->buttonNum3->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum2
         // 
         this->buttonNum2->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum2->Location = System::Drawing::Point(135, 123);
         this->buttonNum2->Name = L"buttonNum2";
         this->buttonNum2->Size = System::Drawing::Size(75, 75);
         this->buttonNum2->TabIndex = 28;
         this->buttonNum2->Text = L"2";
         this->buttonNum2->UseVisualStyleBackColor = true;
         this->buttonNum2->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // buttonNum1
         // 
         this->buttonNum1->Font = (gcnew System::Drawing::Font(L"Cambria", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->buttonNum1->Location = System::Drawing::Point(54, 123);
         this->buttonNum1->Name = L"buttonNum1";
         this->buttonNum1->Size = System::Drawing::Size(75, 75);
         this->buttonNum1->TabIndex = 27;
         this->buttonNum1->Text = L"1";
         this->buttonNum1->UseVisualStyleBackColor = true;
         this->buttonNum1->Click += gcnew System::EventHandler(this, &CloseCash::numberButtonClick);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(94, 42);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(163, 23);
         this->label1->TabIndex = 40;
         this->label1->Text = L"Enter Cash Amount:";
         // 
         // CloseCash
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(344, 521);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->textInput);
         this->Controls->Add(this->buttonEnter);
         this->Controls->Add(this->buttonClear);
         this->Controls->Add(this->buttonNum0);
         this->Controls->Add(this->buttonNum9);
         this->Controls->Add(this->buttonNum8);
         this->Controls->Add(this->buttonNum7);
         this->Controls->Add(this->buttonNum6);
         this->Controls->Add(this->buttonNum5);
         this->Controls->Add(this->buttonNum4);
         this->Controls->Add(this->buttonNum3);
         this->Controls->Add(this->buttonNum2);
         this->Controls->Add(this->buttonNum1);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->MinimizeBox = false;
         this->Name = L"CloseCash";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Close Cash";
         this->TopMost = true;
         this->Load += gcnew System::EventHandler(this, &CloseCash::CloseCash_Load);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
      private: System::Void numberButtonClick(System::Object^ sender, System::EventArgs^ e) {
         System::Windows::Forms::Button^ buttonPressed = (System::Windows::Forms::Button^)sender;
         AddDigit(buttonPressed->Text);
      }
   private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
      textInput->Text = "$0.00";
      this->payment = "";
   }
   private: System::Void buttonEnter_Click(System::Object^  sender, System::EventArgs^  e) {
      this->form->Enabled = true;
      this->Close();
   }
   private: System::Void CloseCash_Load(System::Object^  sender, System::EventArgs^  e)
   {    
      textInput->Text = total;
      this->payment = "";
   }
   private: void AddDigit(String^ num) {
      this->payment +=  num;
      String ^ formPay = this->payment;
      if (formPay->Length > 2) {
         int length = formPay->Length;
         formPay = formPay->Insert(length - 2, ".");
      }
      else if (formPay->Length == 1) {
         formPay = System::String::Concat("0.0", formPay);
      }
      else if (formPay->Length == 2) {
         formPay = System::String::Concat("0.", formPay);
      }
      else {
         formPay = "0.00";
      }
 
     formPay = String::Format("{0:C2}", System::Convert::ToDouble(formPay));
     textInput->Text = formPay;
   }

   public: System::String ^ getPayment() {
      return textInput->Text;
   }
};
}
