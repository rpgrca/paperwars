#ifndef _WEAPONSWORD_H_INCLUDED
#define _WEAPONSWORD_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"

class CWeaponSword : public CWeapon {
    public:
        CWeaponSword() {
            m_eWeaponType = enWEAPONTYPE_SWORD;
        }
};

#endif // _WEAPONSWORD_H_INCLUDED
