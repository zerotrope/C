#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hr = 14;
    int ms = 78;
    int ss = 182;

    printf("Hello world!\n");
    hello();
    conversion(&hr,&ms,&ss);
    printf("Heures:%i  Minutes:%i  Secondes:%i  ", hr, ms, ss);

    /*int toto = 8;
    printf("toto = %i\n",toto);
    printf("Adresse de toto = %x\n",&toto);
    int *ptoto;
    ptoto = &toto;
    printf("ptoto = %x\n",ptoto);
    printf("Adresse de ptoto = %x\n",&ptoto);
    *ptoto = 5;
    printf("Valeur du pointeur pointe par ptoto = %i\n",*ptoto);
    printf("toto = %i\n",toto);*/


    return 0;   // convention pour signaler fin d'un code : "Process terminated with status 0"
}

void hello()
{
    printf("Salut!\n");
}

int conversion(int *h,int *m,int *s)
{
    int c = 32;
    *h = *s/3600 + *m/60 + *h;
    *m = *s/60 + *m%60;
    *s = *s%60;
    //*m = *m + c;
    m = m + 250;                // pointeur suivant accédant à *
    *m = *m + 1;                // itère sur la valeur pointée
    return(s);
}
