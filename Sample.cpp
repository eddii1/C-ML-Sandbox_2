//
// Created by Tudoran Eduard on 26.04.2026.
//

#include "Sample.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>



bool Sample::check() const {
    return !v.empty() && !m.empty() && v.size() == m.size();
}

std::size_t Sample::sample_count() const {
    return v.size();
}

std::size_t Sample::feature_count() const {
    return m.empty() ? 0 : m.front().size();
}

void Sample::vector_set(const std::vector<float>& aux) {
    v = aux;
}

void Sample::matrix_set(const std::vector<std::vector<float>>& aux) {
    m = aux;
}

void Sample::randomly_init() {
    int size, rows;

    clear();

    std::cout << "DATI SIZE (SAU NUMAR COLOANE):\n";
    std::cin >> size;

    std::cout << "DATI NUMAR RANDURI:\n";
    std::cin >> rows;

    for (int i = 0; i < size; i ++)
        v.push_back(rand() % 100 + 69);

    m.resize(size);
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < rows; j ++)
            m[i].push_back(rand() % 50 + 67);
}

void Sample::clear()  {
    v.clear();
    m.clear();
}

const std::vector<float>& Sample::responses() const {
    return v;
}

const std::vector<std::vector<float>>& Sample::predictors() const {
    return m;
}

arma::rowvec Sample::responses_as_rowvec() const {
    arma::rowvec result(v.size());

    for (std::size_t i = 0; i < v.size(); ++i)
        result[i] = v[i];

    return result;
}

arma::Row<size_t> Sample::responses_as_labels() const {
    arma::Row<size_t> result(v.size());

    for (std::size_t i = 0; i < v.size(); ++i)
        result[i] = static_cast<size_t>(std::llround(v[i]));

    return result;
}

arma::mat Sample::predictors_as_mat() const {
    if (!check())
        return {};

    const std::size_t rows = feature_count();
    arma::mat result(rows, sample_count());

    for (std::size_t sample_idx = 0; sample_idx < sample_count(); ++sample_idx) {
        if (m[sample_idx].size() != rows) {
            throw std::runtime_error("Inconsistent feature count inside Sample.");
        }

        for (std::size_t feature_idx = 0; feature_idx < rows; ++feature_idx)
            result(feature_idx, sample_idx) = m[sample_idx][feature_idx];
    }

    return result;
}

std::ostream& operator<<(std::ostream &os, const Sample &aux) {
    int v_size = aux.v.size();
    int m_size = aux.m.size();

    os << "VECTOR OUTPUT: \n";
    for (int i = 0; i < v_size; i++)
        os << aux.v[i] << " ";
    os << '\n';

    os << "MATRIX OUTPUT: \n";
    for (int i = 0; i< m_size; i++) {
        int mm_size = aux.m[i].size();
        for (int j = 0; j < mm_size; j++)
            os << aux.m[i][j] << " ";
        os << '\n';
    }
    os << '\n';



    return os;
}
