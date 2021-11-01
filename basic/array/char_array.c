#include <stdio.h>

/*
   其实字符串就是字符序列，由多个字符组成，所以在C语言中，我们可以用字符数组来存储字符串。
   字符串可以看做是一个特殊的字符数组，为了跟普通的字符数组区分开来，应该在字符串的尾部添加了一个结束标志'\0'。
   '\0'是一个ASCII码值为0的字符，是一个空操作符，表示什么也不干。
   所以采用字符数组存放字符串，赋值时应包含结束标志'\0'。

   %s表示期望输出一个字符串，因此printf函数会从b的首地址开始按顺序输出字符，一直到\0字符为止，
   因为\0是字符串的结束标记。
   所以，如果想要创建一个字符串，记得加上结束符\0，不然后果很严重，会访问到一些垃圾数据。
 **/
int main() {
	char a[3] = {'m', 'j', '\0'}; 	// 添加了结束符\0
	char b[] = {'i', 's'};        	// 假设忘记添加结束符\0
	// or
	// char b[] = "is";
	printf("string a：%s", a);     	// 输出字符串a
	printf("\n");                 	// 换行
	printf("string b：%s\n", b);   	// 输出字符串b

	return 0;
}
