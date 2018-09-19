#include "stdafx.h"
#include <CppUnitTest.h>
#include <string.h>

#include "MenuCategory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(MenuCategoryTests)
   {
   public:
      
      TEST_METHOD(FindRecipeExists)
      {
         MenuCategory * testCategory = new MenuCategory();
         Recipe* testRecipe = new Recipe(new string("TestOne"), 17.38, new string("TestDescription"));
         Recipe* testser = new Recipe(new string("TestOne"), 0.00, nullptr);
         
         testCategory->AddRecipe(testRecipe);

         Recipe* result = testCategory->FindRecipe(testser);

         Assert::IsTrue(testRecipe == result);
      }

      TEST_METHOD(FindRecipeNotExists)
      {
         MenuCategory * testCategory = new MenuCategory();
         Recipe* testRecipe = new Recipe(new string("TestOne"), 17.38, new string("TestDescription"));
         Recipe* testser = new Recipe(new string("TestTwo"), 0.00, nullptr);

         testCategory->AddRecipe(testRecipe);

         Recipe* result = testCategory->FindRecipe(testser);

         Assert::IsTrue(nullptr == result);
      }

      TEST_METHOD(RemoveRecipeFound)
      {
         MenuCategory * testCategory = new MenuCategory();
         Recipe* testRecipe = new Recipe(new string("TestOne"), 17.38, new string("TestDescription"));
         testCategory->AddRecipe(testRecipe);

         Assert::IsTrue(testCategory->numRecipes() == 1);

         testCategory->RemoveRecipe(testRecipe);

         Assert::IsTrue(testCategory->numRecipes() == 0);
      }

      TEST_METHOD(RemoveRecipeNotFound)
      {
         MenuCategory * testCategory = new MenuCategory();
         Recipe* testRecipe = new Recipe(new string("TestOne"), 17.38, new string("TestDescription"));
         Recipe* testRecipeTwo = new Recipe(new string("TestTwo"), 17.38, new string("TestDescription"));
         testCategory->AddRecipe(testRecipe);

         Assert::IsTrue(testCategory->numRecipes() == 1);

         testCategory->RemoveRecipe(testRecipeTwo);

         Assert::IsTrue(testCategory->numRecipes() == 1);
      }

      TEST_METHOD(GetMenuCategoryName)
      {
         MenuCategory * testCategory = new MenuCategory("I like Testing");
         string * testString = new string("I like Testing");

         Assert::IsTrue(*testString == *testCategory->Name());
      }

   TEST_METHOD(SetMenuCategoryName)
   {
      MenuCategory * testCategory = new MenuCategory("I like Testing");
      string * testString = new string("I like Testing");

      Assert::IsTrue(*testString == *testCategory->Name());

      string * testRename = new string("I really like testing");

      testCategory->Name(new string("I really like testing"));

      Assert::IsTrue(*testRename == *testCategory->Name());
   }
};
};