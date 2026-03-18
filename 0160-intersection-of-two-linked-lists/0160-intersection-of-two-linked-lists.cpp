/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA= headA;
        ListNode *tempB= headB;
        int lenA=0,lenB=0;
        while(tempA){
            lenA++;
            tempA=tempA->next;
        }
         while(tempB){
            lenB++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;

        if(lenB>lenA){
            int diff= lenB-lenA;
            for(int i=1;i<=diff;i++){
                // galti: yaha tempA nahi, tempB move hoga
                tempB=tempB->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
        }

        // galti: lenA > lenB wala case missing hai
        else if(lenA>lenB){
            int diff = lenA-lenB;
            for(int i=1;i<=diff;i++){
                tempA=tempA->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
        }

        // jab dono ki length equal ho
        else{
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
        }

        return tempA;
    }
};