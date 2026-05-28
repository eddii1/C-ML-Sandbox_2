#include "ModelFactory.h"

#include "KNN.h"
#include "LinearRegression.h"

std::shared_ptr<Model> ModelFactory::linear_regression() {
    return std::make_shared<LinearRegression>();
}

std::shared_ptr<Model> ModelFactory::knn(std::size_t k) {
    return std::make_shared<KNN>(k);
}
