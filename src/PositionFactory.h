#ifndef _POSITIONFACTORY_H_INCLUDED
#define _POSITIONFACTORY_H_INCLUDED 0xBEBACAFE

#include "Position.h"

class CPositionFactory {
    public:
        CPosition *Create() {
            return (new CPosition);
        }
};

#endif // _POSITIONFACTORY_H_INCLUDED
