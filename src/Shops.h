#ifndef _SHOPS_H_INCLUDED
#define _SHOPS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Shop.h"

class CShops {
    private:
        std::vector<CShop *> m_pShops;

    public:
       ~CShops() {
            Clear();
        }

        bool Add(CShop *pShop) {
            bool bResult = false;

            if (pShop != NULL) {
                if (Find(pShop->GetID()) == NULL) {
                    m_pShops.push_back(pShop);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CShop *pShop = NULL;
            std::vector<CShop *>::iterator pIterator;

            for (pIterator = m_pShops.begin(); pIterator != m_pShops.end(); ++pIterator) {
                pShop = (*pIterator);
                delete pShop;
            }

            m_pShops.clear();
        }

        void Clear() {
            m_pShops.clear();
        }

        CShop *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pShops.size())
                return (m_pShops.at(lIndex));
            else
                return (NULL);
        }

        CShop *Find(const long lID) {
            CShop *pShop = NULL;
            std::vector<CShop *>::iterator pIterator;

            for (pIterator = m_pShops.begin(); pIterator != m_pShops.end(); ++pIterator) {
                pShop = (*pIterator);
                if (pShop->GetID() == lID) {
                    return (pShop);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pShops.size());
        }

        bool Remove(CShop *pShop) {
            CShop *pShopToFind = NULL;
            std::vector<CShop *>::iterator pIterator;
            bool bResult = false;

            if (pShop != NULL) {
                for (pIterator = m_pShops.begin(); pIterator != m_pShops.end(); ++pIterator) {
                    pShopToFind = (*pIterator);
                    if (pShopToFind->GetID() == pShop->GetID()) {
                        m_pShops.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _SHOPS_H_INCLUDED
