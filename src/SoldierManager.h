#ifndef _SOLDIERMANAGER_H_INCLUDED
#define _SOLDIERMANAGER_H_INCLUDED 0xBEBACAFE

#include <string>
#include "SoldierFactory.h"
#include "Soldiers.h"
#include "Soldier.h"
#include "SoldierType.h"

class CSoldierManager {
    private:
        CSoldiers m_pSoldiers;

    public:
       ~CSoldierManager() {
            m_pSoldiers.Purge();
        }

        CSoldier *Create(const enSoldierType eSoldierType = enSOLDIERTYPE_UNKNOWN, const std::string szName = "", const long lHealth = -1, const long lMaximumHealth = -1, const long lAttack = -1, const long lMaximumAttack = -1, const long lDefense = -1, const long lMaximumDefense = -1, const long lLevel = -1, const long lExperience = -1, const long lSpeed = -1, const long lRange = -1) {
            CSoldier *pSoldier = NULL;
            CSoldierFactory *pSoldierFactory = NULL;

            pSoldierFactory = new CSoldierFactory;
            pSoldier = pSoldierFactory->Create(eSoldierType);

            if (szName != "")
                pSoldier->SetName(szName);

            if (lHealth != -1)
                pSoldier->SetHealth(lHealth);

            if (lMaximumHealth != -1)
                pSoldier->SetMaximumHealth(lMaximumHealth);

            if (lAttack != -1)
                pSoldier->SetAttack(lAttack);

            if (lMaximumAttack != -1)
                pSoldier->SetMaximumAttack(lMaximumAttack);

            if (lDefense != -1)
                pSoldier->SetDefense(lDefense);

            if (lMaximumDefense != -1)
                pSoldier->SetMaximumDefense(lMaximumDefense);

            if (lLevel != -1)
                pSoldier->SetLevel(lLevel);

            if (lExperience != -1)
                pSoldier->SetExperience(lExperience);

            if (lSpeed != -1)
                pSoldier->SetSpeed(lSpeed);

            if (lRange != -1)
                pSoldier->SetRange(lRange);

            delete pSoldierFactory;

            m_pSoldiers.Add(pSoldier);
            return (pSoldier);
        }

        bool Delete(CSoldier *pSoldier) {
            bool bResult = false;

            if (m_pSoldiers.Remove(pSoldier)) {
                delete pSoldier;
                pSoldier = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CSoldier *Find(const long lID) {
            return (m_pSoldiers.Find(lID));
        }

        void Update(CSoldier *pSoldier) {
            m_pSoldiers.UpdateElement(pSoldier);
        }
};

#endif // _SOLDIERMANAGER_H_INCLUDED
