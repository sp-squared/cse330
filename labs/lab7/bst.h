// Colin Morris-Moncada
// Lab 7 
// Binary Search Tree Header File

#ifndef BST_H
#define BST_H
#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;


// Typename C for Comparable aka = < >
template <typename C>
class BinarySearchTree
{
    public:

        // DEFAULT CONSTRUCTORS
        BinarySearchTree()
            : root{nullptr}
            {}
        BinarySearchTree(const BinarySearchTree & rhs)
            : root{nullptr}
            {
                root = clone (rhs. root);
            }
        BinarySearchTree(BinarySearchTree &&  rhs)
            : root{rhs.root}
            {
                rhs.root = nullptr;
            }

        // DESTRUCTOR 
        ~BinarySearchTree()
        {
            makeEmpty();
        }

        // EQUAL OPERATORS for pass by const ref and pass by ref 
        BinarySearchTree & operator=( const BinarySearchTree & rhs )
        {
            BinarySearchTree copy = rhs;
            std::swap(*this , copy);
            return *this;
        }

        BinarySearchTree & operator=( BinarySearchTree && rhs )
        {
            std::swap( root , rhs.root );
            return *this;
        }

        // MEMBER FUNCTION PROTOTYPES
        const C & findMin() const
        {
            assert( !isEmpty());
            return findMin( root ) -> element;
        }

        const C & findMax() const
        {
            assert( !isEmpty());
            return findMax( root ) -> element;
        }


        bool contains (const C & x) const
        {
            return contains (x,root);
        }
        
        bool isEmpty() const
        {
            return root == nullptr;
        }

        void printTree ( ostream & out = cout ) const
        {
            if( isEmpty() )
            {
                out << "empty tree" << endl;
            }
            else
            {
                printTree ( root, out );

            }
        }

        void makeEmpty()
        {
            makeEmpty( root );
        }

        // insert pass by const and pass by ref
        void insert (const C & x )
        {
            insert( x, root);
        }

        void insert (C && x)
        {
            insert (std::move(x), root);
        }

        void remove( const C & x)
        {
            remove (x,root);

        }


        void printInternal()
        {
            printInternal(root,0);
        }
    private:

        // DEFINING OUR MEMBER FUNCTIONS

        struct BinaryNode
        {
            C element;
            BinaryNode *left;
            BinaryNode *right;

            BinaryNode(const C & theElement, BinaryNode *lt, BinaryNode *rt )
                : element{ theElement}, left{lt}, right{rt}
                {}
            BinaryNode( C && theElement, BinaryNode *lt, BinaryNode *rt)
                :element{std::move(theElement)}, left{lt}, right{rt}
                {}
        };

        BinaryNode *root;

        // Internal method to insert into a subtree
        // x is the item to insert
        // t is the node that roots the subtree
        // sets the new root of the subtree
        void insert ( const C & x, BinaryNode * & t)
        {
            if ( t == nullptr)
                t = new BinaryNode{x, nullptr, nullptr};
            else if(x < t ->element)
                insert( x, t ->left );
            else if(t ->element < x)
             insert(x, t->right);
            else
                ;
        }

        // Internal method to insert into a subtree
        // x is the item to insert
        // t is the node that roots the subtree
        // sets the new root of the subtree


        void insert (C && x, BinaryNode * & t )
        {
            if (t == nullptr)
                t = new BinaryNode{std::move(x), nullptr, nullptr};
            else if(x < t->element)
                insert(std::move(x), t->left);
            else if(t->element < x)
                insert (std::move(x), t->right);
            else
                ;
        }

        // internal method to remove a subtree
        // x is the item to remove
        // t is the node that roots the subtree
        // sets the new root of the subtree

        void remove( const C & x, BinaryNode * & t)
        {
            if ( t == nullptr)
                return;
            if (x < t->element)
                remove(x,t->left);
            else if(t->element < x)
                remove(x, t->right);
            else if(t->left != nullptr && t->right != nullptr)
            {
            // aka the two children
                t->element = findMin(t->right) ->element;
                remove (t->element, t->right);
            }
            else
            {
                BinaryNode *oldNode = t;
                t = (t->left != nullptr) ? t->left : t->right;
                delete oldNode;
            }
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
                cout << "not found" << endl;
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

        BinaryNode *clone (BinaryNode *t) const
        {
            if (t == nullptr)
            {
                return nullptr;
            }
            else
            {
              return new BinaryNode{t->element, clone(t->left), clone(t->right)};  
            }
        }

        void printInternal(BinaryNode* t, int offset)
        {
            if (t == nullptr)
                return;
        
            for(int i = 1; i <= offset; i++)
                cout << "@";
        
            cout << t->element << endl;
            printInternal(t->left, offset + 1);
            printInternal(t->right, offset + 1);
        }

    
};
#endif
