#pragma once

#include <vector>

class IModel {
public:
	IModel() {}
	virtual ~IModel() {}

	virtual void Initialize(std::string const& model_path) = 0;
	virtual float Predict(std::vector<float> const& input) = 0;
};

#ifdef LOAD_MODEL_DLL
#ifdef LOAD_MODEL_EXPORTING
#define LOAD_MODEL_EXPORTS __declspec( dllexport )
#else
#define LOAD_MODEL_EXPORTS __declspec( dllimport )
#endif

extern "C" LOAD_MODEL_EXPORTS IModel* CreateModel();
extern "C" LOAD_MODEL_EXPORTS void ReleaseModel(IModel* model);

#endif