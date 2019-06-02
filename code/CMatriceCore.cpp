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
    if (!((iMACNbLignes == 0) || (iMACNbColonnes == 0))) {
        //printf("[%d, %d]\n", iMACNbColonnes, iMACNbColonnes);
        unsigned int uiLigne = 0;
        for (uiLigne = iMACNbLignes; uiLigne > 0; uiLigne--) {
            delete (ppMACValeurs[uiLigne - 1]);
            ppMACValeurs[uiLigne - 1] = nullptr;
            if (uiLigne == 1) { break; }
        }
    }
    delete (ppMACValeurs);
    ppMACValeurs = nullptr;
    iMACNbLignes = 0;
    iMACNbColonnes = 0;
    //std::cout << "-- CMatriceCore destructor" << std::endl;
}

template<class T>
unsigned int CMatriceCore<T>::getNbLignes() const {
    return iMACNbLignes;
}

template<class T>
unsigned int CMatriceCore<T>::getNbColonnes() const {
    return iMACNbColonnes;
}

template<class T>
T **CMatriceCore<T>::getValeurs() const{
    return ppMACValeurs;
}

template<class T>
T CMatriceCore<T>::getValeur(unsigned int iPositionLigne, unsigned int iPositionColonne) const {
    if(iPositionColonne<0 || iPositionColonne>getNbColonnes()){
        throw new CException();
    }
    if(iPositionLigne<0 || iPositionLigne>getNbLignes()){
        throw new CException();
    }
    return ppMACValeurs[iPositionLigne][iPositionColonne];
}

template<class T>
void CMatriceCore<T>::setValeurs_(T **ppValeurs, unsigned int iNbLignes, unsigned int iNbColonnes) {
    iMACNbLignes = iNbLignes;
    iMACNbColonnes = iNbColonnes;
    try {
        ppMACValeurs = (T **) realloc(ppMACValeurs, iNbLignes * sizeof(T *));
        for (unsigned int iLigne = 0; iLigne < (iNbLignes); iLigne++) {
            ppMACValeurs[iLigne] = (T *) malloc(iNbColonnes * sizeof(T));
            for (unsigned int iColonne = 0; iColonne < (iNbColonnes); iColonne++) {
                setValeur(ppValeurs[iLigne][iColonne], iLigne, iColonne);
            }
        }
    } catch (CException const &exception) {
        throw exception;
    }
}

template<class T>
void CMatriceCore<T>::setValeur(T valeur, unsigned int iPositionLigne, unsigned int iPositionColonne) {
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
void CMatriceCore<T>::MACAfficher() {
    for (unsigned int i = 0; i < getNbLignes(); i++) {
        for (unsigned int j = 0; j < getNbColonnes(); j++) {
            printf("%f ", getValeur(i, j));
        }
        printf("\n");
    }
}



