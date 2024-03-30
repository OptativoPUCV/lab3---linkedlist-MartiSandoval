#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* lista = (List *) malloc(sizeof(List));
  lista->head = NULL;
  lista->current = NULL;
  lista->tail = NULL;
     return lista;
}

void * firstList(List * list) {
  if (list->head == NULL) return NULL;
  list->current = list->head;
    return list->head->data;
}

void * nextList(List * list) {
  if (list->current == NULL || list->current->next == NULL) return NULL;
  list->current = list->current->next;
  
    return list->current->data;
}

void * lastList(List * list) {
  if (list->tail == NULL) return NULL;
  list->current = list->tail;
    return list->tail->data;
}

void * prevList(List * list) {
  if (list->current == NULL || list->current->prev == NULL) return NULL;
  list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
  Node* nuevo = createNode(data);
  if (list->head == list->current) {
    list->current = nuevo;
    list->current->prev = nuevo;
    list->head = nuevo;
    nuevo->prev = NULL;
    nuevo->next = list->current;
  }
  else if (list->head == NULL) {
    list->head = nuevo;
    list->tail = nuevo;
    nuevo->prev = NULL;
    nuevo->next = NULL;
  }
  else {
    list->head->prev = nuevo;
    nuevo->next = list->head;
    nuevo->prev = NULL;
    list->head = nuevo;
  }
  
  
  
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  /*Node* aux = list->current;
  if (list->current == list->head) {
    list->head = list->head->next;
    list->head->prev = NULL;  
  }*/
  
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}