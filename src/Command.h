#ifndef _COMMAND_H_INCLUDED
#define _COMMAND_H_INCLUDED 0xBEBACAFE

#include <string>
#include "CommandType.h"

class CCommand : public CObject {
    protected:
        enCommandType m_eCommandType;
        std::string m_szName;

    public:
        CCommand()
            : m_eCommandType(enCOMMANDTYPE_UNKNOWN), m_szName("") {
        }

        std::string GetName() const {
            return (m_szName);
        }

        void SetName(const std::string szName) {
            m_szName = szName;
        }

        enCommandType GetType() const {
            return (m_eCommandType);
        }
};

#endif // _COMMAND_H_INCLUDED
