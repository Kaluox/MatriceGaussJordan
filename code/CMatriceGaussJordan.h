#ifndef MATRICES_CMATRICEGAUSSJORDAN_H
#define MATRICES_CMATRICEGAUSSJORDAN_H

#include "CMatrice.h"
#include "CMatriceExtractor.h"

template<class T>
class CMatriceGaussJordan {
private :
    CMatrice<T> *pMGJMATMatrice;

    CMatrice<T> &MGJGenerateId(unsigned int uiNbLignes, unsigned int uiNbColonnes);

    void MGJEchangeLignes(unsigned int uiIndexOne, unsigned int uiIndexTwo);

    void MGJSetLigne(CMatrice<T> &MATLigne, unsigned int uiLigneNb);

public :
    CMatriceGaussJordan(CMatrice<T> &oMATParam);
    ~CMatriceGaussJordan();
    CMatrice<T> &MGJget();
};


#include "CMatriceGaussJordan.cpp"

#endif //MATRICES_CMATRICEGAUSSJORDAN_H
