#include<bits/stdc++.h>
using namespace std;
const int r = 5;

//���ٲ�������
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

/*�����������
����temp��ֵ��A�е�ֵ��Ϊ������
	��һ����С��temp
	�ڶ����ִ��ڵ���temp
����temp��A���±�+1��λ��
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
	//cout<<"�м�ֵ�±�Ϊ:"<<(j-1)<<"����ֵΪ��"<<v<<endl; 
    if(k== j)
        return v;
    else if(k<j)
        {
            vector<int> A1  ;
            for(int i=0;i!=j-1;++i)
                (A1).push_back(A[i]);
            return Select2(A1,k);// K��JС��A[0]-A[j-2]�����KСԪ��               
        }
    else
        {
            vector<int> A2;
            for(int i=j;i!=(A).size();++i)
                (A2).push_back(A[i]);
            return Select2(A2,k-j);//K��J����A[j] --- A[A.size()-1]�����K-JСԪ�ء���
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
    cout<<"501���������KСԪ��"<<endl; 
    cout<<"����Ҫ�ҵĵ�KСԪ�أ�";
    int k=4;
    for(int k=1;k!=A.size()+1;++k)
    {
        cout<<Select2(A,k)<<"==?"<<Aa[k-1]<<"�����������KСԪ�أ���֤�����㷨���."<<k<<endl;
    }
    system("pause");
    return 0;
}
