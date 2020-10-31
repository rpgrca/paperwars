#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Object.h"
#include "PlayerType.h"
#include "Input.h"

class CPlayer : public CObject {
    protected:
        CInput *m_pInput;
        std::string m_szName;
        long m_lMoney;
        long m_lScore;
        enPlayerType m_ePlayerType;

    public:
        CPlayer()
            :m_szName(""), m_lMoney(0), m_lScore(0), m_ePlayerType(enPLAYERTYPE_UNKNOWN), m_pInput(NULL) {
        }

        void SetName(const std::string szName) {
            m_szName = szName;
        }

        std::string GetName() const {
            return (m_szName);
        }

        void SetScore(const long lScore) {
            m_lScore = lScore;
        }

        long GetScore() const {
            return (m_lScore);
        }

        void SetMoney(const long lMoney) {
            m_lMoney = lMoney;
        }

        long GetMoney() const {
            return (m_lMoney);
        }

        enPlayerType GetType() const {
            return (m_ePlayerType);
        }

        void SetInput(const CInput *pInput) {
            m_pInput = pInput;
        }

        CInput *GetInput() const {
            return (m_pInput);
        }
};

#endif // _PLAYER_H_INCLUDED
