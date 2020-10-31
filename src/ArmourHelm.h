#ifndef _ARMOURHELM_H_INCLUDED
#define _ARMOURHELM_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"

class CArmourHelm : public CArmour {
    public:
        CArmourHelm() {
            m_eArmourType = enARMOURTYPE_HELM;
        }
};

#endif // _ARMOURHELM_H_INCLUDED
