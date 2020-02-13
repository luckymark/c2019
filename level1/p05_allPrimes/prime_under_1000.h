int prime(int x)
{
	int a[]={3,5,7,11,13,17,19,23,29,31,37};//sqrt(1000)<37
	int sqrt_x,i,w;
	
	sqrt_x=sqrt(x)+1;
	w=0;
	
	for(i=0;a[i]<=sqrt_x;i++)
	{	
		if(x%a[i]==0)
		{
			w=1;
			break;
		}
	}
	return w;
}
