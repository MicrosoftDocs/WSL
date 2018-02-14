#undef UNICODE

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <afunix.h>
#include <stdlib.h>
#include <stdio.h>

#define SERVER_SOCKET "server.sock"

int __cdecl main(void)
{

    SOCKET ClientSocket = INVALID_SOCKET;
    SOCKET ListenSocket = INVALID_SOCKET;
    int Result;
    char SendBuffer[] = "af_unix from Windows to WSL!";
    int SendResult;
    SOCKADDR_UN ServerSocket;
    WSADATA WsaData;

    // Initialize Winsock
    Result = WSAStartup(MAKEWORD(2,2), &WsaData);
    if (Result != 0) {
        printf("WSAStartup failed with error: %d\n", Result);
        goto Exit;
    }

    // Create a AF_UNIX stream server socket.
    ListenSocket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        goto Exit;
    }

    memset(&ServerSocket, 0, sizeof(ServerSocket));
    ServerSocket.sun_family = AF_UNIX;
    strncpy(ServerSocket.sun_path, SERVER_SOCKET, strlen(SERVER_SOCKET));

    // Bind the socket to the path.
    Result = bind(ListenSocket, (struct sockaddr *)&ServerSocket, sizeof(ServerSocket));
    if (Result == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        goto Exit;
    }

    // Listen to start accepting connections.
    Result = listen(ListenSocket, SOMAXCONN);
    if (Result == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        goto Exit;
    }

    printf("Accepting connections on: '%s'\n", SERVER_SOCKET);
    // Accept a connection.
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        goto Exit;
    }

    printf("Accepted a connection.\n" );
    printf("Relayed %d bytes: '%s'\n", strlen(SendBuffer), SendBuffer);
    // Send some data.
    SendResult = send(ClientSocket, SendBuffer, (int)strlen(SendBuffer), 0 );
    if (SendResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        goto Exit;
    }

    // shutdown the connection.
    printf("Shutting down\n");
    Result = shutdown(ClientSocket, 0);
    if (Result == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        goto Exit;
    }

Exit:

    // cleanup
    if (ListenSocket != INVALID_SOCKET) {
        closesocket(ListenSocket);
    }

    if (ClientSocket != INVALID_SOCKET) {
        closesocket(ClientSocket);
    }

    // Analogous to `unlink`
    DeleteFileA(SERVER_SOCKET);
    WSACleanup();
    return 0;
}
