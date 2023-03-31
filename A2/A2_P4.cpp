#include <iostream>
#include <string>
using namespace std;
int lines,operation;

struct Node{
    int wei;
	Node *lson, *rson;
    long long val,sum;
    Node(){
	    wei = 0;
	    val = sum = 0;
	    lson = rson = NULL;
    }
    Node(int num){
    	wei = 1;
    	val = sum = num;
    	lson = rson = new Node();
	}
};

int random(Node* input){
    int inputnum = (input->wei * input->val + input->sum)%2;
    return inputnum;
}

Node* root = new Node();
Node* temp1 = new Node();
Node* temp2 = new Node();
Node* temp3 = new Node();

Node* merge(Node* left, Node* right){
	if(left->wei == 0)return right;
	if(right->wei == 0)return left;
    if((random(left) + random(right))%2 == 0){
        left->rson = merge(left->rson, right);
        left->sum = left->lson->sum + left->rson->sum + left->val;
        left->wei = left->lson->wei + left->rson->wei + 1;
        return left;
    }
    if ((random(left) + random(right))%2 == 1){
        right->lson = merge(left, right->lson);
        right->sum = right->lson->sum + right->rson->sum + right->val;
        right->wei = right->lson->wei + right->rson->wei + 1;
        return right;
    }
}

void split(Node* node, int k, Node* &l, Node* &r){
    if(node->wei == 0){
        l = new Node();
        r = new Node();
        return;
    }
    if(node->lson->wei < k){
        l = node;
        split(node->rson, k - node->lson->wei - 1, node->rson, r);
    }
    if (node->lson->wei >= k){
        r = node;
        split(node->lson, k, l, node->lson);
    }
    node->sum = node->lson->sum + node->rson->sum + node->val;
    node->wei = node->lson->wei + node->rson->wei + 1;
}

void insert(){
    int k,x;
    scanf("%d%d",&k,&x);
    split(root, k, temp1, temp2);
    temp1 = merge(temp1, new Node(x));
    root = merge(temp1, temp2);
}

void mydelete(){
    int k;
    scanf("%d",&k);
    split(root, k-1, temp1, temp2);
    split(temp2, 1, temp2, temp3);
    root = merge(temp1, temp3);
}

void sum(){
    int l,r;
    scanf("%d%d",&l,&r);
    split(root, l-1, temp1, temp2);
    split(temp2, r-l+1, temp2, temp3);
    cout << temp2->sum << endl;
    temp2 = merge(temp1, temp2);
    root = merge(temp2, temp3);
}

int main()
{   
    scanf("%d",&lines);
    for (int i = 0; i < lines; i++){
        cin >> operation;
        if(operation==1){
            insert();
        }
        if(operation==2){
            mydelete();
        }
        if(operation==3){
            sum();
        }
    }
    return 0;
}