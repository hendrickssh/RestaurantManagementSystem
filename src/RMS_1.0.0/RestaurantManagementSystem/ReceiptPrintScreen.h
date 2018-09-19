#pragma once
#include <msclr\marshal_cppstd.h> //String Converter
#include <ostream>
#include <fstream>

#include "Order.h"
#include "ReceiptController.h"
#include "Receipt.h"
using namespace std;

namespace RestaurantManagementSystem 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ReceiptPrintScreen
	/// </summary>
	public ref class ReceiptPrintScreen : public System::Windows::Forms::Form
	{
	public:
		ReceiptPrintScreen(void)
		{
			InitializeComponent();
		}

      ReceiptPrintScreen( Order * or )
      {
         InitializeComponent();
         cusRecipet = new Receipt(or ->GetNumber(), or ->GetServer(), or ->GetTable(), or ->GetTime(), or ->GetTotal(), or-GetOrderLst());
         rc = new ReceiptController(cusRecipet);
      }
      


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ReceiptPrintScreen()
		{
			if (components)
			{
				delete components;
            //delete rc;
            //delete cusOrder;
            //delete customerRecipet;
			}
		}

   protected:
   private: System::Windows::Forms::Label^  screenLabl;
   private: System::Windows::Forms::Button^  printBttn;
   private: System::Windows::Forms::Button^  cancelBttn;


   private: System::Windows::Forms::GroupBox^  controlGBox;
   private: System::Windows::Forms::RichTextBox^  receiptTextBox;


   protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
      ReceiptController * rc;
      Receipt * customerRecipet;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         this->screenLabl = (gcnew System::Windows::Forms::Label());
         this->printBttn = (gcnew System::Windows::Forms::Button());
         this->cancelBttn = (gcnew System::Windows::Forms::Button());
         this->controlGBox = (gcnew System::Windows::Forms::GroupBox());
         this->receiptTextBox = (gcnew System::Windows::Forms::RichTextBox());
         this->SuspendLayout();
         // 
         // screenLabl
         // 
         this->screenLabl->AutoSize = true;
         this->screenLabl->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->screenLabl->Location = System::Drawing::Point(55, 10);
         this->screenLabl->Name = L"screenLabl";
         this->screenLabl->Size = System::Drawing::Size(232, 23);
         this->screenLabl->TabIndex = 1;
         this->screenLabl->Text = L"Receipt Print Screen";
         this->screenLabl->TextAlign = System::Drawing::ContentAlignment::TopCenter;
         // 
         // printBttn
         // 
         this->printBttn->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->printBttn->Location = System::Drawing::Point(18, 450);
         this->printBttn->Name = L"printBttn";
         this->printBttn->Size = System::Drawing::Size(308, 62);
         this->printBttn->TabIndex = 2;
         this->printBttn->Text = L"Print Receipt";
         this->printBttn->UseVisualStyleBackColor = true;
         this->printBttn->Click += gcnew System::EventHandler(this, &ReceiptPrintScreen::button1_Click);
         // 
         // cancelBttn
         // 
         this->cancelBttn->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->cancelBttn->Location = System::Drawing::Point(18, 518);
         this->cancelBttn->Name = L"cancelBttn";
         this->cancelBttn->Size = System::Drawing::Size(308, 61);
         this->cancelBttn->TabIndex = 3;
         this->cancelBttn->Text = L"Cancel Print";
         this->cancelBttn->UseVisualStyleBackColor = true;
         this->cancelBttn->Click += gcnew System::EventHandler(this, &ReceiptPrintScreen::button2_Click);
         // 
         // controlGBox
         // 
         this->controlGBox->Location = System::Drawing::Point(12, 437);
         this->controlGBox->Name = L"controlGBox";
         this->controlGBox->Size = System::Drawing::Size(320, 152);
         this->controlGBox->TabIndex = 4;
         this->controlGBox->TabStop = false;
         // 
         // recipteTextBox
         // 
         this->receiptTextBox->BackColor = System::Drawing::SystemColors::Control;
         this->receiptTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->receiptTextBox->DetectUrls = false;
         this->receiptTextBox->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->receiptTextBox->Location = System::Drawing::Point(12, 36);
         this->receiptTextBox->Name = L"recipteTextBox";
         this->receiptTextBox->ReadOnly = true;
         this->receiptTextBox->Size = System::Drawing::Size(320, 388);
         this->receiptTextBox->TabIndex = 5;
         this->receiptTextBox->Text = L"Bacon Cheese Burger Bsk w/ Mello Yello\n\tWell done\n\tExtra crispy\n\tHold the Mayo";
         // 
         // ReceiptPrintScreen
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->BackColor = System::Drawing::SystemColors::ActiveBorder;
         this->ClientSize = System::Drawing::Size(344, 601);
         this->Controls->Add(this->receiptTextBox);
         this->Controls->Add(this->cancelBttn);
         this->Controls->Add(this->printBttn);
         this->Controls->Add(this->screenLabl);
         this->Controls->Add(this->controlGBox);
         this->Name = L"ReceiptPrintScreen";
         this->Text = L"ReceiptPrintScreen";
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

      /// <summary>
      /// "Print" a recipte.
      /// <summary>
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
   ofstream file;
   System::String ^ strt = receiptTextBox->Text->ToString();
   std::string str = msclr::interop::marshal_as<std::string>(strt);
   file.open("Recipte"); //Need identifcation method
   file << str;
   file.close();
   this->Close();
}

         /// <summary>
         /// Closes the print screen when the cancle button is pressed.
         /// <summary>
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
   this->Close();
}

};
}
