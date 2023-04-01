#pragma once
#include "Graph.h"

namespace UnikursLine {
	ref class GPoint {
	public:
		static Generic::List<GPoint^> Points;

	private:
		// если точка - храним Point
		// если Node - храним Node
		Object^ Point;
	private:
		bool isNode = false;
	public:
		GPoint(Node^ node);
		GPoint(System::Drawing::Point^ point);
		GPoint(GPoint^ point);

		bool IsNode();
		Node^ GetNode();

		System::Drawing::Point^ GetPosition();
	};

}