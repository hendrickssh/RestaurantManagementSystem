//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Table GUI
//---------------------------------------------------------------------

#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UIControls {

	/// <summary>
	/// Summary for TableGUI
	/// </summary>
	public ref class TableGUI : public System::Windows::Forms::UserControl
	{
	public:
		TableGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
      

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TableGUI()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::Button^  btnClearTable;
   protected:
   private: System::Windows::Forms::Button^  btnBill;
   private: System::Windows::Forms::Button^  btnSubmit;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Label^  lblTableNum;

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
         this->btnClearTable = (gcnew System::Windows::Forms::Button());
         this->btnBill = (gcnew System::Windows::Forms::Button());
         this->btnSubmit = (gcnew System::Windows::Forms::Button());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->lblTableNum = (gcnew System::Windows::Forms::Label());
         this->SuspendLayout();
         // 
         // btnClearTable
         // 
         this->btnClearTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnClearTable->Location = System::Drawing::Point(15, 38);
         this->btnClearTable->Name = L"btnClearTable";
         this->btnClearTable->Size = System::Drawing::Size(182, 30);
         this->btnClearTable->TabIndex = 0;
         this->btnClearTable->Text = L"Clear";
         this->btnClearTable->UseVisualStyleBackColor = true;
         // 
         // btnBill
         // 
         this->btnBill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnBill->Location = System::Drawing::Point(15, 73);
         this->btnBill->Name = L"btnBill";
         this->btnBill->Size = System::Drawing::Size(182, 30);
         this->btnBill->TabIndex = 1;
         this->btnBill->Text = L"Bill";
         this->btnBill->UseVisualStyleBackColor = true;
         // 
         // btnSubmit
         // 
         this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnSubmit->Location = System::Drawing::Point(15, 108);
         this->btnSubmit->Name = L"btnSubmit";
         this->btnSubmit->Size = System::Drawing::Size(182, 30);
         this->btnSubmit->TabIndex = 2;
         this->btnSubmit->Text = L"SubmitOrder";
         this->btnSubmit->UseVisualStyleBackColor = true;
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(11, 8);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(69, 24);
         this->label1->TabIndex = 3;
         this->label1->Text = L"Table:";
         // 
         // lblTableNum
         // 
         this->lblTableNum->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->lblTableNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblTableNum->Location = System::Drawing::Point(97, 10);
         this->lblTableNum->Name = L"lblTableNum";
         this->lblTableNum->Size = System::Drawing::Size(100, 22);
         this->lblTableNum->TabIndex = 4;
         // 
         // TableGUI
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->Controls->Add(this->lblTableNum);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->btnSubmit);
         this->Controls->Add(this->btnBill);
         this->Controls->Add(this->btnClearTable);
         this->Name = L"TableGUI";
         this->Size = System::Drawing::Size(207, 148);
         this->Load += gcnew System::EventHandler(this, &TableGUI::TableGUI_Load);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void TableGUI_Load(System::Object^  sender, System::EventArgs^  e) {
   }
};
}
