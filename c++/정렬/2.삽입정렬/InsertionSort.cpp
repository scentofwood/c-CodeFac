#include <iostream>
#include <vector>

using namespace std;

// 삽입정렬
// 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 
// 자신의 위치를 찾아 삽입함으로써 정렬로 완성하는 알고리즘
// O(N^2)의 성능을 갖는 정렬 알고리즘
void insertionSort(vector<int>* v) {
	int temp;
	for (int i = 0; i < v->size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v->at(j) > v->at(i)) {
				temp = v->at(i);
				for (int k = i; k > j; k--) {
					v->at(k) = v->at(k-1);
				}
				v->at(j) = temp;
				break;
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

	insertionSort(&v);
	
	cout << "호출후\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

