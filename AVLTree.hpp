#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

#include "Utility.hpp"

namespace ft
{
    template <typename E, typename Compare, bool AllowDuplicate>
    class AVLTree;

    template <typename E, typename Compare, bool AllowDuplicate>
    class AVLTreeIterator
    {
        private:
                typedef AVLTree<E, Compare, AllowDuplicate> tree;
                typedef typename tree::node node;

                tree& _tree;
                node* _node;

                AVLTreeIterator(tree& t, node *n): _tree(t), _node(n)
                {
                }

        public:
                typedef std::ptrdiff_t difference_type;
                typedef E value_type;
                typedef E* pointer;
                typedef E& reference;
                typedef BidirectionalIteratorTag iterator_category;

                AVLTreeIterator(const AVLTreeIterator<E, Compare, AllowDuplicate>& other): _tree(other._tree), _node(other._node)
                {
                }

                ~AVLTreeIterator()
                {
                }

                AVLTreeIterator<E, Compare, AllowDuplicate>& operator=(const AVLTreeIterator<E, Compare, AllowDuplicate>& other)
                {
                    _node = other._node;
                    return *this;
                }

                AVLTreeIterator<E, Compare, AllowDuplicate>& operator++()
                {

                }
    };

    template <typename E, typename Compare, bool AllowDuplicate>
    class AVLTree
    {
        private:
                struct node
                {
                    E el;
                    node* parent;
                    node* right;
                    node* left;
                    int height;

                    node(E el_, node* parent_, node* right_, node*left_, int height_): el(el_), parent(parent_), right(right_), left(left_), height(height_)
                    {
                    }
                };

                Compare _cmp;
                node* _root;
                size_t _len;

                static int balance_factor(node* n)
                {
                    if (!n)
                        return 0;
                    return (n->left ? n->left->height : -1) -       (n->right > n->right->height : -1);
                }
    };
}

#endif