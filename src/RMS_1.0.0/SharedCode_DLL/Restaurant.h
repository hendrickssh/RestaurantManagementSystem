//---------------------------------------------------------------------
// Name:    ++C
// Project: Restaurant Management System
// Purpose: Restaurant Object.
//---------------------------------------------------------------------

#pragma once

#ifdef SHAREDCODE_DLL_EXPORTS  
#define SHAREDCODE_API __declspec(dllexport)   
#else  
#define SHAREDCODE_API __declspec(dllimport)   
#endif  

#include "stdafx.h"
#include <string.h>
#include "TableController.h"
#include "ReservationController.h"
#include "OrderController.h"
#include "RestaurantMenu.h"

using namespace std;

namespace SharedCode
{
   /// <summary>
   /// Class which holds all data necessary to run a restaurant.
   /// </summary>
   class SHAREDCODE_API Restaurant
   {
   private:
      /// <summary>
      /// Static reference to an instance of a restaurnat. Each program using 
      /// this DLL should only be working with one restaurant instance at a
      /// time.
      /// </summary>
      static Restaurant* instance;
   public:

      /// <summary>
      /// Holds one Restaurant object per running instance of the management 
      /// system. This will be shared between all UI components.
      /// </summary>
      /// <returns>Look above...</returns>
      static SharedCode::Restaurant * GetRestaurant();

      /// <summary>
      /// Initializes all the restaurant controllers to manage the main restaurant
      /// functions.
      /// </summary>
      Restaurant();

      /// <summary>
      /// String to the location of the database file. 
      /// </summary>
      string * DatabaseLocation;

      /// <summary>
      /// Saves the current menu to the current database location.
      /// </summary>
      void SaveMenu();

      /// <summary>
      /// Loads the menu from the default location.
      /// </summary>
      void LoadMenu();

      /// <summary>
      /// Gets the current table controller. 
      /// </summary>
      /// <returns>Current table controller.</returns>
      TableController * getTableController();

      /// <summary>
      /// Gets the current order controller.
      /// </summary>
      /// <returns>The current order controller.</returns>
      OrderController * getOrderController();

      /// <summary>
      /// Gets the current reservation controller.
      /// </summary>
      /// <returns>The current reservation controller.</returns>
      ReservationController * getReservationController();

      /// <summary>
      /// Gets a reference to the current restaurant menu.
      /// </summary>
      /// <returns>The current restaurant menu</returns>
      RestaurantMenu * getRestaurantMenu();

      /// <summary>
      /// Deletes all restaurant data from memories.
      /// </summary>
      ~Restaurant();
   private:
      /// <summary>
      /// The name of the restaurant.
      /// </summary>
      string name;

      /// <summary>
      /// The address of the restaurant.
      /// </summary>
      string address;

      /// <summary>
      /// The Phone number of the restaurant.
      /// </summary>
      string phone;

      /// <summary>
      /// The main order controller, all orders for the restaurant will reside in here. 
      /// </summary>
      OrderController * orderController;

      /// <summary>
      /// The main order controller, all orders for the restaurant will reside in here. 
      /// </summary>
      OrderController * drinkController;

      /// <summary>
      /// This holds a the restaurant's menu, which contains cateogires, which 
      /// contain the actual recipes for the restaurant. 
      /// </summary>
      RestaurantMenu * restaurantMenu;

      /// <summary>
      /// The main table controller, all table for the restaurant will reside in here. 
      /// </summary>
      TableController * tableController;

      /// <summary>
      /// The main time clock controller, this will be used for employee clock-in
      /// and employee clock-out.
      /// </summary>
      //TimeClockController * timeClockController;

      /// <summary>
      /// The main reservation controller, this will be used to store reservations.
      /// </summary>
      ReservationController * reservationController;

   };
}
