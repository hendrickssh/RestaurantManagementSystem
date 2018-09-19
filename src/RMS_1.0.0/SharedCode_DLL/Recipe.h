//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Recipe object.
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

using namespace std;

namespace SharedCode
{
   using namespace std;
   class SHAREDCODE_API Recipe
   {
   public:

	   /// <summary>
	   /// Create a new Recipe object.
	   /// </summary>
	   Recipe();

      /// <summary>
      /// Createsa new recipe using a string value as it's name. 
      /// </summary>
      Recipe(string recipeName);

      /// <summary>
      /// Creates a recipe with the specified recipe name.
      /// </summary>
      Recipe(string * recipeName);

	  /// <summary>
	  /// Creates a recipe with the specified name, price, and description.
	  /// </summary>
	  Recipe(string * recipeName, float price, string * description);

      /// <summary>
      /// Destruct a recipe object.
      /// </summary>
      ~Recipe();

      /// <summary>
      /// Returns the pointer to the Recipe's name string.
      ///    /// This string is owned by the recipe and should not be deleted, 
      /// it will be deleted inside the destructor of Recipe.
      /// </summary>
      /// <returns>Pointer to the recipe's name string</returns>
      string * Name();

	  /// <summary>
	  /// Update the name of the recipe.
	  /// </summary>
	  /// <param name="newName">Pointer to the new name string</param>
	  void Name(string * newName);

	  /// <summary>
	  /// Gets the description of the recipe.
	  /// </summary>
	  /// <returns>String pointer to the description of the recipe.</returns>
	  string * Description();

	  /// <summary>
	  /// Sets the description of the recipe.
	  /// </summary>
	  /// <param name="newDescription">The new description for the recipe</param>
	  void Description(string * newDescription);

	  /// <summary>
	  /// Get the price of the recipe.
	  /// </summary>
	  /// <returns>The price of the recipe.</returns>
	  float Price();

	  /// <summary>
	  /// Sets the price of the recipe.
	  /// </summary>
	  /// <param name="newPrice">The new price for the recipe</param>
	  void Price(float newPrice);

      /// <summary>
      /// Compares two recipes and returns true if their names are equal.
      /// </summary>
      /// <param name="recipe">The recipe to compare to.</param>
      /// <returns>True if hte names match, false if not.</returns>
      bool operator==(Recipe * skeletonRecipe);
	  
	  /// <summary>
	  /// Compares two recipes and returns true if their names are equal.
	  /// </summary>
	  /// <param name="recipe">The recipe to compare to.</param>
	  /// <returns>True if hte names match, false if not.</returns>
	  bool operator==(const Recipe &skeletonRecipe);

   private:
      
      /// <summary>
      /// The name of the recipe.
      /// </summary>
      string * name;

      /// <summary>
      /// The price of the recipe.
      /// </summary>
      float price;
      
      /// <summary>
      /// The description of the recipe.
      /// </summary>
      string * description;
   };
}

