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
		/// ¬ычисл€ет рассто€ние от центра позиции узла
		/// </summary>
		/// <param name="position">¬ычисл€ема€ точка</param>
		/// <returns>¬озвращает рассто€ние от центра позиции узла или -1, если точка не попадает в узел</returns>
		float DistanceFromCenter(System::Drawing::Point^ position);
	
	};
}

#endif