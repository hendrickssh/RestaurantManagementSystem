//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: GUI for editing the Menu. Has the ability to add/delete
//    Categories and Items.
//---------------------------------------------------------------------

#pragma once

#include <string>

#include <msclr\marshal_cppstd.h>

#include "Restaurant.h"
#include "RestaurantMenu.h"

namespace RestaurantManagementSystem {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;
   using namespace SharedCode;

   /// <summary>
   /// Summary for RestaurantMenuEditor
   /// </summary>
   public ref class RestaurantMenuEditor : public System::Windows::Forms::Form
   {
   public:
      RestaurantMenuEditor(void)
      {
         RestaurantMenuEditor(nullptr);
         //
         //TODO: Add the constructor code here
         //
      }
      RestaurantMenuEditor(Form ^ form)
      {
         InitializeComponent();
         this->form = form;

         PopulateTree();
      }

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~RestaurantMenuEditor()
      {
         if (components)
         {
            delete components;
         }
      }
   private: System::Windows::Forms::Form ^ form;
   private: System::Windows::Forms::TreeView^  treeMenu;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Button^  btnNewRecipe;

   private: System::Windows::Forms::Button^  btnDeleteRecipe;


   private: System::Windows::Forms::TextBox^  tbRecipeDescription;

   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::Label^  lblRecipeName;
   private: System::Windows::Forms::Label^  lblPrice;
   private: System::Windows::Forms::TextBox^  tbRecipeName;
   private: System::Windows::Forms::TextBox^  tbRecipePrice;
   private: System::Windows::Forms::Button^  btnSaveChanges;

   private: System::Windows::Forms::Button^  btnCancelChanges;

   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::TextBox^  tbCategoryName;

   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::ComboBox^  cbRecipeCategory;
   private: System::Windows::Forms::Button^  btnNewCategory;
   private: System::Windows::Forms::Button^  btnCategorySaveName;
   private: System::Windows::Forms::Button^  btnDeleteCategory;



   private: System::Windows::Forms::GroupBox^  groupBox1;
   private: System::Windows::Forms::Panel^  panel1;









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
         this->treeMenu = (gcnew System::Windows::Forms::TreeView());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->btnNewRecipe = (gcnew System::Windows::Forms::Button());
         this->btnDeleteRecipe = (gcnew System::Windows::Forms::Button());
         this->tbRecipeDescription = (gcnew System::Windows::Forms::TextBox());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->lblRecipeName = (gcnew System::Windows::Forms::Label());
         this->lblPrice = (gcnew System::Windows::Forms::Label());
         this->tbRecipeName = (gcnew System::Windows::Forms::TextBox());
         this->tbRecipePrice = (gcnew System::Windows::Forms::TextBox());
         this->btnSaveChanges = (gcnew System::Windows::Forms::Button());
         this->btnCancelChanges = (gcnew System::Windows::Forms::Button());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->tbCategoryName = (gcnew System::Windows::Forms::TextBox());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->cbRecipeCategory = (gcnew System::Windows::Forms::ComboBox());
         this->btnNewCategory = (gcnew System::Windows::Forms::Button());
         this->btnCategorySaveName = (gcnew System::Windows::Forms::Button());
         this->btnDeleteCategory = (gcnew System::Windows::Forms::Button());
         this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
         this->panel1 = (gcnew System::Windows::Forms::Panel());
         this->groupBox1->SuspendLayout();
         this->panel1->SuspendLayout();
         this->SuspendLayout();
         // 
         // treeMenu
         // 
         this->treeMenu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->treeMenu->HideSelection = false;
         this->treeMenu->ItemHeight = 20;
         this->treeMenu->Location = System::Drawing::Point(12, 37);
         this->treeMenu->Name = L"treeMenu";
         this->treeMenu->ShowNodeToolTips = true;
         this->treeMenu->Size = System::Drawing::Size(671, 517);
         this->treeMenu->TabIndex = 3;
         this->treeMenu->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &RestaurantMenuEditor::ClickTreeNode);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label1->Location = System::Drawing::Point(12, 10);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(70, 25);
         this->label1->TabIndex = 1;
         this->label1->Text = L"Menu";
         // 
         // btnNewRecipe
         // 
         this->btnNewRecipe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnNewRecipe->Location = System::Drawing::Point(14, 208);
         this->btnNewRecipe->Name = L"btnNewRecipe";
         this->btnNewRecipe->Size = System::Drawing::Size(134, 37);
         this->btnNewRecipe->TabIndex = 0;
         this->btnNewRecipe->TabStop = false;
         this->btnNewRecipe->Text = L"New Recipe";
         this->btnNewRecipe->UseVisualStyleBackColor = true;
         this->btnNewRecipe->Click += gcnew System::EventHandler(this, &RestaurantMenuEditor::btnAddItem_Click);
         // 
         // btnDeleteRecipe
         // 
         this->btnDeleteRecipe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->btnDeleteRecipe->Location = System::Drawing::Point(151, 208);
         this->btnDeleteRecipe->Name = L"btnDeleteRecipe";
         this->btnDeleteRecipe->Size = System::Drawing::Size(134, 37);
         this->btnDeleteRecipe->TabIndex = 2;
         this->btnDeleteRecipe->TabStop = false;
         this->btnDeleteRecipe->Text = L"Delete Recipe";
         this->btnDeleteRecipe->UseVisualStyleBackColor = true;
         this->btnDeleteRecipe->Click += gcnew System::EventHandler(this, &RestaurantMenuEditor::btnDeleteRecipe_Click);
         // 
         // tbRecipeDescription
         // 
         this->tbRecipeDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->tbRecipeDescription->Location = System::Drawing::Point(191, 42);
         this->tbRecipeDescription->MaxLength = 300;
         this->tbRecipeDescription->Multiline = true;
         this->tbRecipeDescription->Name = L"tbRecipeDescription";
         this->tbRecipeDescription->Size = System::Drawing::Size(366, 149);
         this->tbRecipeDescription->TabIndex = 3;
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label2->Location = System::Drawing::Point(188, 15);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(169, 24);
         this->label2->TabIndex = 5;
         this->label2->Text = L"Recipe Description";
         // 
         // lblRecipeName
         // 
         this->lblRecipeName->AutoSize = true;
         this->lblRecipeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblRecipeName->Location = System::Drawing::Point(14, 15);
         this->lblRecipeName->Name = L"lblRecipeName";
         this->lblRecipeName->Size = System::Drawing::Size(126, 24);
         this->lblRecipeName->TabIndex = 6;
         this->lblRecipeName->Text = L"Recipe Name";
         // 
         // lblPrice
         // 
         this->lblPrice->AutoSize = true;
         this->lblPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->lblPrice->Location = System::Drawing::Point(14, 75);
         this->lblPrice->Name = L"lblPrice";
         this->lblPrice->RightToLeft = System::Windows::Forms::RightToLeft::No;
         this->lblPrice->Size = System::Drawing::Size(118, 24);
         this->lblPrice->TabIndex = 7;
         this->lblPrice->Text = L"Recipe Price";
         // 
         // tbRecipeName
         // 
         this->tbRecipeName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->tbRecipeName->Location = System::Drawing::Point(14, 44);
         this->tbRecipeName->MaxLength = 30;
         this->tbRecipeName->Name = L"tbRecipeName";
         this->tbRecipeName->Size = System::Drawing::Size(165, 26);
         this->tbRecipeName->TabIndex = 1;
         // 
         // tbRecipePrice
         // 
         this->tbRecipePrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->tbRecipePrice->Location = System::Drawing::Point(14, 104);
         this->tbRecipePrice->MaxLength = 7;
         this->tbRecipePrice->Name = L"tbRecipePrice";
         this->tbRecipePrice->Size = System::Drawing::Size(165, 26);
         this->tbRecipePrice->TabIndex = 2;
         // 
         // btnSaveChanges
         // 
         this->btnSaveChanges->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnSaveChanges->Location = System::Drawing::Point(286, 208);
         this->btnSaveChanges->Name = L"btnSaveChanges";
         this->btnSaveChanges->Size = System::Drawing::Size(134, 37);
         this->btnSaveChanges->TabIndex = 10;
         this->btnSaveChanges->TabStop = false;
         this->btnSaveChanges->Text = L"Save Changes";
         this->btnSaveChanges->UseVisualStyleBackColor = true;
         this->btnSaveChanges->Click += gcnew System::EventHandler(this, &RestaurantMenuEditor::btnSaveChanges_Click);
         // 
         // btnCancelChanges
         // 
         this->btnCancelChanges->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->btnCancelChanges->Location = System::Drawing::Point(422, 208);
         this->btnCancelChanges->Name = L"btnCancelChanges";
         this->btnCancelChanges->Size = System::Drawing::Size(134, 37);
         this->btnCancelChanges->TabIndex = 11;
         this->btnCancelChanges->TabStop = false;
         this->btnCancelChanges->Text = L"Cancel Changes";
         this->btnCancelChanges->UseVisualStyleBackColor = true;
         this->btnCancelChanges->Click += gcnew System::EventHandler(this, &RestaurantMenuEditor::CancelChangesClick);
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label3->Location = System::Drawing::Point(14, 14);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(141, 24);
         this->label3->TabIndex = 12;
         this->label3->Text = L"Category Name";
         // 
         // tbCategoryName
         // 
         this->tbCategoryName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->tbCategoryName->Location = System::Drawing::Point(14, 41);
         this->tbCategoryName->MaxLength = 30;
         this->tbCategoryName->Name = L"tbCategoryName";
         this->tbCategoryName->Size = System::Drawing::Size(157, 26);
         this->tbCategoryName->TabIndex = 13;
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->label4->Location = System::Drawing::Point(14, 135);
         this->label4->Name = L"label4";
         this->label4->RightToLeft = System::Windows::Forms::RightToLeft::No;
         this->label4->Size = System::Drawing::Size(150, 24);
         this->label4->TabIndex = 14;
         this->label4->Text = L"Recipe Category";
         this->label4->Visible = false;
         // 
         // cbRecipeCategory
         // 
         this->cbRecipeCategory->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
         this->cbRecipeCategory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->cbRecipeCategory->FormattingEnabled = true;
         this->cbRecipeCategory->ImeMode = System::Windows::Forms::ImeMode::Disable;
         this->cbRecipeCategory->Location = System::Drawing::Point(14, 162);
         this->cbRecipeCategory->Name = L"cbRecipeCategory";
         this->cbRecipeCategory->Size = System::Drawing::Size(165, 28);
         this->cbRecipeCategory->TabIndex = 15;
         this->cbRecipeCategory->Tag = L"    ";
         this->cbRecipeCategory->Visible = false;
         // 
         // btnNewCategory
         // 
         this->btnNewCategory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
         this->btnNewCategory->Location = System::Drawing::Point(14, 72);
         this->btnNewCategory->Name = L"btnNewCategory";
         this->btnNewCategory->Size = System::Drawing::Size(134, 37);
         this->btnNewCategory->TabIndex = 16;
         this->btnNewCategory->Text = L"New Category";
         this->btnNewCategory->UseVisualStyleBackColor = true;
         this->btnNewCategory->Click += gcnew System::EventHandler(this, &RestaurantMenuEditor::btnNewCategory_Click);
         // 
         // btnCategorySaveName
         // 
         this->btnCategorySaveName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->btnCategorySaveName->Location = System::Drawing::Point(154, 72);
         this->btnCategorySaveName->Name = L"btnCategorySaveName";
         this->btnCategorySaveName->Size = System::Drawing::Size(134, 37);
         this->btnCategorySaveName->TabIndex = 17;
         this->btnCategorySaveName->Text = L"Save Name";
         this->btnCategorySaveName->UseVisualStyleBackColor = true;
         this->btnCategorySaveName->Click += gcnew System::EventHandler(this, &RestaurantMenuEditor::btnCategorySaveName_Click);
         // 
         // btnDeleteCategory
         // 
         this->btnDeleteCategory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
            System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
         this->btnDeleteCategory->Location = System::Drawing::Point(295, 72);
         this->btnDeleteCategory->Name = L"btnDeleteCategory";
         this->btnDeleteCategory->Size = System::Drawing::Size(134, 37);
         this->btnDeleteCategory->TabIndex = 18;
         this->btnDeleteCategory->Text = L"Delete Category";
         this->btnDeleteCategory->UseVisualStyleBackColor = true;
         this->btnDeleteCategory->Click += gcnew System::EventHandler(this, &RestaurantMenuEditor::btnDeleteCategory_Click);
         // 
         // groupBox1
         // 
         this->groupBox1->Controls->Add(this->tbRecipeDescription);
         this->groupBox1->Controls->Add(this->btnNewRecipe);
         this->groupBox1->Controls->Add(this->btnDeleteRecipe);
         this->groupBox1->Controls->Add(this->label2);
         this->groupBox1->Controls->Add(this->cbRecipeCategory);
         this->groupBox1->Controls->Add(this->lblRecipeName);
         this->groupBox1->Controls->Add(this->label4);
         this->groupBox1->Controls->Add(this->lblPrice);
         this->groupBox1->Controls->Add(this->tbRecipeName);
         this->groupBox1->Controls->Add(this->tbRecipePrice);
         this->groupBox1->Controls->Add(this->btnCancelChanges);
         this->groupBox1->Controls->Add(this->btnSaveChanges);
         this->groupBox1->Location = System::Drawing::Point(687, 173);
         this->groupBox1->Margin = System::Windows::Forms::Padding(2);
         this->groupBox1->Name = L"groupBox1";
         this->groupBox1->Padding = System::Windows::Forms::Padding(2);
         this->groupBox1->Size = System::Drawing::Size(568, 262);
         this->groupBox1->TabIndex = 19;
         this->groupBox1->TabStop = false;
         // 
         // panel1
         // 
         this->panel1->Controls->Add(this->label3);
         this->panel1->Controls->Add(this->tbCategoryName);
         this->panel1->Controls->Add(this->btnDeleteCategory);
         this->panel1->Controls->Add(this->btnNewCategory);
         this->panel1->Controls->Add(this->btnCategorySaveName);
         this->panel1->Location = System::Drawing::Point(687, 37);
         this->panel1->Margin = System::Windows::Forms::Padding(2);
         this->panel1->Name = L"panel1";
         this->panel1->Size = System::Drawing::Size(568, 132);
         this->panel1->TabIndex = 20;
         // 
         // RestaurantMenuEditor
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(1264, 681);
         this->Controls->Add(this->panel1);
         this->Controls->Add(this->groupBox1);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->treeMenu);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->Name = L"RestaurantMenuEditor";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"Menu Editor";
         this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RestaurantMenuEditor::RestaurantMenuEditor_FormClosing);
         this->Load += gcnew System::EventHandler(this, &RestaurantMenuEditor::RestaurantMenuEditor_Load);
         this->groupBox1->ResumeLayout(false);
         this->groupBox1->PerformLayout();
         this->panel1->ResumeLayout(false);
         this->panel1->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void RestaurantMenuEditor_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
   {
      if (form != nullptr)
         form->Show();
   }
   private: System::Void RestaurantMenuEditor_Load(System::Object^  sender, System::EventArgs^  e)
   {
      treeMenu->ExpandAll();
   }
   private: System::Void btnAddItem_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (treeMenu->SelectedNode == nullptr)
         return;

      int top = treeMenu->Top;

      TreeNode ^ categoryNode;

      if (dynamic_cast<RecipeWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
         categoryNode = treeMenu->SelectedNode->Parent;
      else if (dynamic_cast<CategoryWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
         categoryNode = treeMenu->SelectedNode;
      else
         return;

      ((CategoryWrapper^)categoryNode->Tag)->category->AddRecipe(new Recipe("NewRecipe"));

      PopulateTree();

   }

            /// <summary>
            /// Populates the restaurant menu tree with nodes for the current restaurant
            /// menu.
            /// </summary>
   private: void PopulateTree()
   {
      treeMenu->BeginUpdate();

      SharedCode::Restaurant * restaurantInstance = SharedCode::Restaurant::GetRestaurant();

      SharedCode::RestaurantMenu * menu = restaurantInstance->getRestaurantMenu();

      SharedCode::RestaurantMenu::CategoryIterator categoryIterator = menu->FirstCategory();

      treeMenu->Nodes->Clear();

      cbRecipeCategory->Items->Clear();

      for (categoryIterator; categoryIterator != menu->LastCategory(); categoryIterator++)
      {
         SharedCode::MenuCategory::RecipeIterator recipeIterator = (*categoryIterator)->FirstRecipe();

         TreeNode ^ categoryNode = gcnew TreeNode(gcnew String((*categoryIterator)->Name()->c_str()));

         CategoryWrapper ^ categoryWrapper = gcnew CategoryWrapper(*categoryIterator);

         categoryNode->Tag = categoryWrapper;

         cbRecipeCategory->Items->Add(categoryWrapper);

         treeMenu->Nodes->Add(categoryNode);

         for (recipeIterator; recipeIterator != (*categoryIterator)->LastRecipe(); recipeIterator++)
         {
            TreeNode ^ recipeNode = gcnew TreeNode(gcnew String((*recipeIterator)->Name()->c_str()));

            recipeNode->Tag = gcnew RecipeWrapper(*recipeIterator);

            recipeNode->ToolTipText = gcnew String((*recipeIterator)->Description()->c_str());

            categoryNode->Nodes->Add(recipeNode);
         }
      }

      treeMenu->ExpandAll();

      treeMenu->EndUpdate();
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

   private: ref class RecipeWrapper
   {
   public: RecipeWrapper(SharedCode::Recipe * recipe) : recipe(recipe) {};

   public: SharedCode::Recipe * recipe;
   };

            /// <summary>
            /// Populates the editable fields with the recipe's information.
            /// </summary>
            /// <param name="sender"></param>
            /// <param name="e"></param>
            /// <returns></returns>
   private: System::Void ClickTreeNode(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {
      PopulateFields();
   }
   private: System::Void PopulateFields()
   {
      CategoryControlsEnabled(false);
      RecipeControlsEnabled(false);

      if (dynamic_cast<RecipeWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
      {
         RecipeControlsEnabled(true);

         Recipe * recipePtr = ((RecipeWrapper^)treeMenu->SelectedNode->Tag)->recipe;

         if (recipePtr->Name() != nullptr)
            tbRecipeName->Text = gcnew String(recipePtr->Name()->c_str());
         else
            tbRecipeName->Text = "";

         char result[15];

         sprintf_s(result, "%3.2f", ((RecipeWrapper^)treeMenu->SelectedNode->Tag)->recipe->Price());

         tbRecipePrice->Text = gcnew String(string(result).c_str());

         if (recipePtr->Description() != nullptr)
            tbRecipeDescription->Text = gcnew String(((RecipeWrapper^)treeMenu->SelectedNode->Tag)->recipe->Description()->c_str());
         else
            tbRecipeDescription->Text = "";

         cbRecipeCategory->SelectedItem = ((CategoryWrapper^)treeMenu->SelectedNode->Parent->Tag);

      }

      if (dynamic_cast<CategoryWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
      {
         CategoryControlsEnabled(true);

         MenuCategory * categoryPtr = ((CategoryWrapper^)treeMenu->SelectedNode->Tag)->category;

         if (categoryPtr->Name() != nullptr)
            tbCategoryName->Text = gcnew String(categoryPtr->Name()->c_str());
      }
   }

            /// <summary>
            /// 
            /// </summary>
            /// <param name="enabled"></param>
            /// <returns></returns>
   private: System::Void CategoryControlsEnabled(Boolean enabled)
   {
      btnCategorySaveName->Enabled = enabled;
      btnDeleteCategory->Enabled = enabled;
      btnNewCategory->Enabled = true;

      tbCategoryName->Enabled = enabled;
      tbCategoryName->Text = "";
   }

            /// <summary>
            /// Mass change the enabled settings for the recipe editing controls.
            /// </summary>
            /// <param name="enabled"></param>
            /// <returns></returns>
   private: System::Void RecipeControlsEnabled(Boolean enabled)
   {
      btnCancelChanges->Enabled = enabled;
      btnDeleteRecipe->Enabled = enabled;
      btnSaveChanges->Enabled = enabled;
      btnNewRecipe->Enabled = true;

      tbRecipeName->Enabled = enabled;
      tbRecipePrice->Enabled = enabled;
      cbRecipeCategory->Enabled = enabled;
      tbRecipeDescription->Enabled = enabled;

      tbRecipeName->Text = "";
      tbRecipePrice->Text = "";
      tbRecipeDescription->Text = "";
   }

   private: System::Void RecipeNameChanged(System::Object^  sender, System::EventArgs^  e) {

      UpdateSelectedNode();
   }

            /// <summary>
            /// Updates the string of the selected node in the tree.
            /// </summary>
            /// <returns></returns>
   private: System::Void UpdateSelectedNode()
   {
      if (dynamic_cast<RecipeWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
      {
         Recipe * recipePtr = ((RecipeWrapper^)treeMenu->SelectedNode->Tag)->recipe;

         treeMenu->SelectedNode->Text = gcnew String(recipePtr->Name()->c_str());

         Restaurant::GetRestaurant()->SaveMenu();
      }
   }

            /// <summary>
            /// Repopulates the fields using the currently selected tree node.
            /// </summary>
            /// <param name="sender"></param>
            /// <param name="e"></param>
            /// <returns></returns>
   private: System::Void CancelChangesClick(System::Object^  sender, System::EventArgs^  e) {
      PopulateFields();
   }
   private: System::Void btnSaveChanges_Click(System::Object^  sender, System::EventArgs^  e) {
      if (treeMenu->SelectedNode != nullptr && dynamic_cast<RecipeWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
      {
         msclr::interop::marshal_context context;

         Recipe * recipePtr = ((RecipeWrapper^)treeMenu->SelectedNode->Tag)->recipe;

         std::string * newRecipeName = new string(context.marshal_as<std::string>(tbRecipeName->Text));

         recipePtr->Name(newRecipeName);

         std::string newRecipePrice(context.marshal_as<std::string>(tbRecipePrice->Text));

         float newPrice;

         sscanf_s(newRecipePrice.c_str(), "%f", &newPrice);

         recipePtr->Price(newPrice);

         std::string * newRecipeDescription = new string(context.marshal_as<std::string>(tbRecipeDescription->Text));

         recipePtr->Description(newRecipeDescription);

         UpdateSelectedNode();
      }
   }
   private: System::Void btnNewCategory_Click(System::Object^  sender, System::EventArgs^  e) {
      Restaurant::GetRestaurant()->getRestaurantMenu()->AddCategory(new MenuCategory("NewCategory"));
      PopulateTree();
      treeMenu->SelectedNode = treeMenu->Nodes[treeMenu->Nodes->Count - 1];

      Restaurant::GetRestaurant()->SaveMenu();
   }
   private: System::Void btnDeleteCategory_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (treeMenu->SelectedNode != nullptr)
      {
         if (dynamic_cast<CategoryWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
         {
            MenuCategory * categoryPtr = ((CategoryWrapper^)treeMenu->SelectedNode->Tag)->category;

            Restaurant::GetRestaurant()->getRestaurantMenu()->RemoveCategory(categoryPtr);

            PopulateTree();

            if (treeMenu->Nodes->Count > 0)
               treeMenu->SelectedNode = treeMenu->Nodes[0];
         }
         tbCategoryName->Text = "";
         Restaurant::GetRestaurant()->SaveMenu();
      }
   }
   private: System::Void btnCategorySaveName_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (dynamic_cast<CategoryWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
      {
         msclr::interop::marshal_context context;

         MenuCategory * categoryPtr = ((CategoryWrapper^)treeMenu->SelectedNode->Tag)->category;

         std::string * newCategoryName = new string(context.marshal_as<std::string>(tbCategoryName->Text));

         categoryPtr->Name(newCategoryName);

         PopulateTree();

         treeMenu->SelectedNode = treeMenu->Nodes[0];

         Restaurant::GetRestaurant()->SaveMenu();
      }
   }
   private: System::Void btnDeleteRecipe_Click(System::Object^  sender, System::EventArgs^  e)
   {
      if (treeMenu->SelectedNode != nullptr)
      {
         if (dynamic_cast<RecipeWrapper^>(treeMenu->SelectedNode->Tag) != nullptr)
         {
            Recipe * recipePtr = ((RecipeWrapper^)treeMenu->SelectedNode->Tag)->recipe;

            MenuCategory * categoryPtr = ((CategoryWrapper^)treeMenu->SelectedNode->Parent->Tag)->category;

            categoryPtr->RemoveRecipe(recipePtr);

            PopulateTree();

            tbRecipeName->Text = "";
            tbRecipePrice->Text = "";
            tbRecipeDescription->Text = "";
            Restaurant::GetRestaurant()->SaveMenu();
         }
      }
   }
   };
}
