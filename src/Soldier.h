#ifndef _SOLDIER_H_INCLUDED
#define _SOLDIER_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Object.h"
#include "SoldierType.h"
#include "Weapons.h"
#include "Armours.h"

class CSoldier : public CObject {
    private:
        static const enSoldierType c_eSoldierType = enSOLDIERTYPE_UNKNOWN;
        static const long c_lHealth = -1;
        static const long c_lMaximumHealth = -1;
        static const long c_lAttack = -1;
        static const long c_lMaximumAttack = -1;
        static const long c_lDefense = -1;
        static const long c_lMaximumDefense = -1;
        static const long c_lLevel = -1;
        static const long c_lExperience = -1;
        static const long c_lSpeed = -1;
        static const long c_lRange = 1;

    protected:
        long m_lID;
        enSoldierType m_eSoldierType;
        long m_lHealth;
        long m_lMaximumHealth;
        long m_lAttack;
        long m_lMaximumAttack;
        long m_lDefense;
        long m_lMaximumDefense;
        long m_lLevel;
        long m_lExperience;
        long m_lSpeed;
        long m_lRange;
        std::string m_szDefaultName;
        enSoldierType m_eDefaultType;
        long m_lDefaultHealth;
        long m_lDefaultMaximumHealth;
        long m_lDefaultAttack;
        long m_lDefaultMaximumAttack;
        long m_lDefaultDefense;
        long m_lDefaultMaximumDefense;
        long m_lDefaultLevel;
        long m_lDefaultExperience;
        long m_lDefaultSpeed;
        long m_lDefaultRange;
        mutable CArmours m_pArmours;
        mutable CWeapons m_pWeapons;

    public:
        CSoldier()
            : m_eSoldierType(c_eSoldierType), m_lHealth(c_lHealth), m_lMaximumHealth(c_lMaximumHealth), m_lAttack(c_lAttack), m_lMaximumAttack(c_lMaximumAttack), m_lDefense(c_lDefense), m_lMaximumDefense(c_lMaximumDefense), m_lLevel(c_lLevel), m_lExperience(c_lExperience), m_lSpeed(c_lSpeed), m_lRange(c_lRange) {
            m_szName = "";
            m_szDefaultName = "";
            m_lDefaultHealth = c_lHealth;
            m_lDefaultMaximumHealth = c_lMaximumHealth;
            m_lDefaultAttack = c_lAttack;
            m_lDefaultMaximumAttack = c_lMaximumAttack;
            m_lDefaultDefense = c_lDefense;
            m_lDefaultMaximumDefense = c_lMaximumDefense;
            m_lDefaultLevel = c_lLevel;
            m_lDefaultExperience = c_lExperience;
            m_lDefaultSpeed = c_lSpeed;
            m_eDefaultType = c_eSoldierType;
            m_lDefaultRange = c_lRange;
        }

        virtual ~CSoldier() {
            m_pArmours.Clear();
            m_pWeapons.Clear();
        }

        CSoldier(const enSoldierType eSoldierType, const std::string szName = "", const long lHealth = c_lHealth, const long lMaximumHealth = c_lMaximumHealth, const long lAttack = c_lAttack, const long lMaximumAttack = c_lMaximumAttack, const long lDefense = c_lDefense, const long lMaximumDefense = c_lMaximumDefense, const long lLevel = c_lLevel, const long lExperience = c_lExperience, const long lSpeed = c_lSpeed, const long lRange = c_lRange)
            : m_eSoldierType(eSoldierType),
              m_lHealth(lHealth),
              m_lMaximumHealth(lMaximumHealth),
              m_lAttack(lAttack),
              m_lMaximumAttack(lMaximumAttack),
              m_lDefense(lDefense),
              m_lMaximumDefense(lMaximumDefense),
              m_lLevel(lLevel),
              m_lExperience(lExperience),
              m_lSpeed(lSpeed),
              m_lRange(lRange) {
            m_szName = szName;
        }

        long GetHealth() const {
            return (m_lHealth);
        }

        void SetHealth(const long lHealth) {
            m_lHealth = lHealth;
        }

        long GetMaximumHealth() const {
            return (m_lMaximumHealth);
        }

        void SetMaximumHealth(const long lMaximumHealth) {
            m_lMaximumHealth = lMaximumHealth;
        }

        long GetAttack() const {
            return (m_lAttack);
        }

        void SetAttack(const long lAttack) {
            m_lAttack = lAttack;
        }

        long GetMaximumAttack() const {
            return (m_lMaximumAttack);
        }

        void SetMaximumAttack(const long lMaximumAttack) {
            m_lMaximumAttack = lMaximumAttack;
        }

        long GetDefense() const {
            return (m_lDefense);
        }

        void SetDefense(const long lDefense) {
            m_lDefense = lDefense;
        }

        long GetMaximumDefense() const {
            return (m_lMaximumDefense);
        }

        void SetMaximumDefense(const long lMaximumDefense) {
            m_lMaximumDefense = lMaximumDefense;
        }

        long GetLevel() const {
            return (m_lLevel);
        }

        void SetLevel(const long lLevel) {
            m_lLevel = lLevel;
        }

        long GetExperience() const {
            return (m_lExperience);
        }

        void SetExperience(const long lExperience) {
            m_lExperience = lExperience;
        }

        enSoldierType GetType() const {
            return (m_eSoldierType);
        }

        void SetType(const enSoldierType eSoldierType) {
            m_eSoldierType = eSoldierType;
        }

        long GetSpeed() const {
            return (m_lSpeed);
        }

        void SetSpeed(const long lSpeed) {
            m_lSpeed = lSpeed;
        }

        long GetRange() const {
            return (m_lRange);
        }

        void SetRange(const long lRange) {
            m_lRange = lRange;
        }

        std::string GetDefaultName() const {
            return (m_szDefaultName);
        }

        long GetDefaultHealth() const {
            return (m_lDefaultHealth);
        }

        long GetDefaultMaximumHealth() const {
            return (m_lDefaultMaximumHealth);
        }

        long GetDefaultAttack() const {
            return (m_lDefaultAttack);
        }

        long GetDefaultMaximumAttack() const {
            return (m_lDefaultMaximumAttack);
        }

        long GetDefaultDefense() const {
            return (m_lDefaultDefense);
        }

        long GetDefaultMaximumDefense() const {
            return (m_lDefaultMaximumDefense);
        }

        long GetDefaultLevel() const {
            return (m_lDefaultLevel);
        }

        long GetDefaultExperience() const {
            return (m_lDefaultExperience);
        }

        long GetDefaultSpeed() const {
            return (m_lDefaultSpeed);
        }

        enSoldierType GetDefaultType() const {
            return (m_eDefaultType);
        }

        long GetDefaultRange() const {
            return (m_lDefaultRange);
        }

        CArmours *GetArmours() {
            return (&m_pArmours);
        }

        CWeapons *GetWeapons() {
            return (&m_pWeapons);
        }

        long GetModifiedAttack() const {
            long lAttack = 0;
            CWeapon *pWeapon = NULL;

            lAttack = m_lAttack;
            pWeapon = m_pWeapons.GetAt(0);
            if (pWeapon != NULL) {
                lAttack += pWeapon->GetToHitModifier();
            }

            return (lAttack);
        }

        long GetModifiedDefense() const {
            long lDefense = 0;
            unsigned long lIndex = 0;

            lDefense = m_lDefense;
            for (lIndex = 0; lIndex < m_pArmours.GetCount(); lIndex++)
                lDefense += m_pArmours.GetAt(lIndex)->GetDefenseModifier();

            return (lDefense);
        }
};

template<typename T>
class CTSoldier : public CSoldier {
    public:
        virtual ~CTSoldier() { }

        void SetDefault() {
            m_lDefaultHealth = T::c_lHealth;
        }
};

#endif // _SOLDIER_H_INCLUDED

// vim:nowrap
