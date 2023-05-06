#pragma once
//#include "Graph.h"
#include "Node.h"
#include "Line.h"
#include <cliext/list>

#ifndef ULGPOINT
#define ULGPOINT

namespace UnikursLine {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class GPoint {
	public:
		static Generic::List<GPoint^>^ Points;

	public:
		// если точка - храним Point
		// если Node - храним Node
		Object^ Point;

	public:
		static const int EmptyPointDiameter = 5;
		static const float MaxDistNeighborhood = (float)Node::circleDiameter;

	private:
		bool isNode = false;
	public:
		GPoint();
		GPoint(Node^ node);
		GPoint(System::Drawing::Point^ point);
		GPoint(GPoint^ point);
		~GPoint();

		bool IsNode();
		Node^ GetNode();

		System::Drawing::Point^ GetPosition();
		System::Void SetPosition(System::Drawing::Point^ position);

		float DistanceFromCenter(System::Drawing::Point^ position);
	};

}

#endif // !ULGPOINT