#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		printf("%d\n", rand() % 10 + 1);
		printf("%d\n", rand() % 50 + 1);
		printf("%d\n", rand() % 100 + 1);
	}
}
