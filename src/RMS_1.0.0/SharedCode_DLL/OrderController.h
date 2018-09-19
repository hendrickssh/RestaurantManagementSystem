//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Order Controller.
//---------------------------------------------------------------------

#pragma once

#pragma warning( disable : 4251 )

#include "stdafx.h"
#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif 

#include "Order.h"
#include "OrderCommand.h"

#include <vector>
#include <stack>

namespace SharedCode
{
   using namespace std;

   /// <summary>
   /// A controller which is used to manage the orders currently open or closed
   /// in the restaurant. 
   /// </summary>
   class SHAREDCODE_API OrderController
   {   
   public:

      /// <summary>
      /// Container class to hold orders.
      /// </summary>
      typedef vector<Order*> OrderContainer;

      /// <summary>
      /// Stack container to hold OrderCommands
      /// </summary>
      typedef stack<OrderCommand*> OrderCommandStack;

      ///<summary>
      ///  Default constructor for a OrderController object.
      ///</summary>
	   OrderController() {};

      ///<summary>
      /// Delete method.
      ///</summary>
      ~OrderController();

      /// <summary>
      /// Deletes the order if it is found in the order controller. The function
      /// will return true if the order is deleted, and the order parameter that
      /// is passed in will be set to null. 
      /// </summary>
      /// <param name="order">The order to delete from the order controller.</param>
      /// <returns>True if order is deleted, false if not.</returns>
      bool DeleteOrder(Order *& order);

      ///<summary>
      /// Marks an order complete.
      ///</summary>
      ///<param name="order">The order to mark complete</param>
      void CompleteOrder(Order * order);

	  /// <summary>
	  /// Creates a blank order to manipulate.
	  /// </summary>
	  /// <returns></returns>
      Order * CreateOrder();



      /// <summary>
      /// Used to get the entire list of orders
      /// </summary>
      /// <returns>The list of all tables.</returns>
      OrderContainer getOrders();

      /// <summary>
      /// gets order at index
      /// </summary>
      Order * OrderAt(int i);

      Order * OrderWithID(int orderID);

	  /// <summary>
	  /// Executes the given command and adds it to the undo/redo stack.
	  /// </summary>
	  /// <param name="command">An OrderCommand to execute.</param>
	  void ExecuteCommand(OrderCommand * command);

	  /// <summary>
	  /// Undoes the command at the top of the undo stack.
	  /// </summary>
	  void UndoCommand();

	  /// <summary>
	  /// Redoes the command at the top of the redo stack.
	  /// </summary>
	  void RedoCommand();



   private:
      /// <summary>
      /// A vector to hold all the orders
      /// </summary>
      OrderContainer orderList;

      /// <summary>
      /// Gets the order id for the new order
      /// </summary>
      /// <returns>New order id</returns>
      int GetNextID();

      /// <summary>
      /// The number of orders.
      /// </summary>
      int numOrders;

	  /// <summary>
	  /// The stack to hold all the executed order commands.
	  /// </summary>
	  OrderCommandStack executedCommands;

	  /// <summary>
	  /// The stack to hold all of the reverted order commands.
	  /// </summary>
	  OrderCommandStack revertedCommands;
   };
}