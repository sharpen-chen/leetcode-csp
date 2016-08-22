
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };


ListNode* oddEvenList(ListNode* head) {
        ListNode *p=head;
        vector<int> odd,even;
        int count=1;
        while(p){
            if(count%2)
            odd.push_back(p->val);
            else
            even.push_back(p->val);
            
            p=p->next;
            count++;
        }
        p=head;
        vector<int>::iterator itOdd=odd.begin();
        vector<int>::iterator itEven=even.begin();
        
        while(itOdd!=odd.end()){
           p->val=*itOdd;
           itOdd++;
           p=p->next;
        }
        while(itEven!=even.end()){
            p->val=*itEven;
            itEven++;
            p=p->next;
        }
          return head;
    }
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