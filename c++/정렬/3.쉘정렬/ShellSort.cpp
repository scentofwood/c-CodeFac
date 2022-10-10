#include <iostream>
#include <vector>

using namespace std;

// 쉘정렬 
// 특정 레코드와 거리가 일정한 레코드끼리 부파일로 나누어 각 부파일을 삽입정렬하는 알고리즘 
// 최악O(N^2), 평균O(N*1.5) 성능을 갖는 정렬 알고리즘

void insertionSort(vector<int>* v, int first, int last, int gap) {
	int temp;
	for (int i = first; i <= last; i = i+gap) {
		cout << "i[" << i << "] = " << v->at(i) << " vs ";
		for (int j = first; j < i; j = j+gap) {
			cout << "j[" << j << "] = " << v->at(j) << " / ";
			if (v->at(j) > v->at(i)) {
				temp = v->at(i);
				for (int k = i; k > j; k = k-gap) {
					v->at(k) = v->at(k-gap);
				}
				v->at(j) = temp;
				cout << "바꿈";
				break;
			}
		}
		cout << '\n';
	}
} 

void shellSort(vector<int>* v) {

	for (int gap = v->size()/2; gap > 0; gap = gap/2) {
		if ((gap%2) == 0) {
			// gap을 홀수로 만든다.
			gap++;
		}
	
		// 부분 리스트의 개수는 gap과 같다.
		for (int i = 0; i < gap; i++) {
			// 부분 리스트에 대한 삽입 정렬 수행
			cout << "i = " << i << " gap = " << gap << " -----------------------------\n"; 
			insertionSort(v, i, v->size()-1, gap);
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

	shellSort(&v);
	
	cout << "호출후\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

