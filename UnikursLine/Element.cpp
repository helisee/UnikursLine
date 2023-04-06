#include "Element.h"
#include <string>

using namespace UnikursLine;

Element::Element(TextBox^ tb, unsigned nodeNum, unsigned branchNum) {
	this->textBox = tb;
	this->NodeNumber = nodeNum;
	this->BranchNumer = branchNum;

	this->textBox->TextChanged += gcnew System::EventHandler(this, &Element::numericUpDownNodes_ValueChanged);
}

System::Void 
Element::ChangeValue(int value) {
	this->matrix[this] = value;
}

System::Void 
Element::numericUpDownNodes_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	auto str = ((TextBox^)sender)->Text;
	int val = 0;

	bool isInt = System::Int32::TryParse(str, val);
	if (isInt == false) {
		str = L"0";
		return;
	}
	this->ChangeValue(val);
	
}