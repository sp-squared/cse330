// Figure 3.20
// erase routines for List Class

// erase item at itr
iterator erase( iterator itr )
{
        Node *p = itr.current;
        iterator retVal { p -> next };
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
        delete p;
        theSize--;

        return retVal;
}

// erase item at itr
iterator erase( iterator from, iterator to )
{
        for ( iterator itr = from; itr != to; )
        {
                itr = erase( itr );
        }
        return to;
}
