#ifndef _WEAPON_H_INCLUDED
#define _WEAPON_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Object.h"
#include "WeaponType.h"

class CWeapon : public CObject {
    private:
        static const long c_lToHitModifier = 0;
        static const long c_lDamageModifier = 0;
        static const enWeaponType c_eWeaponType = enWEAPONTYPE_UNKNOWN;

    protected:
        long m_lToHitModifier;
        long m_lDamageModifier;
        enWeaponType m_eWeaponType;

    public:
        CWeapon()
            : m_lToHitModifier(c_lToHitModifier), m_lDamageModifier(c_lDamageModifier), m_eWeaponType(c_eWeaponType) {
            m_szName = "Weapon";
        }

        CWeapon(const long lToHitModifier, const long lDamageModifier)
            : m_lToHitModifier(lToHitModifier), m_lDamageModifier(lDamageModifier), m_eWeaponType(c_eWeaponType) {
            m_szName = "Weapon";
        }

        CWeapon(const long lToHitModifier, const long lDamageModifier, const enWeaponType eWeaponType)
            : m_lToHitModifier(lToHitModifier), m_lDamageModifier(lDamageModifier), m_eWeaponType(eWeaponType) {
            m_szName = "Weapon";
        }

        long GetToHitModifier() const {
            return (m_lToHitModifier);
        }

        void SetToHitModifier(const long lToHitModifier) {
            m_lToHitModifier = lToHitModifier;
        }

        long GetDamageModifier() const {
            return (m_lDamageModifier);
        }

        void SetDamageModifier(const long lDamageModifier) {
            m_lDamageModifier = lDamageModifier;
        }

        enWeaponType GetType() const {
            return (m_eWeaponType);
        }
};

#endif // _WEAPON_H_INCLUDED
