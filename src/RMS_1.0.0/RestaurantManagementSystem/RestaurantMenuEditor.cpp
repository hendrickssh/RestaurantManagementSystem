#include "RestaurantMenuEditor.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void OpenRestaurantMenuEditor()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew RestaurantManagementSystem::RestaurantMenuEditor);
}