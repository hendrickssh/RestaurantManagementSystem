#include "stdafx.h"
#include "CppUnitTest.h"
#include "string.h"

#include "Restaurant.h"
#include <TableController.h>
#include <ReservationController.h>
#


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(RestaurantTest)
   {
   public:

      /// <summary>
      /// Constructor Test
      /// </summary>
      TEST_METHOD(ConstructorTest)
      {
         Restaurant * temp = new Restaurant();
         Assert::IsNotNull(temp);
      }

      /// <summary>
      /// A test to get the tablecontroller
      /// </summary>
      TEST_METHOD(getTablecontroller)
      {
         Restaurant * temp = new Restaurant();
         TableController * tables = temp->getTableController();

         Assert::IsNotNull(tables);
      }

      /// <summary>
      /// A test to get the ordercontroller
      /// </summary>
      TEST_METHOD(GetOrderControllerTest)
      {
         Restaurant * temp = new Restaurant();
         OrderController * orders = temp->getOrderController();

         Assert::IsNotNull(orders);
      }

      /// <summary>
      /// A test to get the reservartioncontroller
      /// </summary>
      TEST_METHOD(GetReservationControllerTest)
      {
         Restaurant * temp = new Restaurant();
         ReservationController * res = temp->getReservationController();

         Assert::IsNotNull(res);
      }

      /// <summary>
      /// A test to get restaurantmenu
      /// </summary>
      TEST_METHOD(GetRestaurantMenuTest)
      {
         Restaurant * temp = new Restaurant();
         RestaurantMenu * menu = temp->getRestaurantMenu();

         Assert::IsNotNull(menu);
      }

      /// <summary>
      /// Destructor Test
      /// </summary>
      TEST_METHOD(DestructorTest)
      {
         Restaurant * temp = new Restaurant();
         delete temp;
      }

      /// <summary>
      /// Get static instance test
      /// </summary>
      TEST_METHOD(GetRestaurantTest)
      {
         Restaurant * temp = Restaurant::GetRestaurant();
         Assert::IsNotNull(temp);
      }

      TEST_METHOD(SaveMenuTest)
      {
         Restaurant * temp = new Restaurant();
         temp->SaveMenu();
      }
   };
}