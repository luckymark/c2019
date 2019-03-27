

#include <stdio.h>
int main()
{	
    int age;
    for(age=1;;age++)
    {
        if(age*1.0/6+age*1.0/12+age*1.0/7+5+4==age*1.0/2)
        {	
	    age-=4; 
        printf("¶ª·¬Í¼¶ù×ÓËÀÊ±¶ª·¬Í¼%dËê¡£",age);
        break;
        }
    }
}
