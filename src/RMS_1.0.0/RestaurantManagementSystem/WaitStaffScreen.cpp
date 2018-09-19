#include "WaitStaffScreen.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void OpenWaitStaffScreenDebug()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew RestaurantManagementSystem::WaitStaffScreen);
}