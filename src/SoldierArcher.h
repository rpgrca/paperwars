#ifndef _SOLDIERARCHER_H_INCLUDED
#define _SOLDIERARCHER_H_INCLUDED 0xBEBACAFE

#include <string>
#include "SoldierType.h"
#include "Soldier.h"

class CSoldierArcher : public CSoldier {
    private:
        static const enSoldierType c_eType = enSOLDIERTYPE_ARCHER;
        static const long c_lHealth = 7;
        static const long c_lMaximumHealth = 7;
        static const long c_lAttack = 2;
        static const long c_lMaximumAttack = 2;
        static const long c_lDefense = 1;
        static const long c_lMaximumDefense = 1;
        static const long c_lLevel = 1;
        static const long c_lExperience = 0;
        static const long c_lSpeed = 2;
        static const long c_lRange = 5;

        void SetDefault() {
            m_szDefaultName = "Archer";
            m_eDefaultType = c_eType;
            m_lDefaultHealth = c_lHealth;
            m_lDefaultMaximumHealth = c_lMaximumHealth;
            m_lDefaultAttack = c_lAttack;
            m_lDefaultMaximumAttack = c_lMaximumAttack;
            m_lDefaultDefense = c_lDefense;
            m_lDefaultMaximumDefense = c_lMaximumDefense;
            m_lDefaultLevel = c_lLevel;
            m_lDefaultExperience = c_lExperience;
            m_lDefaultSpeed = c_lSpeed;
            m_lDefaultRange = c_lRange;
        }

    public:
        CSoldierArcher()
            : CSoldier(enSOLDIERTYPE_ARCHER, "Archer", c_lHealth, c_lMaximumHealth, c_lAttack, c_lMaximumAttack, c_lDefense, c_lMaximumDefense, c_lLevel, c_lExperience, c_lSpeed, c_lRange) {
            SetDefault();
        }

        CSoldierArcher(const std::string szName, const long lHealth = c_lHealth, const long lMaximumHealth = c_lMaximumHealth, const long lAttack = c_lAttack, const long lMaximumAttack = c_lMaximumAttack, const long lDefense = c_lDefense, const long lMaximumDefense = c_lMaximumDefense, const long lLevel = c_lLevel, const long lExperience = c_lExperience, const long lSpeed = c_lSpeed, const long lRange = c_lRange)
            : CSoldier(enSOLDIERTYPE_ARCHER, szName, lHealth, lMaximumHealth, lAttack, lMaximumAttack, lDefense, lMaximumDefense, lLevel, lExperience, lSpeed, lRange) {
            SetDefault();
        }
};

#endif // _SOLDIERARCHER_H_INCLUDED
