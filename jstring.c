#include "jstring.h"
#include <assert.h>
/*****将字符ct的内容拷贝到s中，ct的结束符为'\0',调用者保证s的空间足够大***/
char *strcpy(char *s,const char *ct){
    assert(s != NULL && ct != NULL);
    char *p = s;
    while((*s++)=(*ct++));
    return p;
}
/**从ct中最多拷贝n个字符到s，ct结束标志位\0，调用者保证s足够大
   当n小于strlen(ct)时，只复制ct的前n个字符
   当n大于strlen(ct)时，复制ct的全部字符，并在末尾加'\0'
***/
char *strncpy(char *s,const char *ct,size_t n){
    assert(s != NULL && ct != NULL && n >=0 );
    char *p = s;
    while(n-- > 0 &&(*s++=*ct++));
    if (n = 0)
        *s = '\0';
    return p;
}
/***计算st字符串的长度，ct必须以'\0'为结束符
    返回类型为size_t
****/
size_t strlen(const char *st){
    assert(st != NULL);
    size_t n = 0;
    while(*st++)
        n ++;
    return n;
}
void printChars(const char *s){
    printf("%s\n",s);
    size_t i=0;
    for(i=0; i <= strlen(s); i ++)
        printf("%ld->%c:%d ",i,s[i],s[i]);
    printf("\n");
}
void testStrncpy(){
    char s[100];
    char *ct = "我来测试strcpy的";
    printf("sizeof(s)=%ld,strlen(ct)=%ld\n",sizeof(s),strlen(ct));
    strncpy(s,ct,3);
    printChars(ct);
    printChars(s);

}
void testStrcpy(){
    char s[100];
    char *ct = "我来测试strncpy的";
    printf("sizeof(s)=%ld,strlen(ct)=%ld",sizeof(s),strlen(ct));
    strcpy(s,ct);
    printf("%s\n",s);
}

void test(){
//    testStrcpy();
    testStrncpy();
}
int main(void){
    test();
}
