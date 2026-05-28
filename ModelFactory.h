#ifndef MLSANDBOX_MODELFACTORY_H
#define MLSANDBOX_MODELFACTORY_H

#include "Model.h"
#include <cstddef>
#include <memory>

class ModelFactory {
public:
    static std::shared_ptr<Model> linear_regression();
    static std::shared_ptr<Model> knn(std::size_t k = 3);
};

#endif // MLSANDBOX_MODELFACTORY_H
