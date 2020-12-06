#include <iostream>
#include <string>

using namespace std;

template <typename T> void change(T& a, T& b) {
	cout << "�پ��� ������Ÿ�� �����͸� ��ü�մϴ�.\n";
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void change<int>(int& a, int& b) {
	cout << "������ �����͸� ��ü�մϴ�.\n";
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
		cout << "�Ϲ����ø� Ŭ����\n";
		return data;
	}
};

// ����Ʈ���ø�
template <typename T = int> class DefaultData {
private:
	T data;
public:
	DefaultData(T data) : data(data) {	}
	void setData(T data) {
		this->data = data;
	}
	T getData() {
		cout << "����Ʈ���ø� Ŭ����\n";
		return data;
	}
};

int main(void) {
	string a = "������";
	string b = "ȫ�浿";
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
	GeneralData<string> data2("������");
	cout << data1.getData() << ":" << data2.getData() << endl;
	cout << "---------------------------------------\n";
	
	DefaultData<> data3(1);
	GeneralData<string> data4("ȫ�浿");
	cout << data3.getData() << ":" << data4.getData() << endl;
	
	
	system("pause");
	return 0;
}

