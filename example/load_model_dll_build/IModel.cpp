#include "IModel.h"

#include "Model.h"

IModel* CreateModel() {
	return new Model();
}

void ReleaseModel(IModel* model) {
	delete model;
}