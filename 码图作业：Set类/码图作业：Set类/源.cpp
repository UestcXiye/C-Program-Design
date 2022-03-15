#include"CSet.h"
#include<stdlib.h>
int main()
{
	Set s1, s2;
	s1 += 1; s2 += 2; s1 += 3; s2 += 1;
	s2 += 5; s2 += 6;
	(s1 | s2).ShowElement();

	system("pause");
	return 0;
}