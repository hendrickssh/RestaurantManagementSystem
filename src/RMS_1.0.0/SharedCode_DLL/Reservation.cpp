#pragma once

#include "stdafx.h"

#include "Reservation.h"

SharedCode::Reservation::Reservation(char * user, char * t,bool isres)
{
   name = new char[sizeof(user)];
   charTime = new char[sizeof(t)];
   strcpy(name, user);
   strcpy(charTime, t);
   isReservation = isres;
}

SharedCode::Reservation::~Reservation()
{
   delete this->charTime;
   delete this->name;
}

char * SharedCode::Reservation::Name()
{
   return name;
}

char * SharedCode::Reservation::Time()
{
   return charTime;
}

bool SharedCode::Reservation::IsReservation()
{
   return isReservation;
}
