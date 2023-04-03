#include "MyForm.h"
#include <Windows.h>

using namespace UnikursLine; // Название проекта
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm^ _mForm = gcnew MyForm();
	_mForm->InitGraph();
	Application::Run(_mForm);

	return 0;
}

System::Void
MyForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	SetConsoleOutputCP(1251);
	MessageBox::Show(
		"Дата созания: 25.01.2023\nВерсия: 1.0.0.\nРазрабочик: Метелев Петр Андреевич",
		"О программе"
	);
	SetConsoleOutputCP(886);
}

System::Void
MyForm::numericUpDownBranches_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	generateMatrix(sender, e);
}

System::Void
MyForm::numericUpDownNodes_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	generateMatrix(sender, e);
}



System::Void
MyForm::generateMatrix(System::Object^ sender, System::EventArgs^ e) {
	if (myDynamicObjs == nullptr) myDynamicObjs = gcnew Generic::List<Object^>();

	// Небезопасно ввиду ссылок на элементы/ через for по индексу сделать??
	for each (auto elem in myDynamicObjs) {
		this->panelMatrix->Controls->Remove((Control^)elem);
		this->panelHorizontal->Controls->Remove((Control^)elem);
		this->panelVertical->Controls->Remove((Control^)elem);
	}
	myDynamicObjs->Clear();

	int nodes = (int)this->numericUpDownNodes->Value;
	int branches = (int)this->numericUpDownBranches->Value;
	int width = 32;
	int height = 20;
	int offsetX = 4;
	int offsetY = 4;

	for (int i = 0; i < nodes; i++) {

		makeRowIndexLabel(i, height, offsetY, width);

		for (int j = 0; j < branches; j++) {
			System::Windows::Forms::TextBox^ tb;
			tb = (gcnew System::Windows::Forms::TextBox());
			this->panelMatrix->Controls->Add(tb);

			tb->Location = System::Drawing::Point(j * (width + offsetX) + width, i * (height + offsetY) + this->panelHorizontal->Size.Height);
			tb->Name = L"textBox" + i.ToString() + j.ToString();
			tb->Size = System::Drawing::Size(width, height);
			tb->Text = L"0";
			tb->AutoSize = false;
			tb->TabIndex = i * branches + j + 4;
			tb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			Update();

			//dynamicControls->push_back(tb);
			myDynamicObjs->Add(tb);

			// всё что ниже не выполнится для следующей строки
			if (i > 0) continue;
			makeColIndexLabel(j, width, offsetX);
		}
	}
}

System::Void
MyForm::makeColIndexLabel(int j, int width, int offsetX)
{
	System::Windows::Forms::Label^ colIndexLabel;
	colIndexLabel = (gcnew System::Windows::Forms::Label());
	this->panelHorizontal->Controls->Add(colIndexLabel);
	colIndexLabel->Location = System::Drawing::Point(j * (width + offsetX), 0);
	colIndexLabel->Name = L"labelHorizontal" + j.ToString();
	colIndexLabel->Size = System::Drawing::Size(width, 13);
	colIndexLabel->TabIndex = 100 + j;
	colIndexLabel->Text = L"" + (j + 1).ToString();
	colIndexLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

	Update();
	myDynamicObjs->Add(colIndexLabel);
	//dynamicControls->push_back(colIndexLabel);
}

System::Void
MyForm::makeRowIndexLabel(int i, int height, int offsetY, int width)
{
	System::Windows::Forms::Label^ rowIndexLabel;
	rowIndexLabel = (gcnew System::Windows::Forms::Label());
	this->panelVertical->Controls->Add(rowIndexLabel);
	rowIndexLabel->Location = System::Drawing::Point(0, i * (height + offsetY) + this->panelHorizontal->Size.Height);
	rowIndexLabel->Name = L"labelVertical" + i.ToString();
	rowIndexLabel->Size = System::Drawing::Size(width, height);
	rowIndexLabel->TabIndex = 200 + i;
	rowIndexLabel->Text = (i + 1).ToString();
	rowIndexLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

	Update();
	myDynamicObjs->Add(rowIndexLabel);
	//dynamicControls->push_back(rowIndexLabel);
}


System::Void
MyForm::onPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	int width = 50;
	int height = 50;
	Bitmap^ image = gcnew Bitmap(width, height);
	System::Drawing::Graphics^ gfx = Graphics::FromImage(image);
	System::Drawing::Brush^ brush = gcnew SolidBrush(Color::LightGray);
	System::Drawing::Brush^ darkGray = gcnew SolidBrush(Color::DarkGray);

	int fontSize = 20;
	System::Drawing::Font^ font = gcnew System::Drawing::Font("Verdana", (float)fontSize);

	gfx->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
	gfx->FillEllipse(brush, 0, 0, width, height);
	gfx->DrawEllipse(Pens::DarkGray, 0, 0, width, height);
	gfx->DrawString(L"1", font, darkGray, float(width - fontSize) / 2, (float)4);
	this->pictureBox1->Image = image;
}

System::Void
MyForm::makeGraphField(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	int width = 50;
	int height = 50;
	Bitmap^ image = gcnew Bitmap(width, height);
	System::Drawing::Graphics^ gfx = Graphics::FromImage(image);
	System::Drawing::Brush^ brush = gcnew SolidBrush(Color::LightGray);
	System::Drawing::Brush^ darkGray = gcnew SolidBrush(Color::DarkGray);

	gfx->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
	gfx->FillEllipse(brush, 0, 0, width, height);
	gfx->DrawEllipse(Pens::DarkGray, 0, 0, width, height);
	this->pictureBoxMain->Image = image;

}

System::Void
MyForm::makePictureBox() {
	System::Windows::Forms::PictureBox^ pb = (gcnew System::Windows::Forms::PictureBox());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(pb))->BeginInit();

	pb->Location = System::Drawing::Point(26, 19);
	pb->Name = L"pictureBox1";
	pb->Size = System::Drawing::Size(49, 50);
	pb->TabIndex = 0;
	pb->TabStop = false;

	//pb->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);

	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(pb))->EndInit();
}

System::Void
MyForm::panel1_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
	//System::Windows::Forms::MessageBox::Show(e->Data->GetFormats()[0]);

}



System::Void
MyForm::pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (mouseDown) {
		((Control^)sender)->Left = e->X + pictureBox1->Left - mouseDownLocation.X;
		((Control^)sender)->Top = e->Y + pictureBox1->Top - mouseDownLocation.Y;
		if (((Control^)sender)->Left <= 0) {
			((Control^)sender)->Left = 0;
		}
		if (((Control^)sender)->Top <= 0) {
			((Control^)sender)->Top = 0;
		}
		if (((Control^)sender)->Left > pictureBox1->Parent->Size.Width - pictureBox1->Size.Width) {
			((Control^)sender)->Left = pictureBox1->Parent->Size.Width - pictureBox1->Size.Width;
		}
		if (((Control^)sender)->Top > pictureBox1->Parent->Size.Height - pictureBox1->Size.Height) {
			((Control^)sender)->Top = pictureBox1->Parent->Size.Height - pictureBox1->Size.Height;
		}
	}
}

System::Void
MyForm::pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mouseDown = true;
	mouseDownLocation = e->Location;
}
System::Void
MyForm::pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	mouseDown = false;
}

System::Void
MyForm::pictureBoxMain_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	labelCoordinates->Text = (e->X).ToString() + L"; " + (e->Y).ToString();

	/*		int circleWidth = 50;
			int circleHeight = 50;

			int circleCenterOffsetX = circleWidth / 2;
			int circleCenterOffsetY = circleHeight / 2;

			Bitmap^ image = (Bitmap^)(this->pictureBoxMain->Image);
			if (image == nullptr) {
				image = gcnew Bitmap(((Control^)sender)->Size.Width, ((Control^)sender)->Size.Height);
			}
			System::Drawing::Graphics^ gfx = Graphics::FromImage(image);

			System::Drawing::Brush^ brush = gcnew SolidBrush(Color::LightGray);
			System::Drawing::Brush^ darkGray = gcnew SolidBrush(Color::DarkGray);
			gfx->Clear(Color::White);
			gfx->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			gfx->FillEllipse(brush, e->X - circleCenterOffsetX, e->Y - circleCenterOffsetY, circleWidth, circleHeight);
			gfx->DrawEllipse(Pens::DarkGray, e->X - circleCenterOffsetX, e->Y - circleCenterOffsetY, circleWidth, circleHeight);



			this->pictureBoxMain->Image = image; */
}
System::Void
MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(
		"Zetros",
		"Info"
	);
}
/// <summary>
/// Инициализирует поле графа
/// </summary>
/// <returns>System::Void</returns>




System::Void
MyForm::InitGraph() {
	Graph^ gr = gcnew Graph(this->pictureBoxMain);
}