#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class NODE
{
public:
        NODE()
                :left(nullptr), right(nullptr)
                {}
        NODE(T x)
                :value(x), left(nullptr), right (nullptr)
                {}
        NODE(T x, NODE<T> *lft, NODE<T> *rgt)
                :value(x), left(lft), right(rgt)
                {}
        T value;
        NODE <T> *left;
        NODE <T> *right;
};

int main()
{
        NODE <int> n35(35);
        NODE <int> n19(19);
        NODE <int> n101(101);
        NODE <int> n12(12);
        NODE <int> n46(46, &n35, &n19);
        NODE <int> n10(10, &n101, &n12);
        NODE <int> root(55, &n46, &n10);

        std::queue <NODE <int> > theq;
        theq.push(root);

        while(!theq.empty())
        {
                NODE <int> front = theq.front();
                cout << front.value << " ";
                theq.pop();

                if(front.left != nullptr)
                {
                        theq.push(*front.left);
                }

                if(front.right != nullptr)
                {
                        theq.push(*front.right);
                }

        }

        cout << endl;

return 0;
}
