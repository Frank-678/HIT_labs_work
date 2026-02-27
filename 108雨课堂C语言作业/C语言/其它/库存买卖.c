#include <stdio.h>

typedef struct {
    int price;   /* 单位：分 ; 避免浮点数算钱带来的误差*/
    int stock;
} Item;

int main(void) {
    Item item[] = { {350, 5}, {450, 4}, {200, 8} }; /* id:0..2 */
    int n = (int)(sizeof(item) / sizeof(item[0]));

    for (;;) {
        int id;
        if (scanf("%d", &id) != 1) return 0; 
        if (id < 0) break;
        if (id >= n || item[id].stock <= 0) { puts("ERROR"); continue; }

        double pay;
        if (scanf("%lf", &pay) != 1) return 0; /* 单位：元 */

        int paid = (int)(pay * 100 + 0.5); // + 0.5 为了四舍五入
        int cost = item[id].price;

        if (paid < cost) { puts("ERROR"); continue; }

        item[id].stock--;
        printf("%.2f元\n", (paid - cost) / 100.0);
    }
    return 0;
}
