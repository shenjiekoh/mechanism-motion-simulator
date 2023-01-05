#include "MainWindow.h"

using namespace Mechanism;

[STAThreadAttribute]
int main(array<System::String^ >^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MainWindow());
	return 0;
}