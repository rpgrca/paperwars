#ifndef _BATTALIONFACTORY_H_INCLUDED
#define _BATTALIONFACTORY_H_INCLUDED 0xBEBACAFE

#include "Battalion.h"

class CBattalionFactory {
    public:
        CBattalion *Create() {
            return (new CBattalion);
        }
};

#endif // _BATTALIONFACTORY_H_INCLUDED
