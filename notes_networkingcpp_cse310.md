##### What is network programming?  

All network computers have an ip addr (duh)  
31 bits to make up an ip addr. (ipv4)  
Computers need a network card to communicate aka **interfaces**  

* Interfaces  
Wireless card  
could also be Ethernet adapter or VPN  
 
> When we make a connection with another machine, we have to specify a port  
A machine can specify about 65k ports  
The reason why? Because it allows for multiple internet connections at the same time!  
> Important: The first 1024 are reserved for the OS  

* Common Ports  
21 FTP (File Transfer Protocol)  
22 SSH (Secure Shell)  
23 Telnet  
25 SMTP (Simple Mail Transfer Protocol)  
80 HTTP (Hypertext..)  Most famous!  
110 POP3 (Post office..)   

Not used as much: Port 13 is Time Protocol, 17 is the quote of the day!  

##### Asio cpp library  
Asio comes from the BOOST development framework  
 
##### Sockets  

Q: Sockets v Ports?  
Port is a logical construct assigned to network processes. 
A Socket is a combination of port and IP address  

An incoming packet has a port number which is used to identify the process that needs to consume the packet  

Q: What are Sockets?  
As mentioned, used to identify both a machine and a service within the machine  
Sockets are the low level connection endpoint. They are a way you can connect to any 2 computers  
There are a lot of protocols that sit on top of Sockets 

* Protocols  
They sit on top of Socket functions  
(e.g TCP, low-level networking protocol, HTTP is a high-level networking protocol used by the web)  
  * TCP  
  TCP stands for Transmission Control Protocol  
  Standard that allows applications to exchange messages over a network  
  send data and packages over intern.  
  Guarantees the integrity of messages by doing this:
  1. Establishes a connection between a source and a destination, and it ensures that it remains live until communication begins.  
  1. Then it breaks large amounts of data into smaller packets, making sure integrity in the process.  

FTP is used for files  

* DNS  
Q: If everything is IP addresses, how can I make www.google.com into an IP addy?  
A: That's the responsibility of the DNS  
Domain Name Service  
Translates human-readable into IP Add.  
A DNS server elimate the need for humans to memorize IPs.  
We send the server a *string*, and it would return us an IP.   

You can use `NS lookup` in the commmand line to do this yourself!  
aka **Name server lookup**

BIND (aka named) is the most widely used DNS server  

* Client/Server  
Servers wait a lot because it has a lot of crap on it  
Process:  
1. Client establishes a connection to server  
1. Client sends request for info  
1. Server finds the info they want 
1. Server sends it back!  
1. Depending on the protocol, client/server disconnect  

* [ ] One Shot
client and server are going to shut down the connection once client recieves the info  
Here's an example with a **One-shot** server  
  > Client: I need a picture!
  > Server: Gee, I'm lonely.. (The server always just waits around)  


* Broadcast Server  
Multiple clients (a,b&c)  
architecturally, we give 1 thread per client bc we need to do as much as we can asynchronously  
MMORPG's use Broadcast servers!:  
  > Client A: "Here are my coords in the map"  
  > Server recieves those coords  
  > Server: "Hey B and C, Player A is at theese coords: <375.0, -41.0> "   
##### Client Socket Workflow  

Q: What even is a Socket?  
A socket is one endpoint of a two-way communication link between 2 programs running on the network.  
The Socket mechanism provides a means of **IPC (inter-process communication)** by establishing named comntact points between which the communication takes place.  
A socket is like a pipe, connects things.  
A Socket is created at each end of communication (if there are 2 people trying to communicate, there are 2 sockets)  
A Socket compose of an:  
  IP Address  
  Port number  

A client creates a socket and then attempts to connect to the server's Socket.  

##### Q: How do we do that in our Code?  

1. socket()  
1. connect()  
1. recv()  

Q: Why are we using htons and passing in a port number integer greater than 16 bits?  
A: ?  

##### Socket BINDING  
each socket needs unique address   
an address is a combo of an ip address and port number   
when socket normally created it assumes IP of network that created it.  
If socket has an IP addy but no port #, it is **unbound**  
When it has both, the socket is **bound** to a port or an addy  
If you want to bind to 

If you don't care what address or port you have, you can use the ip 0.0.0.0  

##### What does the server need to do now?  

On server end of socket:  
1. we need to create a socket()  
1. bind() that socket to an ip an port IOT:  
1. listen() for connections  
1. accept() connection  
1. send() or recv() data

For the client side, we connect()'ed with the connect() function, but this time we need to use bind().  
