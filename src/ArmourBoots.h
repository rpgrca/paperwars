#ifndef _ARMOURBOOTS_H_INCLUDED
#define _ARMOURBOOTS_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"

class CArmourBoots : public CArmour {
    public:
        CArmourBoots() {
            m_eArmourType = enARMOURTYPE_BOOTS;
        }
};

#endif // _ARMOURBOOTS_H_INCLUDED
