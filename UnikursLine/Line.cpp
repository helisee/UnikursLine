#include "Line.h"

using namespace UnikursLine;

Line::Line(int number, GPoint^ from, GPoint^ to) {
	this->Num = number;
	this->From = from;
	this->To = to;
}