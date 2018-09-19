#include "stdafx.h"
#include "CppUnitTest.h"
#include "string.h"

#include "Receipt.h"
#include "Order.h"
#include "OrderItem.h"
#include "Recipe.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(ReceiptTest)
   {
   public:

      /// <summary>
      /// Test to ensure that reccomend gratuities can be 
      /// calculated correclty and given back as a formatted string.
      /// </summary>
      TEST_METHOD(CalculateTips)
      {
         string * itemAName = new string("Udon Noodle");
         string * des = NULL;
         float price = 4.75;
         Recipe * recA = new Recipe(itemAName, price, des);
         OrderItem * itemA = new OrderItem(recA);
         Order * order = new Order(6465);
         order->AddItem(itemA);
         Receipt * bill = new Receipt();
         string str = "Poor Service: $5.49\nGood Service: $5.74\nExcellent Service: $5.99\n";
         Assert::AreEqual(bill->CalculateTips(order->GetTotalOrderCost()), str);
         delete itemAName, des, recA, itemA, order, bill;
      }

      /// <summary>
      /// Test to ensure that a recipet object can be formatted correctly.
      /// </summary>
      TEST_METHOD(FormatReceipt)
      {
         string * itemAName = new string("Udon Noodle");
         string * des = NULL;
         float price = 4.75;


         Recipe * recA = new Recipe(itemAName, price, des);
         OrderItem * itemA = new OrderItem(recA);
         Order * order = new Order(6465);
         order->AddItem(itemA);
         Receipt * bill = new Receipt();

         string str = bill->FormatReceipt(order);
         string expected = "     Thank you!\n";
         expected += ("Order ID: 6465\n");
         expected += "********************************\n";
         expected += "Udon Noodle     $4.75\n";
         expected += "********************************\n";
         expected += "Total: $4.99\n";
         expected += "Gratuity:\n";
         expected += "Poor Service: $5.49\nGood Service: $5.74\nExcellent Service: $5.99\n";
         Assert::AreEqual(str, expected);
      }

      /// <summary>
      /// Test the deconstructor.
      /// </summary>
      TEST_METHOD(DeconstructorTest)
      {
         Receipt * rec = new Receipt();
         delete rec;
      }
   };
}