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
     * \brief {unsigned int} iMACNbLignes
     */
    unsigned int iMACNbLignes;

    /**
     * \brief {unsigned int} iMACNbColonnes
     */
    unsigned int iMACNbColonnes;

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
    virtual void setValeurs_(T **ppValeurs, unsigned int iNbLignes, unsigned int iNbColonnes);

public:
    /**
     * \fn void setValeur(T valeur, unsigned int iPositionLigne, unsigned int iPositionColonne)
     * \param {T} valeur
     * \param {unsigned int} iPositionLigne
     * \param {unsigned int} iPositionColonne
     */
    virtual void setValeur(T valeur, unsigned int iPositionLigne, unsigned int iPositionColonne);

    /**
     * \fn unsigned int getNbLignes()
     * \return {unsigned int}
     */
    virtual unsigned int getNbLignes() const;

    /**
     * \fn unsigned int getNbColonnes()
     * \return {unsigned int}
     */
    virtual unsigned int getNbColonnes() const;

    /**
     * \fn T** getValeurs()
     * \brief Returns all values.
     * @return {T**}
     */
    virtual T ** getValeurs() const;

    /**
     * \fn T getValeur(unsigned int iPositionLigne, unsigned int iPositionColonne)
     * \param {unsigned int} iPositionLigne
     * \param {unsigned int} iPositionColonne
     * \brief Returns the value at the position defined in parameters
     * \return {T}
     */
    virtual T getValeur(unsigned int iPositionLigne, unsigned int iPositionColonne) const;

    void MACAfficher();
};

#include "CMatriceCore.cpp"

#endif //MATRICES_CMATRICECORE_H
