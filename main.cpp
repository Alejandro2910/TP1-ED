#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Algoritmos.h"
#include "ListaPosicionadaLSE.h"
#include "ListaPosicionadaLDE.h"
#include "ListaIndexadaLSE.h"
#include "ListaOrd_LSE.h"
#include "ListaOrd_Array.h"

using namespace std;

int main()
{
    ListaPosicionadaLSE l;
    l.Iniciar();
    l.Insertar(5,l.Primera());
    l.Insertar(8, l.Siguiente(l.Primera()));
    l.AgregarAlFinal(9);
    l.AgregarAlFinal(23);
    l.AgregarAlFinal(15);

    ListaPosicionadaLSE lp;
    lp.Iniciar();
    lp.Insertar(1, lp.Primera());
    lp.AgregarAlFinal(2);
    lp.AgregarAlFinal(9);
    lp.AgregarAlFinal(7);
    lp.AgregarAlFinal(8);

    ListaPosicionadaLSE lp2;
    lp2.Iniciar();
    lp2.Insertar(1, lp2.Primera());
    lp2.AgregarAlFinal(9);
    //lp2.AgregarAlFinal(9);
    //lp2.AgregarAlFinal(1);
    //lp2.AgregarAlFinal(5);

    cout<<"L= "; l.imprimir();
    Algoritmos<int> a;
    a.invertir(l);
    cout<<endl<<"\nL= "; a.Listar(l);
    cout<<endl<<"\nLp= "; a.Listar(lp);

    if(a.Simetrica(lp))
        cout<<"\nEs simetrica";
    else
        cout<<"\nNo simetrica";

    //a.EliminarRepetidos(lp);
    //cout<<endl<<"\nLp= "; a.Listar(lp);

    cout<<endl<<"\nLp= "; a.Listar(lp);
    cout<<endl<<"\nLp2= "; a.Listar(lp2);
    if(a.DosListasIguales(lp, lp2))
        cout<<"\nSon iguales";
    else
        cout<<"\nNo son iguales";

        if(a.BuscarElem(l, 167))
        cout<<"\nSi esta";
    else
        cout<<"\nNo esta";

        if(a.Sublista(lp, lp2))
        cout<<"\nSi es sub";
    else
        cout<<"\nNo es sub";
    return 0;
}
