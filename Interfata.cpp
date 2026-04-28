//
// Created by Tudoran Eduard on 26.04.2026.
//

#include "Interfata.h"
#include <iostream>

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
                if (!s.check())
                    std::cout << "SAMPLE NEINITIALIZAT/GOL\n";
                else
                    std::cout << s;
                break;
            }
            case 2: {
                std::cout << "TO BE IMPLEMENTED\n";
                break;
            }
            case 3: {
                if (s.check()) {
                    std::string yn;
                    std::cout << "SAMPLE DEJA INITIALIZATI. RESET SAMPLE SI RAND?(y/n)";
                    std::cin >> yn;
                    if (yn == "y" || yn == "Y") {
                        s.clear();
                        s.randomly_init();
                    }

                }else
                    s.randomly_init();
                break;
            }
            case 4: {
                s.clear();
                break;
            }
            case 5: {
                break;
            }
        }
    }
}
