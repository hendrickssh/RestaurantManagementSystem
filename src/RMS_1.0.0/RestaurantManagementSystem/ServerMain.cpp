#include "ServerMain.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void OpenServerMain()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew RestaurantManagementSystem::ServerMain);
}