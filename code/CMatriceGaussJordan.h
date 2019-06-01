#ifndef MATRICES_CMATRICEGAUSSJORDAN_H
#define MATRICES_CMATRICEGAUSSJORDAN_H

#include "CMatrice.h"

template<class T> class CMatriceGaussJordan: public CMatrice<T>{
private :
    CMatrice<T> *pMGJMATMatrice;

    CMatrice<T> &MGJGenerateId(unsigned int uiNbLignes, unsigned int uiNbColonnes);

    void MGJEchangeLignes(unsigned int uiIndexOne, unsigned int uiIndexTwo);

public :
    explicit CMatriceGaussJordan(CMatrice<T> &oMATParam);

    ~CMatriceGaussJordan();

    CMatrice<T> &MGJget();
};


#include "CMatriceGaussJordan.cpp"

#endif //MATRICES_CMATRICEGAUSSJORDAN_H
