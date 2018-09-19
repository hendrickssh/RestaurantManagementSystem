#include "stdafx.h"
#include "Printer.h"


bool SharedCode::Printer::CatalogDigitallyReceipt(string str, long int id)
{
   if (id == NULL)
      return false;
   string fileName = std::to_string(id);
   string filePath = "../" + fileName + ".txt";
   ofstream file(filePath);
   file << str;
   file.close();
   return true;
}