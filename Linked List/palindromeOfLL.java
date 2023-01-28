import java.util.*;


public class Main {
    public static void main(String[] args) throws Throwable {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        LinkedList llist= new LinkedList(); 
        int a1=sc.nextInt();
        Node head= new Node(a1);
        llist.addToTheLast(head);
        for (int i = 1; i < n; i++) 
        {
            int a = sc.nextInt(); 
            llist.addToTheLast(new Node(a));
        }
            
        Solution A = new Solution();
        A.checkLinkedListPalindrome(llist.head);
        
    }
}

class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
    
class LinkedList
{
    Node head;  
    Node tail;
    public void addToTheLast(Node node) 
    {
      if (head == null) 
      {
       head = node;
       tail = node;
      } 
      else 
      {
       tail.next = node;
       tail = node;
      }
    }
      void printList()
    {
        Node temp = head;
        while (temp != null)
        {
           System.out.print(temp.data+" ");
           temp = temp.next;
        }  
        System.out.println();
    }
    
}

class Solution
{
	static void print(Node head){
		while(head!=null){
			System.out.print(head.data);
			head = head.next;
		}
	}
	static Node midnode(Node head){
		Node fp = head;
		Node sp = head;
		while(fp!=null && fp.next!=null){
			fp = fp.next.next;
			sp =sp.next;
		}
		return sp;
	}
	static Node reverse(Node curr){
		Node prev = null;
		while(curr!=null){
			Node nextofCurr = curr.next;
			curr.next = prev;
			prev = curr;
			curr = nextofCurr;
		}
		return prev;
	}
	static boolean check(Node head , Node rev){
		while(head !=null && rev!=null){
			if(head.data != rev.data){
				return false;
			}
			head=head.next;
			rev=rev.next;
		}
		return true;
	}
    static void checkLinkedListPalindrome(Node head)
    {
        Node mid = midnode(head);
		
		Node rev = reverse(mid);
		boolean contains = check(head , rev);
		if(contains){
			System.out.print("YES");
		}else{
			System.out.print("NO");
		}
    }
    
}