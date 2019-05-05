#ifndef AVL_TREE
#define AVL_TREE

#include <iostream>


typedef int object;
class avlelem1{
    public:
        int height;
        object val;
        avlelem1 *left, *right;
};

class avltree1{
    private:
        avlelem1 *root;
        int Max(int a, int b);
        int GetHeight(avlelem1 *elem);
        void UpdateHeight(avlelem1 *elem);
        void Insert(avlelem1* &elem,object o);
        void DeleteTree(avlelem1 *root);
        void CheckRotationRight(avlelem1* &elem);
        void CheckRotationLeft(avlelem1* &elem);
        void Print(avlelem1 *curr);
        void PrintSorted(avlelem1 *curr);
        void RotateLeft(avlelem1* &a);
        void DoubleRotationLeft(avlelem1* &a);
        void RotateRight(avlelem1* &a);
        void DoubleRotationRight(avlelem1* &a);
        avlelem1* DeleteObject(avlelem1* &elem, object o);
    public:
        avltree1();
        ~avltree1();
        void Insert(object o); //insert value
        void Print();   //print tree
        void PrintSorted(int *nmbrs, int n);
        void DeleteObject(object o);    //delete value
};

avltree1::avltree1(){
    root = NULL;
}

avltree1::~avltree1(){
    DeleteTree(root);
    root = NULL;
}

void avltree1::DeleteTree(avlelem1 *root){
    if(root != NULL){
            if(root->left != NULL) DeleteTree(root->left);
            if(root->right != NULL) DeleteTree(root->right);
            delete root;
    }
}

int avltree1::Max(int a, int b){
    if(a < b) return b;
    else return a;
}

int avltree1::GetHeight(avlelem1 *elem){
    if(elem==NULL) return -1;
    else return elem->height;
}

void avltree1::UpdateHeight(avlelem1 *elem){
    elem->height = 1 + Max(GetHeight(elem->left), GetHeight(elem->right));
}

void avltree1::RotateLeft(avlelem1* &a){
    avlelem1 *b = a->right;
    a->right = b->left;
    b->left = a;
    a = b;
    UpdateHeight(a->left);
    UpdateHeight(a);
}

void avltree1::RotateRight(avlelem1* &a){
    avlelem1 *b = a->left;
    a->left = b->right;
    b->right = a;
    a = b;
    UpdateHeight(a->right);
    UpdateHeight(a);
}

void avltree1::DoubleRotationLeft(avlelem1* &a){
    RotateRight(a->right);
    RotateLeft(a);
}

void avltree1::DoubleRotationRight(avlelem1* &a){
    RotateLeft(a->left);
    RotateRight(a);
}

void avltree1::CheckRotationRight(avlelem1* &elem){
    if(elem != NULL){
            if(elem->left != NULL){
                if(GetHeight(elem->left) - GetHeight(elem->right) == 2){
                    if(GetHeight(elem->left->right) > GetHeight(elem->left->left)){
                        DoubleRotationRight(elem);
                    }else RotateRight(elem);
                }else UpdateHeight(elem);
            }else UpdateHeight(elem);
    }
}

void avltree1::CheckRotationLeft(avlelem1* &elem){
    if(elem != NULL){
            if(elem->right != NULL){
                if(GetHeight(elem->right) - GetHeight(elem->left) == 2){
                    if(GetHeight(elem->right->left) > GetHeight(elem->right->right)){
                        DoubleRotationLeft(elem);
                    }else RotateLeft(elem);
                }else UpdateHeight(elem);
            }else UpdateHeight(elem);
    }
}

void avltree1::Insert(avlelem1* &elem,object o){
    if(elem == NULL){
            elem = new avlelem1;
            elem->height = 0;
            elem->val = o;
            elem->left = NULL;
            elem->right = NULL;
    }else{
        if(o <= elem->val){
                Insert(elem->left, o);
                CheckRotationRight(elem);
        }else{
            Insert(elem->right, o);
            CheckRotationLeft(elem);
        }
    }
}

void avltree1::Insert(object o){
    Insert(root, o);
}

avlelem1* searchMin(avlelem1* root){
   avlelem1* pre;
    while(root->left != NULL){
        pre = root;
        root = root->right;
    }
    pre->right = root->right;
    //printf("%d\n", root->val);
    return root;
}

avlelem1* avltree1::DeleteObject(avlelem1* &elem, object o){
    avlelem1* save;
    avlelem1* curr;
            if (elem->left != NULL && elem->left->val == o){
                save = elem->left;
                if(save->left == NULL && save->right == NULL){
                        elem->left = NULL;
                        delete save;
                        CheckRotationLeft(elem->left);
                        CheckRotationRight(elem->left);
                        return elem;
                    }
                if(save->left == NULL && save->right != NULL){
                        elem->left = save->right;
                        delete save;
                        CheckRotationLeft(elem->left);
                        CheckRotationRight(elem->left);
                        return elem;
                    }
                if(save->left != NULL && save->right == NULL){
                        elem->left = save->left;
                        delete save;
                        CheckRotationLeft(elem->left);
                        CheckRotationRight(elem->left);
                        return elem;
                    }
                if(save->left != NULL && save->right != NULL){
                        curr = searchMin(save);
                        if(save->left != curr){
                            curr->left = save->left;
                        }
                        if(save->right != curr){
                            curr->right = save->right;
                        }
                        elem->left = curr;
                        delete save;
                        CheckRotationLeft(elem->left);
                        CheckRotationRight(elem->left);
                        return elem;
                    }
            }else if(elem->right != NULL && elem->right->val == o){
                save = elem->right;
                if(save->left == NULL && save->right == NULL){
                        elem->right = NULL;
                        delete save;
                        CheckRotationLeft(elem->right);
                        CheckRotationRight(elem->right);
                        return elem;
                    }
                if(save->left == NULL && save->right != NULL){
                        elem->right = save->right;
                        delete save;
                        CheckRotationLeft(elem->right);
                        CheckRotationRight(elem->right);
                        return elem;
                    }
                if(save->left != NULL && save->right == NULL){
                        elem->right = save->left;
                        delete save;
                        CheckRotationLeft(elem->right);
                        CheckRotationRight(elem->right);
                        return elem;
                    }
                if(save->left != NULL && save->right != NULL){
                        curr = searchMin(save);
                        if(save->left != curr){
                            curr->left = save->left;
                        }
                        if(save->right != curr){
                            curr->right = save->right;
                        }
                        elem->right = curr;
                        CheckRotationLeft(elem->right);
                        CheckRotationRight(elem->right);
                        delete save;
                        return elem;
                }
    }else{
        if(o <= elem->val){
            elem->left = DeleteObject(elem->left, o);
            CheckRotationRight(elem->left);
            return elem;
        }else{
            elem->right = DeleteObject(elem->right, o);
            CheckRotationLeft(elem->right);
            return elem;
        }
    }
}

void avltree1::DeleteObject(object o){
    DeleteObject(root, o);
    CheckRotationLeft(root);
    CheckRotationRight(root);
}

void avltree1::Print(){
    Print(root);
    printf("\n");
}

void avltree1::Print(avlelem1 *root){
    if(root!=NULL){
        printf("(");
        Print(root->left);
        printf(",%d,", root->val);
        Print(root->right);
        printf(")");
    }else{
        printf("n");
    }
}

void avltree1::PrintSorted(int *nmbrs, int n){
    for(int i = 0; i < n; i++){
        Insert(nmbrs[i]);
    }
    PrintSorted(root);
    printf("\n");
}

void avltree1::PrintSorted(avlelem1 *root){
    if(root!=NULL){
        PrintSorted(root->left);
        printf("%d,", root->val);
        PrintSorted(root->right);
    }
}

#endif // AVL_TREE
