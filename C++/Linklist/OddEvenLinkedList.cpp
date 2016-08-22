
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };


bool isOddVal(int val){
    return val&1;
}
ListNode* oddEvenList(ListNode* head) {
        ListNode *p=head, *followp=head;
        ListNode *q=head;
       if(head==NULL)
       return NULL;
        while(p&&isOddVal(p->val)){
            followp=p;
            p=p->next;
          }
          q=p;
         while(q!=NULL){
        // q: search the first odd node after even 
         while(q->next!=NULL&&!isOddVal(q->next->val)) 
            q=q->next;
         if(q->next==NULL)// q points to  the end of link list 
           break;
         if(q!=NULL){
              ListNode* tmp=q->next;
              q->next=tmp->next;
            if(followp!=p) // case1 : the head is odd val   //case 2: the head is even val 
                followp->next=tmp;
            else
                head=tmp;               
            followp=tmp;
            tmp->next=p;
            }
          }   
          return head;
    }
     
ListNode* initLink(vector<int> input){
   if(input.size()==0)
   return NULL;
   ListNode* head=new ListNode(input[0]);
   ListNode *p=head;
    for(int i=1;i<input.size();i++){
        
        ListNode* node=new ListNode(input[i]);
        p->next=node;
        p=p->next;
       
    }
    return head;
}
int main()
{
    vector<int> input={2};
    ListNode * head,*p;
    head=initLink(input);
    p=head;
    p=oddEvenList(head);
    while(p!=NULL){
        cout<<p->val<<endl;
        p=p->next;
    }
    return 0;
}