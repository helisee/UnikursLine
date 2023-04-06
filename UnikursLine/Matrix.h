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
	protected: 
		static Dictionary <Element^, int>^ matrix;
	
	public:
		Matrix();
		Matrix(unsigned nodeNum, unsigned branchNum);
		Matrix(Panel^ panelMatrix, unsigned nodeNum, unsigned branchNum);

		//System::Void Add();
	};
}

#endif // !ULMATRIX