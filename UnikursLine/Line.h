#pragma once
#include "GPoint.h"

#ifndef ULLINE
#define ULLINE

namespace UnikursLine {

	ref class Line
	{
	public:
		int Num;
		GPoint^ From;
		GPoint^ To;

		Line(int number, GPoint^ from, GPoint^ to);
	};

}

#endif

