//
// Created by alexi on 24/05/2019.
//

#ifndef MATRICES_CMATRICEGAUSSJORDAN_H
#define MATRICES_CMATRICEGAUSSJORDAN_H

#include "CMatrice.h"

template<class T> class CMatriceGaussJordan: public CMatrice<T>{

private :
public :
    CMatriceGaussJordan(unsigned int uiTaille);

    CMatriceGaussJordan CMCIdentite(unsigned int uiTaille);

    CMatriceGaussJordan(const char* pcMatriceString, const char* pcDefaultDelimValues, const char* pcDefaultDelimLines);

    CMatriceGaussJordan CMCInverseGJ(CMatriceGaussJordan CMCParam);

    CMatrice<T> getLigne(unsigned int uiNumLigne);

    void CMCEchangeLignes(unsigned int uiIndexOne, unsigned int uiIndexTwo);

};


#endif //MATRICES_CMATRICEGAUSSJORDAN_H
