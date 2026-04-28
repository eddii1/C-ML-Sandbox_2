//
// Created by Tudoran Eduard on 28.04.2026.
//

#include "Dataset.h"

Sample& Dataset::get_train() {
    return train;
}

const Sample& Dataset::get_train() const {
    return train;
}

Sample& Dataset::get_test() {
    return test;
}

const Sample& Dataset::get_test() const {
    return test;
}
