// 4.3 Binary Search Tree ADT (pg 132)
#ifndef BST_H
#define BST_H
template <typename C>
class BinarySearchTree
{
    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree  & rhs);
        BinarySearchTree(BinarySearchTree && rhs);
        ~BinarySearchTree();

        const C & findmin() const;
        const C & findmax() const;
        bool contains (const C & x) const;










};
#endif