#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TPieza pieza;
    TColeccionPiezas sig;
};

TColeccionPiezas crearColeccionPiezasVacia(){
    return NULL;
}

void insertarPiezaAlPrincipio(TColeccionPiezas &coleccionPiezas, TPieza pieza){
    TColeccionPiezas tmp = new rep_coleccionpiezas;
    tmp->pieza = pieza;
    tmp->sig = coleccionPiezas;
    coleccionPiezas = tmp;
}

void insertarPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza pieza){
    if (coleccionPiezas == NULL) insertarPiezaAlPrincipio(coleccionPiezas, pieza);
    else {
        if (idTPieza(pieza) < idTPieza(coleccionPiezas->pieza)) insertarPiezaAlPrincipio(coleccionPiezas, pieza);
        else insertarPiezaColeccionPiezas(coleccionPiezas->sig, pieza);
    }
}

void imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas){
    TColeccionPiezas recorrer = coleccionPiezas;
    while (recorrer != NULL)
    {
        imprimirTPieza(recorrer->pieza);
        recorrer = recorrer->sig;
    }
}

bool esVaciaColeccionPiezas(TColeccionPiezas piezas){
    return piezas == NULL;
}

bool existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    TColeccionPiezas recorrer = coleccionPiezas;
    bool existe = false;
    while ((recorrer != NULL) && !existe) {
        existe = idTPieza(recorrer->pieza) == idPieza;
        recorrer = recorrer->sig;
    }
    return existe;
}

TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    TColeccionPiezas recorrer = coleccionPiezas;

    while ((recorrer != NULL) && (idPieza != idTPieza(recorrer->pieza))) {
        recorrer = recorrer->sig;
    }

    return recorrer->pieza;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
    if (idTPieza(coleccionPiezas->pieza) != idPieza) removerPiezaColeccionPiezas(coleccionPiezas->sig, idPieza);
    else {
        TColeccionPiezas tmp = coleccionPiezas;
        coleccionPiezas = coleccionPiezas->sig;
        liberarTPieza(tmp->pieza);
        delete tmp;
        tmp = NULL;
    }
}

void liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    TColeccionPiezas recorrer = coleccionPiezas;
    while (recorrer != NULL){
        TColeccionPiezas tmp = recorrer;
        recorrer = recorrer->sig;
        liberarTPieza(tmp->pieza);
        delete tmp;
        tmp = NULL;
    }
    coleccionPiezas = NULL;
}