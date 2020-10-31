#ifndef _WEAPONBOW_H_INCLUDED
#define _WEAPONBOW_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"

class CWeaponBow : public CWeapon {
    public:
        CWeaponBow() {
            m_eWeaponType = enWEAPONTYPE_BOW;
        }
};

#endif // _WEAPONBOW_H_INCLUDED
