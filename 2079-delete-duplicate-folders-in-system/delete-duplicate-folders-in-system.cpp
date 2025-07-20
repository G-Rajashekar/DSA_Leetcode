class Solution {
public:
    struct Node{
     string val;
     string subfolder;
     unordered_map<string,Node*>children;
   };

   Node *getNode(string val){
        Node *temp=new Node();
        temp->val=val;
        temp->subfolder="";
        return temp;
   } 

   void insertNode(Node *root,vector<string>&path){
        for (auto folder:path){
            if (root->children.find(folder)==root->children.end()){
                root->children[folder]=getNode(folder);
            }
            root=root->children[folder];
        }
   }

   string populateNodes(Node *root,unordered_map<string,int>&subFoldersCnt){
        vector<pair<string,string>>paths;

        for (auto it:root->children){
            string result=populateNodes(it.second,subFoldersCnt);
            paths.push_back({it.first,result});
        }

        sort(paths.begin(),paths.end());
        string path="";

        for (auto it:paths){
            path+="("+it.first+it.second+")";
        }

        root->subfolder=path;

        if (!path.empty()){
            subFoldersCnt[path]++;
        }
        return path;
   }

   void removeDuplicates(Node* currentFolder, unordered_map<string, int>& subFoldersCnt) {
    for (auto it = currentFolder->children.begin(); it != currentFolder->children.end(); ) {
        Node* childFolder = it->second;
        if (!childFolder->subfolder.empty() && subFoldersCnt[childFolder->subfolder] > 1) {
            it = currentFolder->children.erase(it); 
        } else {
            removeDuplicates(childFolder, subFoldersCnt);
            ++it;
        }
    }
}
     void constructResult(Node *root,vector<string>&path,vector<vector<string>>&result){
           for (auto it:root->children){
                path.push_back(it.first);
                result.push_back(path);
                constructResult(it.second,path,result);
                path.pop_back();
           }
     }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node *root=new Node("/");

        for (auto path:paths){
            insertNode(root,path);
        }
        unordered_map<string,int>subFoldersCnt;
        populateNodes(root,subFoldersCnt);
        removeDuplicates(root,subFoldersCnt);

        vector<vector<string>>result;
        vector<string>path;
        constructResult(root,path,result);
        return result;
    }
};