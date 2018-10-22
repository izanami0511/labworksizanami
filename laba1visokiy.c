#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	

#define YES 1
#define NO 0
#define MAXLINE 1000

void process_line(char buffer[]);

void main(void)
{
	char line[MAXLINE];
	//gets(line);
	fgets(line, sizeof(line), stdin);
	process_line(line);
	puts(line);
	getch();
}

void process_line(char buffer[])
{
	char *buf_ptr;	 // указатель на текущий символ буфера
	char *end;		 // указатель на конец слова
	char *begin;	 // указатель на начало слова
	char c;			 // текущий символ
	int flag;		 // признак слова
	int found;		 // признак того, что в слове гласных больше, чем согласных 
	int cnt_glas = 0;	 //счетчик гласных
	int cnt_soglas = 0;	 //счетчик согласных

	flag = NO;
	found = NO;
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;

	do
	{
		c = *buf_ptr; // взять текущий символ из буфера

		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			// найден разделитель
			if (flag == YES)
				// найден первый разделить после слова
			{
				end = buf_ptr - 1; // запомнить указатель на конец слова
				if (cnt_soglas < cnt_glas)
					found = YES;
				else
					found = NO;

				if (found == YES)
				{
					// в слове было гласных больше, чем согласных 
					// слово нужно удалить
					char *src = end + 1;
					char *dst = begin;
					// удаление слова (перенос оставшейся части строки)
					while ((*dst++ = *src++) != '\0');
					buf_ptr = begin; // начать обработку строки с перенесённого фрагмента
				}
				found = NO;
			}
			flag = NO;
			cnt_soglas = 0;
			cnt_glas = 0;
		}

		else
		{
			//найдена буква
			if (flag == NO)
				begin = buf_ptr; // запомнить указатель на начало слова
			//нахождение слова с количеством гласных больше, чем согласных 
			//if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
			//{
			//	break;
			//}
			if (c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o')
			{
				cnt_glas++;
			}
			else if ((c != '1' || c != '2' || c != '3' || c != '4' || c != '5' || c != '6' || c != '7' || c != '8' || c != '9' || c != '0'))
			{
				
				cnt_soglas++;
			}
			flag = YES;
		}
		buf_ptr++;

	} while (c != '\0');

}