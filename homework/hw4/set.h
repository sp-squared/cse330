// Colin Morris-Moncada
// HW 4
// Set Header File

#ifndef BST_H
#define BST_H
#include <cassert>
#include <algorithm>
#include "vector.h"
#include "stack.h"
using namespace std;

// Typename C for Comparable aka = < >
template <typename C>
class Set
{
private:
    struct BinaryNode
    {
        C element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode( const C & theElement, BinaryNode *lt, BinaryNode *rt )
            : element{ theElement }, left{ lt }, right { rt }
        {} 
    };
public:
    class iterator
    {
    public:
        iterator()
            : current(nullptr)
        {}

        C & operator*()
        {
            return current -> element;
        }   

        iterator end()
        {
            Stack<Vector<BinaryNode* > > emptystack;
            return iterator( nullptr, emptystack );
        }

        Set & operator= ( const Set & rhs )
        {
            Set copy = rhs;
            std::swap ( *this, copy);
            return *this;
        }

        const C & findMin() const
        {
            assert(!isEmpty() );
            return findMin ( root ) -> element;
        }

         const C & findMax() const
        {
            assert(!isEmpty() );
            return findMax ( root ) -> element;
        }
        
        bool contains( const C & x ) const
        {
            return contains( x, root);
        }

        bool isEmpty() const
        {
            return root == nullptr;
        }

        void printTree ( ostream & out = cout ) const
        {
            if ( isEmpty() )
                out << "Empty Tree" << endl;
            else
                printTree( root, out );
        }

        void printInternal()
        {
            printInternal( root, 0 );
        }

        BinaryNode * current;
        Stack<Vector<BinaryNode* > > antes;

        iterator( BinaryNode *p, Stack<Vector<BinaryNode*> > st )
            :current{p}, antes{st}
        {}

        friend class Set<C>;
    };
    // End of Class Iterator

public:
    Set()
        : root{nullptr}
    {}

    Set( const Set & rhs )
        : root{nullptr}
    {
        root = clone ( rhs.root);
    }

    Set( Set && rhs)
    {
        rhs.root = nullptr;
    }

    ~Set()
    {
        makeEmpty();
    }

    iterator begin()
    {
        BinaryNode *lmost = root;
        Stack<Vector<BinaryNode* > > nstack;
        while(lmost-> left != nullptr)
        {
            nstack.push(lmost);
            lmost = lmost -> left;
        }

        return iterator( lmost, nstack);
    }

    iterator operator++(int)
    {
        iterator old = *this;
        ++(*this);
        return old;
    }

    bool operator ==(const iterator & rhs) const
    {
        return rhs.current;
    }

    bool operator !=(const iterator & rhs) const
    {
        return !(*this == rhs);
    }
private:
    void makeEmpty()
    {
        makeEmpty ( root );
    }

    void insert( const C * x )
    {
        insert( x, root);
    }

    void remove( const C & x )
    {
        remove( x, root);
    }
    
private:
    BinaryNode *root;

    void insert ( const C & x, BinaryNode * & t)
    {
        if ( t == nullptr)
            t = new BinaryNode{x, nullptr, nullptr};
        else if(x < t ->element)
            insert( x, t ->left );
        else if(t ->element < x)
         insert(x, t->right);
        else
        {
            ;
        }
    }


    void remove( const C & x, BinaryNode * & t)
        {
            if ( t == nullptr)
            {
                cout << "nothing to remove" << endl;
                return;
            }
            if (x < t->element)
                remove(x,t->left);
            else if(t->element < x)
                remove(x, t->right);
            else
            {
                if(t -> left != nullptr && t -> right != nullptr)
                {
                    t->element = findMin( t->right ) ->element;
                    remove ( t->element, t->right );
                }
            else if(t->left != nullptr)
                {
                    BinaryNode *oldNode = t;
                    t = t->left;
                    delete oldNode;
                }
            else if(t->right != nullptr)
                {
                    BinaryNode *oldNode = t;
                    t = t->right;
                    delete oldNode;
                }
            else
            {
                assert( t->left == nullptr && t->right == nullptr);
                
                BinaryNode *oldNode = t;
                delete oldNode;
                t = nullptr;
            }
            }
            return;
        }


    // internal method to find smallest item in a subtree t
    // return node containing the smallest item
    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t==nullptr)
            return nullptr;
        if(t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    // internal method to finding the largeset 
    // item in a subtree t
    // return node containing the largest item
    BinaryNode * findMax(BinaryNode *t) const
    {
        if (t != nullptr)
            while(t->right != nullptr)
                t = t->right;
        return t;
    }


    // internal method to determine if item is in
    // subtree
    // x is item to search for
    // t is the node that roots the subtree
    bool contains(const C & x, BinaryNode *t) const
    {
        if ( t == nullptr)
        {
            return false;
        }else if(x < t->element)
        {
            return contains(x, t->left);
        }else if(t->element < x)
        {
            return contains(x, t->right);
        }
        else
        {
            cout << "found" << endl;
            return true; // match
        }
    }


    void makeEmpty(BinaryNode * & t)
        {
            if (t != nullptr)
            {
                makeEmpty (t->left);
                makeEmpty (t->right);
                delete t;
            }
            t = nullptr;
        }


    void printTree( BinaryNode *t, ostream & out) const
        {
            if (t != nullptr)
            {
                printTree(t->left, out);
                out << t->element <<endl;
                printTree(t->right, out);
            }
        }


    void printInternal(BinaryNode* t, int offset)
        {
            for(int i = 1; i <= offset; i++)
                cout << "..";
        
            if (t == nullptr)
            {
                cout << "@" << endl;
                return;
            }

            cout << t->element << endl;
            printInternal(t->left, offset + 1);
            printInternal(t->right, offset + 1);
        }

        BinaryNode * clone ( BinaryNode *t) const
        {
            if ( t == nullptr)
                return nullptr;
            else
                return new BinaryNode
                {
                    t ->element, clone ( t->left ), clone( t->right ) 
                };
        }
};
#endif