#include "Element.h"
#include "Matrix.h"
#include "Graph.h"
#include <string>

using namespace UnikursLine;

Element::Element(TextBox^ tb, unsigned nodeNum, unsigned branchNum) {
	this->textBox = tb;
	this->NodeNumber = nodeNum;
	this->BranchNumer = branchNum;

	this->textBox->TextChanged += gcnew System::EventHandler(this, &Element::numericUpDownNodes_ValueChanged);

	Matrix::Set(this, 0);
}

Element::~Element() {
	delete this->textBox;
}

System::Void 
Element::ChangeMatrixValue(int value) {
	Matrix::Set(this, value);
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
	if (val > 0) {
		val = 1;
	}
	if (val < 0) {
		val = -1;
	}
	this->ChangeMatrixValue(val);
	((TextBox^)sender)->Text = val.ToString();
	Graph::RedrawGraph();
}

System::Void 
Element::ChangeTextBoxValue(int val) {
	this->textBox->Text = val.ToString();
}