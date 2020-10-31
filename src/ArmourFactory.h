#ifndef _ARMOURFACTORY_H_INCLUDED
#define _ARMOURFACTORY_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"
#include "ArmourHelm.h"
#include "ArmourMail.h"
#include "ArmourBracers.h"
#include "ArmourGreaves.h"
#include "ArmourBoots.h"
#include "ArmourShield.h"
#include "ArmourCloak.h"

class CArmourFactory {
    public:
        CArmour *Create(const enArmourType eArmourType) {
            CArmour *pArmour = NULL;

            switch (eArmourType) {
                case enARMOURTYPE_NONE:
                    pArmour = NULL;
                    break;

                case enARMOURTYPE_UNKNOWN:
                    pArmour = new CArmour;
                    break;

                case enARMOURTYPE_HELM:
                    pArmour = new CArmourHelm;
                    break;

                case enARMOURTYPE_MAIL:
                    pArmour = new CArmourMail;
                    break;

                case enARMOURTYPE_BRACERS:
                    pArmour = new CArmourBracers;
                    break;

                case enARMOURTYPE_GREAVES:
                    pArmour = new CArmourGreaves;
                    break;

                case enARMOURTYPE_BOOTS:
                    pArmour = new CArmourBoots;
                    break;

                case enARMOURTYPE_SHIELD:
                    pArmour = new CArmourShield;
                    break;

                case enARMOURTYPE_CLOAK:
                    pArmour = new CArmourCloak;
                    break;
            }

            return (pArmour);
        }
};

#endif // _ARMOURFACTORY_H_INCLUDED
