#include <stdio.h>
#include <string.h>
int main() {
    int mode, i;
    char s[1000];
    while(1) {
        printf("[0] Encrypt\n[1] Decrypt\nPlease choose mode: ");
        scanf("%d", &mode);
        if(mode == 0) {
            printf("Please input plaintext:\n");
            scanf("%s", s);
            for(i = 0; i < strlen(s); i++) 
                s[i] = (s[i]+61-(i+5)%6)%94+33;
            printf("%s\n", s);
        }
        if(mode == 1) {
            printf("Please input cipher:\n");
            scanf("%s", s);
            for(i = 0; i < strlen(s); i++)
                s[i] = (s[i]+61+(i+5)%6)%94+33;
            printf("%s\n", s);
        }
    }   
    return 0;
}