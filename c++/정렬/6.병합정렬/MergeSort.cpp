#include <iostream>
#include <vector>

using namespace std;

// �������� 
// ��ü ���Ҹ� ������ �� ������ ���Ҹ� ������ �ٽ� �����ϴ� �˰���
// O(NlogN)�� ������ ���� ���� �˰���

void merge(vector<int>* v, int start, int middle, int end) {
	int left = start,
		right = middle + 1;

	// �ӽú���
	vector<int> result;

	cout << "       ** merge start[" << start << "] middle[" << middle << "] end[" << end << "]\n";;
	cout << "          v �迭 ";
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i) << ' ';
	}
	cout << '\n';

	// start ���� middle ������ �迭�� middle+1���� end ������ �迭�� ��
	// �� �迭 �� ���� ���ڸ� ã�� �ӽ� �迭�� �ְ� �� �� ��� �ϳ��� ���� ���޽� ����
	while (left <= middle && right <= end)
	{
		if (v->at(left) < v->at(right))
		{
			result.push_back(v->at(left));
			left++;
		} else {
			result.push_back(v->at(right));
			right++;
		}
	}

	// left ����� index�� ���� �������� ���
	while (left <= middle) {
		result.push_back(v->at(left));
		left++;
	}

	// right ����� index�� ���� �������� ���
	while (right <= end) {
		result.push_back(v->at(right));
		right++;
	}

	for (int i = start, r = 0; i <= end; i++, r++) {
		cout << "          copy";
		cout << " - v->at(" << i << ")=" << v->at(i);
		cout << " result.at(" << r << ")=" << result.at(r) << ")\n";		
		v->at(i) = result.at(r);
	}
}

void mergeSort(vector<int>* v, int start, int end) {
	int middle;
	
	if (end - start < 1)
		return;	
	middle = (start + end) / 2;
	cout << "mergeSort start[" << start << "] middle[" << middle << "] end[" << end << "]\n";;

	mergeSort(v, start, middle);
	mergeSort(v, middle+1, end);
	merge(v, start, middle, end);
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

	mergeSort(&v, 0, v.size()-1);
	
	cout << "ȣ����\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

