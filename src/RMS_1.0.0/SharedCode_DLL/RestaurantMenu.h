//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Restaurant menu object
//---------------------------------------------------------------------

#pragma once

#include "stdafx.h"

#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif 

#include <vector>
#include <string.h>

#include "MenuCategory.h"

using namespace std;

namespace SharedCode
{
   class SHAREDCODE_API RestaurantMenu
   {
   public:

      /// <summary>
      /// Typedef for the container of Menu categories.
      /// </summary>
      typedef vector<MenuCategory*> CategoryContainer;

      /// <summary>
      /// Iterator type for the CategoryContainer
      /// </summary>
      typedef CategoryContainer::const_iterator CategoryIterator;

	  /// <summary>
	  /// Import a Restaurant menu from the given XML file.
	  /// </summary>
	  /// <param name="filePath">Local path to the menu to import.</param>
	  /// <returns>The imported menu</returns>
	  static RestaurantMenu * ImportMenu(string filePath);

	  /// <summary>
	  /// Export a Restaurant menu to a given XML file path.
	  /// </summary>
	  /// <param name="filePath">Local path to export to.</param>
	  /// <param name="menu">The menu to export.</param>
	  /// <returns>True/False if the export succeeds/fails</returns>
	  static void ExportMenu(string filePath, RestaurantMenu * menu);
	  
      /// <summary>
      /// Creates a new restaurant menu object which does not have any categories.
      /// </summary>
      RestaurantMenu();

      /// <summary>
      /// Destructs a Restaurant Menu.
      /// </summary>
      ~RestaurantMenu();

      /// <summary>
      /// Add a category to the RestaurantMenu.
      /// The Restauarant Menu will then be responsible for deleting the 
      /// category object when it is no longer needed. The categories
      /// should only be deleted via the RestaurantMenu object and no
      /// category should be shared (by reference) between two menu objects.
      /// </summary>
      /// <param name="category">The category to add to the menu.</param>
      void AddCategory(MenuCategory * category);

      /// <summary>
      /// Get a category by name.
      /// </summary>
      /// <param name="name">Name of the category to get.</param>
      /// <returns>Null if the category isn't found, Reference to the 
      /// category object if it is found.</returns>
      MenuCategory * FindCategory(string name);

      /// <summary>
      /// Find a category based off of a skeleton cateogory object.
      /// </summary>
      /// <param name="skeletonCategory">The skeleton cateogry containing the necessary info to match the categories.</param>
      /// <returns>The category object or null if it's not found.</returns>
      MenuCategory * FindCategory(MenuCategory * skeletonCategory);

	  /// <summary>
	  /// Removes a given category from the Restaurant Menu.
	  /// </summary>
	  /// <param name="categoryToRemove">Category to remove.</param>
	  void RemoveCategory(MenuCategory * categoryToRemove);

	  /// <summary>
	  /// Get an iterator the Categories list.
	  /// </summary>
	  /// <returns>Constant iterator the list of menu categories.</returns>
	  CategoryIterator FirstCategory();

	  /// <summary>
	  /// Get an iterator the Categories list.
	  /// </summary>
	  /// <returns>Constant iterator the list of menu categories.</returns>
	  CategoryIterator LastCategory();

	  /// <summary>
	  /// Gets the number of menu categories in the current menu.
	  /// </summary>
	  /// <returns>Number of categories.</returns>
	  int CategoryCount();

      /// <summary>
      /// Returns true if the Restaurant Menu contains a category which meets
      /// the equivalence criteria for categories.
      /// </summary>
      /// <param name="skeletonCategory">The skeleton category to check for.</param>
      /// <returns>True if the menu has the skeleton category, false if not.</returns>
      bool HasCategory(MenuCategory * skeletonCategory);

      /// <summary>
      /// Returns a Recipe object if one is found that matches the given recipe name.
      /// </summary>
      /// <param name="recipeName">The name of the recipe to search for.</param>
      /// <returns>A Recipe object if found, nullptr if not.</returns>
      Recipe * FindRecipe(string recipeName);

      /// <summary>
      /// Searches the whole Restaurant Menu for a recipe which meets the 
      /// equivalence criteria for recipes. 
      /// </summary>
      /// <param name="skeletonRecipe">The recipe to search for.</param>
      /// <returns>A pointer to the recipe object if found, nullptr if not.</returns>
      Recipe * FindRecipe(Recipe * skeletonRecipe);

      /// <summary>
      /// Returns the number of categories in the menu
      /// </summary>
      /// <returns>Size of the Category vector.</returns>
      int numCategories();

   private:
      /// <summary>
      /// Contains the categories for the restaurant menu.
      /// </summary>
      CategoryContainer * categories;
   };

}