#include<iostream>
using namespace std;

struct node{
	int value;
	node *left,*right;
};

int N,Post[40],In[40];
node* makenode(int h1,int t1,int h2,int t2){
	if(h1>t1)return nullptr;
	node *p = new node;
	p->value = Post[t1];
	int index;
	for(index=h2;In[index]!=Post[t1];index++);
	p->left = makenode(h1,index-1-h2+h1,h2,index-1);
	p->right = makenode(index-h2+h1,t1-1,index+1,t2);
	return p;
}


int main(){
	cin>>N;
	int i;
	for(i = 0;i<N;i++){
		cin>>Post[i];
	}
	for(i = 0;i<N;i++){
		cin>>In[i];
	}
	node* root = makenode(0,N-1,0,N-1);
	node* Queue[40];
	int head = 0,tail = 0;
	Queue[tail++] = root;
	while(head<tail){
		if(head!=0){
			cout<<' ';
		}
		node* p = Queue[head++];
		cout<<p->value;
		if(p->left){
			Queue[tail++] = p->left;
		}
		if(p->right){
			Queue[tail++] = p->right;
		}
	}
	return 0;
}