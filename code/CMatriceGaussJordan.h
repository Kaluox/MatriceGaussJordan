#ifndef MATRICES_CMATRICEGAUSSJORDAN_H
#define MATRICES_CMATRICEGAUSSJORDAN_H

#include "CMatrice.h"
#include "CMatriceExtractor.h"

/**
 * @class CMatriceGaussJordan
 * @tparam T
 * @desc A class for inverting a CMatrice. This class uses the Gauss-Jordan method. {@link CMatrice#MATInverse}
 */
template<class T>
class CMatriceGaussJordan {
private :
    /**
     * @name CMatriceGaussJordan#pMGJMATMatrice
     * @type {CMatrice<T>}
     * @desc The resulting inverted CMatrice is here. Get by using the method {@link CMatriceGaussJordan#MGJGet}.
     * @private
     */
    CMatrice<T> *pMGJMATMatrice;

    /**
     * @fn CMatriceGaussJordan#MGJGenerateId
     * @param {unsigned int} uiNbLignes
     * @param {unsigned int} uiNbColonnes
     * @desc Generates a CMatrice identity with the specified uiNbLignes & uiNbColonnes param.
     * @return {CMatrice<T>&}
     * @private
     */
    CMatrice<T> &MGJGenerateId(unsigned int uiNbLignes, unsigned int uiNbColonnes);

    /**
     * @fn CMatriceGaussJordan#MGJEchangeLignes
     * @param {unsigned int} uiIndexOne
     * @param {unsigned int} uiIndexTwo
     * @desc Exchange the lines specified of {@link CMatriceGaussJordan#pMGJMATMatrice}.
     * @private
     */
    void MGJEchangeLignes(unsigned int uiIndexOne, unsigned int uiIndexTwo);

    /**
     * @fn CMatriceGaussJordan#MGJSetLigne
     * @param {CMatrice<T>&} MATLigne - Must be a line --> 1 line and same nb columns as {@link CMatriceGaussJordan#pMGJMATMatrice}
     * @param {unsigned int} uiLigneNb - The line which must be change.
     * @desc Sets the line specified to the specified set of values.
     * @private
     */
    void MGJSetLigne(CMatrice<T> &MATLigne, unsigned int uiLigneNb);

public :
    /**
     * @constructor
     * @param {CMatrice<T> &} oMATParam
     * @desc Creates a new CMatriceGaussJordan. Does all operations. Once called just use the getter to retrieve {@link CMatriceGaussJordan#pMGJMATMatrice}.
     */
    CMatriceGaussJordan(CMatrice<T> &oMATParam);

    /**
     * @desctructor
     */
    ~CMatriceGaussJordan();

    /**
     * @fn CMatriceGaussJordan#MGJget
     * @return {CMatrice<T> &}
     * @desc Returns {@link CMatriceGaussJordan#pMGJMATMatrice}.
     */
    CMatrice<T> &MGJget();
};


#include "CMatriceGaussJordan.cpp"

#endif //MATRICES_CMATRICEGAUSSJORDAN_H
