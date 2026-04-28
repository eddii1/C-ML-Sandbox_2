//
// Created by Tudoran Eduard on 28.04.2026.
//

#include "DatasetLoader.h"
#include <fstream>
#include <sstream>

Dataset DatasetLoader::load(const std::string& nume_fisier) {
    Dataset data;

    data.train = parseCSV(nume_fisier + "/train");
    data.test = parseCSV(nume_fisier + "/test");
    return data;
}

Sample DatasetLoader::parseCSV(const std::string& nume_fisier) {
    Sample sample;
    std::ifstream fin(nume_fisier);
    if (!fin.is_open())
        return sample;

    std::vector<float> values;
    std::vector<std::vector<float>> matrix;
    std::string line;

    while (std::getline(fin, line)) {
        for (char& ch : line)
            if (ch == ',')
                ch = ' ';

        std::istringstream iss(line);
        float value;
        if (!(iss >> value))
            continue;

        values.push_back(value);

        std::vector<float> row;
        while (iss >> value) {
            row.push_back(value);
        }

        matrix.push_back(row);
    }

    sample.vector_set(values);
    sample.matrix_set(matrix);
    return sample;
}
