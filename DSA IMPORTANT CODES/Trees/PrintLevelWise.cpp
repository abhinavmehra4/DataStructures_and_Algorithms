#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>

class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children; 

    TreeNode(T data)
    {
        this->data=data;
    }
    ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
}
};

//Function to tak elevel wise input
TreeNode<int>* takeInputLevelWise()
{   
    int rootData;
    cout<<"Enter root data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData); //we created the root node
   queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root); //push the pparent node inside
    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front = pendingNodes.front(); //we get the topmost element of the queue using front()
        pendingNodes.pop(); //topmost queue element gets popped
        cout<<"Enter the number of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
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
void printLevelWise(TreeNode<int>* root) //this printing is using iterative method to avoid comma use
{
    if(root==NULL)
        return;

    queue<TreeNode<int>*> pendingPrints;
    pendingPrints.push(root);
    while(pendingPrints.size()!=0)
    {
        TreeNode<int>* frontNode = pendingPrints.front();
        pendingPrints.pop();
        cout<<frontNode->data<<":";
        for(int i=0;i<frontNode->children.size();i++)
        {
            if(i==frontNode->children.size()-1)
            {
                cout<<frontNode->children[i]->data;    
            }
            else{
                cout<<frontNode->children[i]->data<<",";
            }
            
            pendingPrints.push(frontNode->children[i]);
        }
        cout<<endl;
    }
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    return 0;
}
