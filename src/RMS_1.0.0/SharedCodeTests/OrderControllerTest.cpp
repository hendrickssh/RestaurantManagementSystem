#include "stdafx.h"
#include <CppUnitTest.h>
#include <string.h>

#include <Order.h>
#include <OrderController.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(OrderControllerTest)
   {
   public:

      /// <summary>
      /// A test for ensuring that a Order can be created
      /// within the OrderController.
      /// </summary>
      TEST_METHOD(CreateOrderTest)
      {
         OrderController * controller = new OrderController();
         Order * testOrder = controller->CreateOrder();

         Assert::IsNotNull(testOrder);
      }

      /// <summary>
      /// A test for ensuring that the ID for the next
      /// order increments based off of the final order.
      /// </summary>
      TEST_METHOD(GetNextIDTest)
      {
         int idtest = 0;
         OrderController * controller = new OrderController();
         Order * testOrder = controller->CreateOrder();
         Assert::AreEqual(1, testOrder->GetID());
         Order * testOrder1 = controller->CreateOrder();
         Assert::AreEqual(2, testOrder1->GetID());
         Assert::IsNotNull(testOrder);
      }

      /// <summary>
      /// A test to ensure that Orders can be marked as completed.
      /// </summary>
      TEST_METHOD(CompleteOrderTest)
      {
         int idtest = 0;
         OrderController * cont = new OrderController();
         Order * testOrder = cont->CreateOrder();
         cont->CompleteOrder(testOrder);
         
         Assert::IsTrue(testOrder->GetOrderState());
      }

      /// <summary>
      /// A test to ensure that a single order can be deleted
      /// from the OrderController.
      /// </summary>
      TEST_METHOD(DeleteOrderSingle)
      {
         Order * testOrder = NULL;
         OrderController * controller = new OrderController();
         bool result = false;

         testOrder = controller->CreateOrder();

         result = controller->DeleteOrder(testOrder);

         Assert::IsNull(testOrder, L"Test order was not set to NULL");
         Assert::IsTrue(result, L"OrderController::DeleteOrder did not return true");
      }

      /// <summary>
      /// A test to ensure that two orders can be deleted from
      /// the OrderController.
      /// </summary>
      TEST_METHOD(DeleteOrderTwoItems)
      {
         Order * testOrderOne = NULL;
         Order * testOrderTwo = NULL;
         OrderController * controller = new OrderController();
         bool result = false;

         testOrderOne = controller->CreateOrder();
         testOrderTwo = controller->CreateOrder();

         result = controller->DeleteOrder(testOrderTwo);

         Assert::IsNull(testOrderTwo, L"Test order two was not set to NULL");
         Assert::IsTrue(result, L"OrderController::DeleteOrder did not return true");

         Assert::IsNotNull(testOrderOne, L"Test order one was set to NULL, should not have been touched");
         Assert::AreEqual(1, testOrderOne->GetID(), L"Order one ID was not one");
      }

	  /// <summary>
	  /// A test to ensure that the contoller can handle
	  /// deleteing from the list when no items exist in
	  /// it.
	  /// </summary>
	  TEST_METHOD(DeleteOrderNoItemsInList)
	  {
		  OrderController * controller = new OrderController();
		  Order * testOrderOne = new Order();

		  bool result = controller->DeleteOrder(testOrderOne);

		  Assert::IsFalse(result);
        delete controller, testOrderOne;
	  }

	  /// <summary>
	  /// A test to ensure the controller can handle 
	  /// deleting an Order that is not in the list.
	  /// </summary>
	  TEST_METHOD(DeleteOrderNotInList)
	  {
		  OrderController * controller = new OrderController();
		  Order * testOrderOne = new Order();
		  Order * testOrderTwo = controller->CreateOrder();

		  bool result = controller->DeleteOrder(testOrderOne);

		  Assert::IsFalse(result);
	  }

	  /// <summary>
	  /// A test to ensure that the controller can
	  /// return an order at a specific index.
	  /// </summary>
      TEST_METHOD(OrderAtTest)
      {
         OrderController * controller = new OrderController();
         controller->CreateOrder();
         controller->CreateOrder();
         controller->CreateOrder();
         
         Assert::AreEqual(1,controller->OrderAt(0)->GetID());
         Assert::AreEqual(2, controller->OrderAt(1)->GetID());
      }

	  /// <summary>
	  /// A test to ensure that the controller can
	  /// properly return an empty list of orders.
	  /// </summary>
	  TEST_METHOD(GetOrdersEmptyList)
	  {
		  OrderController * controller = new OrderController();
		  SharedCode::OrderController::OrderContainer temp;
		  temp = controller->getOrders();
		  Assert::IsTrue(temp.size() == 0);
	  }

	  /// <summary>
	  /// A test to ensure that the controller can
	  /// properly return a nonempty list of orders.
	  /// </summary>
	  TEST_METHOD(GetOrdersNotEmptyList)
	  {
		  OrderController * controller = new OrderController();
		  SharedCode::OrderController::OrderContainer temp;
		  controller->CreateOrder();
		  temp = controller->getOrders();
		  Assert::IsTrue(temp.size() > 0);
	  }

	  /// <summary>
	  /// A test to ensure that the controller can 
	  /// properly return an order with a specified
	  /// id.
	  /// </summary>
	  TEST_METHOD(GetOrderWithIDInList)
	  {
		  OrderController * controller = new OrderController();
		  controller->CreateOrder();
		  controller->CreateOrder();

		  Order * testOrderOne = controller->OrderWithID(1);
		  Order * testOrderTwo = controller->OrderWithID(2);

		  Assert::IsTrue(testOrderOne->GetID() == 1);
		  Assert::IsTrue(testOrderTwo->GetID() == 2);
	  }

	  /// <summary>
	  /// A test to ensure that the controller can
	  /// properly handle when an Order with a specified
	  /// id does not exist.
	  /// </summary>
	  TEST_METHOD(GetOrderWithIDNotInList)
	  {
		  OrderController * controller = new OrderController();
		  controller->CreateOrder();
		  controller->CreateOrder();

		  Order * testOrderOne = controller->OrderWithID(3);

		  Assert::IsNull(testOrderOne);
	  }

	  /// <summary>
	  /// A test to ensure a controller can be destroyed;
	  /// </summary>
	  TEST_METHOD(DestructorTest)
	  {
		  OrderController * controller = new OrderController();
		  controller->CreateOrder();
		  controller->CreateOrder();
		  Assert::IsNotNull(controller);
		  delete controller;
	  }
   };
}
