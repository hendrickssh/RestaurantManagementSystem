//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Printer class. 
//---------------------------------------------------------------------

#pragma once

#include "stdafx.h"

#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif 

#include <string>
#include <direct.h>
#include <fstream>
#include <iostream>

using namespace std;

namespace SharedCode
{
   using namespace std;

   /// <summary>
   /// Printer class that allows for items to be printed.
   /// </summary>
   class SHAREDCODE_API Printer
   {
   public:

      /// <summary>
      /// Default constructor for the printer class. Does nothing.
      /// </summary>
      Printer() {}

      /// <summary>
      /// Deconstructor for the printer class. Does nothing.
      /// </summary>
      ~Printer() {}

      /// <summary>
      /// Process a Receipt to be printed and has it catalog digitally.
      /// </summary>
      /// <param name="id">The idnumber as an integer</param>
      /// <param name="str">Item to be printed as an std::string</param>
      /// <returns>True if the receipt printed sucessfully.</returns>
      bool CatalogDigitallyReceipt(string str, long int id);
   };
}

