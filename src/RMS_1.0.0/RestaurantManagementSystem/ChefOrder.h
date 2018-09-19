#pragma once
#include "OrderController.h"
#include "Order.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace RestaurantManagementSystem 
{

	/// <summary>
	/// Summary for ChefOrder
	/// </summary>
	public ref class ChefOrder : public System::Windows::Forms::UserControl
	{

   private:
      OrderController * conOrder;

	public:
		ChefOrder(Order * or)
		{
			InitializeComponent();
         /*         Fix label modifcation
         String ^ temp = gcnew String("Order Number: ");
         ordNumLabl->Text = String::Concat(temp, or ->GetNumber);
         */

         conOrder = new OrderController(or);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChefOrder()
		{
			if (components)
			{
				delete components;
            delete conOrder;
			}
		}
   private: System::Windows::Forms::CheckedListBox^  orderListBox;
   protected:
   private: System::Windows::Forms::Button^  cmpletBttn;
   private: System::Windows::Forms::Button^  clrBttn;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
   private: System::Windows::Forms::Label^  ordNumLabl;
   private: System::Windows::Forms::Label^  tablNumLabl;
   private: System::Windows::Forms::Label^  serverNamLabl;
   private: System::Windows::Forms::Label^  timeLabl;
            

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         this->orderListBox = (gcnew System::Windows::Forms::CheckedListBox());
         this->cmpletBttn = (gcnew System::Windows::Forms::Button());
         this->clrBttn = (gcnew System::Windows::Forms::Button());
         this->ordNumLabl = (gcnew System::Windows::Forms::Label());
         this->tablNumLabl = (gcnew System::Windows::Forms::Label());
         this->serverNamLabl = (gcnew System::Windows::Forms::Label());
         this->timeLabl = (gcnew System::Windows::Forms::Label());
         this->SuspendLayout();
         // 
         // orderListBox
         // 
         this->orderListBox->FormattingEnabled = true;
         this->orderListBox->Location = System::Drawing::Point(25, 106);
         this->orderListBox->Name = L"orderListBox";
         this->orderListBox->Size = System::Drawing::Size(260, 289);
         this->orderListBox->TabIndex = 0;
         this->orderListBox->DoubleClick += gcnew System::EventHandler(this, &ChefOrder::orderListBox_DoubleClick);
         // 
         // cmpletBttn
         // 
         this->cmpletBttn->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->cmpletBttn->Location = System::Drawing::Point(25, 419);
         this->cmpletBttn->Name = L"cmpletBttn";
         this->cmpletBttn->Size = System::Drawing::Size(260, 77);
         this->cmpletBttn->TabIndex = 1;
         this->cmpletBttn->Text = L"Complete";
         this->cmpletBttn->UseVisualStyleBackColor = true;
         this->cmpletBttn->Click += gcnew System::EventHandler(this, &ChefOrder::cmpletBttn_Click);
         // 
         // clrBttn
         // 
         this->clrBttn->Location = System::Drawing::Point(25, 523);
         this->clrBttn->Name = L"clrBttn";
         this->clrBttn->Size = System::Drawing::Size(260, 77);
         this->clrBttn->TabIndex = 2;
         this->clrBttn->Text = L"Clear";
         this->clrBttn->UseVisualStyleBackColor = true;
         this->clrBttn->Click += gcnew System::EventHandler(this, &ChefOrder::clrBttn_Click);
         // 
         // ordNumLabl
         // 
         this->ordNumLabl->AutoSize = true;
         this->ordNumLabl->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->ordNumLabl->Location = System::Drawing::Point(22, 13);
         this->ordNumLabl->Name = L"ordNumLabl";
         this->ordNumLabl->Size = System::Drawing::Size(100, 18);
         this->ordNumLabl->TabIndex = 3;
         this->ordNumLabl->Text = L"OrderNum";
         // 
         // tablNumLabl
         // 
         this->tablNumLabl->AutoSize = true;
         this->tablNumLabl->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->tablNumLabl->Location = System::Drawing::Point(22, 31);
         this->tablNumLabl->Name = L"tablNumLabl";
         this->tablNumLabl->Size = System::Drawing::Size(60, 18);
         this->tablNumLabl->TabIndex = 4;
         this->tablNumLabl->Text = L"label2";
         // 
         // serverNamLabl
         // 
         this->serverNamLabl->AutoSize = true;
         this->serverNamLabl->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->serverNamLabl->Location = System::Drawing::Point(22, 49);
         this->serverNamLabl->Name = L"serverNamLabl";
         this->serverNamLabl->Size = System::Drawing::Size(60, 18);
         this->serverNamLabl->TabIndex = 5;
         this->serverNamLabl->Text = L"label3";
         // 
         // timeLabl
         // 
         this->timeLabl->AutoSize = true;
         this->timeLabl->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->timeLabl->Location = System::Drawing::Point(22, 67);
         this->timeLabl->Name = L"timeLabl";
         this->timeLabl->Size = System::Drawing::Size(60, 18);
         this->timeLabl->TabIndex = 6;
         this->timeLabl->Text = L"label4";
         // 
         // ChefOrder
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->Controls->Add(this->timeLabl);
         this->Controls->Add(this->serverNamLabl);
         this->Controls->Add(this->tablNumLabl);
         this->Controls->Add(this->ordNumLabl);
         this->Controls->Add(this->clrBttn);
         this->Controls->Add(this->cmpletBttn);
         this->Controls->Add(this->orderListBox);
         this->Name = L"ChefOrder";
         this->Size = System::Drawing::Size(321, 621);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

   private: System::Void cmpletBttn_Click(System::Object^  sender, System::EventArgs^  e) 
   {
      conOrder->CompleteOrder();
      delete this;
   }


   private: System::Void clrBttn_Click(System::Object^  sender, System::EventArgs^  e) 
   {
      conOrder->ClearOrder();
      delete this;
   }

   private: System::Void orderListBox_DoubleClick(System::Object^  sender, System::EventArgs^  e) 
   {
      delete this;
   }

   };
}
