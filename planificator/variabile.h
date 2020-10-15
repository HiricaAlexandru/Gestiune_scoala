#ifndef VARIABILE_H_INCLUDED
#define VARIABILE_H_INCLUDED
struct Elev{
    int note[20];
    int nrNote=0;
    char scoala[75];
    char nume[20];
    char prenume[25];
    };

struct Data{
    int zi;
    int luna;
    int an;
    int ora;};

struct Clasa{
    char nume[45];
    Data dn;
    Elev el[10];
    char tip[20];
    char tema[100];
    int nrElevi = 0;

    };
struct Statistica{
    int nrClase = 0;
    Data dnstats;
    int lNumeCls = 4;
    int lNrElevi = 2;
    int lOra = 2;
    int lTip = 3;
    int lTema = 4;
    int lNumeElev = 4;
    int lPrenume = 7;
    int lScl = 6;
    int lNote = 2;
    const int lData = 10;
    };


#endif // VARIABILE_H_INCLUDED
