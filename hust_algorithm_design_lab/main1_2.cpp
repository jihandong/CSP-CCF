#include<bits/stdc++.h>
using namespace std;
const int r = 5;

//快速插入排序
void insertsort(vector<int> &vint)
{
    int j=0;
    int temp;
    for(int i=1;i!=vint.size();i++)
    {
        //a[0]=a[i];
        temp=(vint)[i];
        j=i- 1;
        while(j>=0 && temp<(vint)[j])
        {
            (vint)[j+1]=(vint)[j];
            j--;
        }
         (vint)[j+1]=temp;
    }
}

/*快速排序分类
按照temp的值将A中的值分为两部分
	第一部分小于temp
	第二部分大于等于temp
返回temp在A的下表+1的位置
*/ 
int Partition(vector<int> &A, int temp)
{
    int p=A.size()-1;
    int v ;
    int i=1;
    while(true)
    {
        while(true)
        {   
                if(i<p&&A[i]<temp)
                    ++i;
                else
                    break;
        }
        while(true)
        {
                if(A[p]>temp&&p>=0)
                    --p;
                else
                    break;
        }
        if(i<p)
        {   
            v =A[i];
            A[i]=A[p];
            A[p]=v;
        }
        else
            return (p);
    }   
     
}

int Select2( vector<int>& A,int k)
{
     
    if(A.size()<=r)
    {
        insertsort(A);
        return A[k-1];
    }
    vector<int> M ;
    for(int i=0;i<=(A.size()-5);i+=5)
    {
        if((i+5)>A.size())
            break;
        vector<int> m;
        m.push_back(A[i]);
        m.push_back(A[i+1]);
        m.push_back(A[i+2]);
        m.push_back(A[i+3]);
        m.push_back(A[i+4]);
        insertsort(m);
        (M).push_back((m)[2]);
    }
    int v ;
    if((A.size()/r)%2 ==1)
         v = Select2(M,(1+(A.size()/r)/2));
    else
        v = Select2(M,(A.size()/r)/2);
    int j = Partition(A,v) ;
	//cout<<"中间值下标为:"<<(j-1)<<"划分值为："<<v<<endl; 
    if(k== j)
        return v;
    else if(k<j)
        {
            vector<int> A1  ;
            for(int i=0;i!=j-1;++i)
                (A1).push_back(A[i]);
            return Select2(A1,k);// K比J小在A[0]-A[j-2]中求第K小元素               
        }
    else
        {
            vector<int> A2;
            for(int i=j;i!=(A).size();++i)
                (A2).push_back(A[i]);
            return Select2(A2,k-j);//K比J大，在A[j] --- A[A.size()-1]中求第K-J小元素。。
        }
     
         
}
int main()
{
    vector<int> A ,Aa;
    for(int i=0;i!=100;++i)
    {
        A.push_back((int)rand());
        Aa.push_back(A[i]);
    }       
    insertsort(Aa);
    cout<<"501个数中求第K小元素"<<endl; 
    cout<<"输入要找的第K小元素：";
    int k=4;
    for(int k=1;k!=A.size()+1;++k)
    {
        cout<<Select2(A,k)<<"==?"<<Aa[k-1]<<"插入排序求第K小元素，验证上述算法结果."<<k<<endl;
    }
    system("pause");
    return 0;
}
