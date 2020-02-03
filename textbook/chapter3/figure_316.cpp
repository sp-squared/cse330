// Figure 3.16
// Constrcutor, Big Five, and private init routine for List Class

List()
        { init(); }

~List()
{
        clear();
        delete head;
        delete tail;
}

List( const List & rhs )
{
        init();
        for( auto & x : rhs )
        {
                push_back( x );
        }
}

List & operator= (const List & rhs)
{
        List copy = rhs;
        std::swap(*this, copy);
        return *this;
}

List(List && rhs)
        :theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
{
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
}

List & operator= ( List && rhs )
{
        std::swap( theSize, rhs.theSize );
        std::swap( head, rhs.head );
        std::swap( tail, rhs.tail );
}

// init routine goes in private
void init()
{
        theSize = 0;
        head = new Node;
        tail = new Node;
        head -> next = tail;
        tail -> prev = head;
}
