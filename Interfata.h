//
// Created by Tudoran Eduard on 26.04.2026.
//
#include "Dataset.h"
#include "DatasetLoader.h"
#ifndef MLSANDBOX_INTERFATA_H
#define MLSANDBOX_INTERFATA_H

class Interfata {
  Dataset data;
  DatasetLoader loader;

  Sample &select_sample();

public:
  void start();
};

#endif // MLSANDBOX_INTERFATA_H
