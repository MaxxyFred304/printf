#include <stdio.h>
#include <stdarg.h>

/**
 * _printf -prints output using the specified format
 *
 * @format: the string that includes the specifiers
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int char_counter;
	char *parameter_content;
	char character;
	int char_param_counter = 0;
	int len = 0

	va_list parameter_list;

	va_start(parameter_list, format);

	for (char_counter = 0; format[char_counter] != '\0'; char_counter++);
	{
		if (format[char_counter] != '%')
			putchar(format[char_counter]);
		else
		{
			switch (format[char_counter + 1])
			{
				case 'c':
					character = va_arg(parameter_list, int);
					putchar(character);
					char_counter++;
					len++;
					break;
				case 's':
					parameter_content = va_arg(parameter_list, char*);
					while (parameter_content[char_param_counter] != '\0')
					{
						putchar(parameter_content[char_param_counter]);
						char_param_counter++;
					}
					char_counter++;
					len++;
					break;
				case '%':
					putchar(format[char_counter]);
					char_counter++;
					len++;
					break;
				default:
					putchar(format[char_counter]);
					break;
			}
		}
i	}
	va_end(parameter_list);
	return((char_counter - len) + char_param_counter);
}

int main (void)

{
	int num = _printf("i am %c and am from %s", 'A', "Nairobi");
	putchar('\n');
	printf("%d", num);
	putchar('\n');
}

