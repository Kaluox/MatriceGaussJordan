
#include "CMatriceGaussJordan.h"
#include "CMatriceExtractor.h"

template<class T>
CMatriceGaussJordan<T> CMatriceGaussJordan<T>::CMCInverseGJ(CMatriceGaussJordan CMCParam) {
    if(getNbColonnes() != getNbLignes()) {
        throw new CException("\nLa matrice n'est pas carrée !\n");
    }
    else{
        CMatriceGaussJordan<T> tmp(*this);
        CMatriceGaussJordan<T> *tmpIdentite = new CMCIdentite(getNbLignes());
        unsigned int uiLigneLastPivot = 0;
        unsigned int uiLignePivot = 0;
        //std::cout << *tmpI <<std::endl;
        for(int indexColonne = 0 ; indexColonne < getNbColonnes() ; indexColonne++){
            int iValeurPivot = tmp.getValeur(indexColonne,indexColonne);
            for(int indexLigne = uiLigneLastPivot ; indexLigne < getNbLignes() ; indexLigne++){
                if(iValeurPivot < abs(tmp.getValeur(indexLigne, indexColonne))){
                    iValeurPivot = tmp.getValeur(indexLigne, indexColonne);
                    uiLignePivot = indexLigne;
                }
            }
            if(iValeurPivot != 0){
                if(uiLignePivot != indexColonne){
                    tmp->CMCEchangeLignes(uiLignePivot,indexColonne);
                    tmpIdentite->CMCEchangeLignes(uiLignePivot,indexColonne);
                }
                tmp->getLigne(indexColonne)/iValeurPivot;
                tmpIdentite->getLigne(indexColonne)/iValeurPivot;
                if(indexColonne!=getNbColonnes()){
                    for(int indexLigne = indexColonne + 1 ; indexLigne < getNbLignes() ; indexLigne++){
                        tmp.getLigne(indexLigne)-tmp.getLigne(indexColonne)*tmp.getLigne(indexLigne).getValeur(0,indexColonne);
                        tmpIdentite.getLigne(indexLigne)-tmpIdentite.getLigne(indexColonne)*tmpIdentite.getLigne(indexLigne).getValeur(0,indexColonne);
                    }
                }
            }
            else{
                throw new CException("Le pivot c'est pas ouf")
            }

        }
    }
    return tmpIdentite;
}


template<class T>
void CMatriceGaussJordan<T>::MGJEchangeLignes(unsigned int uiIndexOne, unsigned int uiIndexTwo) {
    CMatriceExtractor<T> MAEMatriceExtractor(*pMGJMATMatrice);
    CMatrice<T> tmpLigne1 = MAEMatriceExtractor.MAEgetLigne(uiIndexOne);
    CMatrice<T> tmpLigne2 = MAEMatriceExtractor.MAEgetLigne(uiIndexTwo);
    for (int index = 0; index < getNbColonnes(); index++) {
        this->setValeur(tmpLigne2.getValeur(1, index), uiIndexOne, index);
        this->setValeur(tmpLigne1.getValeur(1, index), uiIndexTwo, index);
    }
}

template<class T>
CMatriceGaussJordan<T>::CMatriceGaussJordan(CMatrice<T> &MATParam) {
    unsigned int uiNbLignes = MATParam.getNbLignes();
    unsigned int uiNbColonnes = MATParam.getNbColonnes();
    pMGJMATMatrice = new CMatrice<T>(uiNbLignes, uiNbColonnes * 2);

    CMatrice<T> MATId = MGJGenerateId(uiNbLignes, uiNbColonnes);
    unsigned int uiLigneIterator, uiColonneIterator;
    for (uiLigneIterator = 0; uiLigneIterator < uiNbLignes; uiLigneIterator++) {
        for (uiColonneIterator = 0; uiColonneIterator < uiNbColonnes; uiColonneIterator++) {
            pMGJMATMatrice->setValeur(MATParam.getValeur(uiLigneIterator, uiColonneIterator), uiLigneIterator,
                                      uiColonneIterator);
        }
        for (uiColonneIterator = uiNbColonnes; uiColonneIterator < uiNbColonnes * 2; uiColonneIterator++) {
            pMGJMATMatrice->setValeur(MATId.getValeur(uiLigneIterator, uiColonneIterator), uiLigneIterator,
                                      uiColonneIterator);
        }
    }
    //pMGJMATMatrice = [MATParam|MATId]


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
    delete (pMGJMATMatrice);
}

template<class T>
CMatrice<T> &CMatriceGaussJordan<T>::MGJget() {
    return *pMGJMATMatrice;
}
