#ifndef _SHOPMANAGER_H_INCLUDED
#define _SHOPMANAGER_H_INCLUDED 0xBEBACAFE

#include <string>
#include "ShopFactory.h"
#include "Shops.h"
#include "Shop.h"

class CShopManager {
    private:
        CShops m_pShops;

    public:
       ~CShopManager() {
            m_pShops.Purge();
        }

        CShop *Create() {
            CShop *pShop = NULL;
            CShopFactory *pShopFactory = NULL;

            pShopFactory = new CShopFactory;
            pShop = pShopFactory->Create();
            delete pShopFactory;

            m_pShops.Add(pShop);
            return (pShop);
        }

        bool Delete(CShop *pShop) {
            bool bResult = false;

            if (m_pShops.Remove(pShop)) {
                delete pShop;
                pShop = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CShop *Find(long lID) {
            return (m_pShops.Find(lID));
        }
};

#endif // _SHOPMANAGER_H_INCLUDED
