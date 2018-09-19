//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Table Controller.
//---------------------------------------------------------------------

#pragma once

#pragma warning (disable: 4251)

#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif  

#include "stdafx.h"
#include <string.h>
#include <vector>

#include "Reservation.h"
#include "Table.h"

using namespace std;


namespace SharedCode
{
   using namespace std;

   typedef vector<Table*> TableContainer;

   class SHAREDCODE_API TableController
   {
   public:
      /// <summary>
      /// Default Constructor for TableController Class
      /// </summary>
      TableController() { numTables = 0; };

      /// <summary>
      /// Destructor
      /// </summary>
      ~TableController();

      /// <summary>
      /// Marks the table as seated so no new parties can be seated there.
      /// </summary>
      /// <param name="table">The Table that is being marked as seated</param>
      /// <param name="reservation">The reservation on that table</param>
      /// <returns>If the table was seated or not</returns>
      bool SeatTable(Table * table, Reservation * reservation);

      /// <summary>
      /// Returns the table at the selected index
      /// </summary>
      /// <param name="i">The index of the table</param>
      /// <returns>The table object at index i</returns>
      Table * GetTable(int i);

      /// <summary>
      /// Creates a new table at the end of the TableController
      /// and increments numTables
      /// </summary>
      /// <returns>The table that was created</returns>
      Table* CreateTable();

      /// <summary>
      /// Creates a new table at the end of the TableController
      /// and increments numTables
      /// </summary>
      /// <param>The capacity of the table</param>
      /// <returns>The table that was created</returns>
      Table* CreateTable(int cap);

      Table* TableWithOrderID(int orderID);

      /// <summary>
      /// Used to get the entire list of tables
      /// </summary>
      /// <returns>The list of all tables.</returns>
      TableContainer getTables();

   private:
      /// <summary>
      /// The list of tables.
      /// </summary>
      TableContainer tables;

      /// <summary>
      /// The number of tables.
      /// </summary>
      int numTables;
   };

}
