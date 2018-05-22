#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include "ListaPosicionadaLSE.h"
#include "CajaS.h"

template <class A>
class Algoritmos
{
    public:
        void invertir(ListaPosicionadaLSE Lista){
            CajaS<A> *iter=Lista.Primera();
            CajaS<A> *iter2=Lista.Ultima();
            if((Lista.NumElem()%2)!=0){
                while(iter!=iter2){
                    Lista.Intercambiar(iter, iter2);
                    iter=iter->ptrNext;
                    iter2=Lista.Anterior(iter2);
                }
            }else{
                bool casoFinal=false;
                while(!casoFinal){
                    Lista.Intercambiar(iter, iter2);
                    iter=iter->ptrNext;
                    iter2=Lista.Anterior(iter2);
                    if((iter->ptrSig)==iter2){
                        casoFinal=true;
                    }
                }
            }
        }
        Algoritmos(){}
        virtual ~Algoritmos(){}

    protected:

    private:
};

#endif // ALGORITMOS_H
