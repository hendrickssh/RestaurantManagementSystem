//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: GUI for taking orders. Can add/remove items from the order.
//---------------------------------------------------------------------

#pragma once
#include "ServerClose.h"
#include "Restaurant.h"
#include "RestaurantMenu.h"
#include <Order.h>
#include <OrderItem.h>
#include <AddOrderItem.h>
#include <RemoveOrderItem.h>

namespace RestaurantManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SharedCode;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class ServerMain : public System::Windows::Forms::Form
	{

	public:
		ServerMain(void)
		{
			ServerMain(nullptr, nullptr, nullptr);
		}
		Form ^ form; //Previous screen
		Form ^ login; //Login screen for Done button
		const int NUM_CATEGORY_BUTTONS = 7;
		const int NUM_RECIPE_BUTTONS = 20;
		int catCounter;
		int recCounter;
		long orderCounter;
   private: System::Windows::Forms::Button^  btnUndo;
   private: System::Windows::Forms::Button^  button1;
   public:
   public:
		Order * myOrder;
		ServerMain(Form ^ form, Form ^ login, Order * order)
		{
			InitializeComponent();
			this->form = form;
			this->login = login;
			this->myOrder = order;
			this->orderCounter = 1;

			//
			//TODO: Add the constructor code here
			//
		}

	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::Button^  btnClear;

	private: System::Windows::Forms::TreeView^  orderTree;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  orderIDLabel;
	private: System::Windows::Forms::Button^  btnNextPage;
	private: System::Windows::Forms::Button^  btnRec19;
	private: System::Windows::Forms::Button^  btnRec20;
	private: System::Windows::Forms::Button^  btnRec18;
	private: System::Windows::Forms::Button^  btnRec16;
	private: System::Windows::Forms::Button^  btnRec17;
	private: System::Windows::Forms::Button^  btnRec15;
	private: System::Windows::Forms::Button^  btnRec13;
	private: System::Windows::Forms::Button^  btnRec14;
	private: System::Windows::Forms::Button^  btnRec12;
	private: System::Windows::Forms::Button^  btnRec10;
	private: System::Windows::Forms::Button^  btnRec11;
	private: System::Windows::Forms::Button^  btnRec9;
	private: System::Windows::Forms::Button^  btnRec7;
	private: System::Windows::Forms::Button^  btnRec8;
	private: System::Windows::Forms::Button^  btnRec6;
	private: System::Windows::Forms::Button^  btnRec4;
	private: System::Windows::Forms::Button^  btnRec5;
	private: System::Windows::Forms::Button^  btnRec3;
	private: System::Windows::Forms::Button^  btnRec1;
	private: System::Windows::Forms::Button^  btnRec2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServerMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnDone;
	private: System::Windows::Forms::Button^  btnTabs;

	private: System::Windows::Forms::Button^  btnClose;
	private: System::Windows::Forms::Button^  btnFastCash;

	private: System::Windows::Forms::Button^  btnMenuUp;
	private: System::Windows::Forms::Button^  btnMenuDown;

	private: System::Windows::Forms::Button^  btnCat1;
	private: System::Windows::Forms::Button^  btnCat2;
	private: System::Windows::Forms::Button^  btnCat3;
	private: System::Windows::Forms::Button^  btnCat4;
	private: System::Windows::Forms::Button^  btnCat5;
	private: System::Windows::Forms::Button^  btnCat6;
	private: System::Windows::Forms::Button^  btnCat7;
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
         System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ServerMain::typeid));
         this->btnDone = (gcnew System::Windows::Forms::Button());
         this->btnTabs = (gcnew System::Windows::Forms::Button());
         this->btnClose = (gcnew System::Windows::Forms::Button());
         this->btnFastCash = (gcnew System::Windows::Forms::Button());
         this->btnMenuUp = (gcnew System::Windows::Forms::Button());
         this->btnMenuDown = (gcnew System::Windows::Forms::Button());
         this->btnCat1 = (gcnew System::Windows::Forms::Button());
         this->btnCat2 = (gcnew System::Windows::Forms::Button());
         this->btnCat3 = (gcnew System::Windows::Forms::Button());
         this->btnCat4 = (gcnew System::Windows::Forms::Button());
         this->btnCat5 = (gcnew System::Windows::Forms::Button());
         this->btnCat6 = (gcnew System::Windows::Forms::Button());
         this->btnCat7 = (gcnew System::Windows::Forms::Button());
         this->btnDelete = (gcnew System::Windows::Forms::Button());
         this->btnClear = (gcnew System::Windows::Forms::Button());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->label6 = (gcnew System::Windows::Forms::Label());
         this->btnNextPage = (gcnew System::Windows::Forms::Button());
         this->btnRec19 = (gcnew System::Windows::Forms::Button());
         this->btnRec20 = (gcnew System::Windows::Forms::Button());
         this->btnRec18 = (gcnew System::Windows::Forms::Button());
         this->btnRec16 = (gcnew System::Windows::Forms::Button());
         this->btnRec17 = (gcnew System::Windows::Forms::Button());
         this->btnRec15 = (gcnew System::Windows::Forms::Button());
         this->btnRec13 = (gcnew System::Windows::Forms::Button());
         this->btnRec14 = (gcnew System::Windows::Forms::Button());
         this->btnRec12 = (gcnew System::Windows::Forms::Button());
         this->btnRec10 = (gcnew System::Windows::Forms::Button());
         this->btnRec11 = (gcnew System::Windows::Forms::Button());
         this->btnRec9 = (gcnew System::Windows::Forms::Button());
         this->btnRec7 = (gcnew System::Windows::Forms::Button());
         this->btnRec8 = (gcnew System::Windows::Forms::Button());
         this->btnRec6 = (gcnew System::Windows::Forms::Button());
         this->btnRec4 = (gcnew System::Windows::Forms::Button());
         this->btnRec5 = (gcnew System::Windows::Forms::Button());
         this->btnRec3 = (gcnew System::Windows::Forms::Button());
         this->btnRec1 = (gcnew System::Windows::Forms::Button());
         this->btnRec2 = (gcnew System::Windows::Forms::Button());
         this->label7 = (gcnew System::Windows::Forms::Label());
         this->orderIDLabel = (gcnew System::Windows::Forms::Label());
         this->orderTree = (gcnew System::Windows::Forms::TreeView());
         this->btnUndo = (gcnew System::Windows::Forms::Button());
         this->button1 = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();
         // 
         // btnDone
         // 
         this->btnDone->BackColor = System::Drawing::Color::IndianRed;
         this->btnDone->Font = (gcnew System::Drawing::Font(L"Calibri", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnDone->ForeColor = System::Drawing::Color::White;
         this->btnDone->Location = System::Drawing::Point(575, 0);
         this->btnDone->Name = L"btnDone";
         this->btnDone->Size = System::Drawing::Size(140, 70);
         this->btnDone->TabIndex = 0;
         this->btnDone->Text = L"DONE";
         this->btnDone->UseVisualStyleBackColor = false;
         this->btnDone->Click += gcnew System::EventHandler(this, &ServerMain::btnDone_Click);
         // 
         // btnTabs
         // 
         this->btnTabs->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnTabs->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnTabs->Location = System::Drawing::Point(12, 0);
         this->btnTabs->Name = L"btnTabs";
         this->btnTabs->Size = System::Drawing::Size(100, 60);
         this->btnTabs->TabIndex = 1;
         this->btnTabs->Text = L"TABLES";
         this->btnTabs->UseVisualStyleBackColor = false;
         this->btnTabs->Visible = false;
         this->btnTabs->Click += gcnew System::EventHandler(this, &ServerMain::btnTabs_Click);
         // 
         // btnClose
         // 
         this->btnClose->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnClose->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnClose->Location = System::Drawing::Point(1115, 0);
         this->btnClose->Name = L"btnClose";
         this->btnClose->Size = System::Drawing::Size(140, 60);
         this->btnClose->TabIndex = 3;
         this->btnClose->Text = L"CLOSE";
         this->btnClose->UseVisualStyleBackColor = false;
         this->btnClose->Visible = false;
         this->btnClose->Click += gcnew System::EventHandler(this, &ServerMain::btnClose_Click);
         // 
         // btnFastCash
         // 
         this->btnFastCash->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnFastCash->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnFastCash->Location = System::Drawing::Point(969, 0);
         this->btnFastCash->Name = L"btnFastCash";
         this->btnFastCash->Size = System::Drawing::Size(140, 60);
         this->btnFastCash->TabIndex = 4;
         this->btnFastCash->Text = L"FAST CASH";
         this->btnFastCash->UseVisualStyleBackColor = false;
         this->btnFastCash->Visible = false;
         // 
         // btnMenuUp
         // 
         this->btnMenuUp->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnMenuUp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMenuUp.BackgroundImage")));
         this->btnMenuUp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
         this->btnMenuUp->Enabled = false;
         this->btnMenuUp->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnMenuUp->FlatAppearance->BorderSize = 5;
         this->btnMenuUp->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnMenuUp->Location = System::Drawing::Point(575, 80);
         this->btnMenuUp->Name = L"btnMenuUp";
         this->btnMenuUp->Size = System::Drawing::Size(140, 60);
         this->btnMenuUp->TabIndex = 6;
         this->btnMenuUp->UseVisualStyleBackColor = false;
         this->btnMenuUp->Click += gcnew System::EventHandler(this, &ServerMain::btnMenuUp_Click);
         // 
         // btnMenuDown
         // 
         this->btnMenuDown->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnMenuDown->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMenuDown.BackgroundImage")));
         this->btnMenuDown->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
         this->btnMenuDown->Enabled = false;
         this->btnMenuDown->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnMenuDown->FlatAppearance->BorderSize = 5;
         this->btnMenuDown->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnMenuDown->Location = System::Drawing::Point(575, 608);
         this->btnMenuDown->Name = L"btnMenuDown";
         this->btnMenuDown->Size = System::Drawing::Size(140, 60);
         this->btnMenuDown->TabIndex = 7;
         this->btnMenuDown->UseVisualStyleBackColor = false;
         this->btnMenuDown->Click += gcnew System::EventHandler(this, &ServerMain::btnMenuDown_Click);
         // 
         // btnCat1
         // 
         this->btnCat1->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCat1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCat1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCat1->FlatAppearance->BorderSize = 5;
         this->btnCat1->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCat1->Location = System::Drawing::Point(575, 146);
         this->btnCat1->Name = L"btnCat1";
         this->btnCat1->Size = System::Drawing::Size(140, 60);
         this->btnCat1->TabIndex = 8;
         this->btnCat1->Text = L"$TEMP$";
         this->btnCat1->UseVisualStyleBackColor = false;
         this->btnCat1->Visible = false;
         this->btnCat1->Click += gcnew System::EventHandler(this, &ServerMain::catButtonClick);
         // 
         // btnCat2
         // 
         this->btnCat2->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCat2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCat2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCat2->FlatAppearance->BorderSize = 5;
         this->btnCat2->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCat2->Location = System::Drawing::Point(575, 212);
         this->btnCat2->Name = L"btnCat2";
         this->btnCat2->Size = System::Drawing::Size(140, 60);
         this->btnCat2->TabIndex = 9;
         this->btnCat2->Text = L"$TEMP$";
         this->btnCat2->UseVisualStyleBackColor = false;
         this->btnCat2->Visible = false;
         this->btnCat2->Click += gcnew System::EventHandler(this, &ServerMain::catButtonClick);
         // 
         // btnCat3
         // 
         this->btnCat3->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCat3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCat3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCat3->FlatAppearance->BorderSize = 5;
         this->btnCat3->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCat3->Location = System::Drawing::Point(575, 278);
         this->btnCat3->Name = L"btnCat3";
         this->btnCat3->Size = System::Drawing::Size(140, 60);
         this->btnCat3->TabIndex = 10;
         this->btnCat3->Text = L"$TEMP$";
         this->btnCat3->UseVisualStyleBackColor = false;
         this->btnCat3->Visible = false;
         this->btnCat3->Click += gcnew System::EventHandler(this, &ServerMain::catButtonClick);
         // 
         // btnCat4
         // 
         this->btnCat4->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCat4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCat4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCat4->FlatAppearance->BorderSize = 5;
         this->btnCat4->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCat4->Location = System::Drawing::Point(575, 344);
         this->btnCat4->Name = L"btnCat4";
         this->btnCat4->Size = System::Drawing::Size(140, 60);
         this->btnCat4->TabIndex = 11;
         this->btnCat4->Text = L"$TEMP$";
         this->btnCat4->UseVisualStyleBackColor = false;
         this->btnCat4->Visible = false;
         this->btnCat4->Click += gcnew System::EventHandler(this, &ServerMain::catButtonClick);
         // 
         // btnCat5
         // 
         this->btnCat5->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCat5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCat5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCat5->FlatAppearance->BorderSize = 5;
         this->btnCat5->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCat5->Location = System::Drawing::Point(575, 410);
         this->btnCat5->Name = L"btnCat5";
         this->btnCat5->Size = System::Drawing::Size(140, 60);
         this->btnCat5->TabIndex = 12;
         this->btnCat5->Text = L"$TEMP$";
         this->btnCat5->UseVisualStyleBackColor = false;
         this->btnCat5->Visible = false;
         this->btnCat5->Click += gcnew System::EventHandler(this, &ServerMain::catButtonClick);
         // 
         // btnCat6
         // 
         this->btnCat6->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCat6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCat6->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCat6->FlatAppearance->BorderSize = 5;
         this->btnCat6->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCat6->Location = System::Drawing::Point(575, 476);
         this->btnCat6->Name = L"btnCat6";
         this->btnCat6->Size = System::Drawing::Size(140, 60);
         this->btnCat6->TabIndex = 13;
         this->btnCat6->Text = L"$TEMP$";
         this->btnCat6->UseVisualStyleBackColor = false;
         this->btnCat6->Visible = false;
         this->btnCat6->Click += gcnew System::EventHandler(this, &ServerMain::catButtonClick);
         // 
         // btnCat7
         // 
         this->btnCat7->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnCat7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
         this->btnCat7->FlatAppearance->BorderColor = System::Drawing::Color::Black;
         this->btnCat7->FlatAppearance->BorderSize = 5;
         this->btnCat7->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnCat7->Location = System::Drawing::Point(575, 542);
         this->btnCat7->Name = L"btnCat7";
         this->btnCat7->Size = System::Drawing::Size(140, 60);
         this->btnCat7->TabIndex = 14;
         this->btnCat7->Text = L"$TEMP$";
         this->btnCat7->UseVisualStyleBackColor = false;
         this->btnCat7->Visible = false;
         this->btnCat7->Click += gcnew System::EventHandler(this, &ServerMain::catButtonClick);
         // 
         // btnDelete
         // 
         this->btnDelete->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnDelete->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnDelete->Location = System::Drawing::Point(12, 609);
         this->btnDelete->Name = L"btnDelete";
         this->btnDelete->Size = System::Drawing::Size(100, 60);
         this->btnDelete->TabIndex = 16;
         this->btnDelete->Text = L"DELETE";
         this->btnDelete->UseVisualStyleBackColor = false;
         this->btnDelete->Click += gcnew System::EventHandler(this, &ServerMain::btnDelete_Click);
         // 
         // btnClear
         // 
         this->btnClear->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnClear->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnClear->Location = System::Drawing::Point(330, 608);
         this->btnClear->Name = L"btnClear";
         this->btnClear->Size = System::Drawing::Size(100, 60);
         this->btnClear->TabIndex = 17;
         this->btnClear->Text = L"CLEAR";
         this->btnClear->UseVisualStyleBackColor = false;
         this->btnClear->Visible = false;
         this->btnClear->Click += gcnew System::EventHandler(this, &ServerMain::btnClear_Click);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(13, 414);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(99, 23);
         this->label1->TabIndex = 25;
         this->label1->Text = L"SUB-TOTAL:";
         this->label1->Visible = false;
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label2->Location = System::Drawing::Point(13, 476);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(79, 29);
         this->label2->TabIndex = 26;
         this->label2->Text = L"TOTAL:";
         this->label2->Visible = false;
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label3->Location = System::Drawing::Point(13, 447);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(44, 23);
         this->label3->TabIndex = 27;
         this->label3->Text = L"TAX:";
         this->label3->Visible = false;
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label4->Location = System::Drawing::Point(185, 414);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(55, 23);
         this->label4->TabIndex = 28;
         this->label4->Text = L"$0.00";
         this->label4->Visible = false;
         // 
         // label5
         // 
         this->label5->AutoSize = true;
         this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label5->Location = System::Drawing::Point(185, 476);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(67, 29);
         this->label5->TabIndex = 29;
         this->label5->Text = L"$0.00";
         this->label5->Visible = false;
         // 
         // label6
         // 
         this->label6->AutoSize = true;
         this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label6->Location = System::Drawing::Point(185, 447);
         this->label6->Name = L"label6";
         this->label6->Size = System::Drawing::Size(55, 23);
         this->label6->TabIndex = 30;
         this->label6->Text = L"$0.00";
         this->label6->Visible = false;
         // 
         // btnNextPage
         // 
         this->btnNextPage->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnNextPage->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnNextPage->Location = System::Drawing::Point(1116, 539);
         this->btnNextPage->Name = L"btnNextPage";
         this->btnNextPage->Size = System::Drawing::Size(140, 60);
         this->btnNextPage->TabIndex = 73;
         this->btnNextPage->Text = L"Next Page";
         this->btnNextPage->UseVisualStyleBackColor = false;
         this->btnNextPage->Visible = false;
         // 
         // btnRec19
         // 
         this->btnRec19->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec19->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec19->Location = System::Drawing::Point(824, 539);
         this->btnRec19->Name = L"btnRec19";
         this->btnRec19->Size = System::Drawing::Size(140, 60);
         this->btnRec19->TabIndex = 72;
         this->btnRec19->Text = L"$TEMP$";
         this->btnRec19->UseVisualStyleBackColor = false;
         this->btnRec19->Visible = false;
         this->btnRec19->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec20
         // 
         this->btnRec20->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec20->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec20->Location = System::Drawing::Point(970, 539);
         this->btnRec20->Name = L"btnRec20";
         this->btnRec20->Size = System::Drawing::Size(140, 60);
         this->btnRec20->TabIndex = 71;
         this->btnRec20->Text = L"$TEMP$";
         this->btnRec20->UseVisualStyleBackColor = false;
         this->btnRec20->Visible = false;
         this->btnRec20->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec18
         // 
         this->btnRec18->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec18->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec18->Location = System::Drawing::Point(1116, 473);
         this->btnRec18->Name = L"btnRec18";
         this->btnRec18->Size = System::Drawing::Size(140, 60);
         this->btnRec18->TabIndex = 70;
         this->btnRec18->Text = L"$TEMP$";
         this->btnRec18->UseVisualStyleBackColor = false;
         this->btnRec18->Visible = false;
         this->btnRec18->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec16
         // 
         this->btnRec16->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec16->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec16->Location = System::Drawing::Point(824, 473);
         this->btnRec16->Name = L"btnRec16";
         this->btnRec16->Size = System::Drawing::Size(140, 60);
         this->btnRec16->TabIndex = 69;
         this->btnRec16->Text = L"$TEMP$";
         this->btnRec16->UseVisualStyleBackColor = false;
         this->btnRec16->Visible = false;
         this->btnRec16->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec17
         // 
         this->btnRec17->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec17->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec17->Location = System::Drawing::Point(970, 473);
         this->btnRec17->Name = L"btnRec17";
         this->btnRec17->Size = System::Drawing::Size(140, 60);
         this->btnRec17->TabIndex = 68;
         this->btnRec17->Text = L"$TEMP$";
         this->btnRec17->UseVisualStyleBackColor = false;
         this->btnRec17->Visible = false;
         this->btnRec17->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec15
         // 
         this->btnRec15->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec15->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec15->Location = System::Drawing::Point(1116, 407);
         this->btnRec15->Name = L"btnRec15";
         this->btnRec15->Size = System::Drawing::Size(140, 60);
         this->btnRec15->TabIndex = 67;
         this->btnRec15->Text = L"$TEMP$";
         this->btnRec15->UseVisualStyleBackColor = false;
         this->btnRec15->Visible = false;
         this->btnRec15->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec13
         // 
         this->btnRec13->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec13->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec13->Location = System::Drawing::Point(824, 407);
         this->btnRec13->Name = L"btnRec13";
         this->btnRec13->Size = System::Drawing::Size(140, 60);
         this->btnRec13->TabIndex = 66;
         this->btnRec13->Text = L"$TEMP$";
         this->btnRec13->UseVisualStyleBackColor = false;
         this->btnRec13->Visible = false;
         this->btnRec13->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec14
         // 
         this->btnRec14->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec14->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec14->Location = System::Drawing::Point(970, 407);
         this->btnRec14->Name = L"btnRec14";
         this->btnRec14->Size = System::Drawing::Size(140, 60);
         this->btnRec14->TabIndex = 65;
         this->btnRec14->Text = L"$TEMP$";
         this->btnRec14->UseVisualStyleBackColor = false;
         this->btnRec14->Visible = false;
         this->btnRec14->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec12
         // 
         this->btnRec12->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec12->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec12->Location = System::Drawing::Point(1116, 341);
         this->btnRec12->Name = L"btnRec12";
         this->btnRec12->Size = System::Drawing::Size(140, 60);
         this->btnRec12->TabIndex = 64;
         this->btnRec12->Text = L"$TEMP$";
         this->btnRec12->UseVisualStyleBackColor = false;
         this->btnRec12->Visible = false;
         this->btnRec12->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec10
         // 
         this->btnRec10->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec10->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec10->Location = System::Drawing::Point(824, 341);
         this->btnRec10->Name = L"btnRec10";
         this->btnRec10->Size = System::Drawing::Size(140, 60);
         this->btnRec10->TabIndex = 63;
         this->btnRec10->Text = L"$TEMP$";
         this->btnRec10->UseVisualStyleBackColor = false;
         this->btnRec10->Visible = false;
         this->btnRec10->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec11
         // 
         this->btnRec11->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec11->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec11->Location = System::Drawing::Point(970, 341);
         this->btnRec11->Name = L"btnRec11";
         this->btnRec11->Size = System::Drawing::Size(140, 60);
         this->btnRec11->TabIndex = 62;
         this->btnRec11->Text = L"$TEMP$";
         this->btnRec11->UseVisualStyleBackColor = false;
         this->btnRec11->Visible = false;
         this->btnRec11->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec9
         // 
         this->btnRec9->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec9->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec9->Location = System::Drawing::Point(1115, 275);
         this->btnRec9->Name = L"btnRec9";
         this->btnRec9->Size = System::Drawing::Size(140, 60);
         this->btnRec9->TabIndex = 61;
         this->btnRec9->Text = L"$TEMP$";
         this->btnRec9->UseVisualStyleBackColor = false;
         this->btnRec9->Visible = false;
         this->btnRec9->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec7
         // 
         this->btnRec7->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec7->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec7->Location = System::Drawing::Point(823, 275);
         this->btnRec7->Name = L"btnRec7";
         this->btnRec7->Size = System::Drawing::Size(140, 60);
         this->btnRec7->TabIndex = 60;
         this->btnRec7->Text = L"$TEMP$";
         this->btnRec7->UseVisualStyleBackColor = false;
         this->btnRec7->Visible = false;
         this->btnRec7->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec8
         // 
         this->btnRec8->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec8->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec8->Location = System::Drawing::Point(969, 275);
         this->btnRec8->Name = L"btnRec8";
         this->btnRec8->Size = System::Drawing::Size(140, 60);
         this->btnRec8->TabIndex = 59;
         this->btnRec8->Text = L"$TEMP$";
         this->btnRec8->UseVisualStyleBackColor = false;
         this->btnRec8->Visible = false;
         this->btnRec8->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec6
         // 
         this->btnRec6->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec6->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec6->Location = System::Drawing::Point(1115, 212);
         this->btnRec6->Name = L"btnRec6";
         this->btnRec6->Size = System::Drawing::Size(140, 60);
         this->btnRec6->TabIndex = 58;
         this->btnRec6->Text = L"$TEMP$";
         this->btnRec6->UseVisualStyleBackColor = false;
         this->btnRec6->Visible = false;
         this->btnRec6->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec4
         // 
         this->btnRec4->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec4->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec4->Location = System::Drawing::Point(823, 212);
         this->btnRec4->Name = L"btnRec4";
         this->btnRec4->Size = System::Drawing::Size(140, 60);
         this->btnRec4->TabIndex = 57;
         this->btnRec4->Text = L"$TEMP$";
         this->btnRec4->UseVisualStyleBackColor = false;
         this->btnRec4->Visible = false;
         this->btnRec4->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec5
         // 
         this->btnRec5->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec5->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec5->Location = System::Drawing::Point(969, 212);
         this->btnRec5->Name = L"btnRec5";
         this->btnRec5->Size = System::Drawing::Size(140, 60);
         this->btnRec5->TabIndex = 56;
         this->btnRec5->Text = L"$TEMP$";
         this->btnRec5->UseVisualStyleBackColor = false;
         this->btnRec5->Visible = false;
         this->btnRec5->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec3
         // 
         this->btnRec3->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec3->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec3->Location = System::Drawing::Point(1115, 146);
         this->btnRec3->Name = L"btnRec3";
         this->btnRec3->Size = System::Drawing::Size(140, 60);
         this->btnRec3->TabIndex = 55;
         this->btnRec3->Text = L"$TEMP$";
         this->btnRec3->UseVisualStyleBackColor = false;
         this->btnRec3->Visible = false;
         this->btnRec3->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec1
         // 
         this->btnRec1->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec1->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec1->Location = System::Drawing::Point(823, 146);
         this->btnRec1->Name = L"btnRec1";
         this->btnRec1->Size = System::Drawing::Size(140, 60);
         this->btnRec1->TabIndex = 54;
         this->btnRec1->Text = L"$TEMP$";
         this->btnRec1->UseVisualStyleBackColor = false;
         this->btnRec1->Visible = false;
         this->btnRec1->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // btnRec2
         // 
         this->btnRec2->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnRec2->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnRec2->Location = System::Drawing::Point(969, 146);
         this->btnRec2->Name = L"btnRec2";
         this->btnRec2->Size = System::Drawing::Size(140, 60);
         this->btnRec2->TabIndex = 53;
         this->btnRec2->Text = L"$TEMP$";
         this->btnRec2->UseVisualStyleBackColor = false;
         this->btnRec2->Visible = false;
         this->btnRec2->Click += gcnew System::EventHandler(this, &ServerMain::addRecipeToOrder);
         // 
         // label7
         // 
         this->label7->AutoSize = true;
         this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label7->Location = System::Drawing::Point(152, 19);
         this->label7->Name = L"label7";
         this->label7->Size = System::Drawing::Size(113, 33);
         this->label7->TabIndex = 74;
         this->label7->Text = L"Order #: ";
         // 
         // orderIDLabel
         // 
         this->orderIDLabel->AutoSize = true;
         this->orderIDLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->orderIDLabel->Location = System::Drawing::Point(271, 19);
         this->orderIDLabel->Name = L"orderIDLabel";
         this->orderIDLabel->Size = System::Drawing::Size(0, 33);
         this->orderIDLabel->TabIndex = 75;
         // 
         // orderTree
         // 
         this->orderTree->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->orderTree->FullRowSelect = true;
         this->orderTree->ItemHeight = 22;
         this->orderTree->Location = System::Drawing::Point(17, 80);
         this->orderTree->Name = L"orderTree";
         this->orderTree->ShowPlusMinus = false;
         this->orderTree->ShowRootLines = false;
         this->orderTree->Size = System::Drawing::Size(515, 321);
         this->orderTree->TabIndex = 76;
         // 
         // btnUndo
         // 
         this->btnUndo->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->btnUndo->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnUndo->Location = System::Drawing::Point(118, 609);
         this->btnUndo->Name = L"btnUndo";
         this->btnUndo->Size = System::Drawing::Size(100, 60);
         this->btnUndo->TabIndex = 77;
         this->btnUndo->Text = L"UNDO";
         this->btnUndo->UseVisualStyleBackColor = false;
         this->btnUndo->Click += gcnew System::EventHandler(this, &ServerMain::btnUndo_Click);
         // 
         // button1
         // 
         this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
         this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->button1->Location = System::Drawing::Point(224, 609);
         this->button1->Name = L"button1";
         this->button1->Size = System::Drawing::Size(100, 60);
         this->button1->TabIndex = 78;
         this->button1->Text = L"REDO";
         this->button1->UseVisualStyleBackColor = false;
         this->button1->Click += gcnew System::EventHandler(this, &ServerMain::button1_Click);
         // 
         // ServerMain
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(1264, 681);
         this->ControlBox = false;
         this->Controls->Add(this->button1);
         this->Controls->Add(this->btnUndo);
         this->Controls->Add(this->orderTree);
         this->Controls->Add(this->orderIDLabel);
         this->Controls->Add(this->label7);
         this->Controls->Add(this->btnNextPage);
         this->Controls->Add(this->btnRec19);
         this->Controls->Add(this->btnRec20);
         this->Controls->Add(this->btnRec18);
         this->Controls->Add(this->btnRec16);
         this->Controls->Add(this->btnRec17);
         this->Controls->Add(this->btnRec15);
         this->Controls->Add(this->btnRec13);
         this->Controls->Add(this->btnRec14);
         this->Controls->Add(this->btnRec12);
         this->Controls->Add(this->btnRec10);
         this->Controls->Add(this->btnRec11);
         this->Controls->Add(this->btnRec9);
         this->Controls->Add(this->btnRec7);
         this->Controls->Add(this->btnRec8);
         this->Controls->Add(this->btnRec6);
         this->Controls->Add(this->btnRec4);
         this->Controls->Add(this->btnRec5);
         this->Controls->Add(this->btnRec3);
         this->Controls->Add(this->btnRec1);
         this->Controls->Add(this->btnRec2);
         this->Controls->Add(this->label6);
         this->Controls->Add(this->label5);
         this->Controls->Add(this->label4);
         this->Controls->Add(this->label3);
         this->Controls->Add(this->label2);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->btnClear);
         this->Controls->Add(this->btnDelete);
         this->Controls->Add(this->btnCat7);
         this->Controls->Add(this->btnCat6);
         this->Controls->Add(this->btnCat5);
         this->Controls->Add(this->btnCat4);
         this->Controls->Add(this->btnCat3);
         this->Controls->Add(this->btnCat2);
         this->Controls->Add(this->btnCat1);
         this->Controls->Add(this->btnMenuDown);
         this->Controls->Add(this->btnMenuUp);
         this->Controls->Add(this->btnFastCash);
         this->Controls->Add(this->btnClose);
         this->Controls->Add(this->btnTabs);
         this->Controls->Add(this->btnDone);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->Name = L"ServerMain";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"New Order";
         this->Load += gcnew System::EventHandler(this, &ServerMain::ServerMain_Load);
         this->ResumeLayout(false);
         this->PerformLayout();

      }

#pragma endregion
	private: System::Void btnDone_Click(System::Object^  sender, System::EventArgs^  e) {
      if (orderTree->Nodes->Count != 0) {
         this->form->Show();
         this->Close();
      }
	}
	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
		ServerClose ^ close = gcnew ServerClose(this, this->login);
		close->Show();
		this->Hide();
	}
	private: System::Void ServerMain_Load(System::Object^  sender, System::EventArgs^  e)
	{
		this->MaximizeBox = false;
		this->orderIDLabel->Text = myOrder->GetID().ToString();
      PopulateTree();

		SharedCode::Restaurant * restaurantInstance = SharedCode::Restaurant::GetRestaurant();
		SharedCode::RestaurantMenu * menu = restaurantInstance->getRestaurantMenu();
		SharedCode::RestaurantMenu::CategoryIterator categoryIterator = menu->FirstCategory();
		catCounter = 1;
		bool firstCategory = true;
		if (menu->numCategories() > NUM_CATEGORY_BUTTONS) {
			for (categoryIterator; categoryIterator != (menu->FirstCategory() + NUM_CATEGORY_BUTTONS); categoryIterator++)
			{
				SharedCode::MenuCategory::RecipeIterator recipeIterator = (*categoryIterator)->FirstRecipe();
				String ^buttonName = ("btnCat");
				buttonName = buttonName->Concat(buttonName, catCounter.ToString());
				Control ^temp = FindControl(buttonName);
				temp->Show();
				temp->Text = (gcnew String((*categoryIterator)->Name()->c_str()));
				CategoryWrapper ^ categoryWrapper = gcnew CategoryWrapper(*categoryIterator);
				temp->Tag = categoryWrapper;

				recCounter = 1;

				if (firstCategory) {
					for (recipeIterator; recipeIterator != ((*categoryIterator)->LastRecipe()); recipeIterator++) {
						String ^buttonName = ("btnRec");
						buttonName = buttonName->Concat(buttonName, recCounter.ToString());
						Control ^temp = FindControl(buttonName);
						temp->Show();
						temp->Text = (gcnew String((*recipeIterator)->Name()->c_str()));
						RecipeWrapper ^ recipeWrapper = gcnew RecipeWrapper(*recipeIterator);
						temp->Tag = recipeWrapper;

						recCounter++;
					}
				}
				firstCategory = false;
				catCounter++;
			}
			btnMenuDown->Enabled = true;
		}
		else {
			for (categoryIterator; categoryIterator != menu->LastCategory(); categoryIterator++)
			{
				SharedCode::MenuCategory::RecipeIterator recipeIterator = (*categoryIterator)->FirstRecipe();
				String ^buttonName = ("btnCat");
				buttonName = buttonName->Concat(buttonName, catCounter.ToString());
				Control ^temp = FindControl(buttonName);
				temp->Show();
				temp->Text = (gcnew String((*categoryIterator)->Name()->c_str()));
				CategoryWrapper ^ categoryWrapper = gcnew CategoryWrapper(*categoryIterator);
				temp->Tag = categoryWrapper;

				recCounter = 1;

				if (firstCategory) {
					for (recipeIterator; recipeIterator != ((*categoryIterator)->LastRecipe()); recipeIterator++) {
						String ^buttonName = ("btnRec");
						buttonName = buttonName->Concat(buttonName, recCounter.ToString());
						Control ^temp = FindControl(buttonName);
						temp->Show();
						temp->Text = (gcnew String((*recipeIterator)->Name()->c_str()));
						RecipeWrapper ^ recipeWrapper = gcnew RecipeWrapper(*recipeIterator);
						temp->Tag = recipeWrapper;

						recCounter++;
					}
				}
				firstCategory = false;
				catCounter++;
			}
		}

	}
	private: System::Void btnTabs_Click(System::Object^  sender, System::EventArgs^  e) {
		this->form->Show();
		this->Close();
	}

	private: ref class CategoryWrapper
	{
	public: CategoryWrapper(SharedCode::MenuCategory * category) : category(category) {};

	public: SharedCode::MenuCategory * category;

	public: System::String ^ ToString() override
	{
		return gcnew String(category->Name()->c_str());
	}
	};

	private: Control^ FindControl(String^ strControlName)
	{
		if (strControlName->Length == 0 || this->Controls->Find(strControlName, true)->Length == 0)
			return nullptr;

		return this->Controls->Find(strControlName, true)[0];
	}

	private: ref class RecipeWrapper
	{
	public: RecipeWrapper(SharedCode::Recipe * recipe) : recipe(recipe) {};

	public: SharedCode::Recipe * recipe;
	};
            private: ref class OrderItemWrapper
            {
            public: OrderItemWrapper(SharedCode::OrderItem * orderItem) : orderItem(orderItem) {};

            public: SharedCode::OrderItem * orderItem;
            };

	private: System::Void btnMenuUp_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 1; i <= NUM_CATEGORY_BUTTONS; i++) {
			String ^buttonName = ("btnCat");
			buttonName = buttonName->Concat(buttonName, i.ToString());
			Control ^temp = FindControl(buttonName);
			temp->Hide();
		}

		SharedCode::Restaurant * restaurantInstance = SharedCode::Restaurant::GetRestaurant();
		SharedCode::RestaurantMenu * menu = restaurantInstance->getRestaurantMenu();
		SharedCode::RestaurantMenu::CategoryIterator categoryIterator = menu->FirstCategory();

		int j = 1;
		for (categoryIterator; categoryIterator != menu->FirstCategory() + NUM_CATEGORY_BUTTONS; categoryIterator++)
		{
			SharedCode::MenuCategory::RecipeIterator recipeIterator = (*categoryIterator)->FirstRecipe();
			String ^buttonName = ("btnCat");
			buttonName = buttonName->Concat(buttonName, j.ToString());
			Control ^temp = FindControl(buttonName);
			temp->Show();
			temp->Text = (gcnew String((*categoryIterator)->Name()->c_str()));
			CategoryWrapper ^ categoryWrapper = gcnew CategoryWrapper(*categoryIterator);
			temp->Tag = categoryWrapper;
			j++;
			catCounter--;
		}
		btnMenuDown->Enabled = true;
		btnMenuUp->Enabled = false;
		catCounter++;
	}

	private: System::Void btnMenuDown_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 1; i <= NUM_CATEGORY_BUTTONS; i++) {
			String ^buttonName = ("btnCat");
			buttonName = buttonName->Concat(buttonName, i.ToString());
			Control ^temp = FindControl(buttonName);
			temp->Hide();
		}

		SharedCode::Restaurant * restaurantInstance = SharedCode::Restaurant::GetRestaurant();
		SharedCode::RestaurantMenu * menu = restaurantInstance->getRestaurantMenu();
		SharedCode::RestaurantMenu::CategoryIterator categoryIterator = menu->FirstCategory() + catCounter - 1;

		int j = 1;
		for (categoryIterator; categoryIterator != menu->LastCategory(); categoryIterator++)
		{
			SharedCode::MenuCategory::RecipeIterator recipeIterator = (*categoryIterator)->FirstRecipe();
			String ^buttonName = ("btnCat");
			buttonName = buttonName->Concat(buttonName, j.ToString());
			Control ^temp = FindControl(buttonName);
			temp->Show();
			temp->Text = (gcnew String((*categoryIterator)->Name()->c_str()));
			CategoryWrapper ^ categoryWrapper = gcnew CategoryWrapper(*categoryIterator);
			temp->Tag = categoryWrapper;
			j++;
			catCounter++;
		}
		btnMenuDown->Enabled = false;
		btnMenuUp->Enabled = true;
	}

	private: System::Void catButtonClick(System::Object^  sender, System::EventArgs^  e) {

		for (int i = 1; i <= NUM_RECIPE_BUTTONS; i++) {
			String ^buttonName = ("btnRec");
			buttonName = buttonName->Concat(buttonName, i.ToString());
			Control ^temp = FindControl(buttonName);
			temp->Hide();
		}

		SharedCode::Restaurant * restaurantInstance = SharedCode::Restaurant::GetRestaurant();
		SharedCode::RestaurantMenu * menu = restaurantInstance->getRestaurantMenu();
		Button^ selectedButton = dynamic_cast<Button^>(sender);
		CategoryWrapper^ categoryWrapper = dynamic_cast<CategoryWrapper^>(selectedButton->Tag);

		SharedCode::MenuCategory::RecipeIterator recipeIterator = categoryWrapper->category->FirstRecipe();
		recCounter = 1;

		for (recipeIterator; recipeIterator != categoryWrapper->category->LastRecipe(); recipeIterator++) {
			String ^buttonName = ("btnRec");
			buttonName = buttonName->Concat(buttonName, recCounter.ToString());
			Control ^temp = FindControl(buttonName);
			temp->Show();
			temp->Text = (gcnew String((*recipeIterator)->Name()->c_str()));
			RecipeWrapper ^ recipeWrapper = gcnew RecipeWrapper(*recipeIterator);
			temp->Tag = recipeWrapper;

			recCounter++;
		}
	}


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

	private: System::Void addRecipeToOrder(System::Object^  sender, System::EventArgs^  e) {
		Button^ recipeButton = dynamic_cast<Button^>(sender);
		RecipeWrapper^ recipe = dynamic_cast<RecipeWrapper^>(recipeButton->Tag);

      OrderItem * orderItem = new OrderItem(recipe->recipe);
      OrderItemWrapper^ orderItemWrapper = gcnew OrderItemWrapper(orderItem);
		AddOrderItem * addItem = new AddOrderItem(myOrder, orderItem);

      Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(addItem);

      PopulateTree();
	}
	private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) {
      if (orderTree->SelectedNode != nullptr && orderTree->SelectedNode->Tag != nullptr) {
         OrderItem * orderItem = ((OrderItemWrapper^)orderTree->SelectedNode->Tag)->orderItem;

         RemoveOrderItem* removeItem = new RemoveOrderItem(myOrder, orderItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(removeItem);

         PopulateTree();
      }

	}

	private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
	}

   private: System::Void btnUndo_Click(System::Object^  sender, System::EventArgs^  e) {
      Restaurant::GetRestaurant()->getOrderController()->UndoCommand();
      PopulateTree();
   }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
   Restaurant::GetRestaurant()->getOrderController()->RedoCommand();
   PopulateTree();
}
};
}
