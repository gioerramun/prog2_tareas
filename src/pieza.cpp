#include "../include/pieza.h"

struct rep_pieza {
    int identificador;
    char nombrePieza[MAX_NOMBRE_PIEZA];
    char nombreAutor[MAX_NOMBRE_AUTOR];
    char apellidoAutor[MAX_APELLIDO_AUTOR];
    TFecha fecha;
};

TPieza crearTPieza(int identificador, const char nombrePieza[MAX_NOMBRE_PIEZA], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], TFecha fechaCreacion){
    TPieza pieza = new rep_pieza;
    pieza->identificador = identificador;
    strcpy(pieza->nombrePieza, nombrePieza);
    strcpy(pieza->nombreAutor, nombreAutor);
    strcpy(pieza->apellidoAutor, apellidoAutor);
    pieza->fecha = fechaCreacion;
    
    return pieza;
}

int idTPieza(TPieza pieza){ 
    return pieza->identificador;
}

void imprimirTPieza(TPieza pieza){
    printf("Pieza: %d\n", pieza->identificador);
    printf("%s-%s %s\n", pieza->nombrePieza, pieza->nombreAutor, pieza->apellidoAutor);
    printf("Creada en: ");
    imprimirTFecha(pieza->fecha);
}

void liberarTPieza(TPieza &pieza){
    liberarTFecha(pieza->fecha);
    delete pieza;
    pieza = NULL;
}


