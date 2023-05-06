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
		
	public:
		Matrix();
		Matrix(unsigned nodeNum, unsigned branchNum);
		Matrix(Panel^ panelMatrix, unsigned nodeNum, unsigned branchNum);

		static System::Void Clear();
		static System::Void Set(Element^ elem, int val);
		
	};
}

#endif // !ULMATRIX