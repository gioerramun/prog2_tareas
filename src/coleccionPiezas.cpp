#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TPieza pieza;
    TColeccionPiezas sig;
};

TColeccionPiezas crearColeccionPiezasVacia(){
    return NULL;
}

// void insertarPiezaAlPrincipio(TColeccionPiezas &coleccionPiezas, TPieza pieza){
//     TColeccionPiezas tmp = new rep_coleccionpiezas;
//     tmp->pieza = pieza;
//     tmp->sig = coleccionPiezas;
//     coleccionPiezas = tmp;
// }

// void insertarPieza(TColeccionPiezas &coleccionPiezas, TPieza pieza){
//     if (coleccionPiezas == NULL) insertarPiezaAlPrincipio(coleccionPiezas, pieza);
//     else {
//         if (idTPieza(pieza) < idTPieza(coleccionPiezas->pieza)) insertarPiezaAlPrincipio(coleccionPiezas, pieza);
//         else insertarPieza(coleccionPiezas, pieza);
//     }
// }

void insertarPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza pieza){
    TColeccionPiezas tmp = new rep_coleccionpiezas;
    tmp->pieza = pieza;
    tmp->sig = NULL;

    if (coleccionPiezas == NULL) {
        coleccionPiezas = tmp;
    }
    else if (idTPieza(pieza) < idTPieza(coleccionPiezas->pieza)) {
        tmp->sig = coleccionPiezas;
        coleccionPiezas = tmp;
    }
    else {
        TColeccionPiezas recorrer = coleccionPiezas;
        while ((recorrer->sig != NULL) && (idTPieza(pieza) > idTPieza(recorrer->pieza)))
        {
            recorrer = recorrer->sig;
        }
        if (idTPieza(pieza) > idTPieza(recorrer->pieza))
        {
            recorrer->sig = tmp;
        }
        else
        {
            tmp->sig = recorrer->sig;
            recorrer->sig = tmp;
        }
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
    return true;
}

TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    return NULL;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
   
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