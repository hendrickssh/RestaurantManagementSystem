#include "stdafx.h"
#include "CppUnitTest.h"
#include "string.h"

#include "Printer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace SharedCode;

namespace SharedCodeTests
{
   TEST_CLASS(PrinterTest)
   {
   public:

      /// <summary>
      /// A test to ensure that a receipt can be printed given it has an ID number.
      /// </summary>
      TEST_METHOD(CatalogDigitalReceipt)
      {
         Printer * print = new Printer();
         string str = "Bugger \n\tLettuce \n\tTomato";
         int identifcationNumber = 1234567890;
         Assert::AreEqual(print->CatalogDigitallyReceipt(str, identifcationNumber), true);
         delete print; 
      }

      /// <summary>
      /// A test to ensure that a receipt can not be printed 
      /// given it does not have an ID number.
      /// </summary>
      TEST_METHOD(NullIDCatalogDigitalReceipt)
      {
         Printer * print = new Printer();
         string str = "Bugger \n\tLettuce \n\tTomato";
         int identifcationNumber = NULL;
         Assert::IsFalse(print->CatalogDigitallyReceipt(str, identifcationNumber));
         delete print;
      }

      /// <summary>
      /// A test to ensure that a receipt can be printed given it has an 
      /// ID number and string of items.
      /// </summary>
      TEST_METHOD(CatalogDigitalReceiptNoString)
      {
         Printer * print = new Printer();
         string str = "";
         int identifcationNumber = 1234567890;
         Assert::AreEqual(print->CatalogDigitallyReceipt(str, identifcationNumber), true);
         delete print;
      }

      /// <summary>
      /// A test to ensure that a receipt can not be printed 
      /// given it does not have an ID number and no string.
      /// </summary>
      TEST_METHOD(NullIDCatalogDigitalReceiptNoString)
      {
         Printer * print = new Printer();
         string str = "";
         int identifcationNumber = NULL;
         Assert::IsFalse(print->CatalogDigitallyReceipt(str, identifcationNumber));
         delete print;
      }
   };
}