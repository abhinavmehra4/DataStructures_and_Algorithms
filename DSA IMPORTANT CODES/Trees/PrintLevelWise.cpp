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
};

//Function to tak elevel wise input
TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter the root data\n";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the number of children "<<endl;
        cin>>numChild;
        for(int i =0;i<numChild;i++)
        {
            int childData;
            cout<<"Enter the data for "<<numChild<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNode.push(child);
        }
    }
    
    return root;
}

void printLevelWise(TreeNode<int>* root)
{
    if(root==NULL)
        return;
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);


return 0;
}
