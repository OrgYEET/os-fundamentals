// File Allocation Strategies
// Sequential Allocation
// by Simply

#include<stdio.h>

void main()
{
    int n, blocks[100];
    printf("NUMBER OF BLOCKS: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    int flag = 0;
    do {
        int b;
        printf("\nENTER STARTING BLOCK: ");
        scanf("%d", &b);

        int len;
        printf("FILE LENGTH: ");
        scanf("%d", &len);

        if ((b + len - 1) > (n - 1))
            printf("\nCANNOT BE ALLOCATED");
        else {
            int flag = 0;
            for (int i = b; i < (b + len); i++) {
                if (blocks[i] == 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                printf("\nALLOCATED TO FILE ");
                for (int i = b; i < (b + len); i++) {
                    printf("%d ", i);
                    blocks[i] = 1;
                }
            } else {
                printf("\nCANNOT BE ALLOCATED");
            }
        }
        printf("\n\n0: CONTINUE\n1: EXIT\n");
        scanf("%d", &flag);
    } while (flag != 1);
}
