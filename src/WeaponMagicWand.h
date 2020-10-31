#ifndef _WEAPONMAGICWAND_H_INCLUDED
#define _WEAPONMAGICWAND_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"

class CWeaponMagicWand : public CWeapon {
    public:
        CWeaponMagicWand() {
            m_eWeaponType = enWEAPONTYPE_MAGIC_WAND;
        }
};

#endif // _WEAPONMAGICWAND_H_INCLUDED
