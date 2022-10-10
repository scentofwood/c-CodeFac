#include <iostream>
#include <vector>

using namespace std;

// ��������
// �ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �迭 �κа� ���Ͽ�, 
// �ڽ��� ��ġ�� ã�� ���������ν� ���ķ� �ϼ��ϴ� �˰���
// O(N^2)�� ������ ���� ���� �˰���
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

	cout << "ȣ����\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';

	insertionSort(&v);
	
	cout << "ȣ����\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

