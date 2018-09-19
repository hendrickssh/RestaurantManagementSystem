//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: GUI for the host to seat tables and take reservations.
//---------------------------------------------------------------------

#pragma once

#include <msclr/marshal.h>

#include <Table.h>
#include <Reservation.h>
#include <ReservationController.h>
#include <Restaurant.h>

namespace RestaurantManagementSystem {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;
   using namespace UIControls;
   using namespace SharedCode;
   using namespace msclr::interop;

   /// <summary>
   /// Summary for HostScreen
   /// </summary>
   public ref class HostScreen : public System::Windows::Forms::Form
   {
   public:
      HostScreen(void)
      {
         HostScreen(nullptr);
      }

      /// <summary>
      /// Creates a HostScreen with a form reference to the parent.
      /// </summary>
      /// <param name="form">Pass in the form which is opening this one, usually just use "this".</param>
      HostScreen(Form ^ form)
      {
         InitializeComponent();
         this->form = form;
      }

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~HostScreen()
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

   private: System::Windows::Forms::ListBox^  lstReservations;

   protected:

   private: System::Windows::Forms::Button^  btnArrival;
   private: System::Windows::Forms::Button^  btnRemove;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::Button^  btnRemoveWaiting;

   private: System::Windows::Forms::Button^  btnSeat;


   private: System::Windows::Forms::ListBox^  lstWaiting;

   private: System::Windows::Forms::FlowLayoutPanel^  tableList;
   private: System::Windows::Forms::GroupBox^  grpTables;
   private: System::Windows::Forms::GroupBox^  gbCreateRes;

   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::TextBox^  txtGuestName;
   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Button^  btnAddReservation;
   private: System::Windows::Forms::DateTimePicker^  dtpTime;
   private: System::Windows::Forms::Button^  btnCreateWalkIn;



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
         this->lstReservations = (gcnew System::Windows::Forms::ListBox());
         this->btnArrival = (gcnew System::Windows::Forms::Button());
         this->btnRemove = (gcnew System::Windows::Forms::Button());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->btnRemoveWaiting = (gcnew System::Windows::Forms::Button());
         this->btnSeat = (gcnew System::Windows::Forms::Button());
         this->lstWaiting = (gcnew System::Windows::Forms::ListBox());
         this->tableList = (gcnew System::Windows::Forms::FlowLayoutPanel());
         this->grpTables = (gcnew System::Windows::Forms::GroupBox());
         this->gbCreateRes = (gcnew System::Windows::Forms::GroupBox());
         this->btnCreateWalkIn = (gcnew System::Windows::Forms::Button());
         this->dtpTime = (gcnew System::Windows::Forms::DateTimePicker());
         this->btnAddReservation = (gcnew System::Windows::Forms::Button());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->txtGuestName = (gcnew System::Windows::Forms::TextBox());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->grpTables->SuspendLayout();
         this->gbCreateRes->SuspendLayout();
         this->SuspendLayout();
         // 
         // lstReservations
         // 
         this->lstReservations->FormattingEnabled = true;
         this->lstReservations->Location = System::Drawing::Point(12, 34);
         this->lstReservations->Name = L"lstReservations";
         this->lstReservations->Size = System::Drawing::Size(175, 316);
         this->lstReservations->TabIndex = 0;
         // 
         // btnArrival
         // 
         this->btnArrival->Location = System::Drawing::Point(12, 356);
         this->btnArrival->Name = L"btnArrival";
         this->btnArrival->Size = System::Drawing::Size(175, 33);
         this->btnArrival->TabIndex = 2;
         this->btnArrival->Text = L"Arrival";
         this->btnArrival->UseVisualStyleBackColor = true;
         this->btnArrival->Click += gcnew System::EventHandler(this, &HostScreen::btnArrival_Click_1);
         // 
         // btnRemove
         // 
         this->btnRemove->Location = System::Drawing::Point(12, 395);
         this->btnRemove->Name = L"btnRemove";
         this->btnRemove->Size = System::Drawing::Size(175, 33);
         this->btnRemove->TabIndex = 3;
         this->btnRemove->Text = L"Remove Reservation";
         this->btnRemove->UseVisualStyleBackColor = true;
         this->btnRemove->Click += gcnew System::EventHandler(this, &HostScreen::btnRemove_Click);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(34, 9);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(130, 24);
         this->label1->TabIndex = 4;
         this->label1->Text = L"Reservations";
         this->label1->Click += gcnew System::EventHandler(this, &HostScreen::label1_Click);
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label2->Location = System::Drawing::Point(241, 9);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(89, 24);
         this->label2->TabIndex = 9;
         this->label2->Text = L"Walk-Ins";
         // 
         // btnRemoveWaiting
         // 
         this->btnRemoveWaiting->Location = System::Drawing::Point(193, 395);
         this->btnRemoveWaiting->Name = L"btnRemoveWaiting";
         this->btnRemoveWaiting->Size = System::Drawing::Size(175, 33);
         this->btnRemoveWaiting->TabIndex = 8;
         this->btnRemoveWaiting->Text = L"Remove Patron";
         this->btnRemoveWaiting->UseVisualStyleBackColor = true;
         this->btnRemoveWaiting->Click += gcnew System::EventHandler(this, &HostScreen::btnRemoveWaiting_Click);
         // 
         // btnSeat
         // 
         this->btnSeat->Location = System::Drawing::Point(193, 356);
         this->btnSeat->Name = L"btnSeat";
         this->btnSeat->Size = System::Drawing::Size(175, 33);
         this->btnSeat->TabIndex = 7;
         this->btnSeat->Text = L"Seat";
         this->btnSeat->UseVisualStyleBackColor = true;
         this->btnSeat->Click += gcnew System::EventHandler(this, &HostScreen::btnSeat_Click);
         // 
         // lstWaiting
         // 
         this->lstWaiting->FormattingEnabled = true;
         this->lstWaiting->Location = System::Drawing::Point(193, 34);
         this->lstWaiting->Name = L"lstWaiting";
         this->lstWaiting->Size = System::Drawing::Size(175, 316);
         this->lstWaiting->TabIndex = 5;
         // 
         // tableList
         // 
         this->tableList->AutoScroll = true;
         this->tableList->Location = System::Drawing::Point(6, 19);
         this->tableList->Name = L"tableList";
         this->tableList->Size = System::Drawing::Size(866, 635);
         this->tableList->TabIndex = 10;
         this->tableList->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &HostScreen::tableList_Paint);
         // 
         // grpTables
         // 
         this->grpTables->Controls->Add(this->tableList);
         this->grpTables->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->grpTables->Location = System::Drawing::Point(374, 9);
         this->grpTables->Name = L"grpTables";
         this->grpTables->Size = System::Drawing::Size(878, 660);
         this->grpTables->TabIndex = 12;
         this->grpTables->TabStop = false;
         this->grpTables->Text = L"Tables";
         // 
         // gbCreateRes
         // 
         this->gbCreateRes->Controls->Add(this->btnCreateWalkIn);
         this->gbCreateRes->Controls->Add(this->dtpTime);
         this->gbCreateRes->Controls->Add(this->btnAddReservation);
         this->gbCreateRes->Controls->Add(this->label4);
         this->gbCreateRes->Controls->Add(this->txtGuestName);
         this->gbCreateRes->Controls->Add(this->label3);
         this->gbCreateRes->Location = System::Drawing::Point(12, 435);
         this->gbCreateRes->Name = L"gbCreateRes";
         this->gbCreateRes->Size = System::Drawing::Size(356, 234);
         this->gbCreateRes->TabIndex = 13;
         this->gbCreateRes->TabStop = false;
         // 
         // btnCreateWalkIn
         // 
         this->btnCreateWalkIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->btnCreateWalkIn->Location = System::Drawing::Point(168, 181);
         this->btnCreateWalkIn->Name = L"btnCreateWalkIn";
         this->btnCreateWalkIn->Size = System::Drawing::Size(140, 47);
         this->btnCreateWalkIn->TabIndex = 6;
         this->btnCreateWalkIn->Text = L"Walk-In";
         this->btnCreateWalkIn->UseVisualStyleBackColor = true;
         this->btnCreateWalkIn->Click += gcnew System::EventHandler(this, &HostScreen::btnCreateWalkIn_Click);
         // 
         // dtpTime
         // 
         this->dtpTime->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->dtpTime->CustomFormat = L"hh:mm tt";
         this->dtpTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
         this->dtpTime->Location = System::Drawing::Point(12, 109);
         this->dtpTime->Name = L"dtpTime";
         this->dtpTime->ShowUpDown = true;
         this->dtpTime->Size = System::Drawing::Size(225, 20);
         this->dtpTime->TabIndex = 5;
         // 
         // btnAddReservation
         // 
         this->btnAddReservation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->btnAddReservation->Location = System::Drawing::Point(12, 181);
         this->btnAddReservation->Name = L"btnAddReservation";
         this->btnAddReservation->Size = System::Drawing::Size(140, 47);
         this->btnAddReservation->TabIndex = 4;
         this->btnAddReservation->Text = L"Reservation";
         this->btnAddReservation->UseVisualStyleBackColor = true;
         this->btnAddReservation->Click += gcnew System::EventHandler(this, &HostScreen::btnAddReservation_Click);
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label4->Location = System::Drawing::Point(7, 81);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(65, 25);
         this->label4->TabIndex = 2;
         this->label4->Text = L"Time:";
         // 
         // txtGuestName
         // 
         this->txtGuestName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->txtGuestName->Location = System::Drawing::Point(12, 49);
         this->txtGuestName->Name = L"txtGuestName";
         this->txtGuestName->Size = System::Drawing::Size(225, 29);
         this->txtGuestName->TabIndex = 1;
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label3->Location = System::Drawing::Point(7, 20);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(137, 25);
         this->label3->TabIndex = 0;
         this->label3->Text = L"Guest Name:";
         // 
         // HostScreen
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(1264, 681);
         this->Controls->Add(this->gbCreateRes);
         this->Controls->Add(this->grpTables);
         this->Controls->Add(this->label2);
         this->Controls->Add(this->btnRemoveWaiting);
         this->Controls->Add(this->btnSeat);
         this->Controls->Add(this->lstWaiting);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->btnRemove);
         this->Controls->Add(this->btnArrival);
         this->Controls->Add(this->lstReservations);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->Name = L"HostScreen";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Host Screen";
         this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &HostScreen::HostScreen_FormClosing);
         this->Load += gcnew System::EventHandler(this, &HostScreen::HostScreen_Load);
         this->grpTables->ResumeLayout(false);
         this->gbCreateRes->ResumeLayout(false);
         this->gbCreateRes->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
   }
   private: System::Void tableList_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
   {

   }
   private: System::Void HostScreen_Load(System::Object^  sender, System::EventArgs^  e)
   {
      RefreshScreen();
   }

   private: System::Void CreateTables()
   {
      Restaurant * restaurant = Restaurant::GetRestaurant();
      TableContainer tables = restaurant->getTableController()->getTables();
      for (unsigned int table = 0; table < tables.size(); table++)
         tableList->Controls->Add(gcnew HostTableGUI_V2(table, gcnew System::EventHandler(this, &HostScreen::button1_Click)));
   }

   private: System::Void HostScreen_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
   {
      if (form != nullptr)
         form->Show();
   }

   private: System::Void btnAddReservation_Click(System::Object^  sender, System::EventArgs^  e)
   {
      Restaurant * restaurant = Restaurant::GetRestaurant();
      ReservationController * resController = restaurant->getReservationController();
      marshal_context ^ context = gcnew marshal_context();

      if (txtGuestName->Text != "" && dtpTime->Text != "")
      {
         const char * strGuestName = context->marshal_as<const char*>(txtGuestName->Text);
         const char * strResTime = context->marshal_as<const char*>(dtpTime->Text);
         resController->CreateReservation((char*)strGuestName, (char*)strResTime, true);
         lstReservations->Items->Add(txtGuestName->Text + " : " + dtpTime->Text);
      }
   }

   private: System::Void btnRemove_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (lstReservations->SelectedIndex >= 0)
      {
         Restaurant * restaurant = Restaurant::GetRestaurant();
         ReservationController * resController = restaurant->getReservationController();

         System::String ^ test = (lstReservations->SelectedItem->ToString());
         int index = test->IndexOf(" ");
         if (index > 0)
         {
            test = test->Substring(0, index);
            test = test->Trim();
         }
         marshal_context ^ context = gcnew marshal_context();
         const char * strGuestName = context->marshal_as<const char *>(test);
         resController->RemoveReservation((char*)strGuestName);
         lstReservations->Items->Remove(lstReservations->SelectedItem);
      }
   }

   private: System::Void btnArrival_Click(System::Object^  sender, System::EventArgs^  e)
   {




   }

   private: System::Void HostScreen::RefreshScreen()
   {
      this->Controls->Clear();
      InitializeComponent();
      Restaurant * restaurant = Restaurant::GetRestaurant();
      TableContainer tables = restaurant->getTableController()->getTables();
      for (unsigned int table = 0; table < tables.size(); table++)
         tableList->Controls->Add(gcnew HostTableGUI_V2(table));
      ReservationController * resController = restaurant->getReservationController();
      for (int i = 0; i < resController->NumReservations(); i++)
      {
         if (resController->GetReservationAt(i)->IsReservation())
            lstReservations->Items->Add(gcnew System::String(resController->GetReservationAt(i)->Name())
               + " : " + gcnew System::String(resController->GetReservationAt(i)->Time()));
         else
            lstWaiting->Items->Add(gcnew System::String(resController->GetReservationAt(i)->Name())
               + " : " + gcnew System::String(resController->GetReservationAt(i)->Time()));
      }
   }
   private: System::Void btnCreateWalkIn_Click(System::Object^  sender, System::EventArgs^  e)
   {
      Restaurant * restaurant = Restaurant::GetRestaurant();
      ReservationController * resController = restaurant->getReservationController();
      marshal_context ^ context = gcnew marshal_context();
      if (txtGuestName->Text != "" && dtpTime->Text != "")
      {
         const char* strGuestName = context->marshal_as<const char*>(txtGuestName->Text);
         const char* strResTime = context->marshal_as<const char*>(dtpTime->Text);
         resController->CreateReservation((char*)strGuestName, (char*)strResTime, false);
         lstWaiting->Items->Add(txtGuestName->Text + " : " + dtpTime->Text);
      }
   }
   private: System::Void btnRemoveWaiting_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (lstWaiting->SelectedIndex >= 0)
      {
         Restaurant * restaurant = Restaurant::GetRestaurant();
         ReservationController * resController = restaurant->getReservationController();

         System::String ^ test = (lstWaiting->SelectedItem->ToString());
         int index = test->IndexOf(" ");
         if (index > 0)
         {
            test = test->Substring(0, index);
            test = test->Trim();
         }
         marshal_context ^ context = gcnew marshal_context();
         const char * strGuestName = context->marshal_as<const char *>(test);
         resController->RemoveReservation((char*)strGuestName);
         lstWaiting->Items->Remove(lstWaiting->SelectedItem);
      }
   }

   private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
   {
      RefreshScreen();
   }
   private: System::Void btnSeat_Click(System::Object^  sender, System::EventArgs^  e)
   {
      Restaurant * restaurant = Restaurant::GetRestaurant();
      ReservationController * resController = restaurant->getReservationController();
      if (lstWaiting->SelectedIndex >= 0)
      {
         System::String ^ test = (lstWaiting->SelectedItem->ToString());
         int index = test->IndexOf(" ");
         if (index > 0)
         {
            test = test->Substring(0, index);
            test = test->Trim();
         }
         marshal_context ^ context = gcnew marshal_context();
         const char * strGuestName = context->marshal_as<const char *>(test);
         Reservation * res = resController->GetReservation((char*)strGuestName);
         for (int i = 0; i < 20; i++)
         {
            if (restaurant->getTableController()->GetTable(i)->Vacant())
            {
               restaurant->getTableController()->GetTable(i)->UpdateReservation(res);
               restaurant->getTableController()->SeatTable(restaurant->getTableController()->GetTable(i), res);
               resController->RemoveReservation((char*)strGuestName);
               break;
            }
         }
         RefreshScreen();
      }
   };
   private: System::Void btnArrival_Click_1(System::Object^  sender, System::EventArgs^  e)
   {
      Restaurant * restaurant = Restaurant::GetRestaurant();
      ReservationController * resController = restaurant->getReservationController();
      if (lstReservations->SelectedIndex >= 0)
      {
         System::String ^ test = (lstReservations->SelectedItem->ToString());
         int index = test->IndexOf(" ");
         if (index > 0)
         {
            test = test->Substring(0, index);
            test = test->Trim();
         }
         marshal_context ^ context = gcnew marshal_context();
         const char * strGuestName = context->marshal_as<const char *>(test);
         Reservation * res = resController->GetReservation((char*)strGuestName);
         for (int i = 0; i < 20; i++)
         {
            if (restaurant->getTableController()->GetTable(i)->Vacant())
            {
               restaurant->getTableController()->GetTable(i)->UpdateReservation(res);
               restaurant->getTableController()->SeatTable(restaurant->getTableController()->GetTable(i), res);
               resController->RemoveReservation((char*)strGuestName);
               break;
            }
         }
         RefreshScreen();
      }
   }
   };
};


