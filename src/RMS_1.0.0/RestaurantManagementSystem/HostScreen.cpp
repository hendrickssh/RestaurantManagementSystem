#include "HostScreen.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void OpenHostScreen()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew RestaurantManagementSystem::HostScreen);
}