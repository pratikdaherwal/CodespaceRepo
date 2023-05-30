class Solution {
public:
    bool dfs(vector<vector<char>>& board,vector<vector<int>>& vis,
        int row,int col,string word,string temp,int ptr,int n,int m){
        vis[row][col]=1;
        temp+=board[row][col];
        if(temp==word) return true;
        if(ptr>=word.length())return false;
        int delRow[]={1,-1,0,0};
        int delCol[]={0,0,1,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==word[ptr+1] && vis[nrow][ncol]==0)
            {
                dfs(board,vis,nrow,ncol,word,temp,ptr+1,n,m);
                return true;
            }
        }
        return false;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,vis,i,j,word,"",0,n,m))
                        return true;
                }
            }
        }
            return false;
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends