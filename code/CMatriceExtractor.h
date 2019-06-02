#ifndef MATRICEGAUSSJORDAN_CMATRICEEXTRACTOR_H
#define MATRICEGAUSSJORDAN_CMATRICEEXTRACTOR_H

#include "CMatrice.h"

/**
 * @class CMatriceExtractor
 * @tparam T
 * @desc A class for extracting a CMatrice<T> from a CMatrice<T>.
 */
template<class T>
class CMatriceExtractor {
private:
    /**
     * @name CMatriceExtractor#pMAEMatrice
     * @type {CMatrice<T> *}
     * @desc A pointer to a {@link CMatrice}.
     * Keeps the original pointer so that the returned CMatrice from one of this class's methods is still relevant,
     * even after operations on the original CMatrice.
     * @private
     */
    CMatrice<T> *pMAEMatrice;
public:
    /**
     * @constructor
     * @param {CMatrice<T>*} pMATParam - A pointer to a CMatrice<T>
     * @desc Creates a CMatriceExtractor. Once created, all *sub-CMatrice<T>* can be extracted.
     */
    CMatriceExtractor(CMatrice<T> *pMATParam);

    /**
     * @destructor
     */
    ~CMatriceExtractor();

    /**
     * @fn CMatriceExtractor#MAEget
     * @param {unsigned int} uiLigneFrom - The position in terms of lines for the first value.
     * @param {unsigned int} uiColFrom - The position in terms of columns for the first value.
     * @param {unsigned int} uiLigneTo - The position in terms of lines for the last value.
     * @param {unsigned int} uiColTo - The position in terms of columns for the last value.
     * @return {CMatrice<T> &}
     * @desc Use to get a *sub-Cmatrice<T>* from the original CMatrice<T> from the specified coordonates.
     */
    CMatrice<T> &MAEget(unsigned int uiLigneFrom, unsigned int uiColFrom, unsigned int uiLigneTo, unsigned int uiColTo);

    /**
     * @fn CMatriceExtractor#MAEgetLigne
     * @param {unsigned int} uiLigne - The wanted line's number
     * @return {CMatrice<T> &}
     * @desc Returns the wanted line as a CMatrice<T> with a number of lines equals to 1.
     */
    CMatrice<T> &MAEgetLigne(unsigned int uiLigne);

    /**
     * @fn CMatriceExtractor#MAEgetColonne
     * @param {unsigned int} uiLigne - The wanted column's number
     * @return {CMatrice<T> &}
     * @desc Returns the wanted column as a CMatrice<T> with a number of columns equals to 1.
     */
    CMatrice<T> &MAEgetColonne(unsigned int uiCol);
};

#include "CMatriceExtractor.cpp"

#endif //MATRICEGAUSSJORDAN_CMATRICEEXTRACTOR_H
