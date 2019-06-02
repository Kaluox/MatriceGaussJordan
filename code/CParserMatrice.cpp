#include "CParserMatrice.h"

CParserMatrice::CParserMatrice(const char *pcFilePath) : CParser(pcFilePath) {
    std::string bufferString;
    const char *opcBufferValue;
    const char **ppcBuffer;
    unsigned int uiFieldNum;
    unsigned int uiNbLignes = 0, uiNbColonnes = 0;
    std::string matriceBufferString;

    for (uiFieldNum = 0; uiFieldNum < PARGetNbFields(); uiFieldNum++) {
        bufferString = PARGetFields()[uiFieldNum];//fields
        ppcBuffer = PARGet(bufferString.c_str());//values
        switch (PMAResolveField(bufferString.c_str())) {
            case TypeMatrice: {
                if (strcmp(ppcBuffer[0], "double") != 0) {
                    throw new CException("ERROR: file specified type is not double");
                }
                break;
            }
            case NBLignes: {
                uiNbLignes = (unsigned int) std::stod(ppcBuffer[0]);
                break;
            }
            case NBColonnes: {
                uiNbColonnes = (unsigned int) std::stod(ppcBuffer[0]);
                break;
            }
            case Matrice: {
                unsigned int uiIteratorLigne;
                for (uiIteratorLigne = 0; uiIteratorLigne < uiNbLignes; uiIteratorLigne++) {
                    matriceBufferString += ppcBuffer[uiIteratorLigne];
                    matriceBufferString += ":";
                }
                break;
            }
            case INVALID: {
                throw new CException("ERROR Invalid file structure.");
                break;
            }
            default: {
                throw new CException("ERROR Invalid file structure.");
                break;
            }
        }
    }
    pMATPMAMatrice = new CMatrice<double>(matriceBufferString.c_str(), " ", ":");
}

CParserMatrice::Fields CParserMatrice::PMAResolveField(const char *pcFieldString) {
    if (strcmp(pcFieldString, "TypeMatrice") == 0) { return TypeMatrice; }
    else if (strcmp(pcFieldString, "NBLignes") == 0) { return NBLignes; }
    else if (strcmp(pcFieldString, "NBColonnes") == 0) { return NBColonnes; }
    else if (strcmp(pcFieldString, "Matrice") == 0) { return Matrice; }
    else { return INVALID; }
}

CMatrice<double> &CParserMatrice::PMAGetMatrice() {
    return *pMATPMAMatrice;
}
