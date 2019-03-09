#include<stdio.h>
#include<conio.h>
char CODE[2][95] = 
{{" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"}, 
 {"xA.KU2g!OrRyu]p8E;s&1`5HCD{jXlz_}|vo:)Y%f9Bawh $W(\"4cq\*NL-kI/Q?b'J=^d,Z[FGntP+#Vie<>m@TS~70M36"}};
void func(char c[1000]){
	int i = 0, a, b;
	if (c[0] == 'e')a = 0;
	if (c[0] == 'd')a = 1;
	while (c[i] != '\0'){
		for (int k = 0; k < 95; k++) {
			if (c[i] == CODE[a][k]) {
				printf_s("%c", CODE[1 - a][k]);
				break;
			}
		}
		i++;
	}
}
int main() {
	int i = 0;
	printf_s("输入密码（加密请以e开头，解密请以d开头）：\n");
	char c[1000] = { '\0' };
	gets_s(c);
	func(c);
	return 0;
}