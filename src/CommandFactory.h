#ifndef _COMMANDFACTORY_H_INCLUDED
#define _COMMANDFACTORY_H_INCLUDED 0xBEBACAFE

#include "Command.h"
#include "CommandType.h"

class CCommandFactory {
    public:
        CCommand *Create(const enCommandFactory eCommandFactory) {
            return (NULL);
        }
};

#endif // _COMMANDFACTORY_H_INCLUDED
