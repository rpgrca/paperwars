#ifndef _WEAPONFACTORY_H_INCLUDED
#define _WEAPONFACTORY_H_INCLUDED 0xBEBACAFE

#include "Weapon.h"
#include "WeaponType.h"
#include "WeaponAxe.h"
#include "WeaponSword.h"
#include "WeaponBow.h"
#include "WeaponKnife.h"
#include "WeaponHalberd.h"
#include "WeaponClub.h"
#include "WeaponMagicWand.h"

class CWeaponFactory {
    public:
        CWeapon *Create(const enWeaponType eWeaponType) {
            CWeapon *pWeapon = NULL;

            switch (eWeaponType) {
                case enWEAPONTYPE_NONE:
                    pWeapon = NULL;
                    break;

                case enWEAPONTYPE_UNKNOWN:
                    pWeapon = new CWeapon;
                    break;

                case enWEAPONTYPE_AXE:
                    pWeapon = new CWeaponAxe;
                    break;

                case enWEAPONTYPE_SWORD:
                    pWeapon = new CWeaponSword;
                    break;

                case enWEAPONTYPE_BOW:
                    pWeapon = new CWeaponBow;
                    break;

                case enWEAPONTYPE_KNIFE:
                    pWeapon = new CWeaponKnife;
                    break;

                case enWEAPONTYPE_HALBERD:
                    pWeapon = new CWeaponHalberd;
                    break;

                case enWEAPONTYPE_CLUB:
                    pWeapon = new CWeaponClub;
                    break;

                case enWEAPONTYPE_MAGIC_WAND:
                    pWeapon = new CWeaponMagicWand;
                    break;
            }

            return (pWeapon);
        }
};

#endif // _WEAPONFACTORY_H_INCLUDED
