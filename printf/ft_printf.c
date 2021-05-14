/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:07:29 by aapresya          #+#    #+#             */
/*   Updated: 2021/03/12 14:08:11 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"
#include <stdio.h>


int ft_numlength(int num)
{
	int i;

	i = 0;
	// if (num < 0)
	// 	i++;
	if (num == 0)
		i = 1;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	if (t_flags.period && t_flags.precision == 0)
		i = 0;
	return (i);
}

// void check_identifiers(char *format, va_list args)
// {
// 	while (*format != '\0')
// 	{
// 		if (*format == '%')
// 		{
// 		 	write(1, "%", 1);
// 			break;
// 		}
// 		if (*format == '-')
// 			t_flags.minus = 1;
// 		else if (*format == '0')
// 			t_flags.zero = 1; 
// 		else if (ft_isdigit(*format))
// 		{
// 			t_flags.minWidth = ft_atoi(&(*format));
// 			format += ft_numlength(t_flags.minWidth) - 1;
// 			printf("\n min: %d", t_flags.minWidth);
// 		}
// 		else if (*format == '.')
// 		{
// 			t_flags.period = 1;
// 			if (ft_isdigit(*(++format))){
// 				t_flags.precision = ft_atoi(&(*format));
// 				printf("max: %d ", t_flags.precision);
// 			}
// 			else if (*format == '*')
// 				t_flags.precision = va_arg(args, int);
// 			format += ft_numlength(t_flags.precision) - 1;
// 		}
// 		format++;
// 	}
// }

void	ft_check_minus(char **f)
{

	while (*(*f) == '-' || *(*f) == '0'){
		if (*(*f) == '-')
			t_flags.minus = 1;
		if (*(*f) == '0')
			t_flags.zero = 1;
		(*f)++;	
	}
	// if (*(*f) == '-')
	// {
	// 	t_flags.minus = 1;
	// 	(*f)++;
	// }
	// if (*(*f) == '0')
	// {
	// 	t_flags.zero = 1;
	// 	(*f)++;
	// }
	if (t_flags.zero == 1 && t_flags.minus == 1)
		t_flags.zero = 0;
	
}

int	ft_atoi2(char **str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (**str == 32 || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + **str - '0';
		(*str)++;
	}
	return (sign * result);
}

void ft_printf_char(){
	if (t_flags.minus){
		ft_putchar_fd((char)t_flags.arg, 1);
		while (t_flags.minWidth-- > 1)
			ft_putchar_fd(' ', 1);
	}
	else{
		while (t_flags.minWidth-- > 1)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd((char)t_flags.arg, 1);
	}
}

void ft_printf_int()
{
	int spaces;
	int zeroes;
	int num;

	zeroes =  t_flags.precision ? t_flags.precision - ft_numlength((int)t_flags.arg) : 0;
	if (t_flags.precision > ft_numlength((int)t_flags.arg))
		spaces = t_flags.minWidth - t_flags.precision;
	else
		spaces = t_flags.minWidth - ft_numlength((int)t_flags.arg);	
	
	if(t_flags.zero && t_flags.precision == 0){
		zeroes += spaces;
		spaces = 0;
	}

	num = (int)t_flags.arg;
	
	if ((int)t_flags.arg < 0)
	{
		num *= -1;
		spaces--;

		if (spaces <= 0 && zeroes > 0 && t_flags.precision == 0)
			zeroes--;
	}
	if (!t_flags.minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		if ((int)t_flags.arg < 0)
			ft_putchar_fd('-', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(t_flags.period && t_flags.precision == 0))
			ft_putstr_fd(ft_itoa(num), 1);
	}
	else
	{
		if ((int)t_flags.arg < 0)
			ft_putchar_fd('-', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(t_flags.period && t_flags.precision == 0))
			ft_putstr_fd(ft_itoa(num), 1);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}	
}

void ft_printf_string()
{
	int spaces;

	if (t_flags.period)
	{
		if (t_flags.precision < ft_strlen((char *)t_flags.arg))
			spaces = t_flags.minWidth - t_flags.precision;
		else
			spaces = t_flags.minWidth - ft_strlen((char *)t_flags.arg);
	}
	else
		spaces = t_flags.minWidth - ft_strlen((char *)t_flags.arg);
	if (t_flags.minus)
	{
		while (t_flags.precision-- > 0 && (char *)t_flags.arg)
			ft_putchar_fd(*(char *)t_flags.arg++, 1);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		while (t_flags.precision-- > 0 && (char *)t_flags.arg)
			ft_putchar_fd(*(char *)t_flags.arg++, 1);
	}
}


void ft_check_type(char **format){
	if (*(*format) == 'c')
		ft_printf_char();
	else if (*(*format) == 's')
		ft_printf_string();
	// else if (*format == 'p')
	// 	ft_printf_pointer();
	else if (*(*format) == 'd' || *(*format) == 'i')
		ft_printf_int();
	// else if (*format == 'i')
	// 	ft_printf_octal(); //?
	// else if (*format == 'u')
	// 	ft_printf_unsignedInt();
	// else if (*format == 'x')
	// 	ft_printf_hexaLower();
	// else if (*format == 'X')
	// 	ft_printf_hexaCapital();
	(*format)++;	
}
void updateStruct(){
	t_flags.minus = 0;
	t_flags.zero = 0;
	t_flags.minWidth = 0;
	t_flags.period = 0;
	t_flags.precision = 0; 
}

 int	ft_printf(const char *f, ...){
	
	char 	*format;
	va_list	args;
	//int		arg;

	format = (char *)f;
	va_start(args, f);

	while (*format)
	{
		
		if (*format == '%')
		{
			updateStruct();
			format++;
			ft_check_minus(&format);
			if (*format >= '0' && *format <= '9')
				t_flags.minWidth = ft_atoi2(&format);
			if (*format == '*')
			{
				t_flags.minWidth  = va_arg(args, int);
				format++;
			}
			//printf("%d", t_flags.minWidth);
			if (*format == '.'){
				t_flags.period = 1;
				format++;
				if (*format >= '0' && *format <= '9')
					t_flags.precision = ft_atoi2(&format);
				else if (*format == '*')
				{
					t_flags.precision = va_arg(args, int);
					format++;
				}
			}
			t_flags.arg = va_arg(args, void *);
			ft_check_type(&format);
		}
			//check_identifiers(format, args);
			// if(f[i] == '%')
			// 	ft_putstr_fd(va_arg(args, char*),1);
			// 	va_arg(args, int);
		else{
			write(1, &(*format), 1);
			//printf("\n%soof", format);
			format++;
		}	
		
	}
	//printf("%s", format);
	va_end(args);
	return (0);
}

//"./sources"




// int		main()
//   {
// // char *c = "1111";
// // printf("%d", ft_isdigit(*c));
// // check_identifiers("%-0247.478h");
// // printf("%-5.*s", 3, "asdsa");
// // printf("%18.15s\n", "Hello");
//  	//ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
// 	//ft_printf("%c%c%c", ' ','!','"');
// 	printf("%5.4d\n", 0);
// 	ft_printf("%5.4d", 0);


// // ft_printf("%-10.*d %7cv hello\n", 8, 349857, 's');
// // printf("%-10.*d %7cv hello\n", 8, 349857, 's');

// //printf("Hello %15chhh\n", 'b');

// //printf("%-10d", 7);
	
	
// // printf("Zero: %d\n", t_flags.zero);
// // printf("Max: %d\n", t_flags.maxWidth);
// // printf("Min: %d\n", t_flags.minWidth);
// // printf("Dot: %d\n", t_flags.period);

//   }