/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Pair{
    TreeNode node;
    int vl;
    int hl;

    Pair(TreeNode node,int vl,int hl){
        this.node=node;
        this.vl=vl;
        this.hl=hl;
    }
}
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Map<Integer,Map<Integer,PriorityQueue<Integer>>> data=new TreeMap<>();
        Queue<Pair> q=new ArrayDeque<>();
        q.offer(new Pair(root,0,0));
        while(!q.isEmpty()){
            Pair pr=q.poll();
            int hor=pr.hl;
            int ver=pr.vl;
            TreeNode node=pr.node;
            data.putIfAbsent(ver,new TreeMap<>());
            data.get(ver).putIfAbsent(hor,new PriorityQueue<>());
            data.get(ver).get(hor).offer(node.val);
            if(node.left!=null){
                q.offer(new Pair(node.left,ver-1,hor+1));
            }
            if(node.right!=null){
                q.offer(new Pair(node.right,ver+1,hor+1));
            }
        }

        List<List<Integer>> result=new ArrayList<>();

        for(Map<Integer,PriorityQueue<Integer>> ys:data.values()){
            List<Integer> col=new ArrayList<>();
            for(PriorityQueue<Integer> qs:ys.values()){
                while(!qs.isEmpty()){
                    col.add(qs.poll());
                }
            }
            result.add(col);
        }

        return result;
    }
}