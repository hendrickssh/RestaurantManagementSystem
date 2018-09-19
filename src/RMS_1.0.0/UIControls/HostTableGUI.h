//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Host Table GUI.
//---------------------------------------------------------------------

#pragma once

#include <Table.h>
#include <Restaurant.h>
#include <ReservationController.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace SharedCode;

using namespace std;

namespace UIControls 
{

	/// <summary>
	/// Summary for HostTableGUI
	/// </summary>
	public ref class HostTableGUI : public System::Windows::Forms::UserControl
	{

   private: Table * table;

	public:
      HostTableGUI(void)
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
      HostTableGUI(int tableID)
      {
         InitializeComponent();

         
         table = Restaurant::GetRestaurant()->getTableController()->GetTable(tableID);

         int tableNum = table->GetTableNum();

         String ^ str = tableNum.ToString();
         
         lblTableNum->Text = lblTableNum->Text->Replace("##", str);
      }
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HostTableGUI()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::Label^  lblTableNum;
   protected:

   private: System::Windows::Forms::TreeView^  treeTable;

   private: System::Windows::Forms::Button^  btnSeat;
   protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

      System::Windows::Forms::TreeNode^  statusNode;
      System::Windows::Forms::TreeNode^  capacityNode;
      System::Windows::Forms::TreeNode^  nameNode;
      System::Windows::Forms::TreeNode^  timeNode;
      System::Windows::Forms::TreeNode^  reservationNode;

      void BuildTree()
      {
         statusNode = (gcnew System::Windows::Forms::TreeNode(L"Status:"));
         capacityNode = (gcnew System::Windows::Forms::TreeNode(L"Capacity:"));
         nameNode = (gcnew System::Windows::Forms::TreeNode(L"Name:"));
         timeNode = (gcnew System::Windows::Forms::TreeNode(L"Time:"));
         reservationNode = (gcnew System::Windows::Forms::TreeNode(L"Reservation", gcnew cli::array< System::Windows::Forms::TreeNode^  >(2) {
            nameNode,
               timeNode
         }));

         statusNode->Name = L"Status";
         statusNode->Text = L"Status:";
         capacityNode->Name = L"Capacity";
         capacityNode->Text = L"Capacity:";
         nameNode->Name = L"Name";
         nameNode->Text = L"Name:";
         timeNode->Name = L"Time";
         timeNode->Text = L"Time:";
         reservationNode->Name = L"Reservation";
         reservationNode->Text = L"Reservation";
         this->treeTable->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(3) { statusNode, capacityNode, reservationNode
         });
         
      }

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         
         this->lblTableNum = (gcnew System::Windows::Forms::Label());
         this->treeTable = (gcnew System::Windows::Forms::TreeView());
         this->btnSeat = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();



         this->treeTable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->treeTable->Location = System::Drawing::Point(4, 34);
         this->treeTable->Name = L"treeTable";
         // 
         // lblTableNum
         // 
         this->lblTableNum->AutoSize = true;
         this->lblTableNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblTableNum->Location = System::Drawing::Point(50, 11);
         this->lblTableNum->Name = L"lblTableNum";
         this->lblTableNum->Size = System::Drawing::Size(104, 24);
         this->lblTableNum->TabIndex = 4;
         this->lblTableNum->Text = L"Table - ##";
         // 
         // treeTable
         // 
         this->treeTable->ShowRootLines = false;
         this->treeTable->Size = System::Drawing::Size(197, 109);
         this->treeTable->TabIndex = 5;
         this->treeTable->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &HostTableGUI::treeTable_AfterSelect);
         this->treeTable->Enter += gcnew System::EventHandler(this, &HostTableGUI::treeTable_Enter);
         // 
         // btnSeat
         // 
         this->btnSeat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnSeat->Location = System::Drawing::Point(4, 148);
         this->btnSeat->Name = L"btnSeat";
         this->btnSeat->Size = System::Drawing::Size(197, 30);
         this->btnSeat->TabIndex = 6;
         this->btnSeat->Text = L"Seat";
         this->btnSeat->UseVisualStyleBackColor = true;
         this->btnSeat->Click += gcnew System::EventHandler(this, &HostTableGUI::btnSeat_Click);
         // 
         // HostTableGUI
         // 
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
         this->Controls->Add(this->btnSeat);
         this->Controls->Add(this->treeTable);
         this->Controls->Add(this->lblTableNum);
         this->Name = L"HostTableGUI";
         this->Size = System::Drawing::Size(204, 188);
         this->Load += gcnew System::EventHandler(this, &HostTableGUI::HostTableGUI_Load);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void treeTable_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) 
   {
      
   }
private: System::Void treeTable_Enter(System::Object^  sender, System::EventArgs^  e) 
{
 
}
private: System::Void HostTableGUI_Load(System::Object^  sender, System::EventArgs^  e) {
   BuildTree();
   statusNode->Text = "Status: " + (table->Vacant() ? "Vacant" : "Occupied");
   capacityNode->Text = "Capacity: " + table->Capacity().ToString();
   treeTable->ExpandAll();

   if (!table->Vacant())
   {
      treeTable->ExpandAll();
      nameNode->Text = "Name: " + gcnew String(table->ReservationName());
      timeNode->Text = "Time: " + gcnew String(table->GetReservationTime());
   }
}

private: System::Void btnSeat_Click(System::Object^  sender, System::EventArgs^  e) 
{
   Restaurant * restaurant = Restaurant::GetRestaurant();
   if (restaurant == NULL)
      return;
   ReservationController * resController = restaurant->getReservationController();
   treeTable->ExpandAll();
   if (resController->NumReservations() > 0)
   {
      if (table->UpdateReservation(resController->GetReservationAt(0)))
      {
         nameNode->Text = "Name: " + gcnew String(table->ReservationName());
         timeNode->Text = "Time: " + gcnew String(table->GetReservationTime());
         resController->RemoveReservation(table->ReservationName());
      }
   }
   statusNode->Text = "Status: " + (table->Vacant() ? "Vacant" : "Occupied");
}
};
}
