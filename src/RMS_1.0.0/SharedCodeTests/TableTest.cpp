#include "stdafx.h"
#include <CppUnitTest.h>
#include <string.h>

#include <Table.h>
#include <Reservation.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(TableTest)
   {
   public:

      /// <summary>
      /// A test for default Table constructor
      /// </summary>
      TEST_METHOD(CreateTableDefaultTest)
      {
         Table * table = new Table();
         Assert::IsNotNull(table);
      }

      /// <summary>
      /// A test for Table with int constructor
      /// </summary>
      TEST_METHOD(CreateTableIntTest)
      {
         Table * table = new Table(1);
         Assert::IsNotNull(table);
      }

      /// <summary>
      /// A test for Table with int and capacity
      /// Constructor
      /// </summary>
      TEST_METHOD(CreateTeableParamsTest)
      {
         Table * table = new Table(1, 3);
         Assert::IsNotNull(table);
      }

      /// <summary>
      /// A test for the Table destructor.
      /// </summary>
      TEST_METHOD(DestructorTest)
      {
         Table * table = new Table();
         delete table;
      }

      /// <summary>
      /// A test to get Table num.
      /// </summary>
      TEST_METHOD(GetTableNumTest)
      {
         Table * table = new Table(2);
         bool SameTableNum = (2 == table->GetTableNum());
         Assert::IsTrue(SameTableNum);
      }

      /// <summary>
      /// A test to get the table capacity
      /// </summary>
      TEST_METHOD(GetTableCapacityTest)
      {
         Table * table = new Table(2, 3);
         bool SameTableCap = (3 == table->Capacity());
         Assert::IsTrue(SameTableCap);
      }

      /// <summary>
      /// A test to update the reservation 
      /// when table is vacant
      /// </summary>
      TEST_METHOD(UpdateReservationVacantTest)
      {
         Table * table = new Table();
         Assert::IsTrue(table->Vacant());
         table->UpdateReservation(new Reservation("","",true));
         Assert::IsFalse(table->Vacant());
      }

      /// <summary>
      /// A test to update the reservation
      /// when the table is not vacant.
      /// </summary>
      TEST_METHOD(UpdateReservationNotVacantTest)
      {
         Table * table = new Table();
         Assert::IsTrue(table->Vacant());
         table->UpdateReservation(new Reservation());
         Assert::IsFalse(table->Vacant());
         Assert::IsFalse(table->UpdateReservation(new Reservation()));
      }

      /// <summary>
      /// A test to get a tables reservation
      /// time
      /// </summary>
      TEST_METHOD(GetReservationTimeTest)
      {
         Table * table = new Table();
         table->UpdateReservation(new Reservation("test", "test", true));
         Assert::AreEqual("test", table->GetReservationTime());
      }

      /// <summary>
      /// A test to get a tables reservation
      /// name
      /// </summary>
      TEST_METHOD(GetReservationNameTest)
      {
         Table * table = new Table();
         table->UpdateReservation(new Reservation("name", "test", true));
         Assert::AreEqual("name", table->ReservationName());
      }

      /// <summary>
      /// A test to remove a reservation
      /// from a table
      /// </summary>
      TEST_METHOD(RemoveReservationTest)
      {
         Table * table = new Table();
         table->UpdateReservation(new Reservation());
         Assert::IsFalse(table->Vacant());
         table->RemoveReservation();
         Assert::IsTrue(table->Vacant());
      }

      /// <summary>
      /// A test to update and
      /// get the orderid
      /// </summary>
      TEST_METHOD(UpdateAndGetOrderIdTest)
      {
         Table * table = new Table();
         bool sameId = (-1 == table->OrderID());
         Assert::IsTrue(sameId);
         table->UpdateOrderID(5);
         sameId = (5 == table->OrderID());
         Assert::IsTrue(sameId);
      }
   };
}