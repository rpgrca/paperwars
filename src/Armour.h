#ifndef _ARMOUR_H_INCLUDED
#define _ARMOUR_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Object.h"
#include "ArmourType.h"

class CArmour : public CObject {
    private:
        static const long c_lDefenseModifier = 0;
        static const long c_lDodgeModifier = 0;
        static const enArmourType c_eArmourType = enARMOURTYPE_UNKNOWN;

    protected:
        long m_lDodgeModifier;
        long m_lDefenseModifier;
        enArmourType m_eArmourType;

    public:
        CArmour()
            : m_lDodgeModifier(c_lDodgeModifier), m_lDefenseModifier(c_lDefenseModifier), m_eArmourType(c_eArmourType) {
            m_szName = "Armour";
        }

        CArmour(const long lDodgeModifier, const long lDefenseModifier)
            : m_lDodgeModifier(lDodgeModifier), m_lDefenseModifier(lDefenseModifier), m_eArmourType(c_eArmourType) {
            m_szName = "Armour";
        }

        CArmour(const long lDodgeModifier, const long lDefenseModifier, const enArmourType eArmourType)
            : m_lDodgeModifier(lDodgeModifier), m_lDefenseModifier(lDefenseModifier), m_eArmourType(eArmourType) {
            m_szName = "Armour";
        }

        long GetDodgeModifier() const {
            return (m_lDodgeModifier);
        }

        void SetDodgeModifier(const long lDodgeModifier) {
            m_lDodgeModifier = lDodgeModifier;
        }

        long GetDefaultDodgeModifier() const {
            return (c_lDodgeModifier);
        }

        long GetDefenseModifier() const {
            return (m_lDefenseModifier);
        }

        void SetDefenseModifier(const long lDefenseModifier) {
            m_lDefenseModifier = lDefenseModifier;
        }

        long GetDefaultDefenseModifier() const {
            return (c_lDefenseModifier);
        }

        enArmourType GetType() const {
            return (m_eArmourType);
        }

        enArmourType GetDefaultType() const {
            return (c_eArmourType);
        }
};

#endif // _ARMOUR_H_INCLUDED
