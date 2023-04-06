#include "Matrix.h"

using namespace UnikursLine;

Matrix::Matrix() {
	this->matrix = gcnew Dictionary <Element^, int>();
}

Matrix::Matrix(unsigned nodeCount, unsigned branchCount) {
	if (this->matrix == nullptr) this->matrix = gcnew Dictionary <Element^, int>();
	this->matrix->Clear();

	// дублирующий функционал ...
	for (unsigned node = 1; node <= nodeCount; node++) {
		for (unsigned branch = 1; branch <= branchCount; branch++) {

		}
	}
}

Matrix::Matrix(Panel^ panelMatrix, unsigned nodeCount, unsigned branchCount) {
	this->panelMatrix = panelMatrix;
	this->matrix = gcnew Dictionary <Element^, int>();

	
}