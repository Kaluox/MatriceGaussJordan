//
// Created by alexi on 24/05/2019.
//

#include "CMatriceGaussJordan.h"

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
CMatriceGaussJordan<T> CMatriceGaussJordan<T>::CMCIdentite(unsigned int uiTaille) {
    CMatriceGaussJordan CMCIdentite = new CMatriceGaussJordan(uiTaille);
    for(int index = 0; index < uiTaille ; index++){
        CMCIdentite.setValeur(1,index,index);
    }
    return CMCIdentite;
}

template<class T>
CMatriceGaussJordan<T>::CMatriceGaussJordan(unsigned int uiTaille) {
    CMatrice(uiTaille, uiTaille);
}

template<class T>
CMatrice<T> CMatriceGaussJordan<T>::getLigne(unsigned int uiNumLigne) {
    CMatrice tmpLigne = CMatrice(1,getNbColonnes());
    for(int iIndex = 0 ; iIndex < getNbColonnes() ; iIndex++){
        tmpLigne.setValeur(this->getValeur(uiNumLigne,iIndex),1,iIndex);
    }
    return tmpLigne;
}

template<class T>
void CMatriceGaussJordan<T>::CMCEchangeLignes(unsigned int uiIndexOne, unsigned int uiIndexTwo) {
    CMatrice tmpLigne1 = this->getLigne(uiIndexOne);
    CMatrice tmpLigne2 = this->getLigne(uiIndexTwo);
    for(int index = 0 ; index < getNbColonnes() ; index++){
        this->setValeur(tmpLigne2.getValeur(1,index),uiIndexOne,index);
        this->setValeur(tmpLigne1.getValeur(1,index),uiIndexTwo,index);
    }
}

template<class T>
CMatriceGaussJordan<T>::CMatriceGaussJordan(const char *pcMatriceString, const char *pcDefaultDelimValues,
                                  const char *pcDefaultDelimLines){
    new CMatrice(*pcMatriceString, *pcDefaultDelimValues, *pcDefaultDelimLines);
    if(this->getNbLigne() != this->getNbColonnes()){
        std::cout<<"Bof bof"<<std::endl;
    }

}




