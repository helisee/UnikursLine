#pragma once

#ifndef ULELEMENT
#define ULELEMENT

namespace UnikursLine {
	using namespace System::Windows::Forms;
	using namespace System::Collections;

	ref class Element {

	public:
		unsigned NodeNumber;
		unsigned BranchNumer;
	private :
		TextBox^ textBox;

	public:
		Element(TextBox^ tb, unsigned nodeNum, unsigned branchNum);
		~Element();
		System::Void ChangeMatrixValue(int value);
		System::Void numericUpDownNodes_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void ChangeTextBoxValue(int val);

	};
}

#endif // !ULELEMENT