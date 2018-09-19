#include "stdafx.h"
#include "CppUnitTest.h"
#include "string.h"

#include "Restaurant.h"
#include "RestaurantMenu.h"
#include "MenuCategory.h"

#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace SharedCode;

namespace SharedCodeTests
{
	TEST_CLASS(RestaurantMenu_Tests)
	{
	public:

		TEST_METHOD(AddCategory)
		{
			RestaurantMenu * Menu = new RestaurantMenu();

			MenuCategory * Desserts = new MenuCategory("Desserts");

			Assert::IsNotNull(Desserts);

			Assert::IsFalse(Menu->HasCategory(Desserts));

			Menu->AddCategory(Desserts);

			Assert::IsTrue(Menu->HasCategory(Desserts));
		}

		TEST_METHOD(HasCategoryFailure)
		{
			RestaurantMenu * Menu = new RestaurantMenu();

			MenuCategory * Desserts = new MenuCategory("Desserts");

			MenuCategory * Fish = new MenuCategory("Fish");

			Assert::IsNotNull(Desserts);
			Assert::IsNotNull(Fish);

			Assert::IsFalse(Menu->HasCategory(Desserts));
			Assert::IsFalse(Menu->HasCategory(Fish));

			Menu->AddCategory(Desserts);

			Assert::IsTrue(Menu->HasCategory(Desserts));
			Assert::IsFalse(Menu->HasCategory(Fish));
		}

		/// <summary>
		/// Tests that Find Category actually finds the proper category.
		/// </summary>
		TEST_METHOD(FindCategory)
		{
			RestaurantMenu * Menu = new RestaurantMenu();

			MenuCategory * AppetizerCategory = new MenuCategory("Appetizers");

			MenuCategory * DinnersCategory = new MenuCategory("Dinners");

			Menu->AddCategory(AppetizerCategory);

			Menu->AddCategory(DinnersCategory);

			Assert::IsTrue(AppetizerCategory == Menu->FindCategory("Appetizers"));
			Assert::IsTrue(AppetizerCategory == Menu->FindCategory(AppetizerCategory));

			Assert::IsFalse(DinnersCategory == Menu->FindCategory("Appetizers"));
			Assert::IsFalse(DinnersCategory == Menu->FindCategory(AppetizerCategory));

			Assert::IsTrue(DinnersCategory == Menu->FindCategory("Dinners"));
			Assert::IsTrue(DinnersCategory == Menu->FindCategory(DinnersCategory));

			Assert::IsFalse(AppetizerCategory == Menu->FindCategory("Dinners"));
			Assert::IsFalse(AppetizerCategory == Menu->FindCategory(DinnersCategory));

			delete Menu;
		}

      /// <summary>
      /// Tests that Find Category actually finds the proper category.
      /// </summary>
      TEST_METHOD(FindRecipe)
      {
         RestaurantMenu * Menu = new RestaurantMenu();

         MenuCategory * AppetizerCategory = new MenuCategory("Appetizers");

         MenuCategory * DinnersCategory = new MenuCategory("Dinners");

         Menu->AddCategory(AppetizerCategory);

         Menu->AddCategory(DinnersCategory);

         Recipe * Recipe1 = new Recipe("Recipe1");
         Recipe * Recipe2 = new Recipe("Recipe2");
         Recipe * Recipe3 = new Recipe("Recipe3");
         Recipe * Recipe4 = new Recipe("Recipe4");

         AppetizerCategory->AddRecipe(Recipe1);
         AppetizerCategory->AddRecipe(Recipe2);
         DinnersCategory->AddRecipe(Recipe3);
         DinnersCategory->AddRecipe(Recipe4);

         Assert::IsNotNull(Menu->FindRecipe(Recipe1));
         Assert::IsNotNull(Menu->FindRecipe(Recipe2));
         Assert::IsNotNull(Menu->FindRecipe(Recipe3));
         Assert::IsNotNull(Menu->FindRecipe(Recipe4));

         Assert::IsNotNull(Menu->FindRecipe("Recipe1"));
         Assert::IsNotNull(Menu->FindRecipe("Recipe2"));
         Assert::IsNotNull(Menu->FindRecipe("Recipe3"));
         Assert::IsNotNull(Menu->FindRecipe("Recipe4"));

         delete Menu;
      }
      /// <summary>
      /// Tests that Find Category actually finds the proper category.
      /// </summary>
      TEST_METHOD(FindRecipeNotFound)
      {
         RestaurantMenu * Menu = new RestaurantMenu();

         MenuCategory * AppetizerCategory = new MenuCategory("Appetizers");

         MenuCategory * DinnersCategory = new MenuCategory("Dinners");

         Menu->AddCategory(AppetizerCategory);

         Menu->AddCategory(DinnersCategory);

         Recipe * Recipe1 = new Recipe("Recipe1");
         Recipe * Recipe2 = new Recipe("Recipe2");
         Recipe * Recipe3 = new Recipe("Recipe3");
         Recipe * Recipe4 = new Recipe("Recipe4");

         AppetizerCategory->AddRecipe(Recipe1);
         AppetizerCategory->AddRecipe(Recipe2);
         DinnersCategory->AddRecipe(Recipe3);

         Assert::IsNotNull(Menu->FindRecipe(Recipe1));
         Assert::IsNotNull(Menu->FindRecipe(Recipe2));
         Assert::IsNotNull(Menu->FindRecipe(Recipe3));
         Assert::IsNull(Menu->FindRecipe(Recipe4));

         Assert::IsNotNull(Menu->FindRecipe("Recipe1"));
         Assert::IsNotNull(Menu->FindRecipe("Recipe2"));
         Assert::IsNotNull(Menu->FindRecipe("Recipe3"));
         Assert::IsNull(Menu->FindRecipe("Recipe4"));

         delete Menu;
      }

      /// <summary>
      /// Tests loading a valid menu xml file.
      /// </summary>
      TEST_METHOD(LoadRestaurantMenu)
      {
         RestaurantMenu * test = RestaurantMenu::ImportMenu("../../RestaurantManagementSystem/db.xml");

         RestaurantMenu::CategoryIterator iterator = test->FirstCategory();

         if (iterator != test->LastCategory())
         {
            char * charString = (char*)((*iterator)->Name());

            while (iterator != test->LastCategory())
            {
               Logger::WriteMessage(charString);
               iterator++;
            }
         }
      }

      /// <summary>
      /// Tests loading a restaurant menu when the file doesn't exist.
      /// </summary>
      TEST_METHOD(LoadRestaurantMenuNonExistent)
      {
         Restaurant * testRestaurant = new Restaurant();

         remove("db.xml");

         testRestaurant->LoadMenu();
      }

      /// <summary>
      /// Tests exporting the menu.
      /// </summary>
      TEST_METHOD(ExportMenu)
      {
         RestaurantMenu * test = RestaurantMenu::ImportMenu("../../RestaurantManagementSystem/db.xml");

         remove("output.xml");

         RestaurantMenu::ExportMenu("output.xml", test);
      }

      /// <summary>
      /// Tests exporting the menu when the file already exists.
      /// </summary>
      TEST_METHOD(ExportMenuOverwrite)
      {
         RestaurantMenu * test = RestaurantMenu::ImportMenu("../../RestaurantManagementSystem/db.xml");
         
         remove("output.xml");

         RestaurantMenu::ExportMenu("output.xml", test);

         RestaurantMenu::ExportMenu("output.xml", test);
      }

      /// <summary>
      /// Tests that a category is removed from a menu.
      /// </summary>
      TEST_METHOD(RemoveCategory)
      {
         RestaurantMenu * test = new RestaurantMenu();

         Assert::IsTrue(test->numCategories() == 0);

         test->AddCategory(new MenuCategory(new string("TestCategory")));

         Assert::IsFalse(test->numCategories() == 0);

         test->RemoveCategory(*test->FirstCategory());

         Assert::IsTrue(test->numCategories() == 0);
      }

      /// <summary>
      /// Tests that numCategories works.
      /// </summary>
      TEST_METHOD(NumCategoriesTest)
      {
         RestaurantMenu * test = new RestaurantMenu();

         Assert::IsTrue(test->numCategories() == 0);

         test->AddCategory(new MenuCategory(new string("TestCategory")));

         Assert::IsFalse(test->numCategories() == 0);

         test->RemoveCategory(*test->FirstCategory());

         Assert::IsTrue(test->numCategories() == 0);
      }

      /// <summary>
      /// Tests that category count works.
      /// </summary>
      TEST_METHOD(CategoryCountTest)
      {
         RestaurantMenu * test = new RestaurantMenu();

         Assert::IsTrue(test->CategoryCount() == 0);

         test->AddCategory(new MenuCategory(new string("TestCategory")));

         Assert::IsFalse(test->CategoryCount() == 0);

         test->RemoveCategory(*test->FirstCategory());

         Assert::IsTrue(test->CategoryCount() == 0);
      }



	};
}