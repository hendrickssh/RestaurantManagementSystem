//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Server Table GUI
//---------------------------------------------------------------------

#pragma once

#include <Table.h>
#include <Restaurant.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace SharedCode;

using namespace std;

namespace UIControls {

   /// <summary>
   /// Summary for ServerTableGUI
   /// </summary>
   public ref class ServerTableGUI : public System::Windows::Forms::UserControl
   {

   private: Table * table;
   public: int tableID;
   private: System::Windows::Forms::Button^  btnPay;
   private: System::Windows::Forms::Button^  btnEditOrder;
   public: int orderID;

   public:
      ServerTableGUI(void)
      {
         InitializeComponent();
      }
      /// <summary>
      /// Creates a new HostTableGUI object and pre-sets the table object 
      /// that it is meant to use.
      /// 
      /// The table pointer is NOT owned by the HostTableGUI object, it should
      /// be a part of the Table controller. If the table pointer is not part of
      /// the table controller then it should be tracked and deleted after the
      /// HostTableGUI object is deleted.
      /// </summary>
      /// <param name="table">The table object for which to display info.</param>
   public:
      ServerTableGUI(int tableID, System::EventHandler ^ clickEvent, System::EventHandler ^ clickEvent1, System::EventHandler ^ clickEvent2)
      {
         InitializeComponent();

         this->tableID = tableID;

         this->openTakeOrderScreen = openTakeOrderScreen;

         this->openPayScreen = openPayScreen;

         table = Restaurant::GetRestaurant()->getTableController()->GetTable(tableID);

         int tableNum = table->GetTableNum();

         String ^ str = tableNum.ToString();

         lblTableNum->Text = lblTableNum->Text->Replace("##", str);

         this->btnTakeOrder->Click += clickEvent;
         this->btnPay->Click += clickEvent1;
         this->btnEditOrder->Click += clickEvent2;

         this->btnPay->Tag = this;
         this->btnEditOrder->Tag = this;
      }


   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~ServerTableGUI()
      {
         if (components)
         {
            delete components;
         }
      }
   private: System::Windows::Forms::Button^  btnTakeOrder;
   protected:
   private: System::Windows::Forms::TreeView^  treeTable;
   private: System::Windows::Forms::Label^  lblTableNum;

   private:
      /// <summary>
      /// Required designer variable.
      /// </summary>
      System::ComponentModel::Container ^components;
      System::Windows::Forms::TreeNode^  idNode;
      System::Windows::Forms::TreeNode^  completeNode;
      System::Windows::Forms::TreeNode^  orderNode;

      void BuildTree()
      {
         idNode = (gcnew System::Windows::Forms::TreeNode(L"Name:"));
         completeNode = (gcnew System::Windows::Forms::TreeNode(L"Time:"));
         orderNode = (gcnew System::Windows::Forms::TreeNode(L"Reservation", gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
            idNode,
               completeNode
         }));

         idNode->Name = L"ID";
         idNode->Text = L"ID:";
         completeNode->Name = L"No Order";
         completeNode->Text = L"No Order";
         orderNode->Name = L"Order";
         orderNode->Text = L"Order";
         this->treeTable->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { orderNode
         });

      }
#pragma region Windows Form Designer generated code
      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      void InitializeComponent(void)
      {
         this->btnTakeOrder = (gcnew System::Windows::Forms::Button());
         this->treeTable = (gcnew System::Windows::Forms::TreeView());
         this->lblTableNum = (gcnew System::Windows::Forms::Label());
         this->btnPay = (gcnew System::Windows::Forms::Button());
         this->btnEditOrder = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();
         // 
         // btnTakeOrder
         // 
         this->btnTakeOrder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnTakeOrder->Location = System::Drawing::Point(4, 148);
         this->btnTakeOrder->Name = L"btnTakeOrder";
         this->btnTakeOrder->Size = System::Drawing::Size(197, 30);
         this->btnTakeOrder->TabIndex = 9;
         this->btnTakeOrder->Text = L"Take Order";
         this->btnTakeOrder->UseVisualStyleBackColor = true;
         this->btnTakeOrder->Click += gcnew System::EventHandler(this, &ServerTableGUI::btnTakeOrder_Click);
         // 
         // treeTable
         // 
         this->treeTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->treeTable->Location = System::Drawing::Point(4, 34);
         this->treeTable->Name = L"treeTable";
         this->treeTable->ShowRootLines = false;
         this->treeTable->Size = System::Drawing::Size(197, 109);
         this->treeTable->TabIndex = 8;
         // 
         // lblTableNum
         // 
         this->lblTableNum->AutoSize = true;
         this->lblTableNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblTableNum->Location = System::Drawing::Point(50, 11);
         this->lblTableNum->Name = L"lblTableNum";
         this->lblTableNum->Size = System::Drawing::Size(104, 24);
         this->lblTableNum->TabIndex = 7;
         this->lblTableNum->Text = L"Table - ##";
         // 
         // btnPay
         // 
         this->btnPay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnPay->Location = System::Drawing::Point(4, 148);
         this->btnPay->Name = L"btnPay";
         this->btnPay->Size = System::Drawing::Size(197, 30);
         this->btnPay->TabIndex = 10;
         this->btnPay->Text = L"Pay";
         this->btnPay->UseVisualStyleBackColor = true;
         this->btnPay->Visible = false;
         this->btnPay->Click += gcnew System::EventHandler(this, &ServerTableGUI::btnPay_Click);
         // 
         // btnEditOrder
         // 
         this->btnEditOrder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnEditOrder->Location = System::Drawing::Point(4, 148);
         this->btnEditOrder->Name = L"btnEditOrder";
         this->btnEditOrder->Size = System::Drawing::Size(197, 30);
         this->btnEditOrder->TabIndex = 11;
         this->btnEditOrder->Text = L"Edit Order";
         this->btnEditOrder->UseVisualStyleBackColor = true;
         this->btnEditOrder->Visible = false;
         this->btnEditOrder->Click += gcnew System::EventHandler(this, &ServerTableGUI::btnEditOrder_Click);
         // 
         // ServerTableGUI
         // 
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
         this->Controls->Add(this->btnEditOrder);
         this->Controls->Add(this->btnPay);
         this->Controls->Add(this->btnTakeOrder);
         this->Controls->Add(this->treeTable);
         this->Controls->Add(this->lblTableNum);
         this->Name = L"ServerTableGUI";
         this->Size = System::Drawing::Size(204, 188);
         this->Load += gcnew System::EventHandler(this, &ServerTableGUI::ServerTableGUI_Load);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void ServerTableGUI_Load(System::Object^  sender, System::EventArgs^  e)
   {
      BuildTree();
      RefreshScreen();
   }

   private: System::Void(__cdecl *openTakeOrderScreen) (int);

   private: System::Void btnTakeOrder_Click(System::Object^  sender, System::EventArgs^  e)
   {
      Restaurant::GetRestaurant()->getOrderController()->CreateOrder();
      int index = (int)(Restaurant::GetRestaurant()->getOrderController()->getOrders().size());
      this->orderID = index;
      this->table->UpdateOrderID(orderID);
      RefreshScreen();
   }

   private: System::Void RefreshScreen()
   {
      orderNode->Text = "Order";
      treeTable->ExpandAll();
      btnPay->Visible = false;
      btnEditOrder->Visible = false;
      btnTakeOrder->Visible = true;
      if (!table->Vacant())
      {
         if (this->table->OrderID() != -1)
         {
            btnTakeOrder->Enabled = false;
            Order * temp = Restaurant::GetRestaurant()->getOrderController()->OrderWithID(table->OrderID());
            idNode->Text = "ID: " + table->OrderID().ToString();
            if (temp->GetOrderState())
            {
               completeNode->Text = "Ready for pickup";
               this->treeTable->BackColor = Color::LightGreen;
               btnTakeOrder->Visible = false;
               btnPay->Visible = true;
            }
            else
            {
               completeNode->Text = "Being Prepared";
               this->treeTable->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                  static_cast<System::Int32>(static_cast<System::Byte>(128)));;
               btnEditOrder->Visible = true;
            }
         }
         else
         {
            btnTakeOrder->Enabled = true;
            this->treeTable->BackColor = Color::IndianRed;
            idNode->Text = "No Order";
         }
      }
      else
      {
         btnTakeOrder->Enabled = false;
      }

   }
            private: System::Void(__cdecl *openPayScreen) (int);
   private: System::Void btnPay_Click(System::Object^  sender, System::EventArgs^  e) 
   {

   }
private: System::Void btnEditOrder_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
