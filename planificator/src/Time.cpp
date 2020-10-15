#include "Time.h"
#include <stdlib.h>
#include <string.h>
Time::Time()

{
    //ctor
}

Time::~Time()
{
    //dtor
}
Time::void setTimp(int ora1)
{
    ora = ora1;
}
Time::void setData(char sir[])
{
    zi = atoi(sir);
    char *p;
    p = strchr(sir,'-');
    luna = atoi(p+1);
    p = strchr (p+1, '-');
    an = atoi(p+1);
}
