#include "tensorflow/core/public/session.h"
#include "tensorflow/core/platform/env.h"

using namespace tensorflow;

float run(tensorflow::Session * session, int input1, double input2) {
	Tensor a(DT_INT32, TensorShape());
	a.scalar<int>()() = input1;

	Tensor b(DT_FLOAT, TensorShape());
	b.scalar<float>()() = input2;

	std::vector<std::pair<string, tensorflow::Tensor>> inputs = {
		{ "input1", a },
		{ "input2", b },
	};

	std::vector<tensorflow::Tensor> outputs;

	Status status = session->Run(inputs, { "output" }, {}, &outputs);
	if (!status.ok()) {
		std::cout << status.ToString() << "\n";
		throw std::runtime_error("error");
	}

	auto output = outputs[0].scalar<float>();
	//std::cout << output[0].DebugString() << "\n";
	//std::cout << output() << "\n";
	return output();
}

int main(int argc, char* argv[]) {
	Session* session;
	Status status = NewSession(SessionOptions(), &session);
	if (!status.ok()) {
		std::cout << status.ToString() << "\n";
		return 1;
	}

	GraphDef graph_def;
	status = ReadBinaryProto(Env::Default(), "./model/graph.pb", &graph_def);
	if (!status.ok()) {
		std::cout << status.ToString() << "\n";
		return 1;
	}

	status = session->Create(graph_def);
	if (!status.ok()) {
		std::cout << status.ToString() << "\n";
		return 1;
	}

	std::cout << "result: " << run(session, 1, 123.321) << std::endl;
	std::cout << "result: " << run(session, 2, 23.321) << std::endl;
	std::cout << "result: " << run(session, 3, 3.321) << std::endl;
	
	for (int i = 0; i < 10000000; ++i) {
		run(session, 1, 123.321);
		run(session, 2, 23.21);
		run(session, 3, 3.321);

		if (i % 10000 == 0) std::cout << "calculate " << i << " times!" << std::endl;
	}

	session->Close();

	return 0;
}