#define __STDC_WANT_LIB_EXT1__ 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include "CParser.h"
#include "CException.h"

CParser::CParser(const char *pcFilePath) {
    uiPARNbFields = 0;
    uiPARNbValues = 0;
    pcPARFields = (char **) malloc(sizeof(char *));
    pcPARValues = (char ***) malloc(sizeof(char **));
    extractValues(pcFilePath);
}

const char **CParser::PARGetFields() {
    return (const char **) pcPARFields;
}

const char ***CParser::PARGetValues() {
    return (const char ***) pcPARValues;
}

const char **CParser::PARGet(const char *pcField) {
    unsigned int uiFieldNum;
    for (uiFieldNum = 0; uiFieldNum < uiPARNbFields; uiFieldNum++) {
        if (strcmp(pcField, pcPARFields[uiFieldNum]) == 0) {
            return (const char **) pcPARValues[uiFieldNum];
        }
    }
    throw new CException("ERROR: CParser field not found.");
}

const char **CParser::operator()(const char *pcField) {
    return PARGet(pcField);
}

void CParser::extractValues(const char *pcFilePath) {
    std::string bufferString, bufferString2, part1, part2;
    bool bValueMultiline = false;
    bool bStringAnalysed = false;
    std::ifstream ifstream;
    size_t stPosEqualSign = 0, stPosCrochetOuvrant = 0, stPosCrochetFermant = 0;
    int iOsef;

    ifstream.open(pcFilePath, std::ifstream::in);
    if (ifstream) {
        unsigned int uiTmpNbValues;
        for (bufferString; getline(ifstream, bufferString);) {

            if (bValueMultiline) {
                stPosCrochetFermant = bufferString.find(']');
                if ((stPosCrochetFermant != std::string::npos)) {
                    bValueMultiline = false;
                    uiPARNbValues += 1;
                } else {
                    pcPARValues[uiPARNbValues] = (char **) realloc(pcPARValues[uiPARNbValues],
                                                                   (uiTmpNbValues + 1) * sizeof(char *));
                    pcPARValues[uiPARNbValues][uiTmpNbValues] = (char *) malloc(
                            (bufferString.size() + 1) * sizeof(char));
                    iOsef = strcpy_s(pcPARValues[uiPARNbValues][uiTmpNbValues], bufferString.size() + 1,
                                     bufferString.c_str());
                    uiTmpNbValues += 1;
                }
            } else {
                stPosEqualSign = bufferString.find('=');//position of the "=" sign in the line
                if (stPosEqualSign != std::string::npos) {//if position("=") exists
                    part1 = bufferString.substr(0, stPosEqualSign);//everything before "="
                    part2 = bufferString.substr(stPosEqualSign + 1);//everything after "="
                    pcPARFields = (char **) realloc(pcPARFields, (uiPARNbFields + 1) * sizeof(char *));
                    pcPARFields[uiPARNbFields] = (char *) malloc((part1.size() + 1) * sizeof(char));
                    iOsef = strcpy_s(pcPARFields[uiPARNbFields], part1.size() + 1, part1.c_str());
                    uiPARNbFields += 1;

                    pcPARValues = (char ***) realloc(pcPARValues, (uiPARNbValues + 1) * sizeof(char **));
                    pcPARValues[uiPARNbValues] = (char **) malloc(sizeof(char *));
                    stPosCrochetOuvrant = part2.find('[');
                    if (stPosCrochetOuvrant != std::string::npos) {
                        bValueMultiline = true;
                        uiTmpNbValues = 0;
                    } else {
                        pcPARValues[uiPARNbValues][0] = (char *) malloc((part2.size() + 1) * sizeof(char));
                        iOsef = strcpy_s(pcPARValues[uiPARNbValues][0], part2.size() + 1, part2.c_str());
                        uiPARNbValues += 1;
                    }
                }
            }
        }
        ifstream.close();
    } else {
        throw new CException("ERROR");
    }

}

CParser::~CParser() {
    delete (pcPARFields);
    delete (pcPARValues);
}

unsigned int CParser::PARGetNbFields() {
    return uiPARNbFields;
}

unsigned int CParser::PARGetNbValues() {
    return uiPARNbValues;
}
