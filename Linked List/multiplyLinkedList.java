import java.util.*;
class Node
{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        next=null;
    }
}

class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
        Node head=null;
        Node phead=null;
        int n=sc.nextInt();
        while(n-->0){
            int n1=sc.nextInt();
            if(head==null)
                head=new Node(n1);
            else
                addHead(head,n1);
        }
        int m=sc.nextInt();
        while(m-->0){
            int n1=sc.nextInt();
            if(phead==null)
                phead=new Node(n1);
            else{
                addHead(phead,n1);
            }
        }
		Solution g=new Solution();
        System.out.println(g.multiplyLists(head,phead));
	}
   
    public static void addHead(Node node,int a) {
          if (node == null)
            return;
		if(node.next==null)
			node.next=new Node(a);
		else
			addHead(node.next,a);
	}
}

class Solution{
   public long multiplyLists(Node l1,Node l2){
        long firstNum = 0;
	   long secondNum = 0;
	   while(l1!=null){
		   firstNum = (firstNum*10) %1000000007 + l1.data;
		   l1=l1.next;
	   }
	   while(l2!=null){
		   secondNum = (secondNum*10 )%1000000007+ l2.data;  
		   l2=l2.next;
	   }
	   long ans = firstNum*secondNum;
	   return ans%1000000007;
   }
}
