#pragma once
#include "MyForm.h"

namespace UnikursLine
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Node
	{

	public:
		int X;
		int Y;
		Point^ Position;
	private:
		int circleWidth = 50;
		int circleHeight = 50;
		int circleCenterOffsetX = circleWidth / 2;
		int circleCenterOffsetY = circleHeight / 2;

	public:
		Node(Point^ position) {
			this->Position = position;
			X = position->X;
			Y = position->Y;
		}

		~Node() {

		}
	};

	// ¬ инициализации указать панель отрисовки
	public ref class Graph {
	private:
		PictureBox^ pictureBoxField;
		
		bool mousePressed = false;
	public:
		Generic::List<Node^>^ Nodes;

	public:	Graph(PictureBox^ pictureBoxField); 

		~Graph() {
			//delete pictureBoxField;
			//delete Nodes;
		}

		System::Void SetField(PictureBox^ pictureBoxField) {
			this->pictureBoxField = pictureBoxField;
		}

		System::Void AddNode() {
			int count = Nodes->Count;
			int magicNumber = 10;
			Point^ pos = gcnew Point(magicNumber * count, magicNumber * count);
			Node^ newnode = gcnew Node(pos);
		}

		System::Void pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		System::Void pictureBoxField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		System::Void pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		
	};
}