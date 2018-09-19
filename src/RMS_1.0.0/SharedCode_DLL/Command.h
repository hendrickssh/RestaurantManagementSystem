//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: UNDO/REDO, Abstract command object.
//---------------------------------------------------------------------

#pragma once

#include "stdafx.h"
#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif

namespace SharedCode
{
	class SHAREDCODE_API Command
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
	};
}