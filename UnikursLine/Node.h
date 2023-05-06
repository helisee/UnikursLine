#pragma once

#ifndef ULNODE
#define ULNODE

namespace UnikursLine {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Node
	{	
	public:
		unsigned Num;
		int X;
		int Y;
		Point^ Position;

		static Generic::List<Node^>^ Nodes;
	public:
		static int circleRadius = 25;
		static int circleDiameter = 2 * circleRadius;

	public:
		Node();
		Node(Point^ position);
		Node(int number);

		~Node();

		static Node^ GetNode(unsigned number);
		static System::Void Clear();

		System::Void SetPosition(Point^ position);

	public:
		/// <summary>
		/// ��������� ���������� �� ������ ������� ����
		/// </summary>
		/// <param name="position">����������� �����</param>
		/// <returns>���������� ���������� �� ������ ������� ���� ��� -1, ���� ����� �� �������� � ����</returns>
		float DistanceFromCenter(System::Drawing::Point^ position);
	
	};
}

#endif