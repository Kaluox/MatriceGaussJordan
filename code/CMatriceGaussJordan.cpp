
template<class T>
void CMatriceGaussJordan<T>::MGJEchangeLignes(unsigned int uiIndexOne, unsigned int uiIndexTwo) {
    CMatriceExtractor<T> *MAEMatriceExtractor = new CMatriceExtractor<T>(pMGJMATMatrice);
    CMatrice<T> tmpLigne1 = MAEMatriceExtractor->MAEgetLigne(uiIndexOne);
    CMatrice<T> tmpLigne2 = MAEMatriceExtractor->MAEgetLigne(uiIndexTwo);
    //pMGJMATMatrice->MACAfficher();
    MGJSetLigne(tmpLigne1, uiIndexTwo);
    //pMGJMATMatrice->MACAfficher();
    MGJSetLigne(tmpLigne2, uiIndexOne);
    //pMGJMATMatrice->MACAfficher();
    delete (MAEMatriceExtractor);
}

template<class T>
CMatriceGaussJordan<T>::CMatriceGaussJordan(CMatrice<T> &MATParam) {
    pMGJMATMatrice = (CMatrice<T> *) malloc(sizeof(CMatrice<T>));
    unsigned int uiNbLignes = MATParam.getNbLignes();
    unsigned int uiNbColonnes = MATParam.getNbColonnes();
    pMGJMATMatrice = new CMatrice<T>(uiNbLignes, uiNbColonnes * 2);
    //Empty for now

    CMatrice<T> MATId = MGJGenerateId(uiNbLignes, uiNbColonnes);
    unsigned int uiLigneIterator, uiColonneIterator;
    for (uiLigneIterator = 0; uiLigneIterator < uiNbLignes; uiLigneIterator++) {
        for (uiColonneIterator = 0; uiColonneIterator < uiNbColonnes; uiColonneIterator++) {
            pMGJMATMatrice->setValeur(MATParam.getValeur(uiLigneIterator, uiColonneIterator), uiLigneIterator,
                                      uiColonneIterator);
        }
        for (uiColonneIterator = uiNbColonnes; uiColonneIterator < uiNbColonnes * 2; uiColonneIterator++) {
            pMGJMATMatrice->setValeur(MATId.getValeur(uiLigneIterator, uiColonneIterator - uiNbColonnes),
                                      uiLigneIterator,
                                      uiColonneIterator);
        }
    }
    //pMGJMATMatrice = [MATParam|MATId]

    CMatriceExtractor<T> *pMAEMatriceExtractor = new CMatriceExtractor<T>(pMGJMATMatrice);
    CMatriceExtractor<T> MAEMatriceExtractor = *pMAEMatriceExtractor;
    CMatrice<T> MATLigneTmp;
    CMatrice<T> MATLignePivot;
    unsigned int uiLastPivotFound = 0;
    unsigned int uiLignePivot = 0;
    T tValPivot;
    for (uiColonneIterator = 0; uiColonneIterator < uiNbColonnes; uiColonneIterator++) {
        tValPivot = pMGJMATMatrice->getValeur(uiColonneIterator, uiColonneIterator);
        uiLignePivot = uiColonneIterator;
        //*
        for (uiLigneIterator = uiLastPivotFound; uiLigneIterator < pMGJMATMatrice->getNbLignes(); uiLigneIterator++) {
            if (tValPivot < abs(pMGJMATMatrice->getValeur(uiLigneIterator, uiColonneIterator))) {
                tValPivot = pMGJMATMatrice->getValeur(uiLigneIterator, uiColonneIterator);
                uiLignePivot = uiLigneIterator;
            }
        }
        if (tValPivot != (T) 0) {
            uiLastPivotFound = uiLignePivot;
            if (uiLignePivot != uiColonneIterator) {
                MGJEchangeLignes(uiLignePivot, uiColonneIterator);
            }
            MATLignePivot = MAEMatriceExtractor.MAEgetLigne(uiColonneIterator);
            MATLignePivot /= tValPivot;
            MGJSetLigne(MATLignePivot, uiColonneIterator);

            for (uiLigneIterator = uiColonneIterator + 1; uiLigneIterator < uiNbLignes; uiLigneIterator++) {
                MGJSetLigne(MAEMatriceExtractor.MAEgetLigne(uiLigneIterator) -
                            (MATLignePivot * pMGJMATMatrice->getValeur(uiLigneIterator, uiColonneIterator)),
                            uiLigneIterator);
            }
        }
    }
    for (uiColonneIterator = uiNbColonnes - 1; uiColonneIterator > 0; uiColonneIterator--) {
        MATLignePivot = MAEMatriceExtractor.MAEgetLigne(uiColonneIterator);
        for (uiLigneIterator = 0; uiLigneIterator < uiColonneIterator; uiLigneIterator++) {
            MGJSetLigne(MAEMatriceExtractor.MAEgetLigne(uiLigneIterator) -
                        (MATLignePivot * pMGJMATMatrice->getValeur(uiLigneIterator, uiColonneIterator)),
                        uiLigneIterator);
        }
    }
    CMatrice<T> MATNewMatrice = MAEMatriceExtractor.MAEget(0, uiNbColonnes, uiNbLignes - 1, uiNbColonnes * 2 - 1);
    pMGJMATMatrice = new CMatrice<T>(MATNewMatrice);
    //delete(pMAEMatriceExtractor);
}

template<class T>
CMatrice<T> &CMatriceGaussJordan<T>::MGJGenerateId(unsigned int uiNbLignes, unsigned int uiNbColonnes) {
    CMatrice<T> *pMATMatriceIdentite = new CMatrice<T>(uiNbLignes, uiNbColonnes);
    unsigned int uiDiagIterator;
    for (uiDiagIterator = 0; uiDiagIterator < uiNbLignes; uiDiagIterator++) {
        pMATMatriceIdentite->setValeur((T) 1, uiDiagIterator, uiDiagIterator);
    }
    return *pMATMatriceIdentite;

}

template<class T>
CMatriceGaussJordan<T>::~CMatriceGaussJordan() {
}

template<class T>
CMatrice<T> &CMatriceGaussJordan<T>::MGJget() {
    return *pMGJMATMatrice;
}

template<class T>
void CMatriceGaussJordan<T>::MGJSetLigne(CMatrice<T> &MATLigne, unsigned int uiLigneNb) {
    //printf("MATLigne[%d, %d], [%d, %d]\n", MATLigne.getNbLignes(), MATLigne.getNbColonnes(), pMGJMATMatrice->getNbLignes(), pMGJMATMatrice->getNbColonnes());
    if ((MATLigne.getNbColonnes() != pMGJMATMatrice->getNbColonnes()) || (MATLigne.getNbLignes() != 1)) {
        throw new CException("Error: setLigne");
    }
    unsigned int uiColonneIterator;
    for (uiColonneIterator = 0; uiColonneIterator < pMGJMATMatrice->getNbColonnes(); uiColonneIterator++) {
        pMGJMATMatrice->setValeur(MATLigne.getValeur(0, uiColonneIterator), uiLigneNb, uiColonneIterator);
    }
    //pMGJMATMatrice->MACAfficher();
}
