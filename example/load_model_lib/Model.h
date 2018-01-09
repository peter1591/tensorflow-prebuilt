#pragma once

#include <string>
#include <vector>
#include <memory>

namespace tensorflow {
	class Session;
	class Tensor;
}

class Model {
public:
	Model(std::string const& model_path);

	~Model();

	float Predict(std::vector<float> const& input);

private:
	tensorflow::Session * session_;
	std::unique_ptr<std::vector<tensorflow::Tensor>> outputs_;
};