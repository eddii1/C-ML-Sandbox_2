//
// Created by Tudoran Eduard on 28.04.2026.
//

#include "KNN.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <mlpack.hpp>

KNN::KNN(std::size_t k) : k(k), trained(false), last_accuracy(0.0) {}

void KNN::set_k(std::size_t value) {
    k = std::max<std::size_t>(1, value);
}

std::size_t KNN::get_k() const {
    return k;
}

const arma::Row<size_t> &KNN::get_last_predictions() const {
    return last_predictions;
}

double KNN::get_last_accuracy() const {
    return last_accuracy;
}

arma::Row<size_t> KNN::predict_labels(const Sample &sample) const {
    if (!trained)
        return {};

    const arma::mat query = sample.predictors_as_mat();
    if (query.n_cols == 0)
        return {};

    const std::size_t effective_k = std::min<std::size_t>(k, train_features.n_cols);
    mlpack::KNN knn_model(train_features);

    arma::Mat<size_t> neighbors;
    arma::mat distances;
    knn_model.Search(query, effective_k, neighbors, distances);

    arma::Row<size_t> predictions(query.n_cols);

    for (arma::uword col = 0; col < query.n_cols; ++col) {
        std::map<size_t, size_t> votes;

        for (arma::uword row = 0; row < neighbors.n_rows; ++row) {
            const size_t label = train_labels[neighbors(row, col)];
            ++votes[label];
        }

        size_t best_label = 0;
        size_t best_count = 0;
        for (const auto &[label, count] : votes) {
            if (count > best_count) {
                best_label = label;
                best_count = count;
            }
        }

        predictions[col] = best_label;
    }

    return predictions;
}

void KNN::train_impl(const Sample &sample) {
    if (!sample.check()) {
        std::cout << "Train sample-ul pentru KNN este gol.\n";
        trained = false;
        return;
    }

    train_features = sample.predictors_as_mat();
    train_labels = sample.responses_as_labels();
    trained = true;

    std::cout << "KNN a fost antrenat pe " << sample.sample_count()
              << " exemple cu k=" << std::max<std::size_t>(1, k) << ".\n";
}

void KNN::predict_impl(const Sample &sample) {
    if (!trained) {
        std::cout << "KNN nu este antrenat.\n";
        return;
    }

    last_predictions = predict_labels(sample);

    std::cout << "Predictii KNN (primele "
              << std::min<std::size_t>(5, last_predictions.n_elem)
              << "): ";

    for (std::size_t i = 0;
         i < std::min<std::size_t>(5, last_predictions.n_elem); ++i) {
        std::cout << last_predictions[i] << ' ';
    }
    std::cout << '\n';
}

void KNN::evaluate_impl(const Sample &sample) {
    if (!trained) {
        std::cout << "KNN nu este antrenat.\n";
        return;
    }

    const arma::Row<size_t> actual = sample.responses_as_labels();
    last_predictions = predict_labels(sample);

    if (actual.n_elem == 0 || last_predictions.n_elem != actual.n_elem) {
        std::cout << "Setul de test pentru KNN este invalid.\n";
        return;
    }

    const arma::uword correct = arma::accu(last_predictions == actual);
    last_accuracy = static_cast<double>(correct) /
                    static_cast<double>(actual.n_elem);

    std::cout << "Evaluare KNN:\n";
    std::cout << "Accuracy: " << std::fixed << std::setprecision(6)
              << last_accuracy << '\n';
}
