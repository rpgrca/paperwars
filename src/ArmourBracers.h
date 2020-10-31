#ifndef _ARMOURBRACERS_H_INCLUDED
#define _ARMOURBRACERS_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"

class CArmourBracers : public CArmour {
    public:
        CArmourBracers() {
            m_eArmourType = enARMOURTYPE_BRACERS;
        }
};

#endif // _ARMOURBRACERS_H_INCLUDED
