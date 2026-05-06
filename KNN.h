//
// Created by Tudoran Eduard on 28.04.2026.
//

#ifndef MLSANDBOX_KNN_H
#define MLSANDBOX_KNN_H
#include "Model.h"
#include <armadillo>

class KNN : public Model {
private:
  std::size_t k;
  arma::mat train_features;
  arma::Row<size_t> train_labels;
  bool trained;
  arma::Row<size_t> last_predictions;
  double last_accuracy;

  arma::Row<size_t> predict_labels(const Sample &sample) const;

public:
  explicit KNN(std::size_t k = 3);
  ~KNN() = default;

  void set_k(std::size_t value);
  std::size_t get_k() const;
  const arma::Row<size_t> &get_last_predictions() const;
  double get_last_accuracy() const;

protected:
  void train_impl(const Sample &sample) override;
  void predict_impl(const Sample &sample) override;
  void evaluate_impl(const Sample &sample) override;
};

#endif // MLSANDBOX_KNN_H
