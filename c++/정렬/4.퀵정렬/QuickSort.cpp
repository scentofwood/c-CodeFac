#include <iostream>
#include <vector>

using namespace std;

// 퀵정렬 
// Pivot 기준으로 큰 원소와 작은 원소들로 분할하여 
// 분할된 각 배열을 같은 방법으로 다시 정렬해 나가는 알고리즘
// O(NlogN) 성능을 갖는 정렬 알고리즘
void quickSort(vector<int>* v, int left, int right) {
	
	cout << "입력받은 값 범위 left[" << left << "] ~ right[" << right << "]";

	// 유효성 검증 
	if (left >= right) {
		cout << " > SKIP\n";
		return;
	} else {
		cout << '\n';
	}

	// Divide process
//	int	p = (left+right)/2;
	int	p = left,
		i = left+1,
		j = right,
		pivot = v->at(p);

	while (i < j) {
		while (v->at(j) > pivot) {
			if (i < j)
				j--;
			else
				break;	
		}
		while (v->at(i) < pivot) {
			if (i < j)
				i++;
			else
				break;
		}
		if (i < j) {
			cout << " > pivot[" << p << "] = " << pivot << ' ';
			cout << "i[" << i << "] = " << v->at(i) << " vs ";
			cout << "j[" << j << "] = " << v->at(j) << '\n';
			swap(v->at(i), v->at(j));
		}
	}
	// Pivot과 Pivot보다 작은 원소들 중에서 가장 큰 원소와 교환 
	if (v->at(p) > v->at(i)) {
		swap(v->at(p), v->at(i));		
	} 
	
	// Conquer process
	cout << "quickSort left  ";
	quickSort(v, left, i-1);

	cout << "quickSort right ";
	quickSort(v, i, right);

}


int main(void) {
	vector<int> v;
	v.push_back( 6); v.push_back( 5); v.push_back( 3); v.push_back( 1); v.push_back( 8);
	v.push_back(20); v.push_back(12); v.push_back(14); v.push_back(11); v.push_back(17);
	v.push_back(16); v.push_back(15); v.push_back(13); v.push_back(19); v.push_back(18);
	v.push_back( 7); v.push_back( 2); v.push_back( 4); v.push_back( 9); v.push_back(10);

	cout << "호출전\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';

	cout << "quickSort 시작  ";
	quickSort(&v, 0, v.size()-1);
	
	cout << "호출후\n";
	for (int i = 0; i < v.size(); i++) {
		cout <<  v[i] << ' ';
	}
	cout << '\n';
	
	system("pause");
	return 0;
}

