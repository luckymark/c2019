#include <stdio.h>
#include<math.h>

int main()
{
    int i, num,sprta;
    printf("Please input a num:");
    scanf("%d",&num);
    sprta = sqrt(num);
    for(i = 2;i<sprta+2;i++)
    {
        if(num%i == 0)
        {
            printf("no");
            break;
        }
        else if(i >= sprta)
        {
            printf("yes");
            break;
        }
    }
    return 0;
}
