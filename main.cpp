//#include "pch.h"
#include <iostream>
#include <string>
#include "code/CMatriceCore.h"
#include "code/CMatrice.h"
#include "code/CMatriceGaussJordan.h"

int main(int argc, const char *argv[]) {
    try {
        std::cout << "Main [matricesGaussJordan]" << std::endl;
        if (argc == 1) {
            throw new CException("No file specified.");
        }

        CMatrice<double> *pMATMatrice;
        for (int iArgNb = 1; iArgNb < argc; iArgNb++) {
            pMATMatrice = new CMatrice<double>(argv[iArgNb]);
            printf("matrice[%d] created:\n", iArgNb - 1);
            pMATMatrice->MACAfficher();
            printf("\n");

            printf("matrice[%d] inverse:\n", iArgNb - 1);
            pMATMatrice->MATInverse().MACAfficher();
            printf("\n");

            delete (pMATMatrice);
        }

    } catch (CException const &exception) {
        fprintf(stderr, "%s\n", exception.what());
    }
    //system("pause");
    return 0;
}