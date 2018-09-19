//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: UNDO/REDO, AddOrderItem command object
//---------------------------------------------------------------------
#pragma once

#include "stdafx.h"
#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif

#include "OrderCommand.h"
#include "OrderItem.h"

namespace SharedCode
{
	using namespace std;
	class SHAREDCODE_API AddOrderItem : public OrderCommand
	{
	public:

		/// <summary>
		/// Creates an AddOrderItem command object with the specified order and
		/// item to remove.
		/// </summary>
		/// <param name="order">The order to add the item to.</param>
		/// <param name="orderItem">The item to add to the order.</param>
		AddOrderItem(Order * order, OrderItem * orderItem);

      /// <summary>
      /// Deletes any local memory.
      /// </summary>
      ~AddOrderItem();

		/// <summary>
		/// Executes the command on the receiver.
		/// </summary>
		void Execute() override;

		/// <summary>
		/// Reverts the effects of the command on the receiver.s
		/// </summary>
		void Revert() override;

	private:
		OrderItem * item;
      bool executed;
	};
}