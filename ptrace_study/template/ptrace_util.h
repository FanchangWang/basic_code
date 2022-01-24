#include <stdio.h>
#include <sys/ptrace.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>

#include <sys/user.h>

#define LONGSIZE  sizeof(long)

// 附加到正在运行的进程
int ptrace_attach(pid_t target_pid);
// 让子进程继续运行
int ptrace_cont(pid_t target_pid);
// 结束对目标进程的跟踪
int ptrace_detach(pid_t target_pid);


// 获取寄存器
int get_registers(pid_t target_pid, struct user_regs_struct *regs);
// 写入寄存器
int set_registers(pid_t target_pid, struct user_regs_struct *regs);
// 打印寄存器信息
int show_registers(struct user_regs_struct regs);
// 打印此时的寄存器信息
int show_current_registers(pid_t pid);


// 读取内存中的数据
int getdata(pid_t target_pid, unsigned long addr, uint8_t *dst, unsigned long len);
// 往内存中写入数据
int putdata(pid_t target_pid, unsigned long addr, uint8_t *src, unsigned long len);


// 以地址 sp 为基址，往这块内堆中 push 数据，可以操纵远程进程 stack
int push_stack(int pid, unsigned long long *sp, long * paramers,int len);
// 以地址 sp 为基址，往这块内堆中 pop  数据，可以操纵远程进程 stack
int pop_stack(int pid, unsigned long long *sp, long *paramers, int len);


// 断点处原始数据
uint8_t orig;
// 在 vaddr 处 设置断点，并获取这处的原来数据、方便以后还原
int set_breakpoint(pid_t pid,size_t vaddr);
// 判断是否运行到断点处，如果运行到断点处就获取寄存器信息
int is_hit_breakpoint(pid_t pid,struct user_regs_struct *regs);
// 恢复断点处的代码, 即还原寄存器信息和此位置原来的数据
int recovery_breakpoint(pid_t pid,struct user_regs_struct regs);
// 远程调用函数
int call_function(int pid,size_t func_addr,long paramers[],const unsigned int num_param,struct user_regs_struct regs,long *result);






