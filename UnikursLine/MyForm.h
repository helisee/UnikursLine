#pragma once
#include <string.h>
#include "windows.h"
#include <cliext/list>

namespace UnikursLine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBoxMatrix;
	private: System::Windows::Forms::Label^ labelNodes;
	private: System::Windows::Forms::Label^ labelBranches;

	private: System::Windows::Forms::NumericUpDown^ numericUpDownBranches;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownNodes;
	private: System::Windows::Forms::Panel^ panelMatrix;

	private: System::Windows::Forms::Panel^ panelHorizontal;

	private: System::Windows::Forms::Panel^ panelVertical;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBoxMain;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ labelCoordinates;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;
	
	
	
	//private: cli::array<Object^>^ myDynamicObjs;
	//private: cliext::list<Object^>^ dynamicControls;

	protected:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->groupBoxMatrix->SuspendLayout();
			this->panelMatrix->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBranches))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownNodes))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1013, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(68, 20);
			this->toolStripMenuItem1->Text = L"Помощь";
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
			// 
			// groupBoxMatrix
			// 
			this->groupBoxMatrix->Controls->Add(this->label1);
			this->groupBoxMatrix->Controls->Add(this->labelCoordinates);
			this->groupBoxMatrix->Controls->Add(this->panelMatrix);
			this->groupBoxMatrix->Controls->Add(this->labelBranches);
			this->groupBoxMatrix->Controls->Add(this->numericUpDownBranches);
			this->groupBoxMatrix->Controls->Add(this->numericUpDownNodes);
			this->groupBoxMatrix->Controls->Add(this->labelNodes);
			this->groupBoxMatrix->Location = System::Drawing::Point(23, 42);
			this->groupBoxMatrix->Name = L"groupBoxMatrix";
			this->groupBoxMatrix->Size = System::Drawing::Size(338, 446);
			this->groupBoxMatrix->TabIndex = 1;
			this->groupBoxMatrix->TabStop = false;
			this->groupBoxMatrix->Text = L" Матрица";
			this->groupBoxMatrix->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(274, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Zetros";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// labelCoordinates
			// 
			this->labelCoordinates->AutoSize = true;
			this->labelCoordinates->Location = System::Drawing::Point(152, 23);
			this->labelCoordinates->Name = L"labelCoordinates";
			this->labelCoordinates->Size = System::Drawing::Size(35, 13);
			this->labelCoordinates->TabIndex = 6;
			this->labelCoordinates->Text = L"label1";
			// 
			// panelMatrix
			// 
			this->panelMatrix->AutoScroll = true;
			this->panelMatrix->Controls->Add(this->panelHorizontal);
			this->panelMatrix->Controls->Add(this->panelVertical);
			this->panelMatrix->Location = System::Drawing::Point(6, 85);
			this->panelMatrix->Name = L"panelMatrix";
			this->panelMatrix->Size = System::Drawing::Size(332, 300);
			this->panelMatrix->TabIndex = 5;
			// 
			// panelHorizontal
			// 
			this->panelHorizontal->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelHorizontal->Location = System::Drawing::Point(32, 0);
			this->panelHorizontal->Name = L"panelHorizontal";
			this->panelHorizontal->Size = System::Drawing::Size(300, 20);
			this->panelHorizontal->TabIndex = 2;
			// 
			// panelVertical
			// 
			this->panelVertical->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelVertical->Location = System::Drawing::Point(0, 0);
			this->panelVertical->Name = L"panelVertical";
			this->panelVertical->Size = System::Drawing::Size(32, 300);
			this->panelVertical->TabIndex = 1;
			// 
			// labelBranches
			// 
			this->labelBranches->AutoSize = true;
			this->labelBranches->Location = System::Drawing::Point(6, 51);
			this->labelBranches->Name = L"labelBranches";
			this->labelBranches->Size = System::Drawing::Size(46, 13);
			this->labelBranches->TabIndex = 4;
			this->labelBranches->Text = L"Ветвей:";
			// 
			// numericUpDownBranches
			// 
			this->numericUpDownBranches->Location = System::Drawing::Point(70, 49);
			this->numericUpDownBranches->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDownBranches->Name = L"numericUpDownBranches";
			this->numericUpDownBranches->Size = System::Drawing::Size(48, 20);
			this->numericUpDownBranches->TabIndex = 3;
			this->numericUpDownBranches->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownBranches_ValueChanged);
			// 
			// numericUpDownNodes
			// 
			this->numericUpDownNodes->Location = System::Drawing::Point(70, 23);
			this->numericUpDownNodes->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownNodes->Name = L"numericUpDownNodes";
			this->numericUpDownNodes->Size = System::Drawing::Size(48, 20);
			this->numericUpDownNodes->TabIndex = 2;
			this->numericUpDownNodes->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownNodes->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownNodes_ValueChanged);
			// 
			// labelNodes
			// 
			this->labelNodes->AutoSize = true;
			this->labelNodes->Location = System::Drawing::Point(6, 25);
			this->labelNodes->Name = L"labelNodes";
			this->labelNodes->Size = System::Drawing::Size(42, 13);
			this->labelNodes->TabIndex = 0;
			this->labelNodes->Text = L"Узлов:";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBoxMain);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(367, 42);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(634, 456);
			this->panel1->TabIndex = 2;
			this->panel1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MyForm::panel1_DragEnter);
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::onPaint);
			// 
			// pictureBoxMain
			// 
			this->pictureBoxMain->Location = System::Drawing::Point(75, 0);
			this->pictureBoxMain->Name = L"pictureBoxMain";
			this->pictureBoxMain->Size = System::Drawing::Size(498, 456);
			this->pictureBoxMain->TabIndex = 1;
			this->pictureBoxMain->TabStop = false;
			this->pictureBoxMain->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBoxMain_MouseMove);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(228, 127);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 50);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(17, 9);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(55, 55);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1013, 547);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBoxMatrix);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Unikurs Line";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxMatrix->ResumeLayout(false);
			this->groupBoxMatrix->PerformLayout();
			this->panelMatrix->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBranches))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownNodes))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			SetConsoleOutputCP(1251);
			MessageBox::Show(
				"Дата созания: 25.01.2023\nВерсия: 1.0.0.\nРазрабочик: Метелев Петр Андреевич",
				"О программе" 
			);
			SetConsoleOutputCP(886);
		}
		private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
		}

		private: System::Void numericUpDownBranches_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			generateMatrix(sender, e);
		}
		//numericUpDown2_ValueChanged
		private: System::Void numericUpDownNodes_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			generateMatrix(sender, e);
		}

		Generic::List<Object^>^ myDynamicObjs;

		private: System::Void generateMatrix(System::Object^ sender, System::EventArgs^ e) {
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

		private: System::Void  makeColIndexLabel(int j, int width, int offsetX)
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

		private: System::Void makeRowIndexLabel(int i, int height, int offsetY, int width)
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
		   

		private: System::Void onPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			
			int width = 50;
			int height = 50;
			Bitmap^ image = gcnew Bitmap(width, height);
			System::Drawing::Graphics^ gfx = Graphics::FromImage(image);
			System::Drawing::Brush^ brush = gcnew SolidBrush(Color::LightGray);
			System::Drawing::Brush^ darkGray = gcnew SolidBrush(Color::DarkGray);

			int fontSize = 20;
			System::Drawing::Font^ font = gcnew System::Drawing::Font("Verdana", fontSize);
			
			gfx->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
			gfx->FillEllipse(brush, 0, 0, width, height);
			gfx->DrawEllipse(Pens::DarkGray, 0, 0, width, height);
			gfx->DrawString(L"1", font, darkGray, (width - fontSize)/2, 4);
			this->pictureBox1->Image = image;

			
		}
		
		private: System::Void makeGraphField(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
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

		private: System::Void makePictureBox() {
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
		
		private: System::Void panel1_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
			//System::Windows::Forms::MessageBox::Show(e->Data->GetFormats()[0]);
		
		}
		
	private: 
		bool mouseDown = false;
		Point mouseDownLocation;
		
		private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
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
		
		private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			mouseDown = true;
			mouseDownLocation = e->Location;
		}
		private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			mouseDown = false;
		}

	private: System::Void pictureBoxMain_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		labelCoordinates->Text = (e->X).ToString() + L"; " + (e->Y).ToString();

		int circleWidth = 50;
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

		

		this->pictureBoxMain->Image = image;
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(
		"Zetros",
		"Info"
	);
}
};

}
