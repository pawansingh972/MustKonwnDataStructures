#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node* addNodeAtEnd (Node* head, int data) {
    Node* temp = (struct Node*) malloc (sizeof (Node));
    Node* q = head;
    temp->data = data;
    temp->next = NULL;

    if (!head) {
        head = temp;
        return head;
    }

    while (q->next) {
        q = q->next;
    }

    q->next = temp;
    return head;
}

Node* addNodeAtBeginning (Node* head, int data) {
    Node* temp = (struct Node*) malloc (sizeof (Node));

    temp->data = data;
    temp->next = head;
    head = temp;

    return head;
}

Node* deleteFromBeginning (Node* head, int data) {
    if (!head) {
        printf ("\n List is Empty..");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    
    return head;
}

Node* deleteFromEnd ( Node* head, int data) {
    if (!head) {
        printf ("\n List is Empty..");
        return;
    }
    Node* q = head;
    Node* temp;

    if (!head->next) {
        temp = head;
        free(temp);
        head = NULL;
        return head;
    }

    while (q->next->next) {
        q = q->next;
    }
    temp = q->next;
    q->next = NULL;
    free(temp);
    return head;
}

Node* Reverse(Node *head) {
    if(head->next == NULL) {
        return head;
    }
    Node *prevNode = NULL;
    Node *currentNode = head;
    Node *nextNode = head->next;

    currentNode->next = prevNode;
    while (nextNode->next != NULL) {
        prevNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
        currentNode->next = prevNode;
    }
    nextNode->next = currentNode;
    
    return nextNode;
}

Node*  printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}


int main(int argc, char const *argv[]) {
    return 0;
}