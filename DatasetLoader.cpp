//
// Created by Tudoran Eduard on 28.04.2026.
//

#include "DatasetLoader.h"
#include "AppExceptions.h"
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
        throw DatasetException("Nu pot deschide fisierul " + nume_fisier);

    std::vector<float> values;
    std::vector<std::vector<float>> matrix;
    std::string line;

    int line_number = 0;
    while (std::getline(fin, line)) {
        ++line_number;
        for (char& ch : line)
            if (ch == ',')
                ch = ' ';

        std::istringstream iss(line);
        float value;
        if (!(iss >> value))
            throw DatasetException("Linie invalida in " + nume_fisier + ": " + std::to_string(line_number));

        values.push_back(value);

        std::vector<float> row;
        while (iss >> value) {
            row.push_back(value);
        }

        matrix.push_back(row);
    }

    if (values.empty())
        throw DatasetException("Fisierul nu contine sample-uri: " + nume_fisier);

    sample.vector_set(values);
    sample.matrix_set(matrix);
    return sample;
}
