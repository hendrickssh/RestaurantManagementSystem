#include "stdafx.h"
#include "RemoveOrderItem.h"

SharedCode::RemoveOrderItem::RemoveOrderItem(Order * order, OrderItem * orderItem)
{
	this->orderState = order;
   this->item = orderItem;
   executed = false;
}

void SharedCode::RemoveOrderItem::Execute()
{
   if(!executed)
	   this->orderState->RemoveItem(item);
   executed = true;
}

void SharedCode::RemoveOrderItem::Revert()
{
   if(executed)
	   this->orderState->AddItem(item);
   executed = false;
}

SharedCode::RemoveOrderItem::~RemoveOrderItem()
{
   if(executed)
	   delete this->item;
}
