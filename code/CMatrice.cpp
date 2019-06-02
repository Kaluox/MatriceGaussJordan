//#include "CMatrice.h"


#include "CMatrice.h"
#include "CException.h"
#include "CMatriceGaussJordan.h"

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

        unsigned int iLineNumber = -1;//current line number in loop
        unsigned int iColonneNumber = -1;//current column number in loop

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
        if ((std::string) (typeid(T).name()) != "double") {
            throw new CException("ERROR matrice type not [double].");
        }
        std::string sFileName = pcFileName;
        //std::cout << "\nCMatrice constructor from File [" << sFileName << "]." << std::endl;
        if (sFileName.find(".txt") == std::string::npos) {
            throw new CException("ERROR file not [.txt].");
        }
        std::ifstream ifstream;
        ifstream.open(sFileName, std::ifstream::in);
        if (ifstream.fail()) {
            throw new CException("ERROR File not found");
        }

        std::string part1, part2;
        std::string sMatriceType = "void";
        std::string sMatriceString;
        unsigned int iNbLignes = 0, iNbColonnes = 0;
        std::string::size_type stPosEqualSign;
        bool bMatriceStringOpened = false;
        for (std::string line; getline(ifstream, line);) {//for each line
            //std::cout << "reading line: '" << line << "'" << std::endl;
            stPosEqualSign = line.find("=");//position of the "=" sign in the line
            if (stPosEqualSign != std::string::npos) {//if position("=")!=end of line
                part1 = line.substr(0, stPosEqualSign);//everything before "="
                part2 = line.substr(stPosEqualSign + 1);//everything after "="
                if (part1 == "TypeMatrice") {
                    if (part2 != typeid(T).name()) {//integrity
                        throw new CException("The file does not have the right matrice type.");
                    }
                } else if (part1 == "NBLignes") {
                    iNbLignes = (int) std::stod(part2);
                } else if (part1 == "NBColonnes") {
                    iNbColonnes = (int) std::stod(part2);
                } else if (part1 == "Matrice") {
                    if (part2 == "[") {
                        bMatriceStringOpened = true;
                    } else {
                        throw new CException("The file does not have the right structure.1");
                    }
                } else {
                    throw new CException("The file does not have the right structure.2");
                }
            } else {
                if (line == "]" && bMatriceStringOpened) {
                    sMatriceString = sMatriceString.substr(0, sMatriceString.size() - 1);
                    bMatriceStringOpened = false;
                }
                if (bMatriceStringOpened) {
                    //values are passed by here
                    sMatriceString = sMatriceString + line + ":";
                } else {
                    //throw new CException("The file does not have the right structure.3");
                }
            }
        }
        //std::cout << std::endl;
        //std::cout << "Got : '" << sMatriceString << "'" << std::endl;
        ifstream.close();
        setValeurs(sMatriceString.c_str(), " ", ":");
        if (iNbLignes != getNbLignes()) {
            throw new CException();
        }
        if (iNbColonnes != getNbColonnes()) {
            throw new CException();
        }
    } catch (std::exception const &exception) {
        std::cerr << exception.what() << "\n";
        throw new CException("ERROR unable to create new CMatrice from file.");

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
            if (getValeur(iLigne, iColonne) != matrice.getValeur(iLigne, iColonne)) {
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
    CMatriceGaussJordan<T> *MGJMatrice = new CMatriceGaussJordan<T>(*this);
    return MGJMatrice->MGJget();
}




