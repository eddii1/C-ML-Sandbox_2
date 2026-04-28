//
// Created by Tudoran Eduard on 26.04.2026.
//

#include "Sample.h"
#include <iostream>
#include <cstdlib>
#include <vector>



bool Sample::check() {
    return v.size() != 0 && m.size() != 0;
}

void Sample::vector_set(const std::vector<float>& aux) {
    for (auto it : aux)
        v.push_back(it);
}

void Sample::matrix_set(const std::vector<std::vector<float>>& aux) {
    m.resize(aux.size());
    for (int i = 0; i < aux.size(); i++)
        for (auto it : aux[i])
            m[i].push_back(it);
}

void Sample::randomly_init() {
    int size, rows;

    std::cout << "DATI SIZE\n";
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
