#pragma once

#include <Table.h>
#include <Restaurant.h>
#include <ReservationController.h>
#include "UIControls.h"

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
   /// Summary for MyUserControl
   /// </summary>
   public ref class MyUserControl : public System::Windows::Forms::UserControl
   {

   private: Table * table;

   public:
      MyUserControl(void)
      {
         InitializeComponent();
         //
         //TODO: Add the constructor code here
         //
      }
   public:
      MyUserControl(int tableID)
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
      ~MyUserControl()
      {
         if (components)
         {
            delete components;
         }
      }
   private: System::Windows::Forms::Label^  lblTableNum;
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
         this->lblTableNum = (gcnew System::Windows::Forms::Label());
         this->SuspendLayout();
         // 
         // lblTableNum
         // 
         this->lblTableNum->AutoSize = true;
         this->lblTableNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblTableNum->Location = System::Drawing::Point(3, 16);
         this->lblTableNum->Name = L"lblTableNum";
         this->lblTableNum->Size = System::Drawing::Size(86, 20);
         this->lblTableNum->TabIndex = 0;
         this->lblTableNum->Text = L"TABLE: ##";
         // 
         // MyUserControl
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->Controls->Add(this->lblTableNum);
         this->Name = L"MyUserControl";
         this->Size = System::Drawing::Size(110, 110);
         this->Load += gcnew System::EventHandler(this, &MyUserControl::MyUserControl_Load);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void MyUserControl_Load(System::Object^  sender, System::EventArgs^  e) {
      Restaurant * restaurant = Restaurant::GetRestaurant();
      if (restaurant == NULL)
         return;
      ReservationController * resController = restaurant->getReservationController();
      if (resController->NumReservations() > 0)
      {
         if (table->UpdateReservation(resController->GetReservationAt(0)))
            resController->RemoveReservation(table->ReservationName());
      }
   }
   }
}
};
}
