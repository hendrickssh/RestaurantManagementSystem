#pragma once

#include "stdafx.h"

#include "Table.h"

SharedCode::Table::Table()
{
   tableNum = -1;
   capacity = 0;
   vacant = true;
   orderID = -1;
   reservation = new Reservation();
}

SharedCode::Table::Table(int id)
{
   tableNum = id;
   capacity = 0;
   vacant = true;
   orderID = -1;
   reservation = new Reservation();
}

SharedCode::Table::Table(int id, int cap)
{
   tableNum = id;
   capacity = cap;
   vacant = true;
   orderID = -1;
   reservation = new Reservation();
}

SharedCode::Table::~Table()
{
}

int SharedCode::Table::GetTableNum()
{
   return tableNum;
}

int SharedCode::Table::Capacity()
{
   return this->capacity;
}

bool SharedCode::Table::UpdateReservation(Reservation * res)
{
   if (Vacant())
   {
      reservation = res;
      vacant = false;
      return true;
   }
   return false;
}

char * SharedCode::Table::GetReservationTime()
{
   return reservation->Time();
}

char * SharedCode::Table::ReservationName()
{
   return reservation->Name();
}

void SharedCode::Table::RemoveReservation()
{
   reservation = NULL;
   vacant = true;
}



