#include "ReceiptPrintScreen.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void OpenReceiptDebug()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew RestaurantManagementSystem::ReceiptPrintScreen);
}
