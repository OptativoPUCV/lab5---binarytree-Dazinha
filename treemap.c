#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
  if(tree->lower_than(key1,key2)==0 && tree->lower_than(key2,key1)==0)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

/*
1.- Implemente la función *createTreeMap* en el archivo treemap.c. Esta función recibe la función de comparación de claves y crea un mapa (TreeMap) inicializando sus variables. 
El siguiente código muestra como inicializar la función de comparación. Reserve memoria, inicialice el resto de variables y retorne el mapa.
*/
//TreeMap* map = createTreeMap(lower_than_string);

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
  TreeMap *map = (TreeMap*) malloc(sizeof(TreeMap));

  if (map == NULL)
  {
    return NULL;
  }

  map -> root = NULL;

  //map->lower_than = lower_than;
  map-> lower_than = lower_than;
  
  return map;
}

/*
2.- Implemente la función Pair* searchTreeMap(TreeMap* tree, void* key), la cual busca el nodo con clave igual a key y retorna el **Pair** asociado al nodo. Si no se encuentra la clave retorna NULL.
Recuerde hacer que el current apunte al nodo encontrado.
*/
//if (searchTreeMap(tree, key) == NULL
//is_equal(TreeMap* tree, void* key1, void* key2) return 1, else return 0
    /*
    if(compare == 0)
    {
      return tree -> current -> pair;
    }
    else if (compare > 0)
    {
      tree -> current = tree -> current -> right;
    }
    else
    {
      tree -> current = tree -> current -> left;
    }
    */


Pair * searchTreeMap(TreeMap * tree, void* key) {
  if (key == NULL || tree == NULL)
  {
    return NULL;
  }

  tree -> current = tree -> root;
  
  while (tree -> current != NULL)
  {
    int compare = tree -> lower_than(key, tree -> current -> pair -> key);
    //retorna 1 si key1<key2 y 0 si no
    //key1 = key
    //key2 = tree-> current-> pair-> key
    
    if (compare == 0)
    {
      if (is_equal(tree, key, tree -> current -> pair -> key) == 1) {
        return tree -> current -> pair;
      }
      //si no son iguales, muevo a la derecha
      tree -> current = tree -> current -> right; 
      
    } 
    else //if (compare == 1)
    {
      tree -> current = tree -> current -> left;
    } 

  }
  
  return NULL;
}

/*
3.- Implemente la función void insertTreeMap(TreeMap * tree, void* key, void * value). Esta función inserta un nuevo dato (key,value) en el árbol y hace que el current apunte al nuevo nodo.
Para insertar un dato, primero debe realizar una búsqueda para encontrar donde debería ubicarse. Luego crear el nuevo nodo y enlazarlo. Si la clave del dato ya existe retorne sin hacer nada (recuerde que el mapa no permite claves repetidas).
*/


void insertTreeMap(TreeMap * tree, void* key, void * value) {
  if (tree == NULL || key == NULL || value == NULL)
  {
    return;
  }

  
  
}

/*
4.- Implemente la función TreeNode * minimum(TreeNode * x). Esta función retorna el **nodo con la mínima clave** ubicado en el subárbol con raiz x. Para obtener el nodo tiene que, a partir del nodo x, irse por la rama izquierda hasta llegar al final del subárbol. Si x no tiene hijo izquierdo se retorna el mismo nodo.
*/

TreeNode * minimum(TreeNode * x){
  if (x == NULL)
  {
    return NULL;
  }

  
  return NULL;
}

/*
5.- Implemente la función void removeNode(TreeMap * tree, TreeNode* node). Esta función elimina el nodo *node* del árbol *tree*. Recuerde que para eliminar un node existen 3 casos:
**Nodo sin hijos:** Se anula el puntero del padre que apuntaba al nodo
**Nodo con un hijo:** El padre del nodo pasa a ser padre de su hijo
**Nodo con dos hijos:** Descienda al hijo derecho y obtenga el menor nodo del subárbol (con la función minimum). Reemplace los datos (key,value) de *node* con los del nodo "minimum". Elimine el nodo minimum (para hacerlo puede usar la misma función *removeNode*).
*/

void removeNode(TreeMap * tree, TreeNode* node) {
  if(tree == NULL || node == NULL)
  {
    return;
  }
  
}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}

/*
6.- Implemente las funciones para recorrer la estructura: Pair* firstTreeMap(TreeMap* tree) retorna el primer **Pair** del mapa (el menor). Pair* nextTreeMap(TreeMap* tree)  retornar el siguiente **Pair** del mapa a partir del puntero TreeNode* current. Recuerde actualizar este puntero.
*/

Pair * firstTreeMap(TreeMap * tree) {
  if (tree == NULL)
  {
    return NULL;
  }

  return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
  if (tree == NULL)
  {
    return NULL;
  }

  return NULL;
}


/*
7.- La función Pair* upperBound(TreeMap* tree, void* key) retorna el **Pair** con clave igual a key. En caso de no encontrarlo retorna el primer par asociado a una clave mayor o igual a key. 
Para implementarla puede realizar una búsqueda normal y usar un puntero a nodo auxiliar ub_node que vaya guardando el nodo con la menor clave *mayor o igual a key*. Finalmente retorne el par del nodo ub\_node.
*/


Pair * upperBound(TreeMap * tree, void* key) {
  if (tree == NULL || key == NULL)
  {
    return NULL;
  }

  
  return NULL;
}

