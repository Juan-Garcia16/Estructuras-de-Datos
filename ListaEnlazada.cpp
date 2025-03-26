#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct node {
    int key;             // Campo que almacena el valor del nodo
    struct node *next;   // Puntero que apunta al siguiente nodo en la lista
};

int main() {
    // Declaración de punteros para manejar la lista enlazada
    struct node *head, *q, *current;

    // Creación del primer nodo (cabeza de la lista)
    head = (struct node *) malloc(sizeof(struct node)); // Reserva de memoria para el nodo
    head->key = 1;                                      // Asignación de valor al nodo
    head->next = NULL;                                  // Inicialmente, no apunta a ningún nodo

    // Creación del segundo nodo
    q = (struct node *) malloc(sizeof(struct node));    // Reserva de memoria para el nodo
    q->key = 2;                                         // Asignación de valor al nodo
    head->next = q;                                     // El primer nodo apunta al segundo nodo

    // Creación del tercer nodo
    q->next = (struct node *) malloc(sizeof(struct node)); // Reserva de memoria para el tercer nodo
    q->next->key = 3;                                      // Asignación de valor al tercer nodo
    q->next->next = NULL;                                  // El tercer nodo es el último, apunta a NULL

    // Recorrido de la lista enlazada para imprimir los valores de los nodos
    current = head; // Inicializamos el puntero 'current' en la cabeza de la lista
    while (current != NULL) { // Mientras no lleguemos al final de la lista
        printf("%d -> ", current->key); // Imprimimos el valor del nodo actual
        current = current->next;        // Avanzamos al siguiente nodo
    }

    // Al final del recorrido, imprimimos "NULL" para indicar el final de la lista
    printf("NULL\n");

    // Nota: No se libera la memoria reservada con malloc en este ejemplo.
    // En un programa real, sería importante liberar la memoria para evitar fugas.
}

/*
Definición de nodos y listas enlazadas:
Nodo: Es una estructura de datos que contiene un valor (o clave) y un puntero que apunta al siguiente nodo en la lista. Es el bloque básico de una lista enlazada.

Lista enlazada: Es una estructura de datos lineal compuesta por nodos conectados entre sí mediante punteros. A diferencia de los arreglos, las listas enlazadas no necesitan un bloque contiguo de memoria, lo que las hace más flexibles para operaciones dinámicas.

Explicación del flujo del programa:
Creación de nodos:

Se crean tres nodos dinámicamente usando malloc.
Cada nodo tiene un valor (key) y un puntero (next) que conecta al siguiente nodo.
Conexión de nodos:

El primer nodo (head) apunta al segundo nodo.
El segundo nodo apunta al tercero.
El tercer nodo apunta a NULL, indicando el final de la lista.
Recorrido de la lista:

Se utiliza un puntero auxiliar (current) para recorrer la lista desde la cabeza (head) hasta el final (NULL).
Durante el recorrido, se imprimen los valores de los nodos en orden.
Salida esperada:
1 -> 2 -> 3 -> NULL
*/