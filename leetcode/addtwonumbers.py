# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
        
class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        ls = ListNode(0)
        pt = ls
        prev = ls
        while l1 is not None and l2 is not None:
            pt.val += l1.val + l2.val
            if pt.val > 9:
                pt.next = ListNode(1)
                pt.val -= 10
            else:
                pt.next = ListNode(0)
            l1 = l1.next
            l2 = l2.next
            prev = pt
            pt = pt.next
        while l1 is not None:
            pt.val += l1.val
            if pt.val > 9:
                pt.next = ListNode(1)
                pt.val -= 10
            else:
                pt.next = ListNode(0)
            l1 = l1.next
            prev = pt
            pt = pt.next
        while l2 is not None:
            pt.val += l2.val
            if pt.val > 9:
                pt.next = ListNode(1)
                pt.val -= 10
            else:
                pt.next = ListNode(0)
            l2 = l2.next
            prev = pt
            pt = pt.next
        if pt.val == 0:
            prev.next = None
        return ls

# l1 = ListNode(2)
# l1.next = ListNode(4)
# l1.next.next = ListNode(3)
# l2 = ListNode(5)
# l2.next = ListNode(6)

# sol = Solution()
# re = sol.addTwoNumbers(l1, l2)
# while re is not None:
#     print re.val
#     re = re.next
