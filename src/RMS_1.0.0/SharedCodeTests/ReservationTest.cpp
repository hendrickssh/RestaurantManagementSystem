#include "stdafx.h"
#include <CppUnitTest.h>
#include <string.h>
#include <time.h>
#include "Reservation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(ReservationTest)
   {
   public:

      /// <summary>
      /// A test for ensuring that a Reservation can be created.
      /// </summary>
      TEST_METHOD(CreateReservationTest)
      {
         Reservation * testRes = new Reservation();

         Assert::IsNotNull(testRes);
      }

      /// <summary>
      /// A test for ensuring that a Reservation can be created
      /// with parameters.
      /// </summary>
      TEST_METHOD(CreateReservationTestWithParameters)
      {
         Reservation * testRes = new Reservation("testName","10:00",true);

         Assert::IsNotNull(testRes);

         char * testTime = testRes->Time();

         Assert::AreEqual(testTime, "10:00");
      }

      /// <summary>
      /// Test to make sure time is returned correctly.
      /// </summary>
      TEST_METHOD(GetTimeTest)
      {
         Reservation * testRes = new Reservation("testName", "10:00", true);
         Assert::AreEqual("10:00", testRes->Time());
      }

      TEST_METHOD(IsReservatinTest)
      {
         Reservation * testRes1 = new Reservation("test", "test", true);
         Reservation * testRes2 = new Reservation("test", "test", false);
         Assert::IsTrue(testRes1->IsReservation());
         Assert::IsFalse(testRes2->IsReservation());
      }
   };
}