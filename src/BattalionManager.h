#ifndef _BATTALIONMANAGER_H_INCLUDED
#define _BATTALIONMANAGER_H_INCLUDED 0xBEBACAFE

#include "BattalionFactory.h"
#include "Battalions.h"
#include "Battalion.h"

class CBattalionManager {
    private:
        CBattalions m_pBattalions;

    public:
       ~CBattalionManager() {
            m_pBattalions.Purge();
        }

        CBattalion *Create() {
            CBattalion *pBattalion = NULL;
            CBattalionFactory *pBattalionFactory = NULL;

            pBattalionFactory = new CBattalionFactory;
            pBattalion = pBattalionFactory->Create();
            delete pBattalionFactory;

            m_pBattalions.Add(pBattalion);
            return (pBattalion);
        }

        bool Delete(CBattalion *pBattalion) {
            bool bResult = false;

            if (m_pBattalions.Remove(pBattalion)) {
                delete pBattalion;
                pBattalion = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CBattalion *Find(long lID) {
            return (m_pBattalions.Find(lID));
        }
};

#endif // _BATTALIONMANAGER_H_INCLUDED
