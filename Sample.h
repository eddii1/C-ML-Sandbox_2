//
// Created by Tudoran Eduard on 26.04.2026.
//
#include <armadillo>
#include <cstddef>
#include <iosfwd>
#include <vector>
#ifndef MLSANDBOX_SAMPLE_H
#define MLSANDBOX_SAMPLE_H


class Sample {
    std::vector<float> v;
    std::vector<std::vector<float>> m;

public:
    bool check() const;
    std::size_t sample_count() const;
    std::size_t feature_count() const;
    void vector_set(const std::vector<float>& aux);
    void matrix_set(const std::vector<std::vector<float>>& aux);
    void randomly_init();
    void clear();
    const std::vector<float>& responses() const;
    const std::vector<std::vector<float>>& predictors() const;
    arma::rowvec responses_as_rowvec() const;
    arma::Row<size_t> responses_as_labels() const;
    arma::mat predictors_as_mat() const;

    friend std::ostream& operator<<(std::ostream &os, const Sample &aux);
};


#endif //MLSANDBOX_SAMPLE_H
