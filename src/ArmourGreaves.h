#ifndef _ARMOURGREAVES_H_INCLUDED
#define _ARMOURGREAVES_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"

class CArmourGreaves : public CArmour {
    public:
        CArmourGreaves() {
            m_eArmourType = enARMOURTYPE_GREAVES;
        }
};

#endif // _ARMOURGREAVES_H_INCLUDED
