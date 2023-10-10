/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* res = NULL;
    struct ListNode* current = NULL;
    int carry =0;

    while(l1 !=NULL || l2 !=NULL || carry!=0)
    {
        int sum= (l1?l1->val:0)+(l2?l2->val:0)+carry ;
        carry = sum/10;
        sum = sum%10;

        //Storing the sum in a new linked list
        struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
        new->val = sum;
        new->next = NULL;

        if(current== NULL)
        {
            res = new;
            current = new;
        }
        else 
        {
            current->next= new;
            current = new;
        }

        l1 = (l1?l1->next:NULL);
        l2 = (l2?l2->next:NULL);

    }
    return res;
}