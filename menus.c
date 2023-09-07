/* 
        Curso Mastermind
        
    Tarea:
    Busca Amigos
*/

// Inclusiones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"

//Comienzo del Codigo

//Menu Comienzo 
void MenuInicio(NodoArbol** raiz) {
    printf("<=== Programa Buscador de Amigos ===>\n");
    printf("\nBienvenido al Buscador de Amigos.\n-Con este programa,puedes agregar personas ");
    printf("con sus aficiones al\narbol y buscar personas con la misma aficion.\n");
    printf("\nSelecciona una opcion:\n");
    printf("\n1. Ingresar personas y buscar aficiones comunes.\n");
    printf("2. Salir del programa.\n");
    printf("\nNumero Opcion: ");
    
    int opcion;
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            IngresarPersonas(raiz);
            MenuFin(raiz);
            break;
        case 2:
            printf("\nGracias por usar el Buscador de Amigos.\n");
            exit(0);
        default:
            printf("\nOpcion no valida. Introduce una opcion valida.\n");
            MenuInicio(raiz);
    }
}


//Menu Ingresar Personas
void IngresarPersonas(NodoArbol** raiz) {
    int continuar = 1; // Variable para controlar si se agregan más personas
    char resultado[2]; // Cambiamos la declaración de resultado a un arreglo de caracteres
    Persona persona;

    while (continuar) {
        // Solicitamos al usuario que ingrese el nombre y la afición de la persona
        printf("\nIngrese el nombre de la persona: ");
        scanf("%s", persona.nombre); // Suponemos que el nombre no contiene espacios
        printf("\nIngrese la aficion de la persona: ");
        scanf("%s", persona.aficion); // Suponemos que la afición no contiene espacios

        // Llamamos a la función para agregar la persona al árbol
        *raiz = agregarPersona(*raiz, persona);

        // Preguntamos al usuario si desea agregar más personas
        printf("\n¿Desea agregar mas personas?\n");
        printf("\n1: Sí\n");
        printf("2: No\n");
        printf("\nNumero Opcion: ");
        scanf("%s", resultado);

        if (strcmp(resultado, "1") == 0) {
            continuar = 1; // Continuar agregando personas
        } else if (strcmp(resultado, "2") == 0) {
            continuar = 0; // Terminar el bucle si la respuesta es "2"
        } else {
            printf("Ingresa una respuesta valida\n");
            continuar = 1; // Mantener el bucle para repetir la pregunta
        }
    }

    // Luego de que el usuario termine de agregar personas
    printf("Buscar personas con la misma aficion:\n");
    char aficionBuscada[50]; // La afición que deseas buscar
    printf("Ingrese la aficion que desea buscar: ");
    scanf("%s", aficionBuscada);

    encontrarAficionesComunes(*raiz, aficionBuscada); // Pasar *raiz
}


//Menu Final Programa
void MenuFin(NodoArbol** raiz) {
    printf("\nAcciones disponibles:\n");
    printf("\n1. Ingresar mas personas al arbol.\n");
    printf("2. Borrar todo el arbol y empezar de nuevo.\n");
    printf("3. Buscar personas con la misma aficion.\n"); 
    printf("4. Salir del programa.\n");
    printf("\nNumero de opcion: ");
    
    int opcion;
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            IngresarPersonas(raiz);
            MenuFin(raiz);
            break;
        case 2:
            // Lógica para borrar el árbol y empezar de nuevo
            liberarArbol(*raiz); // Limpia el árbol actual
            *raiz = NULL; // Reinicia el árbol
            MenuFin(raiz);
            break;
        case 3:
            // Lógica para buscar personas con la misma afición
            printf("\nBuscar personas con la misma aficion:\n");
            char aficionBuscada[50]; // La afición que deseas buscar
            printf("\nIngrese la aficion que desea buscar: ");
            scanf("%s", aficionBuscada);
            encontrarAficionesComunes(*raiz, aficionBuscada);
            MenuFin(raiz);
            break;
        case 4:
            printf("\nGracias por usar el Buscador de Amigos.\n");
            exit(0);
        default:
            printf("\nOpcion no valida. Introduce una opcion valida.\n");
            MenuFin(raiz);
    }
}