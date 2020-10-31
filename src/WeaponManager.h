#ifndef _WEAPONMANAGER_H_INCLUDED
#define _WEAPONMANAGER_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"
#include "WeaponFactory.h"

class CWeaponManager {
    private:
        CWeapons m_pWeapons;

    public:
       ~CWeaponManager() {
            m_pWeapons.Purge();
        }

        CWeapon *Create(const enWeaponType eWeaponType, const long lToHitModifier = 0, const long lDamageModifier = 0) {
            CWeaponFactory *pWeaponFactory = NULL;
            CWeapon *pWeapon = NULL;

            if (eWeaponType != enWEAPONTYPE_NONE) {
                pWeaponFactory = new CWeaponFactory;
                pWeapon = pWeaponFactory->Create(eWeaponType);
                delete pWeaponFactory;

                if (lToHitModifier != 0)
                    pWeapon->SetToHitModifier(lToHitModifier);

                if (lDamageModifier != 0)
                    pWeapon->SetDamageModifier(lDamageModifier);

                m_pWeapons.Add(pWeapon);
            }

            return (pWeapon);
        }
};

#endif // _WEAPONMANAGER_H_INCLUDED
