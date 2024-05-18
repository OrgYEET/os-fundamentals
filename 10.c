// Deadlock Detection Algorithm
// by Simply

#include<stdio.h>
#include<stdlib.h>

int available[10];
int allocation[10][10];
int request[10][10];

void main() {
    int n, m;
    printf("NUMBER OF PROCESSES: ");
    scanf("%d", &n);
    printf("NUMBER OF RESOURCES: ");
    scanf("%d", &m);
    
    printf("\nAVAILABLE: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    printf("\nALLOCATION:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nREQUEST:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i);
        for(int j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    int* work = (int*)malloc(m * sizeof(int)); 
    int* finish = (int*)malloc(n * sizeof(int)); 
    
 
    for(int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    for(int i = 0; i < n; i++) {
        int flag = 0;
        for(int j = 0; j < m; j++) {
            if(allocation[i][j] != 0) {
                flag = 1;
                break;
            }
        }
        finish[i] = (flag == 0) ? 1 : 0;
    }

    for(int z = 0; z < n; z++) {
        for(int i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int f = 0;
                for(int j = 0; j < m; j++) {
                    if(request[i][j] > work[j]) {
                        f = 1;
                        break;
                    }
                }
                if(f == 0) {
                    for(int p = 0; p < m; p++) {
                        work[p] += allocation[i][p];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    int flag = 0;
    for(int i = 0; i < n; i++) {
        if(finish[i] == 0) {
            flag = 1;
            printf("\nDeadlock detected!\n");
            break;
        }
    }

    if(flag == 0) {
        printf("\nNo deadlock\n");
    }

    free(work);
    free(finish);
}
