class Solution {
public:

    int n,m;
    bool res=false;
    string curr="";

    void solve(int row,int col,vector<vector<char>>& board, string& word,int idx,vector<vector<bool>>& visited)
    {
        if (idx==word.length())
        {
            res=true;
            return;
        }

        if (row<0 || row>=n || col<0 || col>=m || visited[row][col] || board[row][col]!=word[idx] || res) return;        

        //visited[row][col]=true; // extra space consuming
        char temp=board[row][col];
        board[row][col]='#';

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        for (int i=0;i<4;i++)
        {
            int newrow=row+dr[i];
            int newcol=col+dc[i];

            solve(newrow,newcol,board,word,idx+1,visited);
        }

        visited[row][col]=false;
    }

    bool Backtrack(int row,int col,vector<vector<char>>& board, string& word,int idx)
    {
        if (idx==word.length()) return true;
        if (row<0 || row>=n || col<0 || col>=m || board[row][col]=='#' || board[row][col]!=word[idx]) return false;

        char temp=board[row][col];
        board[row][col]='#';

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for (int i=0;i<4;i++)
        {
            int newrow=row+dr[i];
            int newcol=col+dc[i];
            if (Backtrack(newrow,newcol,board,word,idx+1)) return true;
        }

        board[row][col]=temp;

        return false;

    }


    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (board[i][j]==word[0])
                {
                    //solve(i,j,board,word,0,visited);  // 1st method
                    if (Backtrack(i,j,board,word,0)) return true; // 2nd method
                    //if (res) return true;
                }
            }
        }

        return false;
    }
};