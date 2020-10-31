#ifndef _POSITIONMANAGER_H_INCLUDED
#define _POSITIONMANAGER_H_INCLUDED 0xBEBACAFE

#include "PositionFactory.h"
#include "Positions.h"
#include "Position.h"

class CPositionManager {
    private:
        CPositions m_pPositions;

    public:
       ~CPositionManager() {
            m_pPositions.Purge();
        }

        CPosition *Create(long lPositionX = -1, long lPositionY = -1, long lLevel = -1, CObject *pObject = NULL) {
            CPosition *pPosition = NULL;
            CPositionFactory *pPositionFactory = NULL;

            pPositionFactory = new CPositionFactory;
            pPosition = pPositionFactory->Create();
            delete pPositionFactory;

            if (lPositionX != -1)
                pPosition->SetPositionX(lPositionX);

            if (lPositionY != -1)
                pPosition->SetPositionY(lPositionY);

            if (lLevel != -1)
                pPosition->SetLevel(lLevel);

            if (pObject != NULL)
                pPosition->SetObject(pObject);

            m_pPositions.Add(pPosition);
            return (pPosition);
        }

        bool Delete(CPosition *pPosition) {
            bool bResult = false;

            if (m_pPositions.Remove(pPosition)) {
                delete pPosition;
                pPosition = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CPosition *Find(long lID) {
            return (m_pPositions.Find(lID));
        }
};

#endif // _POSITIONMANAGER_H_INCLUDED
