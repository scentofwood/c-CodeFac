#include <iostream>
#include <string>
#include <winsock2.h>

/***********************************************************************
 * g++ 소스파일.cpp -o 실행파일.exe -lws2_32
***********************************************************************/

using namespace std;

void ShowErrorMessage(string message) {
    cout << "[오류 발생]: " << message << endl;
    system("pause");
    exit(1);
}

int main(void) {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    SOCKADDR_IN serverAddress, clientAddress;

    int serverPort = 9876;
    char received[256];

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)  // Winsock을 초기화 합니다.
        ShowErrorMessage("WSAStartup()");

    serverSocket = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓을 생성합니다.

    if (serverSocket == INVALID_SOCKET)
        ShowErrorMessage("socket()");

    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;                 // ipv4
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);  // 4바이트 정수를 네트워크 바이트 형식으로
    serverAddress.sin_port = htons(serverPort);         // 2바이트 정수를 네티워크 바이트 형식으로
    if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
        ShowErrorMessage("bind()");
    cout << "[현재 상태]: bind()" << endl;

    if (listen(serverSocket, 5) == SOCKET_ERROR)        // 동시에 5개까지 연결 허용
        ShowErrorMessage("listen()");
    cout << "[현재 상태]: listen()" << endl;

    int sizeClientAddress = sizeof(clientAddress);
    clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddress, &sizeClientAddress);
    cout << "[현재 상태]: accept()" << endl;

    if (clientSocket == INVALID_SOCKET)
        ShowErrorMessage("accept()");

    while (1) { // 클라이언트의 메시지를 받아서 그대로 다시 전달합니다.
        int length = recv(clientSocket, received, sizeof(received), 0);
        received[length] = NULL;
        cout << "[클라이언트 메시지]: " << received << endl;
        cout << "메시지 전송]: " << received << endl;
        if (strcmp(received, "[exit]") == 0) {
            send(clientSocket, received, sizeof(received) - 1, 0);
            cout << "[서버 종료]" << endl;
            break;
        }
        send(clientSocket, received, sizeof(received) - 1, 0);
    }

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    system("pause");
    return 0;
}