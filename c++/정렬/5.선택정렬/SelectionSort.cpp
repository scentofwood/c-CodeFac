#include <iostream>
#include <vector>

using namespace std;

// 선택정렬 
// 주어진 리스트 중에서 최소값(또는 최대값)을 찾고 
// 그 값을 맨 앞에 위치한 값과 교체함으로써 정렬을 완성하는 알고리즘
// O(N^2)의 성능을 갖는 정렬 알고리즘
void selectionSort(vector<int>* v) {

	int min_val, min_off;

	for (int i = 0; i < v->size(); i++) {
		// 제일 앞 원소가 자장 작다고 가정하고 하나씩 찾아감 
		min_val = v->at(i);
		min_off = i;
		
		for (int j = i+1; j < v->size(); j++) {
			// 더 작은 값을 발견 
			if (min_val > v->at(j)) {
				min_val = v->at(j);
				min_off = j;
			}
		}

		// 발견한 작은 값을 앞으로 옮김		
		if (min_off != i) {
			swap(v->at(min_off), v->at(i));
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

	selectionSort(&v);
	
	cout << "호출후\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

