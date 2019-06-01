template<class T>
CMatriceExtractor<T>::CMatriceExtractor(CMatrice<T> *MATParam) {
    pMAEMatrice = (CMatrice<T> *) malloc(sizeof(CMatrice<T>));
    pMAEMatrice = MATParam;
}


template<class T>
CMatrice<T> &CMatriceExtractor<T>::MAEget(unsigned int uiLigneFrom, unsigned int uiColFrom, unsigned int uiLigneTo,
                                          unsigned int uiColTo) {
    if ((uiLigneFrom > uiLigneTo) || (uiColFrom > uiColTo) || (uiLigneTo >= pMAEMatrice->getNbLignes()) ||
        (uiColTo >= pMAEMatrice->getNbColonnes())) {
        throw new CException("Error CMatriceExtractor");
    }
    CMatrice<T> *pMATToReturn = new CMatrice<T>(uiLigneTo - uiLigneFrom + 1, uiColTo - uiColFrom + 1);
    unsigned int uiLigTmp, uiColTmp;
    for (uiLigTmp = uiLigneFrom; uiLigTmp < uiLigneTo + 1; uiLigTmp++) {
        for (uiColTmp = uiColFrom; uiColTmp < uiColTo + 1; uiColTmp++) {
            pMATToReturn->setValeur(pMAEMatrice->getValeur(uiLigTmp, uiColTmp), uiLigTmp - uiLigneFrom,
                                    uiColTmp - uiColFrom);
        }
    }
    return *pMATToReturn;
}

template<class T>
CMatriceExtractor<T>::~CMatriceExtractor() {
    pMAEMatrice = nullptr;
}

template<class T>
CMatrice<T> &CMatriceExtractor<T>::MAEgetLigne(unsigned int uiLigne) {
    return MAEget(uiLigne, 0, uiLigne, pMAEMatrice->getNbColonnes() - 1);
}

template<class T>
CMatrice<T> &CMatriceExtractor<T>::MAEgetColonne(unsigned int uiCol) {
    return MAEget(0, uiCol, pMAEMatrice->getNbLignes() - 1, uiCol);
}
