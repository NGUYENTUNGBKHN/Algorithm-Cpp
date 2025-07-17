/**
 * @file       generate_parentheses.cpp
 * @brief      
 * @date       2025/07/17
 * @author     [Gentantun] (nguyenthanhtung8196@gmail.com)
 * @details    
 * @ref        
 * @copyright  Copyright (c) 2025 Fangia Savy
*/

/*******************************************************************************
**                                INCLUDES
*******************************************************************************/
#include <iostream>
#include <vector>
#include <cassert>   /// for assert
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

/**
 * @brief      
 * @namespace backtracking
 * 
*/
namespace backtracking{
/**
 * @brief      generate_parentheses class
 * 
*/
class generate_parentheses
{
private:
    /* data */
    std::vector<std::string> res;   // 

    void makeStrings(std::string str, int n, int closed, int open);
public:
    generate_parentheses(/* args */);
    ~generate_parentheses();

    std::vector<std::string> generate(int n);
};

/**
 * @brief      Construct a new generate parentheses::generate parentheses object
 * 
*/
generate_parentheses::generate_parentheses()
{

}

/**
 * @brief      Destroy the generate parentheses::generate parentheses object
 * 
*/
generate_parentheses::~generate_parentheses()
{

}

/**
 * @brief      generate_parentheses::makeStrings
 * 
 * @param str 
 * @param n 
 * @param closed 
 * @param open 
*/
void generate_parentheses::makeStrings(std::string str, int n, int closed, int open)
{
    if (closed > open)
    {
        return;
    }

    if (str.length() >= 2*n)
    {
        if (closed == open)
        {
            res.push_back(str);
            // std::cout << str << std::endl;
        }
        return;
    } 
    
    makeStrings(str + ")", n, closed + 1, open);
    makeStrings(str + "(", n, closed, open + 1);
}

/**
 * @brief      generate_parentheses::generate
 * 
 * @param n 
 * @return std::vector<std::string> 
*/
std::vector<std::string> generate_parentheses::generate(int n)
{
    res.clear();
    std::string strRes = "(";

    makeStrings(strRes, n, 0, 1);

    return res;
}

}

void test()
{
    int n = 0;
    std::vector<std::string> patterns;
    backtracking::generate_parentheses p;

    n = 1;
    patterns = {{"()"}};
    assert(p.generate(n) == patterns);

    n = 3;
    patterns = {{"()()()"}, {"()(())"}, {"(())()"}, {"(()())"}, {"((()))"}};

    assert(p.generate(n) == patterns);

    n = 4;
    patterns = {{"()()()()"}, {"()()(())"}, {"()(())()"}, {"()(()())"},
                {"()((()))"}, {"(())()()"}, {"(())(())"}, {"(()())()"},
                {"(()()())"}, {"(()(()))"}, {"((()))()"}, {"((())())"},
                {"((()()))"}, {"(((())))"}};
    assert(p.generate(n) == patterns);

    std::cout << "All tests passed\n";
}

int main()
{
    test();
    return 0;
}





/******************************** End of file *********************************/
