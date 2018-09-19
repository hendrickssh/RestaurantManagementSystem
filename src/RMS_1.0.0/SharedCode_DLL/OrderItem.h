//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Order Item.
//---------------------------------------------------------------------

#pragma once

#include "stdafx.h"
#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif 

#include <string>

#include "Recipe.h"

using namespace std;

namespace SharedCode
{
   using namespace std;
   class SHAREDCODE_API OrderItem
   {
   public:
      OrderItem();

      /// <summary>
      /// Creates a new order item. The order item will "own" the customizations
      /// string and delete it when it is deleted. The recipe should be a pointer
      /// from the restaurant menu, it will be used to provide the name .
      /// </summary>
      /// <param name="item">A string with the name of a specific item.</param>
	  OrderItem(Recipe * recipe);

      /// <summary>
      /// Deletes the customizations string so we don't have memory leaks.
      /// </summary>
      ~OrderItem();

      /// <summary>
      /// Returns the customization string for the OrderItem. 
      /// 
      /// This is still owned by the OrderItem so do not delete the string, it 
      /// will be deleted when the OrderItem is deleted. 
      /// </summary>
      /// <returns>String containing all the customizations.</returns>
	  vector <string*> * GetCustomizations();

      /// <summary>
      /// Returns a string representation of the order items name.
      /// </summary>
      /// <returns>A string representation of the order item.</returns>
      Recipe * GetRecipe();

      /// <summary>
      /// Adds a custimization option selected from the order item.
      /// </summary>
      void AddCustomization(string * customization);

      /// <summary>
      /// Removes a custimization option selected from the order item.
      /// </summary>
      void RemoveCustomization( string * customization );

	  float GetPrice();

   private:
      /// <summary>
      /// A string containing a list of customizations for the order.
      /// </summary>
      
      vector <string*> * customizations;

	  /// <summary>
	  /// The recipe for the order item.
	  /// </summary>
	  Recipe * recipe;
   };
}

