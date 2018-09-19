#include "ReservationController.h"

bool SharedCode::ReservationController::RemoveReservation(char * guestName)
{
   for (int i = 0; i < resList->size(); i++)
   {
      if (*guestName == *GetReservationAt(i)->Name())
      {
         resList->erase(resList->begin() + i);
         numReservations--;
         return true;
      }
   }
   return false;
}

SharedCode::Reservation * SharedCode::ReservationController::CreateReservation(char * name, char * time,bool isReservation)
{
   Reservation * temp = new Reservation(name, time,isReservation);
   resList->push_back(temp);
   numReservations++;
   return temp;
}

SharedCode::Reservation * SharedCode::ReservationController::CreateReservation()
{
   resList->push_back(new Reservation("","",true));
   numReservations++;
   return resList->back();
}

int SharedCode::ReservationController::NumReservations()
{
   return numReservations;
}

SharedCode::Reservation * SharedCode::ReservationController::GetReservationAt(int index)
{
   return resList->at(index);
}

SharedCode::Reservation * SharedCode::ReservationController::GetReservation(char * guestName)
{
   for (int i = 0; i < resList->size(); i++)
   {
      if (*guestName == *GetReservationAt(i)->Name())
      {
         return GetReservationAt(i);
      }
   }
   return nullptr;
}

SharedCode::ReservationController::~ReservationController()
{
   for (int i = 0; i < resList->size(); i++)
   {
      delete resList->at(i);
   }
   delete resList;
}
