//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: UNDO/REDO, Order command object
//---------------------------------------------------------------------

#pragma once

#include "stdafx.h"
#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif

#include "Command.h"
#include "Order.h"

namespace SharedCode
{
	class SHAREDCODE_API OrderCommand : public Command
	{
	public:

		/// <summary>
		/// Executes the command on the receiver.
		/// </summary>
		virtual void Execute() = 0;

		/// <summary>
		/// Reverts the effects of the command on the receiver.s
		/// </summary>
		virtual void Revert() = 0;
	protected:
		Order * orderState;
	};
}