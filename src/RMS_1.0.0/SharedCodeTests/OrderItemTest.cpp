#include "stdafx.h"
#include <CppUnitTest.h>
#include <string.h>

#include <iostream>

#include <Restaurant.h>

#include <Order.h>
#include <OrderItem.h>
#include <OrderCommand.h>
#include <AddOrderItem.h>
#include <RemoveOrderItem.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

using namespace SharedCode;

namespace SharedCodeTests
{
	
   TEST_CLASS(OrderItemTests)
   {
   public:
      /// <summary>
      /// A test to item number is changed.
      /// </summary>
      TEST_METHOD(AddOrderItem_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         AddOrderItem * addItem = new AddOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(addItem);

         bool ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsTrue(ItemFound);
      }

      /// <summary>
      /// Tests that the destructor deletes the order item object.
      /// </summary>
      TEST_METHOD(AddOrderItemDestructor_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         AddOrderItem * addItem = new AddOrderItem(testOrder, testItem);

         delete addItem;
      }

      /// <summary>
      /// Tests that the destructor deletes the order item object.
      /// </summary>
      TEST_METHOD(AddOrderItemDestructorExecuted_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         AddOrderItem * addItem = new AddOrderItem(testOrder, testItem);

         addItem->Execute();

         delete addItem;

         Assert::IsFalse(testOrder->Items()->empty());
      }

      /// <summary>
      /// Tests that the destructor deletes the order item object.
      /// </summary>
      TEST_METHOD(RemoveOrderItemDestructor_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         RemoveOrderItem * removeItem = new RemoveOrderItem(testOrder, testItem);

         delete removeItem;
      }

      /// <summary>
      /// Tests that the destructor deletes the order item object.
      /// </summary>
      TEST_METHOD(RemoveOrderItemDestructorExecuted_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         RemoveOrderItem * removeItem = new RemoveOrderItem(testOrder, testItem);

         removeItem->Execute();

         delete removeItem;
      }

      /// <summary>
      /// A test to item number is changed.
      /// </summary>
      TEST_METHOD(UndoAddOrderItem_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         AddOrderItem * addItem = new AddOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(addItem);

         bool ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsTrue(ItemFound);

         Restaurant::GetRestaurant()->getOrderController()->UndoCommand();

         ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsFalse(ItemFound);
      }

      /// <summary>
      /// A test to item number is changed.
      /// </summary>
      TEST_METHOD(RedoAddOrderItem_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         AddOrderItem * addItem = new AddOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(addItem);

         bool ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsTrue(ItemFound);

         Restaurant::GetRestaurant()->getOrderController()->UndoCommand();

         ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsFalse(ItemFound);
         
         Restaurant::GetRestaurant()->getOrderController()->RedoCommand();

         ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsTrue(ItemFound);
      }

      /// <summary>
      /// A test to item number is changed.
      /// </summary>
      TEST_METHOD(RemoveOrderItem_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         AddOrderItem * addItem = new AddOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(addItem);

         RemoveOrderItem * removeItem = new RemoveOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(removeItem);

         bool ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsFalse(ItemFound);
      }

      /// <summary>
      /// A test to item number is changed.
      /// </summary>
      TEST_METHOD(UndoRemoveOrderItem_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         AddOrderItem * addItem = new AddOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(addItem);

         RemoveOrderItem * removeItem = new RemoveOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(removeItem);

         bool ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsFalse(ItemFound);

         Restaurant::GetRestaurant()->getOrderController()->UndoCommand();

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsTrue(ItemFound);
      }

      /// <summary>
      /// A test to item number is changed.
      /// </summary>
      TEST_METHOD(RedoRemoveOrderItem_Test)
      {
         Order * testOrder = new Order(0);

         OrderItem * testItem = new OrderItem(nullptr);

         AddOrderItem * addItem = new AddOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(addItem);

         RemoveOrderItem * removeItem = new RemoveOrderItem(testOrder, testItem);

         Restaurant::GetRestaurant()->getOrderController()->ExecuteCommand(removeItem);

         bool ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsFalse(ItemFound);

         Restaurant::GetRestaurant()->getOrderController()->UndoCommand();

         ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsTrue(ItemFound);

         Restaurant::GetRestaurant()->getOrderController()->RedoCommand();

         ItemFound = false;

         for (Order::OrderItemContainer::const_iterator iterator = testOrder->Items()->begin(); iterator != testOrder->Items()->end(); iterator++)
            if (*iterator == testItem)
               ItemFound = true;

         Assert::IsFalse(ItemFound);
      }

      /// <summary>
      /// Tests that adding a string customization works.
      /// </summary>
      TEST_METHOD(OrderItemAddCustomization)
      {
         OrderItem * testItem = new OrderItem(nullptr);

         Assert::IsTrue(testItem->GetCustomizations()->empty());

         testItem->AddCustomization(new string("TestCustomization"));

         Assert::IsFalse(testItem->GetCustomizations()->empty());

         Assert::IsTrue(*testItem->GetCustomizations()->at(0) == "TestCustomization");
      }

      TEST_METHOD(OrderItemRemoveCustomization)
      {
         OrderItem * testItem = new OrderItem(nullptr);

         Assert::IsTrue(testItem->GetCustomizations()->empty());

         testItem->AddCustomization(new string("TestCustomization"));

         Assert::IsFalse(testItem->GetCustomizations()->empty());

         testItem->RemoveCustomization(new string("TestCustomization"));

         Assert::IsTrue(testItem->GetCustomizations()->empty());
      }

      TEST_METHOD(OrderItemDestructMultiple)
      {
         OrderItem * testItem = new OrderItem(nullptr);

         testItem->AddCustomization(new string("Custom1"));
         testItem->AddCustomization(new string("Custom2"));
         testItem->AddCustomization(new string("Custom3"));

         delete testItem;
      }

      TEST_METHOD(OrderItemGetRecipe)
      {
         Recipe * testRecipe = new Recipe(new string("TestName"), 17.38, new string("FettyWap"));

         OrderItem * testItem = new OrderItem(testRecipe);

         Assert::IsTrue(testRecipe == testItem->GetRecipe());
      }
   };
   
}