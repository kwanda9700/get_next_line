/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksilekwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:59:09 by ksilekwa          #+#    #+#             */
/*   Updated: 2019/06/05 12:00:05 by ksilekwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(unsigned long long overflow, int sign, const char *p)
{
	int	i;

	i = 0;
	while (*p <= '1' || *p >= '9')
		p++;
	while (ft_isdigit(*(p + i)))
		i++;
	if (i >= 19)
		return (sign == -1 ? 0 : -1);
	if (overflow > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	else
		return (overflow * sign);
}

int			ft_atoi(const char *str)
{
	unsigned long long	ret;
	int					len;
	int					i;
	int					sign;

	sign = 1;
	i = -1;
	len = 0;
	ret = 0;
	while (ft_iswhitespace(*str))
		str++;
	while (str[len])
		len++;
	while (++i <= len)
	{
		if (ft_isdigit(str[i]))
			ret = (ret * 10) + (str[i] - '0');
		else if (i == 0 && (str[i] == '-' || str[i] == '+'))
			sign = str[i] == '-' ? -1 : 1;
		else
			return (overflow(ret, sign, str));
	}
	return (overflow(ret, sign, str));
}
/*
**int		main(void)
**{
**	ft_putstr("\033[36mTest 1: input \" -sfecf\"\n\033[0m");
**	printf("%d\n", atoi(" -sfecf"));
**	printf("%d\n", ft_atoi(" -sfecf"));
**	ft_putstr("\033[36mTest 2: input \"\"\n\033[0m");
**	printf("%d\n", atoi(""));
**	printf("%d\n", ft_atoi(""));
**	ft_putstr("\033[36mTest 3: input \"+0\"\n\033[0m");
**	printf("%d\n", atoi("+0"));
**	printf("%d\n", ft_atoi("+0"));
**	ft_putstr("\033[36mTest 4: input \"-0\"\n\033[0m");
**	printf("%d\n", atoi("-0"));
**	printf("%d\n", ft_atoi("-0"));
**	ft_putstr("\033[36mTest 5: input \"0\"\n\033[0m");
**	printf("%d\n", atoi("0"));
**	printf("%d\n", ft_atoi("0"));
**	ft_putstr("\033[36mTest 6: input \"     --s8\"\n\033[0m");
**	printf("%d\n", atoi("     --s8"));
**	printf("%d\n", ft_atoi("     --s8"));
**	ft_putstr("\033[36mTest 7: input \"0001020304\"\n\033[0m");
**	printf("%d\n", atoi("0001020304"));
**	printf("%d\n", ft_atoi("0001020304"));
**	ft_putstr("\033[36mTest 8: input \"-2147483648\"\n\033[0m");
**	printf("%d\n", atoi("-2147483648"));
**	printf("%d\n", ft_atoi("-2147483648"));
**	ft_putstr("\033[36mTest 9: input \"-153\"\n\033[0m");
**	printf("%d\n", atoi("-153"));
**	printf("%d\n", ft_atoi("-153"));
**	ft_putstr("\033[36mTest 10: input \"+132\"\n\033[0m");
**	printf("%d\n", atoi("+132"));
**	printf("%d\n", ft_atoi("+132"));
**	ft_putstr("\033[36mTest 11: input \"++876\"\n\033[0m");
**	printf("%d\n", atoi("++876"));
**	printf("%d\n", ft_atoi("++876"));
**	ft_putstr("\033[36mTest 12: input \"--132\"\n\033[0m");
**	printf("%d\n", atoi("--132"));
**	printf("%d\n", ft_atoi("--132"));
**	ft_putstr("\033[36mTest 13: input \"dwbk\"\n\033[0m");
**	printf("%d\n", atoi("dwbk"));
**	printf("%d\n", ft_atoi("dwbk"));
**	ft_putstr("\033[36mTest 14: input \" 1\"\n\033[0m");
**	printf("%d\n", atoi(" 1"));
**	printf("%d\n", ft_atoi(" 1"));
**	ft_putstr("\033[36mTest 15: input \"42jk \"\n\033[0m");
**	printf("%d\n", atoi("45jk "));
**	printf("%d\n", ft_atoi("45jk "));
**	ft_putstr("\033[36mTest 16: input \" 21\"\n\033[0m");
**	printf("%d\n", atoi(" 21"));
**	printf("%d\n", ft_atoi(" 21"));
**	ft_putstr("\033[36mTest 17: input \"     32 \"\n\033[0m");
**	printf("%d\n", atoi("     32 "));
**	printf("%d\n", ft_atoi("     32 "));
**	ft_putstr("\033[36mTest 18: input \"\\n          42 24\"\n\033[0m");
**	printf("%d\n", atoi("\n          42 24"));
**	printf("%d\n", ft_atoi("\n          42 24"));
**	ft_putstr("\033[36mTest 19: input \"1-2\"\n\033[0m");
**	printf("%d\n", atoi("1-2"));
**	printf("%d\n", ft_atoi("1-2"));
**	ft_putstr("\033[36mTest 20: input \"4+2\"\n\033[0m");
**	printf("%d\n", atoi("4+2"));
**	printf("%d\n", ft_atoi("4+2"));
**	ft_putstr("\033[36mTest 21: input \"  +442\"\n\033[0m");
**	printf("%d\n", atoi("  +442"));
**	printf("%d\n", ft_atoi("  +442"));
**	ft_putstr("\033[36mTest 22: input \"  -4232\"\n\033[0m");
**	printf("%d\n", atoi("  -4232"));
**	printf("%d\n", ft_atoi("  -4232"));
**	ft_putstr("\033[36mTest 23: input \"4,5\"\n\033[0m");
**	printf("%d\n", atoi("4,5"));
**	printf("%d\n", ft_atoi("4,5"));
**	ft_putstr("\033[36mTest 24: input \"+\"\n\033[0m");
**	printf("%d\n", atoi("+"));
**	printf("%d\n", ft_atoi("+"));
**	ft_putstr("\033[36mTest 25: input \"-\"\n\033[0m");
**	printf("%d\n", atoi("-"));
**	printf("%d\n", ft_atoi("-"));
**	ft_putstr("\033[36mTest 26: input \"+-1\"\n\033[0m");
**	printf("%d\n", atoi("+-1"));
**	printf("%d\n", ft_atoi("+-1"));
**	ft_putstr("\033[36mTest 27: input \"-+1\"\n\033[0m");
**	printf("%d\n", atoi("-+1"));
**	printf("%d\n", ft_atoi("-+1"));
**	ft_putstr("\033[36mTest 28: input \"\\200123\"\n\033[0m");
**	printf("%d\n", atoi("\200123"));
**	printf("%d\n", ft_atoi("\200123"));
**	ft_putstr("\033[36mTest 29: input \"123\\200\"\n\033[0m");
**	printf("%d\n", atoi("123\200"));
**	printf("%d\n", ft_atoi("123\200"));
**	ft_putstr("\033[36mTest 30: input \"  \\t\\n  \\r\\r\\v\\f-899\"\n\033[0m");
**	printf("%d\n", atoi("  \t\n  \r\r\v\f-899"));
**	printf("%d\n", ft_atoi("  \t\n  \r\r\v\f-899"));
**	ft_putstr("\033[36mTest 31: input \"-2147483648\"\n\033[0m");
**	printf("%d\n", atoi("-2147483648"));
**	printf("%d\n", ft_atoi("-2147483648"));
**	ft_putstr("\033[36mTest 32: input \"2147483647\"\n\033[0m");
**	printf("%d\n", atoi("2147483647"));
**	printf("%d\n", ft_atoi("2147483647"));
**	ft_putstr("\033[36mTest 33: input \"000000000000000100\"\n\033[0m");
**	printf("%d\n", atoi("000000000000000100"));
**	printf("%d\n", ft_atoi("000000000000000100"));
**	ft_putstr("\033[36mTest 34: input \"0000000000-10-\"\n\033[0m");
**	printf("%d\n", atoi("0000000000-10-"));
**	printf("%d\n", ft_atoi("0000000000-10-"));
**	ft_putstr("\033[36mTest 35: input \"-123A There is a Cat in my pants
**  \"\n\033[0m");
**	printf("%d\n", atoi("-123A There is a Cat in my pants"));
**	printf("%d\n", ft_atoi("-123A There is a Cat in my pants"));
**	ft_putstr("\033[36mTest 36: input \"0129\\0012334\\
**  0Hidden\\n123\"\n\033[0m");
**	printf("%d\n", atoi("0129\0012334\0Hidden\n123"));
**	printf("%d\n", ft_atoi("0129\0012334\0Hidden\n123"));
**	ft_putstr("\033[36mTest 37: input \"123456789012345678999\"\n\033[0m");
**	printf("%d\n", atoi("123456789012345678999"));
**	printf("%d\n", ft_atoi("123456789012345678999"));
**	ft_putstr("\033[36mTest 38: input \"123456789012345678\"\n\033[0m");
**	printf("%d\n", atoi("123456789012345678"));
**	printf("%d\n", ft_atoi("123456789012345678"));
**	ft_putstr("\033[36mTest 39: input \"-123456789012345675\"\n\033[0m");
**	printf("%d\n", atoi("-123456789012345675"));
**	printf("%d\n", ft_atoi("-123456789012345675"));
**	ft_putstr("\033[36mTest 40: input \"      +000000000031\"\n\033[0m");
**	printf("%d\n", atoi("      +000000000031"));
**	printf("%d\n", ft_atoi("      +000000000031"));
**}
*/
