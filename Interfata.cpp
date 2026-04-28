//
// Created by Tudoran Eduard on 26.04.2026.
//

#include "Interfata.h"
#include <iostream>

Sample& Interfata::select_sample() {
    while (true) {
        int decision;

        std::cout << "ALEGETI SAMPLE-UL:\n";
        std::cout << "1. TRAIN\n";
        std::cout << "2. TEST\n";
        std::cin >> decision;

        if (decision == 1)
            return data.get_train();
        if (decision == 2)
            return data.get_test();

        std::cout << "OPTIUNE INVALIDA\n";
    }
}

void Interfata::start() {
    while (true) {
        int decision;

        std::cout << "ALEGETI OPERATIA:\n";
        std::cout << "1. AFISATI SAMPLE\n";
        std::cout << "2. INITIALIZATI SAMPLE (PRIN FOLDER):\n";
        std::cout << "3. INITIALIZATI SAMPLE RANDOMLY\n";
        std::cout << "4. RESET SAMPLE\n";
        std::cout << "5. STOP APLICATIE\n";

        std::cin >> decision;

        switch (decision) {
            case 1: {
                Sample& current_sample = select_sample();

                if (!current_sample.check())
                    std::cout << "SAMPLE NEINITIALIZAT/GOL\n";
                else
                    std::cout << current_sample;
                break;
            }
            case 2: {
                std::string folder_name;
                std::cout << "DATI NUMELE FOLDERULUI:\n";
                std::cin >> folder_name;
                data = loader.load(folder_name);
                break;
            }
            case 3: {
                Sample& current_sample = select_sample();

                if (current_sample.check()) {
                    std::string yn;
                    std::cout << "SAMPLE DEJA INITIALIZAT. RESET SAMPLE SI RAND?(y/n)";
                    std::cin >> yn;
                    if (yn == "y" || yn == "Y") {
                        current_sample.clear();
                        current_sample.randomly_init();
                    }

                } else
                    current_sample.randomly_init();
                break;
            }
            case 4: {
                Sample& current_sample = select_sample();
                current_sample.clear();
                break;
            }
            case 5: {
                return;
            }
            default: {
                std::cout << "OPTIUNE INVALIDA\n";
                break;
            }
        }
    }
}
