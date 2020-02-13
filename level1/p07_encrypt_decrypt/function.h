int input(char a[])
{
	int i;
	char ch;
	
	i=0;
	while((ch=getchar())!='\n')
	{
		a[i]=ch;
		++i;
	}
	
	return 0;
}

int output(char a[])
{
	int i;
	char ch;
	
	i=0;
	while(a[i]!=0)
	{
		putchar(a[i]);
		++i;
	}
	
	return 0;
}

int encrypt(char key[],char mingwen[],char miwen[])
{
	int length_key=strlen(key);
	int length_mingwen=strlen(mingwen);
	int i=0;
	
	for(;i<length_mingwen;++i)
	{
		miwen[i]=mingwen[i]+key[i%length_key]-48;
	}
	
	return 0;
}

int decrypt(char key[],char miwen[],char mingwen[])
{
	int length_key=strlen(key);
	int length_miwen=strlen(miwen);
	int i=0;
	
	for(;i<length_miwen;++i)
	{
		mingwen[i]=miwen[i]-key[i%length_key+48;
	}
	
	return 0;
}


