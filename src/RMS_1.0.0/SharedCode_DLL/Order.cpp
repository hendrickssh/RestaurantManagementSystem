#include "Order.h"

SharedCode::Order::Order()
{
}

SharedCode::Order::Order(int id)
{
   orderID = id; 
   status = notcompleted; 
}

SharedCode::Order::~Order()
{
   if (!this->items.empty())
   {
      for (int i = 0; i < this->items.size(); i++)
         delete this->items.at(i);

      this->items.clear();
   }
}

bool SharedCode::Order::GetOrderState()
{
   if (status == completed)
      return true;
   return false;
}

void SharedCode::Order::SetOrderState(bool complete)
{
   if (complete)
      status = completed;
   else
      status = notcompleted;
}

double SharedCode::Order::GetTotalOrderCost()
{
   double total = 0.0;
   for (int i = 0; i < items.size(); i++)
      total += items.at(i)->GetPrice();
   return total;
}

void SharedCode::Order::AddItem(OrderItem * item)
{
   this->items.push_back(item);
}

int SharedCode::Order::GetID()
{
   return orderID;
}

void SharedCode::Order::RemoveItem(OrderItem *& item)
{
   vector<OrderItem *>::iterator iterator = this->items.begin();

   vector<OrderItem*>::iterator found;

   for (iterator; iterator != this->items.end(); iterator++)
   {
      if ((*iterator) == item)
      {
         this->items.erase(iterator);
         break;
      }
   }
}

const vector<SharedCode::OrderItem*> * SharedCode::Order::Items()
{
   return &this->items;
}

void SharedCode::Order::ClearItems()
{
   if (!this->items.empty())
      for (int i = 0; i < this->items.size(); i++)
         delete this->items.at(i);

   this->items.clear();
}
