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

		AddNode();
		AddNode();
		AddNode();
		AddNode();
		AddNode();

		MyForm::I->Update();
	}
}

Graph::~Graph() {

}

System::Void  
Graph::pictureBoxField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = false;
	this->MovableNode = nullptr;
}

System::Void  
Graph::pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = true;
	Node^ near_node = nullptr;
	const float MAX_DIST = 50.0;
	float nearest_point = MAX_DIST;
	for each (auto node in Nodes) {
		float radius = node->DistanceFromCenter(Point(e->X, e->Y));
		if (radius != -1.0) {
			if (radius < nearest_point) {
				near_node = node;
			}
		}
	}
	if (near_node != nullptr) {
		this->MovableNode = near_node;
	}
}

System::Void 
Graph::pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->mousePressed) {
		if (this->MovableNode != nullptr) {
			this->MovableNode->SetPosition(Point(e->X, e->Y));
			this->RedrawGraph();
			//this->Refresh();
		}
		/*int circleWidth = 50;
		int circleHeight = 50;
		int circleCenterOffsetX = circleWidth / 2;
		int circleCenterOffsetY = circleHeight / 2;

		System::Drawing::Brush^ brush = gcnew SolidBrush(Color::LightGray);
		System::Drawing::Brush^ darkGray = gcnew SolidBrush(Color::DarkGray);

		Bitmap^ image = (Bitmap^)(pictureBoxField->Image);
		if (image == nullptr) {
			image = gcnew Bitmap(((Control^)sender)->Size.Width, ((Control^)sender)->Size.Height);
			MyForm::I->label1->Text = ((Control^)sender)->Size.Width.ToString() + L" " + ((Control^)sender)->Size.Height.ToString();
		}

		Graphics^ gfx = Graphics::FromImage(image);
		gfx->Clear(Color::White);
		gfx->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
		gfx->FillEllipse(brush, e->X - circleCenterOffsetX, e->Y - circleCenterOffsetY, circleWidth, circleHeight);
		gfx->DrawEllipse(Pens::DarkGray, e->X - circleCenterOffsetX, e->Y - circleCenterOffsetY, circleWidth, circleHeight);
		this->pictureBoxField->Image = image;*/
		MyForm::I->Update();
	}
}

System::Void 
Graph::AddNode() {
	int count = Nodes->Count;
	int magicNumber = 10;
	Point^ pos = gcnew Point(magicNumber * count + 50, magicNumber * count + 50);
	Node^ newnode = gcnew Node(pos);
	Nodes->Add(newnode);

	//this->Refresh();
}

System::Void
Graph::AddPointToGraph() {
	int count = Points->Count;
	int magicNumber = 20;
	Point^ pos = gcnew Point(magicNumber * count + 50, magicNumber * count + 50);
	GPoint^ newPoint = gcnew GPoint(pos);

	//this->Refresh();
	this->RedrawGraph();
}

System::Void
Graph::AddNodeToGraph(Node^ node) {
	int count = Points->Count;
	int magicNumber = 20;
	Point^ pos = gcnew Point(magicNumber * count + 50, magicNumber * count + 50);
	Node^ newnode = gcnew Node(pos);
	GPoint^ newPoint = gcnew GPoint(newnode);

	this->Refresh();

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
			int pointSize = 2;
			gfx->FillEllipse(black, gp->X - pointSize - 1, gp->Y - pointSize - 1, pointSize, pointSize);
			gfx->DrawEllipse(Pens::Black, gp->X - pointSize - 1, gp->Y - pointSize - 1, pointSize, pointSize);
		}
	}
	this->pictureBoxField->Image = image;
}