#include <iostream>
#include <vector>

using namespace std;

// 힙정렬 
// 최대 힙 트리나 최소 힙 트리를 구성해 정렬을 하는 방법
// 내림차순 정렬을 위해서는 최대 힙을 구성하고 오름차순 정렬을 위해서는 최소 힙을 구성하여 정렬
// O(NlogN)의 성능을 갖는 정렬 알고리즘

void maxHeap(vector<int>* v, int size) {
	if (size <= 1) return;
	
	for (int i = 1; i < size; i++) {
		int child = i;
		do {
			int root = (child - 1) / 2;
			if (v->at(root) < v->at(child)) {
				int temp = v->at(root);
				v->at(root) = v->at(child);
				v->at(child) = temp;
			}
			child = root;
		} while (child != 0);
	}
}

void heapSort(vector<int>* v) {

	int size = v->size();
	if (size <= 1) return;
	
	// 전체 트리구조를 MaxHeap 구조로 바꾸기 
	// 이렇게 하면 확실한 결과는 root 값이 가장 크다는 것 알 수 있음 
	maxHeap(v, size);

	// root를 계속 빼내가며 반복적으로 Heap 구성 
	// 구현시 root값을 맨뒤로 보내고 범위를 줄여 다시 MaxHeap 구성
	// 결국 큰 값이 계속 뒤로 넘어가므로 내림차순 정렬이 됨 
	for (int i = size - 1; i >= 0; i--) {
		int temp = v->at(0);
		v->at(0) = v->at(i);
		v->at(i) = temp;

		maxHeap(v, i);
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

	heapSort(&v);
	
	cout << "호출후\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

