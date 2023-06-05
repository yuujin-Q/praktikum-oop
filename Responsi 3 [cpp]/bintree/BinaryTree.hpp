// Eugene Yap Jin Quan 13521074
#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class BinaryTree {
    private:
        T value;
        std::vector<BinaryTree<T>> children;
        int numChildren;

    public:
        // Default constructor, set numChildren = 0
        BinaryTree() : value(T()), numChildren(0) {}
        // Copy constructor
        BinaryTree(const BinaryTree<T>& other) {
            this->value = other.value;
            this->numChildren = other.numChildren;
            this->children = other.children;
        }
        // Destruktor
        ~BinaryTree() {
            this->children.clear();
        }

        // Setter untuk value
        void setValue(const T & newValue) {
            this->value = newValue;
        }

        /*
        Menambahkan anak binary tree dengan value tertentu.
        Fungsi ini membuat sebuah BinaryTree baru dan menambahkannya ke list of children.
        BinaryTree yang baru dibuat kemudian dikembalikan sebagai return value dari fungsi ini.
        Jika jumlah children sudah lebih dari dua, lemparkan exception "Tidak bisa memiliki lebih dari dua children\n".
        */
        BinaryTree<T>& addChild(T childValue) {
            if (this->numChildren >= 2) {
                throw "Tidak bisa memiliki lebih dari dua children\n";
            } else {
                BinaryTree<T> child;
                child.setValue(childValue);
                this->children.push_back(child);
                this->numChildren++;
                return this->children[this->numChildren - 1];
            }

        }

        /*
        Operator overloading untuk mencetak isi tree ke ostream.
        Format : <value>(<binary_tree_1>)(<binary_tree_2>)
        Tidak perlu ada newline di akhir.
        Berbagai contoh pencetakan binary tree :
        - Binary tree of integer tanpa children : 5()()
        - Binary tree of integer dengan satu children : 5(7()())()
        - Binary tree of integer dengan dua children : 5(7()())(6()())
        */
        friend ostream& operator<<(ostream& out, BinaryTree<T> root) {
            out << root.value;

            out << "(";
            if (root.numChildren > 0) 
                out << root.children[0];
            out << ")";

            out << "(";
            if (root.numChildren > 1)
                out << root.children[1];
            out << ")";
            return out;
        }


};
#endif