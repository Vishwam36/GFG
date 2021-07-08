// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1#
// Good question

class Solution
{
	public:
	struct Node
    {
        char c;
        int freq;
        Node* left, *right;
    };

    struct cmp
    {
        bool operator()(Node* a, Node* b)
        {
            return a->freq > b->freq;
        }
    };

	vector<string> ans;
	
	Node* newNode(char ch, int f)
	{
	    Node* temp = new Node();
	    temp->c = ch;
	    temp->freq = f;
	    return temp;
	}
	
	void rec(Node* root, string temp)
	{
	    if(!root)
	        return;
	    
	    if(!root->left && !root->right)
	        ans.push_back(temp);
	    
	    rec(root->left, temp+"0");
	    rec(root->right, temp+"1");
	}
	
	vector<string> huffmanCodes(string s,vector<int> f,int n)
	{
	    priority_queue<Node*, vector<Node*>, cmp> pq;
	    for(int i = 0; i < n; ++i)
	        pq.push(newNode(s[i], f[i]));
	    
	    while(pq.size() > 1)
	    {
	        auto left = pq.top(); pq.pop();
	        auto right = pq.top(); pq.pop();
	        
	        Node* top = newNode('$', left->freq + right->freq);
	        top->left = left;
	        top->right = right;
	        
	        pq.push(top);
	    }
	    
	    rec(pq.top(), "");
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};
