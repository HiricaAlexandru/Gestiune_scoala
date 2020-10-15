#ifndef FUNCTIIELEV_H_INCLUDED
#define FUNCTIIELEV_H_INCLUDED
#include "variabile.h"

void setNumeElev(Elev &el,char sir[50]){
    strcpy(el.nume,sir);
    }
void setPrenume(Elev &el,char sir[50]){
    strcpy(el.prenume,sir);
    }
void setScoala(Elev &el,char sir[50]){
    strcpy(el.scoala,sir);
    }
void TrecNota(Elev &el,int da){
    el.note[el.nrNote++] = da;
    }

#endif // FUNCTIIELEV_H_INCLUDED
