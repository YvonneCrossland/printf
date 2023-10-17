#include "main.h"

int _printf(const char *format, ...);
{
	int funct_print = 0;

	va_list list_of_funct;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list_of_funct, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1)
			funct_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				funct_print++;
			}
		else if (*format == 'c')
		{
			char c = va_arg(list_of_funct, int);

			write(1, &c, 1);

			funct_print++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(list_of_funct, char*);

			int str_len = 0;

			while (str[str_len] != '\0')
				str_len++;

			write(1, str, str_len);
			funct_print += str_len;
		}
	}
	format++;
	}
	va_end(list_of_funct);

	return (funct_print);
}


int main(void)
{
	_print("%c\n", 'c');
	_print("%s\n", 's');
	_print("%%\n");
	return (0);
}
