#include<iostream>
using namespace std;
#include"AVL.h"
int main()
{
   AVL *root=NULL;
  AVL binary;
  binary.insert(135,&root);
  binary.insert(120,&root);
  binary.insert(30,&root);
  binary.insert(60,&root);
  binary.insert(20,&root);
  binary.insert(18,&root);
  binary.insert(75,&root);
 
  binary.print(root);
  cout<<endl;
  
  system("pause");
}