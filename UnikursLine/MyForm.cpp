#include "MyForm.h"
#include <Windows.h>

using namespace UnikursLine; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm^ mf = gcnew MyForm();
	mf->genGraph();
	Application::Run(mf);

	return 0;
}

System::Void UnikursLine::MyForm::genGraph() {
	  Graph^ gr = gcnew Graph(this->pictureBoxMain);
	}