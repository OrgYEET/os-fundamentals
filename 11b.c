// File Allocation Strategies
// Indexed Allocation
// by Simply

#include<stdio.h>
#include<stdlib.h>

void main() {
    int n;
    printf("NUMBER OF BLOCKS: ");
    scanf("%d", &n);

    int *blocks = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    int flag = 0;
    do {
        int index;
        printf("\nINDEX BLOCK NUMBER: ");
        scanf("%d", &index);

        if (blocks[index] == 1)
            printf("\nINDEX ALREADY ALLOCATED, ALLOCATION NOT POSSIBLE");
        else {
            int length;
            printf("\nFILE LENGTH: ");
            scanf("%d", &length);

            int count = 0;
            blocks[index] = 1;
            int index_block[100];

            for (int i = 0; (i < n) && (count < length); i++) {
                if (blocks[i] == 0) {
                    blocks[i] = 1;
                    index_block[count] = i;
                    count++;
                }
            }

            if (count < length) {
                printf("\nINSUFFICIENT STORAGE, ALLOCATION NOT POSSIBLE");
                for (int i = 0; i < count; i++) {
                    blocks[index_block[i]] = 0;
                }
                blocks[index] = 0;
            } else {
                printf("\nALLOCATED TO DISK in INDEX BLOCK  %d\n", index);
                for (int i = 0; i < count; i++) {
                    printf("%d->%d\n", index, index_block[i]);
                }
            }
        }
        printf("\n\n0: CONTINUE\n1: EXIT\n");
        scanf("%d", &flag);
    } while (flag != 1);
}
