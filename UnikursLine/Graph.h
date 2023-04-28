#pragma once
#include "GPoint.h"
#include "Node.h"
#include "MyForm.h"
#include <cliext/list>

#ifndef ULGRAPH_H
#define ULGRAPH_H

namespace UnikursLine
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Graph {
	private:
		PictureBox^ pictureBoxField;
		bool mousePressed = false;
	public: GPoint^ MovableObject = nullptr;
	public:	static Generic::List<Node^ > ^ Nodes;

	public:	Graph(PictureBox^ pictureBoxField); 
		~Graph();
		// System::Void AddNode();

		/// <summary>
		/// Add empty point to graph
		/// </summary>
		System::Void AddPoint();

		System::Void AddNode();

		System::Void AddLine();
		/// <summary>
		/// Add node to graph
		/// </summary>
		/// <param name="node">���� �����</param>
		/// <returns></returns>
		System::Void AddNode(Node^ node);

		System::Void Refresh();
		System::Void RedrawGraph();

	private:
		System::Void pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		System::Void pictureBoxField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		System::Void pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		
	};
}

#endif