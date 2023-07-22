#include<iostream>
#include<queue>
using namespace std;
class node{
	private:
		string data;
		node* left;
		node* right;
		int height;
	public:
		node(string data){
			this->data=data;
			left=NULL;
			right=NULL;
			height=1;
		}
	friend class avl;
};
class avl{
	private:
		node* root;
		int call_height(node* root){
			if(root->left!=NULL && root->right!=NULL){
				if(root->right->height > root->left->height){
					return root->right->height+1;
				}
				else{
					return root->left->height+1;
				}
			}
			else if(root->left!=NULL && root->right==NULL){
				return root->left->height+1;
			}
			else if(root->left==NULL && root->right!=NULL){
				return root->right->height+1;
			}
			else{
				return 0;
			}
		}
		int bf(node* root){
			//cout<<"Hiee"<<endl;
			int ans;
			if(root->left!=NULL && root->right!=NULL){
				ans= root->left->height-root->right->height;
			}
			else if(root->left==NULL && root->right!=NULL){
				ans= -root->right->height;
			}
			else if(root->left!=NULL && root->right==NULL){
				ans= root->left->height;
			}
			return ans;
		}
	public:
		avl(){
			this->root=NULL;
		}
		node* ll_rotation(node* root){
			cout<<"Hii"<<endl;
			node* a=root;
			node* b=root->left;
			a->left=b->right;
			b->right=a;
			return b;
		}
		node* rr_rotation(node* root){
			node* a=root;
			node* b=root->right;
			a->right=b->left;
			b->left=a;
			return b;
		}
		node* lr_rotation(node* root){
			node* a=root;
			node* b=root->left;
			node* c=root->left->right;
			b->right=c->left;
			a->left=c->right;
			c->left=b;
			c->right=a;
			return c;
		}
		node* rl_rotation(node* root){
			node* a=root;
			node* b=root->right;
			node* c=root->right->left;
			a->right=c->left;
			b->left=c->right;
			c->left=a;
			c->right=b;
			return c;
		}
		node* insert(node* root,string data){
			if(root==NULL){
				root = new node(data);
				return root;
			}
			if(root->data > data){
				root->left = insert(root->left,data);
			}
			if(root->data < data){
				root->right = insert(root->right,data);
			}
			root->height = call_height(root);
			if(bf(root)==2 && bf(root->left)==1){
				root=ll_rotation(root);
			}
			if(bf(root)==2 && bf(root->left)==-1){
				root=lr_rotation(root);
			}
			if(bf(root)==-2 && bf(root->right)==-1){
				root=rr_rotation(root);
			}
			if(bf(root)==-2 && bf(root->right)==1){
				root=rl_rotation(root);
			}
			return root;
		}
		void insert(){
			string data;
			cout<<"ENter the string for input "<<endl;
			cin>>data;
			root = insert(root,data);
		}
		void inorder(node* root){
			if(root==NULL){
				return;
			}
			inorder(root->left);
			cout<<root->data<<" ";
			inorder(root->right);
		}
		void inorder(){
			node* current=root;
			inorder(current);
		}
		node* mini(node* root){
			node* temp=root;
			while(temp->left!=NULL){
				temp=temp->left;
			}
			return temp;
		}
		node* delete_avl(node* root,string data){
			if(root==NULL){
				cout<<"The tree is empty "<<endl;
				return NULL;
			}
			if(root->data == data){
				//4 case
				if(root->left==NULL && root->right==NULL){
					delete root;
					return NULL;
				}
				if(root->left!=NULL && root->right==NULL){
					node* temp=root->left;
					delete root;
					return temp;
				}
				if(root->left==NULL && root->right!=NULL){
					node* temp=root->right;
					delete root;
					return temp;
				}
				if(root->left!=NULL && root->right!=NULL){
					node* temp = mini(root->right);
					root->data = temp->data;
					root->right = delete_avl(root->right,temp->data);
				}
			}
			if(root->data > data){
				root->left = delete_avl(root->left,data);
			}
			if(root->data < data){
				root->right = delete_avl(root->right,data);
			}
			
			if(bf(root)==2 && bf(root->left)==1){
				root = ll_rotation(root);
			}
			if(bf(root)==2 && bf(root->left)==0){
				root = ll_rotation(root);
			}
			if(bf(root)==-2 && bf(root->right)==-1){
				root = rr_rotation(root);
			}
			if(bf(root)==-2 && bf(root->right)==0){
				root = rr_rotation(root);
			}
			if(bf(root)==2 && bf(root->left)==-1){
				root = lr_rotation(root);
			}
			if(bf(root)==-2 && bf(root->right)==1){
				root = rl_rotation(root);
			}
			return root;
		}
		void delete_avl(){
			string data;
			cout<<"Enter the string for deletion "<<endl;
			cin>>data;
			root = delete_avl(root,data);
		}
	void levelordertraversal(node* root){
	if(root==NULL){
		return;
	}
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
			q.push(NULL);
			}
		}
		else{
		cout<<temp->data<<"  ";
		if(temp->left){
			q.push(temp->left);
		}
		if(temp->right){
			q.push(temp->right);
		}
	}
}

}
void level(){
	levelordertraversal(root);
}
};
int main(){
	avl a;
	int ch;
	do{
		cout<<"\n1. Insert in tree "<<endl;
		cout<<"\n2. display in a tree "<<endl;
		cout<<"\n3. Deletion in a tree "<<endl;
		cout<<"\n4. Exit "<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				a.insert();
				break;
			case 2:
				a.level();
				break;
				
			case 3:
				a.delete_avl();
				break;
			case 4:
				cout<<"thank you "<<endl;
				break;
		}
	}while(ch!=4);
	return 0;
}
