//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Receipt object.
//---------------------------------------------------------------------

#pragma once

#pragma warning( disable : 4251 )

#include "stdafx.h"

#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif

#include <string>
#include <sstream>
#include <iomanip>
#include "Order.h"
using namespace std;

namespace SharedCode
{
   using namespace std;
   class SHAREDCODE_API Receipt
   {
   public:
      /// <summary>
      /// Default constructor for a receipt object.
      /// </summary>
      Receipt() {}

      /// <summary>
      /// Deconstructor for a receipt object.
      /// </summary>
      ~Receipt() {}

      /// <summary>
      /// Calculates the tips for a bill.
      /// <param name="cost">Value to apply tips.</param>
      /// <returns>A formatted std::string of the tip values.</returns>
      /// </summary>
      string CalculateTips(double cost);

      /// <summary>
      /// Formats a receipt.
      /// <param name="order">Order object to be formatted.</param>
      /// <returns>A std::string of a formatted receipt.</returns>
      /// </summary>
      string FormatReceipt(Order * order);


   private:
      const double TAX = 1.05;
      const double P_SERVICE_TIPERCENT = 1.1;
      const double G_SERVICE_TIPERCENT = 1.15;
      const double E_SERVICE_TIPERCENT = 1.2;

      /// <summary>
      /// Returns a numerical double value of a 10% tip.
      /// <param name="cost">Value to apply tip.</param>
      /// <returns>Double value of a value applied with the tip value.</returns>
      /// </summary>
      double PoorServiceTip(double cost) { return cost * P_SERVICE_TIPERCENT; }

      /// <summary>
      /// Returns a numerical double value of a 15% tip.
      /// <param name="cost">Value to apply tip.</param>
      /// <returns>Double value of a value applied with the tip value.</returns>
      /// </summary>
      double GoodServiceTip(double cost) { return cost * G_SERVICE_TIPERCENT; }

      /// <summary>
      /// Returns a numerical double value of a 20% tip.
      /// <param name="cost">Value to apply tip.</param>
      /// <returns>Double value of a value applied with the tip value.</returns>
      /// </summary>
      double ExcellentServiceTip(double cost) { return cost * E_SERVICE_TIPERCENT; }

      /// <summary>
      /// Converts a numerical double value into a std string.
      /// <param name="f">Converts a decimal value into a std::string</param>
      /// <returns>A std::string of a double value.</returns>
      /// </summary>
      string To_String_Bill(double f);

      /// <summary>
      /// Rounds a double numerical value.
      /// <param name="d">A decimal value to be rounded 
      /// to the nearest hundreth</param>
      /// <returns>A rounded double value to the nearest hundreth</returns>
      /// </summary>
      double RoundValue(double d);
   };
}