#ifndef MEGACHAT_SERVER_CLIARGEXCEPTION_H
#define MEGACHAT_SERVER_CLIARGEXCEPTION_H

#include <exceptions/exception.h>
#include <string>

class CliArgException : public Exception {
public:
    CliArgException(std::string reason) : Exception(reason) {}
};

#endif //MEGACHAT_SERVER_CLIARGEXCEPTION_H
