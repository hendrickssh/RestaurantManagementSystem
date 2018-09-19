#include "stdafx.h"
#include "CppUnitTest.h"
#include "string.h"

#include "Recipe.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SharedCode;

namespace SharedCodeTests
{
	TEST_CLASS(RecipeTest)
	{
	public:
      /// <summary>
      /// A test to create a recipe by a string.
      /// </summary>
		TEST_METHOD(ConstructByStringObject)
		{
			Recipe * recipe = new Recipe("RecipeName");
			Assert::IsTrue(*recipe->Name() == "RecipeName");
			delete recipe;
		}

      /// <summary>
      /// A test to create a recipe by a *string
      /// </summary>
		TEST_METHOD(ConstructByStringPointer)
		{
			string * recipeName = new string("RecipeName");
			Recipe * recipe = new Recipe(recipeName);
			Assert::IsTrue(*recipe->Name() == "RecipeName");
			delete recipe;
		}

      /// <summary>
      /// A test to create a full recipe.
      /// </summary>
		TEST_METHOD(ConstructFullRecipe)
		{
			string * recipeName = new string("RecipeName");
			string * recipeDesc = new string("This is a recipe description, yo.");
			float recipePrice = (float)17.38;

			Recipe * recipe = new Recipe(recipeName, recipePrice, recipeDesc);

			Assert::IsTrue(*recipe->Name() == *recipeName);

			Assert::IsTrue(*recipe->Description() == *recipeDesc);

			Assert::AreEqual(recipe->Price(), recipePrice);

			delete recipe;
		}

      /// <summary>
      /// A test to check two recipes are equivalent.
      /// </summary>
		TEST_METHOD(CheckEquivalence)
		{

			string * recipeName = new string("RecipeName");
			string * recipeDesc = new string("This is a recipe description, yo.");
			float recipePrice = (float)17.38;

			Recipe * recipe1 = new Recipe(recipeName, recipePrice, recipeDesc);
			Recipe * recipe2 = new Recipe(recipeName, recipePrice, recipeDesc);

			Assert::IsTrue(*recipe1 == *recipe2);

			Assert::IsTrue(*recipe1 == recipe2);
		}

      /// <summary>
      /// A test to default a recipe
      /// </summary>
      TEST_METHOD(DefaultRecipeTest)
      {
         Recipe * recipe = new Recipe();
         Assert::IsNotNull(recipe);
      }

      /// <summary>
      /// A test to change a recipe name.
      /// </summary>
      TEST_METHOD(ChangeRecipeNameTest)
      {
         Recipe * recipe = new Recipe();
         recipe->Name(new string("newName"));
         string name = *(recipe->Name());
         Assert::AreEqual(name.c_str(), "newName");
      }

      /// <summary>
      /// A test to change a recipe description.
      /// </summary>
      TEST_METHOD(ChangeRecipeDescriptionTest)
      {
         Recipe * recipe = new Recipe();
         recipe->Description(new string("newDes"));
         string name = *(recipe->Description());
         Assert::AreEqual(name.c_str(), "newDes");
      }

      /// <summary>
      /// A test to ensure the price is updated.
      /// </summary>
      TEST_METHOD(ChangeRecipePriceTest)
      {
         Recipe * recipe = new Recipe();
         recipe->Price(2.2);
         bool priceSame = (recipe->Price() > 0);
         Assert::IsTrue(priceSame);
      }

      /// <summary>
      /// A test for the destructor
      /// </summary>
      TEST_METHOD(DestructorTest)
      {
         Recipe * recipe = new Recipe();
         delete recipe;
      }
	};
}