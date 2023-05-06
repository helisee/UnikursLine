#pragma once
#include "Node.h"
#ifndef ULLINE
#define ULLINE

namespace UnikursLine {

	ref class Line
	{
	public:
		static Generic::List<Line^>^ Lines;

		unsigned Num;
		Node^ From;
		Node^ To;

		Line();
		Line(int number, Node^ from, Node^ to);
		static System::Void Clear();
		static Line^ GetLine(int num);
	};

}

#endif

