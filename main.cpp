#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};


class BinarySearchTree {
private:
    Node* root;

    //Ekleme Fonksiyonu
    Node* insert(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    // Memory-safe Yýkýcý Fonksiyon (Post-order traversal)
    void destroyTree(Node* node) {
        if (node != NULL) {
            destroyTree(node->left);
            destroyTree(node->right);
            cout << "hafiza su deger icin bosaltiliyor: " << node->data << "\n";
            delete node; 
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    // Destructor (Yýkýcý Metot): Obje kapsam (scope) dýþýna çýkýnca OTOMATÝK çalýþýr.
    ~BinarySearchTree() {
        cout << "\n\ntree tamamen bosaltiliyor...\n";
        destroyTree(root);
    }

    // Kullanýcýya açýlan (Public) temiz arayüz
    void insert(int data) {
        root = insert(root, data);
        cout<<"\n"<<data<<" tree'ye yerlestirildi"; 
    }
};

int main() {
    {
        // Aðaç objesi bu süslü parantezler (scope) içinde yaþar
        BinarySearchTree bst;
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        
        cout << "\nbineary search tree atamasi tamamlanmistir";
        
    }
    
	cout << "\nprogram temiz bir sekilde sonuclanmistir";
    return 0;
}
