#ifndef FUNCTIICLASA_H_INCLUDED
#define FUNCTIICLASA_H_INCLUDED
#include "variabile.h"
#include <string.h>
#include <stdlib.h>
#include "FunctiiElev.h"

void setNumeClasa(char p[], Clasa& cl){
    strcpy(cl.nume,p);
    }
void setData(char sir[], Clasa &cl){
    cl.dn.zi = atoi(sir);
    char *p=strchr(sir,'.');
    cl.dn.luna = atoi(p+1);
    p=strchr(p+1,'.');
    cl.dn.an = atoi(p+1);
    }


void setTip(char sir[], Clasa &cl){
    strcpy(cl.tip,sir);
    }

void setTema(char sir[], Clasa &cl){
    strcpy(cl.tema,sir);
    }
void setOra(char sir[],Clasa &cl){
    cl.dn.ora = atoi(sir);
    }

void stergParticipant(Clasa &cl, int j){
    for(int k=j;k<cl.nrElevi-1;k++)
        cl.el[k] = cl.el[k+1];
    cl.nrElevi--;
    }

#endif // FUNCTIICLASA_H_INCLUDED
