#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//char *server_path = "/var/run/server";
char *client_path = "./client";
char *server_full_path = "server.sock";
//char *client_path = "\0hidden";

int main(int argc, char *argv[]) {
  ssize_t BytesSent;
  struct sockaddr_un serverAddr;
  struct sockaddr_un clientAddr;
  struct sockaddr_un address;
  char buf[100] = "this is a test";
  int serverFd, rc, clientFd;
  int acceptFd;
  socklen_t addrLen;

  if (argc > 1) client_path=argv[1];

  if ((serverFd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("socket error");
    goto ErrorExit;
  }

  // bind the server.
  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sun_family = AF_UNIX;
  strncpy(serverAddr.sun_path, server_full_path, sizeof(serverAddr.sun_path)-1);
  if (bind(serverFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
    perror("server bind error");
    goto ErrorExit;
  }

  // listen
  if (listen(serverFd, 5) == -1) {
    perror("listen error");
    goto ErrorExit;
  }

  memset(&address, 0, sizeof(address));
  addrLen = sizeof(address);
  if (getsockname(serverFd, (struct sockaddr *)&address, &addrLen) == -1) {
    perror("getsockname error");
    goto ErrorExit;
  }

  printf("getsockname on listening socket: %s\n", address.sun_path);
  printf("server listening on: %s\n", server_full_path); 
  fflush(stdout);

  // accept connection
  addrLen = sizeof(address);
  memset(&address, 0, sizeof(address));
  if ((acceptFd = accept(serverFd, (struct sockaddr*)&address, &addrLen)) == -1) {
    perror("accept error");
    goto ErrorExit;
  }

  printf("accept returned address: %s, address size: %d\n", address.sun_path, addrLen);
  if ((BytesSent = send(acceptFd, buf, strlen(buf), 0)) == -1) {
    perror("send");
    goto ErrorExit;
  } 

  printf("sent data successfully, bytes sent: %zd, data: %s\n", BytesSent, buf);

ErrorExit:
  unlink(server_full_path);
  //unlink(client_path);
  return 0;
}
