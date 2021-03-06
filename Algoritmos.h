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
                    if((iter->ptrNext)==iter2){
                        casoFinal=true;
                    }
                }
            }
        }

        void Listar(ListaPosicionadaLSE Lista)
        {
            CajaS<A> *ptr=Lista.Primera();
            while(ptr!=nullptr)
            {
                std::cout<<ptr->elemento<<" ";
                ptr=ptr->ptrNext;
            }
            //std::cout<<std::endl;
        }

        bool Simetrica(ListaPosicionadaLSE Lista){
            CajaS<A> *iter=Lista.Primera();
            CajaS<A> *iter2=Lista.Ultima();
            if((Lista.NumElem()%2)!=0){
                while(iter!=iter2){
                    if(iter->elemento != iter2->elemento)
                        return false;
                    iter=iter->ptrNext;
                    iter2=Lista.Anterior(iter2);
                }
            }else{
                bool casoFinal=false;
                while(!casoFinal){
                    if(iter->elemento != iter2->elemento)
                        return false;
                    iter=iter->ptrNext;
                    iter2=Lista.Anterior(iter2);
                    if((iter->ptrNext)==iter2){
                        casoFinal=true;
                    }
                }
            }
            return true;
        }

        bool BuscarElem(ListaPosicionadaLSE Lista, A elemento){
            CajaS<A> *iter=Lista.Primera();
            while(iter!=nullptr){
                if(Lista.Recuperar(iter) == elemento){
                    return true;
                }
                iter=Lista.Siguiente(iter);
            }
            return false;
        }

        void EliminarRepetidos(ListaPosicionadaLSE Lista)
        {
            CajaS<A> *ptr1=Lista.Primera();
            CajaS<A> *ptr2;
            while(ptr1->ptrNext!=nullptr)
            {
                ptr2=ptr1->ptrNext;
                while(ptr2!=nullptr)
                {
                    if(ptr1->elemento == ptr2->elemento)
                        Lista.Borrar(ptr2);
                    ptr2=ptr2->ptrNext;
                }
                ptr1=ptr1->ptrNext;
            }
        }

        bool Sublista(ListaPosicionadaLSE Lista1, ListaPosicionadaLSE Lista2){
            if(Lista2.NumElem()>Lista1.NumElem()){
                return false;
            }
            bool esElem=false;
            CajaS<A> *iter1=Lista1.Primera();
            CajaS<A> *iter2=Lista2.Primera();
            while(iter2!=nullptr){
                while(iter1!=nullptr){
                    if(Lista1.Recuperar(iter1)==Lista2.Recuperar(iter2)){
                        esElem=true;
                    }
                    iter1=Lista1.Siguiente(iter1);
                }
                if(!esElem){
                    return false;
                }else{
                    esElem=false;
                }
                iter2=Lista2.Siguiente(iter2);
            }
            return true;
        }

        bool DosListasIguales(ListaPosicionadaLSE L1, ListaPosicionadaLSE L2)
        {
            if(L1.NumElem()!= L2.NumElem())
                return false;

            CajaS<A> *ptr1=L1.Primera();
            CajaS<A> *ptr2;
            bool coincidencia;
            while(ptr1!=nullptr)
            {
                coincidencia=false;
                ptr2=L2.Primera();
                while(ptr2!=nullptr && !coincidencia)
                {
                    if(ptr1->elemento == ptr2->elemento)
                        coincidencia=true;
                    ptr2=ptr2->ptrNext;
                }
                if(!coincidencia)
                    return false;
                ptr1=ptr1->ptrNext;
            }
            return true;

        }
        Algoritmos(){}
        virtual ~Algoritmos(){}

    protected:

    private:
};

#endif // ALGORITMOS_H
