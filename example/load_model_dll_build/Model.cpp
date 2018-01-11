#include "Model.h"

#include "tensorflow/core/public/session.h"
#include "tensorflow/core/platform/env.h"

using namespace tensorflow;

Model::Model() : session_(nullptr) {}

void Model::Initialize(std::string const& model_path) {
	Status status = NewSession(SessionOptions(), &session_);
	if (!status.ok()) {
		throw std::runtime_error(status.ToString());
	}

	GraphDef graph_def;
	status = ReadBinaryProto(Env::Default(), model_path, &graph_def);
	if (!status.ok()) {
		throw std::runtime_error(status.ToString());
	}

	status = session_->Create(graph_def);
	if (!status.ok()) {
		throw std::runtime_error(status.ToString());
	}

	outputs_.reset(new std::vector<Tensor>());
}

Model::~Model() {
	session_->Close();
}

float Model::Predict(std::vector<float> const& input)
{
	Tensor input_tensor(Tensor(DT_FLOAT, TensorShape({ 1, (int)input.size() })));
	for (int i = 0; i < (int)input.size(); ++i) {
		input_tensor.matrix<float>()(0, i) = input[i];
	}

	std::vector<std::pair<string, tensorflow::Tensor>> inputs = {
		{ "Placeholder", input_tensor },
	};

	Status status = session_->Run(inputs, { "final/BiasAdd" }, {}, outputs_.get());
	if (!status.ok()) {
		throw std::runtime_error(status.ToString());
	}

	auto output = (*outputs_)[0].scalar<float>();
	return output();
}
