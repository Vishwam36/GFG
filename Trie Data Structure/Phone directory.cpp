// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/phone-directory4628/1#
// Decent

/*
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement 
a search queryfor the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts 
which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:
Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0

Explaination: By running the search query on 
contact list for "g" we get: "geeikistest", 
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list 
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0". 
No results found for "geeips", so print "0".

Your Task:
Youd do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and 
returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|)

Constraints:
1 ≤ n ≤ 50
1 ≤ |contact[i]| ≤ 50
1 ≤ |s| ≤ 6
*/

// Trie Node
struct Node
{
    set<string> words; // set of words coming through this node
    Node* children[26];
};

class Solution{
public:
    vector<string> zero_vector = {"0"};

    void insert(Node* root, string s)
    {
        for(int i = 0; i < s.size(); ++i)
        {
            if(!root->children[s[i]-'a'])
                root->children[s[i]-'a'] = new Node();
            
            root = root->children[s[i]-'a'];
            (root->words).insert(s);
        }
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Node* root = new Node();
        for(int i = 0; i < n; ++i)
            insert(root, contact[i]);
        
        vector<vector<string> > ans;
        bool flag = false; // whether we have encountered any zero_vector
        for(int i = 0; i < s.size(); ++i)
        {
            if(flag || root->children[s[i]-'a'] == NULL)
            {
                flag = true;
                ans.push_back(zero_vector);
            }
            else
            {
                root = root->children[s[i]-'a'];
                ans.push_back(vector<string>((root->words).begin(), (root->words).end()));
            }
        }
        return ans;
    }
};
