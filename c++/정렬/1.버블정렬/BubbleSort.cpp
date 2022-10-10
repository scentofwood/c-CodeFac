#include <iostream>
#include <vector>

using namespace std;

// 버블정렬
// 인접한 2개의 레코드를 비교하여 크기를 비교하고 교환
// O(N^2)의 성능을 갖는 정렬 알고리즘
void bubbleSort(vector<int>* v) {
	for (int i = 0; i < v->size(); i++) {
		for (int j = 1; j < v->size(); j++) {
			if (v->at(j-1) > v->at(j)) {
				swap(v->at(j-1), v->at(j));
			}
		}
	}
} 

int main(void) {
	vector<int> v;
	v.push_back(6); v.push_back(5); v.push_back(3); v.push_back(9); v.push_back(8);
	v.push_back(7); v.push_back(2); v.push_back(4); v.push_back(1);

	cout << "호출전\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';

	bubbleSort(&v);
	
	cout << "호출후\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

