#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *string)
{
    int i;
    
    i = 0;
    while(string[i])
        i++;
    return i;
}
int main(int argc, char **argv)
{
    __CHAR32_TYPE__ c = 'Ӝ';
    //printf("%d", ft_strlen(c));
    printf("%c", c);
}
