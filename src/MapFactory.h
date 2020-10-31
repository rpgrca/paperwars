#ifndef _MAPFACTORY_H_INCLUDED
#define _MAPFACTORY_H_INCLUDED 0xBEBACAFE

#include "Map.h"

class CMapFactory {
    public:
        CMap *Create() {
            return (new CMap);
        }
};

#endif // _MAPFACTORY_H_INCLUDED
