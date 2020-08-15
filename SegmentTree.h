//
// Created by Ahmed Bahnasy on 14.08.20.
//

#ifndef ALGORITHMS_SEGMENTTREE_H
#define ALGORITHMS_SEGMENTTREE_H

struct SegmentTreeNode {
    int v,l,r, lazy;
};


void propagate(SegmentTreeNode t[], int p) {
    t[p].v += t[p].lazy * ((t[p].r - t[p].l)+1);
    if(t[p].l != t[p].r) {
        t[2*p+1].lazy += t[p].lazy;
        t[2*p+2].lazy += t[p].lazy;
    }
    t[p].lazy = 0;
}

int build_segment_tree(int a[], SegmentTreeNode t[], int l, int r, int p) {
    t[p].lazy = 0;
    t[p].l = l;
    t[p].r = r;
    if(l == r) {
        t[p].v = a[l];
        return a[l];
    }
    int m = (l+r)/2;
    t[p].v  = build_segment_tree(a, t, l, m, 2*p+1) +build_segment_tree(a, t, m+1, r, 2*p+2);
}

int sum(SegmentTreeNode t[], int p, int l, int r) {
    if (l > t[p].r || r < t[p].l)
        return 0;
    if(t[p].l <= l && t[p].r <= r)
        propagate(t,p);
        return t[p].v;
    return sum(t, 2*p+1, l,r) + sum(t, 2*p+2, l, r);
}

void add (SegmentTreeNode t[], int p, int idx, int value) {
    if(idx > t[p].r || idx < t[p].l)
        return;
    t[p].v += value;

    if(t[p].l != t[p].r) {
        add(t, 2*p+1, idx, value);
        add(t, 2*p+2, idx, value);
    }

}




void add_range(SegmentTreeNode t[], int p, int l, int r, int value) {
    if (p[t].l > r || p[t].r < l)
        return;
    propagate(t,p);
    if(l <= p[t].l && p[t].r <= r) {
        p[t].lazy += value;
        propagate(t,p);
        return;
    } else if (p[t].l != p[t].r) {
        add_range(t, 2*p+1,l, r, value);
        add_range(t, 2*p+2, l, r, value);
        t[p].v =  t[2*p+1].v + t[2*p+2].v;
    }
}


#endif //ALGORITHMS_SEGMENTTREE_H
