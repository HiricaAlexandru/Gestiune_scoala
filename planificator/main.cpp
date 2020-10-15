#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "variabile.h"
#include "FunctiiClasa.h"
#include "FunctiiElev.h"
#include "Timp.h"

Clasa cl[100];
Statistica Stats;

using namespace std;

void salvezDataInFisier(ofstream *g,int i){
    if(cl[i].dn.zi<10)
            *g<<"0"<<cl[i].dn.zi<<".";
        else
            *g<<cl[i].dn.zi<<".";
        if(cl[i].dn.luna<10)
            *g<<"0"<<cl[i].dn.luna<<".";
        else
            *g<<cl[i].dn.luna<<".";
        *g<<cl[i].dn.an<<"#";
    }

void SalveazaFisier(){
    ofstream g("Date.txt");
    for(int i=0;i<Stats.nrClase;i++){
        g<<cl[i].nrElevi<<"#";
        salvezDataInFisier(&g,i);
        g<<cl[i].dn.ora<<"#";
        g<<cl[i].nume<<"#";
        g<<cl[i].tip<<"#";
        g<<cl[i].tema<<endl;
        for(int j=0;j<cl[i].nrElevi;j++){
            g<<cl[i].el[j].nrNote<<"#";
            g<<cl[i].el[j].nume<<"#";
            g<<cl[i].el[j].prenume<<"#";
            g<<cl[i].el[j].scoala<<"#";
                for(int z=0;z<cl[i].el[j].nrNote;z++){
                    if(z==cl[i].el[j].nrNote-1)
                        g<<cl[i].el[j].note[z];
                    else
                        g<<cl[i].el[j].note[z]<<"#";
            }
            g<<endl;

        }

    }
    g<<'`';

}

void iauDateElev(Clasa &s, ifstream *f,int nrEleviCitire)
{
    int nrNote;
    for(int z=1; z<=nrEleviCitire; s.nrElevi++)
    {
        char st[100];
        f->getline(st,99);
        char *p = strtok(st,"#");
        nrNote = atoi(p);
        p = strtok(NULL,"#");
        setNumeElev(s.el[s.nrElevi],p);
        p = strtok(NULL, "#");
        setPrenume(s.el[s.nrElevi],p);
        p = strtok(NULL, "#");
        setScoala(s.el[s.nrElevi],p);
        int temp;
        while(nrNote!=0)
        {
            p = strtok(NULL,"#");
            temp = atoi(p);
            TrecNota(s.el[s.nrElevi],temp);
            nrNote--;
        }
        z++;
    }
}
void IncarcFisier()
{
    ifstream f("Date.txt");
    int i;
    for(i=0;; i++)
    {
        char st[100];
        f.getline(st,99);
        if(st[0]=='`')
            break;
        char *p = strtok(st,"#");
        int nrEleviCitire = atoi(p);
        p = strtok(NULL,"#");
        setData(p,cl[i]);
        p = strtok(NULL, "#");
        setOra(p,cl[i]);
        p = strtok(NULL, "#");
        setNumeClasa(p,cl[i]);
        p = strtok(NULL,"#");
        setTip(p,cl[i]);
        p = strtok(NULL,"#");
        setTema(p, cl[i]);
        iauDateElev(cl[i], &f,nrEleviCitire);
    }
    Stats.nrClase = i;
    f.close();
}
void afisezEleviiClasei(int i){
    for(int j=0;j<cl[i].nrElevi;j++)
        cout<<j <<". "<<cl[i].el[j].nume<<endl;
    }

int adaugElevi(int nr){
    char st[100];//nr reprezinta practic numarul clasei
    cout<<"Adauga numele elevului ";cin.get(st,99);cin.get();cout<<endl;

    setNumeElev(cl[nr].el[cl[nr].nrElevi],st);
    cout<<"Adauga prenumele elevului ";cin.get(st,99);cin.get();cout<<endl;
    setPrenume(cl[nr].el[cl[nr].nrElevi],st);
    cout<<"Adauga scoala de provenienta ";cin.get(st,99);cin.get();cout<<endl;
    setScoala(cl[nr].el[cl[nr].nrElevi],st);
    cout<<"Adauga notele lui si cand ai terminat scire -1 ";cout<<endl;
    int k=231;
    while(k!=-1){
        cout<<"Adauga Nota ";cin>>k;cin.get();
        if(k>0 && k<11)
            TrecNota(cl[nr].el[cl[nr].nrElevi],k);
        else
            if(k==-1)
                cout<<"Ai terminat de introdus note ";
            else
                cout<<"Nota introdusa nu este una valida, te rog introdu alta valoare "<<endl;
    }
    cout<<"Mai doresti sa mai adaugi elevi?(Y/N)";
    cin>>st;cin.get();
    cl[nr].nrElevi++;
    if(tolower(st[0]) == 'y')
        return 1;
    else
        return -1;

}

void adaugGrupa(){
    Stats.nrClase++;
    char st[100]=" ";
    cout<<"Pune numele grupei:";
    cin.get(st,99);cin.get();cout<<endl;
    setNumeClasa(st, cl[Stats.nrClase-1]);
    cout<<"Adauga data la care se va desfasura (dd.mm.yyyy) ";cin.get(st,99);cin.get();
    setData(st, cl[Stats.nrClase-1]);cout<<endl;
    cout<<"Adauga ora la care se va desfasura ";cin>>st;cin.get();
    setOra(st,cl[Stats.nrClase-1]);cout<<endl;
    cout<<"ce se va face ?"<<endl;
    cout<<"1.test "<<endl;
    cout<<"2.exercitii "<<endl;
    cout<<"3.predare "<<endl;
    int i;
    cout<<"Alege optiune ";cin>>i;cin.get();cout<<endl;
    switch (i){
        case 1: setTip("test",cl[Stats.nrClase-1]);break;
        case 2: setTip("exercitii", cl[Stats.nrClase-1]);break;
        case 3: setTip("predare",cl[Stats.nrClase-1]);
    }
    cout<<"Adaugati tema "<<endl;
    cin.get(st,99);
    cin.get();
    setTema(st,cl[Stats.nrClase-1]);
    int ok=1;
    while(ok==1){
        ok=adaugElevi(Stats.nrClase-1);
    }
}

void scriuNumeleGrupelor(){
    for(int i=0;i<Stats.nrClase;i++)
        cout<<i<<"."<<cl[i].nume<<endl;
    }

void adaugElevinGrupa(){
    system("CLS");
    scriuNumeleGrupelor();
    cout<<"In care vrei sa adaugi?";
    int i;
    cin>>i;cin.get();
    int ok=1;
    while(ok==1){
            ok=adaugElevi(i);
    }
}

void adaugTip(){
    scriuNumeleGrupelor();
    cout<<"carei grupe vrei sa adaugi tipul?";cout<<endl;
    int i;
    cin>>i;cin.get();
    int z;
    cout<<"Alege tipul "<<endl;cout<<"1.Test "<<endl<<"2.Predare "<<endl<<"3.Exercitii ";
    cin>>z;cin.get();
    switch (z){
        case 1: strcpy(cl[i].tip,"test");break;
        case 2: strcpy(cl[i].tip,"predare");break;
        case 3: strcpy(cl[i].tip,"exercitii");break;
    }

}

void adaugTema(){
    scriuNumeleGrupelor();
    cout<<"carei grupe vrei sa adaugi tema?";
    int i;
    cin>>i;cin.get();
    cout<<"Scrie tema ";
    char st[100];cin.get(st,99);cin.get();
    strcpy(cl[i].tema,st);
    }

void adaugNotaElev(){
    cout<<"Alege clasa "<<endl;
    scriuNumeleGrupelor();
    cout<<"Alege optiune ";int i;cin>>i;cin.get();

    char c='n';
    while(c=='n'){
        afisezEleviiClasei(i);
        cout<<"Carui elev doresti sa adaugi nota? "<<endl<<"Alege optiunea ";
        int j;
        cin>>j;cin.get();
        cout<<"Ce nota doresti? ";
        int nota;cin>>nota;cin.get();
        if(nota>0 && nota<11)
            TrecNota(cl[i].el[j],nota);
        else
            cout<<"Nota introdusa este incorecta";
        cout<<endl<<"Ai terminat de trecut nota elevilor din aceasta grupa?(y/n)";cin>>c;cin.get();
        tolower(c);
        system("CLS");
    }
}

void optiuniAdaugare(){
    system("CLS");
    cout<<"1. adaugare grupa "<<endl;
    cout<<"2. adaugare elev in grupa "<<endl;
    cout<<"3. adaugare tip "<<endl;
    cout<<"4. adaugare tema "<<endl;
    cout<<"5. adaugare nota elev "<<endl;
    cout<<"6.Back "<<endl;
    int i;
    cout<<"Alege ";cin>>i;system("CLS");cin.get();
    while(i!=6){
        switch (i){
            case 1:adaugGrupa();break;
            case 2:adaugElevinGrupa();break;
            case 3:adaugTip();break;
            case 4:adaugTema();break;
            case 5:adaugNotaElev();break;
            case 6:break;
        }
        system("CLS");
        cout<<"1. adaugare grupa "<<endl;
        cout<<"2. adaugare elev in grupa "<<endl;
        cout<<"3. adaugare tip "<<endl;
        cout<<"5. adaugare nota elev "<<endl;
        cout<<"6.Back "<<endl;
        cin>>i;cin.get();
    }

}

void afisezOptiuniStergere(){
    cout<<"1. stergere grupa ";cout<<endl;
    cout<<"2. stergere tema ";cout<<endl;
    cout<<"3. stergere tip ";cout<<endl;
    cout<<"4. stergere participant ";cout<<endl;
    cout<<"5. back ";cout<<endl;
    cout<<"Alege optiunea ";
    }

void stergGrupa(){
    system("CLS");
    cout<<"Ce grupa doriti sa stergi?";cout<<endl;
    scriuNumeleGrupelor();
    int i;
    cout<<"Alege optiunea ";cin>>i;cin.get();
    for(int j=i;j<Stats.nrClase;j++)
        cl[j] = cl[j+1];
    Stats.nrClase--;
}

void stergTema(){
    system("CLS");
    cout<<"La ce grupa doresti sa stergi tema?"<<endl;
    scriuNumeleGrupelor;
    int i;cout<<"Alege optiunea ";cin>>i;cin.get();cout<<endl;
    setTema("FARA TEMA", cl[i]);

    }

void stergTip(){
    system("CLS");
    cout<<"La ce grupa doresti sa stergi tipul?"<<endl;
    scriuNumeleGrupelor();
    int i;cout<<"Alege optiunea ";cin>>i;cin.get();cout<<endl;
    setTip("FARA TIP", cl[i]);
}

void stergParticipant(){
    system("CLS");
    cout<<"Carei grupe doresti sa stergi participant? ";cout<<endl;
    scriuNumeleGrupelor();cout<<"Alege optiunea ";
    int i;cin>>i;cin.get();
    afisezEleviiClasei(i);
    int j;
    cout<<"Pe care doresti sa stergi?"<<endl;
    cout<<"Alege optiunea ";cin>>j;cin.get();
    stergParticipant(cl[i],j);
    }

void optiuniStergere(){
    system("CLS");
    afisezOptiuniStergere();
    int i=21312;
    while(i!=5){
        cin>>i;cin.get();
        switch(i){
            case 1: stergGrupa();break;
            case 2: stergTema();break;
            case 3: stergTip();break;
            case 4: stergParticipant();break;
            case 5: break;
            }
        system("CLS");
        afisezOptiuniStergere();
    }
}

void schimbNumeClasa(){
    scriuNumeleGrupelor();
    cout<<"Alege clasa ";
    int i;cin>>i;cin.get();
    cout<<endl<<"Scrie noul nume ";
    char st[45];cin.get(st,45);cin.get();
    setNumeClasa(st,cl[i]);

    }

void schimbDataUneiGrupe(){
    scriuNumeleGrupelor();
    cout<<"Alege clasa ";
    int i;cin>>i;cin.get();
    cout<<"Vechea data era pe "<<cl[i].dn.zi<<"."<<cl[i].dn.luna<<"."<<cl[i].dn.an<<endl;
    cout<<"Doresti sa o schimbi?(y/n)";
    char s;cin>>s;cin.get();
    if(tolower(s)=='y'){
        char st[30];
        cout<<"Introdu noua data dd.mm.yyyy ";cin.get(st,29);cin.get();
        setData(st,cl[i]);

    }

}

void modificOra(){
    scriuNumeleGrupelor();
    cout<<"Carei grupe doresti sa schimbi ora? ";
    int i;cin>>i;cin.get();
    cout<<"Introdu noua ora ";
    char k[4];cin>>k;cin.get();
    setOra(k,cl[i]);
    }

void adaugScoala(){
    system("CLS");
    scriuNumeleGrupelor();
    cout<<"In ce grupa se afla elevul? "<<endl;
    int i;cin>>i;cin.get();
    afisezEleviiClasei(i);
    cout<<"Carui elev doresti sa schimbi scoala? "<<endl;int k;cin>>k;cin.get();
    cout<<"Pune numele noii scoli ";char st[50];cin.get(st,50);cin.get();
    setScoala(cl[i].el[k],st);
}

void afisezOptiuniModificare(){
    cout<<"1. Schimba nume clasa "<<endl;
    cout<<"2. Data unei grupe "<<endl;
    cout<<"3. Tipul "<<endl;
    cout<<"4. Tema "<<endl;
    cout<<"5. Scoala unui elev "<<endl;
    cout<<"6. Ora unei grupe "<<endl;
    cout<<"7. Back "<<endl;
    }

void afisezOptiuniAfisare(){
    system("CLS");
    cout<<"1. Afisez grupele "<<endl;
    cout<<"2. Elevii unei grupe "<<endl;
    cout<<"3. Back "<<endl;
}

void scriuSpatii(int nr){
    for(int i=1;i<=nr;i++)
        cout<<" ";
    }

void GasescLMaxime(){
    for(int i = 0;i<Stats.nrClase;i++){
        if(strlen(cl[i].nume)>Stats.lNumeCls)
            Stats.lNumeCls = strlen(cl[i].nume);

        if(strlen(cl[i].tip)>Stats.lTip)
            Stats.lTip = strlen(cl[i].tip);
        if(strlen(cl[i].tema)>Stats.lTema)
            Stats.lTema = strlen(cl[i].tema);

        for(int j=0;j<cl[i].nrElevi;j++){
            if(strlen(cl[i].el[j].nume)>Stats.lNumeElev)
                Stats.lNumeElev = strlen(cl[i].el[j].nume);

            if(strlen(cl[i].el[j].prenume)>Stats.lPrenume)
               Stats.lPrenume = strlen(cl[i].el[j].prenume) ;

            if(strlen(cl[i].el[j].scoala)>Stats.lScl)
                Stats.lScl = strlen(cl[i].el[j].scoala);


        }

    }
}
void afisezGrupelePeConsolaSimetricSiFrumos(){
    cout<<"Nume";
    scriuSpatii(Stats.lNumeCls-strlen("Nume"));
    cout<<"|"<<"Data";scriuSpatii(Stats.lData-strlen("Data"));cout<<"|";
    cout<<"Tip";scriuSpatii(Stats.lTip-strlen("Tip"));cout<<"|";
    cout<<"Tema";scriuSpatii(Stats.lTema-strlen("Tema"));cout<<endl;
    for(int i=0;i<Stats.nrClase;i++){
        cout<<cl[i].nume;
        scriuSpatii(Stats.lNumeCls-strlen(cl[i].nume));cout<<"|";
        if(cl[i].dn.zi<10)
            cout<<"0";
        cout<<cl[i].dn.zi<<".";
        if(cl[i].dn.luna<10)
            cout<<"0";
        cout<<cl[i].dn.luna<<"."<<cl[i].dn.an<<"|";
        cout<<cl[i].tip;
        scriuSpatii(Stats.lTip-strlen(cl[i].tip));
        cout<<"|";
        cout<<cl[i].tema;
        scriuSpatii(Stats.lTema-strlen(cl[i].tema));cout<<endl;


    }
    system("PAUSE");
    system("CLS");
}

void afisezEleviiClaseiFrumyx(int poz){
    system("CLS");
    cout<<"Nume si prenume";
    scriuSpatii(Stats.lNumeElev + Stats.lPrenume - strlen("Nume si prenume")+1);
    cout<<"|";cout<<"Scoala";scriuSpatii(Stats.lScl - strlen("Scoala"));cout<<"|";
    cout<<"Note"<<endl;
    for(int i=0;i<cl[poz].nrElevi;i++){
            cout<<cl[poz].el[i].nume<<" "<<cl[poz].el[i].prenume;
            scriuSpatii((Stats.lNumeElev+Stats.lPrenume) - (strlen(cl[poz].el[i].nume)+strlen(cl[poz].el[i].prenume)));cout<<"|";
            cout<<cl[poz].el[i].scoala;
            scriuSpatii(Stats.lScl-strlen(cl[poz].el[i].scoala));
            cout<<"|";
            for(int j=0;j<cl[poz].el[i].nrNote;j++)
                cout<<cl[poz].el[i].note[j]<<" ";
            cout<<endl;
    }
    system("PAUSE");
}

void afisezELeviiClaseiAseaFrumosSaLaLa(){
    cout<<"Carei clase apartine elevul?";cout<<endl;
    scriuNumeleGrupelor();cout<<"Da Pozitia clasei ";
    int i;cin>>i;cin.get();
    afisezEleviiClaseiFrumyx(i);
    }

void optiuniModificare(){
    system("CLS");
    afisezOptiuniModificare();
    cout<<"Alege optiune ";int i;
    while(i!=7){
        system("CLS");
        afisezOptiuniModificare();
        cout<<"Alege optiunea ";
        cin>>i;cin.get();
        switch(i){
            case 1: schimbNumeClasa();break;
            case 2: schimbDataUneiGrupe();break;
            case 3: adaugTip();break;
            case 4: adaugTema();break;
            case 5: adaugScoala();break;
            case 6: modificOra();break;
            case 7:break;
            }


    }


    }

void optiuniAfisare(){
    GasescLMaxime();
    cout<<"Ce doresti sa afisezi?"<<endl;
    int i=0;
    while(i!=3){
        switch (i){
            case 1: afisezGrupelePeConsolaSimetricSiFrumos();break;
            case 2: afisezELeviiClaseiAseaFrumosSaLaLa();break;
            case 3:break;
        }

        afisezOptiuniAfisare();
        cin>>i;cin.get();
        system("CLS");


    }
}

int stergDateInvalide(){
    int ok=1;
    for(int i=0;i<Stats.nrClase;i++){
            if(DeterminDataMaiMare(&cl[i].dn, &Stats.dnstats) <= 0){
                setData("00.00.0000",cl[i]);
                setOra("00",cl[i]);
                ok=0;
            }

    }
    return ok;
}

void gasescDataMinima(Data *Temp){
        Temp->an = 100000;
        Temp->luna = 100000;
        Temp->zi = 1000000;
        for(int i=0;i<Stats.nrClase;i++){
            if(cl[i].dn.an!=0 &&DeterminDataMaiMare(&cl[i].dn,Temp)==-1){
                    Temp->an = cl[i].dn.an;
                    Temp->luna = cl[i].dn.luna;
                    Temp->zi = cl[i].dn.zi;
                    Temp-> ora= cl[i].dn.ora;
               }
        }
}
int gasescDateleInvalide(){
    int nr=0;
    for(int i=0;i<Stats.nrClase;i++)
        if(cl[i].dn.an == 0)
            nr++;
    return nr;
}

void Menu(){
    cout<<"Organizator al grupelor cu baza de date al elevilor si sistem de alerta in caz de intercalare al orelor "<<endl<<"si cu instiinare cu cea mai apropiata grupa"<<endl;
    cout<<"Hyrica industries ltd @2018"<<endl;
    system("PAUSE");
    system("CLS");
    //nu merge ctime.h ypu should fix that somehow
    int i=123;

    while(i!=5){
        system("CLS");
        iauDataCurenta(&Stats);
        if(stergDateInvalide()==0){
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 12);
            cout<<"Ai "<<gasescDateleInvalide()<<" clase de au data invalida!!!!";cout<<endl;
            SetConsoleTextAttribute(hConsole, 15);
        }

        if(Stats.nrClase==0){
            cout<<"Nu ai grupe introduse "<<endl;
        }else{
            cout<<"Urmatoarea grupa este programata pe data de ";
            Data statisticaTemp;
            gasescDataMinima(&statisticaTemp);
            if(statisticaTemp.zi<10)
                cout<<"0";
            cout<<statisticaTemp.zi<<".";
            if(statisticaTemp.luna<10)
                cout<<"0";
            cout<<statisticaTemp.luna;
            cout<<"."<<statisticaTemp.an<<" la ora "<<statisticaTemp.ora<<endl;

        }
        cout<<"1.optiuni adaugare "<<endl;
        cout<<"2.optiuni stergere "<<endl;
        cout<<"3.optiuni modificare "<<endl;
        cout<<"4.optiuni afisare "<<endl;
        cout<<"5. iesire "<<endl;
        cout<<"Da optiune ";cin>>i;cin.get();


        switch (i){
            case 1: optiuniAdaugare();break;
            case 2: optiuniStergere();break;
            case 3: optiuniModificare();break;
            case 4: optiuniAfisare();break;
            case 5:break;
        }


    }
}


int main()
{
    IncarcFisier();
    Menu();
    SalveazaFisier();

}
