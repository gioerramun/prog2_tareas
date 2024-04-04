#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TPieza pieza;
    TColeccionPiezas sig;
};

TColeccionPiezas crearColeccionPiezasVacia(){
    TColeccionPiezas coleccion = new rep_coleccionpiezas;
    coleccion->pieza = NULL;
    coleccion->sig = NULL;
    return coleccion;
}

void insertarPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza pieza){
    TColeccionPiezas tmp = new rep_coleccionpiezas;
    tmp->pieza = pieza;
    tmp->sig = NULL;

    TColeccionPiezas recorrer = coleccionPiezas;
    while ((recorrer->pieza != NULL) && (recorrer->sig != NULL) && (idTPieza(pieza) > idTPieza(recorrer->pieza)))
    {
        recorrer = recorrer->sig;
    }
    
    if (recorrer->pieza == NULL) {
        recorrer = tmp;
    } else {
        tmp->sig = recorrer->sig;
        recorrer = tmp;
    }
}

void imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas){
    TColeccionPiezas recorrer = coleccionPiezas;
    while (recorrer->pieza != NULL)
    {
        imprimirTPieza(recorrer->pieza);
        recorrer = recorrer->sig;
    }
}

bool esVaciaColeccionPiezas(TColeccionPiezas piezas){
    return piezas->pieza == NULL;
}

bool existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    return true;
}

TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    return NULL;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
   
}

void liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    while (coleccionPiezas->pieza != NULL)
    {
        liberarTPieza(coleccionPiezas->pieza);
    }
    delete coleccionPiezas;
    coleccionPiezas = NULL;
}