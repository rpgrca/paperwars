#ifndef _ARMOURSHIELD_H_INCLUDED
#define _ARMOURSHIELD_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"

class CArmourShield : public CArmour {
    public:
        CArmourShield() {
            m_eArmourType = enARMOURTYPE_SHIELD;
        }
};

#endif // _ARMOURSHIELD_H_INCLUDED
