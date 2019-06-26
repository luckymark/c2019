#include"putinto.h"
void putinto()
{
    int j,i=0;
    char ch[2];
    FILE *fp;
    if((fp=fopen(" text.txt","ab+"))==NULL)
    {
        printf("error");
        return;
    }
    while(!feof(fp))
    {
        if(fread(&cargo[i],LEN,1,fp))
        {
            i++;
        }
    }
    fclose(fp);
    if(0==i)
    {
        printf("NO record   ");
    }
    else
    {
        system("cls");
       // show();
    }
    if((fp=fopen(" text.txt","wb+"))==NULL)
    {
        printf("ERROR");
        return;
    }
    for(j=0; j<i; j++)
    {
        fwrite(&cargo[j],LEN,1,fp);
    }
    printf("do you want to input (y/n)\n");
    scanf("%s",ch);
    while(strcmp(ch,"y")==0)
    {
        printf("please input name\n");
        scanf("%s",cargo[i].name);
        for(j=0; j<i; j++)
        {
            if(strcmp(cargo[i].name,cargo[j].name)==0)
            {
                printf("error,the name  existed");
                _getch();
                fclose(fp);
                return;
            }
        }
        printf("please input weight\n");
        scanf("%lf",&cargo[i].weight);
        if(fwrite(&cargo[i],LEN,1,fp)!=1)
        {
            printf("error,can not save");
            _getch();
        }
        else
        {
            printf("%s is inputed\n",cargo[i].name);
            i++;
        }
        printf("continue?(y/n)");
        scanf("%s",ch);
    }
    fclose(fp);
    printf("ok\n");


}
