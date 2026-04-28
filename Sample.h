//
// Created by Tudoran Eduard on 26.04.2026.
//
#include <vector>
#ifndef MLSANDBOX_SAMPLE_H
#define MLSANDBOX_SAMPLE_H


class Sample {
    std::vector<float> v;
    std::vector<std::vector<float>> m;

public:
    bool check();
    void vector_set(std::vector<float> aux);
    void matrix_set(std::vector<std::vector<float>> aux);
    void randomly_init();
    void clear() ;

    friend std::ostream& operator<<(std::ostream &os, const Sample &aux);
};


#endif //MLSANDBOX_SAMPLE_H