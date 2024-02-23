#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

    char str[101];

    fgets(str, 101, stdin);
    int len = 0;

    for (int i = 0; str[i] && str[i] != '\n'; i++)
        len++;
    printf("%d\n", len);

    return 0;
}
