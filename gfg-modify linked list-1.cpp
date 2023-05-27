//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node* findMedian(Node* head){
        if(!head)
            return head;
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL,*nextnode;
        Node* curr = head;
        while(curr){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    
    void update(Node* &slow,Node* &head){
        Node* ptr = head;
        while(slow){
            int temp = ptr->data;
            ptr->data = slow->data-temp;
            slow->data = temp;
            ptr = ptr->next;
            slow = slow->next;
        }
    }
    
    Node* modifyTheList(struct Node *head){
        //add code here.
        if(!head)
            return head;
    
        Node* slow = findMedian(head); // tail of first half
        Node* slow_next = slow->next; // head of second half
    
        Node* prev = reverse(slow_next);
        
        slow->next = prev;
        Node* ptr = head;
        slow = slow->next;
        
        update(slow,head);
    
        slow = findMedian(head);
        slow_next = slow->next;
        
        prev = reverse(slow_next);
        slow->next = prev;
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends