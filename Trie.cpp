#include<bits/stdc++.h>

using namespace std;

struct node 
{ 
    node* child[26]; 
    bool f; //denotes end of the word 
    
    node(){
    	f = false; 
    	for (int i=0;i<26;i++) 
        	child[i] = NULL;
	}
};

node* createNode() 
{ 
    node* newNode =  new node(); 
    return newNode; 
}  

void insert(node* root, string str) 
{ 
    node* cur = root; 
    for (int i=0;i<str.length();i++) 
    { 
        int ind = str[i]-'a'; 
        if (!cur->child[ind]) 
            cur->child[ind] = createNode(); 
        cur = cur->child[ind]; 
    } 
    // end of word 
    cur->f = true;
} 

bool search(node* root, string str) 
{ 
    node* cur = root; 
    for (int i=0;i<str.length();i++) 
    { 
        int ind = str[i]-'a'; 
        if (!cur->child[ind]) 
            return false; 
        cur = cur->child[ind]; 
    } 
    return (cur != NULL && cur->f); 
} 

int main(){
	int n; //number of words in dictionary
	cin >> n;
	node* dict = new node();
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		insert(dict,s);
	}
	string word;
	cin >> word;  //word we are looking for in the dictionary
	if(search(dict,word))
		cout << "Word is present in the dictionary\n";
	else
		cout << "Word isn't present in the dictionary\n";
	return 0;
}
