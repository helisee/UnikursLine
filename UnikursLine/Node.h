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
		int X;
		int Y;
		Point^ Position;

	public:
		//int circleWidth = 50;
		//int circleHeight = 50;
		//int circleCenterOffsetX = circleWidth / 2;
		//int circleCenterOffsetY = circleHeight / 2;
		static int circleRadius = 25;
		static int circleDiameter = 2 * circleRadius;

	public:
		Node(Point^ position);
		~Node();
		System::Void SetPosition(Point^ position);


	public:
		/// <summary>
		/// ¬ычисл€ет рассто€ние от центра позиции узла
		/// </summary>
		/// <param name="position">¬ычисл€ема€ точка</param>
		/// <returns>¬озвращает рассто€ние от центра позиции узла или -1, если точка не попадает в узел</returns>
		float DistanceFromCenter(Point^ position);
	
	};
}

#endif