#ifndef _ARMOURMAIL_H_INCLUDED
#define _ARMOURMAIL_H_INCLUDED 0xBEBACAFE

#include "Armour.h"
#include "ArmourType.h"

class CArmourMail : public CArmour {
    public:
        CArmourMail() {
            m_eArmourType = enARMOURTYPE_MAIL;
        }
};

#endif // _ARMOURMAIL_H_INCLUDED
