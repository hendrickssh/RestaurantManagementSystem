#pragma once

#include "stdafx.h"

#include "TableController.h"

SharedCode::TableController::~TableController()
{
   for (int i = 0; i < numTables; i++)
      delete tables.at(i);
}

bool SharedCode::TableController::SeatTable(SharedCode::Table * table, SharedCode::Reservation * reservation)
{
   return table->UpdateReservation(reservation);
}


SharedCode::Table * SharedCode::TableController::GetTable(int i)
{
   return tables.at(i);
}

SharedCode::Table * SharedCode::TableController::CreateTable()
{
   numTables++;
   SharedCode::Table * temp = new SharedCode::Table(numTables);
   tables.push_back(temp);
   return temp;
}

SharedCode::Table * SharedCode::TableController::CreateTable(int cap)
{
   numTables++;
   SharedCode::Table * temp = new SharedCode::Table(numTables,cap);
   tables.push_back(temp);
   return temp;
}

SharedCode::Table * SharedCode::TableController::TableWithOrderID(int orderID)
{
   for (int i = 0; i < tables.size(); i++)
   {
      if (tables.at(i)->OrderID() == orderID)
         return tables.at(i);
   }
   return nullptr;
}

SharedCode::TableContainer SharedCode::TableController::getTables()
{
   return this->tables;
}
