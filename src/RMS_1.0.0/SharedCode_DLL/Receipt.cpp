#pragma once

#include "stdafx.h"
#include "OrderItem.h"
#include "Receipt.h"

string SharedCode::Receipt::CalculateTips(double cost)
{
   string str = "Poor Service: $" + To_String_Bill(PoorServiceTip(cost * TAX)) + "\n";
   str += "Good Service: $" + To_String_Bill(GoodServiceTip(cost * TAX)) + "\n";
   str += "Excellent Service: $" + To_String_Bill(ExcellentServiceTip(cost * TAX)) + "\n";
   return str;
}

string SharedCode::Receipt::To_String_Bill(double f)
{
   stringstream stream;
   stream << fixed << setprecision(2) << RoundValue(f);
   return stream.str();
}

double SharedCode::Receipt::RoundValue(double d)
{
   int integerValue = (int)d;
   int decimal;
   string str;
   d -= integerValue;
   d *= 100;
   decimal = (int)d;
   d -= decimal;
   if (d != 0)
      decimal++;
   return ((double)integerValue + ((double)decimal/ 100));
}

string SharedCode::Receipt::FormatReceipt(Order * order)
{
   string id = std::to_string(order->GetID());
   vector<OrderItem*> items = *order->Items();
   string str = "     Thank you!\n";
   str += ("Order ID: " + id + '\n');
   str += "********************************\n";
   for (int i = 0; i < items.size(); i++)
   {
      str = str + (*items.at(i)->GetRecipe()->Name());
      str = str + "     $" + To_String_Bill(items.at(i)->GetPrice());
      str += "\n";
   }
   str += "********************************\n";
   str += "Total: $";
   str += To_String_Bill(order->GetTotalOrderCost() * TAX);
   str += "\n";
   str += "Gratuity:\n";
   str += CalculateTips(order->GetTotalOrderCost());
   return str;
}
