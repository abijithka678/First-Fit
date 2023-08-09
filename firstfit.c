#include <stdio.h>

int main() {
    int bno, pno, bsize[20], psize[20], allocation[20];
    
    // Initializing allocation array with -1
    for (int i = 0; i < 20; i++) {
        allocation[i] = -1;
    }
    
    // Input the number and size of blocks
    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    
    printf("Enter the size of blocks: ");
    for (int i = 0; i < bno; i++) {
        scanf("%d", &bsize[i]);
    }
    
    // Input the number and size of processes
    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    
    printf("Enter the size of processes: ");
    for (int i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
    }
    
    // Memory allocation using first-fit
    for (int i = 0; i < pno; i++) {
        for (int j = 0; j < bno; j++) {
            if (allocation[i] == -1 && psize[i] <= bsize[j]) {
                allocation[i] = j;
                bsize[j] -= psize[i];
            }
        }
    }
    
    // Print the allocation results
    printf("Process_no\tProcess_size\tBlock_no\n");
    for (int i = 0; i < pno; i++) {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        
        if (allocation[i] != -1) {
            printf("%d", allocation[i]);
        } else {
            printf("Not allocated");
        }
        
        printf("\n");
    }
    
    return 0;
}
