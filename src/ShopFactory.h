#ifndef _SHOPFACTORY_H_INCLUDED
#define _SHOPFACTORY_H_INCLUDED 0xBEBACAFE

#include "Shop.h"

class CShopFactory {
    public:
        CShop *Create() {
            return (new CShop);
        }
};

#endif // _SHOPFACTORY_H_INCLUDED
