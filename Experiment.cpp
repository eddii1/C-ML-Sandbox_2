#include "Experiment.h"

#include "AppExceptions.h"
#include "KNN.h"
#include "LinearRegression.h"

#include <iostream>
#include <utility>

Experiment::Experiment(std::string name_, Dataset dataset_, std::shared_ptr<Model> model_)
    : name(std::move(name_)), dataset(std::move(dataset_)), model(std::move(model_)) {
    if (name.empty())
        throw AppException("Experiment name must not be empty.");
    if (!model)
        throw ModelException("Experiment received a null model.");
}

Experiment::Experiment(const Experiment& other)
    : name(other.name), dataset(other.dataset), scores(other.scores) {
    if (other.model)
        model = other.model->clone();
}

Experiment& Experiment::operator=(Experiment other) {
    swap(*this, other);
    return *this;
}

void Experiment::run() {
    std::cout << "Experiment: " << name << '\n';
    model->train(dataset);
    model->predict(dataset);
    model->evaluate(dataset);

    if (const auto* lr = dynamic_cast<const LinearRegression*>(model.get()))
        scores.add(lr->get_last_r2());
    else if (const auto* knn = dynamic_cast<const KNN*>(model.get()))
        scores.add(knn->get_last_accuracy());
}

void Experiment::print_model_details() const {
    if (const auto* lr = dynamic_cast<const LinearRegression*>(model.get())) {
        std::cout << "Model concret: LinearRegression, ultimul R^2 = "
                  << lr->get_last_r2() << '\n';
    } else if (const auto* knn = dynamic_cast<const KNN*>(model.get())) {
        std::cout << "Model concret: KNN, ultimul accuracy = "
                  << knn->get_last_accuracy() << '\n';
    } else {
        std::cout << "Model concret necunoscut.\n";
    }
}

const History<double>& Experiment::score_history() const {
    return scores;
}

void swap(Experiment& first, Experiment& second) noexcept {
    using std::swap;
    swap(first.name, second.name);
    swap(first.dataset, second.dataset);
    swap(first.model, second.model);
    swap(first.scores, second.scores);
}
