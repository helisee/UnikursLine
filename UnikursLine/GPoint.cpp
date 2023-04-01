#include "GPoint.h"
#include "Node.h"

using namespace UnikursLine;

GPoint::GPoint(Node^ node) {
	this->isNode = true;
	this->Point = node;
	Points.Add(this);
	Node::Nodes.Add(node);
}

GPoint::GPoint(System::Drawing::Point^ point) {
	this->isNode = false;
	this->Point = point;
	Points.Add(this);
}

GPoint::GPoint(GPoint^ gpoint) {
	this->Point = gpoint->Point;
	this->isNode = gpoint->isNode;
}

bool GPoint::IsNode() {
	return this->isNode;
}

Node^ GPoint::GetNode() {
	if (isNode)
		return (Node^)this->Point;
	return nullptr;
}

System::Drawing::Point^ GPoint::GetPosition() {
	if (isNode) {
		return ((Node^)this->Point)->Position;
	}
	return (System::Drawing::Point^)this->Point;
}