#include <iostream>
#include <set>

using namespace std;

int main(void) {
	int array[5] = {2,4,6,8,10};
	set<int> s(array, array + 5);
	set<int>::iterator iter = s.begin();;
	for (; iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << '\n';
	s.insert(1);
	s.insert(3);
	s.insert(5);
	iter = s.begin();
	for (; iter != s.end(); iter++) {
		cout << *iter << ' ';
	}
	cout << '\n';
	
	system("pause");
}
