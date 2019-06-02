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

#endif //MATRICES_CEXCEPTION_H
