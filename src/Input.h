#ifndef _INPUT_H_INCLUDED
#define _INPUT_H_INCLUDED 0xBEBACAFE

#include "Object.h"
#include "InputType.h"
#include "Commands.h"
#include "Command.h"

class CInput : public CObject {
    protected:
        enInputType m_eInputType;
        CCommands m_pCommands;

    public:
        CInput()
            : m_eInputType(enINPUTTYPE_UNKNOWN) {
        }

       ~CInput() {
            m_pCommands.Clear();
        }

        virtual bool Poll() {
            return (false);
        }

        enInputType GetInput() const {
            return (m_eInputType);
        }

        CCommand *GetCommand() {
            CCommand *pCommand = NULL;

            if (m_pCommands.GetCount() > 0) {
                pCommand = m_pCommands.GetAt(0);
                m_pCommands.Remove(pCommand);
            }

            return (pCommand);
        }
};

#endif // _INPUT_H_INCLUDED
