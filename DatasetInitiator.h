//
// Created by Tudoran Eduard on 26.04.2026.
//
#include "Sample.h"
#include <fstream>
#ifndef MLSANDBOX_DATASETINITIATOR_H
#define MLSANDBOX_DATASETINITIATOR_H


class DatasetInitiator {
    Sample train, test;

public:
    void parse(std::fstream nume_fisier);
};


#endif //MLSANDBOX_DATASETINITIATOR_H