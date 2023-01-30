
import java.util.*;
import java.lang.*;

class Node{
    int data;
    Node next;
    Node(int key){
        data = key;
        next = null;
    }
}

class Main{
    static Node head;
    static Node temp;
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0){
            int n = sc.nextInt();
            int a1 = sc.nextInt();
            head = null;
            temp = null;
            addToTheLast(a1);
            
            for(int i = 1; i < n; i++){
                int data = sc.nextInt();
                addToTheLast(data);
            }
            Solution ans = new Solution();
            Node node = ans.rearrange(head);
            printList(node);
            System.out.println();
        }
    }
    
    public static void addToTheLast(int data){
        if(head == null){
			head = new Node(data);
			temp =head;
			return ;
		}
		else{
			Node new_node = new Node(data);
			temp.next = new_node;
			temp=temp.next;
			return;		
		}
    }
    
    public static void printList(Node node){
        while(node != null){
            System.out.print(node.data + " ");
            node = node.next;
        }
    }
}

class Solution{

	public static Node reverse(Node head){
		Node prev = null;
		while(head!=null){
			Node nextnode = head.next;
			head.next = prev;
			prev = head;
			head = nextnode;
		}
		return prev;
	}
	// public static void print(Node head){
	// 	while(head!=null){
	// 		System.out.print(head.data+" ");
	// 		head =head.next;
	// 	}
	// }
    public static Node rearrange(Node node){
       //1) middle nikal le
		Node fast = node;
		Node slow = node;
		while(fast!=null && fast.next!=null){
			fast = fast.next.next;
			slow = slow.next;
		}
		Node first = node;
		Node second = reverse(slow.next);
		slow.next = null;
		///print(second);
		//merge both the lists
		
		while(second!=null){
			Node temp1 = first.next;
			first.next = second;
			Node temp2 = second.next;
			second.next =temp1;
			first = temp1;
			second = temp2;
		}
		return node;
       
    }
}

