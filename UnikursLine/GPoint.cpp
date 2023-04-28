#include "GPoint.h"
#include "MyForm.h"

using namespace UnikursLine;

GPoint::GPoint() {
	this->Points = gcnew Generic::List<GPoint^>();
}

GPoint::GPoint(Node^ node) {
	this->isNode = true;
	this->Point = node;
	//создать линию
	Points->Add(this);
	Node::Nodes->Add(node);
}

GPoint::GPoint(System::Drawing::Point^ point) {
	this->isNode = false;
	this->Point = point;
	//создать линию
	Points->Add(this);
}

GPoint::GPoint(GPoint^ gpoint) {
	this->Point = gpoint->Point;
	//создать линию
	this->isNode = gpoint->isNode;
	Points->Add(this);
}

GPoint::~GPoint() {
	Points->Clear();
}

bool 
GPoint::IsNode() {
	return this->isNode;
}

Node^ 
GPoint::GetNode() {
	if (isNode)
		return (Node^)this->Point;
	return nullptr;
}

float 
GPoint::DistanceFromCenter(System::Drawing::Point^ position) {
	if (isNode) {
		return ((Node^)Point)->DistanceFromCenter(position);
	}
	else {
		System::Drawing::Point^ point = ((System::Drawing::Point^)this->Point);
		float x_x0 = (position->X - point->X);
		float y_y0 = (position->Y - point->Y);
		float radius = Math::Sqrt(x_x0 * x_x0 + y_y0 * y_y0);

		if (radius > this->EmptyPointDiameter) return -1.0;
		return radius;
	}
}

System::Drawing::Point^ 
GPoint::GetPosition() {
	if (this->isNode) {
		return ((Node^)this->Point)->Position;
	}
	return (System::Drawing::Point^)this->Point;
}

System::Void 
GPoint::SetPosition(System::Drawing::Point^ position) {
	if (this->isNode) {
		MyForm::I->label1->Text = L"Node";
		this->GetNode()->SetPosition(position);
	}
	else {
		this->Point = gcnew System::Drawing::Point(position->X, position->Y);
		//System::Drawing::Point ^ newPos = (System::Drawing::Point^)this->Point;
		//newPos = gcnew System::Drawing::Point(position->X, position->Y);
		//MyForm::I->label1->Text = position->X.ToString()+ L"; " + position->Y.ToString();
	}
}