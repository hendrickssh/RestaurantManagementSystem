//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Reservation object.
//---------------------------------------------------------------------

#pragma once
#include "stdafx.h"

#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif 

#include <string>
#include <locale>
namespace SharedCode
{
   using namespace std;
   class SHAREDCODE_API Reservation
   {
   public:
      /// <summary>
      /// Default Constructor for Reservation.
      /// </summary>
      Reservation() { name = "test"; charTime = "00:00"; }

      Reservation(char * user, char * t,bool isres);

      /// <summary>
      /// Destructor for Reservation.
      /// </summary>
      ~Reservation();
      
      /// <summary>
      /// Returns the name on the reservation.
      /// </summary>
      /// <returns>name</returns>
      char * Name();

      /// <summary>
      /// Returns the time on the reservation.
      /// </summary>
      /// <returns>charTime</returns>
      char * Time();

      bool IsReservation();

   private:
      /// <summary>
      /// char* representation of the time_t time
      /// </summary>
      char * charTime;

      /// <summary>
      /// Name Associated with this Reservation.
      /// </summary>
      char * name;

      bool isReservation;
      
   };
}
