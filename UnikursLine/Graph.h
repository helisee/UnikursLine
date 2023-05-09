#pragma once
#include "GPoint.h"
#include "Node.h"
#include "MyForm.h"
#include "Line.h"
#include "Element.h"
#include "Matrix.h"
#include <cliext/list>

#ifndef ULGRAPH_H
#define ULGRAPH_H

namespace UnikursLine
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Graph {
	private:
		static PictureBox^ pictureBoxField;
		bool mousePressed = false;
	public: Node^ MoveNode = nullptr;

	public:	Graph(PictureBox^ pictureBoxField); 
		~Graph();
		// System::Void AddNode();

		/// <summary>
		/// Add empty point to graph
		/// </summary>
		System::Void AddPoint();

		System::Void AddNode();

		/// <summary>
		/// Add node to graph
		/// </summary>
		/// <param name="node">Óחוכ דנאפא</param>
		/// <returns></returns>
		System::Void AddNode(Node^ node);

		System::Void Refresh();
		static System::Void RedrawGraph();

	private:
		System::Void pictureBoxField_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		System::Void pictureBoxField_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 
		System::Void pictureBoxField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); 

		System::Void InitDicts();
	public:
		static bool CheckForEulerPath();
		static System::Void DFS(int vertex, array< array<int>^ >^ v, array <bool>^ visited);
		static System::Void FindEulerPath( );

		
	};
}

#endif