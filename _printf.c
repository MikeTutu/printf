#include "holberton.h"
/**
  * _printf - print out passed argumetns base on the format
  * @format: a string that conatian diffrent specifiers
  * Return: len of passed string
  */
int _printf(const char *format, ...)
{
	int i;
	int num;
	char *str;
	va_list args;

	va_start(args, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					_int(num);
					break;
				case 's':
					str = va_arg(args, char*);
					_string(str);
					break;
				case '%':
					_putchar('%');
					break;
			}
			i++;
		}
		_putchar(format[i]);
	}
	return (i);
}

