//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Called when an order is closed. Splashes the amount due(change).
//---------------------------------------------------------------------

#pragma once

namespace RestaurantManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CloseSplash
	/// </summary>
	public ref class CloseSplash : public System::Windows::Forms::Form
	{
	public:
		CloseSplash(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

   private: String ^ change;
   public:
      CloseSplash(String ^ change)
      {
         InitializeComponent();
         this->change = change;
      }
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CloseSplash()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Label^  lblChange;
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
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->lblChange = (gcnew System::Windows::Forms::Label());
         this->SuspendLayout();
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(224, 45);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(118, 23);
         this->label1->TabIndex = 33;
         this->label1->Text = L"CHANGE DUE:";
         // 
         // lblChange
         // 
         this->lblChange->AutoSize = true;
         this->lblChange->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblChange->Location = System::Drawing::Point(256, 93);
         this->lblChange->Name = L"lblChange";
         this->lblChange->Size = System::Drawing::Size(55, 23);
         this->lblChange->TabIndex = 34;
         this->lblChange->Text = L"$0.00";
         this->lblChange->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
         // 
         // CloseSplash
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(584, 211);
         this->ControlBox = false;
         this->Controls->Add(this->lblChange);
         this->Controls->Add(this->label1);
         this->MaximizeBox = false;
         this->MinimizeBox = false;
         this->Name = L"CloseSplash";
         this->ShowIcon = false;
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"CloseSplash";
         this->TopMost = true;
         this->Load += gcnew System::EventHandler(this, &CloseSplash::CloseSplash_Load);
         this->Click += gcnew System::EventHandler(this, &CloseSplash::CloseSplash_Click);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   // -------------------------------------------------------------------
   // Initiate the change amount on load.
   // -------------------------------------------------------------------
   private: System::Void CloseSplash_Load(System::Object^  sender, System::EventArgs^  e) {
      lblChange->Text = change;
   }
   // -------------------------------------------------------------------
   // When you click anywhere on the Component, the component closes
   // -------------------------------------------------------------------
   private: System::Void CloseSplash_Click(System::Object^  sender, System::EventArgs^  e) {
      this->Close();
   }
};
}
