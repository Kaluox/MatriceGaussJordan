//#include "pch.h"
#include <iostream>
#include <string>
#include "code/CMatriceCore.h"
#include "code/CMatrice.h"
#include "code/CMatriceGaussJordan.h"

int main(int argc, const char* argv[]) {
    std::cout<<"BLOP"<<std::endl;
    CMatriceGaussJordan<int> *tmp2 = new CMatriceGaussJordan<int>(2);
    std::cout<<"BLIP"<<std::endl;
    /*try {
        std::cout << "Main [matrices]" << std::endl;
        if (argc == 1) {
            throw new CException("No file specified.");
        }

        CMatrice<double> **ppMATtab = (CMatrice<double> **) malloc(sizeof(CMatrice<double> *));
        for (int iArgNb = 1; iArgNb < argc; iArgNb++) {
            ppMATtab = (CMatrice<double> **) realloc(ppMATtab, iArgNb * sizeof(CMatrice<double> *));
            ppMATtab[iArgNb - 1] = new CMatrice<double>(argv[iArgNb]);
            std::cout << "matrice[" << iArgNb - 1 << "] created" << std::endl;
            std::cout << *ppMATtab[iArgNb - 1] << std::endl;
        }

        CMatrice<double> *tmpCopy = new CMatrice<double>(*ppMATtab[0]);
        std::cout << "matrice == matrice: " << ((*tmpCopy == *ppMATtab[0]) ? "true" : "false") << std::endl;

        int c;
        std::cout << "c(int) = ? : ";
        std::cin >> c;

        for (int iArgNb = 1; iArgNb < argc; iArgNb++) {
            std::cout << "matrice[" << iArgNb - 1 << "] * " << c << " :" << std::endl;
            std::cout << *ppMATtab[iArgNb - 1] * c << std::endl;
        }

        for (int iArgNb = 1; iArgNb < argc; iArgNb++) {
            std::cout << "matrice[" << iArgNb - 1 << "] / " << c << " :" << std::endl;
            std::cout << *ppMATtab[iArgNb - 1] / c << std::endl;
        }


        std::cout << "SUM(matrices[0, " << argc - 2 << "]) : " << std::endl;
        CMatrice<double> *tmpMATSum = new CMatrice<double>(*ppMATtab[0]);
        for (int iArgNb = 2; iArgNb < argc; iArgNb++) {
            *tmpMATSum += *ppMATtab[iArgNb - 1];
        }
        std::cout << *tmpMATSum << std::endl;
        delete (tmpMATSum);

        std::cout << "SUM(matrices[0, " << argc - 2 << "])_2 : " << std::endl;
        CMatrice<double> *tmpMATSum2 = new CMatrice<double>(*ppMATtab[0]);
        for (int iArgNb = 2; iArgNb < argc; iArgNb++) {
            *tmpMATSum2 = (*tmpMATSum2 + *ppMATtab[iArgNb - 1]);
        }
        std::cout << *tmpMATSum2 << std::endl;
        delete (tmpMATSum2);

        std::cout << "SUM(matrices[0, " << argc - 2 << "] * (-1)^n) : " << std::endl;
        CMatrice<double> *tmpMATSumPowMinOne = new CMatrice<double>(*ppMATtab[0]);
        for (int iArgNb = 2; iArgNb < argc; iArgNb++) {
            *tmpMATSumPowMinOne += (*ppMATtab[iArgNb - 1] * pow((-1), (iArgNb - 1)));
        }
        std::cout << *tmpMATSumPowMinOne << std::endl;
        delete (tmpMATSumPowMinOne);

        std::cout << "SUM(matrices[0, " << argc - 2 << "] * (-1)^n)_2 : " << std::endl;
        CMatrice<double> *tmpMATSumPowMinOne2 = new CMatrice<double>(*ppMATtab[0]);
        for (int iArgNb = 2; iArgNb < argc; iArgNb++) {
            *tmpMATSumPowMinOne2 = (*tmpMATSumPowMinOne2 + *ppMATtab[iArgNb - 1] * pow((-1), (iArgNb - 1)));
        }
        std::cout << *tmpMATSumPowMinOne2 << std::endl;
        delete (tmpMATSumPowMinOne2);

        std::cout << "PI(matrices[0, " << argc - 2 << "]) : " << std::endl;
        CMatrice<double> *tmpMATMultiply = new CMatrice<double>(*ppMATtab[0]);
        for (int iArgNb = 2; iArgNb < argc; iArgNb++) {
            *tmpMATMultiply *= (*ppMATtab[iArgNb - 1]).oTranspose();
        }
        std::cout << *tmpMATMultiply << std::endl;
        delete (tmpMATMultiply);

        std::cout << "PI(matrices[0, " << argc - 2 << "])_2 : " << std::endl;
        CMatrice<double> *tmpMATMultiply2 = new CMatrice<double>(*ppMATtab[0]);
        for (int iArgNb = 2; iArgNb < argc; iArgNb++) {
            *tmpMATMultiply2 = ((*tmpMATMultiply2) * (*ppMATtab[iArgNb - 1]).oTranspose());
        }
        std::cout << *tmpMATMultiply2 << std::endl;
        delete (tmpMATMultiply2);

        std::cout << "cleaning memory" << std::endl;
        for (int iArgNb = 1; iArgNb < argc; iArgNb++) {
            delete (ppMATtab[iArgNb - 1]);
        }
        std::cout << "done" << std::endl;
    } catch (CException const &exception) {
        std::cerr << exception.what() << "\n";
    }
    system("pause");
    return 0;
    std::cout<<"Main Matrice"<<std::endl;
    std::cout<<"Creating MatriceCarree"<<std::endl;
    CMatriceGaussJordan<int> *tmp2 = new CMatriceGaussJordan<int>("1 1:1 1", " ", ":");
    } catch (CException const &exception) {
        std::cerr << exception.what() << "\n";
    }
    system("pause");
    return 0;
*/
}