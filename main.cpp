#include <iostream>

using namespace std;

struct carte
{
    int cod;
    string autor;
    string nume;
    int an;
    bool imprumut;
};

struct persoana
{
    string nume;
    int indexcarti[100];
};

carte *citesteDetaliiCarte(){
    carte *rezultat=new carte;
    cout<<endl<<"###Carte noua###"<<endl;
    cout<<"Introduceti codul de identificare: ";
    cin>>rezultat->cod;
    cout<<"Introduceti autorul: ";
    cin>>rezultat->autor;
    cout<<"Introduceti numele cartii: ";
    cin>>rezultat->nume;
    cout<<"Introduceti anul publicatiei: ";
    cin>>rezultat->an;
    rezultat->imprumut=0;
    return rezultat;
}

int adaugare(carte *biblioteca[],int dimensiune){
    //Cautarea primului loc liber din biblioteca
    int index,i;
    for(i=0;i<dimensiune;i++)
        if(biblioteca[i]==NULL) {
        index=i;
        break;
    }
    if(i==dimensiune)
    {
            cout<<endl<<"###Nu mai sunt locuri libere!"<<endl;
            return 0;
    }
    biblioteca[index]=citesteDetaliiCarte();
    cout<<endl<<"Indexul este: "<<index+1<<endl;
    return 1;
}

void stergere(carte *biblioteca[],int dimensiune){
    cout<<endl<<"###Stergere carte###"<<endl;
    int loc;
    cout<<endl<<"Care este numarul de ordine al cartii in biblioteca?"<<endl;
    cin>>loc;
    loc--;
    if((loc+1)>dimensiune){
    cout<<"Locul nu exista in biblioteca";
    } else {
        if(biblioteca[loc]==NULL){
         cout<<endl<<"Locul este deja liber" << endl;
        } else {
            delete biblioteca[loc];
            biblioteca[loc]=NULL;
        }
    }
}

void listeazaDetalii(carte *book)
{
        cout<<"Cod: "<<book->cod<<endl;
        cout<<"Autor: "<<book->autor<<endl;
        cout<<"Nume: "<<book->nume<<endl;
        cout<<"An: "<<book->an<<endl;
        cout<<"Imprumutat(0/1): "<<book->imprumut<<endl;
}

/*void initializare(carte *book)
{
    book->cod=NULL;
    book->an=NULL;
    book->autor="";
    book->nume="";
    book->imprumut=NULL;
}
*/

void listeaza(carte *biblioteca[],int dimensiune){
    for(int i=0;i<dimensiune;i++)
    {
        cout<<endl<<"#Carte "<<i+1<<" :"<<endl;
        if(biblioteca[i]!=NULL){
        listeazaDetalii(biblioteca[i]);
        } else {
            cout<< "N/A"<<endl;
        }
    }
}

void listeazaID(carte *biblioteca[],int dimensiune){
    cout<<endl<<"###Listeaza carte dupa cod-ID###"<<endl;
    int id;
    bool gasit=0;
    cout<<endl<<"Care este codul de identificare-ID cartii?"<<endl;
    cin>>id;
    for(int i=0;i<dimensiune;i++) {
            if(biblioteca[i]!=NULL) {
                if(biblioteca[i]->cod==id) {
                listeazaDetalii(biblioteca[i]);
                gasit =1;
            }
        }
    }
    if(!gasit) cout << endl << "Codul de identificare-ID NU a fost gasit" << endl;
}

int imprumut(carte *biblioteca[],persoana oameni[],int dimensiune,int dimensiune1){
    persoana human;
    int cod1;
    bool omgasit=0;
    int pozitie;
    cout<<endl<<"Introduceti numele persoanei care imprumuta cartea: "<<endl;
    cin>>human.nume;

    for(int i=0;i<dimensiune1;i++)
        if(oameni[i].nume==human.nume) {
            omgasit=1;
            pozitie=i;
        }

    if(omgasit) {
            cout<<"Introduceti codul cartii imprumutate: ";
            cin>>cod1;
            for(int i=0;i<dimensiune;i++){
                    if(biblioteca[i]!=NULL) { //Nu am pointer initializat, n-am nici cod
                        if(biblioteca[i]->cod==cod1){
                                    for(int j=0;j<100;j++){
                                        if(biblioteca[i]->imprumut) {
                                                cout << "Carte deja inregistrata ca fiind deja imprumutata";
                                                return 0;
                                        }
                                        if(oameni[pozitie].indexcarti[j]==0) {
                                            oameni[pozitie].indexcarti[j]=cod1;
                                            cout << endl <<"###Am adaugat in " << oameni[pozitie].indexcarti[j];
                                            biblioteca[i]->imprumut=1;
                                            return 1;
                            }
                        }
                    }
                }
            }
            cout<<"Codul nu exista";return 0;
    } else {
        cout<<endl<<"Persoana nu a fost inregistrata!";return 0;
    }
}

void infopersoana(persoana oameni[],int dimensiune,carte *biblioteca[])
    {
        string name;
        bool gasit=0;
        int index;
        cout << endl << "Numele persoanei cautate este: "<<endl;
        cin>>name;
        for(int i=0;i<dimensiune;i++) {
            if(oameni[i].nume==name) {
                    cout<<name<<" a imprumutat cartile cu urmatoarele ID-uri: "<<endl;
                for(int j=0;j<100;j++) {
                    if(oameni[i].indexcarti[j]) {
                        //cout << i << "-" << j << ":" << endl;
                        cout << "# " <<oameni[i].indexcarti[j] << endl;
                       // listeazaDetalii(biblioteca[oameni[i].indexcarti[j]]);
            }
        }
    }
  }
}
int main()
{
cout<<"***Bun venit la Biblioteca!***\n";
cout <<"Introduceti dimensiunea bibliotecii "<<"(numarul maxim de carti suportate):\n";

int i,size;
cin>>size;
carte **biblioteca;
biblioteca=new carte*[size];

for(int i=0;i<size;i++){
    biblioteca[i]=NULL;
}

int size1;
cout <<"Introduceti numarul de persoane ca vin la biblioteca:";
cin >> size1;
persoana *persoane;
persoane=new persoana[size1];

for(int i=0;i<size1;i++){
    for(int j=0;j<100;j++){
        persoane[i].indexcarti[j]=0;
        }
    persoane[i].nume="";
}

for(int i=0;i<size1;i++){
    cout<<"Nume persoana: "<<i+1<<" :";
    cin>>persoane[i].nume;
}

cout << endl << "Vizitatorii bibliotecii sunt: " << endl;
for(int i=0;i<size1;i++) {
    for(int j=0;j<100;j++) {
        persoane[i].indexcarti[j]=0;
    }
    cout<<"#"<<i+1<<" :"<<persoane[i].nume<<endl;
}

char op;
    do {
        cout<<endl;
        cout <<endl<< "Introduceti optiune: " << endl;
        cout << " A - Adauga carte" << endl;
        cout << " L - Listeaza cartile din biblioteca" << endl;
        cout << " E - Elimina o carte" << endl;
        cout << " I - Imprumutul de carte"<<endl;
        cout << " C - Listeaza informatii despre o carte dupa cod-ID " << endl;
        cout << " P - Listarea informatiilor despre o persoana " << endl;
        cout << " Q - Inchide aplicatia" << endl;
        cin>>op;

        switch(op) {
        case 'A': adaugare(biblioteca,size); break;
        case 'L': listeaza(biblioteca,size); break;
        case 'E': stergere(biblioteca,size); break;
        case 'I': if(imprumut(biblioteca,persoane,size,size1)) cout << endl << "AM ADAUGAT!" << endl; break;
        case 'C': listeazaID(biblioteca,size); break;
        case 'P': infopersoana(persoane,size1,biblioteca); break;
        case 'Q': cout << "Inchide aplicatie" << endl; break;
        default: cout<< "Optiune invalida" <<endl; break;
        }
    } while (op!= 'Q');
return 0;
}
