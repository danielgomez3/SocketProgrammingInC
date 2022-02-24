#include <iostream>
/* Asio is a vast library w/ lots of modules, doesn't only just handle networking,
 * It does a bunch of I/O for programs. For now we'll just focus on networking over internet. We also have to include a define statement to exclude stuff from the
 * BOOST framwork:*/
#define ASIO_STANDALONE
#include <asio.hpp>
/* this handles the movement of memory for us:*/  
#include <asio/ts/buffer.hpp>  
/*all of the things we need to do internet-wise:*/
#include <asio.hpp>  

int main(){ 
  return 0;
}
