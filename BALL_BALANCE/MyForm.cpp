#include "MyForm1.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	BALL_BALANCE::MyForm form;
	Application::Run(%form);

	return 0;
}
