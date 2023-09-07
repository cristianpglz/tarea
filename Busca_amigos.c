/* 
        Curso Mastermind
        
    Tarea:
    Busca Amigos
    
Funcionamiento Basico:
Se trata de una aplicacion para el ingreso de nombres con aficiones,donde se almacenan en una estructura de Arbol/Ramas
que luego se puede comparar entre diferentes aficiones y encontrar varios nombres con las mismas.*/

// Inclusiones
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "Arbol_Personas.h"

//Comienzo del Codigo
int main() {
    // Inicializar Raíz
    NodoArbol* raiz = NULL;

    // Llamar al menú de inicio
    MenuInicio(&raiz);

    return 0;
}
