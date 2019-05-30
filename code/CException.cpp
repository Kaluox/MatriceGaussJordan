//#include "CException.h"

//#include "CException.h"

CException::CException() throw() {
    pcEXCMsg = "ERROR\n";
}

CException::CException(const char *pcMsg) throw() {
    pcEXCMsg = pcMsg;
    std::cerr << pcEXCMsg << "\n";
}

CException::~CException() {
    delete (pcEXCMsg);
}

const char *CException::what() const {
    return pcEXCMsg;
}

