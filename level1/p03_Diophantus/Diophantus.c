#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int age;
    //显然岁数是12*7的倍数，其实就是12*7岁，再多就打破世界记录了
    const int step = 12 * 7;

    for (i = 1;; i++) {
        age = i * step;
        if (age / 6 + age / 12 + age / 7 + 5 + age / 2 + 4 == age) {
            printf("age: %d\n", age);
            break;
        }
    }

    system("pause");
    return 0;
}
