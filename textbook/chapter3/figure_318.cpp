// Figure 3.18
// insert routine for List Class

// insert x before itr
iterator insert( iterator itr, const Object & x )
{
        Node *p = itr.current;
        theSize++;
        return { p -> prev = p -> prev -> next = new Node{ x, p -> prev, p } };
}

//insert x before itr
iterator insert ( iterator itr, Object && x )
{
        Node *p = itr.current;
        theSize++;
        return { p -> prev = p -> prev -> next = new Node{ std::move(x), p -> prev, p } };
}
