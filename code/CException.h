#ifndef MATRICES_CEXCEPTION_H
#define MATRICES_CEXCEPTION_H

#include <stdio.h>

class CException {
private:
    const char *pcEXCMsg;
public:
    CException() throw();

    CException(const char *pcMsg) throw();

    ~CException();

    virtual const char *what() const throw();
};

#include "CException.cpp"

#endif //MATRICES_CEXCEPTION_H
