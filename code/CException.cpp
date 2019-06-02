CException::CException() throw() {
    pcEXCMsg = "ERROR\n";
}

CException::CException(const char *pcMsg) throw() {
    pcEXCMsg = pcMsg;
    fprintf(stderr, "%s\n", pcEXCMsg);
}

CException::~CException() {
    delete (pcEXCMsg);
}

const char *CException::what() const {
    return pcEXCMsg;
}

