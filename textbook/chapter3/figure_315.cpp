// Figure 3.15
// Nested iterator Class for List Class

class iterator : public const_iterator
{
public:
        iterator()
                {}

        Object & operator* ()
                { return const_iterator :: retrieve(); }
        const Object & operator* () const
                { return const_iterator :: operator*(); }

        iterator & operator++ ()
        {
                this -> current = this -> current -> next;
                return *this;
        }

        iterator operator++ (int)
        {
                iterator old = *this;
                ++(*this)
                return old;
        }

protected:
        iterator ( Node *p ) : const_iterator{ p }
                {}

        friend class List <Object>;
};