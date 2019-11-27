#include <bits/stdc++.h>
using namespace::std;
 
/*
	0-1 ��������
	���룺
		products_count����Ʒ������
		capacity������������
		weight_array����Ʒ��������
		value_array����Ʒ�۸�����
		result���������
*/
void knapsack(int products_count, int capacity, vector<int>& weight_array, vector<int>& value_array, vector<vector<int>>& result)
{
	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = 1; j <= capacity; ++j)
		{
			if (weight_array[i] > j) // ��ǰ���������� j �Ų��µ� i ����Ʒʱ
			{
				result[i][j] = result[i - 1][j]; // ������ i ����Ʒ���õ� i - 1 ����Ʒ
			}
			else
			{
				int value1 = result[i - 1][j - weight_array[i]] + value_array[i]; // ���ߵ� i - 1����Ʒ
				int value2 = result[i - 1][j]; // �����ߵ� i - 1 ����Ʒ
				if (value1 > value2)
				{
					result[i][j] = value1;
				}
				else
				{
					result[i][j] = value2;
				}
			}
		}
	}
}
 
int main()
{
 	int products_count, capacity;
	for(products_count = 500; products_count <= 20000; products_count += 500)
	{
		vector<int> weight_array(1, 0);
		vector<int> value_array(1, 0);
		//cout << endl<< "-----------------------------" << endl;
		//cout << "please input products count and knapsack's capacity: " << endl; // ������Ʒ�����ͱ�������
		//cin >> products_count >> capacity;
		srand((int)time(0)); 	//���������  
		capacity = products_count * 25;
		//cout << "please input weight array for " << products_count << " products" << endl;
		for (int i = 1; i <= products_count; ++i) // ѭ������ÿ����Ʒ������
		{
			int tmp;
			//cin >> tmp;
			tmp = ((unsigned) rand()) % 100 + 1; //�����������1~100
			weight_array.push_back(tmp);
		}
		//cout << "please input value array for " << products_count << " products" << endl;
		for (int i = 1; i <= products_count; ++i) // ѭ������ÿ����Ʒ�ļ۸�
		{
			int tmp;
			//cin >> tmp;
			tmp = ((unsigned) rand()) % 100 + 1;	//������ɼ۸� 
			value_array.push_back(tmp);
		}
		vector<vector<int>> result(products_count + 1, vector<int>(capacity + 1, 0)); // �������
		clock_t start, end;
		start = clock();
		knapsack(products_count, capacity, weight_array, value_array, result); // ���ö�̬�滮�㷨
		end = clock();
		double endtime=(double)(end-start)/CLOCKS_PER_SEC;
		//cout << "knapsack result is " << result[products_count][capacity] << endl;
		//cout << "time cost is " << endtime << endl;
		cout << products_count << '\t' << endtime << endl;	//��ӡ��ģ����ʱ 
	}
 
	return 0;
}
