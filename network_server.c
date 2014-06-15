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
  struct sockaddr_storage their_addr;
  socklen_t addr_size;
  struct addrinfo hints, *servinfo;
  int sockfd, new_fd;
  
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  int status; 
  if((status = getaddrinfo(NULL, "8080", &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    return 1;
  }
   
  sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
  if(sockfd == -1) { return error("socket"); }
  
  int option = 1;
  int result; 
  result = setsockopt(sockfd, IPPROTO_TCP, 24, &option, 4);
  if(result) { return error("setsockopt"); }  

  result = bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);
  if(result) { return error("bind"); }
  
  result = listen(sockfd, 5);
  if(result) { return error("listen"); }
 
   addr_size = sizeof(their_addr);
   new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size); 
   char buf[2000];
   
   result = recv(new_fd, (void*) buf, BUF_SIZE, 0);


   for(int i = 0; i < BUF_SIZE; i++) {
     if(buf[i] != 'a' + i % 26) {
       printf("message does not match at %d\n", i);
     }
   }
   return 0;
}


