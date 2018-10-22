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
	char *buf_ptr;	 // ��������� �� ������� ������ ������
	char *end;		 // ��������� �� ����� �����
	char *begin;	 // ��������� �� ������ �����
	char c;			 // ������� ������
	int flag;		 // ������� �����
	int found;		 // ������� ����, ��� � ����� ������� ������, ��� ��������� 
	int cnt_glas = 0;	 //������� �������
	int cnt_soglas = 0;	 //������� ���������

	flag = NO;
	found = NO;
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;

	do
	{
		c = *buf_ptr; // ����� ������� ������ �� ������

		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			// ������ �����������
			if (flag == YES)
				// ������ ������ ��������� ����� �����
			{
				end = buf_ptr - 1; // ��������� ��������� �� ����� �����
				if (cnt_soglas < cnt_glas)
					found = YES;
				else
					found = NO;

				if (found == YES)
				{
					// � ����� ���� ������� ������, ��� ��������� 
					// ����� ����� �������
					char *src = end + 1;
					char *dst = begin;
					// �������� ����� (������� ���������� ����� ������)
					while ((*dst++ = *src++) != '\0');
					buf_ptr = begin; // ������ ��������� ������ � ������������ ���������
				}
				found = NO;
			}
			flag = NO;
			cnt_soglas = 0;
			cnt_glas = 0;
		}

		else
		{
			//������� �����
			if (flag == NO)
				begin = buf_ptr; // ��������� ��������� �� ������ �����
			//���������� ����� � ����������� ������� ������, ��� ��������� 
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