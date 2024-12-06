class SegmentTree{
    int n;
    vector<int> Tree;

    int merge(int a,int b){ // change whenever needed
        return __gcd(a,b);
    }

    void update(int pos,int idx,int l,int r,int val){
        if(l==r){
            Tree[idx]=val;
            return;
        }
        int mid=l-(l-r)/2;
        if(pos<=mid){
            update(pos,2*idx+1,l,mid,val);
        }
        else{
            update(pos,2*idx+2,mid+1,r,val);
        }
        Tree[idx]=merge(Tree[2*idx+1],Tree[2*idx+2]);
    }
    int query(int idx,int l,int r,int lq,int rq){
        if(l>rq || r<lq){
            return 0;
        }
        if(lq<=l && r<=rq){
            return Tree[idx];
        }
        int mid=l-(l-r)/2;
        int left=query(2*idx+1,l,mid,lq,rq);
        int right=query(2*idx+2,mid+1,r,lq,rq);
        return merge(left,right);
    }
    void build(int idx,int l,int r,vector<int>& v){
        if(r<l){
            return;
        }
        if(l==r){
            Tree[idx]=v[l];
            return ;
        }
        int mid=l-(l-r)/2;
        build(2*idx+1,l,mid,v);
        build(2*idx+2,mid+1,r,v);
        Tree[idx]=merge(Tree[2*idx+1],Tree[2*idx+2]);
    }

public:
    SegmentTree(vector<int> & v){
        n=v.size();
        Tree.resize(4*n+2);
        build(0,0,n-1,v);
    }
    void update(int pos,int val){
        update(pos,0,0,n-1,val);
    }
    int query(int l,int r){
        return query(0,0,n-1,l,r);
    }
};