#ifndef _WEAPONKNIFE_H_INCLUDED
#define _WEAPONKNIFE_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"

class CWeaponKnife : public CWeapon {
    public:
        CWeaponKnife() {
            m_eWeaponType = enWEAPONTYPE_KNIFE;
        }
};

#endif // _WEAPONKNIFE_H_INCLUDED
