#include "zhelpers.h"

int main(void)
{
	void *context = zmq_ctx_new();
	void *receiver = zmq_socket(context, ZMQ_PULL);
	zmq_connect(receiver, "tcp://localhost:5557");

	void *sender = zmq_socket(context, ZMQ_PUSH);
	zmq_connect(sender, "tcp://localhost:5558");

	while(1)
	{
		char *string = s_recv(receiver);
		printf("%s.", string);
		fflush(stdout);
		s_sleep(atoi(string));
		free(string);
		s_send(sender, "");
	}
	zmq_close(receiver);
	zmq_close(sender);
	zmq_ctx_destroy(context);
	return 0;
}