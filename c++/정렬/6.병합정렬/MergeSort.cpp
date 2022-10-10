#include <iostream>
#include <vector>

using namespace std;

// 병합정렬 
// 전체 원소를 분할한 후 분할한 원소를 정렬후 다시 병합하는 알고리즘
// O(NlogN)의 성능을 갖는 정렬 알고리즘

void merge(vector<int>* v, int start, int middle, int end) {
	int left = start,
		right = middle + 1;

	// 임시벡터
	vector<int> result;

	cout << "       ** merge start[" << start << "] middle[" << middle << "] end[" << end << "]\n";;
	cout << "          v 배열 ";
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i) << ' ';
	}
	cout << '\n';

	// start 부터 middle 까지의 배열과 middle+1부터 end 까지의 배열을 비교
	// 두 배열 중 작은 숫자를 찾아 임시 배열에 넣고 둘 중 어느 하나의 끝에 도달시 종료
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

	// left 블록의 index가 아직 남아있을 경우
	while (left <= middle) {
		result.push_back(v->at(left));
		left++;
	}

	// right 블록의 index가 아직 남아있을 경우
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

	cout << "호출전\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';

	mergeSort(&v, 0, v.size()-1);
	
	cout << "호출후\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

