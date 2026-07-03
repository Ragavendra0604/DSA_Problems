class Pair{
    int row;
    int col;
    int dist;

    Pair(int row,int col,int dist){
        this.row=row;
        this.col=col;
        this.dist=dist;
    }
}


class Solution {
    public int[][] updateMatrix(int[][] mat) {
        Queue<Pair> q=new ArrayDeque<>();
        int visited[][]=new int[mat.length][mat[0].length];

        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[0].length;j++){
                if(mat[i][j]==0){
                    q.offer(new Pair(i,j,0));
                }
            }
        }

        while(!q.isEmpty()){
            Pair val=q.poll();
            int rw=val.row;
            int cl=val.col;
            int dst=val.dist;

            int dx[]={0,-1,1,0};
            int dy[]={-1,0,0,1};

            for(int i=0;i<4;i++){
                int nx=dx[i]+rw;
                int ny=dy[i]+cl;
                if(nx>=0 && nx<mat.length && ny>=0 && ny<mat[0].length && mat[nx][ny]==1 && visited[nx][ny]==0){
                    mat[nx][ny]=dst+1;
                    visited[nx][ny]=1;
                   q.offer(new Pair(nx,ny,dst+1));
                }
            }
        }
        return mat;
    }
}