//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Order object, holds vector of order items, order id, order state,
//    and order cost.
//---------------------------------------------------------------------
#pragma once

#include "stdafx.h"
#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif 

#include <string>

#include "Table.h"
#include "OrderItem.h"

using namespace std;

namespace SharedCode
{
   using namespace std;
   class SHAREDCODE_API Order
   {
   public: enum ORDER_STATES
   {
      completed,
      notcompleted
   };

   public:

      /// <summary>
      /// Vector of order item pointers
      /// </summary>
      typedef vector <OrderItem*> OrderItemContainer;

      /// <summary>
      /// Iterator for the order items.
      /// </summary>
      typedef OrderItemContainer::iterator OrderItemIterator;

      /// <summary>
      /// The Default contstructor of an order item.
      /// </summary>
      Order();

      /// <summary>
      /// Creates an order item based on user 
      /// submitted information.
      /// </summary>
      /// <param name="id">The idnumber as an int</param>
      Order(int id);

      /// <summary>
      /// Deconstructor, deletes the order and table 
      /// associated with the order.
      /// </summary>
      ~Order();

      /// <summary>
      /// Returns the ID of the order.
      /// </summary>
      /// <returns>Int representation of the order.</returns>
      int   GetID();

      /// <summary>
      /// Retruns the order state of this order.
      /// </summary>
      /// <returns>The order state</returns>
      bool GetOrderState();

      /// <summary>
      /// Sets the order state of this order
      /// </summary>
      /// <param name="complete">A boolean representation of the orders state.</param>
      void SetOrderState(bool complete);

	  /// <summary>
	  /// Adds an order item to the order.
	  /// </summary>
	  /// <param name="item">The order item to add.</param>
	  void AddItem(OrderItem * item);

	  /// <summary>
	  /// Removes an order item from an order.
	  /// </summary>
	  /// <param name="item">The order item to remove.</param>
	  void RemoveItem(OrderItem *& item);
	  
	  /// <summary>
	  /// Returns a constant vector of all the order items. 
	  /// </summary>
	  /// <returns>Constant vector of all the order items.</returns>
	  const OrderItemContainer * Items();

	  /// <summary>
	  /// Clears all of the order items from the order.
	  /// </summary>
	  void ClearItems();

      /// <summary>
      /// Retruns the order total.
      /// </summary>
      /// <returns>The numerical value of an order.</returns>
      double GetTotalOrderCost();

      /// <summary>
      /// An enum defining what state the order is currently in.
      /// </summary>
      ORDER_STATES status;


   private:
      /// <summary>
      /// ID of the current order
      /// </summary>
      int orderID;

      /// <summary>
      /// Searches a vector of items for a particular order item.
      /// </summary>
      OrderItemContainer items;
   };
}
