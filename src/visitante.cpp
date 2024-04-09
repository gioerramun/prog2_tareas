#include "../include/visitante.h"

// En esta sección se implementará el módulo visitante.cpp. 
// Cada elemento del tipo visitante almacenará un
// id, la edad, su nombre y apellido

// 1. Implemente la representación de visitante rep_visitante y 
// las funciones crearTVisitante, imprimirTVisitante y liberarTVisitante. 
// Tenga en cuenta que el formato de impresión se especifica en visitante.h.
// Ejecute el caso de prueba visitante1-crear-imprimir-liberar para verificar el 
// funcionamiento de las operaciones. Foro de dudas.

// 2. Implemente las funciones idTVisitante, nombreTVisitante, apellidoTVisitante 
// y edadTVisitante. Ejecute el test visitante2-id-nombre-apellido-edad para 
// verificar las funciones. Foro de dudas.

// 3. Implemente la función copiarTVisitante. Ejecute el test visitante3-copiar 
// para verificar la función. Ejecute el test visitante4-combinado Foro de dudas.


struct rep_visitante {
    int id;
    int edad;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
};

TVisitante crearTVisitante(int id, const char nombre[MAX_NOMBRE], const char apellido[MAX_APELLIDO], int edad){
    TVisitante visitante = new rep_visitante;
    visitante->id = id;
    visitante->edad = edad;
    strcpy(visitante->nombre, nombre);
    strcpy(visitante->apellido, apellido);
    return visitante;
}

void nombreTVisitante(TVisitante visitante, char nombre[MAX_NOMBRE]){
    strcpy(nombre, visitante->nombre);
}

void apellidoTVisitante(TVisitante visitante, char apellido[MAX_APELLIDO]){
    strcpy(apellido, visitante->apellido);
}

int idTVisitante(TVisitante visitante){
    return visitante->id;
}

int edadTVisitante(TVisitante visitante){
    return visitante->edad;
}

void liberarTVisitante(TVisitante &visitante){
    delete visitante;
    visitante = NULL;
}

TVisitante copiarTVisitante(TVisitante visitante){
    TVisitante copiaVisitante = new rep_visitante;
    copiaVisitante->id = visitante->id;
    copiaVisitante->edad = visitante->edad;
    strcpy(copiaVisitante->nombre, visitante->nombre);
    strcpy(copiaVisitante->apellido, visitante->apellido);
    return copiaVisitante;
}

void imprimirTVisitante(TVisitante visitante){
    printf("Visitante %s %s\n", visitante->nombre, visitante->apellido);
    printf("Id: %d\n", visitante->id);
    printf("Edad: %d\n", visitante->edad);
}

