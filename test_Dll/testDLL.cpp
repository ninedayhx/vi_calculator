//@brief:	此dll用于计算带浮点数的算术后缀表达式
//@auther:	黄旭
//@date:	2021/5/1

#include "pch.h"
#include "testDLL.h"

//字符属性类
class str_pro
{
public:
    string  str;
    bool    isnum;
    bool    isop;
};

int sort_prior(string op)                   //给运算符优先级排序
{
    int prior = 0;

    if (op == "^")
        prior = 3;
    if (op == "*" || op == "/" || op == "%"|| op == "s" || op == "c" || op == "t")
        prior = 2;
    if (op == "+" || op == "-")
        prior = 1;
    if (op == "(")
        prior = 0;

    return prior;
}

char* stringreplace(char* str)
{
    string stmp = str;
    for (int i = 0; i < stmp.size(); i++)
    {
        if (stmp[i] == 's')
        {
            if (i != 0 && stmp[i - 1] == 'n')
            {
                continue;
            }
            stmp.insert(i + 1, "in");
            i += 2;
        }
        if (stmp[i] == 'c')
        {
            stmp.insert(i + 1, "os");
            i += 2;
        }
        if (stmp[i] == 't')
        {
            if (i != 0 && stmp[i - 1] == 'u')
            {
                continue;
            }
            stmp.insert(i + 1, "an");
            i += 2;
        }
    }
    char* tmp;
    int len = stmp.length();
    tmp = (char*)malloc(len+1);
    stmp.copy(tmp, len, 0);
    *(tmp + len) = '\0';
    return tmp;

}

// string & 引用 在labview内对应到Cstr
float calc(char * str)
{
    string sVi = str;
    bool isnum = false, isop = false;
    str_pro tmp;
    vector<str_pro> vMidEqu;
    float x = 0, y = 0, res = 0;
    //遍历str,抽离其中的浮点数与运算符
    for (int i = 0; i < sVi.size(); i++)
    {
        if ((sVi[i] >= '0' && sVi[i] <= '9') || sVi[i] == '.')
        {
            //如果上一个是数字，则当前向量索引不变，字符接尾部
            if (isnum)
            {
                vMidEqu.back().str += sVi[i];
            }
            //如果不是，则索引加
            else
            {
                tmp.str = string(1, sVi[i]);
                tmp.isnum = true;
                vMidEqu.push_back(tmp);
                //cnt_vec++;
            }
            isnum = true;
            isop = false;
        }
        else
        {
            tmp.str = string(1, sVi[i]);
            tmp.isnum = false;
            vMidEqu.push_back(tmp);
            //cnt_vec++;
            isnum = false;
            isop = true;
        }
    }//遍历后将得到一个抽离好元素的向量。

    //操作符栈
    stack<str_pro> sStr;
    //后缀表达式向量
    vector<str_pro> vBackEqu;


    for (int i = 0; i < vMidEqu.size(); i++)
    {
        //若为数字 直接输出
        if (vMidEqu.at(i).isnum)
        {
            vBackEqu.push_back(vMidEqu.at(i));
        }
        //若为操作符
        else
        {
            //栈空或为左括号 直接输出
            if (sStr.empty() || vMidEqu.at(i).str == "(")
            {
                sStr.push(vMidEqu.at(i));
            }
            //若为右括号 依次退栈，直到遇到左括号
            else if (vMidEqu.at(i).str == ")")
            {
                while (sStr.top().str != "(")
                {
                    vBackEqu.push_back(sStr.top());
                    sStr.pop();
                }
                sStr.pop();
            }
            //否则进栈
            else
            {
                //如果遇到优先级低的运算符，继续进栈
                while (sort_prior(vMidEqu.at(i).str) <= sort_prior(sStr.top().str))
                {
                    vBackEqu.push_back(sStr.top());
                    sStr.pop();
                    if (sStr.empty())
                        break;
                }
                //如果遍历到的运算符优先级高于栈内的，则退栈
                sStr.push(vMidEqu.at(i));
            }

        }
    }

    while (!sStr.empty())
    {
        vBackEqu.push_back(sStr.top());
        sStr.pop();
    }

    stack<float> sfnum;

    //计算后缀表达式
    try 
    {
        for (int i = 0; i < vBackEqu.size(); i++)
        {
            if (vBackEqu.at(i).isnum)
            {
                sfnum.push(atof(vBackEqu.at(i).str.c_str()));
            }
            else
            {
                if (vBackEqu.at(i).str == "%" || vBackEqu.at(i).str == "s" || vBackEqu.at(i).str == "c" || vBackEqu.at(i).str == "t")
                {
                    if (sfnum.empty())
                    {
                        return 0.1234;
                    }
                    x = sfnum.top();
                    sfnum.pop();
                    if (vBackEqu.at(i).str == "%")
                        res = x / 100;
                    if (vBackEqu.at(i).str == "s")
                        res = sin(x);
                    if (vBackEqu.at(i).str == "c")
                        res = cos(x);
                    if (vBackEqu.at(i).str == "t")
                    {
                        if (x >= 3.1415 && x <= 3.1416)
                        {
                            return 0.1234;
                        }
                        res = tan(x);
                    }

                    sfnum.push(res);
                }
                else
                {
                    if (sfnum.empty())
                    {
                        return 0.1234;
                    }
                    y = sfnum.top();
                    sfnum.pop();
                    if (sfnum.empty())
                    {
                        return 0.1234;
                    }
                    x = sfnum.top();
                    sfnum.pop();
                    if (vBackEqu.at(i).str == "+")
                    {
                        res = x + y;
                    }
                    else if (vBackEqu.at(i).str == "-")
                    {
                        res = x - y;
                    }
                    else if (vBackEqu.at(i).str == "*")
                    {
                        res = x * y;
                    }
                    else if (vBackEqu.at(i).str == "^")
                    {
                        res = pow(x, y);
                    }
                    else if (vBackEqu.at(i).str == "/")
                    {
                        if (y == 0)
                        {
                            return 0.1234;
                        }
                        res = x / y;
                    }
                    else
                    {
                        return 0.1234;
                    }

                    sfnum.push(res);
                }
            }
        }
    }
    catch (out_of_range)
    {
        return 0.1234;
    }
    catch (bad_exception)
    {
        return 0.1234;
    }
    
    return res;
}