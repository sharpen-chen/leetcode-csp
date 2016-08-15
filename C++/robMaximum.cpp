
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 int rob(TreeNode* root) {
     int result1=0,result2=0;
     int result=0;
     vector<TreeNode*> oddLevel;
     vector<TreeNode*> evenLevel;
     if(root==NULL){
         return 0;
     }
     oddLevel.push_back(root);
     
     while(oddLevel.size()>0){
         vector<TreeNode*>::iterator it=oddLevel.begin();
         if((*it)->left!=NULL)
              evenLevel.push_back((*it)->left);       
         if((*it)->right!=NULL)
              evenLevel.push_back((*it)->right);
        result1+=(*it)->val;
        oddLevel.erase(it);
        while(evenLevel.size()>0){
            vector<TreeNode*>::iterator evenIt=evenLevel.begin();
            if((*evenIt)->left!=NULL)
                oddLevel.push_back((*evenIt)->left);
            if((*evenIt)->right!=NULL)
                oddLevel.push_back((*evenIt)->right);
            result2+=(*evenIt)->val;
            evenLevel.erase(evenIt);
        }         
     }
     return result1>=result2?result1:result2;
    }

    TreeNode* initBTree(vector<int> input)  
{  
    int size=input.size();
    cout<<"input.size:"<<size<<endl;
    if (size < 1)  
    {  
        return NULL;  
    }  
    //动态申请size大小的指针数组  
    TreeNode **nodes = new TreeNode*[size];  
    //将int数据转换为TreeNode节点  
    for (int i = 0; i < size; i++)  
    {  
        if (input[i] == 0)  
        {  
            nodes[i] = NULL;  
        }  
        else  
        {  
            nodes[i] = new TreeNode(input[i]);  
        }  
    }  
    queue<TreeNode*> nodeQueue;  
    nodeQueue.push(nodes[0]);  
  
    TreeNode *node;  
    int index =1;  
   
    while (index < size )  
    {        
        node = nodeQueue.front();              
        nodeQueue.pop();
        //handle left son
        if(nodes[index]){
            nodeQueue.push(nodes[index]);
            node->left=nodes[index];
        }
        index++;
        //handle right son
        if(index<size && nodes[index]){           
            nodeQueue.push(nodes[index]);
            node->right=nodes[index];
        }
         index++;           
    } 
    // while (index < size )  
    // {  
    //     node = nodeQueue.front();  
        
    //     nodeQueue.pop();
    //     cout<<node->val<<endl;
    //     if(nodes[index]){          
    //         nodeQueue.push(nodes[index++]);
    //         node->left = nodeQueue.back();
    //     }

    //     if(nodes[index] && index<size){
    //         nodeQueue.push(nodes[index++]);           
    //         node->right = nodeQueue.back();
    //     }
        
         
    // }  
    return nodes[0];  
} 

void inOrder(TreeNode *root, vector<int> &result)  
{  
    
    if (root)  
    {  
      //  cout<<"debug!"<<endl;
        inOrder(root->left, result); 
        cout<<root->val<<endl; 
        result.push_back(root->val);  
        inOrder(root->right, result);  
    }  
}  

void traverse(vector<int> nums)  
{  
    vector<int>::size_type size = nums.size();  
    for (size_t i = 0; i < size; i++)  
    {       
        cout << nums[i] << ' ';  
    }  
    cout << endl;  
}  

int main()
{
    // queue<TreeNode*> nodeQueue;  
    // nodeQueue.push(NULL);
    // TreeNode* test=nodeQueue.front();
    // nodeQueue.pop();
    // if(test==NULL)
    // cout<<"hell"<<endl;
    // else
    // cout<<"ddd";
    vector<int> input={4,1,0,2,0,3};
    vector<int> inResult;  
    TreeNode *root=initBTree(input);
    inOrder(root, inResult);  
    cout << "中序遍历的结果：" << '\n';  
    traverse(inResult);  

    cout<<rob(root)<<endl;
    return 0;
}