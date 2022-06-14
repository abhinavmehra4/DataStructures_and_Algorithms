#include<iostream>
#include "TreeNode.h"
#include<vector>
#include<queue>
using namespace std;
TreeNode<int>* takeInputLevelWise()
{   
    int rootData;
    cout<<"Enter root data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData); //we created the root node
    /*
        Now create a queue. Push the root in and push in the children of the root. 
        Then connect the children to theri parent node. 
        After all the children are in and cpnnected
        pop out the parent node. The for the next node in the queue, push in its own children, connect them, and after that, pop out the 
        parent node. So on and so forth.

        But should we put the nodes in the queue or the 'int' data. We will push in the nodes because we have to make the connections to the parent as well

    */
   queue<TreeNode<int>*> pendingNodes;
   //in this inbuilt library we have a push(), pop() and front(), empty() and size()
    pendingNodes.push(root); //push the pparent node inside
    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front = pendingNodes.front(); //we get the topmost element of the queue using front()
        pendingNodes.pop(); //topmost queue element gets popped
        cout<<"Enter the number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        //depending on the value of numChild, we create those many nodes
        for(int i=0;i<numChild;i++)
        {
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            int childData;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }

    }
    return root;
}

void printTree(TreeNode<int>* root)
{
    if(root==NULL) //this is an edge case
        return;

     cout<<root->data<<":"; //this works as a base case. Hence in case of Generic Trees we don't have to give a base case.
     for(int i=0;i<root->children.size();i++)
     {
         cout<<root->children[i]->data<<",";
     }
     cout<<endl; //1: 2,3,  this will be our output
     for(int i =0;i<root->children.size();i++)
     {
         printTree(root->children[i]); 
     }
}

int getLeafNodeCount(TreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    int ans=0;
    /*
    dont do 
    int ans=1; because every time recursion is cfalled, the value of answer will be set to 1 and the code will 
    become same as calculating the number of nodes

    */
    if(root->children.size()==0)
        return 1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=getLeafNodeCount(root->children[i]);
    }
}

void deleteTree(TreeNode<int>* root) //similaar to postorder traversal
{
    for(int i =0;i<root->children.size();i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}
int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    cout<<endl;
    return 0;
}