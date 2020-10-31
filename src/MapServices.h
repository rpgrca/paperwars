#ifndef _MAPSERVICES_H_INCLUDED
#define _MAPSERVICES_H_INCLUDED 0xBEBACAFE

#include "Map.h"
#include "Position.h"

class CMapServices {
    public:
        bool AddPosition(CMap *pMap, CPosition *pPosition) {
            bool bResult = false;

            if ((pMap != NULL) && (pPosition != NULL)) {
                bResult = pMap->GetPositions()->Add(pPosition);
            }

            return (bResult);
        }

        bool RemovePosition(CMap *pMap, CPosition *pPosition) {
            bool bResult = false;

            if ((pMap != NULL) && (pPosition != NULL)) {
                bResult = pMap->GetPositions()->Remove(pPosition);
            }

            return (bResult);
        }

        CPosition *FindPosition(CMap *pMap, long lID) {
            CPosition *pPosition = NULL;

            if ((pMap != NULL) && (lID > 0)) {
                pPosition = pMap->GetPositions()->Find(lID);
            }

            return (pPosition);
        }

        bool MoveEast(CMap *pMap, CPosition *pPosition) {
            bool bResult = false;

            if ((pMap != NULL) && (pPosition != NULL)) {
                if (pPosition->GetPositionX() + 1 < pMap->GetWidth()) {
                    pPosition->SetPositionX(pPosition->GetPositionX() + 1);
                    bResult = true;
                }
            }

            return (bResult);
        }

        bool MoveWest(CMap *pMap, CPosition *pPosition) {
            bool bResult = false;

            if ((pMap != NULL) && (pPosition != NULL)) {
                if (pPosition->GetPositionX() - 1 >= 0) {
                    pPosition->SetPositionX(pPosition->GetPositionX() - 1);
                    bResult = true;
                }
            }

            return (bResult);
        }

        bool MoveNorth(CMap *pMap, CPosition *pPosition) {
            bool bResult = false;

            if ((pMap != NULL) && (pPosition != NULL)) {
                if (pPosition->GetPositionY() - 1 >= 0) {
                    pPosition->SetPositionY(pPosition->GetPositionY() - 1);
                    bResult = true;
                }
            }

            return (bResult);
        }

        bool MoveSouth(CMap *pMap, CPosition *pPosition) {
            bool bResult = false;

            if ((pMap != NULL) && (pPosition != NULL)) {
                if (pPosition->GetPositionY() + 1 < pMap->GetHeight()) {
                    pPosition->SetPositionY(pPosition->GetPositionY() + 1);
                    bResult = true;
                }
            }

            return (bResult);
        }
};




#endif // _MAPSERVICES_H_INCLUDED
