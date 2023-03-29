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
		MyForm::I->Update();
	}
}

System::Void  Graph::pictureBoxField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = false;
	//MyForm::I->label1->Text = L"Unpressed";
}
System::Void  Graph::pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->mousePressed = true;
};
System::Void Graph::pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->mousePressed) {
		int circleWidth = 50;
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
		this->pictureBoxField->Image = image;
		MyForm::I->Update();
	}
}









