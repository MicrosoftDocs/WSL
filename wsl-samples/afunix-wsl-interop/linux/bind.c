#include "header.h"

int main(int argc, char* argv[]) {
	struct sockaddr_un serverAddr = { 0 };
	int serverFd = 0;

	if ((serverFd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket error");
		goto ErrorExit;
	}

	// bind the server.
	serverAddr.sun_family = AF_UNIX;
	strncpy(serverAddr.sun_path, BIND_SOCKET, sizeof(serverAddr.sun_path) - 1);
	printf("binding to: '%s'\n", BIND_SOCKET);
	if (bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
		perror("server bind error");
		goto ErrorExit;
	}

ErrorExit:
	unlink(BIND_SOCKET);
	return 0;
}
