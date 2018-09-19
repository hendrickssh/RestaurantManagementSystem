//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: GUI for chefs to see active orders
//---------------------------------------------------------------------

#pragma once

#include <Restaurant.h>

namespace RestaurantManagementSystem
{
   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;
   using namespace UIControls;
   using namespace SharedCode;

   /// <summary>
   /// Summary for Chef
   /// </summary>
   public ref class Chef : public System::Windows::Forms::Form
   {
   public:
      int workingOrders = 0;
      Chef(void)
      {
         Chef(nullptr);
      }
      Chef(Form ^ form)
      {
         
         InitializeComponent();
         this->form = form;
      }

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~Chef()
      {
         if (components)
         {
            delete components;
         }
      }

      /// <summary>
      ///   Holds a reference to the form which opened this form. This is to be
      ///   shown when this form is about to close. 
      /// </summary>
   private: System::Windows::Forms::Form ^ form;




   protected:

   private: System::Windows::Forms::FlowLayoutPanel^  orderList;
   private: System::Windows::Forms::StatusStrip^  statusStrip1;
   private: System::Windows::Forms::ToolStripStatusLabel^  lblWorkingOrders;

   private: System::Windows::Forms::GroupBox^  grpOrders;

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
         this->orderList = (gcnew System::Windows::Forms::FlowLayoutPanel());
         this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
         this->lblWorkingOrders = (gcnew System::Windows::Forms::ToolStripStatusLabel());
         this->grpOrders = (gcnew System::Windows::Forms::GroupBox());
         this->statusStrip1->SuspendLayout();
         this->grpOrders->SuspendLayout();
         this->SuspendLayout();
         // 
         // orderList
         // 
         this->orderList->Cursor = System::Windows::Forms::Cursors::Default;
         this->orderList->Location = System::Drawing::Point(6, 25);
         this->orderList->Name = L"orderList";
         this->orderList->Size = System::Drawing::Size(947, 475);
         this->orderList->TabIndex = 23;
         this->orderList->WrapContents = false;
         this->orderList->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Chef::mainLayout_Paint);
         // 
         // statusStrip1
         // 
         this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->lblWorkingOrders });
         this->statusStrip1->Location = System::Drawing::Point(0, 659);
         this->statusStrip1->Name = L"statusStrip1";
         this->statusStrip1->Size = System::Drawing::Size(1264, 22);
         this->statusStrip1->TabIndex = 24;
         this->statusStrip1->Text = L"statusStrip1";
         // 
         // lblWorkingOrders
         // 
         this->lblWorkingOrders->Name = L"lblWorkingOrders";
         this->lblWorkingOrders->Size = System::Drawing::Size(93, 17);
         this->lblWorkingOrders->Text = L"Working Orders:";
         // 
         // grpOrders
         // 
         this->grpOrders->Controls->Add(this->orderList);
         this->grpOrders->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->grpOrders->Location = System::Drawing::Point(12, 7);
         this->grpOrders->Name = L"grpOrders";
         this->grpOrders->Size = System::Drawing::Size(1240, 639);
         this->grpOrders->TabIndex = 26;
         this->grpOrders->TabStop = false;
         this->grpOrders->Text = L"Orders";
         // 
         // Chef
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->BackColor = System::Drawing::SystemColors::Control;
         this->ClientSize = System::Drawing::Size(1264, 681);
         this->Controls->Add(this->grpOrders);
         this->Controls->Add(this->statusStrip1);
         this->Cursor = System::Windows::Forms::Cursors::IBeam;
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->MaximumSize = System::Drawing::Size(1280, 720);
         this->MinimumSize = System::Drawing::Size(1280, 720);
         this->Name = L"Chef";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Chef";
         this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Chef::Chef_FormClosed);
         this->Load += gcnew System::EventHandler(this, &Chef::Chef_Load);
         this->statusStrip1->ResumeLayout(false);
         this->statusStrip1->PerformLayout();
         this->grpOrders->ResumeLayout(false);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

   private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
   {
   }

   private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
   {
   }

   private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
   {
   }

   private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
   {
   }

   private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)
   {
      this->MaximizeBox = false;
   }

   private: System::Void mainLayout_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
   {
   }            
   private: System::Void Chef_Load(System::Object^  sender, System::EventArgs^  e)
   {    
      Restaurant * restaurant = Restaurant::GetRestaurant();

      if (restaurant == NULL)
         return;    
      OrderController::OrderContainer orders = restaurant->getOrderController()->getOrders();

      for (int order = 0; order < orders.size(); order++)
      {
         if (!orders.at(order)->GetOrderState())
         {
            orderList->Controls->Add(gcnew OrderItemGUI(order));
            workingOrders++;
         }
      }     
      lblWorkingOrders->Text = "Working Orders: " + workingOrders;
   }
   private: System::Void btnComplete_Click(System::Object^  sender, System::EventArgs^  e)
   {      
      workingOrders--;
      lblWorkingOrders->Text = "Working Orders: " + workingOrders;
   }
   private: System::Void numOrdersLL_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
   {

   }
   private: System::Void Chef_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
   {
      if (form != nullptr)
         form->Show();
   }
   };
}
