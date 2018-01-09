#include "tensorflow/core/public/session.h"
#include "tensorflow/core/platform/env.h"

using namespace tensorflow;

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

	Tensor a(DT_INT32, TensorShape());
	a.scalar<int>()() = 3;

	Tensor b(DT_FLOAT, TensorShape());
	b.scalar<float>()() = 123.321;

	std::vector<std::pair<string, tensorflow::Tensor>> inputs = {
		{ "input1", a },
		{ "input2", b },
	};

	std::vector<tensorflow::Tensor> outputs;

	status = session->Run(inputs, { "output" }, {}, &outputs);
	if (!status.ok()) {
		std::cout << status.ToString() << "\n";
		return 1;
	}

	auto output_c = outputs[0].scalar<float>();

	std::cout << outputs[0].DebugString() << "\n";
	std::cout << output_c() << "\n";

	session->Close();
	return 0;
}