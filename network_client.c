#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define BUF_SIZE 2000

int error(char* error) {
  printf("%s error %s\n", error, strerror(errno));
  return 1;
}

int main( int argc, char **argv) {
  struct addrinfo hints, *res;
  int sockfd;
  
  if(argc != 2) {
    printf("Please include the ip address of the receiving server\n");
    return 1;
  }

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  int status; 
  if((status = getaddrinfo(argv[1], "8080", &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    return 1;
  }
   
  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if(sockfd == -1) { return error("socket"); }

  int result; 
  result = bind(sockfd, res->ai_addr, res->ai_addrlen);
  if(result) { return error("bind"); }
  
  result = connect(sockfd, res->ai_addr, res->ai_addrlen);
   char buf[2000];
   
   for(int i = 0; i < BUF_SIZE; i++) {
     buf[i] = 'a' + i % 26; 
   }
   result = send(sockfd, (void*) buf, BUF_SIZE, 0);

   if(result) { return error("recv"); }

   for(int i = 0; i < BUF_SIZE; i++) {
     if(buf[i] != 'a' + i % 26) {
       printf("message does not match at %d\n", i);
     }
   }
   return 0;
}


