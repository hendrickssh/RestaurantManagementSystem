//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: UNDO/REDO, RemoveOrderItem command object
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
	class SHAREDCODE_API RemoveOrderItem : public OrderCommand
	{
	public:

		/// <summary>
		/// Creates a RemoveOrderItem command object with the specified order and
		/// item to remove.
		/// </summary>
		/// <param name="order">The order to delete the item from.</param>
		/// <param name="orderItem">The item to delete from the order.</param>
		RemoveOrderItem(Order * order, OrderItem * orderItem);

		/// <summary>
		/// Executes the command on the receiver.
		/// </summary>
		void Execute() override;

		/// <summary>
		/// Reverts the effects of the command on the receiver.s
		/// </summary>
		void Revert() override;

		/// <summary>
		/// Destroys the reference to item since we don't need it fam.
		/// </summary>
		~RemoveOrderItem();

	private:
		OrderItem * item;
      bool executed;
	};
}