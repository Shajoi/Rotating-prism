#include "Prizma.h"
using namespace System;
using namespace System::Windows::Forms;
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Kursprizma::Prizma form;
	Application::Run(% form);
}

