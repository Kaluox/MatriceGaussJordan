#include "../../code/CMatrice.h"


#define TEST_DOUBLE 1
#define TEST_INT 0
#define TEST_SHORT 0
#define TEST_LONG 0
#define TEST_FLOAT 0
#define TEST_CHAR 0

template<typename T>
bool testInverseGJ() {
    bool bTestPassed = true;
    CMatrice<T> matriceTest("1 0 0:0 1 0:0 0 1", " ", ":");
    CMatrice<T> matriceTestInverseExpected("1 0 0:0 1 0:0 0 1", " ", ":");
    bTestPassed &= ((matriceTest.MATInverse()) == (matriceTestInverseExpected));

    matriceTest("1 0 0:1 2 1:0 0 1", " ", ":");
    matriceTestInverseExpected("1 0 0:-0.5 0.5 -0.5:0 0 1", " ", ":");
    bTestPassed &= ((matriceTest.MATInverse()) == (matriceTestInverseExpected));
    return bTestPassed;
}

/**
 * @fn testThemAll<T>()
 * @brief Realise tous les test avec le type <T> specifie.
 * @tparam {T}
 * @return {bool}
 */
template<typename T>
bool testThemAll() {
    printf("launching tests...\n");
    bool bTestPassed = true;
    bTestPassed &= testInverseGJ<T>();
    printf("\ttestInverseGJ [%s]\n", ((bTestPassed) ? "OKAY" : "FAIL"));
    printf("tests [%s]\n", ((bTestPassed) ? "PASSED" : "FAIL"));
    return bTestPassed;
}


int main(int argc, const char *argv[]) {
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