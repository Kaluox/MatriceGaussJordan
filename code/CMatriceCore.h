#ifndef MATRICES_CMATRICECORE_H
#define MATRICES_CMATRICECORE_H

#include "CException.h"

/**
 * \class CMatriceCore
 */
template<class T> class CMatriceCore {
    //attributs
private:
    /**
     * \brief {int} iMACNbLignes
     */
    int iMACNbLignes;

    /**
     * \brief {int} iMACNbColonnes
     */
    int iMACNbColonnes;

    /**
     * \brief {T**} ppMACValeurs
     */
    T ** ppMACValeurs;

    //methodes
protected:
    /**
     *\brief Default Constructor
     */
    CMatriceCore();

    /**
     * \brief Copy Constructor
     * \param {CMatriceCore} matriceCore
     */
    CMatriceCore(const CMatriceCore<T> & matriceCore);

    /**
     * \brief Destructor
     */
    ~CMatriceCore();

    /**
     * \fn void setValeurs(T ** ppValeurs)
     * \param {T **} ppValeurs
     */
    virtual void setValeurs_(T ** ppValeurs, int iNbLignes, int iNbColonnes);

public:
    /**
     * \overload operator << (std::ostream & strm) const
     * \return {std::ostream&}
     */
    std::ostream& operator<<(std::ostream &strm) const;

    /**
     * \fn void setValeur(T valeur, int iPositionLigne, int iPositionColonne)
     * \param {T} valeur
     * \param {int} iPositionLigne
     * \param {int} iPositionColonne
     */
    virtual void setValeur(T valeur, int iPositionLigne, int iPositionColonne);

    /**
     * \fn int getNbLignes()
     * \return {int}
     */
    virtual int getNbLignes() const;

    /**
     * \fn int getNbColonnes()
     * \return {int}
     */
    virtual int getNbColonnes() const;

    /**
     * \fn T** getValeurs()
     * \brief Returns all values.
     * @return {T**}
     */
    virtual T ** getValeurs() const;

    /**
     * \fn T getValeur(int iPositionLigne, int iPositionColonne)
     * \param {int} iPositionLigne
     * \param {int} iPositionColonne
     * \brief Returns the value at the position defined in parameters
     * \return {T}
     */
    virtual T getValeur(int iPositionLigne, int iPositionColonne) const;
};

#include "CMatriceCore.cpp"

#endif //MATRICES_CMATRICECORE_H
