#include <iostream>
#include <vector>

using namespace std;

// �������� 
// �־��� ����Ʈ �߿��� �ּҰ�(�Ǵ� �ִ밪)�� ã�� 
// �� ���� �� �տ� ��ġ�� ���� ��ü�����ν� ������ �ϼ��ϴ� �˰���
// O(N^2)�� ������ ���� ���� �˰���
void selectionSort(vector<int>* v) {

	int min_val, min_off;

	for (int i = 0; i < v->size(); i++) {
		// ���� �� ���Ұ� ���� �۴ٰ� �����ϰ� �ϳ��� ã�ư� 
		min_val = v->at(i);
		min_off = i;
		
		for (int j = i+1; j < v->size(); j++) {
			// �� ���� ���� �߰� 
			if (min_val > v->at(j)) {
				min_val = v->at(j);
				min_off = j;
			}
		}

		// �߰��� ���� ���� ������ �ű�		
		if (min_off != i) {
			swap(v->at(min_off), v->at(i));
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

	selectionSort(&v);
	
	cout << "ȣ����\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

