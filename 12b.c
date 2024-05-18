// Disk Scheduling Algorithms
// Scan 
// by Simply

#include <stdio.h>

void main() {
    int head, req[20], n, i, j, seek = 0, max, flag = 0, seq[20], c = 0, temp;
    printf("NUMBER OF CYLINDERS: ");
    scanf("%d", &max);
    printf("NUMBER OF REQUESTS: ");
    scanf("%d", &n);
    printf("ENTER REQUESTS: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    if (req[0] > max - 1)
        flag = 1;
    
    if (flag == 1)
        printf("CANNOT BE COMPLETED");
    else {
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (req[j] > req[j + 1]) {
                    temp = req[j];
                    req[j] = req[j + 1];
                    req[j + 1] = temp;
                }
            }
        }

        printf("POSTION OF READER / WRITER: ");
        scanf("%d", &head);
        j = 0;
        while (req[j] <= head)
            j++;

        for (i = j; i < n; i++)
        {
            seek += req[i] - head;
            head = req[i];
            seq[c] = req[i];
            c++;
        }

        seek += (max - 1) - req[n - 1];
        head = max - 1;

        for (i = j - 1; i >= 0; i--)
        {
            seek += head - req[i];
            head = req[i];
            seq[c] = req[i];
            c++;
        }

        printf("TIME TO SEEK = %d\n", seek);
        printf("SEEK SEQUENCE: ");
        for (i = 0; i < c; i++)
            printf("%d->", seq[i]);
    }
}
