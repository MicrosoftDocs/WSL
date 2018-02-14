#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *server_full_path = "server.sock";
char *client_full_path = "client.sock";

int main(int argc, char *argv[]) {
  char Buf[100];
  ssize_t BytesRecvd;
  struct sockaddr_un clientAddr = {0};
  struct sockaddr_un serverAddr = {0};
  struct sockaddr_un address;
  char serverAddress[100] = {0};
  int serverFd, rc, clientFd;
  int acceptFd;
  socklen_t addrLen;

  if ((clientFd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
    perror("clientFd socket error");
    goto ErrorExit;
  }

  memset(&clientAddr, 0, sizeof(clientAddr));
  clientAddr.sun_family = AF_UNIX;
  strncpy(clientAddr.sun_path, client_full_path, sizeof(clientAddr.sun_path)-1);
  if (bind(clientFd, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) == -1) {
    perror("server bind error");
    goto ErrorExit;
  }

  addrLen = sizeof(clientAddr);
  memset(&clientAddr, 0, sizeof(clientAddr));
  if (getsockname(clientFd, (struct sockaddr*)&clientAddr, &addrLen) == -1) {
    perror("getsockname(client)");
    goto ErrorExit;
  }

  printf("getsockname returned: %s, addressize: %d\n", clientAddr.sun_path, addrLen);
  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sun_family = AF_UNIX;
  strncpy(serverAddr.sun_path, server_full_path, sizeof(serverAddr.sun_path));
  printf("client: connecting to %s\n", serverAddress);
  if (connect(clientFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
    perror("connect error");
    goto ErrorExit;
  }

  printf("client: connected to the server\n");
  addrLen = sizeof(clientAddr);
  memset(&clientAddr, 0, sizeof(clientAddr));
  if (getpeername(clientFd, (struct sockaddr*)&clientAddr, &addrLen) == -1) {
    perror("getpeername(client)");
    goto ErrorExit;
  }

  printf("getpeername returned: %s, addressize: %d\n", clientAddr.sun_path, addrLen);
  memset(Buf, 0, sizeof(Buf));
  if ((BytesRecvd = recv(clientFd, Buf, sizeof(Buf), 0)) == -1) {
    perror("recv");
    goto ErrorExit;
  } 

  printf("received: %zd bytes, %s\n", BytesRecvd, Buf);
 
ErrorExit:
  unlink(client_full_path);
  return 0;
}
