#include "holberton.h"
char *tostring(char st[], long int num, int length)
{
  int i, len = length;
  long int n2 = num, rem;

  if (num < 0)
    num *= -1;
  for (i = 0; i < len; i++)
    {
      rem = num % 10;
      num = num / 10;
      st[len - (i + 1)] = rem + '0';
    }
  st[len] = '\0';
  if (n2 < 0)
    {
      len++;
      for (i = len - 1; i >= 0; i--)
	st[i + 1] = st[i];
      st[0] = '-';
    }

  return (st);

}
int num_len(unsigned int num)
{
  int len = 0;

  while (num != 0)
    {
      len++;
      num /= 10;
    }

  return (len);
}
int _print_unsigned(va_list args)
{
  unsigned int un = UINT_MAX;
  long int n = va_arg(args, unsigned int);
  unsigned int res;
  int len = 0;
  char s[59];
  char *st;

  st = malloc(sizeof(59));
  if (n >= 0 && n < UINT_MAX)
      res = n;
  else if (n == -1)
      res = un;
  else
      res = un + n;

  len = num_len(res);
  st = tostring(s, res, len);
  printstr(st);

  return len;
}

void printstr(char *str)
{
  while (*str)
    _putchar(*str++);
}
