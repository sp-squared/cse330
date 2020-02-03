template <typename Object>
class List
{
private:
        struct Node
                {/* Figure 3.13 */};

public:
        class const_iterator
                {/* Figure 3.14 */};

        class iterator : public const_iterator
                {/* Figure 3.15 */};

public:
        List()
                {/* Figure 3.16 */}
        List(const List & rhs)
                {/* Figure 3.16 */}
        ~List()
                {/* Figure 3.16 */}
        List & operator= (const List & rhs)
                {/* Figure 3.16 */}
        List(List && rhs)
                {/* Figure 3.16 */}
        List & operator= (List && rhs)
                {/* Figure 3.16 */}

        iterator begin()
                {return {head -> next};}
        const_iterator begin() const
                {return {head -> next};}
        iterator end()
                {return{tail};}
        const_iterator end() const
                {return{tail};}

        int size() const
                {return theSize;}
        bool empty() const
                {return size == 0;}

        void clear()
        {
                while(!empty())
                        pop_front();
        }
        Object & front()
                {return *begin();}
        const Object & front() const
                {return *begin();}
        Object & back()
                {return *--end();}
        const Object & back() const
                {return *--back();}
        void push_front(const Object & x)
                {insert(begin(), x );}
        void push_front(Object && x)
                {insert(begin(), std::move(x) );}
        void push_back(const Object & x)
                {insert(end(), x);}
        void push_back(Object && x)
                {insert(end(), std::move(x) );}
        void pop_front()
                {erase(begin() );}
        void pop_back()
                {erase(--end() );}

        iterator insert(iterator itr, const Object & x)
                {/* Figure 3.18 */}
        iterator insert(iterator itr, Object && x)
                {/* Figure 3.18 */}

        iterator erase (iterator itr)
                {/* Figure 3.20 */}
        iterator erase(iterator from, iterator to)
                {/* Figure 3.20 */}

private:
        int theSize;
        Node *head;
        Node *tail;

        void init()
                {/* Figure 3.16*/}
};
