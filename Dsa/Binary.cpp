#include<iostream>
using namespace std;
class node{
	private:
		node* left;
		node* right;
		string title;
	public:
		node(string title="NULL"){
			this->title=title;
			right=NULL;
			left=NULL;
		}
		void display(){
			cout<<this->title<<endl;
		}
	friend class binary_tree;
};
class binary_tree{
	private:
		node* root;
	public:
		binary_tree(){
			this->root=NULL;
		}
		binary_tree(string title){
			root = new node(title);
		}
		
		void display(){
			if(root==NULL){
				cout<<"No book exist "<<endl;
				return;
			}
			preorder(root);
		}
		node* search(node* start,string title);
		node* last_search(node* start);
		void addchapter(string chapter_name);
		void addsection(string chapter_name,string section_name);
		void addsubsection(string chapter_name,string section_name,string sub_section_name);
		void preorder(node* root);
};
node* binary_tree::search(node* start,string title){
	node* last = start;
	if(last==NULL){
//		cout<<"Not exist"<<endl;
		return NULL;
	}
	else{
		while(last!=NULL){
			if(last->title==title){
				return last;
			}
			last=last->right;
		}
		return NULL;
	}
}
node* binary_tree::last_search(node* start){
	node* current = start;
	while(current->right!=NULL){
		current=current->right;
	}
	return current;
}
void binary_tree::preorder(node* root){
	cout<<root->title<<endl;
	preorder(root->left);
	preorder(root->right);
}
void binary_tree::addchapter(string chapter_name){
	if(root==NULL){
		cout<<"The book doesnt exist "<<endl;
	}
	else{
		node* chapter;
		node* Newchapter;
		node* lastchapter;
		chapter=root->left;
		if(chapter==NULL){
			root->left = new node(chapter_name);
			cout<<"Chapter is inserted successfully "<<endl;
		}
		else{
			Newchapter = search(chapter,chapter_name);
			if(Newchapter==NULL){
				lastchapter = last_search(chapter);
				lastchapter->right = new node(chapter_name);
				cout<<"Chapter is inserted successfully "<<endl;
			}
			else{
				cout<<"Duplicate found "<<endl;
			}
		}
	}
}
void binary_tree::addsection(string chapter_name,string section_name){
	if(root==NULL){
		cout<<"The book doesnt exist "<<endl;
		return;
	}
	else{
		node *chapter,*section,*last_section,*Newsection;
		chapter=root->left;
		if(chapter==NULL){
			cout<<"No chapter exist for inserting the section "<<endl;
		}
		else{
			chapter=search(chapter,chapter_name);
			if(chapter==NULL){
				cout<<"The chapter doesnt found "<<endl;
			}
			else{
				section = chapter->left;
				if(section==NULL){
					chapter->left = new node(section_name);
					cout<<"Section is added successfully"<<endl;
                    return;
				}
				else{
					Newsection = search(section,section_name);
					if(Newsection==NULL){
						last_section = last_search(section);
						last_section->right = new node(section_name);
						cout<<"Section is added successfully endl "<<endl;
					}
					else{
						cout<<"Duplicate entries found "<<endl;
					}
				}
			}
		}
	}
}

void binary_tree::addsubsection(string chapter_name,string section_name,string sub_section_name){
	if(root==NULL){
		cout<<"The book doesnt exist "<<endl;
		return;
	}
	else{
		node *chapter,*section,*subsection,*last_subsection,*Newsubsection;
		chapter = root->left;
		if(chapter==NULL){
			cout<<"Chapter doesnt exist "<<endl;
		}
		else{
			chapter = search(chapter,chapter_name);
			if(chapter==NULL){
				cout<<"Chapter not found "<<endl;
				return;
			}
			else{
				section = chapter->left;
				if(section==NULL){
					cout<<"The section doesnt exist "<<endl;
					return;
				}
				else{
					section = search(section,section_name);
					if(section==NULL){
						cout<<"Section doesnt find "<<endl;
						return;
					}
					else{
						subsection = section->left;
						if(subsection==NULL){
							section->left = new node(sub_section_name);
							cout<<"Subsection is added successfully "<<endl;
						}
						else{
							Newsubsection = search(subsection,sub_section_name);
							if(Newsubsection==NULL){
								last_subsection = last_search(subsection);
								last_subsection->right = new node(sub_section_name);
								cout<<"The Sub-section is added successfully "<<endl;
							}
							else{
								cout<<"Duplicate found "<<endl;
							}
						}
					}
				}
			}
		}
	}
}
int main(){
	string title;
	cout<<"Enter the title "<<endl;
	cin>>title;
	binary_tree bt(title);
	int ch;
	string chapter,section,subsection;
	do{
		cout<<"\n 1.Add chapter "<<endl;
		cout<<"\n 2.Add section "<<endl;
		cout<<"\n 3.Add subsection "<<endl;
		cout<<"\n 4.Display "<<endl;
		cout<<"\n 5.Exit "<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter chapter name "<<endl;
				cin>>chapter;
				bt.addchapter(chapter);
				break;
			case 2:
				cout<<"Enter chapter name "<<endl;
				cin>>chapter;
				cout<<"Enter section name "<<endl;
				cin>>section;
				bt.addsection(chapter,section);
				break;
			case 3:
				cout<<"Enter chapter name "<<endl;
				cin>>chapter;
				cout<<"Enter section name "<<endl;
				cin>>section;
				cout<<"Enter subsection name "<<endl;
				cin>>subsection;
				bt.addsubsection(chapter,section,subsection);
				break;
			case 4:
				bt.display();
			case 5:
				cout<<"Thank you "<<endl;
				break;
		}
	}while(ch!=5);
	return 0;
}
