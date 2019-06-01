#ifndef MATRICEGAUSSJORDAN_CMATRICEEXTRACTOR_H
#define MATRICEGAUSSJORDAN_CMATRICEEXTRACTOR_H

#include "CMatrice.h"

template<class T>
class CMatriceExtractor {
private:
    CMatrice<T> *pMAEMatrice;
public:
    CMatriceExtractor(CMatrice<T> *MATParam);

    ~CMatriceExtractor();

    CMatrice<T> &MAEget(unsigned int uiLigneFrom, unsigned int uiColFrom, unsigned int uiLigneTo, unsigned int uiColTo);

    CMatrice<T> &MAEgetLigne(unsigned int uiLigne);

    CMatrice<T> &MAEgetColonne(unsigned int uiCol);
};

#include "CMatriceExtractor.cpp"

#endif //MATRICEGAUSSJORDAN_CMATRICEEXTRACTOR_H
