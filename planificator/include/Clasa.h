#ifndef CLASA_H
#define CLASA_H
#include "Time.h"
class Elevi

class Clasa:public Time, public Elevi
{
    public:
        Clasa();
        ~Clasa();

        void setNumeClasa(char *p);

        void modificNumeClasa(char *p);

        void setOra(int ora);

        void setData(char sir[]);

        void adaugElev();


    protected:

    private:
        char nume[30];
        Time tm;
        Elevi elev[10];
        char tip[10];
        char tema[50];
        int nrElevi=1;

};

#endif // CLASA_H
