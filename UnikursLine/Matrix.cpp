#include "Matrix.h"
#include "Line.h"
#include "MyForm.h"

using namespace UnikursLine;

Matrix::Matrix() {
	this->matrix = gcnew Dictionary <Element^, int>();
	//this->adjMatrix = gcnew array<int, 2>(0,0);
}

Matrix::Matrix(unsigned nodeCount, unsigned branchCount) {
	if (this->matrix == nullptr) this->matrix = gcnew Dictionary <Element^, int>();
	this->matrix->Clear();
	//this->adjMatrix = gcnew array<int, 2>(nodeCount, nodeCount);
}

Matrix::Matrix(Panel^ panelMatrix, unsigned nodeCount, unsigned branchCount) {
	this->panelMatrix = panelMatrix;
	this->matrix = gcnew Dictionary <Element^, int>();
	//this->adjMatrix = gcnew array<int, 2>(nodeCount, nodeCount);
}

System::Void
Matrix::Clear() {
	matrix->Clear();
	//adjMatrix = gcnew array<int, 2>(0, 0);
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

unsigned 
Matrix::Deg(unsigned nodeNum) {
	unsigned deg = 0;
	for each (auto elem in matrix->Keys) {
		if (elem->NodeNumber != nodeNum) continue;
		
		//если значение не нулевое (могут быть 0, -1, 1) 
		// будем считать что граф неориентированный, с ориентированным -1 не будет счиаться за степень
		if (matrix[elem] != 0) deg++;
	}

	return deg;
}

array < array<int>^ >^
Matrix::GetAdjMatrix() {
	int nodes = Node::Nodes->Count;
	int lines = Line::Lines->Count;
	array < array<int>^ >^ adjMatrix = gcnew array < array<int>^ >(nodes);

	String^ str = L"";

	for (int i = 0; i < nodes; ++i) {
		adjMatrix[i] = gcnew array<int>(nodes);
		for (int j = 0; j < nodes; ++j) {
			adjMatrix[i][j] = 0;
		}
	}

	for each (auto line in Line::Lines) {
		if (line->From != nullptr && line->To != nullptr) {
			int n = line->From->Num - 1;
			int m = line->To->Num - 1;

			adjMatrix[n][m] = 1;
			adjMatrix[m][n] = 1;
		}
	}

	for (int i = 0; i < nodes; ++i) {
		for (int j = 0; j < nodes; ++j) {
			str += adjMatrix[i][j].ToString() + " ";
		}
		str += L"\n";
	}

	MyForm::I->label1->Text = str;

	return adjMatrix;
}