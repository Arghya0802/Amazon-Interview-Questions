// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Brute Force: Use a vector to store all the values in the LinkedList and then use 2-Pointer Approach
// Optimal Solution: Get the middle node using slow and fast pointers and reverse the right half of the LinkedList and solve accordingly

class Solution {
private:

ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *curr = head ;
    ListNode *prev = NULL ;
    ListNode *last = NULL ;

    while(curr != NULL)
    {
        last = prev ;
        prev = curr ;

        curr = curr -> next ;

        prev -> next = last ;
    }

    return prev ;
}

public:
    int pairSum(ListNode* head) 
    {
        ListNode *fast = head ;
        ListNode *slow = head ;

        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next ;

            slow = slow -> next ;
        }

        ListNode *reversed = reverseLinkedList(slow) ;

        ListNode *low  = head ;
        ListNode *high = reversed ;

        int ans = 0 ;

        while(high != NULL)
        {
            int currSum = low -> val + high -> val ;

            ans = max(ans , currSum) ;

            low  = low -> next ;

            high = high -> next ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
