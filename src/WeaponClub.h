#ifndef _WEAPONCLUB_H_INCLUDED
#define _WEAPONCLUB_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"

class CWeaponClub : public CWeapon {
    public:
        CWeaponClub() {
            m_eWeaponType = enWEAPONTYPE_CLUB;
        }
};

#endif // _WEAPONCLUB_H_INCLUDED
