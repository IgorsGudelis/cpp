// my bad printf v1.0

#include <iostream>
#include <string>
#include <stdarg.h>

using namespace std;

void Myprintf(char * content, ...)
{

	va_list ptr;
	va_start(ptr, content);

	while (*content != 0)
	{
		if (*content == '%')
		{
			++content;

			if (*content == 'd'){
				cout << va_arg(ptr, int);
			}
			else if (*content == 'f')
				{
					cout << va_arg(ptr, double);
				}
				else if (*content == 's')
					{
						cout << va_arg(ptr, char*);
					}
					else if (*content == 'c')
						{
							cout << va_arg(ptr, char);
						}
						else
							{
								cout << *content;
							}
		}
		else {
			cout << *content;
		}

		++content;
	}

	va_end(ptr);

}


int main()
{
	Myprintf("This is my %d bad %s at %s a%c", 1, "printf", "2.30", 'm');

	return 0;
}