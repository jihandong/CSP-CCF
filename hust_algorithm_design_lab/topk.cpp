#include<bits/stdc++.h>
using namespace std;
int r = 5;

void clear_vector(vector<int> v) {
	vector<int> tmp;
	swap(tmp, v);
}

//����A��val��index������С�ĺʹ��Ԫ�طֱ�������� 
int partition(vector<int> &A, int val) {
	vector<int> left, right;
	//�ֳ������� 
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

//ȡA�е�kС��Ԫ�� 
int select(vector<int> &A, int k) {
    //Ҷ�ڵ� 
    if(A.size() <= r) {
        sort(A.begin(), A.end());
        return A[k-1];
    }
    //ȡ����λ�������� 
    vector<int> mid;
    for(int i = 0; i < A.size(); i += r) {	//ÿr��һ�� 
        vector<int> group;	//����һ������� 
        for(int j = 0; j < r; j++) {
			if(i+j >= A.size()) break;
			group.push_back(A[i+j]); 
		} 
        sort(group.begin(), group.end());	//����������� 
        mid.push_back(group[(group.size()-1) / 2]);	//ȡ��λ�� 
    }
    int val = select(mid, (1 + A.size()/r) / 2);	//ѡ�е�ֵ 
    int rank = partition(A, val);	//����val�����
    clear_vector(mid); 
    if(k == rank)
        return val;
    else if(k < rank) { //K��rankС,��A[0,rank-1)�����KСԪ�� 
        vector<int> A1;
        for(int i = 0; i < rank-1; ++i)
            A1.push_back(A[i]);
        return select(A1, k);              
    } else { //K��rank����[rank,A.size())�����K-rankСԪ�ء���
    	vector<int> A2;
        for(int i = rank; i != A.size(); ++i)
            A2.push_back(A[i]);
        return select(A2, k-rank);
    }
}

void test(int V, int K) {
	clock_t start, end, start2, end2;
	srand((int)time(0)); //��������� 
	vector<int> A1, A2;
	for(int i = 0; i < V; ++i) {
		int rd = (int) rand();
        A1.push_back(rd);
        A2.push_back(rd);
    }
    sort(A2.begin(), A2.end());
    start = clock();	//����ʼ��ʱ
    int res;
    //for(int i = 0; i < 100; i++) {	//Ϊ��ʱ����������ԣ��ظ�100�� 
    for(int i = 0; i < V; i++) printf("%d ", A1[i]); 
    	res = select(A1, K);
    //}
    end = clock();		//���������ʱ
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
