#include <stdio.h>

int main()
{
    char s[80] = "this is a boy muliti";
    int i=0,j=0,k=0;
    char temp;
    while(s[i]!='\0')
    {
        
        if(s[i+1] == ' ' ||  s[i+1] == '\0')
        {
           
            for(k=j;k<i;k++)
            {
                temp = s[i];
                s[i] = s[k];
                s[k] = temp;
            }
            j=i+2;
            printf("%c\n", s[j]);
        }
        i++;
    }
    printf("%s", s);
}
