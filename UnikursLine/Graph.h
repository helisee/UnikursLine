#pragma once
#include "Node.h"
#include "GPoint.h"
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
	public:
		Node^ MovableNode = nullptr;
		Generic::List<Node^ > ^ Nodes;
		Generic::List<GPoint^ > ^ Points;


	public:	Graph(PictureBox^ pictureBoxField); 
		~Graph();
		System::Void AddNode();

		/// <summary>
		/// Add empty point to graph
		/// </summary>
		System::Void AddPointToGraph();

		/// <summary>
		/// Add node to graph
		/// </summary>
		/// <param name="node">Óחוכ דנאפא</param>
		/// <returns></returns>
		System::Void AddNodeToGraph(Node^ node);

		System::Void Refresh();
		System::Void RedrawGraph();


	private:
		System::Void pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		System::Void pictureBoxField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		System::Void pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		
	};
}

#endif