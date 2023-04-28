#pragma once

#ifndef ULELEMENT
#define ULELEMENT

namespace UnikursLine {
	using namespace System::Windows::Forms;

	ref class Element {
	private:
		unsigned NodeNumber;
		unsigned BranchNumer;
		TextBox^ textBox;

	public:
		Element(TextBox^ tb, unsigned nodeNum, unsigned branchNum);
		~Element();
		System::Void ChangeValue(int value);
		System::Void numericUpDownNodes_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	};
}

#endif // !ULELEMENT