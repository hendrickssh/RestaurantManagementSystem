//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: GUI showing all tables, giving the wait staff the ability
//    to create, edit, or close orders for the tables.
//---------------------------------------------------------------------

#pragma once

#include <Table.h>
#include <Restaurant.h>
#include "ServerMain.h"
#include "ServerClose.h"

namespace RestaurantManagementSystem {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;
   using namespace UIControls;
   using namespace SharedCode;

   /// <summary>
   /// Summary for WaitStaff
   /// </summary>
   public ref class WaitStaffScreen : public System::Windows::Forms::Form
   {
   public:
      WaitStaffScreen(void)
      {
         WaitStaffScreen(nullptr);
      }
      WaitStaffScreen(Form ^ form)
      {
         InitializeComponent();
         this->form = form;
      }
   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~WaitStaffScreen()
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
   private: System::Windows::Forms::GroupBox^  grpTables;
   private: System::Windows::Forms::FlowLayoutPanel^  tableList;

   protected:

   protected:

   protected:



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
         this->grpTables = (gcnew System::Windows::Forms::GroupBox());
         this->tableList = (gcnew System::Windows::Forms::FlowLayoutPanel());
         this->grpTables->SuspendLayout();
         this->SuspendLayout();
         // 
         // grpTables
         // 
         this->grpTables->Controls->Add(this->tableList);
         this->grpTables->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->grpTables->Location = System::Drawing::Point(12, 12);
         this->grpTables->Name = L"grpTables";
         this->grpTables->Size = System::Drawing::Size(1240, 657);
         this->grpTables->TabIndex = 13;
         this->grpTables->TabStop = false;
         this->grpTables->Text = L"Tables";
         // 
         // tableList
         // 
         this->tableList->AutoScroll = true;
         this->tableList->Location = System::Drawing::Point(8, 28);
         this->tableList->Name = L"tableList";
         this->tableList->Size = System::Drawing::Size(1226, 623);
         this->tableList->TabIndex = 10;
         this->tableList->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &WaitStaffScreen::tableList_Paint);
         // 
         // WaitStaffScreen
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(1264, 681);
         this->Controls->Add(this->grpTables);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->Name = L"WaitStaffScreen";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Waitron Screen";
         this->Activated += gcnew System::EventHandler(this, &WaitStaffScreen::WaitStaffScreen_Activated);
         this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &WaitStaffScreen::WaitStaffScreen_FormClosing);
         this->Load += gcnew System::EventHandler(this, &WaitStaffScreen::WaitStaff_Load);
         this->Shown += gcnew System::EventHandler(this, &WaitStaffScreen::WaitStaffScreen_Shown);
         this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &WaitStaffScreen::WaitStaffScreen_Paint);
         this->Enter += gcnew System::EventHandler(this, &WaitStaffScreen::WaitStaffScreen_Enter);
         this->grpTables->ResumeLayout(false);
         this->ResumeLayout(false);

      }
#pragma endregion
   private: System::Void WaitStaff_Load(System::Object^  sender, System::EventArgs^  e)
   {
      RefreshScreen();

   }
   private: System::Void btnTakeOrder_Click(System::Object^  sender, System::EventArgs^  e)
   {
      int index = ((int)Restaurant::GetRestaurant()->getOrderController()->getOrders().size());
      ServerMain ^ serverMain = gcnew ServerMain(this, this->form, Restaurant::GetRestaurant()->getOrderController()->OrderAt(index - 1));
      serverMain->Show();
      this->Hide();
   }
   private: System::Void btnPay_Click(System::Object^  sender, EventArgs^  e)
   {
      ServerTableGUI ^ tempGUI = ((ServerTableGUI^)(((Button^)sender)->Tag));
      int tableID = tempGUI->tableID;
      int orderID = Restaurant::GetRestaurant()->getTableController()->GetTable(tableID)->OrderID();
      ServerClose ^ serverClose = gcnew ServerClose(this, this->form, Restaurant::GetRestaurant()->getOrderController()->OrderWithID(orderID));
      serverClose->Show();
      this->Hide();
   }
   private: System::Void btnEditOrder_Click(System::Object^ sender, EventArgs^ e)
   {
      ServerTableGUI ^ tempGUI1 = ((ServerTableGUI^)(((Button^)sender)->Tag));
      int tableID = tempGUI1->tableID;
      int orderID = Restaurant::GetRestaurant()->getTableController()->GetTable(tableID)->OrderID();
      ServerMain ^ serverMain = gcnew ServerMain(this, this->form, Restaurant::GetRestaurant()->getOrderController()->OrderWithID(orderID));
      serverMain->Show();
      this->Hide();
   }
   private: System::Void WaitStaffScreen_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
   {
      if (form != nullptr)
         form->Show();
   }
   private: System::Void tableList_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
   {
   }
   public: void RefreshScreen()
   {
      Restaurant * restaurant = Restaurant::GetRestaurant();

      if (restaurant == NULL)
         return;

      TableContainer tables = restaurant->getTableController()->getTables();

      for (unsigned int table = 0; table < tables.size(); table++)
      {
         tableList->Controls->Add(
            gcnew ServerTableGUI(
               table,
               gcnew System::EventHandler(this, &WaitStaffScreen::btnTakeOrder_Click),
               gcnew System::EventHandler(this, &WaitStaffScreen::btnPay_Click),
               gcnew System::EventHandler(this, &WaitStaffScreen::btnEditOrder_Click)));
      }
   }
   private: System::Void WaitStaffScreen_Shown(System::Object^  sender, System::EventArgs^  e)
   {
      //RefreshScreen();
   }
   public: System::Void WaitStaffScreen_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
   {
      //RefreshScreen();
   }
   private: System::Void WaitStaffScreen_Activated(System::Object^  sender, System::EventArgs^  e)
   {
      //RefreshScreen();
   }
   private: System::Void WaitStaffScreen_Enter(System::Object^  sender, System::EventArgs^  e)
   {
      //RefreshScreen();
   }
   };
}
