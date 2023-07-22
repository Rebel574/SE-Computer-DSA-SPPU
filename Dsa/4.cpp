#include<iostream>
using namespace std;
class node
{
    int data;
    node*left,*right;
    
    public:

    node()
    {
        left=right=NULL;
        data=0;
    }

    friend class Btree;
    friend class stack;
    friend class queue;
};
class stack
{
    public:
    int top;
    node *a[100];
    stack()
    {
        top=-1;
    }
    void push(node *rt)
    {   
        if(top>=99)
        {
            cout<<"\nStack overflow!";
        }
        else
        {
            top++;
            a[top]=rt;
        }
    }
    node *pop()
    {
        if(top==-1)
        {
            cout<<"\nStack is empty!";
            return 0;
        }
        else
        {
            node *temp;
            temp=a[top];
            top--;
            return temp;
        }
    }
    bool isempty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
  
};

class queue
{
    node *start,*end;
    public:
    queue()
    {
        start=NULL;
    }    
    void enqueue(node *temp)
    {
        if(start==NULL)
        {
            start=temp;
            end=temp;
        }
        else
        {
            end->right=temp;
            end=temp;
        }
    }

    node *dequeue()
    {
        node *temp=start;
        if(start==NULL)
        {
            cout<<"\nQueue is empty";
            return NULL; 
        }
        else
        {
            start=start->right;
            return temp;
        }
    }


    bool isempty()
    {
        if(start==NULL)
            return true;
        else
            return false;
    }
 
};

class Btree
{
    node*head;
    public:
    Btree()
    {
        head=NULL;
    }

    void insert();
    void create();
    void search();
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
    void display();
    node*mirroring(node*);
    void mirror();
    void longestpathnodes();
    int count(node*);
    void minimumandmaximum();
    void dlt();
    void lvlorder(node*);
    void pre_nonrec(node*);
    void in_nonrec(node*);
    //void post_nonrec(node*);

};

  void Btree:: pre_nonrec(node*rt)
    {  
        node *travel=rt;
        if(rt==NULL)
        {
            cout<<"\nTree is empty!";
        }
        else
        {
            stack s;
            s.push(travel);
            while(!s.isempty())
            {
                travel=s.pop();
                cout<<travel->data<<" ";
                if(travel->right!=NULL)
                    s.push(travel->right);
                if(travel->left!=NULL)    
                    s.push(travel->left);
            }
            
        }
    }

    void  Btree::in_nonrec(node *rt)
    {
        if(rt==NULL)
        {
            cout<<"\nTree is empty!";
        }
        else
        {
            node *travel=rt;
            stack s;
            while(travel!=NULL)
            {
                s.push(travel);
                travel=travel->left;
            }
            while(!s.isempty())
            {
                travel=s.pop();
                cout<<travel->data<<" ";
                if(travel->right!=NULL)
                {
                    travel=travel->right;
                    while(travel!=NULL);
                    {
                        s.push(travel);
                        travel=travel->left;
                    } 
                }               
            }
        }

    }

    void Btree::lvlorder(node *rt)
    {
        queue q;
        if(head==NULL)
            cout<<"\nTree is empty!";
        else
        {
            node *temp;
            q.enqueue(rt);
            while(!q.isempty())
            {
                temp=q.dequeue();
                cout<<temp->data<<" ";
                if(temp->left!=NULL)
                    q.enqueue(temp->left);
                if(temp->right!=NULL)
                    q.enqueue(temp->right);
            }
        }
    }

void Btree::insert()
{
    node*temp,*travel;
    temp=new node();

    if(head==NULL)
    {
        cout<<"\nEnter the data for root node:: ";
        cin>>temp->data;
        head=temp;
    }
    else
    {
        travel=head;
        int ins=0;
        cout<<"\nEnter the data for new node:: ";
        cin>>temp->data;
        do
        {
            if(travel->data>temp->data)
            {
                    if(travel->left==NULL)
                    {
                        travel->left=temp;
                        ins=1;
                    }
                    else
                    {
                        travel=travel->left;
                    }
            
            }
            else if(travel->data<=temp->data)
            {
                if(travel->right==NULL)
                    {
                        travel->right=temp;
                        ins=1;
                    }
                    else
                    {
                        travel=travel->right;
                    }

            }
        }while(ins!=1);
    }
}

void Btree::create()
{
    if(head!=NULL)
    {
        cout<<"\nTree already created....";
    }
    else
    {
        int n;
        cout<<"\nHow many totals nodes do you want including the root node...:: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            insert();
        }
    }
}

void Btree::display()
{
    if(head==NULL)
    {
        cout<<"\nTree is empty ....try inserting nodes....";
    }
    else
    {
        int b,c;
        
        cout<<"\n~~~~~~~~~~menu for display~~~~~~~~~\n\n1.recursive\n2.nonrecursive\n\nEnter your choice..: ";
        cin>>b;
        switch(b)
        {
            case 1:
                cout<<"\n~~~~~~MENU for RECURSIVE~~~~~~~~~~~~~~\n\n1.preorder\n2.inorder\n3.postorder\n\nEnter your choice..: ";
                cin>>c;
                switch(c)
                {
                    case 1:
                        preorder(head);
                        break;
                    case 2:
                        inorder(head);
                        break;
                    case 3:
                        postorder(head);
                        break;
                    default:
                        cout<<"\nEnter valid choice:: ";
                }
                break;
            case 2:
                cout<<"\n~~~~~~MENU for NONRECURSIVE~~~~~~~~~~~~~~\n\n1.preorder\n2.inorder\n3.postorder\n4.levelwise\n\nEnter your choice..: ";
                cin>>c;
                switch(c)
                {
                    case 1:
                        pre_nonrec(head);
                        break;
                    case 2:
                        in_nonrec(head);
                        break;
                    case 3:
                       // post_nonrec(head);
                        break;
                    case 4:
                            lvlorder(head);
                            break;
                    default:
                        cout<<"\nEnter valid choice:: ";
                }
                break;
            default:
            cout<<"\nEnter valid choice....";
        }
    }
}

void Btree::preorder(node*root)
{
   // root=head;
    if(root!=NULL)
    {
        preorder(root->right);
        cout<<root->data<<"  ";
        preorder(root->left);
        
    }
}

void Btree::inorder(node*root)
{
   // root=head;
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}
void Btree::postorder(node*root)
{
   // root=head;
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"  ";
    }
}

void Btree::dlt()
{
    int key;
    node*travel;
    travel=head;
    node*suces,*parent;
    if(head==NULL)
    {
        cout<<"\nTree empty cant delte....";
    }
    else{
        
        cout<<"\nEnter the data to be deleted..: ";
        cin>>key;
        
       
        while(travel!=NULL)
        {
            if(travel->data>key)
            {
                parent=travel;
                travel=travel->left;
            }
            else if(travel->data<key)
            {
                parent=travel;
                travel=travel->right;
            }
            else if(travel->data==key)
            {
                    cout<<"\nKey found..";
                    break;
            }
            else
            {
                cout<<"\nKey is not present in the given record .....try searching another...::";
            }
        } 

        if(travel->left==NULL && travel->right==NULL)
        {
            if(travel==head)
            {
                head==NULL;
                delete travel;
                travel=NULL;
                return;
            }
            else if(parent->left==travel)
            {
               
            }
            else
            {
                parent->right=NULL;
                delete (travel);
                travel=NULL; 
                return;
            }
         }

        else if(travel->left!=NULL && travel->right!=NULL)
        {
          parent=travel;
          suces=travel->right;
          while(suces->left!=NULL)
          {
            parent=suces;
            suces=suces->left;
          }
          travel->data=suces->data;
           parent->left=NULL;
            delete (suces);
            suces=NULL; 
          return;   
        }

        else
        {   
          if(travel->left==NULL && travel->right!=NULL)
          {
                suces=travel->right;
                travel->data=suces->data;
                travel->right=NULL;
                delete(suces);
                suces=NULL;
                return;
          }
         else  if(travel->left!=NULL && travel->right==NULL)
          {
                suces=travel->left;
                travel->data=suces->data;
                travel->left=NULL;
                delete(suces);
                suces=NULL;
                return;
          }
            

         }   
    }
}

int Btree::count(node*travel)
{
     if(travel==NULL)
        return(0);
    if(travel->left==NULL && travel->right==NULL)
        return(1);
    return(max(count(travel->left),count(travel->right))+1);
}

void Btree::longestpathnodes()
{

if(head==NULL)
    cout<<"\nEmpty Tree.....";
else{
   int a=count(head);
   cout<<"\nMaximum nodes are  : "<<a;
    }
   
}

void Btree::minimumandmaximum()
{
    if(head==NULL)
    cout<<"\nEmpty Tree.....";
    else{   
    node*travel=head;
    //minimum
    while(travel->left!=NULL)
    {
        travel=travel->left;
    }
    cout<<"\nThe minimum element is "<<travel->data<<" .";
    travel=head;
    while(travel->right!=NULL)
    {
        travel=travel->right;
    }
    cout<<"\nThe Maximum element is "<<travel->data<<" .";
    }
}

node*Btree::mirroring(node*travel)
{
 
    node*temp;
    if(travel==NULL)
        return NULL;
    else
    {
        temp=travel->left;
        travel->left=mirroring(travel->right);
        travel->right=mirroring(temp);
        return travel;
    }

}

void Btree::mirror()
{
    if(head==NULL)
    cout<<"\nEmpty Tree.....";
    else
    mirroring(head);
}

void Btree::search()
{
    node*travel=head;
    if(head==NULL)
    {
        cout<<"\nEMpty treee";
    }
    else
    {
        int key;
        cout<<"\nEnter the key to be searved:: ";
        cin>>key;
        while(travel!=NULL)
        {
        if(travel->data==key)
        {
            cout<<"\nkey found...";
            break;
        }
        else if(travel->data>key)
        {
            travel=travel->left;
        }
        else if(travel->data<key)
        {
            travel=travel->right;
        }
        
        }
        if(travel==NULL)
        {
            cout<<"\nKey is not found int the tree...";
            
        }
    }
}
int main()
{
    Btree b;
    int ch;
    do
    {
        cout<<"\n~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~\n\n1.create\n2.insert\n3.search\n4.display\n5.longestpathnodes\n6.minand max\n7delete\n8.mirror\n9.exit\n\nEntre your choice :: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            b.create();
            break;
        case 2:
            b.insert();
            break;
        case 3:
            b.search();
            break;
        case 4:
            b.display();
            break;
        case 5:
            b.longestpathnodes();
            break;
        case 6:
            b.minimumandmaximum();
            break;
        case 7:
            b.dlt();
        case 8:
            b.mirror();
            break;
        case 9:
            break;
        
        default:
            cout<<"\nEnter valid choice plzz.....";
        }
    }while(ch!=9);
    return 0;
}
