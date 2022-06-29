#include <stdio.h>
#include <stdlib.h> 

typedef struct Node
{
    int val;
    struct  Node *next;
    struct  Node *prev;
   
}t_Node;

// void addNode(t_Node **head, int add_val) //adicona elementos no final da lista
// {
// /* ponteiro para ponteiro - necessário pois head não estava alterando o seu estado inicial (NULL) */
//     t_Node *aux  = *head; 
//     /* aux sempre ira apontar para o endereço do primeiro nó para que assim, a lista seja varrida 
//     do inicio até o final */
//     t_Node *newNode = (t_Node *)malloc(sizeof(t_Node));
   
//     newNode->val = add_val;
//     newNode->next = NULL;

//     if (*head == NULL){ // apos o prumeiro no ser adicionado na lista essa condição é falsa e não entra no if
//         // lista vazia
//         *head = newNode; /* *head é alterado apenas uma vez que é quando um no é adicionado */
//         return;
//     } //
  
    
//     while (aux->next != NULL)
//     {
//         aux = aux->next; 
//     }
//     /* no fim do while aux aponta para o ultimo elemento */
//     aux->next = newNode; // aqui é onde o ponteiro next do ultimo elemento aponta para o no recem adicionado
// }

void inputNode(t_Node **head, int input_val, int pos)
{
    t_Node *newNode = (t_Node*)malloc(sizeof(t_Node));
    t_Node *aux_pos;
    
    newNode->val = input_val;
    aux_pos = *head;
    
    if (*head == NULL){
        *head = newNode; // head aponta para o 1 elemento da lista
        aux_pos = *head;
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }

    switch (pos)
    {
    case 1:
       // aux_pos;
        *head = newNode;
        newNode->prev = NULL;
        newNode->next = aux_pos;
        break;
    
    default:
        printf("Invalid option! \n");
        break;
    }
}

void removeNode(t_Node **head)
{
    t_Node *aux;
    
    if (*head == NULL){
        //fila vazia
        return;
    }
    //Recebe referencia atual do inicio da fila
    aux = *head;
    //Avança fila em uma posição
    *head = aux->next;
    //Printa valor que saiu(opcional)
    printf("Valor removido = %d\n",aux->val);
    //Desaloca no que saiu
    free(aux);
    aux = *head;

}
void deleteAll(t_Node **head)
{   
    t_Node *aux_remove = *head;
    t_Node *aux_pos = *head;
    // // aux_remove = head;

    if (aux_remove == NULL){
        printf("Lista vazia!\n");
        return;
    }
   
    while (aux_pos->next != NULL){
        aux_pos = aux_pos->next;
        printf("Valor a ser removido = %d\n",aux_remove->val);
        free(aux_remove);
        aux_remove = aux_pos;
        if(aux_remove->next == NULL){
            printf("Valor a ser removido = %d\n",aux_remove->val);
            free(aux_remove);
            printf("Lista vazia!\n");
            *head = NULL;
            return;
        }
                     
    }
    
    // printf("Valor a ser removido = %d\n",aux_pos->val);
    // free(aux_pos);
    
}
void printList(t_Node *head)
{
    t_Node *aux = head;
   // bool cond = 0;
    
    if (head == NULL){
        printf("Empty!\n\n");
        return;
    }
    while (aux != NULL)
    {
        printf("Valores na lista = %d\n",aux->val);
        aux = aux->next;
    }
}

int main (void){

    int op,value,pos;
    int count = 0;

    t_Node *head = NULL;
    t_Node *prev = NULL;
    
    
    do
    {   
        printf("Where is head ? %p\n",head);
        printf("Select an option\n 1 - Add node\n 2 - Remove Node\n 3 - print\n 4 - Delete all\n 8 - Exit\n ");
        scanf("%d",&op);

        switch (op){
        case 1:
            printf("Enter a value\n");
            scanf("%d",&value);
            if (head != NULL){
                printf("Select a position\n");
                scanf("%d",&pos);
            }
            //addNode(&head,value);
            inputNode(&head, value, pos);
            break;
        case 2:
            removeNode(&head);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            deleteAll(&head);
            printf("head apontando para %p\n",head);
            break;
         case 8:
            printf("saindo\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }while (op != 8);  
    return 0;
}
