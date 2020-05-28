#include "header.h"

int main(int argc, char* argv[]) {
	ssize_t BytesSent = 0;
	struct sockaddr_un serverAddr = { 0 };
	struct sockaddr_un tmpAddr = { 0 };
	char buf[100] = "this is a test";
	int serverFd = 0, acceptFd = 0;
	socklen_t addrLen = 0;

	if ((serverFd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket error");
		goto ErrorExit;
	}

	// bind the server.
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sun_family = AF_UNIX;
	strncpy(serverAddr.sun_path, SERVER_SOCKET, sizeof(serverAddr.sun_path) - 1);
	if (bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
		perror("server bind error");
		goto ErrorExit;
	}

	// listen
	if (listen(serverFd, 5) == -1) {
		perror("listen error");
		goto ErrorExit;
	}

	addrLen = sizeof(tmpAddr);
	memset(&tmpAddr, 0, sizeof(tmpAddr));
	if (getsockname(serverFd, (struct sockaddr*)&tmpAddr, &addrLen) == -1) {
		perror("getsockname error");
		goto ErrorExit;
	}

	printf("getsockname on listening socket: %s\n", tmpAddr.sun_path);
	printf("server listening on: %s\n", SERVER_SOCKET);
	fflush(stdout);

	// accept connection
	addrLen = sizeof(tmpAddr);
	memset(&tmpAddr, 0, sizeof(tmpAddr));
	if ((acceptFd = accept(serverFd, (struct sockaddr*)&tmpAddr, &addrLen)) == -1) {
		perror("accept error");
		goto ErrorExit;
	}

	printf("accept returned address: %s, address size: %d\n", tmpAddr.sun_path, addrLen);
	if ((BytesSent = send(acceptFd, buf, strlen(buf), 0)) == -1) {
		perror("send");
		goto ErrorExit;
	}

	printf("sent data successfully, bytes sent: %zd, data: %s\n", BytesSent, buf);

ErrorExit:
	unlink(SERVER_SOCKET);
	return 0;
}
