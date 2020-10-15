#ifndef ELEVI_H
#define ELEVI_H
#include "Clasa.h"
#include <string.h>


class Elevi
{
    public:
        Elevi();
        ~Elevi();
        void setNume(char sir[]);
        void setPrenume(char sir[]);
        void setScoala(char sir[]);

    protected:

    private:
        char nume[20];
        char prenume[40];
        char scoalaProvenienta[80];

};

#endif // ELEVI_H
