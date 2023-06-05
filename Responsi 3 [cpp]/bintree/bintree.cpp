#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

int main() {
    BinaryTree<int> treeRoot;
    treeRoot.setValue(1);
    BinaryTree<int>& treeL = treeRoot.addChild(2);
    BinaryTree<int>& treeR = treeRoot.addChild(3);
    BinaryTree<int>& treeLL = treeL.addChild(4);
    BinaryTree<int>& treeLR = treeL.addChild(5);
    BinaryTree<int>& treeRL = treeR.addChild(6);

    cout << treeRoot << endl;

    return 0;
}