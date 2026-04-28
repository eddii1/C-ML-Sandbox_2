//
// Created by Tudoran Eduard on 28.04.2026.
//

#ifndef MLSANDBOX_DATASETLOADER_H
#define MLSANDBOX_DATASETLOADER_H
#include "Dataset.h"
#include <fstream>

class DatasetLoader {

public:
    Dataset load(std::string nume_fisier);
    Sample parseCSV(std::string nume_fisier);
};


#endif //MLSANDBOX_DATASETLOADER_H