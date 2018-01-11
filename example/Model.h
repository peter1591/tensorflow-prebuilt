#pragma once

#include <string>
#include <vector>
#include <memory>

#ifdef LOAD_MODEL_DLL
#ifdef LOAD_MODEL_EXPORTING
#define LOAD_MODEL_EXPORTS __declspec( dllexport )
#else
#define LOAD_MODEL_EXPORTS __declspec( dllimport )
#endif

#else
#define LOAD_MODEL_EXPORTS

#endif

namespace tensorflow {
	class Session;
	class Tensor;
}

class LOAD_MODEL_EXPORTS Model {
public:
	Model(std::string const& model_path);

	~Model();

	float Predict(std::vector<float> const& input);

private:
	tensorflow::Session * session_;
	std::unique_ptr<std::vector<tensorflow::Tensor>> outputs_;
};