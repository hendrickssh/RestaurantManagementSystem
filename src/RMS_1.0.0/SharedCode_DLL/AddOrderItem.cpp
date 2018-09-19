#include "stdafx.h"
#include "AddOrderItem.h"

SharedCode::AddOrderItem::AddOrderItem(Order * order, OrderItem * orderItem)
{
    this->orderState = order;
    this->item = orderItem;
    executed = false;
}

SharedCode::AddOrderItem::~AddOrderItem()
{
   if(!executed)
      delete this->item;
}

void SharedCode::AddOrderItem::Execute()
{
   if(!this->executed)
      this->orderState->AddItem(item);
   this->executed = true;
}

void SharedCode::AddOrderItem::Revert()
{
   if(this->executed)
      this->orderState->RemoveItem(this->item);
   this->executed = false;
}