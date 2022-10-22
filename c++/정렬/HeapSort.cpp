#include <iostream>
#include <vector>

using namespace std;

// ������ 
// �ִ� �� Ʈ���� �ּ� �� Ʈ���� ������ ������ �ϴ� ���
// �������� ������ ���ؼ��� �ִ� ���� �����ϰ� �������� ������ ���ؼ��� �ּ� ���� �����Ͽ� ����
// O(NlogN)�� ������ ���� ���� �˰���

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
	
	// ��ü Ʈ�������� MaxHeap ������ �ٲٱ� 
	// �̷��� �ϸ� Ȯ���� ����� root ���� ���� ũ�ٴ� �� �� �� ���� 
	maxHeap(v, size);

	// root�� ��� �������� �ݺ������� Heap ���� 
	// ������ root���� �ǵڷ� ������ ������ �ٿ� �ٽ� MaxHeap ����
	// �ᱹ ū ���� ��� �ڷ� �Ѿ�Ƿ� �������� ������ �� 
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

	cout << "ȣ����\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';

	heapSort(&v);
	
	cout << "ȣ����\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

