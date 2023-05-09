#include "Node.h"

using namespace UnikursLine;

Node::Node() {
	Nodes = gcnew Generic::List<Node^>();
}

Node::Node(int number) {
	this->Num = number;
	int offsetX = 100;
	int offsetY = 100;
	int offsetLeft = 40;
	int offsetTop = 50;

	int br = (int)Math::Ceiling((number - 2) / 2.0);

	Point^ position = gcnew Point(br * offsetX + offsetLeft, offsetY * ((number - 1) % 2) + offsetTop);
	this->Position = position;
	this->X = position->X;
	this->Y = position->Y;
	Nodes->Add(this);
}

Node::Node(Point^ position) {
	this->Position = position;
	this->X = position->X;
	this->Y = position->Y;
	Nodes->Add(this);
}

Node::~Node() {

}

Node^
Node::GetNode(unsigned number) {
	for each (auto node in Nodes) {
		if (node->Num == number) return node;
	}
	return nullptr;
}

System::Void
Node::SetPosition(Point^ position) {
	this->Position = position;
	this->X = position->X;
	this->Y = position->Y;
}

System::Void
Node::Clear() {
	Nodes->Clear();
}

float
Node::DistanceFromCenter(System::Drawing::Point^ position) {
	System::Drawing::Point^ point = ((System::Drawing::Point^)this->Position);
	float x_x0 = (position->X - point->X);
	float y_y0 = (position->Y - point->Y);
	float radius = Math::Sqrt(x_x0 * x_x0 + y_y0 * y_y0);

	return radius;
}