#include <random>
#include <iostream>

#include "Model.h"

int main(int argc, char* argv[])
{
	Model model("./model/freezed.pb");

	std::mt19937 random;
	random.seed(std::random_device()());
	std::uniform_real_distribution<float> distribution(0.0f, 10.0f);

	static constexpr int kBatchSize = 10000;
	std::vector<std::vector<float>> inputs;
	inputs.resize(kBatchSize);
	for (auto & input : inputs) {
		input.resize(140);
	}

	while (true) {
		for (auto & input : inputs) {
			for (auto & field : input) {
				field = distribution(random);
			}
		}
		std::cout << "result: " << model.Predict(inputs[0]) << std::endl;
		std::cout << "result: " << model.Predict(inputs[1]) << std::endl;
		std::cout << "result: " << model.Predict(inputs[2]) << std::endl;

		for (auto const& input : inputs) {
			model.Predict(input);
		}

		std::cout << "calculate " << kBatchSize << " times!" << std::endl;
	}


	return 0;
}