//#include "CMatriceCore.h"
#include "CException.h"

template<class T>
CMatriceCore<T>::CMatriceCore() {
    iMACNbLignes = 0;
    iMACNbColonnes = 0;
    ppMACValeurs = (T**)malloc(sizeof(T*));
    try {
        setValeurs_((T **) nullptr, 0, 0);
    } catch (CException const &exception) {
        throw exception;
    }
}

template<class T>
CMatriceCore<T>::CMatriceCore(const CMatriceCore<T> &matriceCore) {
    //std::cout << "copy CMatriceCore constructor" << std::endl;
    iMACNbLignes = matriceCore.getNbLignes();
    iMACNbColonnes = matriceCore.getNbColonnes();
    ppMACValeurs = (T **) malloc(sizeof(T *));
    setValeurs_(matriceCore.getValeurs(), iMACNbLignes, iMACNbColonnes);
}

template<class T>
CMatriceCore<T>::~CMatriceCore() {
    for (int iLigne = getNbLignes() - 1; iLigne >= 0; iLigne--) {
        delete (ppMACValeurs[iLigne]);
        ppMACValeurs[iLigne] = nullptr;
    }
    delete (ppMACValeurs);
    ppMACValeurs = nullptr;
    iMACNbLignes = 0;
    iMACNbColonnes = 0;
    //std::cout << "-- CMatriceCore destructor" << std::endl;
}

template<class T>
int CMatriceCore<T>::getNbLignes() const{
    return iMACNbLignes;
}

template<class T>
int CMatriceCore<T>::getNbColonnes() const{
    return iMACNbColonnes;
}

template<class T>
T **CMatriceCore<T>::getValeurs() const{
    return ppMACValeurs;
}

template<class T>
T CMatriceCore<T>::getValeur(int iPositionLigne, int iPositionColonne) const {
    if(iPositionColonne<0 || iPositionColonne>getNbColonnes()){
        throw new CException();
    }
    if(iPositionLigne<0 || iPositionLigne>getNbLignes()){
        throw new CException();
    }
    return ppMACValeurs[iPositionLigne][iPositionColonne];
}

template<class T>
void CMatriceCore<T>::setValeurs_(T ** ppValeurs, int iNbLignes, int iNbColonnes) {
    iMACNbLignes = iNbLignes;
    iMACNbColonnes = iNbColonnes;
    try {
        ppMACValeurs = (T **) realloc(ppMACValeurs, iNbLignes * sizeof(T *));
        for (int iLigne = 0; iLigne < (iNbLignes); iLigne++) {
            ppMACValeurs[iLigne] = (T *) malloc(iNbColonnes * sizeof(T));
            for (int iColonne = 0; iColonne < (iNbColonnes); iColonne++) {
                setValeur(ppValeurs[iLigne][iColonne], iLigne, iColonne);
            }
        }
    } catch (CException const &exception) {
        throw exception;
    }
}

template<class T>
void CMatriceCore<T>::setValeur(T valeur, int iPositionLigne, int iPositionColonne) {
    if(iPositionColonne<0 || iPositionColonne>getNbColonnes()){
        throw new CException("position column.");
    }
    if(iPositionLigne<0 || iPositionLigne>getNbLignes()){
        throw new CException("position line.");
    }
    //ppMACValeurs[iPositionLigne][iPositionColonne] = (T)realloc(ppMACValeurs[iPositionLigne][iPositionColonne],sizeof(T));
    ppMACValeurs[iPositionLigne][iPositionColonne] = valeur;
}

template<class T>
std::ostream& operator<<(std::ostream &strm, const CMatriceCore<T> &matriceCore) {
    for (int i = 0; i < matriceCore.getNbLignes(); i++) {
        for (int j = 0; j < matriceCore.getNbColonnes(); j++) {
            strm << std::to_string((int)matriceCore.getValeur(i, j));
            strm << " ";
        }
        strm << "\n";
    }
    return strm;
}



