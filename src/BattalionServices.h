#ifndef _BATTALIONSERVICES_H_INCLUDED
#define _BATTALIONSERVICES_H_INCLUDED 0xBEBACAFE

#include "Battalion.h"
#include "Battalions.h"

class CBattalionServices {
    private:
        CBattalions m_pSelectedBattalions;

    public:
       ~CBattalionServices() {
            m_pSelectedBattalions.Clear();
        }

      /*bool FightRound(CBattalion *pFirstBattalion, CBattalion *pSecondBattalion);*/
/*
        bool ModifyExperience(CBattalion *pBattalion, const long lExperience) {
            bool bResult = false;

            if (pBattalion != NULL) {
                pBattalion->SetExperience(pBattalion->GetExperience() + lExperience);
                while (pBattalion->GetExperience() > (10 * pBattalion->GetLevel() * pBattalion->GetLevel())) {
                    pBattalion->SetLevel(pBattalion->GetLevel() + 1);
                    bResult = true;
                }
            }

            return (bResult);
        }

        long CalculateAttack(const CBattalion *pAttacker, const CBattalion *pDefender) {
            long lResult = 0;

            if ((pAttacker != NULL) && (pDefender != NULL)) {
                lResult = (pAttacker->GetAttack() - pDefender->GetDefense()) + 1;
                if (lResult < 1)
                    lResult = 1;
            }

            return (lResult);
        }

        bool IsAlive(const CBattalion *pBattalion) const {
            bool bResult = false;

            if (pBattalion != NULL)
                if (pBattalion->GetHealth() > 0)
                    bResult = true;

            return (bResult);
        }

        bool Hurt(CBattalion *pBattalion, const long lDamage) {
            bool bResult = false;

            if (pBattalion != NULL)
                if (IsAlive(pBattalion))
                    pBattalion->SetHealth(pBattalion->GetHealth() - lDamage);

            return (bResult);
        }

        bool Heal(CBattalion *pBattalion, const long lHealth) {
            bool bResult = false;

            if (pBattalion != NULL) {
                if (IsAlive(pBattalion)) {
                    pBattalion->SetHealth(pBattalion->GetHealth() + lHealth);
                    if (pBattalion->GetHealth() > pBattalion->GetMaximumHealth()) {
                        pBattalion->SetHealth(pBattalion->GetMaximumHealth());
                    }

                    bResult = true;
                }
            }

            return (bResult);
        }

        bool Kill(CBattalion *pBattalion) {
            bool bResult = false;

            if (pBattalion != NULL) {
                pBattalion->SetHealth(-1);
                bResult = true;
            }

            return (bResult);
        }

        bool Revive(CBattalion *pBattalion) {
            bool bResult = false;

            
            if (pBattalion != NULL) {
                if (! IsAlive(pBattalion)) {
                    pBattalion->SetHealth(1);
                    bResult = true;
                }
            }

            return (bResult);
        }

        bool Select(CBattalion *pBattalion) {
            return (m_pSelectedBattalions.Add(pBattalion));
        }

        bool Unselect(CBattalion *pBattalion) {
            return (m_pSelectedBattalions.Remove(pBattalion));
        }

        bool IsSelected(CBattalion *pBattalion) {
            return (m_pSelectedBattalions.Find(pBattalion->GetID()) != NULL);
        }

        CBattalions *GetSelectedBattalions() {
            return (&m_pSelectedBattalions);
        }
*/
};

#endif // _BATTALIONSERVICES_H_INCLUDED
