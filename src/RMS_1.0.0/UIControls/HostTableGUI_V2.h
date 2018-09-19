//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Host Table GUI V2.
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


namespace UIControls {

	/// <summary>
	/// Summary for HostTableGUI_V2
	/// </summary>
	public ref class HostTableGUI_V2 : public System::Windows::Forms::UserControl
	{

   public: Table * table;
   public: Form ^ form;
	public:
		HostTableGUI_V2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

      HostTableGUI_V2(int tableID)
      {
         InitializeComponent();


         table = Restaurant::GetRestaurant()->getTableController()->GetTable(tableID);

         int tableNum = table->GetTableNum();

         String ^ str = tableNum.ToString();

         lblTableNum->Text = str;
      }

      HostTableGUI_V2(int tableID, Form ^ f)
      {
         InitializeComponent();


         table = Restaurant::GetRestaurant()->getTableController()->GetTable(tableID);

         int tableNum = table->GetTableNum();

         String ^ str = tableNum.ToString();

         lblTableNum->Text = str;
         this->form = f;
      }

      HostTableGUI_V2(int tableID,System::EventHandler ^ clickEvent)
      {
         InitializeComponent();


         table = Restaurant::GetRestaurant()->getTableController()->GetTable(tableID);

         int tableNum = table->GetTableNum();

         String ^ str = tableNum.ToString();

         lblTableNum->Text = str;
         this->btnSeat->Click += clickEvent;
      }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HostTableGUI_V2()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::Label^  lblTableNum;
   protected:

   public: System::Windows::Forms::Button^  btnSeat;

   private: System::Windows::Forms::Label^  lblCapacity;


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
         this->lblTableNum = (gcnew System::Windows::Forms::Label());
         this->btnSeat = (gcnew System::Windows::Forms::Button());
         this->lblCapacity = (gcnew System::Windows::Forms::Label());
         this->SuspendLayout();
         // 
         // lblTableNum
         // 
         this->lblTableNum->Anchor = System::Windows::Forms::AnchorStyles::None;
         this->lblTableNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblTableNum->ForeColor = System::Drawing::SystemColors::ControlText;
         this->lblTableNum->Location = System::Drawing::Point(-1, 0);
         this->lblTableNum->Name = L"lblTableNum";
         this->lblTableNum->Size = System::Drawing::Size(203, 120);
         this->lblTableNum->TabIndex = 0;
         this->lblTableNum->Text = L"1";
         this->lblTableNum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // btnSeat
         // 
         this->btnSeat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnSeat->Location = System::Drawing::Point(-1, 137);
         this->btnSeat->Name = L"btnSeat";
         this->btnSeat->Size = System::Drawing::Size(204, 50);
         this->btnSeat->TabIndex = 1;
         this->btnSeat->Text = L"Seat";
         this->btnSeat->UseVisualStyleBackColor = true;
         this->btnSeat->Click += gcnew System::EventHandler(this, &HostTableGUI_V2::button1_Click);
         // 
         // lblCapacity
         // 
         this->lblCapacity->AutoSize = true;
         this->lblCapacity->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblCapacity->Location = System::Drawing::Point(12, 109);
         this->lblCapacity->Name = L"lblCapacity";
         this->lblCapacity->Size = System::Drawing::Size(70, 25);
         this->lblCapacity->TabIndex = 3;
         this->lblCapacity->Text = L"label1";
         // 
         // HostTableGUI_V2
         // 
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
         this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
         this->Controls->Add(this->lblCapacity);
         this->Controls->Add(this->btnSeat);
         this->Controls->Add(this->lblTableNum);
         this->Name = L"HostTableGUI_V2";
         this->Size = System::Drawing::Size(202, 186);
         this->Load += gcnew System::EventHandler(this, &HostTableGUI_V2::HostTableGUI_V2_Load);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   public: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
   {
      if (table->Vacant())
      {
         table->UpdateReservation(new Reservation());
      }
      else
      {
         Restaurant * temp = Restaurant::GetRestaurant();
         Order * ord = temp->getOrderController()->OrderWithID(table->OrderID());
         table->RemoveReservation();
         if(temp->getOrderController()->OrderWithID(table->OrderID()) != NULL)
            temp->getOrderController()->CompleteOrder(ord);
         table->UpdateOrderID(-1);
      }
      update();
   }
   private: System::Void HostTableGUI_V2_Load(System::Object^  sender, System::EventArgs^  e)
   {
      update();
   }
private: System::Void btnUnseat_Click(System::Object^  sender, System::EventArgs^  e) 
{
   
}

public: void update()
{
   this->lblCapacity->Text = "Seats: " + table->Capacity().ToString();
   if (table->Vacant())
   {
      this->btnSeat->Text = "Seat";
      this->BackColor = Color::LightGreen;
   }
   else
   {
      this->btnSeat->Text = "Unseat";
      this->BackColor = Color::IndianRed;
   }
}
};
}
