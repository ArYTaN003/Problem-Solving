
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ary="";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* f;
        while(!q.empty()) {
            f=q.front(); 
            q.pop();
            if(f!=NULL){
                ary+=to_string(f->val);
                ary+=" ";
                q.push(f->left);
                q.push(f->right);
            }
            else{
                ary+="n ";
            }
        }
        ary = ary.substr(0,ary.length()-1);
        return ary;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="n") return NULL;
        // stringstream reads the string like an input , each word separated by space is taken as separate input
        stringstream ss(data);
        string temp;
        ss >> temp;
        TreeNode *root=new TreeNode(stoi(temp));
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* f;
        while(ss >> temp) {
            f=q.front(); 
            q.pop();
            if (temp!="n") {
                f->left=new TreeNode(stoi(temp));
                q.push(f->left);
            }
            ss >> temp;
            if (temp!="n") {
                f->right=new TreeNode(stoi(temp));
                q.push(f->right);
            }
        }
        return root;
    }