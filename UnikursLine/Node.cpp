#include "Node.h"

using namespace UnikursLine;

Node::Node() {
	Nodes = gcnew Generic::List<Node^>();
}

Node::Node(Point^ position) {
	this->Position = position;
	this->X = position->X;
	this->Y = position->Y;
	Nodes->Add(this);
}


Node::~Node() {
	
}

float 
Node::DistanceFromCenter(Point^ position) {
	float radius = Math::Sqrt((position->X - this->X) * (position->X - this->X) + (position->Y - this->Y) * (position->Y - this->Y));

	if (radius > this->circleRadius) return -1.0;
	return radius;
}

System::Void 
Node::SetPosition(Point^ position) {
	this->Position = position;
	this->X = position->X;
	this->Y = position->Y;
}