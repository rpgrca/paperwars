#ifndef _SOLDIERSERVICES_H_INCLUDED
#define _SOLDIERSERVICES_H_INCLUDED 0xBEBACAFE

#include "Soldier.h"
#include "Soldiers.h"
#include "Weapon.h"
#include "Armour.h"
#include "WeaponType.h"
#include "ArmourType.h"

class CSoldierServices {
    private:
        CSoldiers m_pSelectedSoldiers;

    public:
       ~CSoldierServices() {
            m_pSelectedSoldiers.Clear();
        }

      /*bool FightRound(CSoldier *pFirstSoldier, CSoldier *pSecondSoldier);*/
        bool ModifyExperience(CSoldier *pSoldier, const long lExperience) {
            bool bResult = false;

            if (pSoldier != NULL) {
                pSoldier->SetExperience(pSoldier->GetExperience() + lExperience);
                while (pSoldier->GetExperience() > (10 * pSoldier->GetLevel() * pSoldier->GetLevel())) {
                    pSoldier->SetLevel(pSoldier->GetLevel() + 1);
                    bResult = true;
                }
            }

            return (bResult);
        }

        bool CanHeal(const CSoldier *pHealer) {
            bool bResult = false;

            if (pHealer != NULL)
                if (pHealer->GetType() == enSOLDIERTYPE_CLERIC)
                    bResult = true;

            return (bResult);
        }

        long CalculateAttack(const CSoldier *pAttacker, const CSoldier *pDefender) {
            long lResult = 0;

            if ((pAttacker != NULL) && (pDefender != NULL)) {
                lResult = (pAttacker->GetModifiedAttack() - pDefender->GetModifiedDefense()) + 1;
                if (lResult < 1)
                    lResult = 1;
            }

            return (lResult);
        }

        bool IsAlive(const CSoldier *pSoldier) const {
            bool bResult = false;

            if (pSoldier != NULL)
                if (pSoldier->GetHealth() > 0)
                    bResult = true;

            return (bResult);
        }

        bool Hurt(CSoldier *pSoldier, const long lDamage) {
            bool bResult = false;

            if (pSoldier != NULL)
                if (IsAlive(pSoldier))
                    pSoldier->SetHealth(pSoldier->GetHealth() - lDamage);

            return (bResult);
        }

        bool Heal(CSoldier *pSoldier, const long lHealth) {
            bool bResult = false;

            if (pSoldier != NULL) {
                if (IsAlive(pSoldier)) {
                    pSoldier->SetHealth(pSoldier->GetHealth() + lHealth);
                    if (pSoldier->GetHealth() > pSoldier->GetMaximumHealth()) {
                        pSoldier->SetHealth(pSoldier->GetMaximumHealth());
                    }

                    bResult = true;
                }
            }

            return (bResult);
        }

        bool Kill(CSoldier *pSoldier) {
            bool bResult = false;

            if (pSoldier != NULL) {
                pSoldier->SetHealth(-1);
                bResult = true;
            }

            return (bResult);
        }

        bool Revive(CSoldier *pSoldier) {
            bool bResult = false;

            if (pSoldier != NULL) {
                if (! IsAlive(pSoldier)) {
                    pSoldier->SetHealth(1);
                    bResult = true;
                }
            }

            return (bResult);
        }

        bool Select(CSoldier *pSoldier) {
            return (m_pSelectedSoldiers.Add(pSoldier));
        }

        bool Unselect(CSoldier *pSoldier) {
            return (m_pSelectedSoldiers.Remove(pSoldier));
        }

        bool IsSelected(CSoldier *pSoldier) {
            return (m_pSelectedSoldiers.Find(pSoldier->GetID()) != NULL);
        }

        CSoldiers *GetSelectedSoldiers() {
            return (&m_pSelectedSoldiers);
        }

        bool EquipArmour(CSoldier *pSoldier, CArmour *pArmour) {
            bool bResult = false;

            if ((pSoldier != NULL) && (pArmour != NULL)) {
                if (pSoldier->GetArmours()->Find(pArmour->GetType()) == NULL) {
                    pSoldier->GetArmours()->Add(pArmour);
                    bResult = true;
                }
            }

            return (bResult);
        }

        bool EquipWeapon(CSoldier *pSoldier, CWeapon *pWeapon) {
            bool bResult = false;

            if ((pSoldier != NULL) && (pWeapon != NULL)) {
                if (pSoldier->GetWeapons()->GetCount() == 0) {
                    pSoldier->GetWeapons()->Add(pWeapon);
                    bResult = true;
                }
            }

            return (bResult);
        }

        bool IsEquipped(CSoldier *pSoldier, CArmour *pArmour) {
            bool bResult = false;

            if ((pSoldier != NULL) && (pArmour != NULL))
                bResult = (pSoldier->GetArmours()->Find(pArmour->GetID()));

            return (bResult);
        }

        bool IsEquipped(CSoldier *pSoldier, CWeapon *pWeapon) {
            bool bResult = false;

            if ((pSoldier != NULL) && (pWeapon != NULL))
                bResult = (pSoldier->GetWeapons()->Find(pWeapon->GetID()));

            return (bResult);
        }
};

#endif // _SOLDIERSERVICES_H_INCLUDED
