#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
		printf("%d, ", rand() % 30 + 1);
}
