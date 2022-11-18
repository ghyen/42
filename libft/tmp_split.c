static char	**return_null(void)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *));
	if (!ret)
		return (0);
	ret[0] = 0;
	return (ret);
}

static int	get_t_len(char const *s, char c)
{
	int	j;
	int	i;
	int	cnt;
	int flag;

	cnt = 0;
	i = 0;
	flag = 0;
	while (s[i] && c != 0)
	{
		j = 0;
		if (s[i] == c)
		{
			flag = 1;
			while (s[i + j] == c)
				j++;
			if (s[i + j])
				cnt++;
			else
				cnt = 0;
		}
		if (s[i + j] == 0)
			i += j;
		else
			i += j + 1;
	}
	// 딜리미터가 없는거랑 모두 딜리미터인거랑 어떻게 구분하지?
	if (!flag && cnt == 0)
		cnt = 1;
	return (cnt);
}

static int	cal(char const *s, char c, char **ret)
{
	int	cnt;
	int	j;

	j = 0;
	while (*s)
	{
		cnt = 0;
		while (*s == c && *s)
			s++;
		while (s[cnt] != c && s[cnt])
			cnt++;
		if (cnt == 0)
			break ;
		ret[j] = (char *)malloc(sizeof(char) * (cnt + 1));
		if (!ret[j])
		{
			while (j)
				free(ret[--j]);
			free(ret);
			return (0);
		}
		ft_strlcpy(ret[j], s, cnt + 1);
		s += cnt;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		cnt;
	int		t_len;

	if (!*s)
		return (return_null());
	cnt = get_t_len(s, c);
	if (cnt == 1)
		t_len = 1;
	else if (cnt == 0)
		t_len = 0;
	else
		t_len = cnt - 1;
	ret = (char **)malloc(sizeof(char *) * (t_len + 1));
	if (!ret)
		return (0);
	if (cal(s, c, ret) == 0)
		return (0);
	ret[t_len] = 0;
	return (ret);
}
