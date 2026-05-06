//
// Created by Tudoran Eduard on 28.04.2026.
//

#ifndef MLSANDBOX_DATASET_H
#define MLSANDBOX_DATASET_H
#include "Sample.h"

class Dataset {
  friend class DatasetLoader;

private:
  Sample train, test;

public:
  Sample &get_train();
  const Sample &get_train() const;
  Sample &get_test();
  const Sample &get_test() const;
};

#endif // MLSANDBOX_DATASET_H
