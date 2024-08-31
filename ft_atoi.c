#include <limits.h>

int	is_valid_integer(char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
		sign = sign - (*(str++) == '-') * 2;
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if (sign > 0 && (num > INT_MAX / 10
				|| (num == INT_MAX / 10 && (*str - '0')
					> INT_MAX % 10)))
			return (0);
		if (sign < 0 && (num > -(long)INT_MIN / 10
				|| (num == -(long)INT_MIN
					/ 10 && (*str - '0') > -(long)INT_MIN % 10)))
			return (0);
		num = num * 10 + (*(str++) - '0');
	}
	if (*str)
		return (0);
	return (1);
}

int	is_int_min(char *str)
{
	char	*int_min_str;
	int		i;

	int_min_str = "-2147483648";
	i = 0;
	while (str[i] != '\0' && int_min_str[i] != '\0')
	{
		if (str[i] != int_min_str[i])
			return (0);
		i++;
	}
	if (str[i] != '\0' || int_min_str[i] != '\0')
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	if (is_int_min(str))
		return (INT_MIN);
	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}
