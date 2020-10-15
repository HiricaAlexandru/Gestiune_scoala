#ifndef TIME_H
#define TIME_H
#include <stdlib.h>
#include <string.h>
class Time
{
    public:
    Time();
    virtual ~Time();
    void setTimp(int ora1);
    void setData(char sir[]);

    protected:

    private:
        int ora,minut;
        int zi,luna,an;

};

#endif // TIME_H
