/* 
        Curso Mastermind
        
    Tarea:
    Busca Amigos
*/

#ifndef ARBOL_PERSONAS_H
#define ARBOL_PERSONAS_H

// Define las estructuras Persona y NodoArbol
typedef struct {
    char nombre[50];
    char aficion[50];
} Persona;

typedef struct NodoArbol {
    Persona persona;
    struct NodoArbol* rama1;
    struct NodoArbol* rama2;
    struct NodoArbol* rama3;
} NodoArbol;

// Prototipos de las funciones
NodoArbol* agregarPersona(NodoArbol* raiz, Persona persona);
void imprimirArbol(NodoArbol* raiz, int nivel);
void liberarArbol(NodoArbol* raiz);
void encontrarAficionesComunes(NodoArbol* raiz, const char* aficionBuscada);

#endif // ARBOL_PERSONAS_H
