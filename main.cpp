#include <iostream>
#include <stdlib.h>
#define L 10

using namespace std;

int main(){
 char *s;
int Get_str(char **s);
printf("请输出字符串（任意长度）：\n");
Get_str(&s);
printf("%s\n",s);
}
/*
*读取长度未知的任意字符串
*以回车符作为结尾标识
*每次申请长度为N（=10）的内存空间
*溢出时再次申请。
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
