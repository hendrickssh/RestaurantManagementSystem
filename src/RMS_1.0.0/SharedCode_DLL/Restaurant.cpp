#pragma once
#include "stdafx.h"

#include "Restaurant.h"
#include "RestaurantMenu.h"

SharedCode::TableController * SharedCode::Restaurant::getTableController()
{
   return this->tableController;
}

SharedCode::OrderController * SharedCode::Restaurant::getOrderController()
{
	return this->orderController;
}

SharedCode::RestaurantMenu * SharedCode::Restaurant::getRestaurantMenu()
{
	return this->restaurantMenu;
}

SharedCode::Restaurant::Restaurant()
{
	this->DatabaseLocation = new string("db.xml");

   this->restaurantMenu = new RestaurantMenu();   
	this->orderController = new OrderController();

	this->restaurantMenu = RestaurantMenu::ImportMenu(*this->DatabaseLocation);
	if (this->restaurantMenu == nullptr)
	{
		this->restaurantMenu = new RestaurantMenu();
		RestaurantMenu::ExportMenu(*this->DatabaseLocation, this->restaurantMenu);
	}

   this->drinkController = new OrderController();

   this->reservationController = new ReservationController();

   //this->restaurantMenu = new RestaurantMenu();

   this->tableController = new TableController();

  

   this->reservationController = new ReservationController();

   //this->timeClockController = new TimeClockController();

   //tableController->CreateTable();
}

void SharedCode::Restaurant::SaveMenu()
{
	RestaurantMenu::ExportMenu(*this->DatabaseLocation, this->restaurantMenu);
}

void SharedCode::Restaurant::LoadMenu()
{
   this->restaurantMenu = RestaurantMenu::ImportMenu(*this->DatabaseLocation);
}

SharedCode::ReservationController * SharedCode::Restaurant::getReservationController()
{
	return this->reservationController;
}

SharedCode::Restaurant * SharedCode::Restaurant::GetRestaurant()
{
		static Restaurant * const instance = new Restaurant();
		return instance;
}

SharedCode::Restaurant::~Restaurant()
{
   delete this->orderController;
   //delete this->restaurantMenu;
   delete this->tableController;
   delete this->reservationController;
}