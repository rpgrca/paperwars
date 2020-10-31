#ifndef _ARMOURMANAGER_H_INCLUDED
#define _ARMOURMANAGER_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"
#include "ArmourFactory.h"

class CArmourManager {
    private:
        CArmours m_pArmours;

    public:
       ~CArmourManager() {
            m_pArmours.Purge();
        }

        CArmour *Create(const enArmourType eArmourType, const long lDodgeModifier = 0, const long lDefenseModifier = 0) {
            CArmourFactory *pArmourFactory = NULL;
            CArmour *pArmour = NULL;

            if (eArmourType != enARMOURTYPE_NONE) {
                pArmourFactory = new CArmourFactory;
                pArmour = pArmourFactory->Create(eArmourType);
                delete pArmourFactory;

                if (lDodgeModifier != 0)
                    pArmour->SetDodgeModifier(lDodgeModifier);

                if (lDefenseModifier != 0)
                    pArmour->SetDefenseModifier(lDefenseModifier);

                m_pArmours.Add(pArmour);
            }

            return (pArmour);
        }
};

#endif // _ARMOURMANAGER_H_INCLUDED
