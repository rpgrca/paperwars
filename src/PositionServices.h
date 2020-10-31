#ifndef _POSITIONSERVICES_H_INCLUDED
#define _POSITIONSERVICES_H_INCLUDED 0xBEBACAFE

#include "Soldier.h"

class CPositionServices {
    public:
        bool IsWithinRange(CPosition *pFirstPosition, CPosition *pSecondPosition, long lRange) {
            bool bResult = false;

            if ((pFirstPosition != NULL) && (pSecondPosition)) {
                if (pFirstPosition->GetPositionX() - lRange <= pSecondPosition->GetPositionX() &&
                    pFirstPosition->GetPositionX() + lRange >= pSecondPosition->GetPositionX() &&
                    pFirstPosition->GetPositionY() - lRange <= pSecondPosition->GetPositionY() &&
                    pFirstPosition->GetPositionY() + lRange >= pSecondPosition->GetPositionY()) {
                    bResult = true;
                }
            }

            return (bResult);
        }

        CSoldier *GetSoldier(CPosition *pPosition) {
            return (dynamic_cast<CSoldier *>(pPosition->GetObject()));
        }
};

#endif // _POSITIONSERVICES_H_INCLUDED
