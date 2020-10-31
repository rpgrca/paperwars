#ifndef _SHOP_H_INCLUDED
#define _SHOP_H_INCLUDED 0xBEBACAFE

#include "Object.h"
#include "Weapons.h"
#include "Armours.h"
#include "Soldiers.h"

class CShop : public CObject {
    private:
        CWeapons *m_pWeapons;
        CArmours *m_pArmours;
        CSoldiers *m_pSoldiers;

    public:
        CShop() {
            m_pWeapons = new CWeapons;
            m_pArmours = new CArmours;
            m_pSoldiers = new CSoldiers;
        }

       ~CShop() {
            m_pWeapons->Purge();
            delete m_pWeapons;
            m_pWeapons = NULL;

            m_pArmours->Purge();
            delete m_pArmours;
            m_pArmours = NULL;

            m_pSoldiers->Purge();
            delete m_pSoldiers;
            m_pSoldiers = NULL;
        }

        CWeapons *GetWeapons() {
            return (m_pWeapons);
        }

        CArmours *GetArmours() {
            return (m_pArmours);
        }

        CSoldiers *GetSoldiers() {
            return (m_pSoldiers);
        }
};

#endif // _SHOP_H_INCLUDED
