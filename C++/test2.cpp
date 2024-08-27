#include<stdio.h>
#define N 100

int mian()
{
    char s[N];
    printf("input a string:\n");
    scanf("%s",s);
    int i,up[26]={0},down[26]={0};

    for(i=0;i<N&&s[i]!=0;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        up[s[i]-'A']++;
        else if(s[i]>='a'&&s[i]<='z')
        down[s[i]-'a']++;
        else{
            printf("What you input is not a valid string,error->%c\n",s[i]);
            return 0;
        }
    }
    printf("The result is as follows:\n");
    for(i=0; i<26;i++){
        
        if(up[i]=0)

        printf("%c----%d\n",i+'A',up[i]);

        if(down[i]!=0)

        printf("%c---%d\n",i+'a',down[i]);
    }

    return 0;
}