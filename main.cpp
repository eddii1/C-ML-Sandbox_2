#include "AppExceptions.h"
#include "DatasetLoader.h"
#include "Experiment.h"
#include "ModelFactory.h"

#include <exception>
#include <iostream>

int main() {
    try {
        DatasetLoader loader;
        Dataset dataset = loader.load("examples/linear_regression");

        Experiment linear_experiment(
            "Demo minimal LinearRegression",
            dataset,
            ModelFactory::linear_regression());

        linear_experiment.run();
        linear_experiment.print_model_details();

        Experiment copied_experiment = linear_experiment;
        std::cout << "Copie experiment, scoruri salvate: "
                  << copied_experiment.score_history().size() << '\n';

        Experiment knn_experiment(
            "Demo minimal KNN",
            dataset,
            ModelFactory::knn(3));
        knn_experiment.run();
        knn_experiment.print_model_details();
    } catch (const AppException& err) {
        std::cerr << "Eroare aplicatie: " << err.what() << '\n';
        return 1;
    } catch (const std::exception& err) {
        std::cerr << "Eroare neasteptata: " << err.what() << '\n';
        return 2;
    }

    return 0;
}
