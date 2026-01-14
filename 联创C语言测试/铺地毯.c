#include <stdio.h>

typedef struct
{
	int a;
	int b;
	int g;
	int k;
} carpet;

int main(void)
{
	int n;
	printf("Amounts of carpets: ");
	scanf("%i", &n);
	
	carpet carpets[n];

	for (int i = 0; i < n; i++)
	{
		printf("Carpet %i: ", i + 1);
		scanf("%i%i%i%i", &carpets[i].a, &carpets[i].b, &carpets[i].g, &carpets[i].k);
	}
	
	int x, y;
	printf("Checked dot: ");
	scanf("%i %i", &x, &y); //scanf要用变量地址
	
	int top = -1;
	for (int j = 0; j < n; j++)
	{
		if (x >= carpets[j].a && x <= carpets[j].a + carpets[j].g && y >= carpets[j].b && y <= carpets[j].b + carpets[j].k) //少了向左下的坐标限制
		{
			top = j + 1;
		}
	}//for 这里更好方法是从后往前遍历，遇到就break;
	
	printf("%i", top);
	
	return 0;
}
