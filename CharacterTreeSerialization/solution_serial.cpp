#include<bits/stdc++.h>
using namespace std;

struct node{
	node *left=NULL;
	node *right=NULL;
	char data;
};

node* addNode(char d){
	node *newNode = new node;
	newNode->data = d;
	return newNode;
}

void preorder(node *root, string &s){
	if(root == NULL)
		return;
	s += root->data;
	preorder(root->left, s);
	preorder(root->right, s);
}

void create(string &inputFile, string &outputFile){
	fstream iif,of;
	iif.open(inputFile, ios::in);
	string temp;
	vector<string> inp;
	while(f >> temp){
		inp.push_back(temp);
	}
	iif.close();
	node *root = addNode('.'), *ptr;
	ptr = root;
	for(auto x: v){
		ptr->right = addNode('+');
		node *add = ptr->right;
		for(auto y: x){
			add->left = addNode(y);
			add = add->left;
		}
		add->left = addNode('-');
		ptr = ptr->right;
	}
	string ans;
	preorder(root,ans);
	of.open(outputFile, ios::out | ios::binary);
	if(!of){
		cout << "Error occured in creating file" << endl;
		return -1;
	}
	of << ans;
	of.close();
}

void load(string &inputFile){
	ifstream f;
	f.open(inputFile, ios::in | ios::binary);
	string res;
	f >> res;
	vector<string> ans;
	string temp;
	int len = res.size();
	int flag = 0;
	for(auto x: res){
		if(x == '-'){
			string a = temp.substr(1);
			ans.push_back(a);
			temp = "";
			flag = 0;
		}
		else if(flag) temp += x;
		else if(x == '+' and !flag){
			temp += x;
			flag = 1;
		}
	}
	for(auto x: ans) cout << x << endl;
}

int main(int argc, char** argv){
	if(argc == 3){
		//LOAD
		string inputFile = argv[2];
		load(inputFile);
	}
	else if(argc == 4){
		//CREATE
		string inputFile = argv[2];
		string outputFile = argv[3];
		create(inputFile, outputFile);
	}
	else{
		return -1;
	}
}


