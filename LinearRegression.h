//
// Created by Tudoran Eduard on 28.04.2026.
//

#ifndef MLSANDBOX_LINEARREGRESSION_H
#define MLSANDBOX_LINEARREGRESSION_H
#include "Model.h"
#include <mlpack.hpp>

class LinearRegression : public Model {

private:
  mlpack::LinearRegression<> regression_model;
  bool trained;
  arma::rowvec last_predictions;
  double last_mse;
  double last_r2;

  arma::rowvec predict_sample(const Sample &sample) const;
  static double compute_r2(const arma::rowvec &actual,
                           const arma::rowvec &predicted);

public:
  LinearRegression();
  ~LinearRegression() = default;

  const arma::rowvec &get_last_predictions() const;
  double get_last_mse() const;
  double get_last_r2() const;

  void train_impl(const Sample &sample) override;
  void predict_impl(const Sample &sample) override;
  void evaluate_impl(const Sample &sample) override;
};

#endif // MLSANDBOX_LINEARREGRESSION_H
