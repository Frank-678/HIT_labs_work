//想到隔板法，但运用错误（隔开的是空间！！）

#include <stdio.h>

const int NUM = 1000000007;  //^ 在C语言中是按位异或运算符，不是幂运算。

int calculate(int a, int b);
int fact(int b);

int main(void)
{
	int n, m;
	scanf("%i %i", &n, &m);
	
	int result = calculate(n - 1, m - 1);
	
	printf("%i", result);
	
	return 0;
}

int calculate(int a, int b)
{	
	if (b == 1)  //值得注意，这里的b是指的是第二位，不是后面运算b - 1中的b
	{
		return a % NUM;
	}
	
	int result = (calculate(a - 1, b - 1)  * fact(b)) % NUM + (calculate (a - 1, b) * fact(b + 1)) % NUM; 
	
	return result % NUM;
}

int fact(int b)
{
	int f = 1;
	for (int i = 0; i < b; i++)
	{
		f = f * (b - i);
	}
	return f;
}