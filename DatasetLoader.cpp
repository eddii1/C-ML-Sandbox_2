//
// Created by Tudoran Eduard on 28.04.2026.
//

#include "DatasetLoader.h"

Dataset DatasetLoader::load(std::string nume_fisier) {
    Dataset data;

    std::string filepath_1 = nume_fisier + "/train";
    data.train = parseCSV(nume_fisier + "/train");

    std::string filepath_2 = nume_fisier + "/test";
    data.test = parseCSV(filepath_2);
    return data;
}

Sample DatasetLoader::parseCSV(std::string nume_fisier) {
    Sample train;
    std::ifstream fin(nume_fisier);
    std::vector<std::vector<float>> aux;

    int x;
    int i = -1;
    while (!fin.eof()) {
        i++;
        while (fin >> x) {
            aux[i].push_back(x);
        }
    }


}
