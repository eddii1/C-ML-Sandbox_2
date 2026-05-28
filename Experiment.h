#ifndef MLSANDBOX_EXPERIMENT_H
#define MLSANDBOX_EXPERIMENT_H

#include "Dataset.h"
#include "History.h"
#include "Model.h"

#include <memory>
#include <string>

class Experiment {
    std::string name;
    Dataset dataset;
    std::shared_ptr<Model> model;
    History<double> scores;

public:
    Experiment(std::string name, Dataset dataset, std::shared_ptr<Model> model);
    Experiment(const Experiment& other);
    Experiment& operator=(Experiment other);

    void run();
    void print_model_details() const;

    const History<double>& score_history() const;

    friend void swap(Experiment& first, Experiment& second) noexcept;
};

#endif // MLSANDBOX_EXPERIMENT_H
