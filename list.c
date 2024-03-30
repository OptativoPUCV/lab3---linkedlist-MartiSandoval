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
  if (list->head) {
    list->head->prev = nuevo;
    nuevo->next = list->head;
  }
  else {
    list->current = nuevo;
    list->tail = nuevo;
  }
  list->head = nuevo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* nuevo = createNode(data);
  if (list->current == NULL) {
    list->head = nuevo;
    nuevo->next = NULL;
    list->tail = nuevo;
  }
  else if (list->current->next != NULL) {
    nuevo->next = list->current->next;
    nuevo->prev = list->current->prev;
    list->current->next->prev = nuevo;
  }
  else {
    nuevo->prev = list->current;
    nuevo->next = NULL;
    list->current->next = nuevo;
    list->tail = nuevo;
  }
  list->current = nuevo;
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