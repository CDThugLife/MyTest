#include <iostream>
#include <stdlib.h>
#define L 10

using namespace std;

int main(){
 char *s;
int Get_str(char **s);
printf("������ַ��������ⳤ�ȣ���\n");
Get_str(&s);
printf("%s\n",s);
}
/*
*��ȡ����δ֪�������ַ���
*�Իس�����Ϊ��β��ʶ
*ÿ�����볤��ΪN��=10�����ڴ�ռ�
*���ʱ�ٴ����롣
*/
int Get_str(char **s)
{
int n = 1;
int i = 0;
*s = (char *)malloc(sizeof(char)*L*n);
if(*s == NULL)
{
printf("ERROR On Memory Application.\n");
getchar();
exit(0);
}
while(scanf("%c",*s+i),*(*s+i)!='\n')
{
i++;
if(i >= n*L)
{
n++;
*s = (char *)realloc(*s,sizeof(char)*L*n);
if(*s == NULL)
{
printf("ERROR On Memory Application.\n");
getchar();
exit(0);
}
}
}
*(*s+i) = '\0';
return 0;
}
