int _printf1(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[4096];
	int buff_ind = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	for (int i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			buffer[buff_ind++] = format[i+1];
			if (buff_ind == BUFF_SIZE)
			{
				write(1, buffer, buff_ind);
				buff_ind = 0;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	if (buff_ind > 0)
	{
		write(1, buffer, buff_ind);
	}
	va_end(args);
	return (count);
}
