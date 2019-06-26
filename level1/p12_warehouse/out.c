#include"out.h"
void out()
{
    FILE *fp;
    char sname[10];
    int i,j,m=0;
    char ch[2];
    if((fp=fopen(" text.txt","ab+"))==NULL)
    {
        printf("can not open\n");
        return;
    }
    while(!feof(fp))
        if(fread(&cargo[m],LEN,1,fp)==1)
            m++;
    fclose(fp);
    if(m==0)
    {
        printf("no record!\n");
        return;
    }
    printf("please input the name:");
    scanf("%s",sname);
    for(i=0; i<m; i++)
    {
        if(strcmp(sname,cargo[i].name)==0)
            break;
    }
    if(i==m)
    {
        printf("cannot find\n");
        return ;
    }
    printf("find the cargo,delete?(y/n)");
    scanf("%s",ch);
    if(strcmp(ch,"y")==0)
    {
        for(j=i; j<m; j++)
        {
            cargo[j]=cargo[j+1];
        }
        m--;
        printf("delete successfully!\n");
    }
    if((fp=fopen(" text.txt","wb"))==NULL)
    {
        printf("can not open\n");
        return;
    }
    for(j=0; j<m; j++)
        if(fwrite(&cargo[j],LEN,1,fp)!=1)
        {
            printf("can not save!\n");
            _getch();
        }
    fclose(fp);

}

