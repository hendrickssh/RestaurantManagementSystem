#include "Chef.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void OpenChefScreen()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew RestaurantManagementSystem::Chef);
}