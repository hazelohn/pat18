#include <cstdio> 
#include <cstdlib>
#include <vector> 
#include <set>

using namespace std;

const int maxLen=31;
int K;
int N;
int preorder[maxLen];

bool isRB;
typedef struct NODE* Node;
struct NODE{
  int data;
  Node left;
  Node right;
};
Node root=NULL;
set<int> num;

void judgeSameNum(Node node,int count){
  if(node==NULL) {
    //printf("left count：%d\n",count);
    num.insert(count);
    return;
  }
  if(node->data>0) count++;
  //printf("node->data：%d count:%d\n",node->data,count);
  judgeSameNum(node->left,count);  
  judgeSameNum(node->right,count);
}

void inOrder(Node node)
{
  if(node==NULL){
    return;
  }
  
  inOrder(node->left);
  printf("%d ",node->data);
  inOrder(node->right);
}

void preOrder(Node node){
  if(node==NULL){
    return;
  }
  judgeSameNum(node,0);
  if(num.size()>1){
    isRB=false;
  }
  //printf("num.size：%d ",num.size());
  num.clear();
  //printf("%d ",node->data);
  preOrder(node->left);
  preOrder(node->right);
}

void BST(Node &node,int data){
  //printf("%d ",data);
  int tempData,tempNodedata;
  if(node==NULL) {
    node=new NODE[1];
    node->data=data;
    node->left=node->right=NULL;
    return ;
  }
  if(data<0) tempData=0-data;
  else tempData=data;
  if(node->data<0) tempNodedata=0-node->data;
  else tempNodedata=node->data;
  if(tempNodedata>tempData){
    BST(node->left,data);
  }else{
    BST(node->right,data);
  }
}

void judgeLeaf(Node node){
  if(node==NULL){
    return;
  }
  if(node->data<0){
    if(node->left!=NULL&&node->left->data<0){
      isRB=false;
      return;
    }
    if(node->right!=NULL&&node->right->data<0){
      isRB=false;
      return;
    }
  }
  judgeLeaf(node->left);
  judgeLeaf(node->right);

}
void init(){
  scanf("%d",&K);
  int i,j;
  for(i=0;i<K;i++){
    root=NULL;
    isRB=true;
    scanf("%d",&N);
    for(j=0;j<N;j++){
      scanf("%d",preorder+j);
      BST(root,preorder[j]);
    }
    if(preorder[0]<0){
      isRB=false;
    }
    
    judgeLeaf(root);
    preOrder(root);
    //inOrder(root);
    if(isRB==true){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
    //preOrder(root);
  }
}



int main(void){
  init();
  

}
