#ifndef _OBJECTSERVICES_H_INCLUDED
#define _OBJECTSERVICES_H_INCLUDED 0xBEBACAFE

class CObjectServices {
    public:
        bool IsSame(const CObject *pObject, const CObject *pOtherObject) const {
            bool bResult = false;

            if ((pObject != NULL) && (pOtherObject != NULL))
                bResult = (pObject->GetID() == pOtherObject->GetID());

            return (bResult);
        }
};

#endif // _OBJECTSERVICES_H_INCLUDED
