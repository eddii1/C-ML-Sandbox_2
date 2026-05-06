#include <iostream>
#include <iomanip>
#include <string>

#include "DatasetLoader.h"
#include "LinearRegression.h"

int main(int argc, char** argv) {
    const std::string dataset_path =
        argc > 1 ? argv[1] : "examples/linear_regression";

    DatasetLoader loader;
    Dataset dataset = loader.load(dataset_path);

    if (!dataset.get_train().check() || !dataset.get_test().check()) {
        std::cerr << "Dataset invalid sau lipseste in: " << dataset_path << '\n';
        return 1;
    }

    LinearRegression model;

    std::cout << "Rulez demo-ul de LinearRegression pe: "
              << dataset_path << "\n\n";

    model.train(dataset);
    model.predict(dataset);

    const Sample& test_sample = dataset.get_test();
    const arma::rowvec& predictions = model.get_last_predictions();
    const auto& actual = test_sample.responses();
    const auto& features = test_sample.predictors();

    std::cout << "\nIteratie prin setul de test:\n";
    for (std::size_t i = 0; i < actual.size() && i < predictions.n_elem; ++i) {
        std::cout << "Test[" << i << "] x=[";

        for (std::size_t j = 0; j < features[i].size(); ++j) {
            if (j != 0)
                std::cout << ", ";
            std::cout << features[i][j];
        }

        std::cout << "] expected=" << actual[i]
                  << " predicted=" << std::fixed << std::setprecision(4)
                  << predictions[i] << '\n';
    }

    std::cout << '\n';
    model.evaluate(dataset);

    return 0;
}
