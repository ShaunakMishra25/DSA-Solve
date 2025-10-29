class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
      slow=fast=head
      
      #find the middle
      while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
      # revers
      prev,curr=None,slow
      while curr:
        nxt=curr.next
        curr.next=prev
        prev=curr
        curr=nxt
      
      # compare
      left,right=head,prev
      while right:
        if left.val != right.val:
          return False
        left = left.next
        right = right.next
      return True