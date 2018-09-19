#include "stdafx.h"
#include <CppUnitTest.h>
#include <string.h>

#include <Order.h>
#include <OrderItem.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(OrderTest)
   {
   public:

      /// <summary>
      /// Ensures that the default constructor for Order works.
      /// </summary>
      TEST_METHOD(OrderDefaultConstructor)
      {
         Order * temp = new Order();
         Assert::IsNotNull(temp);
      }

      /// <summary>
      /// Tests that an order can be created with a specified ID
      /// </summary>
      TEST_METHOD(OrderConstructorWithIDFam)
      {

         Order * temp = new Order(1);
         Assert::IsNotNull(temp);
      }

      /// <summary>
      /// Ensures that the destructor works with no order items.
      /// </summary>
      TEST_METHOD(OrderDestructEmpty)
      {
         Order * temp = new Order();
         
         delete temp;
      }

      /// <summary>
      /// Tests the destructor when the order contains no items.
      /// </summary>
      TEST_METHOD(OrderDestructNotEmpty)
      {
         Order * temp = new Order();
         
         temp->AddItem(new OrderItem());

         delete temp;
      }

      /// <summary>
      /// Tests that a completed order returns true.
      /// </summary>
      TEST_METHOD(GetOrderStateTrue)
      {
         Order * temp = new Order();
         temp->SetOrderState(true);
         Assert::IsTrue(temp->GetOrderState());
      }

      /// <summary>
      /// Tests that the default order state is false.
      /// </summary>
      TEST_METHOD(GetOrderStateDefault)
      {
         Order * temp = new Order();
         Assert::IsFalse(temp->GetOrderState(), L"Order state was not false.");
      }

      /// <summary>
      /// Tests that a completed order can be marked as
      /// incomplete.
      /// </summary>
      TEST_METHOD(GetOrderStateFalse)
      {
         Order * temp = new Order();
         temp->SetOrderState(true);
         Assert::IsTrue(temp->GetOrderState(), L"Order state was not set to true.");
         temp->SetOrderState(false);
         Assert::IsFalse(temp->GetOrderState(), L"Order state was not set to false.");
      }

      /// <summary>
      /// A test for ensuring that a order is customizable.
      /// </summary>
      TEST_METHOD(GetTotalOrderCostNoItems)
      {
         Order * temp = new Order();
         Assert::IsTrue(temp->GetTotalOrderCost() == 0.0, L"Total order cost for an empty order was not 0.0.");
      }

      /// <summary>
      /// Tests that the total order coverage totals correctly.
      /// </summary>
      TEST_METHOD(GetTotalOrderCostOneItem)
      {
         Order * temp = new Order();

         temp->AddItem(new OrderItem(new Recipe(nullptr, 5.00f, nullptr)));
         temp->AddItem(new OrderItem(new Recipe(nullptr, 5.00f, nullptr)));
         temp->AddItem(new OrderItem(new Recipe(nullptr, 5.00f, nullptr)));

         Assert::IsTrue(temp->GetTotalOrderCost() == 15.0, L"Total order cost for an empty order was not 15.0.");
      }

      /// <summary>
      /// 
      /// </summary>
      TEST_METHOD(GetOrderID)
      {
         Order * temp = new Order(1);
         Assert::IsTrue(temp->GetID() == 1);
      }



      /// <summary>
      /// Tests that the total order coverage totals correctly.
      /// </summary>
      TEST_METHOD(TestRemoveItemEmpty)
      {
         Order * temp = new Order();

         OrderItem * Item1 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));
         OrderItem * Item2 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));

         temp->RemoveItem(Item1);

         Assert::IsNotNull(Item1);
      }

      /// <summary>
      /// Tests that the total order coverage totals correctly.
      /// </summary>
      TEST_METHOD(TestRemoveItemSuccess)
      {
         Order * temp = new Order();

         OrderItem * Item1 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));
         OrderItem * Item2 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));

         temp->AddItem(Item1);
         temp->RemoveItem(Item1);

         Assert::IsTrue(temp->Items()->empty());
      }

      /// <summary>
      /// Tests that the total order coverage totals correctly.
      /// </summary>
      TEST_METHOD(TestRemoveItemNotInList)
      {
         Order * temp = new Order();

         OrderItem * Item1 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));
         OrderItem * Item2 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));

         temp->AddItem(Item1);
         temp->RemoveItem(Item2);

         Assert::IsNotNull(Item2);
      }

      /// <summary>
      /// Tests that the total order coverage totals correctly.
      /// </summary>
      TEST_METHOD(TestGetOrderItems)
      {
         Order * temp = new Order();

         OrderItem * Item1 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));
         OrderItem * Item2 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));

         temp->AddItem(Item1);

         Assert::IsNotNull(temp->Items());

         Assert::IsTrue(Item1 == *(temp->Items()->begin()));
      }

      /// <summary>
      /// Tests that the total order coverage totals correctly.
      /// </summary>
      TEST_METHOD(TestClearItems)
      {
         Order * temp = new Order();

         OrderItem * Item1 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));
         OrderItem * Item2 = new OrderItem(new Recipe(nullptr, 5.00f, nullptr));

         temp->AddItem(Item1);
         temp->AddItem(Item2);

         Assert::IsTrue(temp->Items()->size() == 2);

         temp->ClearItems();

         Assert::IsTrue(temp->Items()->size() == 0);
      }

   };
}