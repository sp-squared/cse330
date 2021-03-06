// Figure 3.13 
// Nested Node Class for List Class (pg 96)

struct Node
{
        Object data;
        Node *prev;
        Node *next;

        Node (const Object & d = Object{}, Node *p = nullptr, Node *n = nullptr)
                : data{d}, prev{p}, next{n}
                {}
        Node (Object && d, Node *p = nullptr, Node *n = nullptr)
                : data{std::move(d)}, prev{p}, next{n}
                {}
};