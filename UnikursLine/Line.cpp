#include "Line.h"

using namespace UnikursLine;

Line::Line() {
	Lines = gcnew Generic::List<Line^>();
}

Line::Line(int number, Node^ from, Node^ to) {
	this->Num = number;
	this->From = from;
	this->To = to;

	Lines->Add(this);
}

System::Void 
Line::Clear() {
	Lines->Clear();
	
}
	
Line^ 
Line::GetLine(int num) {
	for each (auto line in Lines) {
		if (line->Num == num) return line;
	}
	return nullptr;
}
























