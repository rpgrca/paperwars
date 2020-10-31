#ifndef _WEAPONAXE_H_INCLUDED
#define _WEAPONAXE_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"

class CWeaponAxe : public CWeapon {
    public:
        CWeaponAxe() {
            m_eWeaponType = enWEAPONTYPE_AXE;
        }
};

#endif // _WEAPONAXE_H_INCLUDED
