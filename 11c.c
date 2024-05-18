// File Allocation Strategies
// Linked List Allocation
// by Simply

#include<stdio.h>
#include<stdlib.h>

typedef struct block {
    int block_no;
    struct block *next;
} block;

typedef struct {
    int start_block;
    int length;
    block *list;
} file;

void main() {
    int n;
    printf("NUMBER OF BLOCKS: ");
    scanf("%d", &n);

    int blocks[100];
    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    int flag = 0;
    do {
        file *ptr = (file*) malloc(sizeof(file));
        printf("\nSTARTING BLOCK: ");
        scanf("%d", &(ptr->start_block));
        printf("FILE LENGTH: ");
        scanf("%d", &(ptr->length));

        if (blocks[ptr->start_block] == 1) {
            printf("\nSTARTING BLOCK ALREADY ALLOCATED, NOT POSSIBLE");
        } else {
            block *b = (block*) malloc(sizeof(block));
            b->block_no = ptr->start_block;
            b->next = NULL;
            ptr->list = b;
            blocks[ptr->start_block] = 1;

            int count = 1, i;
            for (i = ptr->start_block + 1; (i <= n) && (count < (ptr->length)); i++) {
                if (blocks[i] == 0) {
                    block *new = (block*) malloc(sizeof(block));
                    new->block_no = i;
                    new->next = NULL;
                    block *p = ptr->list;
                    while (p->next != NULL)
                        p = p->next;
                    p->next = new;
                    count++;
                    blocks[i] = 1;
                }
            }

            if (count < (ptr->length)) {
                printf("\nINSUFFICIENT STORAGE, ALLOCATION NOT POSSIBLE");
            } else {
                printf("\nALLOCATED TO DISK");
                printf("\nLINKED LIST ALLOCATED TO FILE: ");
                block *p = ptr->list;
                while (p->next != NULL) {
                    printf("%d->", p->block_no);
                    p = p->next;
                }
                printf("%d", p->block_no);
            }
        }
        printf("\n\n0: CONTINUE\n1: EXIT\n");
        scanf("%d", &flag);
    } while (flag != 1);
}
