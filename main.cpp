//#include "pch.h"
#include <iostream>
#include <string>
#include "code/CMatriceCore.h"
#include "code/CMatrice.h"
#include "code/CMatriceGaussJordan.h"

int main(int argc, const char* argv[]) {
    try {
        std::cout << "Main [matricesGaussJordan]" << std::endl;
        /*if (argc == 1) {
            throw new CException("No file specified.");
        }*/

        CMatrice<double> *pMATMatrice;
        CMatrice<double> *pMATMatriceInv;
        //for (int iArgNb = 1; iArgNb < argc; iArgNb++) {
            std::ofstream outputFile("test.txt");
            outputFile << "TypeMatrice=double\n"
                          "NBLignes=3\n"
                          "NBColonnes=3\n"
                          "Matrice=[\n"
                          "5 3 6\n"
                          "3 42 8\n"
                          "2 6 65\n"
                          "]";
            outputFile.close();
            pMATMatrice = new CMatrice<double>("test.txt");
        printf("matrice[%d] created:\n", 0);
            pMATMatrice->MACAfficher();
            printf("\n");

        printf("matrice[%d] inverse:\n", 0);
        pMATMatrice->MATInverse().MACAfficher();

            delete (pMATMatrice);
        // }

    } catch (CException const &exception) {
        fprintf(stderr, "%s\n", exception.what());
    }
    //system("pause");
    return 0;
}