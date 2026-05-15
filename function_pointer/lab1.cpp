/**
 * @file       lab1.c
 * @brief      Simple example of function pointers in C
 * @date       2026/05/14
 * @author     [Gentantun] (nguyenthanhtung8196@gmail.com)
 * @details    This file demonstrates the basic usage of function pointers in C
 * @ref
 * @copyright  Copyright (c) 2026 Robotun
*/

#include <iostream>

#define FUNC(x)        (*(void (**)(void))x)()

void test_func()
{
    printf("%s : test\n",__func__);
    // std::cout << "func \n" << std::endl;
}

int main()
{
    std::cout << "start \n" << std::endl;
    void (*p_tr_func)() = &test_func;
    void (**pp_str_func)() = &p_tr_func;
    printf("p_tr_func = %x \n",p_tr_func);
    printf("*p_tr_func = %x \n",*p_tr_func);
    printf("test_func = %x \n",&test_func);
    // void **pp_tr_func = p_tr_func;
    FUNC(pp_str_func);

    
    return 1;
}


