#ifndef _ARMOURCLOAK_H_INCLUDED
#define _ARMOURCLOAK_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"

class CArmourCloak : public CArmour {
    public:
        CArmourCloak() {
            m_eArmourType = enARMOURTYPE_CLOAK;
        }
};

#endif // _ARMOURCLOAK_H_INCLUDED
