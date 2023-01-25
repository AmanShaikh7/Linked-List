import java.util.*;
import java.io.*;

class Node{
    int data;
    Node next;
    Node(int data){
        this.data = data;
        next = null;
    }
}
class LinkedList{
    Node head;
    void add(int data){
        Node new_node = new Node(data);
        if(head == null){
            head = new_node;
            return;
        }
        Node curr = head;
        while(curr.next != null)
            curr = curr.next;
        curr.next = new_node;
    }
}
public class Main {
    public static void reverse(Node curr){
		// 2->6->8->10->1    || 2 <- 6 <- 8 <- 10 <- 1
		Node prev = null;
		while(curr!=null){
			//preserve pointer to the next node
			Node nextofCurr = curr.next;
			//reverse pointers
			curr.next = prev;

			//update the pointers
			prev = curr;
			curr = nextofCurr;
		}
		//tail = head;
		Node head = prev;
		while(head != null){
			System.out.print(head.data+" ");
			head = head.next;
		}
        
    }
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        LinkedList list = new LinkedList();
        int n = input.nextInt();
        for(int i = 0; i < n; i++){
            int x = input.nextInt();
            list.add(x);
        }
        reverse(list.head);
        System.out.println("");
    }
}