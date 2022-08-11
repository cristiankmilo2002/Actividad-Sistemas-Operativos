#include <stdio.h>
#include <stdlib.h>


// -------------------------------------------------

typedef struct linkedListOpt
{
    int value;    // Este sera el valor que tendra el nodo
    struct linkedListOpt *next;   // Aqui autoreferenciamos la estructura para agregar mas nodos del mismo tipo
}linkedList;

// -------------------------------------------------

linkedList *crearLinkedList( linkedList *newLista){   // Se crea una funcion de tipo linkedList para generar la lista que contendra los nodos
    newLista = NULL;  // Inicializamos la lista en null puesto que no existe ningun nodo
    return newLista;   // Retornamos la lista
}

// -------------------------------------------------

linkedList *agregarNuevoNodo(linkedList *newLista, int value){  // Se crea una funcion que recibe la linkedList y el nuevo valor del nodo y lo agrega al final
    linkedList *newNodo, *temp;    // Se crea el nodo a agregar
    newNodo = (linkedList*)malloc(sizeof(linkedList));  // Se reserva la memoria del nuevo nodo
    newNodo->value = value;   // Le asignamos el valor que se recibe
    newNodo->next = NULL;   // Se hace que el valor de next sea NULL puesto que no hay un nodo despues de agregarlo

    if(newLista == NULL){
        newLista = newNodo; // como la lista se inicializa vacia, entonces simplemente agrego el primer elemento
    }else{
        temp = newLista;  // si la lista ya contiene nodos, guardo esa lista en una variable temporal y modifico el ultimo nodo para que ahora apunte al nuevo nodo
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNodo;
    }
    return newLista;
}

// -------------------------------------------------

void removeElegant(linkedList *newLista, linkedList *target){
    
    linkedList **p = &newLista;  // creo un doble apuntador que almacena la direccion del primer elemento de la linked list
    while((*p) != target){  // luego comparo si las direccion en la que esta parado es igual a la que quiero eliminar
        p = &(*p)->next;  // mientras no sean igual, le asigno a p la direccion del siguiente nodo
    } 
    *p = target->next; // cuando ya lo haya encontrado, lo que hace es que a ese nodo anterior al que quiero eliminar, lo hace apuntar al nodo siguiente
}                       // en caso de que sea el ultimo nodo, apuntaria a null

// -------------------------------------------------

int main(){
    linkedList *newLinkedList = crearLinkedList(newLinkedList);
    newLinkedList = agregarNuevoNodo(newLinkedList, 5);  // agrego un nodo
    newLinkedList = agregarNuevoNodo(newLinkedList, 56);  // agrego un nodo
    newLinkedList = agregarNuevoNodo(newLinkedList, 70);  // agrego un nodo
    newLinkedList = agregarNuevoNodo(newLinkedList, 95);  // agrego un nodo
    removeElegant(newLinkedList, newLinkedList->next->next);  // le paso a la funcion el nodo que quiero eliminar en este caso el tercer
    removeElegant(newLinkedList, newLinkedList+3);  // le paso a la funcion el nodo que quiero eliminar en este caso el ultimo
    

    while(newLinkedList != NULL){
        printf("%d\n", newLinkedList->value);
        newLinkedList = newLinkedList->next;
    }
    return 0;
}