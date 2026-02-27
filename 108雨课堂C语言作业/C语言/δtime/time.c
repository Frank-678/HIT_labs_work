#include <stdio.h>

typedef struct {
    int hour;
    int minute;
} time;

int iflarger(const time *p1, const time *p2);
void printdelta(const time* p1, const time* p2);

int main(void) {
    time time1, time2;

    if (scanf("%d %d %d %d", &time1.hour, &time1.minute, &time2.hour, &time2.minute) != 4) 
        return 0;
    if (iflarger(&time1, &time2)) {
        printdelta(&time2, &time1);
    }
    else {
        printdelta(&time1, &time2);
    }
    return 0;
}

int iflarger(const time *p1, const time *p2) {
    if (p1->hour != p2->hour) return p1->hour > p2->hour;
    return p1->minute > p2->minute;
}

/*
    @para 小时间 大时间
*/
void printdelta(const time* p1, const time* p2) {
    int deltahour = p2->hour - p1->hour;
    int deltaminute = p2->minute - p1->minute;

    if (deltaminute < 0) {
        deltahour -= 1;
        deltaminute += 60;
    }
    printf("%i小时%i分钟\n", deltahour, deltaminute);
}
