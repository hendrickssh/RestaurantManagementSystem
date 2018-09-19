//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Menu Category object. Holds recipe objects.
//---------------------------------------------------------------------

#pragma once

#include "stdafx.h"

#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif 

#include <vector>
#include <string>

#include "Recipe.h"

using namespace std;

namespace SharedCode
{
   using namespace std;

   /// <summary>
   /// Represents a Category of menu items. 
   /// Such as Sandwiches, Wraps, Fish, etc.
   /// </summary>
   class SHAREDCODE_API MenuCategory
   {
   public:

      /// <summary>
      /// A container to hold all of the recipes in the cateogry.
      /// </summary>
      typedef vector<Recipe*> RecipeContainer;

      /// <summary>
      /// An iterator to the RecipeContainer.
      /// </summary>
      typedef RecipeContainer::const_iterator RecipeIterator;

      /// <summary>
      /// Creates a new menu category with a blank name.
      /// </summary>
      MenuCategory();

      /// <summary>
      /// Creats a new menu category with the srtring as it's name.
      /// </summary>
      /// <param name="name">The name to give the category.</param>
      MenuCategory(string name);

      /// <summary>
      /// Creates a menu category with the given name.
      /// </summary>
      /// <param name="name">The name of the category to create. 
      /// The category will own this string object and will delete it once it 
      /// is no longer needed.</param>
      MenuCategory(string * name);

      /// <summary>
      /// Destructs a MenuCategory.
      /// </summary>
      ~MenuCategory();

	  /// <summary>
	  /// Returns the Name of the Restaurant Category.
	  /// </summary>
	  /// <returns>String containing the name of the Restaurant Category</returns>
	  string * Name();

	  /// <summary>
	  /// Returns the Name of the Restaurant Category.
	  /// </summary>
	  /// <returns>String containing the name of the Restaurant Category</returns>
	  void Name(string * name);

	  /// <summary>
	  /// Returns an iterator to the list of Recipes that are in this category.
	  /// </summary>
	  /// <returns>Constant iterator to the beginning of the recipes.</returns>
	  RecipeIterator FirstRecipe();

	  /// <summary>
	  /// Returns an iterator to the list of Recipes that are in this category.
	  /// </summary>
	  /// <returns>Constant iterator to the beginning of the recipes.</returns>
	  RecipeIterator LastRecipe();

      /// <summary>
      /// Adds a recipe to the category. 
      /// The category will be responsible for deleting the recipe when it is 
      /// no longer needed.
      /// </summary>
      /// <param name="recipe">The recipe to add to the category.</param>
      void AddRecipe(Recipe * recipe);
      
	  void RemoveRecipe(Recipe * recipe);

      /// <summary>
      /// Uses the FindRecipe(Recipe * skeletonRecipe) function to find a 
      /// recipe by name.
      /// </summary>
      /// <param name="recipeName">Name of the recipe to search for.</param>
      /// <returns>The recipe object if it exists, nullptr if not.</returns>
      Recipe * FindRecipe(string recipeName);

      /// <summary>
      /// Searches for a recipe in this category which meets the equivalence
      /// criteria with the given skeleton recipe.
      /// </summary>
      /// <param name="skeletonRecipe">The skeleton recipe to use while searching.</param>
      /// <returns>The recipe if it is found in the category, nullptr if it isn't found</returns>
      Recipe * FindRecipe(Recipe * skeletonRecipe);

      /// <summary>
      /// Searches and sees if the current category has a recipe which meets
      /// the recipe equivalance critera for the sekelton recipe.
      /// </summary>
      /// <param name="skeletonRecipe">The skeleton recipe to match against the recipes in this category.</param>
      /// <returns>True if the category has the recipe, false if not.</returns>
      bool HasRecipe(Recipe * skeletonRecipe);
      
      /// <summary>
      /// Compares two menu categories by name.
      /// </summary>
      /// <param name="category">The category to compare to.</param>
      /// <returns>True if the names match, false if not.</returns>
      bool operator== (MenuCategory * category);

      /// <summary>
      /// Returns the number of recipes in the category
      /// </summary>
      /// <returns>Size of the recipes vector.</returns>
      size_t numRecipes() { return recipes->size(); }

   private:
      /// <summary>
      /// A pointer to the name of the category
      /// </summary>
      string * name;

      /// <summary>
      /// The recipes that are in the MenuCategory
      /// </summary>
      RecipeContainer * recipes;
   };
}

