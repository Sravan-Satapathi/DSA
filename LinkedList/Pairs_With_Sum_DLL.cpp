/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node *left=head,*right=head;
        while(right->next){
            right=right->next;
        }
        vector<pair<int,int>> result;
        while(left->data<right->data){
            int sum=left->data+right->data;
            if(sum==target){
                result.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if(sum<target) left=left->next;
            else right=right->prev;
        }
        return result;
    }
};
