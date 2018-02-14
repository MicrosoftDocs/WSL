#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *server_full_path = "bind.sock";

int main(int argc, char *argv[]) {
  struct sockaddr_un serverAddr;
  int serverFd, rc, clientFd;
  int acceptFd;
  socklen_t addrLen;

  if ((serverFd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("socket error");
    goto ErrorExit;
  }

  // bind the server.
  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sun_family = AF_UNIX;
  strncpy(serverAddr.sun_path, server_full_path, sizeof(serverAddr.sun_path)-1);
  printf("binding to: '%s'\n", server_full_path);
  if (bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
    perror("server bind error");
    goto ErrorExit;
  }

ErrorExit:
  unlink(server_full_path);
  return 0;
}
