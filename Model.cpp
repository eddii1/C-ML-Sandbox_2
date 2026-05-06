//
// Created by Tudoran Eduard on 28.04.2026.
//

#include "Model.h"

void Model::train(const Dataset &dataset) {
    train_impl(dataset.get_train());
}

void Model::predict(const Dataset &dataset) {
    predict_impl(dataset.get_test());
}

void Model::evaluate(const Dataset &dataset) {
    evaluate_impl(dataset.get_test());
}
