#include "Matrix.h"

using namespace UnikursLine;

Matrix::Matrix() {
	this->matrix = gcnew Dictionary <Element^, int>();
}

Matrix::Matrix(unsigned nodeCount, unsigned branchCount) {
	if (this->matrix == nullptr) this->matrix = gcnew Dictionary <Element^, int>();
	this->matrix->Clear();

/*	// ����������� ���������� ...
	for (unsigned node = 1; node <= nodeCount; node++) {
		for (unsigned branch = 1; branch <= branchCount; branch++) {

		}
	}
	*/
}

Matrix::Matrix(Panel^ panelMatrix, unsigned nodeCount, unsigned branchCount) {
	this->panelMatrix = panelMatrix;
	this->matrix = gcnew Dictionary <Element^, int>();
}

System::Void 
Matrix::Clear() {
	// ����� ������� �������� element?
	matrix->Clear();
}

System::Void 
Matrix::Set(Element^ elem, int val) {
	if (matrix->ContainsKey(elem)) {
		matrix[elem] = val;

		// ������������ ����� �����
		// ����� ��/��
	}
	else {
		matrix->Add(elem, val);

		// ������������ ���� ����� 
		// ����� �� � ��
	}
}

System::Void
ChangeLine(Element^ elem, int val) {
	if (val == -1) {
		// ������������ ����� �� ����
	}
	else if (val == 1) {
		// ������������ ����� �� ����
	}
	else {
		// �������� �����
	}
}



