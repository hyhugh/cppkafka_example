#include <iostream>
#include <cppkafka/cppkafka.h>

using std::cout;
using std::endl;
using std::string;

using cppkafka::Configuration;
using cppkafka::MessageBuilder;
using cppkafka::Producer;

int main(int argc, char *argv[])
{
	MessageBuilder builder("test");
	Configuration config{ { "metadata.broker.list", "127.0.0.1:9092" } };
	Producer producer(config);

	cout << "Producer Running" << endl;
	int i = 0;
	string msg;

	while (1) {
		msg = "Tick: ";
		msg += std::to_string(i++);
		producer.produce(builder.partition(0).payload(msg));
		usleep(100000);
	}
	return 0;
}
