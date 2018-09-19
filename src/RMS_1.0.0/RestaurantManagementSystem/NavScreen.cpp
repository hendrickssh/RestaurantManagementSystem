#include "NavScreen.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void OpenNavScreen()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew RestaurantManagementSystem::NavScreen);
}