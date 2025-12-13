package LinkedList;

public class MiddleoftheLinkedList {
    public static void main(String[] args) {
        
    }
}

class ListNode{
    int val;
    ListNode next;

    ListNode(int x){
        val = x;
        next = null;
    }
}

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}