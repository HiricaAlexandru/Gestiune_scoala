#include "Clasa.h"
#include "Time.h"
#include "Elevi.h"
class Elevi
Clasa::Clasa()
{
    //ctor
}

Clasa::~Clasa()
{
    //dtor
}
void Clasa::setNumeClasa(char *p){
            strcpy(nume,p);
        }
void Clasa:: modificNumeClasa(char *p){
            strcpy(nume,p);
        }

void Clasa:: setOra(int ora){
            setTimp(ora);
        }

void Clasa:: setData(char sir[]){
            tm.setData(sir);
            }
