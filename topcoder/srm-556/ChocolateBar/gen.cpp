#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

void tc_random(int N)
{
	printf("\"");
	REP(i, N)
		printf("%c", rand() % 26 + 'a');
	printf("\"\n");
}

void tc_all_distinct(int N, bool alter)
{
	char pool[N];
	REP(i, 26)
		pool[i] = 'a' + i;
	for (int i = 26; i < N; i++)
		pool[i] = rand() % 26 + 'a';
	REP(i, N)
		if (i)
			swap(pool[i], pool[rand() % i]);
			
	if (alter)
	{
		REP(i, 26) if (i && rand() % 100 <= 25)
			pool[i] = rand() % 26 + 'a';
	}

	printf("\"");
	REP(i, N)
		printf("%c", pool[i]);
	printf("\"\n");

}

void tc_palindrome(int N, bool alter)
{
	char pool[N];
	for (int i = 0; i <= N/2; i++)
		pool[i] = pool[N-i-1] = rand() % 26 + 'a';
	
	if (alter)
	{
		REP(i, 26) if (i && rand() % 100 <= 25)
			pool[i] = rand() % 26 + 'a';
	}

	printf("\"");
	REP(i, N)
		printf("%c", pool[i]);
	printf("\"\n");

}

int main()
{
	srand(time(NULL));
	
	puts("\"x\"");
	puts("\"abcabcabc\"");
	
	tc_all_distinct(3, false);
	tc_all_distinct(5, false);
	tc_all_distinct(10, false);
	tc_all_distinct(15, false);
	tc_all_distinct(20, false);
	tc_all_distinct(25, false);
	tc_all_distinct(30, false);
	tc_all_distinct(40, false);
	tc_all_distinct(45, false);
	tc_all_distinct(50, false);
	
	tc_all_distinct(3, true);
	tc_all_distinct(5, true);
	tc_all_distinct(10, true);
	tc_all_distinct(15, true);
	tc_all_distinct(20, true);
	tc_all_distinct(25, true);
	tc_all_distinct(30, true);
	tc_all_distinct(40, true);
	tc_all_distinct(45, true);
	tc_all_distinct(50, true);
	
	tc_palindrome(2, false);
	tc_palindrome(6, false);
	tc_palindrome(11, false);
	tc_palindrome(16, false);
	tc_palindrome(21, false);
	tc_palindrome(26, false);
	tc_palindrome(31, false);
	tc_palindrome(41, false);
	tc_palindrome(46, false);
	tc_palindrome(49, false);
	
	tc_palindrome(4, true);
	tc_palindrome(4, true);
	tc_palindrome(9, true);
	tc_palindrome(14, true);
	tc_palindrome(19, true);
	tc_palindrome(23, true);
	tc_palindrome(29, true);
	tc_palindrome(39, true);
	tc_palindrome(44, true);
	tc_palindrome(50, true);
	
	tc_random(3);
	tc_random(5);
	tc_random(10);
	tc_random(15);
	tc_random(20);
	tc_random(25);
	tc_random(30);
	tc_random(40);
	tc_random(45);
	tc_random(50);
}
