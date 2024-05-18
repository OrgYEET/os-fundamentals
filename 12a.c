// Disk Scheduling Algorithms
// First Come First Serve
// by Simply

#include <stdio.h>
#include <math.h>

#define MAX 20

void filefcfs(int arr[], int head, int size) {
    int seek = 0;
    int current, previous = head, distance;
    
    printf("Seek Sequence is\n");
    for(int i = 0; i < size; i++) {
        current = arr[i];
        distance = fabs(previous - current);
        seek += distance;
        previous = current;
        printf("%d-> ", arr[i]);
    }

    printf("\nTOTAL SEEK OPERATIONS: %d\n", seek);
}

void main() {
    int arr[MAX], head, n, i, t;
    printf("TOTAL TRACKS: ");
    scanf("%d", &t);
    printf("TOTAL REQUESTS: ");
    scanf("%d", &n);
    printf("ENTER TRACK REQUESTS: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("POSITION OF READER / WRITER: ");
    scanf("%d", &head);
    filefcfs(arr, head, n);
}
