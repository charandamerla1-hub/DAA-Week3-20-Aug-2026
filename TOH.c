#include <stdio.h>
#include<math.h>
#define MAX 50
int main() {

    int source[MAX], destination[MAX], intermediate[MAX];
    int topS = -1, topD = -1, topI = -1;
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    char s = 'S', i = 'I', d = 'D';
    for (int k = n; k >= 1; k--)
        source[++topS] = k;
    if (n % 2 == 0) {
        char temp = i;
        i = d;
        d = temp;
    }

    int total_moves = pow(2,n) - 1;

    for (int move = 1; move <= total_moves; move++) {

        if (move % 3 == 1) {
            if (topS == -1) {
                int disk = destination[topD--];
                source[++topS] = disk;
                printf("Move disk %d from %c to %c\n", disk, d, s);
            } else if (topD == -1) {
                int disk = source[topS--];
                destination[++topD] = disk;
                printf("Move disk %d from %c to %c\n", disk, s, d);
            } else if (source[topS] > destination[topD]) {
                int disk = destination[topD--];
                source[++topS] = disk;
                printf("Move disk %d from %c to %c\n", disk, d, s);
            } else {
                int disk = source[topS--];
                destination[++topD] = disk;
                printf("Move disk %d from %c to %c\n", disk, s, d);
            }
        }
        else if (move % 3 == 2) {
            if (topS == -1) {
                int disk = intermediate[topI--];
                source[++topS] = disk;
                printf("Move disk %d from %c to %c\n", disk, i, s);
            } else if (topI == -1) {
                int disk = source[topS--];
                intermediate[++topI] = disk;
                printf("Move disk %d from %c to %c\n", disk, s, i);
            } else if (source[topS] > intermediate[topI]) {
                int disk = intermediate[topI--];
                source[++topS] = disk;
                printf("Move disk %d from %c to %c\n", disk, i, s);
            } else {
                int disk = source[topS--];
                intermediate[++topI] = disk;
                printf("Move disk %d from %c to %c\n", disk, s, i);
            }
        }
        else {
            if (topI == -1) {
                int disk = destination[topD--];
                intermediate[++topI] = disk;
                printf("Move disk %d from %c to %c\n", disk, d, i);
            } else if (topD == -1) {
                int disk = intermediate[topI--];
                destination[++topD] = disk;
                printf("Move disk %d from %c to %c\n", disk, i, d);
            } else if (intermediate[topI] > destination[topD]) {
                int disk = destination[topD--];
                intermediate[++topI] = disk;
                printf("Move disk %d from %c to %c\n", disk, d, i);
            } else {
                int disk = intermediate[topI--];
                destination[++topD] = disk;
                printf("Move disk %d from %c to %c\n", disk, i, d);
            }
        }
    }

    return 0;
}