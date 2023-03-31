#include "MyForm.h"
#include <Windows.h>

using namespace UnikursLine; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm^ _mForm = gcnew MyForm();
	_mForm->InitGraph();
	Application::Run(_mForm);

	return 0;
}

