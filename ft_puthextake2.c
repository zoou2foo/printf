void	ft_puthex(unsigned long nb, int *len)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, len);
		ft_puthex(nb % 16, len);
	}
	else
	{
		if (nb <= 9)
		{
			ft_putchar(nb + 48, len);
		}
		else
		{
			if (str == 'x' || str == 'p')
				ft_putchar(nb - 10 + 'a', len);
			if (str == 'X')
				ft_putchar(nb - 10 + 'A', len);
		} 
	}
}