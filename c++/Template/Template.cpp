#include <iostream>
#include <string>

using namespace std;

template <typename T> void change(T& a, T& b) {
	cout << "다양한 데이터타입 데이터를 교체합니다.\n";
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void change<int>(int& a, int& b) {
	cout << "정수형 데이터를 교체합니다.\n";
	int temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T> class GeneralData {
private:
	T data;
public:
	GeneralData(T data) : data(data) {	}
	void setData(T data) {
		this->data = data;
	}
	T getData() {
		cout << "일반템플릿 클래스\n";
		return data;
	}
};

// 디폴트템플릿
template <typename T = int> class DefaultData {
private:
	T data;
public:
	DefaultData(T data) : data(data) {	}
	void setData(T data) {
		this->data = data;
	}
	T getData() {
		cout << "디폴트템플릿 클래스\n";
		return data;
	}
};

int main(void) {
	string a = "나동빈";
	string b = "홍길동";
	change(a, b);
	cout << a << ":" << b << endl;
	cout << "---------------------------------------\n";
	
	int i = 7;
	int j = 9;
	change(i, j);
	cout << i << ":" << j << endl;
	cout << "---------------------------------------\n";
	
	long l = 100;
	long m = 200;
	change(l, m);
	cout << l << ":" << m << endl;
	cout << "---------------------------------------\n";
	
	GeneralData<int> data1(1);
	GeneralData<string> data2("나동빈");
	cout << data1.getData() << ":" << data2.getData() << endl;
	cout << "---------------------------------------\n";
	
	DefaultData<> data3(1);
	GeneralData<string> data4("홍길동");
	cout << data3.getData() << ":" << data4.getData() << endl;
	
	
	system("pause");
	return 0;
}

