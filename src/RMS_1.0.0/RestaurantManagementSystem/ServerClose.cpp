#include "ServerClose.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void OpenServerClose()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew RestaurantManagementSystem::ServerClose);
}

