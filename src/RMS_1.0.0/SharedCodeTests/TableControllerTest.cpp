#include "stdafx.h"
#include <CppUnitTest.h>
#include <string.h>

#include <Table.h>
#include <Reservation.h>
#include <TableController.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(TableControllerTest)
   {
   public:

      /// <summary>
      /// A test for creating tables in the TableController
      /// </summary>
      TEST_METHOD(CreateTableTest)
      {
         TableController * controller = new TableController();
         Table * testTable = controller->CreateTable();
         Assert::IsNotNull(controller);
      }
      
      /// <summary>
      /// A test for makeing sure the table number increments
      /// as more tables are added.
      /// </summary>
      TEST_METHOD(TableNumTest)
      {
         TableController * controller = new TableController();
         Table * testTable = controller->CreateTable();
         Table * testTable2 = controller->CreateTable();
         Assert::AreEqual(2, testTable2->GetTableNum());
      }

      /// <summary>
      /// A test for makeing sure the a reservation
      /// can be removed from the table.
      /// </summary>
      TEST_METHOD(RemoveReservationTest)
      {
         TableController * controller = new TableController();
         Table * testTable = controller->CreateTable();
         testTable->UpdateReservation(new Reservation());
         Assert::IsFalse(testTable->Vacant());
         testTable->RemoveReservation();
         Assert::IsTrue(testTable->Vacant());
      }

      /// <summary>
      /// A test for making sure a table
      /// can have a reservation assigned to it.
      /// </summary>
      TEST_METHOD(SeatTableTest)
      {
         TableController * controller = new TableController();
         Table * table1 = controller->CreateTable();
         Table * table2 = controller->CreateTable();
         Table * table3 = controller->CreateTable();
         controller->SeatTable(table3, new Reservation("test", "temp", true));

         Assert::AreEqual("test", controller->GetTable(2)->ReservationName());
      }

      /// <summary>
      /// A test of the destructor
      /// </summary>
      TEST_METHOD(DestructorTest)
      {
         TableController * controller = new TableController();
         controller->CreateTable();
         delete controller;
      }

      /// <summary>
      /// A test to create a table wiht
      /// specified capacity
      /// </summary>
      TEST_METHOD(CreateWithCapTest)
      {
         TableController * controller = new TableController();
         Table * table = controller->CreateTable(5);
         bool size = (5 == table->Capacity());
         Assert::IsTrue(size);
      }

      /// <summary>
      /// A test to return a table
      /// with an order id.
      /// </summary>
      TEST_METHOD(GetTableWithOrderIdTest)
      {
         TableController * controller = new TableController();
         controller->CreateTable();
         controller->CreateTable();
         Assert::IsNull(controller->TableWithOrderID(2));
         controller->GetTable(1)->UpdateOrderID(2);
         Assert::IsNotNull(controller->TableWithOrderID(2));
      }

      /// <summary>
      /// A test to ensure
      /// we can get the table list
      /// </summary>
      TEST_METHOD(GetTablesTest)
      {
         TableController * controller = new TableController();
         controller->CreateTable(1);
         TableContainer temp = controller->getTables();
         bool tableID = (1 == temp.at(0)->GetTableNum());
         Assert::IsTrue(tableID);
      }
   };
}