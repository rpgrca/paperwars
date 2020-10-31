#ifndef _ITEST_H_INCLUDED
#define _ITEST_H_INCLUDED 0xBEBACAFE

class ITest {
    private:
        static long s_lTestID;
        long m_lTestID;

    public:
        virtual std::string GetName() const = 0;
        virtual bool Execute() = 0;

        ITest() :
            m_lTestID(s_lTestID++) {
        }

        virtual ~ITest() {
        }

        long GetID() const {
            return (m_lTestID);
        }
};

#endif // _ITEST_H_INCLUDED
