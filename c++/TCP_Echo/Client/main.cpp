#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <string>
#include <winsock2.h>

/***********************************************************************
 * g++ �ҽ�����.cpp -o ��������.exe -lws2_32
***********************************************************************/

using namespace std;

void ShowErrorMessage(string message) {
    cout << "[���� �߻�]: " << message << endl;
    system("pause");
    exit(1);
}

int main(void) {
    WSADATA wsaData;
    SOCKET clientSocket;
    SOCKADDR_IN serverAddress;

    int serverPort = 9876;
    char received[256];
    string sent;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)  // Winsock�� �ʱ�ȭ �մϴ�.
        ShowErrorMessage("WSAStartup()");

    clientSocket = socket(PF_INET, SOCK_STREAM, 0); // TCP ������ �����մϴ�.

    if (clientSocket == INVALID_SOCKET)
        ShowErrorMessage("socket()");

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;                     // ipv4
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // ���ڿ� ip��  ��Ʈ��ũ ����Ʈ ��������
    serverAddress.sin_port = htons(serverPort);             // 2����Ʈ ������ ��Ƽ��ũ ����Ʈ ��������
    if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
        ShowErrorMessage("connect()");
    cout << "[���� ����]: connect()" << endl;

    while (1) { // �ݺ������� ������ �޽����� �����ϰ� ���� �޽����� ���� �޽��ϴ�.
        cout << "[�޽��� ����]: ";
        getline(cin, sent);
        if (sent == "") continue;
        send(clientSocket, sent.c_str(), sent.length(), 0);
        int length = recv(clientSocket, received, sizeof(received), 0);
        received[length] = '\0';
        if (strcmp(received, "[exit]") == 0) {
            cout << "[���� ����]" << endl;
            break;
        }
        cout << "[���� �޽���]: " << received << endl;
    }

    closesocket(clientSocket);
    WSACleanup();

    system("pause");
    return 0;
}