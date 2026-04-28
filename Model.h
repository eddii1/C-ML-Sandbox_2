//
// Created by Tudoran Eduard on 28.04.2026.
//

#ifndef MLSANDBOX_MODEL_H
#define MLSANDBOX_MODEL_H
#include "Dataset.h"


class Model {

private:
    void train(Dataset& dataset);
    Dataset predict(Dataset& dataset);
};


#endif //MLSANDBOX_MODEL_H