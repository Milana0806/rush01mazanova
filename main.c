#include <stdlib.h>

void ft_putnbr(int nb);
void ft_putchar(char c);
void ft_putstr(char *str);

int ft_atoi(char *str);
int ft_strlen(char *str);
int *tab(char *str);
int control(int ac, char **av);
int control_2(int tab[4][4], int index, int num);
int control_result(int tab[4][4], int index, int entry[16]);

int solve(int tab[4][4], int entry[16], int index)
{
	int size;

	if (index == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (control_2(tab, index, size) == 0)
		{
			tab[index / 4][index % 4] = size;
			if (control_result(tab, index, entry) == 0)
			{
				if (solve(tab, entry, index + 1) == 1)
					return (1);
			}
			else
				tab[index / 4][index % 4] = 0;
		}
	}
	return (0);
}

void print_solution(int sol[4][4])
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(sol[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int main(int ac, char **av)
{
	int sol[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *entry;

	if (control(ac, av) == 1)
		return (0);
	entry = tab(av[1]);

	if (solve(sol, entry, 0) == 1)
		print_solution(sol);
	else
		ft_putstr("No solutions\n");
	return (0);
	free(sol);
}
