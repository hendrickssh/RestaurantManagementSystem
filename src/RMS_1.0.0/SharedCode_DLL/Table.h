//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Table object.
//---------------------------------------------------------------------

#pragma once

#include "stdafx.h"

#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif  

//#include "WaitStaff.h"
#include <string>
#include "Reservation.h"

namespace SharedCode
{
   using namespace std;
   class SHAREDCODE_API Table
   {
   public:
      Table();
      Table(int id);
      Table(int id, int cap);
      ~Table();

      /// <summary>
      /// Returns the table number
      /// </summary>
      /// <returns>tableNum</returns>
      int GetTableNum();

      /// <summary>
      /// Get the current capactiy of the table.
      /// </summary>
      /// <returns>The capacity of the table (number of chairs).</returns>
      int Capacity();

      /// <summary>
      /// Returns if the Table is vacant.
      /// </summary>
      /// <returns>True if vacant, false if not.</returns>
      bool Vacant() { return this->vacant; }

      /// <summary>
      /// Updates the current reservation
      /// </summary>
      /// <param name="res">The new Reservation for the Table.</param>
      /// <returns>If the update was sucessful</returns>
      bool UpdateReservation(Reservation * res);

      /// <summary>
      /// Returns this Tables Reservation
      /// </summary>
      /// <returns>A char* representation of the Reservation</returns>
      char * GetReservationTime();

      /// <summary>
      /// Returns the reservation holders name.
      /// </summary>
      /// <returns>A char* of Reservation->name</returns>
      char * ReservationName();

      /// <summary>
      /// Reservation associated with the table.
      /// </summary>
      Reservation * reservation;

      /// <summary>
      /// Removes the reservation.
      /// </summary>
      void RemoveReservation();

      /// <summary>
      /// returns an int that represents order ID
      /// <returns> orderID </returns>
      /// </summary>
      int OrderID() { return orderID; }

      /// <summary>
      /// updates order id
      /// <param name="id">new order id</param>
      /// </summary>
      void UpdateOrderID(int id) { orderID = id; }

   private:
      /// <summary>
      /// Table ID
      /// </summary>
      int tableNum;

      /// <summary>
      /// Number of seats at table
      /// </summary>
      int capacity;

      /// <summary>
      /// Is the table vacent?
      /// </summary>
      bool vacant;

      ///<summary>
      /// ID of order associated with the table
      ///</summary>
      int orderID;
      
      /// <summary>
      /// Watier assigned to table
      /// </summary>
      //WaitStaff * waitron;

      

      
   };
}