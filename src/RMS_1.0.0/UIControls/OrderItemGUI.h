//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Order Item GUI
//---------------------------------------------------------------------

#pragma once

#include <msclr/marshal.h>

#include <Restaurant.h>
#include <OrderController.h>
#include <Order.h>
#include <OrderItem.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace SharedCode;
using namespace msclr::interop;

namespace UIControls {

	/// <summary>
	/// Summary for OrderItemGUI
	/// </summary>
	public ref class OrderItemGUI : public System::Windows::Forms::UserControl
	{
	public:
      Order * myOrder;
      int ID;
		OrderItemGUI(void)
		{
			InitializeComponent();
	
		}
      OrderItemGUI(Order * order)
      {
         InitializeComponent();
         myOrder = order;
      }
      OrderItemGUI(int id)
      {
         InitializeComponent();
         myOrder = Restaurant::GetRestaurant()->getOrderController()->OrderAt(id);
         ID = id;
      }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OrderItemGUI()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::Label^  label1;
   protected:

   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Label^  label4;




   private: System::Windows::Forms::CheckedListBox^  chkItems;
   private: System::Windows::Forms::Button^  btnComplete;
   private: System::Windows::Forms::Button^  btnClear;
   private: System::Windows::Forms::Label^  lblOrder;

   private: System::Windows::Forms::Label^  lblServer;
   private: System::Windows::Forms::Label^  lblTime;



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
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->chkItems = (gcnew System::Windows::Forms::CheckedListBox());
         this->btnComplete = (gcnew System::Windows::Forms::Button());
         this->btnClear = (gcnew System::Windows::Forms::Button());
         this->lblOrder = (gcnew System::Windows::Forms::Label());
         this->lblServer = (gcnew System::Windows::Forms::Label());
         this->lblTime = (gcnew System::Windows::Forms::Label());
         this->SuspendLayout();
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(9, 9);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(70, 24);
         this->label1->TabIndex = 0;
         this->label1->Text = L"Order:";
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label3->Location = System::Drawing::Point(9, 38);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(77, 24);
         this->label3->TabIndex = 2;
         this->label3->Text = L"Server:";
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label4->Location = System::Drawing::Point(9, 65);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(63, 24);
         this->label4->TabIndex = 3;
         this->label4->Text = L"Time:";
         // 
         // chkItems
         // 
         this->chkItems->FormattingEnabled = true;
         this->chkItems->Location = System::Drawing::Point(12, 96);
         this->chkItems->Name = L"chkItems";
         this->chkItems->Size = System::Drawing::Size(207, 229);
         this->chkItems->TabIndex = 8;
         // 
         // btnComplete
         // 
         this->btnComplete->BackColor = System::Drawing::SystemColors::Control;
         this->btnComplete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnComplete->Location = System::Drawing::Point(12, 332);
         this->btnComplete->Name = L"btnComplete";
         this->btnComplete->Size = System::Drawing::Size(207, 42);
         this->btnComplete->TabIndex = 10;
         this->btnComplete->Text = L"Complete";
         this->btnComplete->UseVisualStyleBackColor = true;
         this->btnComplete->Click += gcnew System::EventHandler(this, &OrderItemGUI::btnComplete_Click);
         // 
         // btnClear
         // 
         this->btnClear->BackColor = System::Drawing::SystemColors::Control;
         this->btnClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnClear->Location = System::Drawing::Point(12, 378);
         this->btnClear->Name = L"btnClear";
         this->btnClear->Size = System::Drawing::Size(207, 40);
         this->btnClear->TabIndex = 11;
         this->btnClear->Text = L"Clear";
         this->btnClear->UseVisualStyleBackColor = true;
         this->btnClear->Click += gcnew System::EventHandler(this, &OrderItemGUI::btnClear_Click);
         // 
         // lblOrder
         // 
         this->lblOrder->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->lblOrder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblOrder->Location = System::Drawing::Point(101, 10);
         this->lblOrder->Name = L"lblOrder";
         this->lblOrder->Size = System::Drawing::Size(118, 22);
         this->lblOrder->TabIndex = 12;
         // 
         // lblServer
         // 
         this->lblServer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->lblServer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblServer->Location = System::Drawing::Point(101, 39);
         this->lblServer->Name = L"lblServer";
         this->lblServer->Size = System::Drawing::Size(118, 22);
         this->lblServer->TabIndex = 14;
         // 
         // lblTime
         // 
         this->lblTime->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->lblTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblTime->Location = System::Drawing::Point(101, 66);
         this->lblTime->Name = L"lblTime";
         this->lblTime->Size = System::Drawing::Size(118, 22);
         this->lblTime->TabIndex = 15;
         // 
         // OrderItemGUI
         // 
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
         this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
         this->Controls->Add(this->lblTime);
         this->Controls->Add(this->lblServer);
         this->Controls->Add(this->lblOrder);
         this->Controls->Add(this->btnClear);
         this->Controls->Add(this->btnComplete);
         this->Controls->Add(this->chkItems);
         this->Controls->Add(this->label4);
         this->Controls->Add(this->label3);
         this->Controls->Add(this->label1);
         this->Name = L"OrderItemGUI";
         this->Padding = System::Windows::Forms::Padding(10);
         this->Size = System::Drawing::Size(228, 427);
         this->Load += gcnew System::EventHandler(this, &OrderItemGUI::OrderItemGUI_Load);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) 
   {      
      delete this;
   }
private: System::Void btnComplete_Click(System::Object^  sender, System::EventArgs^  e) {
   btnComplete->Enabled = false;
   btnComplete->BackColor = btnComplete->BackColor.LightGreen;
   myOrder->SetOrderState(true);
}
private: System::Void OrderItemGUI_Load(System::Object^  sender, System::EventArgs^  e) 
{
   lblOrder->Text = myOrder->GetID().ToString();
   lblServer->Text = "Brady";
   const vector<OrderItem *> * items = myOrder->Items();
   marshal_context ^ context = gcnew marshal_context();
   if (items != NULL)
   {
      for (int i = 0; i < items->size(); i++)
      {
         string str = *items->at(i)->GetRecipe()->Name();
         chkItems->Items->Add(gcnew String(str.c_str()));
      }
   }
   //lblTime->Text = gcnew String(myOrder->TimePlaced());
}
};
}
