#include "Matrix.h"
#include "Line.h"
#include "MyForm.h"

using namespace UnikursLine;

Matrix::Matrix() {
	this->matrix = gcnew Dictionary <Element^, int>();
}

Matrix::Matrix(unsigned nodeCount, unsigned branchCount) {
	if (this->matrix == nullptr) this->matrix = gcnew Dictionary <Element^, int>();
	this->matrix->Clear();
}

Matrix::Matrix(Panel^ panelMatrix, unsigned nodeCount, unsigned branchCount) {
	this->panelMatrix = panelMatrix;
	this->matrix = gcnew Dictionary <Element^, int>();
}

System::Void
Matrix::Clear() {
	matrix->Clear();
}

System::Void
Matrix::Set(Element^ elem, int val) {

	if (matrix->ContainsKey(elem)) {
		Line^ line = Line::GetLine(elem->BranchNumer);
		Node^ mnode = Node::GetNode(elem->NodeNumber);

		Element^ changeElem;
		if (val == 1) {

			for each (auto ielem in matrix->Keys) {
				if (ielem->BranchNumer == elem->BranchNumer && matrix[ielem] == val) {
					changeElem = ielem;//matrix[ielem] = 0;
					break;
				}
			}

			line->From = mnode;
			//matrix[changeElem] = 0;
			
		}
		else if (val == -1) {

			for each (auto ielem in matrix->Keys) {
				if (ielem->BranchNumer == elem->BranchNumer && matrix[ielem] == val) {
					changeElem = ielem; //matrix[ielem] = 0;
					break;
				}
			}

			//matrix[changeElem] = 0;
			line->To = mnode;
		}
		// чистим направление ветки
		else if (val == 0) {
			if (Matrix::matrix[elem] == -1) {
				line->To = nullptr;
			}
			else if (Matrix::matrix[elem] == 1) {
				line->From = nullptr;
			}
		}
		matrix[elem] = val;
		if (changeElem != nullptr) {
			matrix[changeElem] = 0;
			changeElem->ChangeTextBoxValue(0);
		}

		auto str = MyForm::I->labelM->Text;
		str = L"";
		int branches = (int)MyForm::I->numericUpDownBranches->Value;
		for each (auto elem in matrix->Keys) {
			if (elem->BranchNumer == 1) {
				str += L"\n";
			}
			str += matrix[elem].ToString() + L" ";
		}
		MyForm::I->labelM->Text = str;
	}
	else {
		matrix->Add(elem, val);
	}
}
