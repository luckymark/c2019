#include"show.h"
void show()
{
    FILE *fp;
    int j,i=0;
    if((fp=fopen(" text.txt","ab+"))==NULL)
    {
        printf("ERROR");
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
        printf("NO Record");
        return;
    }
    for(j=0;j<i;j++)
    {
        printf("name       weight\t\n");
        printf("%-10s %-15.3f\t\n",cargo[j].name,cargo[j].weight);
    }
}
