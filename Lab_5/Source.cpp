#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <cstdlib>
using namespace std;
//code13
struct VectorNodeSparse {
	int positioni;
	int positionj;
	int value;
	VectorNodeSparse(int positioni,int positionj, int value) {
		this->positioni = positioni;
		this->positionj = positionj;
		this->value = value;
	}
};
//code13
vector <VectorNodeSparse> calculateVector3(vector<VectorNodeSparse> vector1, vector<VectorNodeSparse> vector2, vector<VectorNodeSparse> vector3) {
	
	
	for (int i = 0; i < vector1.size(); i++) {
		int flag = 0;
		for (int j = 0; j < vector2.size(); j++) {
			if ((vector1.at(i).positioni == vector2.at(j).positioni) && (vector1.at(i).positionj == vector2.at(j).positionj)) {
				vector3.push_back(VectorNodeSparse(vector1.at(i).positioni, vector1.at(i).positionj, vector1.at(i).value + vector2.at(j).value));
				flag = 1;
				vector2.erase(vector2.begin());
			}
			
			
		}
		if (flag == 0) vector3.push_back(VectorNodeSparse(vector1.at(i).positioni, vector1.at(i).positionj, vector1.at(i).value + 3));
	} 
	for (int i = 0; i < vector2.size(); i++) {
		vector3.push_back(VectorNodeSparse(vector2.at(i).positioni, vector2.at(i).positionj,  vector2.at(i).value+3));
		

	}
	return vector3;
}
  
    
vector <VectorNodeSparse> calculateVector4(vector<VectorNodeSparse> vector1, vector<VectorNodeSparse> vector2, vector<VectorNodeSparse> vector4) {
	int element1, element2, suma = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int h = 0; h < 5; h++) {
				element1 = 3;
				element2 = 3;
				for (int p = 0; p < vector1.size(); p++) {
					if ((vector1.at(p).positioni == i + 1) && (vector1.at(p).positionj == h + 1)) {
						element1 = vector1.at(p).value;
					}
				}
				for (int k = 0; k < vector2.size(); k++) {
					if ((vector2.at(k).positioni == h + 1) && (vector2.at(k).positionj == j + 1)) {
						element2 = vector2.at(k).value;
					}
				}
				suma = suma + (element1 * element2);
			}
			vector4.push_back(VectorNodeSparse(i + 1, j + 1, suma));
			suma = 0;
		}
	}
	return vector4;
}

	


void output_vector3(vector<VectorNodeSparse> vector3) {
	int a[5][5]{};
	int b, c;
		for (int j = 0; j < vector3.size(); j++) {
			b = vector3.at(j).positioni;
			c = vector3.at(j).positionj;
			a[b-1][c-1] = vector3.at(j).value;
				
			
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (a[i][j] == 0) {
					a[i][j] = 6;
				}

			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {

				cout << a[i][j] << " ";
			}
			cout << endl;
		}
}

/* 1 3 3 3 3
   3 3 3 3 3
   3 3 3 6 3
   3 2 3 3 3
   3 3 3 3 2*/

/* 4 3 3 3 3
   3 3 3 3 3 
   3 3 3 5 3
   3 3 3 3 3
   3 1 3 3 3*/
int main() {

	vector<VectorNodeSparse> vector1;
	vector<VectorNodeSparse> vector2;
	vector<VectorNodeSparse> vector3;
	vector<VectorNodeSparse> vector4;
	vector1.push_back(VectorNodeSparse(1, 1, 1));
	vector1.push_back(VectorNodeSparse(4, 2, 2));
	vector1.push_back(VectorNodeSparse(5, 5, 2));
	vector1.push_back(VectorNodeSparse(3, 4, 6));

	vector2.push_back(VectorNodeSparse(1, 1, 4));
	vector2.push_back(VectorNodeSparse(3, 4, 5));
	vector2.push_back(VectorNodeSparse(5, 2, 1));

	vector3 = calculateVector3(vector1, vector2, vector3);
	cout << "Result  of the addition: " << endl;
	output_vector3(vector3);
	cout << endl;
	vector4 = calculateVector4(vector1, vector2, vector4);
	cout << "Result  of the multiplication: " << endl;
	for (int j = 0; j < vector4.size()-4 ; j=j+5) {

		cout << vector4.at(j).value <<" "<< vector4.at(j+1).value <<" "<< vector4.at(j+2).value <<" "<< vector4.at(j+3).value <<" "<< vector4.at(j+4).value << endl;
	}

}