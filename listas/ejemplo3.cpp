#include <stdio.h>  // Biblioteca estándar para funciones de entrada/salida como printf
#include <stdlib.h> // Biblioteca estándar para funciones de gestión de memoria dinámica como malloc y free

// Definición de la estructura de un nodo
struct node
{
    int key;             // Campo que almacena el valor del nodo
    struct node *next;   // Puntero que apunta al siguiente nodo en la lista
};

int main(){
    int n = 100; // Número inicial para crear la lista con valores del 1 al 100
    struct node *head = NULL, *newNode, *current; // Declaración de punteros para manejar la lista enlazada

    // Creación de la lista enlazada con los números del 1 al 100
    while (n >= 1) // Mientras n sea mayor o igual a 1
    {
        // Se reserva memoria para un nuevo nodo
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) { // Verificación de que malloc no devolvió NULL
            printf("Error al asignar memoria.\n");
            return 1; // Salida con error si no se pudo asignar memoria
        }

        newNode->key = n;   // Se asigna el valor actual de n al campo 'key' del nodo
        newNode->next = head; // El nuevo nodo apunta al nodo actual de la cabeza
        head = newNode;     // La cabeza de la lista ahora es el nuevo nodo
        n--;                // Se decrementa n para continuar con el siguiente número
    }
    
    // Mostrar la información de la lista enlazada
    current = head; // Inicializamos el puntero 'current' en la cabeza de la lista
    while(current != NULL) // Mientras no lleguemos al final de la lista
    {
        printf("%d -> ", current->key); // Imprimimos el valor del nodo actual
        current = current->next;        // Avanzamos al siguiente nodo
    }
    printf("NULL\n"); // Indicamos el final de la lista

    // Liberar la memoria de la lista enlazada
    while (head != NULL) // Mientras la cabeza no sea NULL
    {
        current = head;      // Guardamos la referencia al nodo actual
        head = head->next;   // Avanzamos la cabeza al siguiente nodo
        free(current);       // Liberamos la memoria del nodo actual
    }

    return 0; // Fin del programa
}
//crear lista con los numeros de 1 al 100
//mostrar la informacion de la lista
//liberar la memoria de la lista

/*
GitHub Copilot
Aquí tienes el código documentado con comentarios detallados para cada sección:

Explicación del flujo del programa:
Creación de la lista enlazada:

Se utiliza un bucle while para crear nodos dinámicamente con valores del 100 al 1.
Cada nodo se conecta al nodo anterior mediante el puntero next.
La cabeza de la lista (head) siempre apunta al nodo más reciente.
Mostrar la lista:

Se recorre la lista desde la cabeza hasta el final (NULL) utilizando un puntero auxiliar (current).
Durante el recorrido, se imprimen los valores de los nodos en orden.
Liberar memoria:

Se utiliza otro bucle while para liberar la memoria de cada nodo.
La cabeza de la lista se avanza al siguiente nodo antes de liberar el nodo actual.
Salida esperada:

Notas importantes:
Gestión de memoria: El programa utiliza malloc para asignar memoria dinámica y free para liberarla, evitando fugas de memoria.
Estructura de datos: Este programa implementa una lista enlazada simple, donde cada nodo tiene un valor entero y un puntero al siguiente nodo.*/