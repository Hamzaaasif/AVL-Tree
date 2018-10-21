#include<iostream>
using namespace std;
class AVL
{
  public:
void insert(int val,AVL **root)
  {
    AVL *ptr=new AVL;
    ptr->data=val;
    ptr->rightchild=NULL;
    ptr->leftchild=NULL;
    if(*root==NULL)
    {
      *root=ptr;
    }
    else
    {
      AVL *curr=*root;
      while(curr!=NULL)
      {
        if(curr->data > val)
        {
          
          if(curr->leftchild==NULL)
          {
            curr->leftchild=ptr;
            break;
          }
          curr=curr->leftchild;
        }
        else
        {
          
          if(curr->rightchild==NULL)
          {
            curr->rightchild=ptr;
            break;
          }
          curr=curr->rightchild;
        }
    }
  }

  AVL *temp=checkheight(*root);
  int height=-1;
  int Lheight=leftheight(*root,height);
  int Rheight=rightheight(*root,height);
  if(temp!=NULL && Lheight-Rheight > 1)
  {
    cout<<"Tree build from left unbalanced node is : "<<temp->data;
    shiftright(root,temp);
    cout<<endl;
  }
  if(temp!=NULL && Rheight-Lheight > 1)
  {
    cout<<"Tree build from Right unbalanced node is : "<<temp->data;
    shiftleft(root,temp);
    cout<<endl;
  }

}
  
int rightheight(AVL *root ,int height) //calculate height from right tree
  {
    if(root==NULL)
    {
      return height;
    }
    height++;
    rightheight(root->rightchild , height);
  }
  int leftheight(AVL *root ,int height) //calculate height from left tree
  {
    if(root==NULL)
    {
      return height;
    }
    height++;
    leftheight(root->leftchild,height);
  }
  AVL* checkheight(AVL *root)
  {
    if(root==NULL)
    {
      return NULL;
    }
    else
    {
    int height=-1;
    int Lheight=leftheight(root,height);
    int Rheight=rightheight(root,height);
    checkheight(root->rightchild);
    checkheight(root->leftchild);
    if(Lheight-Rheight > 1 || Rheight-Lheight > 1 )
    {
      return root;
    }
    else
    {
      return NULL;
    }
 }
}
AVL* prevnode(AVL* root,AVL* search)
{
  if(root->leftchild == search || root->rightchild == search)
  {
    return root;
  }
  else if((root->leftchild)->data > search -> data )
  {
    prevnode(root->leftchild , search);
  }
  else
  {
    prevnode(root->rightchild , search);
  }
}
  AVL* shiftleft(AVL** root,AVL* wrongroot) //when trees grows on right side
  {
    AVL*curr=wrongroot->rightchild;
    AVL*temp=NULL;
    if(curr->leftchild != NULL)
    {
      temp=curr->leftchild;
    }
    curr->leftchild=wrongroot;
     if(wrongroot==*root)
    {
      wrongroot->rightchild=NULL;
      *root=curr;
    }
    else
    {
      AVL*prev = prevnode((*root),wrongroot);
      prev->rightchild=curr;
    }
    if(temp!=NULL)
    {
      curr->leftchild->rightchild=temp;
    }
    return curr;
  }

  void shiftright(AVL** root,AVL* wrongroot) //when trees grows on left side
  {
    AVL*curr=wrongroot->leftchild;
    AVL*temp=NULL;
    if(curr->rightchild != NULL)
    {
      temp=curr->rightchild;
    }
    curr->rightchild = wrongroot;
    if(wrongroot==*root)
    {
      wrongroot->leftchild=NULL;
      *root=curr;
    }
    else
    {
      AVL*prev = prevnode((*root),wrongroot);
      prev->leftchild=curr;
    }
     if(temp!=NULL)
    {
      curr->rightchild->leftchild= temp;
    }
  }
  void print(AVL *root)
  {
    if(root==NULL)
    {
      return;
    }
    cout<<root->data<< " ";
    print(root->leftchild);
    print(root->rightchild);
    
    
  }
 

  private:
  int data;
  AVL *rightchild;
  AVL *leftchild;
  int height;
};