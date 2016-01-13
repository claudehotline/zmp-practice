#include  "zhelpers.hpp"

int main()
{
  zmq::context_t context(1);

  zmq::socket_t requester(context, ZMQ_REQ);
  requester.connect("tcp://localhost:5559");

  for (int request = 0; request < 10; request++)
  {
    s_send(requester, "Hello");
    std::string string = s_recv(requester);

    std::cout << "Received reply " << request
            << " [" << string << "]" << std::endl;
  }
}
