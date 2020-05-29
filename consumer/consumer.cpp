#include <iostream>
#include <cppkafka/cppkafka.h>

using std::cout;
using std::endl;
using std::string;

using cppkafka::Configuration;
using cppkafka::Consumer;
using cppkafka::Message;
using cppkafka::TopicPartitionList;

int main(int argc, char *argv[])
{
	cout << "Consumer Running" << endl;
	Configuration config = {
		{ "metadata.broker.list", "127.0.0.1:9092" },
		{ "group.id", 0 },
		{ "enable.auto.commit", false },
	};

	Consumer consumer(config);
	consumer.set_assignment_callback([](const auto &partitions) {
		cout << "Got assigned: " << partitions << endl;
	});

	consumer.set_revocation_callback([](const auto &partitions) {
		cout << "Got revoked: " << partitions << endl;
	});

	consumer.subscribe({ "test" });

	while (1) {
		Message msg = consumer.poll();
		if (msg) {
			if (msg.get_error()) {
				if (!msg.is_eof()) {
					cout << "[+] Received error notification: "
					     << msg.get_error() << endl;
				}
			} else {
				if (msg.get_key()) {
					cout << msg.get_key() << " -> ";
				}
				cout << msg.get_payload() << endl;
				consumer.commit(msg);
			}
		}
	}

	return 0;
}
