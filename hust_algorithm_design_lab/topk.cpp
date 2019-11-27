#include<bits/stdc++.h>
using namespace std;
int r = 5;

void clear_vector(vector<int> v) {
	vector<int> tmp;
	swap(tmp, v);
}

//返回A中val的index，并将小的和大的元素分别放在两边 
int partition(vector<int> &A, int val) {
	vector<int> left, right;
	//分成两部分 
	for(int i = 0; i < A.size(); i++) {
		if(A[i] < val)
			left.push_back(A[i]);
		else
			right.push_back(A[i]);
	}
	int pos = left.size() + 1;
	for(int i = 0; i < right.size(); i++) {
		left.push_back(right[i]);
	}
	swap(left, A);
	return pos;
}

//取A中第k小的元素 
int select(vector<int> &A, int k) {
    //叶节点 
    if(A.size() <= r) {
        sort(A.begin(), A.end());
        return A[k-1];
    }
    //取出中位数并排序 
    vector<int> mid;
    for(int i = 0; i < A.size(); i += r) {	//每r个一组 
        vector<int> group;	//保存一组的数据 
        for(int j = 0; j < r; j++) {
			if(i+j >= A.size()) break;
			group.push_back(A[i+j]); 
		} 
        sort(group.begin(), group.end());	//排序该组数据 
        mid.push_back(group[(group.size()-1) / 2]);	//取中位数 
    }
    int val = select(mid, (1 + A.size()/r) / 2);	//选中的值 
    int rank = partition(A, val);	//返回val的序号
    clear_vector(mid); 
    if(k == rank)
        return val;
    else if(k < rank) { //K比rank小,在A[0,rank-1)中求第K小元素 
        vector<int> A1;
        for(int i = 0; i < rank-1; ++i)
            A1.push_back(A[i]);
        return select(A1, k);              
    } else { //K比rank大，在[rank,A.size())中求第K-rank小元素。。
    	vector<int> A2;
        for(int i = rank; i != A.size(); ++i)
            A2.push_back(A[i]);
        return select(A2, k-rank);
    }
}

void test(int V, int K) {
	clock_t start, end, start2, end2;
	srand((int)time(0)); //随机数种子 
	vector<int> A1, A2;
	for(int i = 0; i < V; ++i) {
		int rd = (int) rand();
        A1.push_back(rd);
        A2.push_back(rd);
    }
    sort(A2.begin(), A2.end());
    start = clock();	//程序开始计时
    int res;
    //for(int i = 0; i < 100; i++) {	//为了时间区别更明显，重复100次 
    for(int i = 0; i < V; i++) printf("%d ", A1[i]); 
    	res = select(A1, K);
    //}
    end = clock();		//程序结束计时
    double endtime=(double)(end-start)/CLOCKS_PER_SEC; 
	printf("\n%dth: res = %d, ans = %d, time = %lf\n", K, res, A2[K-1], endtime);
	return;
}

int main()
{
    int V, K;
    while((scanf("%d%d%d", &V, &K, &r)) == 3) {
		test(V, K);
	}
    return 0;
}
