// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#
// Decent

/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. 

Example 1:
Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output: 
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.

Example 2:
Input:
N = 3
words[] = {no,on,is}
Output: 
no on
is
Explanation:
There are 2 groups of
anagrams "no", "on" make group 1.
"is" makes group 2. 

Your Task:
Complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.

Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.

Constraints:
1<=N<=100
*/

// App 1 : Simple approach

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    vector<vector<string> > ans;
    map<string, vector<int> > m;
    
    for(int i = 0; i < string_list.size(); ++i)
    {
        string s = string_list[i];
        sort(s.begin(), s.end());
        m[s].push_back(i);
    }
    
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        string s = it->first;
        auto indices = it->second;
        
        vector<string> temp;
        for(auto i : indices)
            temp.push_back(string_list[i]);
        
        ans.push_back(temp);
    }
    return ans;
}


// App 2 : Trie approach

struct Node
{
    bool isLeaf;
    Node* children[26];
};

bool search(Node* root, string s)
{
    for(int i = 0; i < s.size(); ++i)
        if(!root->children[s[i]-'a'])
            return false;
    
    return true;
}

void insert(Node* root, string s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        if(!root->children[s[i]-'a'])
            root->children[s[i]-'a'] = new Node();
        
        root = root->children[s[i]-'a'];
    }
}

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    Node* root = new Node();
    map<string, vector<int> > m;
    for(int i = 0; i < string_list.size(); ++i)
    {
        string temp = string_list[i];
        sort(temp.begin(), temp.end());
        
        if(!search(root, string_list[i]))
            insert(root, string_list[i]);
        
        m[temp].push_back(i);
    }
    
    vector<vector<string> > ans;
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        vector<string> temp;
        for(auto i : it->second)
        {
            temp.push_back(string_list[i]);
        }
        ans.push_back(temp);
    }
    return ans;
}
