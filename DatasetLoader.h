//
// Created by Tudoran Eduard on 28.04.2026.
//

#ifndef MLSANDBOX_DATASETLOADER_H
#define MLSANDBOX_DATASETLOADER_H
#include "Dataset.h"
#include <fstream>

class DatasetLoader {

public:
    Dataset load(std::fstream nume_fisier);
};


#endif //MLSANDBOX_DATASETLOADER_H