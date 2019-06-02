#include <iostream>
#include <string>
#include "../../code/CMatriceCore.h"
#include "../../code/CMatrice.h"
#include "../../code/CMatriceGaussJordan.h"


#define TEST_DOUBLE 1
#define TEST_INT 1
#define TEST_SHORT 1
#define TEST_LONG 1
#define TEST_FLOAT 1
#define TEST_CHAR 1


/**
 * @fn testCreate<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnels les codes suivants:
 * <pre>{@code
 * CMatrice<T>* matrice = new CMatrice<T>();
 * }</pre>
 * et
 * <pre>{@code
 * CMatrice<T>* matrice = new CMatrice<T>("string of matrice values", "delimitator for values", "delimitator for lines");
 * }</pre>
 * et
 * <pre>{@code
 * CMatrice<T>* matrice = new CMatrice<T>("chemin/fichier/matrice.txt");
 * }</pre>
 * et que peut importe la façon de realiser de creer un object de type {CMatrice<T>} l'object sera bien cree.
 *
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testCreate() {
    bool bTestPassed = true;

    //check for null
    CMatrice<T>* tmp = new CMatrice<T>();
    bTestPassed &= (tmp != nullptr);
    bTestPassed &= (tmp->getNbLignes() == 0);
    bTestPassed &= (tmp->getNbColonnes() == 0);
    bTestPassed &= (tmp->getValeurs() == nullptr);
    delete(tmp);


    CMatrice<T> *tmp2 = new CMatrice<T>("0 1 2_3 4 5", " ", "_");
    bTestPassed &= (tmp2 != nullptr);
    bTestPassed &= (tmp2->getNbLignes() == 2);
    bTestPassed &= (tmp2->getNbColonnes() == 3);
    bTestPassed &= (tmp2->getValeurs() != nullptr);
    bTestPassed &= (tmp2->getValeur(0,0) == 0);
    bTestPassed &= (tmp2->getValeur(0,1) == 1);
    bTestPassed &= (tmp2->getValeur(1,2) == 5);
    delete(tmp2);


    CMatrice<T> tmp3("0 1:2 3", " ", ":");
    bTestPassed &= (&tmp3 != nullptr);
    bTestPassed &= (tmp3.getNbLignes() == 2);
    bTestPassed &= (tmp3.getNbColonnes() == 2);
    bTestPassed &= (tmp3.getValeurs() != nullptr);
    bTestPassed &= (tmp3.getValeur(0, 0) == 0);
    bTestPassed &= (tmp3.getValeur(0, 1) == 1);
    bTestPassed &= (tmp3.getValeur(1, 1) == 3);

    if ((std::string) (typeid(T).name()) == "double") {
        try {
            std::ofstream outputFile("test.txt");
            outputFile << "TypeMatrice=double\n"
                          "NBLignes=2\n"
                          "NBColonnes=3\n"
                          "Matrice=[\n"
                          "5 3 6\n"
                          "1 -2 8\n"
                          "]";
            outputFile.close();
            CMatrice<T> *tmp4 = new CMatrice<T>("test.txt");
            remove("test.txt");
            CMatrice<T> *tmp4SupposedMatrice = new CMatrice<T>("5 3 6:1 -2 8", " ", ":");
            bTestPassed &= (tmp4 != nullptr);
            bTestPassed &= (*tmp4 == *tmp4SupposedMatrice);
            delete (tmp4SupposedMatrice);
            delete (tmp4);
        } catch (CException const &exception) {
            std::cerr << exception.what() << "\n";
            bTestPassed &= false;
        }
    }

    CMatrice<T> *tmp5 = new CMatrice<T>(4, 5);
    bTestPassed &= (tmp5 != nullptr);
    bTestPassed &= (tmp5->getNbLignes() == 4);
    bTestPassed &= (tmp5->getNbColonnes() == 5);
    bTestPassed &= (tmp5->getValeurs() != nullptr);
    bTestPassed &= (tmp5->getValeur(0, 0) == 0);
    bTestPassed &= (tmp5->getValeur(0, 1) == 0);
    bTestPassed &= (tmp5->getValeur(3, 4) == 0);

    return bTestPassed;
}

/**
 * @fn testDestroy<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnel le code suivant:
 * <pre>{@code
 * CMatrice<T>* matrice;
 * ...
 * delete(matrice);
 * }</pre>
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testDestroy() {
    bool bTestPassed = true;

    CMatrice<T>* tmp = new CMatrice<T>();
    delete(tmp);

    return bTestPassed;
}


/**
 * @fn testEquality<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnel le code suivant:
 * <pre>{@code
 * CMatrice<T> matrice;
 * CMatrice<T> matrice2;
 * ...
 * //precondition: matrice et matrice2 ont meme valeurs, nombre de lignes et colonnes.
 * ...
 * (matrice == matrice2) && (matrice2 == matrice)
 * et que peut importe la façon de realiser une egalite entre deux object de type {CMatrice<T>} la même valeur sera retournee.
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testEquality() {
    bool bTestPassed = true;

    CMatrice<T>* tmp = new CMatrice<T>();

    CMatrice<T>* tmp2 = new CMatrice<T>();
    bTestPassed &= (tmp != tmp2);
    bTestPassed &= (*tmp == *tmp2);
    bTestPassed &= !(*tmp != *tmp2);
    delete(tmp2);

    tmp->setValeurs("0 -5 6: -500 1 0");

    CMatrice<T>* tmp3 = new CMatrice<T>(*tmp);
    bTestPassed &= (tmp != tmp3);
    bTestPassed &= (*tmp == *tmp3);
    bTestPassed &= !(*tmp != *tmp3);

    CMatrice<T> *tmp4 = new CMatrice<T>("0 -5 6: -500 1 0", " ", ":");
    bTestPassed &= (tmp != tmp4);
    bTestPassed &= (*tmp == *tmp4);
    bTestPassed &= !(*tmp != *tmp4);

    bTestPassed &= (tmp3 != tmp4);
    bTestPassed &= (*tmp3 == *tmp4);
    bTestPassed &= !(*tmp3 != *tmp4);

    delete (tmp4);
    delete (tmp3);
    delete(tmp);

    return bTestPassed;
}

/**
 * @fn testCopy<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnel le code suivant:
 * <pre>{@code
 * CMatrice<T> matrice;
 * ...
 * CMatrice<T> matrice2(matrice);
 * CMatrice<T> matrice3 = matrice;
 * CMatrice<T>* matrice4 = new CMatrice(matrice);
 * }</pre>
 * et que peut importe la façon de copier un object de type {CMatrice<T>} la copie sera bien realisee.
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testCopy() {
    bool bTestPassed = true;

    CMatrice<T> *tmp = new CMatrice<T>();
    CMatrice<T> *tmpCopy = new CMatrice<T>(*tmp);
    bTestPassed &= (tmpCopy != tmp);
    bTestPassed &= (*tmpCopy == *tmp);
    delete (tmpCopy);
    delete (tmp);

    CMatrice<T> *tmp2 = new CMatrice<T>("0 0:0 0", " ", ":");
    CMatrice<T> *tmp2Copy = new CMatrice<T>(*tmp2);
    bTestPassed &= (tmp2Copy != tmp2);
    bTestPassed &= (*tmp2Copy == *tmp2);
    delete (tmp2Copy);

    CMatrice<T> tmp2Copy2 = *tmp2;
    bTestPassed &= (&tmp2Copy2 != tmp2);
    bTestPassed &= (tmp2Copy2 == *tmp2);
    delete (tmp2);

    CMatrice<T> tmp3("0 0:0 1", " ", ":");
    CMatrice<T> tmp3Copy(tmp3);
    bTestPassed &= (&tmp3 != &tmp3Copy);
    bTestPassed &= (tmp3 == tmp3Copy);
    bTestPassed &= (tmp3.getValeur(0, 0) == tmp3Copy.getValeur(0, 0));

    return bTestPassed;
}


/**
 * @fn testSumLambda<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnel le code suivant:
 * <pre>{@code
 * CMatrice<T> matrice;
 * ...
 * //x de type <T>
 * ...
 * matrice + x;
 * matrice += x;
 * matrice - x;
 * matrice -= x;
 * }</pre>
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testSumLambda() {
    bool bTestPassed = true;

    CMatrice<T>* tmp = new CMatrice<T>("0 1:2 3", " ", ":");
    CMatrice<T>* tmp2 = new CMatrice<T>(*tmp);
    bTestPassed &= ((*tmp2 + 0) == *tmp);
    *tmp += 0;
    bTestPassed &= ((*tmp2) == *tmp);
    bTestPassed &= ((*tmp2 - 0) == *tmp);
    *tmp2 -= 0;
    bTestPassed &= ((*tmp2) == *tmp);
    delete(tmp2);

    CMatrice<T>* tmpMinusOne = new CMatrice<T>("-1 0:1 2", " ", ":");
    bTestPassed &= ((*tmp + (-1)) == *tmpMinusOne);
    bTestPassed &= (*tmpMinusOne == (*tmp + (-1)));
    *tmp += (-1);
    bTestPassed &= (*tmpMinusOne == *tmp);
    *tmp -= (-1);
    bTestPassed &= (*tmpMinusOne == (*tmp - 1));
    delete(tmpMinusOne);
    delete(tmp);

    return bTestPassed;
}


/**
 * @fn testXLambda<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnel le code suivant:
 * <pre>{@code
 * CMatrice<T> matrice;
 * ...
 * //x de type <T>
 * ...
 * matrice * x;
 * matrice *= x;
 * matrice / x;
 * matrice /= x;
 * }</pre>
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testXLambda() {
    bool bTestPassed = true;

    CMatrice<T>* tmp = new CMatrice<T>("0 1:2 3", " ", ":");
    CMatrice<T>* tmpOne = new CMatrice<T>("1 1:1 1", " ", ":");
    bTestPassed &= (((*tmp * 0) + 1) == (*tmpOne));
    bTestPassed &= ((*tmp * 1) == (*tmp));
    bTestPassed &= ((*tmp * 0) == (*tmpOne * 0));
    delete(tmpOne);
    delete(tmp);

    return bTestPassed;
}


/**
 * @fn testTranspose<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnel le code suivant:
 * <pre>{@code
 * CMatrice<T> matrice;
 * ...
 * matrice.transpose();
 * }</pre>
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testTranspose() {
    bool bTestPassed = true;

    CMatrice<T>* tmp = new CMatrice<T>("0 1:2 3", " ", ":");
    CMatrice<T>* tmpTransposeExpected = new CMatrice<T>("0 2:1 3", " ", ":");
    bTestPassed &= ((tmp->oTranspose()) == *tmpTransposeExpected);
    /*
    std::cout << "---------" << "\n";
    std::cout << "tmp:\n" <<*tmp << "\n";
    std::cout << "tmpTransposeExpected:\n" << *tmpTransposeExpected << "\n";
    std::cout << "tmpTranspose:\n" << (tmp->oTranspose()) << "\n";
    std::cout << "---------" << "\n";
    /**/
    delete(tmpTransposeExpected);
    delete(tmp);

    CMatrice<T>* tmp2 = new CMatrice<T>("0 1 2:3 4 5", " ", ":");
    CMatrice<T>* tmp2TransposeExpected = new CMatrice<T>("0 3:1 4:2 5", " ", ":");
    bTestPassed &= ((tmp2->oTranspose()) == *tmp2TransposeExpected);
    delete(tmp2TransposeExpected);
    delete(tmp2);

    return bTestPassed;
}


/**
 * @fn testSumMatrice<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnel le code suivant:
 * <pre>{@code
 * CMatrice<T> matrice;
 * CMatrice<T> matrice2;
 * ...
 * //precondition: matrice et matrice2 ont meme nombre de ligne et de colonnes.
 * ...
 * matrice + matrice2;
 * matrice += matrice2;
 * matrice - matrice2;
 * matrice -= matrice2;
 * }</pre>
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testSumMatrice() {
    bool bTestPassed = true;
    CMatrice<T> *matrice = new CMatrice<T>("0 0:0 0", " ", ":");
    CMatrice<T> *matrice2 = new CMatrice<T>("1 1:1 1", " ", ":");

    bTestPassed &= (*matrice2 == (*matrice + *matrice2));
    bTestPassed &= (*matrice2 == (*matrice2 - *matrice));

    CMatrice<T> matriceCopy(*matrice);
    *matrice += *matrice2;
    bTestPassed &= (*matrice2 == *matrice);
    *matrice -= *matrice2;
    bTestPassed &= (*matrice == matriceCopy);

    delete (matrice2);
    delete (matrice);

    return bTestPassed;
}


/**
 * @fn testSumMatrice<T>()
 * @brief Une fois ce test reussi, on peut considerer comme fonctionnel le code suivant:
 * <pre>{@code
 * CMatrice<T> matrice;
 * CMatrice<T> matrice2;
 * ...
 * //precondition: matrice et matrice2 ont un nombre de ligne et colonne respectivement inverse.
 * ...
 * matrice * matrice2;
 * matrice *= matrice2;
 * }</pre>
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testXMatrices() {
    bool bTestPassed = true;

    CMatrice<T> *tmp = new CMatrice<T>(2, 2);
    bTestPassed &= ((*tmp) == (*tmp * tmp->oTranspose()));

    CMatrice<T> *tmp2 = new CMatrice<T>("1 1 1:1 1 1", " ", ":");
    CMatrice<T> *tmp3 = new CMatrice<T>("0 0:0 0:0 0", " ", ":");
    bTestPassed &= (*tmp == (*tmp2 * *tmp3));

    *tmp2 *= *tmp3;
    bTestPassed &= (*tmp == *tmp2);

    delete(tmp3);
    delete(tmp2);
    delete (tmp);

    return bTestPassed;
}


/**
 *
 */
/*template <typename T>
 bool testInverseGJ() {
     bool bTestPassed = true;
     CMatriceGaussJordan<T> *tmp = new CMatriceGaussJordan<T>("3 0 2:2 0 -2:0 1 1", " ", ":");
     CMatriceGaussJordan<T> *tmp2 = new CMatriceGaussJordan<T>("0.2 0.2 0:-0.2 0.3 1:0.2 -0.3 0", " ", ":");
     bTestPassed &= (*tmp->CMCInverseGJ(*tmp) == *tmp2);

     return bTestPassed;

 }*/


/**
 * @fn testThemAll<T>()
 * @brief Realise tous les test avec le type <T> specifie.
 * @tparam {T}
 * @return {bool}
 */
template <typename T>
bool testThemAll(){
    std::cout << "testing for all tests <" << typeid(T).name() << ">" << std::endl;
    bool bTestPassed = true;

    std::cout << "\t";
    bTestPassed &= testCreate<T>();
    std::cout << "testCreate [" << ((bTestPassed) ? "OKAY" : "FAIL") << "]" << std::endl;

    std::cout << "\t";
    bTestPassed &= testDestroy<T>();
    std::cout << "testDestroy [" << ((bTestPassed) ? "OKAY" : "FAIL") << "]" << std::endl;

    std::cout << "\t";
    bTestPassed &= testEquality<T>();
    std::cout << "testEquality [" << ((bTestPassed)?"OKAY":"FAIL") << "]" << std::endl;

    std::cout << "\t";
    bTestPassed &= testCopy<T>();
    std::cout << "testCopy [" << ((bTestPassed)?"OKAY":"FAIL") << "]" << std::endl;

    std::cout << "\t";
    bTestPassed &= testSumLambda<T>();
    std::cout << "testSumLambda [" << ((bTestPassed)?"OKAY":"FAIL") << "]" << std::endl;

    std::cout << "\t";
    bTestPassed &= testXLambda<T>();
    std::cout << "testXLambda [" << ((bTestPassed)?"OKAY":"FAIL") << "]" << std::endl;

    std::cout << "\t";
    bTestPassed &= testSumMatrice<T>();
    std::cout << "testSumMatrice [" << ((bTestPassed)?"OKAY":"FAIL") << "]" << std::endl;

    std::cout << "\t";
    bTestPassed &= testTranspose<T>();
    std::cout << "testTranspose [" << ((bTestPassed)?"OKAY":"FAIL") << "]" << std::endl;

    std::cout << "\t";
    bTestPassed &= testXMatrices<T>();
    std::cout << "testXMatrices [" << ((bTestPassed)?"OKAY":"FAIL") << "]" << std::endl;

    /*std::cout << "\t";
    bTestPassed &= testInverseGJ<T>();
    std::cout << "testInverseGJ [" << ((bTestPassed)?"OKAY":"FAIL") << "]" << std::endl;*/

    std::cout << "tests [" << ((bTestPassed)?"PASSED":"FAILED") << "]" << std::endl;

    return bTestPassed;
}


int main(int argc, const char* argv[]) {
#if TEST_DOUBLE == 1
    testThemAll<double>();
#endif
#if TEST_FLOAT == 1
    testThemAll<int>();
#endif
#if TEST_LONG == 1
    testThemAll<long>();
#endif
#if TEST_FLOAT == 1
    testThemAll<float>();
#endif
/*#if TEST_CHAR == 1
    testThemAll<char>();
#endif*/
    //system("pause");
    return 0;
}