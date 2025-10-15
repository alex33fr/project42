int	ft_atoi(const char *s)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == ' ' || s[i] >= '\t' && s[i] <= '\r')
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result == (result * 10) + s[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}
