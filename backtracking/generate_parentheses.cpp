/**
 * @file       generate_parentheses.cpp
 * @brief      
 * @date       2026/05/01
 * @author     [Gentantun] (nguyenthanhtung8196@gmail.com)
 * @details    a sequence of parentheses is well-formed if each opening parentheses
 *              has a corresponding closing parenthesis
 *              and the closing parentheses are correctly ordered
 *              when input write n, it will generate impossible scenarios
 * @ref        
 * @copyright  Copyright (c) 2026 Robotun
*/

/*******************************************************************************
**                                INCLUDES
*******************************************************************************/
#include <iostream>
#include <vector>
/*******************************************************************************
**                       INTERNAL MACRO DEFINITIONS
*******************************************************************************/


/*******************************************************************************
**                      COMMON VARIABLE DEFINITIONS
*******************************************************************************/


/*******************************************************************************
**                      INTERNAL VARIABLE DEFINITIONS
*******************************************************************************/


/*******************************************************************************
**                      INTERNAL FUNCTION PROTOTYPES
*******************************************************************************/


/*******************************************************************************
**                          FUNCTION DEFINITIONS
*******************************************************************************/

namespace backtracking{

// generate_parentheses namespace
namespace generate_parentheses{

class generate_parentheses
{
private:
    /* data */
public:
    std::vector<std::string> genString;
    generate_parentheses(/* args */);
    ~generate_parentheses();
    std::vector<std::string> gen(int n);
    int solve(int open_idx, int close_idx, int n, std::string strResult);
    void show(std::vector<std::string> str);
};

generate_parentheses::generate_parentheses(/* args */)
{
}

generate_parentheses::~generate_parentheses()
{
}
    
int generate_parentheses::solve(int open_idx, int close_idx, int n, std::string strResult)
{
    if (strResult.size() == n*2)
    {
        if (open_idx == close_idx)
        {
            genString.push_back(strResult);
        }
        return 0;
    }

    if (close_idx > open_idx)
    {
        return 0;
    }

    /* gen open parentheses*/
    open_idx ++;
    solve(open_idx, close_idx, n, strResult + '(');

    /* gen close parentheses*/
    open_idx --;
    close_idx++;
    solve(open_idx, close_idx, n, strResult + ')');

}

void generate_parentheses::show(std::vector<std::string> str)
{
    for (int i = 0; i < str.size(); i++)
    {
        std::cout << str[i] << std::endl;
    }
}

std::vector<std::string> generate_parentheses::gen(int n)
{
    int index = 0;
    int open_cnt = 0, close_cnt = 0;
    std::string strResult;

    solve(open_cnt, close_cnt, n, strResult);
    // show(genString);
    return genString;
}

}    
}



int main()
{
    int n = 0;
    std::vector<std::string> patterns;
    backtracking::generate_parentheses::generate_parentheses p;

    n = 1;
    patterns = {{"()"}};
    p.gen(n) == patterns;

    n = 3;
    patterns = {{"()()()"}, {"()(())"}, {"(())()"}, {"(()())"}, {"((()))"}};

    p.gen(n) == patterns;

    n = 4;
    patterns = {{"()()()()"}, {"()()(())"}, {"()(())()"}, {"()(()())"},
                {"()((()))"}, {"(())()()"}, {"(())(())"}, {"(()())()"},
                {"(()()())"}, {"(()(()))"}, {"((()))()"}, {"((())())"},
                {"((()()))"}, {"(((())))"}};
    p.gen(n) == patterns;

    std::cout << "All tests passed\n";

    // test.gen(3);
    return 0;
}




/******************************** End of file *********************************/
