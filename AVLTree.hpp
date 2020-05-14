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

                static void rotate_left(node** target)
			{
				node* y = (*target)->right;
				node* parent = (*target)->parent;
				(*target)->parent = y;
				y->parent = parent;
				(*target)->right = y->left;
				y->left = *target;
				(*target)->height = max(
					(*target)->left ? (*target)->left->height : -1,
					(*target)->right ? (*target)->right->height : -1
				) + 1;
				*target = y;
				y->height = max(
					y->left ? y->left->height : -1,
					y->right ? y->right->height : -1
				) + 1;
			}

			static void rotate_right(node** target)
			{
				node* y = (*target)->left;
				node* parent = (*target)->parent;
				(*target)->parent = y;
				y->parent = parent;
				(*target)->left = y->right;
				y->right = *target;
				(*target)->height = max(
					(*target)->left ? (*target)->left->height : -1,
					(*target)->right ? (*target)->right->height : -1
				) + 1;
				*target = y;
				y->height = max(
					y->left ? y->left->height : -1,
					y->right ? y->right->height : -1
				) + 1;
			}

            static void deep_free(node*& n)
			{
				if (!n)
					return;
				deep_free(n->left);
				deep_free(n->right);
				delete n;
				n = NULL;
			}

            static void print_rec(node* n, int indent = 1)
			{
				std::stringstream ss;
				for (int i = 0; i < indent; i++) ss << ">>";
				if (!n)
				{
					printf("%s NULL\n", ss.str().c_str());
					return;
				}
				printf("%s El is %d (h = %d, balance = %d)\n", ss.str().c_str(), n->el.first, n->height, balance_factor(n));
				printf("%s Left\n", ss.str().c_str());
				print_rec(n->left, indent + 1);
				printf("%s Right\n", ss.str().c_str());
				print_rec(n->right, indent + 1);
			}

            static int max(int a, int b)
			{
				return a > b ? a : b;
			}

			static node* deep_cpy(node *parent, node* n)
			{
				if (!n)
					return NULL;
				node* cpy = new node(n->el, parent, NULL, NULL, n->height);
				cpy->left = deep_cpy(cpy, n->left);
				cpy->right = deep_cpy(cpy, n->right);
				return cpy;
			}
    };
}

#endif