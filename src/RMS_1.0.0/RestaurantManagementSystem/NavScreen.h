//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: The main "top-level" Screen. Can navigate to the other parts
//    of the application from here.
//---------------------------------------------------------------------

#pragma once

#include "HostScreen.h"
#include "Chef.h"
#include "WaitStaffScreen.h"
#include "RestaurantMenuEditor.h"

namespace RestaurantManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NavScreen
	/// </summary>
	public ref class NavScreen : public System::Windows::Forms::Form
	{
	public:
      Restaurant * inst;
		NavScreen(void)
		{
           InitializeComponent();
           //NavScreen(nullptr);	

           //THIS IS A TEST OF THE UW-PLATTEVILLE EMERGENCY ALERT SYSTEM
           inst = Restaurant::GetRestaurant();
           for (int i = 0; i < 20; i++)
              inst->getTableController()->CreateTable(4);
		}
      NavScreen(Form ^ form)
      {
         InitializeComponent();
         this->form = form;
      }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NavScreen()
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

   private: System::Windows::Forms::Button^  btnHostingStation;
   protected:

   private: System::Windows::Forms::Button^  btnChefStation;
   private: System::Windows::Forms::Button^  btnWaitingStation;




   private: System::Windows::Forms::Button^  btnMenuEditor;



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
         this->btnHostingStation = (gcnew System::Windows::Forms::Button());
         this->btnChefStation = (gcnew System::Windows::Forms::Button());
         this->btnWaitingStation = (gcnew System::Windows::Forms::Button());
         this->btnMenuEditor = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();
         // 
         // btnHostingStation
         // 
         this->btnHostingStation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnHostingStation->Location = System::Drawing::Point(643, 42);
         this->btnHostingStation->Name = L"btnHostingStation";
         this->btnHostingStation->Size = System::Drawing::Size(509, 288);
         this->btnHostingStation->TabIndex = 0;
         this->btnHostingStation->Text = L"Hosting Station";
         this->btnHostingStation->UseVisualStyleBackColor = true;
         this->btnHostingStation->Click += gcnew System::EventHandler(this, &NavScreen::btnHostingStation_Click);
         // 
         // btnChefStation
         // 
         this->btnChefStation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnChefStation->Location = System::Drawing::Point(113, 42);
         this->btnChefStation->Name = L"btnChefStation";
         this->btnChefStation->Size = System::Drawing::Size(509, 288);
         this->btnChefStation->TabIndex = 2;
         this->btnChefStation->Text = L"Chef Station";
         this->btnChefStation->UseVisualStyleBackColor = true;
         this->btnChefStation->Click += gcnew System::EventHandler(this, &NavScreen::btnChefStation_Click);
         // 
         // btnWaitingStation
         // 
         this->btnWaitingStation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnWaitingStation->Location = System::Drawing::Point(643, 351);
         this->btnWaitingStation->Name = L"btnWaitingStation";
         this->btnWaitingStation->Size = System::Drawing::Size(509, 288);
         this->btnWaitingStation->TabIndex = 5;
         this->btnWaitingStation->Text = L"Waiting Station";
         this->btnWaitingStation->UseVisualStyleBackColor = true;
         this->btnWaitingStation->Click += gcnew System::EventHandler(this, &NavScreen::btnWaitingStation_Click);
         // 
         // btnMenuEditor
         // 
         this->btnMenuEditor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnMenuEditor->Location = System::Drawing::Point(113, 351);
         this->btnMenuEditor->Name = L"btnMenuEditor";
         this->btnMenuEditor->Size = System::Drawing::Size(509, 288);
         this->btnMenuEditor->TabIndex = 6;
         this->btnMenuEditor->Text = L"Menu Editor";
         this->btnMenuEditor->UseVisualStyleBackColor = true;
         this->btnMenuEditor->Click += gcnew System::EventHandler(this, &NavScreen::btnMenuEditor_Click);
         // 
         // NavScreen
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(1264, 681);
         this->Controls->Add(this->btnMenuEditor);
         this->Controls->Add(this->btnWaitingStation);
         this->Controls->Add(this->btnChefStation);
         this->Controls->Add(this->btnHostingStation);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->Name = L"NavScreen";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Restaurant Management System - Nav";
         this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NavScreen::NavScreen_FormClosing);
         this->Load += gcnew System::EventHandler(this, &NavScreen::NavScreen_Load);
         this->ResumeLayout(false);

      }
#pragma endregion
private: System::Void btnHostingStation_Click(System::Object^  sender, System::EventArgs^  e) 
{
   HostScreen ^ hostScreen = gcnew HostScreen(this);
   hostScreen->Show();
   this->Hide();
}
private: System::Void btnChefStation_Click(System::Object^  sender, System::EventArgs^  e) 
{
   Chef ^ chefScreen = gcnew Chef(this);
   chefScreen->Show();
   this->Hide();
}
private: System::Void btnBarStation_Click(System::Object^  sender, System::EventArgs^  e) 
{
  
}
private: System::Void btnWaitingStation_Click(System::Object^  sender, System::EventArgs^  e) 
{
   if (inst->getRestaurantMenu()->numCategories() != 0) {
      WaitStaffScreen ^ waitStaffScreen = gcnew WaitStaffScreen(this);
      waitStaffScreen->Show();
      this->Hide();
   }
}
private: System::Void NavScreen_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
{
   if (form != nullptr)
      form->Show();
   delete inst;
}
private: System::Void NavScreen_Load(System::Object^  sender, System::EventArgs^  e) 
{
   
}
private: System::Void btnMenuEditor_Click(System::Object^  sender, System::EventArgs^  e) 
{
   RestaurantMenuEditor ^ menuEditor = gcnew RestaurantMenuEditor(this);
   menuEditor->Show();
   this->Hide();
}
};
}
