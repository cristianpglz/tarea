/* 
        Curso Mastermind
        
    Tarea:
    Busca Amigos
*/

// Inclusiones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbol_Personas.h"

//Comienzo del Codigo
// Función para agregar una persona al árbol y Estructurar las Ramas
void EstructuraArbol();
//Agregar Persona al Arbol
NodoArbol* agregarPersona(NodoArbol* raiz, Persona persona) {
    NodoArbol* nuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    if (nuevoNodo == NULL) {
        printf("\nError: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }

    strcpy(nuevoNodo->persona.nombre, persona.nombre);
    strcpy(nuevoNodo->persona.aficion, persona.aficion);
    nuevoNodo->rama1 = NULL;
    nuevoNodo->rama2 = NULL;
    nuevoNodo->rama3 = NULL;

    if (raiz == NULL) {
        return nuevoNodo;
    }

    // Agregar el nuevo nodo alternativamente a las tres ramas del nodo raíz
    if (raiz->rama1 == NULL) {
        raiz->rama1 = nuevoNodo;
    } else if (raiz->rama2 == NULL) {
        raiz->rama2 = nuevoNodo;
    } else if (raiz->rama3 == NULL) {
        raiz->rama3 = nuevoNodo;
    } else {
        // Si todas las ramas están ocupadas, pasa al siguiente nivel del árbol
        raiz->rama1 = agregarPersona(raiz->rama1, persona);
    }

    return raiz;
}

// Función para imprimir el árbol (solo para fines de visualización)
void imprimirArbol(NodoArbol* raiz, int nivel) {
    if (raiz == NULL) {
        return;
    }

    printf("\nNivel %d: %s - %s\n", nivel, raiz->persona.nombre, raiz->persona.aficion);
    imprimirArbol(raiz->rama1, nivel + 1);
    imprimirArbol(raiz->rama2, nivel + 1);
    imprimirArbol(raiz->rama3, nivel + 1);
}

// Función para liberar la memoria del árbol
void liberarArbol(NodoArbol* raiz) {
    if (raiz == NULL) {
        return;
    }

    // Llamamos a la función para las ramas del nodo actual
    liberarArbol(raiz->rama1);
    liberarArbol(raiz->rama2);
    liberarArbol(raiz->rama3);

    // Liberamos la memoria del nodo actual
    free(raiz);
}

// Función para encontrar personas con la misma afición en el árbol
void encontrarAficionesComunes(NodoArbol* raiz, const char* aficionBuscada) {
    if (raiz == NULL) {
        return;
    }

    // Comparamos la afición de la persona en el nodo actual con la afición buscada
    if (strcmp(raiz->persona.aficion, aficionBuscada) == 0) {
        printf("\nPersona con la misma aficion encontrada: %s\n", raiz->persona.nombre);
    }

    // Llamamos a la función para las ramas del nodo actual
    encontrarAficionesComunes(raiz->rama1, aficionBuscada);
    encontrarAficionesComunes(raiz->rama2, aficionBuscada);
    encontrarAficionesComunes(raiz->rama3, aficionBuscada);
}
