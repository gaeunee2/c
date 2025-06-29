#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
    int m, x, S = 0;
    char cmd[10];

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf("%d", &x);
            S |= (1 << (x - 1));
        }
        else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &x);
            S &= ~(1 << (x - 1));
        }
        else if (strcmp(cmd, "check") == 0) {
            scanf("%d", &x);
            printf("%d\n", (S & (1 << (x - 1))) ? 1 : 0);
        }
        else if (strcmp(cmd, "toggle") == 0) {
            scanf("%d", &x);
            S ^= (1 << (x - 1));
        }
        else if (strcmp(cmd, "all") == 0)
            S = (1 << 20) - 1; // 20개의 비트를 1로 세팅
        else if (strcmp(cmd, "empty") == 0)
            S = 0;
    }

    return 0;
}