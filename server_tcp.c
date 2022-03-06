#include <stdlib.h>
#include <stdio.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#include <netinet/in.h>

int main(){

  char server_message[256] = "You have reached the server!\n";

  //create the server socket. REVIEW tcp_client.c
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  //define the server address.
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // bind the socket to our specified IP and port
  bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

  /* start listening for connections. The second parameter is a 'backlog', which means: how many connections
    * waiting for this particular socket at one point at time. Not important. It has to be at least set to '1'
    *It will be important when writing net applications with a lot of traffic */
  listen(server_socket, 5);

  int client_socket;
  /* First parm: socket we are accepting connections on
    2nd and 3rd param if used will hold data of who came in, but we're not going to use that! Fills it w/
   where did this info come from. */
  client_socket = accept(server_socket, NULL,NULL);

  /* 1st, who are we sending it to? 2nd, what are we sending? 3rd, duh. Last, optional flag*/
  send(client_socket, server_message, sizeof(server_message), 0);

  /* close socket*/
  close(server_socket);

  return  0;
    }
