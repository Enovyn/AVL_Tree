#include "avl_tree.h"
#include <iostream>

int main(){
avltree1 a;
a.Insert(5);
a.Insert(6);
a.Insert(9);
a.Insert(12);
a.Insert(13);
a.Insert(3);
a.Insert(8);
a.Insert(10);
a.Insert(11);
a.Insert(16);
a.Insert(15);
a.Insert(14);
a.Insert(4);
a.Insert(2);
a.Insert(1);

a.Print();

a.DeleteObject(12);
printf("\n\n");
a.Print();

a.DeleteObject(8);
printf("\n\n");
a.Print();

a.DeleteObject(5);
printf("\n\n");
a.Print();

a.DeleteObject(4);
printf("\n\n");
a.Print();

a.DeleteObject(3);
printf("\n\n");
a.Print();

a.DeleteObject(6);
printf("\n\n");
a.Print();

a.DeleteObject(15);
printf("\n\n");
a.Print();

a.DeleteObject(14);
printf("\n\n");
a.Print();

return 0;
}
