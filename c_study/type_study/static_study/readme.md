对于内部函数来说，比如一个使用static关键字修饰的函数，编译器在编译时，可能就直接把函数的地址“硬编码”在引用它的地方了。

这也是为什么：如果一个函数只在文件内部使用，最好加上 static 关键字。

一个原因是安全，防止与其他文件中的符号重名，还有一个原因是加快启动速度，因为不需要重定位啊！
