//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: GUI for closing the check and taking payment.
//---------------------------------------------------------------------

#pragma once
#include "CloseCash.h"
#include "CloseSplash.h"
#include "Receipt.h"
#include "Printer.h"
#include <Order.h>
#include "Restaurant.h"

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
	/// Summary for ServerClose
	/// </summary>
	public ref class ServerClose : public System::Windows::Forms::Form
	{
	public:
		ServerClose(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
      Form ^ form; //Previous screen
   private: System::Windows::Forms::Button^  btnResetPay;
   private: System::Windows::Forms::GroupBox^  groupCash;
   private: System::Windows::Forms::Button^  btnCash100;
   private: System::Windows::Forms::Button^  btnCash50;
   private: System::Windows::Forms::Button^  btnCash20;
   private: System::Windows::Forms::Button^  btnCash10;
   private: System::Windows::Forms::Button^  btnCash5;
   private: System::Windows::Forms::Button^  btnCash1;
   private: System::Windows::Forms::Button^  btnDisc;
   private: System::Windows::Forms::Button^  btnMC;
   private: System::Windows::Forms::Button^  btnVisa;
   private: System::Windows::Forms::Button^  btnCheck;
   private: System::Windows::Forms::Button^  btnCash;











   public:
      Order * myOrder;
   private: System::Windows::Forms::TreeView^  orderTree;
   public:
      Form ^ login; //Login screen for done button
      double mySubTotal;
      ServerClose(Form^ form, Form ^ login)
      {
         InitializeComponent();
         this->form = form;
         this->login = login;
      }
      ServerClose(Form^ form, Form ^ login, Order * order)
      {
         InitializeComponent();
         this->myOrder = order;
         this->form = form;
         this->login = login;
         mySubTotal = GetSubTotal(order);
      }
   private: System::Windows::Forms::Label^  lblCash;
   public:



   public:
   private: System::Windows::Forms::Label^  label6;
   private: System::Windows::Forms::Label^  label8;
   private: System::Windows::Forms::Label^  label9;
   private: System::Windows::Forms::Label^  label10;
   private: System::Windows::Forms::Label^  label11;
   public:
   private: System::Windows::Forms::Label^  lblBalance;
   public:
   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::Label^  label7;
   public:
   private: System::Windows::Forms::Label^  lblChange;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServerClose()
		{
			if (components)
			{
				delete components;
			}
		}

   private: System::Windows::Forms::Button^  btnPrint;
   private: System::Windows::Forms::Label^  lblTax;

   private: System::Windows::Forms::Label^  lblTotal;
   private: System::Windows::Forms::Label^  lblSubTot;


   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::Label^  label1;












   private: System::Windows::Forms::Button^  btnDone;
   private: System::Windows::Forms::Button^  btnReturn;









   private: System::Windows::Forms::Button^  btnClose;
   private: System::Windows::Forms::Button^  btnPromo;
   private: System::Windows::Forms::Button^  btnPayment;


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
         this->btnDone = (gcnew System::Windows::Forms::Button());
         this->btnReturn = (gcnew System::Windows::Forms::Button());
         this->btnClose = (gcnew System::Windows::Forms::Button());
         this->btnPromo = (gcnew System::Windows::Forms::Button());
         this->btnPayment = (gcnew System::Windows::Forms::Button());
         this->btnPrint = (gcnew System::Windows::Forms::Button());
         this->lblTax = (gcnew System::Windows::Forms::Label());
         this->lblTotal = (gcnew System::Windows::Forms::Label());
         this->lblSubTot = (gcnew System::Windows::Forms::Label());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->label7 = (gcnew System::Windows::Forms::Label());
         this->lblChange = (gcnew System::Windows::Forms::Label());
         this->lblBalance = (gcnew System::Windows::Forms::Label());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->lblCash = (gcnew System::Windows::Forms::Label());
         this->label6 = (gcnew System::Windows::Forms::Label());
         this->label8 = (gcnew System::Windows::Forms::Label());
         this->label9 = (gcnew System::Windows::Forms::Label());
         this->label10 = (gcnew System::Windows::Forms::Label());
         this->label11 = (gcnew System::Windows::Forms::Label());
         this->btnResetPay = (gcnew System::Windows::Forms::Button());
         this->groupCash = (gcnew System::Windows::Forms::GroupBox());
         this->btnCash100 = (gcnew System::Windows::Forms::Button());
         this->btnCash50 = (gcnew System::Windows::Forms::Button());
         this->btnCash20 = (gcnew System::Windows::Forms::Button());
         this->btnCash10 = (gcnew System::Windows::Forms::Button());
         this->btnCash5 = (gcnew System::Windows::Forms::Button());
         this->btnCash1 = (gcnew System::Windows::Forms::Button());
         this->btnDisc = (gcnew System::Windows::Forms::Button());
         this->btnMC = (gcnew System::Windows::Forms::Button());
         this->btnVisa = (gcnew System::Windows::Forms::Button());
         this->btnCheck = (gcnew System::Windows::Forms::Button());
         this->btnCash = (gcnew System::Windows::Forms::Button());
         this->orderTree = (gcnew System::Windows::Forms::TreeView());
         this->groupCash->SuspendLayout();
         this->SuspendLayout();
         // 
         // btnDone
         // 
         this->btnDone->BackColor = System::Drawing::Color::IndianRed;
         this->btnDone->Font = (gcnew System::Drawing::Font(L"Calibri", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnDone->ForeColor = System::Drawing::Color::White;
         this->btnDone->Location = System::Drawing::Point(570, 0);
         this->btnDone->Name = L"btnDone";
         this->btnDone->Size = System::Drawing::Size(150, 70);
         this->btnDone->TabIndex = 1;
         this->btnDone->Text = L"DONE";
         this->btnDone->UseVisualStyleBackColor = false;
         this->btnDone->Click += gcnew System::EventHandler(this, &ServerClose::btnDone_Click);
         // 
         // btnReturn
         // 
         this->btnReturn->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnReturn->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnReturn->Location = System::Drawing::Point(1165, 0);
         this->btnReturn->Name = L"btnReturn";
         this->btnReturn->Size = System::Drawing::Size(100, 60);
         this->btnReturn->TabIndex = 2;
         this->btnReturn->Text = L"RETURN";
         this->btnReturn->UseVisualStyleBackColor = false;
         this->btnReturn->Visible = false;
         this->btnReturn->Click += gcnew System::EventHandler(this, &ServerClose::btnReturn_Click);
         // 
         // btnClose
         // 
         this->btnClose->BackColor = System::Drawing::Color::MediumSeaGreen;
         this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnClose->Enabled = false;
         this->btnClose->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnClose->FlatAppearance->BorderSize = 5;
         this->btnClose->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnClose->Location = System::Drawing::Point(570, 113);
         this->btnClose->Name = L"btnClose";
         this->btnClose->Size = System::Drawing::Size(150, 60);
         this->btnClose->TabIndex = 12;
         this->btnClose->Text = L"CLOSE";
         this->btnClose->UseVisualStyleBackColor = false;
         this->btnClose->Visible = false;
         this->btnClose->Click += gcnew System::EventHandler(this, &ServerClose::btnClose_Click);
         // 
         // btnPromo
         // 
         this->btnPromo->BackColor = System::Drawing::SystemColors::ButtonFace;
         this->btnPromo->Enabled = false;
         this->btnPromo->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnPromo->Location = System::Drawing::Point(847, 0);
         this->btnPromo->Name = L"btnPromo";
         this->btnPromo->Size = System::Drawing::Size(100, 60);
         this->btnPromo->TabIndex = 13;
         this->btnPromo->Text = L"PROMO";
         this->btnPromo->UseVisualStyleBackColor = false;
         this->btnPromo->Visible = false;
         this->btnPromo->Click += gcnew System::EventHandler(this, &ServerClose::btnPromo_Click);
         // 
         // btnPayment
         // 
         this->btnPayment->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnPayment->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnPayment->Location = System::Drawing::Point(734, 0);
         this->btnPayment->Name = L"btnPayment";
         this->btnPayment->Size = System::Drawing::Size(112, 60);
         this->btnPayment->TabIndex = 14;
         this->btnPayment->Text = L"PAYMENT";
         this->btnPayment->UseVisualStyleBackColor = false;
         this->btnPayment->Visible = false;
         this->btnPayment->Click += gcnew System::EventHandler(this, &ServerClose::btnPayment_Click);
         // 
         // btnPrint
         // 
         this->btnPrint->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnPrint->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnPrint->Location = System::Drawing::Point(13, 618);
         this->btnPrint->Name = L"btnPrint";
         this->btnPrint->Size = System::Drawing::Size(100, 60);
         this->btnPrint->TabIndex = 26;
         this->btnPrint->Text = L"PRINT";
         this->btnPrint->UseVisualStyleBackColor = false;
         this->btnPrint->Click += gcnew System::EventHandler(this, &ServerClose::btnPrint_Click);
         // 
         // lblTax
         // 
         this->lblTax->AutoSize = true;
         this->lblTax->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblTax->Location = System::Drawing::Point(184, 445);
         this->lblTax->Name = L"lblTax";
         this->lblTax->Size = System::Drawing::Size(55, 23);
         this->lblTax->TabIndex = 37;
         this->lblTax->Text = L"$0.00";
         // 
         // lblTotal
         // 
         this->lblTotal->AutoSize = true;
         this->lblTotal->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblTotal->Location = System::Drawing::Point(184, 474);
         this->lblTotal->Name = L"lblTotal";
         this->lblTotal->Size = System::Drawing::Size(67, 29);
         this->lblTotal->TabIndex = 36;
         this->lblTotal->Text = L"$0.00";
         // 
         // lblSubTot
         // 
         this->lblSubTot->AutoSize = true;
         this->lblSubTot->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblSubTot->Location = System::Drawing::Point(184, 412);
         this->lblSubTot->Name = L"lblSubTot";
         this->lblSubTot->Size = System::Drawing::Size(75, 23);
         this->lblSubTot->TabIndex = 35;
         this->lblSubTot->Text = L"$123.45";
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label3->Location = System::Drawing::Point(12, 445);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(44, 23);
         this->label3->TabIndex = 34;
         this->label3->Text = L"TAX:";
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label2->Location = System::Drawing::Point(12, 474);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(79, 29);
         this->label2->TabIndex = 33;
         this->label2->Text = L"TOTAL:";
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(12, 412);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(99, 23);
         this->label1->TabIndex = 32;
         this->label1->Text = L"SUB-TOTAL:";
         // 
         // label7
         // 
         this->label7->AutoSize = true;
         this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label7->ForeColor = System::Drawing::Color::Green;
         this->label7->Location = System::Drawing::Point(136, 564);
         this->label7->Name = L"label7";
         this->label7->Size = System::Drawing::Size(104, 29);
         this->label7->TabIndex = 38;
         this->label7->Text = L"CHANGE:";
         // 
         // lblChange
         // 
         this->lblChange->AutoSize = true;
         this->lblChange->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblChange->ForeColor = System::Drawing::Color::Green;
         this->lblChange->Location = System::Drawing::Point(308, 564);
         this->lblChange->Name = L"lblChange";
         this->lblChange->Size = System::Drawing::Size(67, 29);
         this->lblChange->TabIndex = 39;
         this->lblChange->Text = L"$0.00";
         // 
         // lblBalance
         // 
         this->lblBalance->AutoSize = true;
         this->lblBalance->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblBalance->ForeColor = System::Drawing::Color::Red;
         this->lblBalance->Location = System::Drawing::Point(308, 535);
         this->lblBalance->Name = L"lblBalance";
         this->lblBalance->Size = System::Drawing::Size(67, 29);
         this->lblBalance->TabIndex = 41;
         this->lblBalance->Text = L"$0.00";
         this->lblBalance->TextChanged += gcnew System::EventHandler(this, &ServerClose::lblBalance_TextChanged);
         // 
         // label5
         // 
         this->label5->AutoSize = true;
         this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label5->ForeColor = System::Drawing::Color::Red;
         this->label5->Location = System::Drawing::Point(136, 535);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(158, 29);
         this->label5->TabIndex = 40;
         this->label5->Text = L"BALANCE DUE:";
         // 
         // lblCash
         // 
         this->lblCash->AutoSize = true;
         this->lblCash->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblCash->Location = System::Drawing::Point(490, 412);
         this->lblCash->Name = L"lblCash";
         this->lblCash->Size = System::Drawing::Size(55, 23);
         this->lblCash->TabIndex = 43;
         this->lblCash->Text = L"$0.00";
         // 
         // label6
         // 
         this->label6->AutoSize = true;
         this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label6->Location = System::Drawing::Point(318, 412);
         this->label6->Name = L"label6";
         this->label6->Size = System::Drawing::Size(57, 23);
         this->label6->TabIndex = 42;
         this->label6->Text = L"CASH:";
         // 
         // label8
         // 
         this->label8->AutoSize = true;
         this->label8->Enabled = false;
         this->label8->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label8->Location = System::Drawing::Point(490, 445);
         this->label8->Name = L"label8";
         this->label8->Size = System::Drawing::Size(55, 23);
         this->label8->TabIndex = 45;
         this->label8->Text = L"$0.00";
         // 
         // label9
         // 
         this->label9->AutoSize = true;
         this->label9->Enabled = false;
         this->label9->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label9->Location = System::Drawing::Point(318, 445);
         this->label9->Name = L"label9";
         this->label9->Size = System::Drawing::Size(132, 23);
         this->label9->TabIndex = 44;
         this->label9->Text = L"COMP/PROMO:";
         // 
         // label10
         // 
         this->label10->AutoSize = true;
         this->label10->Enabled = false;
         this->label10->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label10->Location = System::Drawing::Point(490, 479);
         this->label10->Name = L"label10";
         this->label10->Size = System::Drawing::Size(55, 23);
         this->label10->TabIndex = 47;
         this->label10->Text = L"$0.00";
         // 
         // label11
         // 
         this->label11->AutoSize = true;
         this->label11->Enabled = false;
         this->label11->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label11->Location = System::Drawing::Point(318, 479);
         this->label11->Name = L"label11";
         this->label11->Size = System::Drawing::Size(116, 23);
         this->label11->TabIndex = 46;
         this->label11->Text = L"CHECK/CARD:";
         // 
         // btnResetPay
         // 
         this->btnResetPay->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnResetPay->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnResetPay->Location = System::Drawing::Point(119, 618);
         this->btnResetPay->Name = L"btnResetPay";
         this->btnResetPay->Size = System::Drawing::Size(100, 60);
         this->btnResetPay->TabIndex = 48;
         this->btnResetPay->Text = L"RESET";
         this->btnResetPay->UseVisualStyleBackColor = false;
         this->btnResetPay->Click += gcnew System::EventHandler(this, &ServerClose::btnResetPay_Click);
         // 
         // groupCash
         // 
         this->groupCash->BackColor = System::Drawing::Color::Transparent;
         this->groupCash->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->groupCash->Controls->Add(this->btnCash100);
         this->groupCash->Controls->Add(this->btnCash50);
         this->groupCash->Controls->Add(this->btnCash20);
         this->groupCash->Controls->Add(this->btnCash10);
         this->groupCash->Controls->Add(this->btnCash5);
         this->groupCash->Controls->Add(this->btnCash1);
         this->groupCash->Controls->Add(this->btnDisc);
         this->groupCash->Controls->Add(this->btnMC);
         this->groupCash->Controls->Add(this->btnVisa);
         this->groupCash->Controls->Add(this->btnCheck);
         this->groupCash->Controls->Add(this->btnCash);
         this->groupCash->ForeColor = System::Drawing::Color::Black;
         this->groupCash->Location = System::Drawing::Point(734, 113);
         this->groupCash->Name = L"groupCash";
         this->groupCash->Size = System::Drawing::Size(448, 332);
         this->groupCash->TabIndex = 22;
         this->groupCash->TabStop = false;
         // 
         // btnCash100
         // 
         this->btnCash100->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCash100->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCash100->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCash100->FlatAppearance->BorderSize = 5;
         this->btnCash100->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCash100->Location = System::Drawing::Point(296, 136);
         this->btnCash100->Name = L"btnCash100";
         this->btnCash100->Size = System::Drawing::Size(140, 60);
         this->btnCash100->TabIndex = 21;
         this->btnCash100->Text = L"$100";
         this->btnCash100->UseVisualStyleBackColor = false;
         this->btnCash100->Click += gcnew System::EventHandler(this, &ServerClose::cashNumberButtonClick);
         // 
         // btnCash50
         // 
         this->btnCash50->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCash50->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCash50->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCash50->FlatAppearance->BorderSize = 5;
         this->btnCash50->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCash50->Location = System::Drawing::Point(150, 136);
         this->btnCash50->Name = L"btnCash50";
         this->btnCash50->Size = System::Drawing::Size(140, 60);
         this->btnCash50->TabIndex = 20;
         this->btnCash50->Text = L"$50";
         this->btnCash50->UseVisualStyleBackColor = false;
         this->btnCash50->Click += gcnew System::EventHandler(this, &ServerClose::cashNumberButtonClick);
         // 
         // btnCash20
         // 
         this->btnCash20->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCash20->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCash20->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCash20->FlatAppearance->BorderSize = 5;
         this->btnCash20->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCash20->Location = System::Drawing::Point(4, 136);
         this->btnCash20->Name = L"btnCash20";
         this->btnCash20->Size = System::Drawing::Size(140, 60);
         this->btnCash20->TabIndex = 19;
         this->btnCash20->Text = L"$20";
         this->btnCash20->UseVisualStyleBackColor = false;
         this->btnCash20->Click += gcnew System::EventHandler(this, &ServerClose::cashNumberButtonClick);
         // 
         // btnCash10
         // 
         this->btnCash10->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCash10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCash10->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCash10->FlatAppearance->BorderSize = 5;
         this->btnCash10->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCash10->Location = System::Drawing::Point(296, 70);
         this->btnCash10->Name = L"btnCash10";
         this->btnCash10->Size = System::Drawing::Size(140, 60);
         this->btnCash10->TabIndex = 18;
         this->btnCash10->Text = L"$10";
         this->btnCash10->UseVisualStyleBackColor = false;
         this->btnCash10->Click += gcnew System::EventHandler(this, &ServerClose::cashNumberButtonClick);
         // 
         // btnCash5
         // 
         this->btnCash5->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCash5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCash5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCash5->FlatAppearance->BorderSize = 5;
         this->btnCash5->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCash5->Location = System::Drawing::Point(150, 70);
         this->btnCash5->Name = L"btnCash5";
         this->btnCash5->Size = System::Drawing::Size(140, 60);
         this->btnCash5->TabIndex = 17;
         this->btnCash5->Text = L"$5";
         this->btnCash5->UseVisualStyleBackColor = false;
         this->btnCash5->Click += gcnew System::EventHandler(this, &ServerClose::cashNumberButtonClick);
         // 
         // btnCash1
         // 
         this->btnCash1->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCash1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCash1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCash1->FlatAppearance->BorderSize = 5;
         this->btnCash1->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCash1->Location = System::Drawing::Point(4, 70);
         this->btnCash1->Name = L"btnCash1";
         this->btnCash1->Size = System::Drawing::Size(140, 60);
         this->btnCash1->TabIndex = 16;
         this->btnCash1->Text = L"$1";
         this->btnCash1->UseVisualStyleBackColor = false;
         this->btnCash1->Click += gcnew System::EventHandler(this, &ServerClose::cashNumberButtonClick);
         // 
         // btnDisc
         // 
         this->btnDisc->BackColor = System::Drawing::SystemColors::ButtonFace;
         this->btnDisc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnDisc->Enabled = false;
         this->btnDisc->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnDisc->FlatAppearance->BorderSize = 5;
         this->btnDisc->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnDisc->Location = System::Drawing::Point(296, 268);
         this->btnDisc->Name = L"btnDisc";
         this->btnDisc->Size = System::Drawing::Size(140, 60);
         this->btnDisc->TabIndex = 11;
         this->btnDisc->Text = L"DISCOVER";
         this->btnDisc->UseVisualStyleBackColor = false;
         // 
         // btnMC
         // 
         this->btnMC->BackColor = System::Drawing::SystemColors::ButtonFace;
         this->btnMC->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnMC->Enabled = false;
         this->btnMC->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnMC->FlatAppearance->BorderSize = 5;
         this->btnMC->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnMC->Location = System::Drawing::Point(150, 268);
         this->btnMC->Name = L"btnMC";
         this->btnMC->Size = System::Drawing::Size(140, 60);
         this->btnMC->TabIndex = 10;
         this->btnMC->Text = L"M/C";
         this->btnMC->UseVisualStyleBackColor = false;
         // 
         // btnVisa
         // 
         this->btnVisa->BackColor = System::Drawing::SystemColors::ButtonFace;
         this->btnVisa->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnVisa->Enabled = false;
         this->btnVisa->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnVisa->FlatAppearance->BorderSize = 5;
         this->btnVisa->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnVisa->Location = System::Drawing::Point(4, 268);
         this->btnVisa->Name = L"btnVisa";
         this->btnVisa->Size = System::Drawing::Size(140, 60);
         this->btnVisa->TabIndex = 9;
         this->btnVisa->Text = L"VISA";
         this->btnVisa->UseVisualStyleBackColor = false;
         // 
         // btnCheck
         // 
         this->btnCheck->BackColor = System::Drawing::SystemColors::ButtonFace;
         this->btnCheck->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCheck->Enabled = false;
         this->btnCheck->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCheck->FlatAppearance->BorderSize = 5;
         this->btnCheck->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCheck->Location = System::Drawing::Point(150, 4);
         this->btnCheck->Name = L"btnCheck";
         this->btnCheck->Size = System::Drawing::Size(140, 60);
         this->btnCheck->TabIndex = 8;
         this->btnCheck->Text = L"CHECK";
         this->btnCheck->UseVisualStyleBackColor = false;
         // 
         // btnCash
         // 
         this->btnCash->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCash->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCash->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCash->FlatAppearance->BorderSize = 5;
         this->btnCash->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCash->Location = System::Drawing::Point(4, 4);
         this->btnCash->Name = L"btnCash";
         this->btnCash->Size = System::Drawing::Size(140, 60);
         this->btnCash->TabIndex = 7;
         this->btnCash->Text = L"CASH";
         this->btnCash->UseVisualStyleBackColor = false;
         this->btnCash->Click += gcnew System::EventHandler(this, &ServerClose::btnCash_Click);
         // 
         // orderTree
         // 
         this->orderTree->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->orderTree->FullRowSelect = true;
         this->orderTree->ItemHeight = 22;
         this->orderTree->Location = System::Drawing::Point(13, 66);
         this->orderTree->Name = L"orderTree";
         this->orderTree->ShowPlusMinus = false;
         this->orderTree->ShowRootLines = false;
         this->orderTree->Size = System::Drawing::Size(515, 321);
         this->orderTree->TabIndex = 77;
         // 
         // ServerClose
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(1264, 681);
         this->ControlBox = false;
         this->Controls->Add(this->orderTree);
         this->Controls->Add(this->btnResetPay);
         this->Controls->Add(this->label10);
         this->Controls->Add(this->label11);
         this->Controls->Add(this->groupCash);
         this->Controls->Add(this->label8);
         this->Controls->Add(this->label9);
         this->Controls->Add(this->lblCash);
         this->Controls->Add(this->label6);
         this->Controls->Add(this->lblBalance);
         this->Controls->Add(this->label5);
         this->Controls->Add(this->lblChange);
         this->Controls->Add(this->label7);
         this->Controls->Add(this->lblTax);
         this->Controls->Add(this->lblTotal);
         this->Controls->Add(this->lblSubTot);
         this->Controls->Add(this->label3);
         this->Controls->Add(this->label2);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->btnPrint);
         this->Controls->Add(this->btnPayment);
         this->Controls->Add(this->btnPromo);
         this->Controls->Add(this->btnClose);
         this->Controls->Add(this->btnReturn);
         this->Controls->Add(this->btnDone);
         this->MaximizeBox = false;
         this->MinimizeBox = false;
         this->Name = L"ServerClose";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"ServerClose";
         this->Load += gcnew System::EventHandler(this, &ServerClose::ServerClose_Load);
         this->groupCash->ResumeLayout(false);
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void btnReturn_Click(System::Object^  sender, System::EventArgs^  e) {
      form->Show();
      this->Close();
   }
private: System::Void btnDone_Click(System::Object^  sender, System::EventArgs^  e) {
   login->Show();
   this->form->Close();
   this->Close();
}
private: System::Void btnPayment_Click(System::Object^  sender, System::EventArgs^  e) {
   groupCash->Show();
}
private: System::Void btnPromo_Click(System::Object^  sender, System::EventArgs^  e) {
   groupCash->Hide();
}
private: System::Void btnCash_Click(System::Object^  sender, System::EventArgs^  e) {
   CloseCash ^ cashIn = gcnew CloseCash(this, lblBalance->Text);
   cashIn->ShowDialog();
   addCash(cashIn->getPayment());
   subBalance(cashIn->getPayment());
}

private: System::String ^ addTotal(String^ tax, String^ subtotal) {
   tax = tax->Remove(0, 1);
   subtotal = subtotal->Remove(0, 1);
   return String::Format("{0:C2}", (System::Convert::ToDouble(tax) + System::Convert::ToDouble(subtotal)));
}

private: System::String ^ calcTax(String^ subtotal) {
   subtotal = subtotal->Remove(0, 1);
   return String::Format("{0:C2}", (System::Convert::ToDouble(subtotal) * 0.05));
}

private: System::Void subBalance(String^ amount) {
   double amountD = System::Convert::ToDouble(amount->Remove(0, 1));
   double balance = System::Convert::ToDouble(lblBalance->Text->Remove(0, 1));
   double change = System::Convert::ToDouble(lblChange->Text->Remove(0, 1));

   double calculation = balance - amountD;

   if (calculation < 0) {
      lblBalance->Text = "$0.00";
      lblChange->Text = String::Format("{0:C2}", change + (calculation * -1));
   }
   else
      lblBalance->Text = String::Format("{0:C2}", calculation);
}

public: System::Void addCash(String^ amount) {
   amount = amount->Remove(0, 1);
   String^ cash = lblCash->Text->Remove(0, 1);
   lblCash->Text = String::Format("{0:C2}", (System::Convert::ToDouble(amount) + System::Convert::ToDouble(cash)));
}

private: System::Void ServerClose_Load(System::Object^  sender, System::EventArgs^  e) {
   lblSubTot->Text = String::Format("{0:C2}", mySubTotal);
   lblTax->Text = calcTax(lblSubTot->Text);
   lblTotal->Text = addTotal(lblTax->Text, lblSubTot->Text);
   lblBalance->Text = lblTotal->Text;

   PopulateTree();
}

private: System::Void cashNumberButtonClick(System::Object^ sender, System::EventArgs^ e) {
   System::Windows::Forms::Button^ buttonPressed = (System::Windows::Forms::Button^)sender;
   addCash(buttonPressed->Text);
   subBalance(buttonPressed->Text);
}

private: System::Void lblBalance_TextChanged(System::Object^  sender, System::EventArgs^  e) {
   double amount = System::Convert::ToDouble(lblBalance->Text->Remove(0, 1));
   if (amount <= 0) {
      btnClose->Visible = true;
      btnClose->Enabled = true;
   }
   else {
      btnClose->Visible = false;
      btnClose->Enabled = false;
   }
   
}

private: System::Void btnResetPay_Click(System::Object^  sender, System::EventArgs^  e) {
   lblCash->Text = "$0.00";
   lblBalance->Text = lblTotal->Text;
   lblChange->Text = "$0.00";
}

private: double toDouble(String ^ stringNum) {
   stringNum = stringNum->Remove(0, 1);
   return System::Convert::ToDouble(stringNum);
}

private: System::Void btnPrint_Click(System::Object^  sender, System::EventArgs^  e) {
   Receipt * receipt = new Receipt();
   string tempOrder = receipt->FormatReceipt(myOrder);
   Printer * printer = new Printer();
   printer->CatalogDigitallyReceipt(tempOrder, myOrder->GetID());
}
private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
   CloseSplash^ close = gcnew CloseSplash(lblChange->Text);
   Restaurant::GetRestaurant()->getTableController()->TableWithOrderID(myOrder->GetID())->UpdateOrderID(-1);
   close->Show();
   form->Invalidate();
   form->Activate();
   close->Focus();
   form->Show();
   this->Close();
}
private: double GetSubTotal(Order* order)
{
   vector<OrderItem*> items = *order->Items();
   double total = 0;
   for (int i = 0; i < items.size(); i++)
   {
      total += items.at(i)->GetPrice();
   }
   return total;
}
         private: ref class OrderItemWrapper
         {
         public: OrderItemWrapper(SharedCode::OrderItem * orderItem) : orderItem(orderItem) {};

         public: SharedCode::OrderItem * orderItem;
         };

                  private: void PopulateTree() {
                     orderTree->BeginUpdate();

                     orderTree->Nodes->Clear();
                     const vector <OrderItem*> * items = myOrder->Items();

                     if (items != nullptr) {
                        for (std::vector<OrderItem*>::const_iterator it = items->begin(); it != items->end(); it++) {

                           TreeNode^ item = gcnew TreeNode(gcnew String((*it)->GetRecipe()->Name()->c_str()));
                           OrderItemWrapper^ orderItemWrapper = gcnew OrderItemWrapper(*it);
                           item->Tag = orderItemWrapper;
                           orderTree->Nodes->Add(item);

                           String^ priceS = gcnew String(String::Format("{0:C2}", (*it)->GetRecipe()->Price()));
                           TreeNode^ price = gcnew TreeNode(priceS);
                           item->Nodes->Add(price);
                        }
                     }

                     orderTree->ExpandAll();

                     orderTree->EndUpdate();
                  }
};
}
