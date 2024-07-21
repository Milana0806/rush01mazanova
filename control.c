int ft_strlen(char *str);

int control_2(int tab[4][4], int index, int num)
{
    int i;

    i = -1;
    while (++i < index / 4)
        if (tab[i][index % 4] == num)
            return (1);
    i = -1;
    while (++i < index % 4)
        if (tab[index / 4][i] == num)
            return (1);
    return (0);
}

int colomns_up(int tab[4][4], int index, int entry[16])
{
    int i;
    int max;
    int count;

    i = 0;
    max = 0;
    count = 0;
    if (index / 4 == 3)
    {
        while (i < 4)
        {
            if (tab[i][index % 4] > max)
            {
                max = tab[i][index % 4];
                count++;
            }
            i++;
        }
        if (entry[index % 4] != count)
            return (1);
    }
    return (0);
}

int rows_right(int tab[4][4], int index, int entry[16])
{
    int i;
    int max_size;
    int visible_towers;

    i = 4;
    max_size = 0;
    visible_towers = 0;
    if (index % 4 == 3)
    {
        while (--i >= 0)
        {
            if (tab[index / 4][i] > max_size)
            {
                max_size = tab[index / 4][i];
                visible_towers++;
            }
        }
        if (entry[12 + index / 4] != visible_towers)
            return (1);
    }
    return (0);
}

int colomns_down(int tab[4][4], int index, int entry[16])
{
    int i;
    int max;
    int count;

    i = 3;
    max = 0;
    count = 0;
    if (index / 4 == 3)
    {
        while (i >= 0)
        {
            if (tab[i][index % 4] > max)
            {
                max = tab[i][index % 4];
                count++;
            }
            i--;
        }
        if (entry[4 + index % 4] != count)
            return (1);
    }
    return (0);
}

int rows_left(int tab[4][4], int index, int entry[16])
{
    int i;
    int max;
    int count;

    i = 0;
    max = 0;
    count = 0;
    if (index % 4 == 3)
    {
        while (i < 4)
        {
            if (tab[index / 4][i] > max)
            {
                max = tab[index / 4][i];
                count++;
            }
            i++;
        }
        if (entry[8 + index / 4] != count)
            return (1);
    }
    return (0);
}

int control_result(int tab[4][4], int index, int entry[16])
{
    if (rows_left(tab, index, entry) == 1)
        return (1);
    if (rows_right(tab, index, entry) == 1)
        return (1);
    if (colomns_down(tab, index, entry) == 1)
        return (1);
    if (colomns_up(tab, index, entry) == 1)
        return (1);
    return (0);
}