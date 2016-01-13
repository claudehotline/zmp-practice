#include "zhelpers.hpp"

int main(int argc, char *argv[])
{
  zmq::context_t context(1);

  zmq::socket_t responder(context, ZMQ_REP);
  responder.connect("tcp://localhost:5560");

  while(1)
  {
    std::string string = s_recv(responder);

    std::cout << "Received request: " << string << std::endl;

    sleep(1);

    s_send(responder, "World");

  }
}
