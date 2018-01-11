#pragma once

#include <string>
#include <vector>
#include <memory>

#include "IModel.h"

namespace tensorflow {
	class Session;
	class Tensor;
}

class Model : public IModel {
public:
	Model();

	~Model();

	void Initialize(std::string const& model_path);

	float Predict(std::vector<float> const& input);

private:
	tensorflow::Session * session_;
	std::unique_ptr<std::vector<tensorflow::Tensor>> outputs_;
};