#include "Graph.h"

using namespace UnikursLine;

Graph::Graph(PictureBox^ pictureBoxField) {
	{
		this->pictureBoxField = pictureBoxField;
		Nodes = gcnew Generic::List<Node^>();

		Bitmap^ image = (Bitmap^)(this->pictureBoxField->Image);
		if (image == nullptr) {
			image = gcnew Bitmap(((Control^)pictureBoxField)->Size.Width, ((Control^)pictureBoxField)->Size.Height);
		}
		Graphics^ gfx = Graphics::FromImage(image);
		gfx->Clear(Color::White);

		this->pictureBoxField->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Graph::pictureBoxField_MouseMove);
		this->pictureBoxField->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Graph::pictureBoxField_MouseDown);
		this->pictureBoxField->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Graph::pictureBoxField_MouseUp);
		this->pictureBoxField->Image = image;
		gcnew GPoint();
		gcnew Node();

		AddPointToGraph();
		AddPointToGraph();
		AddNodeToGraph();
		AddPointToGraph();
		AddNodeToGraph();
		AddPointToGraph();
		AddNodeToGraph();
		AddNodeToGraph();
		AddNodeToGraph();

		MyForm::I->Update();
	}
}

Graph::~Graph() {

}

System::Void  
Graph::pictureBoxField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = false;
	this->MovableObject = nullptr;
	MyForm::I->label1->Text = L"Zetros";
}

System::Void  
Graph::pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = true;

	GPoint^ nearMovableObj = nullptr;
	float nearestObjectDistance = GPoint::MaxDistNeighborhood;
	for each (auto obj in GPoint::Points) {
		Point^ pos = Point(e->X, e->Y);
		float distance = obj->DistanceFromCenter(pos);
		if (distance == -1) continue;
		if (distance < nearestObjectDistance) nearMovableObj = obj;
		//MyForm::I->label1->Text = nearMovableObj->ToString();
		MyForm::I->Update();
	}
	if (nearMovableObj != nullptr) this->MovableObject = nearMovableObj;
}

System::Void 
Graph::pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->mousePressed) {
		if (this->MovableObject == nullptr) return;

		System::Drawing::Point^ newPos = Point(e->X, e->Y);
		this->MovableObject->SetPosition(newPos);
		this->RedrawGraph();
		MyForm::I->Update();
	}
}

System::Void
Graph::AddPointToGraph() {
	int count = GPoint::Points->Count;
	int magicNumber = 20;
	Point^ pos = gcnew Point(magicNumber * count + 50, magicNumber * count + 50);
	GPoint^ newPoint = gcnew GPoint(pos);

	this->RedrawGraph();
}

System::Void
Graph::AddNodeToGraph() {
	int count = GPoint::Points->Count;
	int magicNumber = 20;
	Point^ pos = gcnew Point(magicNumber * count + 50, magicNumber * count + 50);
	Node^ newnode = gcnew Node(pos);
	GPoint^ newPoint = gcnew GPoint(newnode);

	this->RedrawGraph();
}

System::Void
Graph::AddNodeToGraph(Node^ node) {
	GPoint^ newPoint = gcnew GPoint(node);

	this->RedrawGraph();
}

System::Void 
Graph::Refresh() {
	System::Drawing::Brush^ brush = gcnew SolidBrush(Color::LightGray);
	System::Drawing::Brush^ darkGray = gcnew SolidBrush(Color::DarkGray);

	Bitmap^ image = (Bitmap^)(pictureBoxField->Image);/*
	if (image == nullptr) {
		image = gcnew Bitmap(((Control^)sender)->Size.Width, ((Control^)sender)->Size.Height);
		MyForm::I->label1->Text = ((Control^)sender)->Size.Width.ToString() + L" " + ((Control^)sender)->Size.Height.ToString();
	}*/

	Graphics^ gfx = Graphics::FromImage(image);
	gfx->Clear(Color::White);

	for each (auto node in Nodes) {
		gfx->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
		gfx->FillEllipse(brush, node->X - node->circleRadius, node->Y - node->circleRadius, node->circleDiameter, node->circleDiameter);
		gfx->DrawEllipse(Pens::DarkGray, node->X - node->circleRadius, node->Y - node->circleRadius, node->circleDiameter, node->circleDiameter);
	}
	this->pictureBoxField->Image = image;
}

System::Void 
Graph::RedrawGraph() {
	System::Drawing::Brush^ brush = gcnew SolidBrush(Color::LightGray);
	System::Drawing::Brush^ darkGray = gcnew SolidBrush(Color::DarkGray);
	System::Drawing::Brush^ black = gcnew SolidBrush(Color::Black);

	Bitmap^ image = (Bitmap^)(pictureBoxField->Image);
	Graphics^ gfx = Graphics::FromImage(image);
	gfx->Clear(Color::White);
	gfx->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;

	for each (auto gpoint in GPoint::Points) {
		if (gpoint->IsNode()) {
			Node^ mNode = gpoint->GetNode();
			gfx->FillEllipse(brush, mNode->X - mNode->circleRadius, mNode->Y - mNode->circleRadius, mNode->circleDiameter, mNode->circleDiameter);
			gfx->DrawEllipse(Pens::DarkGray, mNode->X - mNode->circleRadius, mNode->Y - mNode->circleRadius, mNode->circleDiameter, mNode->circleDiameter);
		}
		else {
			Point^ gp = gpoint->GetPosition();
			int pointSize = GPoint::EmptyPointDiameter;
			int pointCentr = pointSize / 2;
			gfx->FillEllipse(black, gp->X - pointCentr, gp->Y - pointCentr, pointSize, pointSize);
			gfx->DrawEllipse(Pens::Black, gp->X - pointCentr, gp->Y - pointCentr, pointSize, pointSize);
		}
	}
	this->pictureBoxField->Image = image;
}