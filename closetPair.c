#include<stdio.h>

void closetPair(int a[],int size, int x)
{
	int l=0;
	int r = size -1 ;
	int diff = 12345;;
	int res_i, res_r;
	while(r>l)
	{
		if(abs(a[l] + a[r] -x) < diff)
		{
			res_i = l;
			res_r = r;
			diff = abs(a[l] + a[r] -x);
		}
		if(a[l] + a[r] > x)
			r--;
		else
			l++;
	}

	printf("%d %d",a[res_i],a[res_r]);
}
int main()
{
    int arr[] =  {10, 22, 28, 29, 30, 40}, x = 54;
    int n = sizeof(arr)/sizeof(arr[0]);
    closetPair(arr, n, x);
    return 0;
}
