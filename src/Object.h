#ifndef _OBJECT_H_INCLUDED
#define _OBJECT_H_INCLUDED 0xBEBACAFE

#include <string>

class CObject {
    private:
        static long s_lID;

    protected:
        long m_lID;
        std::string m_szName;

    public:
        CObject() : m_lID(s_lID++) {
        }

        virtual ~CObject() { 
        }

        long GetID() const {
            return (m_lID);
        }

        void SetName(const std::string szName) {
            m_szName = szName;
        }

        std::string GetName() const {
            return (m_szName);
        }
};

#endif // _OBJECT_H_INCLUDED
