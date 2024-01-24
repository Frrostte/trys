#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue_empty(int f, int r) {
    return ((r < f) ? 1 : 0);
}

int queue_full(int r) {
    return ((MAX - 1 == r) ? 1 : 0);
}

void ins_front(int queue[], int *f, int *r, int item) {
    if (queue_empty(*f, *r)) {
        queue[++(*r)] = item;
        return;
    }
    if (*f != 0) {
        queue[--(*f)] = item;
        return;
    }
    printf("item cannot be inserted");
    return;
}

void ins_rear(int queue[], int *r, int item) {
    if (queue_full(*r)) {
        printf("the queue is full");
        return;
    }

    queue[++(*r)] = item;
    return;
}
void del_front(int queue[], int *f, int *r,int item) {
    if (queue_empty(*f, *r)) {
        printf("Queue is empty. Cannot delete from front.\n");
        return;
    }

    printf("%d deleted from the front.\n", queue[*f]);
    (*f)++;
    if (*f > *r) {
        *f = 0;
        *r = -1;
    }
}

void del_rear(int queue[], int *f, int *r) {
    if (queue_empty(*f, *r)) {
        printf("Queue is empty. Cannot delete from rear.\n");
        return;
    }

    printf("%d deleted from the rear.\n", queue[*r]);
    (*r)--;
    if (*f > *r) {
        *f = 0;
        *r = -1;
    }
}


void display(int queue[], int *f, int *r) {
    if (queue_empty(*f, *r)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = *f; i <= *r; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    return;
}

int main() {
    int queue[MAX];
    int f = 0, r = -1;
    int choice, item;

    for (;;) {
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &item);
                ins_front(queue, &f, &r, item);
                break;

            case 2:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &item);
                ins_rear(queue, &r, item);
                break;

            case 3:
                del_front(queue, &f, &r, item);
                break;

            case 4:
                del_rear(queue, &f, &r);
                break;

            case 5:
                display(queue, &f, &r);
                break;

            case 6:
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
