#pragma once
#include "Element.h"

#ifndef ULMATRIX
#define ULMATRIX

namespace UnikursLine {
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;

	static ref class Matrix {
	private:
		static Panel^ panelMatrix;
	public: 
		static Dictionary <Element^, int>^ matrix;
		//static array<int, 2>^ adjMatrix;
		
	public:
		Matrix();
		Matrix(unsigned nodeNum, unsigned branchNum);
		Matrix(Panel^ panelMatrix, unsigned nodeNum, unsigned branchNum);

		static System::Void Clear();
		static System::Void Set(Element^ elem, int val);
		static unsigned Deg(unsigned nodeNum);
		static array < array<int>^ >^ GetAdjMatrix();
	};
}

#endif // !ULMATRIX