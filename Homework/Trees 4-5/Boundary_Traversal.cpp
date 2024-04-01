void addLeft(TreeNode<int> *root, vector<int> &out)
{
    if (root == NULL) return;
    // If root is not a leaf node we add it to our traversal
    if (root->right || root->left) out.push_back(root->data);
    // We check for furhter left boundaries
    if(root->left) addLeft(root->left, out);
    else addLeft(root->right, out);
}

void addRight(TreeNode<int> *root, vector<int> &out)
{
    if (root == NULL) return;
    // since we need anti-clockwise traversal , we need the right boundary in reverse , so we first check for further right boundary
    if(root->right) addRight(root->right, out);
    else addRight(root->left, out);
    // If root is not a leaf node we add it to our traversal
    if (root->left || root->right) out.push_back(root->data);
}

void addLeaf(TreeNode<int> *root, vector<int> &out)
{
    if (root == NULL) return;
    // If root is a leaf node , we need to at it to our traversal
    if (!root->left && !root->right) out.push_back(root->data);

    addLeaf(root->left, out);
    addLeaf(root->right, out);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{

    if (root == NULL) return {};
    vector<int> out;
    // Root will always be a part of boundary
    out.push_back(root->data);
    // We add left boundary except leaf nodes
    addLeft(root->left, out);
    // We add leaf nodes
    addLeaf(root, out);
    // We add right boundary except leaf nodes
    addRight(root->right, out);
    return out;
}