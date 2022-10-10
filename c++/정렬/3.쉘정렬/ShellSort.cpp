#include <iostream>
#include <vector>

using namespace std;

// ������ 
// Ư�� ���ڵ�� �Ÿ��� ������ ���ڵ峢�� �����Ϸ� ������ �� �������� ���������ϴ� �˰��� 
// �־�O(N^2), ���O(N*1.5) ������ ���� ���� �˰���

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
				cout << "�ٲ�";
				break;
			}
		}
		cout << '\n';
	}
} 

void shellSort(vector<int>* v) {

	for (int gap = v->size()/2; gap > 0; gap = gap/2) {
		if ((gap%2) == 0) {
			// gap�� Ȧ���� �����.
			gap++;
		}
	
		// �κ� ����Ʈ�� ������ gap�� ����.
		for (int i = 0; i < gap; i++) {
			// �κ� ����Ʈ�� ���� ���� ���� ����
			cout << "i = " << i << " gap = " << gap << " -----------------------------\n"; 
			insertionSort(v, i, v->size()-1, gap);
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

	shellSort(&v);
	
	cout << "ȣ����\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

