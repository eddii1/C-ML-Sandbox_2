//
// Created by Tudoran Eduard on 28.04.2026.
//

#ifndef MLSANDBOX_MODEL_H
#define MLSANDBOX_MODEL_H
#include "Dataset.h"

class Model {
public:
  virtual ~Model() = default;

  void train(const Dataset &dataset);
  void predict(const Dataset &dataset);
  void evaluate(const Dataset &dataset);

protected:
  virtual void train_impl(const Sample &sample) = 0;
  virtual void predict_impl(const Sample &sample) = 0;
  virtual void evaluate_impl(const Sample &sample) = 0;
};

#endif // MLSANDBOX_MODEL_H
