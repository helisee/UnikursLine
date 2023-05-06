#include "Graph.h"

using namespace UnikursLine;

Graph::Graph(PictureBox^ pictureBoxField) {

	this->pictureBoxField = pictureBoxField;
	//Nodes = gcnew Generic::List<Node^>();

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

	InitDicts();

	MyForm::I->Update();

}

Graph::~Graph() {

}

System::Void
Graph::pictureBoxField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = false;
	//this->MovableObject = nullptr;
	this->MoveNode = nullptr;
	MyForm::I->label1->Text = L"Zetros";
}

System::Void
Graph::pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = true;

	//GPoint^ nearMovableObj = nullptr;
	Node^ nearMoveNode = nullptr;
	float nearestObjectDistance = Node::circleDiameter;

	//for each (auto obj in GPoint::Points) {
	//	Point^ pos = Point(e->X, e->Y);
	//	float distance = obj->DistanceFromCenter(pos);
	//	if (distance == -1) continue;
	//	if (distance < nearestObjectDistance) nearMovableObj = obj;
	//	//MyForm::I->label1->Text = nearMovableObj->ToString();
	//	MyForm::I->Update();
	//}


	//if (nearMovableObj != nullptr) this->MovableObject = nearMovableObj;
	for each (auto node in Node::Nodes) {
		Point^ pos = Point(e->X, e->Y);
		float distance = node->DistanceFromCenter(pos);
		if (distance < nearestObjectDistance) nearMoveNode = node;
		MyForm::I->Update();
	}

	if (nearMoveNode != nullptr) this->MoveNode= nearMoveNode;
}

System::Void
Graph::pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	/*if (this->mousePressed) {
		if (this->MovableObject == nullptr) return;

		System::Drawing::Point^ newPos = Point(e->X, e->Y);
		this->MovableObject->SetPosition(newPos);
		this->RedrawGraph();
		MyForm::I->Update();
	}*/

	if (this->mousePressed) {
		if (this->MoveNode == nullptr) return;

		System::Drawing::Point^ newPos = Point(e->X, e->Y);
		this->MoveNode->SetPosition(newPos);
		this->RedrawGraph();
		MyForm::I->Update();
	}
}

System::Void
Graph::AddPoint() {
	int count = GPoint::Points->Count;
	int magicNumber = 20;
	Point^ pos = gcnew Point(magicNumber * count + 50, magicNumber * count + 50);
	GPoint^ newPoint = gcnew GPoint(pos);

	this->RedrawGraph();
}

System::Void
Graph::AddNode() {
	int count = GPoint::Points->Count;
	int magicNumber = 20;
	Point^ pos = gcnew Point(magicNumber * count + 50, magicNumber * count + 50);
	Node^ newnode = gcnew Node(pos);
	GPoint^ newPoint = gcnew GPoint(newnode);

	this->RedrawGraph();
}

System::Void
Graph::AddNode(Node^ node) {
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

	for each (auto node in Node::Nodes) {
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
	System::Drawing::Font^ arial16 = gcnew Font("Arial", 16); // магические значения
	System::Drawing::Font^ arial10 = gcnew Font("Arial", 10); // магические значения

	Bitmap^ image = (Bitmap^)(pictureBoxField->Image);
	Graphics^ gfx = Graphics::FromImage(image);
	gfx->Clear(Color::White);
	gfx->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;

	for each (auto node in Node::Nodes) {
		gfx->FillEllipse(brush, node->X - node->circleRadius, node->Y - node->circleRadius, node->circleDiameter, node->circleDiameter);
		gfx->DrawEllipse(Pens::DarkGray, node->X - node->circleRadius, node->Y - node->circleRadius, node->circleDiameter, node->circleDiameter);

		gfx->DrawString(node->Num.ToString(), arial16, black, node->X - 10, node->Y - 10);
	}

	for each (auto line in Line::Lines) {
		if (line->From != nullptr && line->To != nullptr) {

			auto from = line->From->Position;
			auto to = line->To->Position;
			float alpha, b, l, x, y, x0, y0, x1, y1, x2, y2, xa, ya, xb, yb, xn1, yn1, xn2, yn2, xt, yt, d;


			b = line->From->circleRadius;
			x0 = to->X - from->X;
			y0 = to->Y - from->Y;
			l = Math::Sqrt(x0 * x0 + y0 * y0);
			xn1 = b * x0 / l + from->X;
			yn1 = b * y0 / l + from->Y;

			xn2 = x0 * (l - b) / l + from->X;
			yn2 = y0 * (l - b) / l + from->Y;

			b = 10;
			alpha = 0.5236;
			x1 = xn2;
			y1 = yn2;

			x2 = from->X;
			y2 = from->Y;

			x0 = x2 - x1;
			y0 = y2 - y1;

			l = Math::Sqrt(x0 * x0 + y0 * y0);

			x = b * x0 / l;
			y = b * y0 / l;

			xa = x * Math::Cos(alpha) - y * Math::Sin(alpha) + x1;
			ya = x * Math::Sin(alpha) + y * Math::Cos(alpha) + y1;

			xb = x * Math::Cos(alpha) + y * Math::Sin(alpha) + x1;
			yb = -x * Math::Sin(alpha) + y * Math::Cos(alpha) + y1;

			gfx->DrawLine(Pens::Black, xn1, yn1, xn2, yn2);
			gfx->DrawLine(Pens::Black, x1, y1, xa, ya);
			gfx->DrawLine(Pens::Black, x1, y1, xb, yb);

			d = l / 2;

			xt = d * x0 / l + x1 - 3;
			yt = d * y0 / l + y1 + 3;
			gfx->DrawString(line->Num.ToString(), arial10, black, xt, yt);
		}
	}

	/*for each (auto gpoint in GPoint::Points) {
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
	}*/
	Graph::pictureBoxField->Image = image;
}

System::Void
Graph::InitDicts() {
	gcnew GPoint();
	gcnew Matrix();
	gcnew Node();
	gcnew Line();
}