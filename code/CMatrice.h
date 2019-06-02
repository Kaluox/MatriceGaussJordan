#ifndef MATRICES_CMATRICE_H
#define MATRICES_CMATRICE_H

#include "CMatriceCore.h"
#include <fstream>

/**
 * \class CMatrice
 */
template<class T> class CMatrice : public CMatriceCore<T>{
private:
public:

    /**
     * \brief default constructor
     */
    CMatrice();

    /**
     * \brief file constructor
     * @param {const char*} pcFileName
     */
    explicit CMatrice(const char* pcFileName);

    /**
     * \brief string constructor
     * @param {const char*} pcMatriceString
     * @param {const char*} pcDefaultDelimValues
     * @param {const char*} pcDefaultDelimLines
     */
    CMatrice(const char* pcMatriceString, const char* pcDefaultDelimValues, const char* pcDefaultDelimLines);

    /**
     * \brief copy constructor
     * @param {const CMatrice<T> &} matrice
     */
    CMatrice(const CMatrice<T> & matrice);

    /**
     * \brief copy constructor
     * @param {int} iNbLigne
     * @param {int} iNbColonne
     */
    CMatrice(unsigned int iNbLigne, unsigned int iNbColonne);


    /**
     * \brief destructor
     */
    ~CMatrice();

    /**
     * \fn void setValeurs(const char* pcMatriceString, const char* pcDefaultDelimValues = " ", const char* pcDefaultDelimLines = ":")
     * @param {const char*} pcMatriceString
     * @param {const char*} pcDefaultDelimValues
     * @param {const char*} pcDefaultDelimLines
     */
    void setValeurs(const char* pcMatriceString, const char* pcDefaultDelimValues = " ", const char* pcDefaultDelimLines = ":");

    /**
     * \overload operator = (CMatrice& matrice)
     * @param {CMatrice<T> &} matrice
     * @return {CMatrice<T> &}
     */
    CMatrice& operator = (CMatrice& matrice);

    /**
     * \overload operator () (CMatrice& matrice)
     * @param {CMatrice<T> &} matrice
     * @return {CMatrice<T> &}
     */
    CMatrice &operator()(CMatrice &matrice);


    /**
     * \overload operator () (const char* pcMatriceString, const char* pcDefaultDelimValues = " ", const char* pcDefaultDelimLines = ":")
     * @param {const char*} pcMatriceString;
     * @param {const char*} pcDefaultDelimValues;
     * @param {const char*} pcDefaultDelimLines;
     * @return {CMatrice<T> &}
     */
    CMatrice &operator()(const char *pcMatriceString, const char *pcDefaultDelimValues = " ",
                         const char *pcDefaultDelimLines = ":");

    /**
     * \overload operator == (CMatrice<T> & matrice)
     * @param {CMatrice<T> &} matrice
     * @return {bool}
     */
    bool operator == (CMatrice& matrice);

    /**
     * \overload operator != (CMatrice<T> & matrice)
     * @param {CMatrice<T> &} matrice
     * @return {bool}
     */
    bool operator != (CMatrice& matrice);

    /**
     * \overload operator + (T tVal)
     * @param {T} tVal
     * @return {CMatrice<T> &}
     */
    CMatrice &operator+(T tVal);

    /**
     * \overload operator += (T tVal)
     * @param {T} tVal
     * @return {CMatrice<T> &}
     */
    CMatrice& operator += (T tVal);

    /**
     * \overload operator - (T tVal)
     * @param {T} tVal
     * @return {CMatrice<T> &}
     */
    CMatrice &operator-(T tVal);

    /**
     * \overload operator -= (T tVal)
     * @param {T} tVal
     * @return {CMatrice<T> &}
     */
    CMatrice& operator -= (T tVal);

    /**
     * \overload operator * (T tVal)
     * @param {T} tVal
     * @return {CMatrice<T> &}
     */
    CMatrice &operator*(T tVal);

    /**
     * \overload operator *= (T tVal)
     * @param {T} tVal
     * @return {CMatrice<T> &}
     */
    CMatrice& operator *= (T tVal);

    /**
     * \overload operator / (T tVal)
     * @param {T} tVal
     * @return {CMatrice<T> &}
     */
    CMatrice &operator/(T tVal);

    /**
     * \overload operator /= (T tVal)
     * @param {T} tVal
     * @return {CMatrice<T> &}
     */
    CMatrice& operator /= (T tVal);



    /**
     * \overload operator + (Cmatrice<T> & matrice)
     * @param {CMatrice<T> &}
     * @return {CMatrice<T> &}
     */
    CMatrice &operator+(CMatrice &matrice);

    /**
     * \overload operator += (Cmatrice<T> & matrice)
     * @param {CMatrice<T> &}
     * @return {CMatrice<T> &}
     */
    CMatrice& operator += (CMatrice& matrice);

    /**
     * \overload operator - (Cmatrice<T> & matrice)
     * @param {CMatrice<T> &}
     * @return {CMatrice<T> &}
     */
    CMatrice &operator-(CMatrice &matrice);

    /**
     * \overload operator -= (Cmatrice<T> & matrice)
     * @param {CMatrice<T> &}
     * @return {CMatrice<T> &}
     */
    CMatrice& operator -= (CMatrice& matrice);

    /**
     * \overload operator * (Cmatrice<T> & matrice)
     * @param {CMatrice<T> &}
     * @return {CMatrice<T> &}
     */
    CMatrice &operator*(CMatrice &matrice);

    /**
     * \overload operator *= (Cmatrice<T> & matrice)
     * @param {CMatrice<T> &}
     * @return {CMatrice<T> &}
     */
    CMatrice& operator *= (CMatrice& matrice);


    /**
     * \fn CMatrice<T> & oTranspose()
     * @return {CMatrice<T> &}
     */
    CMatrice &oTranspose();

    /**
     * @fn CMatrice#MATInverse
     * @return {CMatrice<T> &} - The resulting inverted CMatrice.
     * @desc Uses {@link CMatriceGaussJordan} to invert a CMatrice.
     * Number of lines must be equals to the number of columns.
     */
    CMatrice &MATInverse();

};

#include "CMatrice.cpp"

#endif //MATRICES_CMATRICE_H
