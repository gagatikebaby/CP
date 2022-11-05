#include "stdio.h"
#define N 100
int main()
{
    char s[N];        
    printf("Input a string:\n");
    scanf("%s", s);
    int i, up[26] = {0}, down[26] = {0};
    for (i = 0; i < N && s[i] != 0; i++)   //判断数组s的第i个元素是不是为0
    {
        if (s[i] >= 'A' && s[i] <= 'Z') // 大写字母
            up[s[i] - 'A']++;
        else if (s[i] >= 'a' && s[i] <= 'z') //小写字母
            down[s[i] - 'a']++;
        else
        { // 其它 出错
            printf("What you input is not a valid string,error--> %c\n", s[i]);
            return 0;
        }
    }
    printf("The result is as follows:\n");
    for (i = 0; i < 26; i++)
    {
        if (up[i] != 0)
            printf("%c----%d\n", i + 'A', up[i]);
        if (down[i] != 0)
            printf("%c----%d\n", i + 'a', down[i]);
    }
    return 0;
}