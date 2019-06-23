#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define random( x ) (rand() % x)
//只能用异或凑合一下了QAQ
void encrypt_decrypt( char *p , int *key ,char *ciphertext )
{
    for(int i = 0; i < strlen( p ); i++)
    {
        ciphertext[ i ] = p[ i ] ^ key[ i ];
    }
}
//随机生成key
void get_key( char *p ,int *key)
{
    for(int i = 0; i < strlen( p ); i++)
    {
        srand(time(0)+rand());
        key[ i ] = random( 10 );
    }
    
}
int main()
{
    //不断用malloc申请内存，学以致用(笑)
    char c ,*str ,*p=(char*)malloc(sizeof(char));
    int n = 0 ,i;
    while(( c = getchar()) != '\n')
    {
        if( n )
        {
            free( str );
        }
        str=( char* )calloc( n+1 ,sizeof( char ));
        str[ n ] = c;
        for( i = 0; i < n; i++ )
        {
            str[ i ]=p[ i ];
        }
        free( p );
        p=( char* )calloc( n+1 ,sizeof( char ));
        for( i = 0; i < n+1; i++ )
        {
            p[ i ] = str[ i ];
        }
        n++;       
    }
    p[ n ]=0;
    puts( p );//确认你输入的是啥
    char ct[ strlen( p )], q[ strlen( p )] ;
    int key[ strlen( p )];
    get_key( p ,key);//获取key
    encrypt_decrypt( p , key ,ct);//加密
    printf("加密过的文本为%s\n" ,ct);
    printf("你的密钥为：");
    for(int i = 0; i < strlen( p ); i++)
    {
        printf("%d",key[ i ]);
    }
    encrypt_decrypt( ct , key ,q);//解密
    printf("\n解密的文本为%s\n" , q);

    return 0; 
}