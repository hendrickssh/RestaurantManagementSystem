#include "OrderController.h"

void SharedCode::OrderController::CompleteOrder(Order * order)
{
   order->status = Order::ORDER_STATES::completed;
}

int SharedCode::OrderController::GetNextID()
{
   return (int)(orderList.size() + 1);
}

bool SharedCode::OrderController::DeleteOrder(Order *& order)
{
   OrderContainer::iterator result;

   if (orderList.empty())
      return false;
   if ((result = std::find(orderList.begin(), orderList.end(), order)) == orderList.end())
      return false;
   orderList.erase(result);
   delete order;
   order = nullptr;
   return true;
}

SharedCode::Order * SharedCode::OrderController::CreateOrder()
{
   numOrders++;
   SharedCode::Order * temp = new SharedCode::Order(GetNextID());
   orderList.push_back(temp);
   return temp;
}

SharedCode::OrderController::OrderContainer SharedCode::OrderController::getOrders()
{
   return this->orderList;
}

SharedCode::Order * SharedCode::OrderController::OrderAt(int i)
{
   return this->orderList.at(i);
}

SharedCode::Order * SharedCode::OrderController::OrderWithID(int orderID)
{
	for (int i = 0; i < orderList.size(); i++)
	{
		if (this->orderList.at(i)->GetID() == orderID)
			return this->orderList.at(i);
	}
	return nullptr;
}

void SharedCode::OrderController::ExecuteCommand(OrderCommand * command)
{
	while (!revertedCommands.empty())
		revertedCommands.pop();

	command->Execute();

	executedCommands.push(command);
}

void SharedCode::OrderController::UndoCommand()
{
	if (!executedCommands.empty())
	{
		OrderCommand * command = executedCommands.top();
		executedCommands.pop();
		command->Revert();
		revertedCommands.push(command);
	}
}

void SharedCode::OrderController::RedoCommand()
{
	if (!revertedCommands.empty())
	{
		OrderCommand * command = revertedCommands.top();
		revertedCommands.pop();
		command->Execute();
		executedCommands.push(command);
	}
}

SharedCode::OrderController::~OrderController()
{
   for (int i = 0; i < orderList.size(); i++)
   {
      delete this->orderList.at(i);
   }
}

