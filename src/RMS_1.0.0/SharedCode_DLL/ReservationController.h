//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Reservation Controller
//---------------------------------------------------------------------

#pragma once

#include "stdafx.h"
#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif 

#include "Reservation.h"
#include <vector>

namespace SharedCode
{
   using namespace std;

   typedef vector<Reservation*> ReservationContainer;

   class SHAREDCODE_API ReservationController
   {
   public:
      /// <summary>
      /// Default Constructor
      /// </summary>
      ReservationController() { resList = new ReservationContainer(); numReservations = 0; }

      /// <summary>
      /// Destructor for ReservationController
      /// </summary>
      ~ReservationController();

      /// <summary>
      /// Removes a Reservation from the list
      /// </summary>
      /// <param name="res">Reservation name</param>
      /// <returns>If it was removed</returns>
      bool RemoveReservation(char * guestName);

      /// <summary>
      /// Adds a reservation to the list
      /// </summary>
      /// <param name="name">String of guest name</param>
      /// <param name="time">String of time</param>
      /// <returns>The created object</returns>
      Reservation * CreateReservation(char * name, char * time,bool isres);

      /// <summary>
      /// Adds a generic Reservation
      /// </summary>
      /// <returns>The created Object</returns>
      Reservation * CreateReservation();

      /// <summary>
      /// Returns the number of Reservations
      /// </summary>
      /// <returns>int number of Reservations</returns>
      int NumReservations();

      /// <summary>
      /// Returns a reservation at the index
      /// </summary>
      /// <param name="index">the index in resList</param>
      /// <returns>The reservation at index</returns>
      Reservation * GetReservationAt(int index);

      Reservation * GetReservation(char * guestName);
   private:
      /// <summary>
      /// List of the Reservations
      /// </summary>
      ReservationContainer * resList;

      int numReservations;
   };
}