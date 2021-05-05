//@brief:	��dll���ڼ������������������׺���ʽ
//@auther:	����
//@date:	2021/5/1

#include "pch.h"
#include "testDLL.h"

//�ַ�������
class str_pro
{
public:
    string  str;
    bool    isnum;
    bool    isop;
};

int sort_prior(string op)                   //����������ȼ�����
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

// string & ���� ��labview�ڶ�Ӧ��Cstr
float calc(char * str)
{
    string sVi = str;
    bool isnum = false, isop = false;
    str_pro tmp;
    vector<str_pro> vMidEqu;
    float x = 0, y = 0, res = 0;
    //����str,�������еĸ������������
    for (int i = 0; i < sVi.size(); i++)
    {
        if ((sVi[i] >= '0' && sVi[i] <= '9') || sVi[i] == '.')
        {
            //�����һ�������֣���ǰ�����������䣬�ַ���β��
            if (isnum)
            {
                vMidEqu.back().str += sVi[i];
            }
            //������ǣ���������
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
    }//�����󽫵õ�һ�������Ԫ�ص�������

    //������ջ
    stack<str_pro> sStr;
    //��׺���ʽ����
    vector<str_pro> vBackEqu;


    for (int i = 0; i < vMidEqu.size(); i++)
    {
        //��Ϊ���� ֱ�����
        if (vMidEqu.at(i).isnum)
        {
            vBackEqu.push_back(vMidEqu.at(i));
        }
        //��Ϊ������
        else
        {
            //ջ�ջ�Ϊ������ ֱ�����
            if (sStr.empty() || vMidEqu.at(i).str == "(")
            {
                sStr.push(vMidEqu.at(i));
            }
            //��Ϊ������ ������ջ��ֱ������������
            else if (vMidEqu.at(i).str == ")")
            {
                while (sStr.top().str != "(")
                {
                    vBackEqu.push_back(sStr.top());
                    sStr.pop();
                }
                sStr.pop();
            }
            //�����ջ
            else
            {
                //����������ȼ��͵��������������ջ
                while (sort_prior(vMidEqu.at(i).str) <= sort_prior(sStr.top().str))
                {
                    vBackEqu.push_back(sStr.top());
                    sStr.pop();
                    if (sStr.empty())
                        break;
                }
                //�������������������ȼ�����ջ�ڵģ�����ջ
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

    //�����׺���ʽ
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