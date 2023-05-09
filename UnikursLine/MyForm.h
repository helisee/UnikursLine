#pragma once
#include <string.h>
#include "windows.h"
#include "Node.h"
#include "Graph.h"
#include "Element.h" 
#include <cliext/list>

#ifndef ULFORM
#define ULFORM

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
		static MyForm^ I;

		MyForm(void)
		{
			I = this;
			InitializeComponent();
			InitGraph();
		}

	protected:
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

	public: System::Windows::Forms::NumericUpDown^ numericUpDownBranches;
	public: System::Windows::Forms::NumericUpDown^ numericUpDownNodes;
	private: System::Windows::Forms::Panel^ panelMatrix;

	private: System::Windows::Forms::Panel^ panelHorizontal;

	private: System::Windows::Forms::Panel^ panelVertical;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	public: System::Windows::Forms::Panel^ panel1;

	public: System::Windows::Forms::PictureBox^ pictureBoxMain;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	public: System::Windows::Forms::Label^ labelCoordinates;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ labelM;
	private: System::Windows::Forms::Button^ buttonEvalPath;
	public:

	public:

	private: System::Windows::Forms::Button^ buttonCheck;
	private: System::Windows::Forms::Label^ labelCheck;
	public:

	public:

	public:

	public:
	private: System::ComponentModel::IContainer^ components;

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
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxMatrix = (gcnew System::Windows::Forms::GroupBox());
			this->labelCheck = (gcnew System::Windows::Forms::Label());
			this->labelCoordinates = (gcnew System::Windows::Forms::Label());
			this->buttonEvalPath = (gcnew System::Windows::Forms::Button());
			this->buttonCheck = (gcnew System::Windows::Forms::Button());
			this->labelM = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelMatrix = (gcnew System::Windows::Forms::Panel());
			this->panelHorizontal = (gcnew System::Windows::Forms::Panel());
			this->panelVertical = (gcnew System::Windows::Forms::Panel());
			this->labelBranches = (gcnew System::Windows::Forms::Label());
			this->numericUpDownBranches = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownNodes = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelNodes = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxMain = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxMatrix->SuspendLayout();
			this->panelMatrix->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBranches))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownNodes))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(68, 20);
			this->toolStripMenuItem1->Text = L"Помощь";
			// 
			// groupBoxMatrix
			// 
			this->groupBoxMatrix->Controls->Add(this->labelCheck);
			this->groupBoxMatrix->Controls->Add(this->labelCoordinates);
			this->groupBoxMatrix->Controls->Add(this->buttonEvalPath);
			this->groupBoxMatrix->Controls->Add(this->buttonCheck);
			this->groupBoxMatrix->Controls->Add(this->labelM);
			this->groupBoxMatrix->Controls->Add(this->label1);
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
			// 
			// labelCheck
			// 
			this->labelCheck->AutoSize = true;
			this->labelCheck->Location = System::Drawing::Point(12, 391);
			this->labelCheck->Name = L"labelCheck";
			this->labelCheck->Size = System::Drawing::Size(99, 13);
			this->labelCheck->TabIndex = 10;
			this->labelCheck->Text = L"Граф не проверен";
			// 
			// labelCoordinates
			// 
			this->labelCoordinates->Location = System::Drawing::Point(12, 404);
			this->labelCoordinates->Name = L"labelCoordinates";
			this->labelCoordinates->Size = System::Drawing::Size(326, 24);
			this->labelCoordinates->TabIndex = 6;
			// 
			// buttonEvalPath
			// 
			this->buttonEvalPath->Enabled = false;
			this->buttonEvalPath->Location = System::Drawing::Point(223, 354);
			this->buttonEvalPath->Name = L"buttonEvalPath";
			this->buttonEvalPath->Size = System::Drawing::Size(109, 23);
			this->buttonEvalPath->TabIndex = 9;
			this->buttonEvalPath->Text = L"Рассчитать путь";
			this->buttonEvalPath->UseVisualStyleBackColor = true;
			this->buttonEvalPath->Click += gcnew System::EventHandler(this, &MyForm::buttonEvalPath_Click);
			// 
			// buttonCheck
			// 
			this->buttonCheck->Enabled = false;
			this->buttonCheck->Location = System::Drawing::Point(9, 354);
			this->buttonCheck->Name = L"buttonCheck";
			this->buttonCheck->Size = System::Drawing::Size(109, 23);
			this->buttonCheck->TabIndex = 7;
			this->buttonCheck->Text = L"Проверить";
			this->buttonCheck->UseVisualStyleBackColor = true;
			this->buttonCheck->Click += gcnew System::EventHandler(this, &MyForm::buttonCheck_Click);
			// 
			// labelM
			// 
			this->labelM->Location = System::Drawing::Point(199, 16);
			this->labelM->Name = L"labelM";
			this->labelM->Size = System::Drawing::Size(133, 66);
			this->labelM->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(124, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 7;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// panelMatrix
			// 
			this->panelMatrix->AutoScroll = true;
			this->panelMatrix->Controls->Add(this->panelHorizontal);
			this->panelMatrix->Controls->Add(this->panelVertical);
			this->panelMatrix->Location = System::Drawing::Point(6, 85);
			this->panelMatrix->Name = L"panelMatrix";
			this->panelMatrix->Size = System::Drawing::Size(332, 263);
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
			this->panelVertical->Size = System::Drawing::Size(32, 263);
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
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(228, 127);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 50);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
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
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
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
			this->groupBoxMatrix->ResumeLayout(false);
			this->groupBoxMatrix->PerformLayout();
			this->panelMatrix->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownBranches))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownNodes))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		bool mouseDown = false;
		Point mouseDownLocation;
		Generic::List<Object^>^ myDynamicObjs;
		Generic::Dictionary<TextBox^, int>^ matrix;

	private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numericUpDownBranches_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numericUpDownNodes_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void generateMatrix(System::Object^ sender, System::EventArgs^ e);
	private: System::Void makeColIndexLabel(int j, int width, int offsetX);
	private: System::Void makeRowIndexLabel(int i, int height, int offsetY, int width);
	private: System::Void onPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void makeGraphField(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
	private: System::Void makePictureBox();
	private: System::Void panel1_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void pictureBoxMain_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void InitGraph();
		   //private: System::Void tbMatrix_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void buttonCheck_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonEvalPath_Click(System::Object^ sender, System::EventArgs^ e);
	public: System::Void EnableButtons(bool enabled);
};

}

#endif