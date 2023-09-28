#include "fdf.h"

int	count_word(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

int main(int argc, char *argv[])
{
    t_data  data;
    int     len;

    if (argc > 1)
    {
        data.dir = ft_strdup("./test_maps/");
        data.file = ft_strjoin(data.dir, argv[1]);
        data.fd = open(data.file, O_RDONLY);
        data.line = get_next_line(data.fd);
        while (data.line != NULL)
        {
            len = count_word(data.line, ' ');
            printf("%d\n", len);
            data.line = get_next_line(data.fd);
        }
    }

    return (0);
}