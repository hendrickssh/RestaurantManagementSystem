#include "stdafx.h"
#include <CppUnitTest.h>
#include <string.h>

#pragma warning ( disable : 4996 )

#include <Reservation.h>
#include <ReservationController.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(ReservationControllerTest)
   {
   public:

      /// <summary>
      /// A test for ensuring that a Reservation can be created
      /// </summary>
      TEST_METHOD(CreateReservationTest)
      {
         ReservationController * test = new ReservationController();
         Reservation * testRes = test->CreateReservation("testName","testTime",true);

         Assert::IsNotNull(test);
      }

      /// <summary>
      /// A test for ensuring that a default Reservation can be created.
      /// </summary>
      TEST_METHOD(CreateReservationDefaultTest)
      {
         ReservationController * test = new ReservationController();
         Reservation * testRes = test->CreateReservation();
         Assert::IsNotNull(test);
      }

      /// <summary>
      /// A test to ensure that a Reservation can be deleted
      /// from the ReservationController.
      /// </summary>
      TEST_METHOD(DeleteReservationTest)
      {
         ReservationController * testController = new ReservationController();
         Reservation * test1 = testController->CreateReservation("1", "1",true);
         Assert::IsTrue(testController->RemoveReservation(test1->Name()));
      }

      /// <summary>
      /// A test to ensure that a Reservation at an index
      /// can be returned from ReservationController
      /// </summary>
      TEST_METHOD(GetReservationAtTest)
      {
         ReservationController * testController = new ReservationController();
         Reservation * test1 = testController->CreateReservation("1", "1", true);
         Reservation * test2 = testController->CreateReservation("1", "1", true);
         
         Assert::AreEqual(test1->Name(), testController->GetReservationAt(0)->Name());
      }

      /// <summary>
      /// A test to ensure that a Reservation at a
      /// high index can be returned from ReservationController
      /// </summary>
      TEST_METHOD(GetReservationAtHighIndexTest)
      {
         
         ReservationController * testController = new ReservationController();
         for (int i = 0; i < 100; i++)
         {
            testController->CreateReservation((char*)std::to_string(i).c_str(), "test", true);
         }
         Assert::AreEqual("60", testController->GetReservationAt(60)->Name());         

         delete testController;
      }

      /// <summary>
      /// A test to ensure that a Reservation with a specific name can be returned
      /// from ReservationController
      /// </summary>
      TEST_METHOD(GetReservationByNameTest)
      {
         ReservationController * testController = new ReservationController();
         Reservation * testRes1 = testController->CreateReservation("1", "test", true);
         Reservation * testRes2 = testController->CreateReservation("2", "test", true);

         Reservation * result = testController->GetReservation("2");

         char * resultName = result->Name();

         Assert::AreEqual(testRes2->Name(), resultName);
      }

      /// <summary>
      /// A test to ensure that ReservationController can
      /// safely handle when a reservation is requested but 
      /// doesn't exist.
      /// </summary>
      TEST_METHOD(GetReservationByNameNotInListTest)
      {
         ReservationController * testController = new ReservationController();
         Reservation * testRes1 = testController->CreateReservation("1", "test", true);
         Reservation * testRes2 = testController->CreateReservation("2", "test", true);

         Assert::IsNull(testController->GetReservation("3"));
      }
      
      /// <summary>
      /// A test to make sure it can handle when a reservation
      /// in not in the list.
      /// </summary>
      TEST_METHOD(RemoveReservatoinNotInControllerTest)
      {
         ReservationController * testController = new ReservationController();
         Reservation * testRes1 = testController->CreateReservation("1", "test", true);
         Assert::IsFalse(testController->RemoveReservation("2"));
      }

      /// <summary>
      /// Tests the destructor
      /// </summary>
      TEST_METHOD(DestructorTest)
      {
         ReservationController * testController = new ReservationController();
         testController->CreateReservation();
         testController->CreateReservation("1", "test", true);
         delete testController;
      }

      /// <summary>
      /// A test to get NumReservations
      /// </summary>
      TEST_METHOD(GetNumResTest)
      {
         ReservationController * controller = new ReservationController();
         controller->CreateReservation();
         bool AreSame = (1 == controller->NumReservations());
         Assert::IsTrue(AreSame);
      }
   };
}