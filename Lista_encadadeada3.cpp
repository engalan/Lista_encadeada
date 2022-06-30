#include <stdio.h>
#include <stdlib.h> 

typedef struct Node
{
    int val,size;
    struct  Node *next;
    struct  Node *prev;
  
}t_Node;

void inputNodeEnd(t_Node **head, int input_val)
{   
    t_Node *newNodeEnd = (t_Node*)malloc(sizeof(t_Node));
    t_Node *aux = *head;

    newNodeEnd->val = input_val;
    newNodeEnd->next = NULL;

    while (aux->next != NULL){
        aux = aux->next;
        }
        aux->next  = newNodeEnd;
        
}

void inputNode(t_Node **head, int size_list, int input_val, int pos)
{
    t_Node *newNode = (t_Node*)malloc(sizeof(t_Node));
    t_Node *aux_pos; //armazena o endereço do ultimo head

    t_Node *aux_prev;
      
    newNode->val = input_val;
    aux_pos = *head;

    if(pos > size_list + 1){
    printf("Invalid position!\n");
    return;
    }
    // insere no inicio
    if (pos == 1){
       // aux_pos;
        *head = newNode;
        // newNode->prev = NULL;
        newNode->next = aux_pos;
        return;
    }
    if (pos > 1 ){
        aux_prev = aux_pos;
        for (int i = 1; i < pos; i++){
            aux_prev = aux_pos;
            aux_pos = aux_pos->next;
        }
        aux_prev->next = newNode;
        newNode->next = aux_pos;
    }
    
    // if (pos == size_list){

    //     while (aux_pos->next != NULL){
    //         aux_pos = aux_pos->next;
    //     }
    //     aux_pos->next = newNode;
    //     newNode->next = NULL;
    // }
    //insere no meio
    // if (pos > size_list){
    // // percorre a lista e ve se a posição é valida      
    // //    while (aux_pos != NULL){
    // //        aux_pos = aux_pos->next;
    // //        size ++;
    // //    }
    // //    printf("Tamanho da lista = %d\n",size);
    // //    if (pos > size){
    // //        printf("Invalid position\n");
    // //        return;
    // //     }
    //     // if (pos == 2){

    //     //     while (aux_pos->next != NULL){
    //     //         aux_pos = aux_pos->next;
    //     //     }
    //     //     aux_pos->next = newNode;
    //     //     newNode->next = NULL;
    //     // }
    // }
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

    t_Node *head = NULL; // inicializando os elementos da struct
    t_Node *prev = NULL;
      
    do
    {   
        printf("Where is head ? %p\n",head);
        printf("Select an option\n 1 - Add node\n 2 - Remove Node\n 3 - print\n 4 - Delete all\n 8 - Exit\n ");
        scanf("%d",&op);
        system("clear");

        switch (op){
        case 1:
            printf("Enter a value\n");
            scanf("%d",&value);

            // if (head != NULL){
            //     printf("Select a position\n");
            //     scanf("%d",&pos);
            // }
            //addNode(&head,value);
            printf("Select a position\n");
            scanf("%d",&pos);
            inputNode(&head,count,value, pos); //incrementar o tamnho da lista dentro da Main
            count ++;
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


