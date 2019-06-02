
template<class T>
CMatrice<T>::CMatrice():CMatriceCore() {
    //std::cout << "Default CMatrice constructor." << std::endl;
}

template<class T>
CMatrice<T>::CMatrice(const CMatrice &matrice):CMatriceCore(matrice) {
    //std::cout << "Copy CMatrice constructor." << std::endl;
}

template<class T>
CMatrice<T>::CMatrice(unsigned int iNbLigne, unsigned int iNbColonne):CMatriceCore() {
    T **pptNewValeurs = (T **) malloc(iNbLigne * sizeof(T *));
    unsigned int iLigne, iColonne;
    for (iLigne = 0; iLigne < iNbLigne; iLigne++) {
        pptNewValeurs[iLigne] = (T *) malloc(iNbColonne * sizeof(T));
        for (iColonne = 0; iColonne < iNbColonne; iColonne++) {
            pptNewValeurs[iLigne][iColonne] = (T) 0;
        }
    }
    setValeurs_(pptNewValeurs, iNbLigne, iNbColonne);
}

template<class T>
CMatrice<T>::~CMatrice() {
    //std::cout << "-- CMatrice destructor." << std::endl;
}

template<class T>
void
CMatrice<T>::setValeurs(const char *pcMatriceString, const char *pcDefaultDelimValues,
                        const char *pcDefaultDelimLines) {
    if(pcMatriceString == ""){
        //throw new CException();
        return;
    }
    try {
        T **ppValeurs = (T **) malloc(sizeof(T *));//init

        std::string sMatriceString = pcMatriceString;//cast (for accessing string functions)
        std::string sMatriceStringLine = "";//for operation purposes

        std::string::size_type stPosDelimValue = 0;//for getting position of first occurence of pcDefaultDelimValues
        std::string::size_type stPosDelimLine = 0;//for getting position of first occurence of pcDefaultDelimLines

        int iLineNumber = -1;//current line number in loop
        int iColonneNumber = -1;//current column number in loop

        do {
            iLineNumber += 1;
            iColonneNumber = -1;

            ppValeurs = (T **) realloc(ppValeurs, (iLineNumber + 1) * sizeof(T *));
            ppValeurs[iLineNumber] = (T *) malloc(sizeof(T));

            stPosDelimLine = sMatriceString.find(pcDefaultDelimLines);
            sMatriceStringLine = sMatriceString.substr(0,
                                                       stPosDelimLine);//sMatriceString[oldDelimLine:newDelimLine] = 1 line

            do {
                iColonneNumber += 1;
                ppValeurs[iLineNumber] = (T *) realloc(ppValeurs[iLineNumber], (iColonneNumber + 1) * sizeof(T));
                stPosDelimValue = (std::string::size_type) std::fmin(sMatriceString.find(pcDefaultDelimValues),
                                                                     sMatriceString.find(pcDefaultDelimLines));
                ppValeurs[iLineNumber][iColonneNumber] = (T) std::stod(sMatriceStringLine,
                                                                       &stPosDelimValue);//cast+copy of value
                //std::cout << "cast value to ppValeur[i][j] : " << iLineNumber << "|" << iColonneNumber << " --> " << ppValeurs[iLineNumber][iColonneNumber] <<std::endl;
                sMatriceStringLine = sMatriceStringLine.substr(
                        stPosDelimValue);//sMatriceStringLine[stPosDelimValue:endline]
            } while ((stPosDelimValue != std::string::npos) && (sMatriceStringLine.size() != 0));//line ended
            sMatriceString = sMatriceString.substr(stPosDelimLine + 1);//remove part studied
        } while ((stPosDelimLine != std::string::npos) && (sMatriceString.size() != 0));
        setValeurs_(ppValeurs, iLineNumber + 1, iColonneNumber + 1);
    } catch (std::exception const &exception) {
        throw new CException(exception.what());
    }
}

template<class T>
CMatrice<T>::CMatrice(const char *pcMatriceString, const char *pcDefaultDelimValues, const char *pcDefaultDelimLines) {
    /*std::cout << "CMatrice constructor from String [" << pcMatriceString << "] with [" << pcDefaultDelimValues
              << "] and [" << pcDefaultDelimLines << "] as delim." << std::endl;/**/
    setValeurs(pcMatriceString, pcDefaultDelimValues, pcDefaultDelimLines);
}

template<class T>
CMatrice<T>::CMatrice(const char *pcFileName) {
    try {
        CParserMatrice parserMatrice(pcFileName);
        *this = parserMatrice.PMAGetMatrice();
    } catch (CException const &exception) {
        std::cerr << exception.what() << "\n";
        throw new CException("ERROR unable to create new CMatrice from file.");
    }
}

template<class T>
CMatrice<T> &CMatrice<T>::operator=(CMatrice &matrice) {
    //std::cout << "\toperator = " << "\n";
    try {
        setValeurs_(matrice.getValeurs(), matrice.getNbLignes(), matrice.getNbColonnes());
    } catch (CException const &exception) {
        throw exception;
    }
    return *this;
}


template<class T>
CMatrice<T> &CMatrice<T>::operator()(CMatrice &matrice) {
    //std::cout << "\toperator (matrice) " << "\n";
    try {
        setValeurs_(matrice.getValeurs(), matrice.getNbLignes(), matrice.getNbColonnes());
    } catch (CException const &exception) {
        throw exception;
    }
    return (*this);
}

template<class T>
CMatrice<T> &CMatrice<T>::operator()(const char *pcMatriceString, const char *pcDefaultDelimValues,
                                     const char *pcDefaultDelimLines) {
    //std::cout << "\toperator (string) " << "\n";
    try {
        setValeurs(pcMatriceString, pcDefaultDelimValues, pcDefaultDelimLines);
    } catch (CException const &exception) {
        throw exception;
    }
    return (*this);
}

template<class T>
bool CMatrice<T>::operator==(CMatrice &matrice) {
    if ((matrice.getNbLignes() != getNbLignes()) || (matrice.getNbColonnes() != getNbColonnes())) {
        return false;
    }
    unsigned int iColonne, iLigne;
    for (iLigne = 0; iLigne < getNbLignes(); iLigne++) {
        for (iColonne = 0; iColonne < getNbColonnes(); iColonne++) {
            if ((getValeur(iLigne, iColonne) - matrice.getValeur(iLigne, iColonne)) != 0) {
                return false;
            }
        }
    }
    return true;
}

template<class T>
CMatrice<T> &CMatrice<T>::operator+(T tVal) {
    //std::cout << "[+] " << tVal << "<" << typeid(T).name() << ">" << std::endl;
    CMatrice<T> *tmp = new CMatrice<T>(*this);
    unsigned int iColonne, iLigne;
    for (iLigne = 0; iLigne < getNbLignes(); iLigne++) {
        for (iColonne = 0; iColonne < getNbColonnes(); iColonne++) {
            tmp->setValeur(getValeur(iLigne, iColonne) + tVal, iLigne, iColonne);
        }
    }
    //std::cout << "returning:" << std::endl << *tmp << std::endl;
    return *tmp;
}

template<class T>
CMatrice<T> &CMatrice<T>::operator-(T tVal) {
    //std::cout << "[-] " << tVal << "<" << typeid(T).name() << ">" << std::endl;
    //std::cout << "returning:" << std::endl << (*this + (tVal * (-1))) << std::endl;
    return (*this + (tVal * (-1)));
}

template<class T>
CMatrice<T> &CMatrice<T>::operator*(T tVal) {
    //std::cout << "[*] " << tVal << "<" << typeid(T).name() << ">" << std::endl;
    CMatrice<T> *tmp = new CMatrice<T>(*this);
    unsigned int iColonne, iLigne;
    for (iLigne = 0; iLigne < getNbLignes(); iLigne++) {
        for (iColonne = 0; iColonne < getNbColonnes(); iColonne++) {
            tmp->setValeur(getValeur(iLigne, iColonne) * tVal, iLigne, iColonne);
        }
    }
    //std::cout << "returning:" << std::endl << *tmp << std::endl;
    return *tmp;
}

template<class T>
CMatrice<T> &CMatrice<T>::operator/(T tVal) {
    //std::cout << "[/] " << tVal << "<" << typeid(T).name() << ">" << std::endl;
    CMatrice<T> *tmp = new CMatrice<T>(*this);
    unsigned int iColonne, iLigne;
    for (iLigne = 0; iLigne < getNbLignes(); iLigne++) {
        for (iColonne = 0; iColonne < getNbColonnes(); iColonne++) {
            tmp->setValeur(getValeur(iLigne, iColonne) / tVal, iLigne, iColonne);
        }
    }
    return *tmp;
}

template<class T>
CMatrice<T> &CMatrice<T>::operator+=(T tVal) {
    //std::cout << "[+=] " << tVal << "<" << typeid(T).name() << ">" << std::endl;
    //std::cout << "returning:" << std::endl << (*this + tVal) << std::endl;
    return (*this)((*this) + tVal);
}

template<class T>
CMatrice<T> &CMatrice<T>::operator-=(T tVal) {
    //std::cout << "[-=] " << tVal << "<" << typeid(T).name() << ">" << std::endl;
    //std::cout << "returning:" << std::endl << (*this - tVal) << std::endl;
    return (*this)((*this) - tVal);
}

template<class T>
CMatrice<T> &CMatrice<T>::operator*=(T tVal) {
    //std::cout << "[*=] " << tVal << "<" << typeid(T).name() << ">" << std::endl;
    //std::cout << "returning:" << std::endl << (*this * tVal) << std::endl;
    return (*this)((*this) * tVal);
}

template<class T>
CMatrice<T> &CMatrice<T>::operator/=(T tVal) {
    //std::cout << "[/=] " << tVal << "<" << typeid(T).name() << ">" << std::endl;
    //std::cout << "returning:" << std::endl << (*this / tVal) << std::endl;
    return (*this)((*this) / tVal);
}

template<class T>
CMatrice<T> &CMatrice<T>::operator+(CMatrice &matrice) {
    //std::cout << "[+]" << std::endl  << matrice << std::endl;
    CMatrice<T> *tmp = new CMatrice<T>(*this);
    if ((matrice.getNbLignes() != getNbLignes()) || (matrice.getNbColonnes() != getNbColonnes())) {
        //throw new CException();
    }
    unsigned int iColonne, iLigne;
    for (iLigne = 0; iLigne < getNbLignes(); iLigne++) {
        for (iColonne = 0; iColonne < getNbColonnes(); iColonne++) {
            tmp->setValeur(getValeur(iLigne, iColonne) + matrice.getValeur(iLigne, iColonne), iLigne, iColonne);
        }
    }
    //std::cout << "returning:" << std::endl << *tmp << std::endl;
    return *tmp;
}

template<class T>
CMatrice<T> &CMatrice<T>::operator+=(CMatrice &matrice) {
    //std::cout << "[+=]" << std::endl << matrice << std::endl;
    //std::cout << "returning:" << std::endl << ((*this)+matrice) << std::endl;
    return (*this)((*this) + matrice);
}

template<class T>
CMatrice<T> &CMatrice<T>::operator-(CMatrice &matrice) {
    //std::cout << "[-]" << std::endl << matrice << std::endl;
    //std::cout << "returning:" << std::endl << ((*this)+matrice*(-1)) << std::endl;
    return ((*this) + matrice * (-1));
}

template<class T>
CMatrice<T> &CMatrice<T>::operator-=(CMatrice &matrice) {
    //std::cout << "[-=]" << std::endl << matrice << std::endl;
    //std::cout << "returning:" << std::endl << ((*this)+matrice*(-1)) << std::endl;
    return (*this)((*this) + matrice * (-1));
}

template<class T>
CMatrice<T> &CMatrice<T>::operator*(CMatrice &matrice) {
    //std::cout << "[*]" << std::endl << matrice << std::endl;
    //CMatrice<T>* tmp = new CMatrice<T>(*this);
    if (getNbColonnes() != matrice.getNbLignes()) {
        std::cerr << "error" << std::endl;
        //throw new CException();
    }
    CMatrice<T> *tmp = new CMatrice<T>(getNbLignes(), matrice.getNbColonnes());
    T tValue;
    unsigned int iLigne, iColonne, iIterator;
    for (iLigne = 0; iLigne < getNbLignes(); iLigne++) {
        for (iColonne = 0; iColonne < matrice.getNbColonnes(); iColonne++) {
            tValue = 0;
            for (iIterator = 0; iIterator < getNbColonnes(); iIterator++) {
                tValue += (getValeur(iLigne, iIterator) * matrice.getValeur(iIterator, iColonne));
            }
            tmp->setValeur(tValue, iLigne, iColonne);
        }
    }
    //std::cout << "returning:" << std::endl << *tmp << std::endl;
    return *tmp;
}

template<class T>
CMatrice<T> &CMatrice<T>::operator*=(CMatrice &matrice) {
    //std::cout << "[*=]" << std::endl << matrice << std::endl;
    //std::cout << "returning:" << std::endl << ((*this)*matrice) << std::endl;
    return (*this)((*this) * matrice);
}

template<class T>
CMatrice<T> &CMatrice<T>::oTranspose() {
    //std::cout << "[oTranspose]" << std::endl << *this << std::endl;
    CMatrice<T> *tmp = new CMatrice<T>(*this);
    T** newVal = (T**)malloc(getNbColonnes()*sizeof(T*));
    for (unsigned int iLigne = 0; iLigne < getNbColonnes(); iLigne++) {
        newVal[iLigne] = (T*)malloc(getNbLignes()*sizeof(T));
        for (unsigned int iColonne = 0; iColonne < getNbLignes(); iColonne++) {
            newVal[iLigne][iColonne] = getValeur(iColonne, iLigne);
        }
    }
    tmp->setValeurs_(newVal, getNbColonnes(), getNbLignes());
    //std::cout << *tmp << std::endl;
    return *tmp;
}

template<class T>
bool CMatrice<T>::operator!=(CMatrice &matrice) {
    return (!(*this == matrice));
}

template<class T>
CMatrice<T> &CMatrice<T>::MATInverse() {
    if ((getNbLignes() != getNbColonnes()) || (getNbLignes() == 0) || (getNbColonnes() == 0)) {
        throw new CException("ERROR: MATInverse dimensions not allowed.");
    }
    CMatriceGaussJordan<T> *MGJMatrice = new CMatriceGaussJordan<T>(*this);
    return MGJMatrice->MGJget();
}




