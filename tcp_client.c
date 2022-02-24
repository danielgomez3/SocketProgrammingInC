#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h> //for defs of sockets that we will use, types has some  
#include <netinet/in.h> //This is for some structures that we will need to store addy declaration  

/*  NOTES: 
 *  AF_INET means address from the intern. requires a pair of (host,port). Host can be URL or its addy, port number is Integer
 *  NOTE: network byte order is big-endian
 *  htons(),htonsl() function converts an unsinged short (16bits), etct. to big-endian*/

int main(){
  /*we are going to use an integer to hold the socket descriptor.  what I mean by descriptor is what's
   * going to containt info about our socket*/
  int network_socket;
  network_socket = socket(AF_INET,SOCK_STREAM,0);

  /*This creates one of the endpoints to create a network communication. Right now we will do 
   * our client. This is just one side of the network communication. IOT connect to another socket we need to call connect() 
   * Before we do that we need to specify an addy to connect to. That's why we called on the <netinet> structure so we know the address and port of the remote socket.*/
  struct sockaddr_in server_address; //declare a structure for an addy
  server_address.sin_family = AF_INET; //set the family of our addy so we know what type of addy

  /*htons will pass our integer port in the correct network byte-order.
   * It's the best way we can insure that it will be stored in the struct correctly
   * We need to specify a port that isn't used by our operating system, let's aim high!*/
  server_address.sin_port = htons(9002); //set the family of our port
                                         
  /*Now we need to store an actual ip addy. sin_addr is also a stucture in itself, so let's access its member s_addr (string address)*/
  server_address.sin_addr.s_addr = INADDR_ANY; // this is the same as 0.0.0.0.0
  
  /*now we can connect. The second param, we need to cast our 'server_address' structure into a slightly
   * different structure. Casted into a struct as sockaddr. Needs to be a pointer bc we want to point to our
   * original value and not have it destroyed when we end the function
   *  last param needs to pass in the size of the addy
   * connect returns an '0' if success, -1 if error.  We can use that to do some error handling, save into a var*/
  int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  if (connection_status == -1){
    printf("\nError making a connection to the remote socket \n");
  }

  /* to recieve some data from the server. IOT, we call rcv()
   *  first param, the data we will get back from the server! yay!
   *  second param, we pass the size of the buffer (250)
   *  third, optional flags param*/
  char server_response[250]; //string with a max capacity, nothing init
  recv(network_socket,&server_response,sizeof(server_response),0);

  /* Since we recieved data, let's print it out!
  
  
  return 0;
}

// /*the first parameter of socket() function will be the domain of this socket, and that is already a constant in the header file. Since it's
//  * an internet socket we will pass in AF_INET
//  * Sock stream is going to be the type of the socket we are using TCP not UDP
//  * Last param specifies protocol. =0 bc already TCP,default to TCP*/
