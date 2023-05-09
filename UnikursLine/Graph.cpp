#include "Graph.h"

using namespace UnikursLine;

Graph::Graph(PictureBox^ pictureBoxField) {

	this->pictureBoxField = pictureBoxField;

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
	this->MoveNode = nullptr;
	MyForm::I->label1->Text = L"Zetros";
}

System::Void
Graph::pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = true;

	Node^ nearMoveNode = nullptr;
	float nearestObjectDistance = (float)Node::circleDiameter;

	for each (auto node in Node::Nodes) {
		Point^ pos = Point(e->X, e->Y);
		float distance = node->DistanceFromCenter(pos);
		if (distance < nearestObjectDistance) nearMoveNode = node;
		MyForm::I->Update();
	}

	if (nearMoveNode != nullptr) this->MoveNode = nearMoveNode;
}

System::Void
Graph::pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

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

	Bitmap^ image = (Bitmap^)(pictureBoxField->Image);

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

		gfx->DrawString(node->Num.ToString(), arial16, black, (float)node->X - 10, (float)node->Y - 10);
	}

	for each (auto line in Line::Lines) {
		if (line->From != nullptr && line->To != nullptr) {

			auto from = line->From->Position;
			auto to = line->To->Position;
			float alpha, b, l, x, y, x0, y0, x1, y1, x2, y2, xa, ya, xb, yb, xn1, yn1, xn2, yn2, xt, yt, d;

			b = (float)line->From->circleRadius;
			x0 = (float)to->X - (float)from->X;
			y0 = (float)to->Y - (float)from->Y;
			l = (float)Math::Sqrt(x0 * x0 + y0 * y0);
			xn1 = b * x0 / l + from->X;
			yn1 = b * y0 / l + from->Y;

			xn2 = x0 * (l - b) / l + from->X;
			yn2 = y0 * (l - b) / l + from->Y;

			b = 10;
			alpha = 0.5236f; // 30 градусов
			x1 = xn2;
			y1 = yn2;

			x2 = (float)from->X;
			y2 = (float)from->Y;

			x0 = x2 - x1;
			y0 = y2 - y1;

			l = (float)Math::Sqrt(x0 * x0 + y0 * y0);

			x = b * x0 / l;
			y = b * y0 / l;

			xa = x * (float)Math::Cos(alpha) - y * (float)Math::Sin(alpha) + x1;
			ya = x * (float)Math::Sin(alpha) + y * (float)Math::Cos(alpha) + y1;

			xb = x * (float)Math::Cos(alpha) + y * (float)Math::Sin(alpha) + x1;
			yb = -x * (float)Math::Sin(alpha) + y * (float)Math::Cos(alpha) + y1;

			gfx->DrawLine(Pens::Black, xn1, yn1, xn2, yn2);
			//gfx->DrawLine(Pens::Black, x1, y1, xa, ya);
			//gfx->DrawLine(Pens::Black, x1, y1, xb, yb);

			d = l / 2;

			xt = d * x0 / l + x1 - 3;
			yt = d * y0 / l + y1 + 3;
			gfx->DrawString(line->Num.ToString(), arial10, black, xt, yt);
		}
	}
	Graph::pictureBoxField->Image = image;
}

System::Void
Graph::InitDicts() {
	gcnew GPoint();
	gcnew Matrix();
	gcnew Node();
	gcnew Line();
}

bool
Graph::CheckForEulerPath() {
	int oddVertex = 0;
	for each (auto node in Node::Nodes) {
		int nodeNum = node->Num;
		unsigned deg = Matrix::Deg(nodeNum);
		if (deg % 2 == 1) oddVertex++;
	}
	if (oddVertex > 2) return false;

	array< array<int>^ >^ adjMatr = Matrix::GetAdjMatrix();

	int size = Node::Nodes->Count;
	array < bool >^ visited = gcnew array < bool >(size);
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < size; i++) {
		unsigned deg = Matrix::Deg(i + 1);
		if (deg > 0) {
			DFS(i, adjMatr, visited);
			break;
		}
	}

	for (int i = 0; i < size; i++) {
		unsigned deg = Matrix::Deg(i + 1);
		if (deg > 0 && visited[i] == false) {
			return false;
		}
	}
	return true;
}

System::Void
Graph::DFS(int vertex, array< array<int>^ >^ v, array <bool>^ visited) {
	visited[vertex] = true;
	for (int i = 0; i < v[0]->Length; i++) {
		if (v[vertex][i] != 0 && visited[i] == false) {
			DFS(i, v, visited);
		}
	}
}

System::Void 
Graph::FindEulerPath() {
	Generic::Stack<int>^ st = gcnew Generic::Stack<int>();
	array< array<int>^ >^ v = Matrix::GetAdjMatrix();
	unsigned start = 0;
	for (int u = 0; u < v[0]->Length; u++) {
		unsigned deg = Matrix::Deg(u + 1);
		if (deg % 2 == 1) {
			start = u;
			break;
		}
	}
	array< array<int>^ >^ e = v;
	st->Push(start);

	while (st->Count != 0) {
		unsigned w = st->Peek();
		bool found = false;

		for (int u = 0; u < v[0]->Length; u++) {
			if (e[w][u] != 0) {
				st->Push(u);
				e[w][u] = 0;
				e[u][w] = 0;
				found = true;
				break;
			}
		}

		if (found == false) {
			st->Pop();
			//MyForm::I->labelCoordinates->Text = L"";
			String^ str = MyForm::I->labelCoordinates->Text;
			if (str == L"")
				MyForm::I->labelCoordinates->Text = (w+1).ToString();
			else
				MyForm::I->labelCoordinates->Text = str + L"->" + (w + 1).ToString();
		}
	}
}