# Digital-library-in-C++-
O biblioteca poate contine mai multe carti. Despre fiecare carte se vor cunoaste cel putin
urmatoarele informatii: cod identificare (int), autor(string), nume(string), an publicatie(int).
Obs: Puteti adauga si alte informatii daca sunteti de parare ca este necesar.
Cartile pot fi imprumutate de catre persoane. O persoana este identificata prin nume(string)
Aplicatia va trebui sa permita urmatoarele operatii:
● A - Adaugarea unei carti in biblioteca 
  ○ Se citesc de la tastatura detaliile cartii (id, autor, nume, an publicatie)
● L - Listarea tuturor cartilor din biblioteca 
● E - Eliminarea unei carti din bibilioteca
  ○ Se citeste de la tastatura id-ul cartii ce trebuie eliminata
● I - Imprumutul unei carti catre o persoana 
  ○ Se citeste de la tastatura id-ul cartii si numele persoanei ce o imprumuta
● C - Listarea informatiilor despre o carte (nume, autor, an, daca a fost imprumutata) 
  ○ Se citeste de la tastatura id-ul cartii
● P - Listarea informatiilor despre o persoana (Ce carti a imprumutat) 
  ○ Se citeste de la tastatura numele persoanei

Am scris proiectul avand in vedere urmatoarele aspecte:

● Citirea de la tastatura a dimensiunii bibliotecii (numarul maxim de carti suportate)
● Alocarea dinamica a bibliotecii
● Alocarea dinamica a fiecarei carti din biblioteca in parte 
● Am folosit o structura pentru a retine informatiile despre carti
● Modalitate prin care se identifica daca o carte este imprumutata - bool
● O biblioteaca este privita ca un array de carti
