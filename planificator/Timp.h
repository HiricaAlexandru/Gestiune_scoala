#ifndef TIMP_H_INCLUDED
#define TIMP_H_INCLUDED

#include <windows.h>
#include "variabile.h"

void iauDataCurenta(Statistica *Statistica){
    SYSTEMTIME st;
    GetLocalTime(&st);
    Statistica->dnstats.an = st.wYear;
    Statistica->dnstats.luna = st.wMonth;
    Statistica->dnstats.zi = st.wDay;
    Statistica->dnstats.ora = st.wHour;
}

int DeterminDataMaiMare(Data *TimeElev, Data *SysTime){
    if((TimeElev->an) < (SysTime->an))
        return -1;

    if((TimeElev->an) > (SysTime->an))
        return 1;

    if((TimeElev->luna) < (SysTime-> luna))
        return -1;

    if((TimeElev->luna) > (SysTime->luna))
        return 1;

    if((TimeElev->zi) < (SysTime-> zi))
        return -1;
    if((TimeElev->zi) > (SysTime->zi))
        return 1;

    if((TimeElev->ora) < (SysTime->ora))
        return -1;

    if((TimeElev->ora) < (SysTime->ora))
        return 1;

    return 0;
    }

#endif // TIMP_H_INCLUDED
