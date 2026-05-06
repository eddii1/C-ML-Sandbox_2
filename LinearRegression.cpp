//
// Created by Tudoran Eduard on 28.04.2026.
//

#include "LinearRegression.h"
#include <algorithm>
#include <armadillo>
#include <iomanip>
#include <iostream>

LinearRegression::LinearRegression()
    : trained(false), last_mse(0.0), last_r2(0.0) {}

const arma::rowvec &LinearRegression::get_last_predictions() const {
    return last_predictions;
}

double LinearRegression::get_last_mse() const {
    return last_mse;
}

double LinearRegression::get_last_r2() const {
    return last_r2;
}

arma::rowvec LinearRegression::predict_sample(const Sample &sample) const {
    arma::rowvec predictions;
    regression_model.Predict(sample.predictors_as_mat(), predictions);
    return predictions;
}

double LinearRegression::compute_r2(const arma::rowvec &actual,
                                    const arma::rowvec &predicted) {
    const double mean = arma::mean(actual);
    const double ss_res = arma::accu(arma::square(actual - predicted));
    const double ss_tot = arma::accu(arma::square(actual - mean));

    if (ss_tot == 0.0)
        return ss_res == 0.0 ? 1.0 : 0.0;

    return 1.0 - (ss_res / ss_tot);
}

void LinearRegression::train_impl(const Sample &sample) {
    if (!sample.check()) {
        std::cout << "Train sample-ul pentru LinearRegression este gol.\n";
        trained = false;
        return;
    }

    regression_model.Train(sample.predictors_as_mat(),
                           sample.responses_as_rowvec());
    trained = true;

    std::cout << "LinearRegression a fost antrenat pe "
              << sample.sample_count() << " exemple cu "
              << sample.feature_count() << " features.\n";
}

void LinearRegression::predict_impl(const Sample &sample) {
    if (!trained) {
        std::cout << "LinearRegression nu este antrenat.\n";
        return;
    }

    last_predictions = predict_sample(sample);

    std::cout << "Predictii LinearRegression (primele "
              << std::min<std::size_t>(5, last_predictions.n_elem)
              << "): ";

    for (std::size_t i = 0;
         i < std::min<std::size_t>(5, last_predictions.n_elem); ++i) {
        std::cout << std::fixed << std::setprecision(4)
                  << last_predictions[i] << ' ';
    }
    std::cout << '\n';
}

void LinearRegression::evaluate_impl(const Sample &sample) {
    if (!trained) {
        std::cout << "LinearRegression nu este antrenat.\n";
        return;
    }

    const arma::rowvec actual = sample.responses_as_rowvec();
    last_predictions = predict_sample(sample);
    last_mse = arma::mean(arma::square(last_predictions - actual));
    last_r2 = compute_r2(actual, last_predictions);

    std::cout << "Evaluare LinearRegression:\n";
    std::cout << "MSE: " << std::fixed << std::setprecision(6)
              << last_mse << '\n';
    std::cout << "R^2: " << std::fixed << std::setprecision(6)
              << last_r2 << '\n';
}
