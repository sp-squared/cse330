#include <iostream>
#include <string>
#include <cctype>
#include "vector.h"
#include "stack.h"
using namespace std;

bool is_operator(string x)
{
        if (x == "+" or x == "-" or x == "*" or x == "/")
        {
                return true;
        }
        return false;
}

bool is_operand(string x)
{
        return isalnum(x[0]);

}

bool is_lower_eq_precedence(string op1, string op2)
{
        return (op2 == "*" or op2 == "/" or op1 == "+" or op1 == "-");
}

string infix2postfix()
{
        string postfix = "";
        Stack <Vector <string> > thestack;
        string inp;
        cin >> inp;
        while(true)
        {
                if (inp == "=")
                {
                        break;
                }
                if (is_operand(inp))
                {
                        //cout << inp << " ";
                        postfix = postfix + inp + " ";
                }else if(inp == "(")
                {
                        thestack.push(inp);
                }else if(is_operator(inp))
                {
                        if (thestack.empty())
                        {
                                thestack.push(inp);
                        }else{
                                while(thestack.top() != "(" and !thestack.empty() and !is_lower_eq_precedence(thestack.top(), inp))
                                {
                                        postfix = postfix + thestack.top() + " ";
                                        //cout << thestack.top() << " ";
                                        thestack.pop();
                                }

                                thestack.push(inp);
                        }

                }else if (inp == ")")
                {
                        while (thestack.top()!= "(")
                        {
                                postfix = postfix + thestack.top() + " ";
                                //cout << thestack.top() << " ";
                                thestack.pop();
                        }
                        thestack.pop();
                }

                cin >> inp; // read next input
        }
        // step 6
        while( !thestack.empty())
        {
                postfix = postfix + thestack.top() + " " ;
                //cout << thestack.top() << " ";
                thestack.pop();
        }
return postfix;
}

int main()
{
        string infix;
        cout << "Enter an infix expression : ";
        string post = infix2postfix();
        cout << "post fix expression : " << post << endl;
}
