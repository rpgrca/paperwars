#ifndef _WEAPONHALBERD_H_INCLUDED
#define _WEAPONHALBERD_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"

class CWeaponHalberd : public CWeapon {
    public:
        CWeaponHalberd() {
            m_eWeaponType = enWEAPONTYPE_HALBERD;
        }
};

#endif // _WEAPONHALBERD_H_INCLUDED
