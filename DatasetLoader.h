//
// Created by Tudoran Eduard on 28.04.2026.
//

#ifndef MLSANDBOX_DATASETLOADER_H
#define MLSANDBOX_DATASETLOADER_H
#include "Dataset.h"
#include <string>

class DatasetLoader {

public:
    Dataset load(const std::string& nume_fisier);
    Sample parseCSV(const std::string& nume_fisier);
};


#endif //MLSANDBOX_DATASETLOADER_H
