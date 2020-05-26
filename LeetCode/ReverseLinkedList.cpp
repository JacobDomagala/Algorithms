/*
	Reverse a singly linked list.

	-----------------------------------EXAMPLE-----------------------------------

	Input: 1->2->3->4->5->NULL
	Output: 5->4->3->2->1->NULL
*/


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}

		auto tmp = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;

		return tmp;
	}
};