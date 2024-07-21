#include <stdlib.h>
int ft_strlen(char *str);
int ft_atoi(char *str);

int control(int ac, char **av)
{
    if (ac != 2)
        return (1);
    if (ft_strlen(av[1]) != 31)
        return (1);
    return (0);
}

int *tab(char *str)
{
    int i;
    int j;
    int *sol;

    if (!(sol = malloc(sizeof(int) * 16)))
        return (0);
    i = -1;
    j = 0;
    while (str[++i] != '\0')
        if (str[i] >= '0' && str[i] <= '9')
            sol[j++] = ft_atoi(str + i);
    return (sol);
}