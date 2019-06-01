
#include "CMatriceExtractor.h"

template<class T>
CMatriceExtractor<T>::CMatriceExtractor(CMatrice<T> &MATParam) {
    pMAEMatrice = new CMatrice<T>(MATParam);
}


template<class T>
CMatrice<T> &CMatriceExtractor<T>::MAEget(unsigned int uiLigneFrom, unsigned int uiColFrom, unsigned int uiLigneTo,
                                          unsigned int uiColTo) {
    if ((uiLigneFrom > uiLigneTo) || (uiColFrom > uiColTo) || (uiLigneTo > pMAEMatrice->getNbLignes()) ||
        (uiColTo > pMAEMatrice->getNbColonnes())) {
        throw new CException("Error CMatriceExtractor");
    }
    CMatrice<T> *pMATToReturn = new CMatrice<T>(uiLigneTo - uiLigneFrom, uiColTo - uiColFrom);
    unsigned int uiLigTmp, uiColTmp;
    for (uiLigTmp = uiLigneFrom; uiLigTmp < uiLigneTo; uiLigTmp++) {
        for (uiColTmp = uiColFrom; uiColTmp < uiColTo; uiColTmp++) {
            pMATToReturn->setValeur(pMAEMatrice->getValeur(uiLigTmp, uiColTmp), uiLigTmp - uiLigneFrom,
                                    uiColTmp - uiColFrom);
        }
    }
    return *pMATToReturn;
}

template<class T>
CMatriceExtractor<T>::~CMatriceExtractor() {
    delete (pMAEMatrice);
}

template<class T>
CMatrice<T> &CMatriceExtractor<T>::MAEgetLigne(unsigned int uiLigne) {
    return MAEget(uiLigne, 0, uiLigne, pMAEMatrice->getNbColonnes());
}

template<class T>
CMatrice<T> &CMatriceExtractor<T>::MAEgetColonne(unsigned int uiCol) {
    return MAEget(0, uiCol, pMAEMatrice->getNbLignes(), uiCol);
}
