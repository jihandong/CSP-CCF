#include <bits/stdc++.h>
using namespace::std;
 
/*
	0-1 背包问题
	输入：
		products_count：商品的数量
		capacity：背包的容量
		weight_array：商品重量数组
		value_array：商品价格数组
		result：结果数组
*/
void knapsack(int products_count, int capacity, vector<int>& weight_array, vector<int>& value_array, vector<vector<int>>& result)
{
	for (int i = 1; i <= products_count; ++i)
	{
		for (int j = 1; j <= capacity; ++j)
		{
			if (weight_array[i] > j) // 当前背包的容量 j 放不下第 i 件商品时
			{
				result[i][j] = result[i - 1][j]; // 放弃第 i 件商品，拿第 i - 1 件商品
			}
			else
			{
				int value1 = result[i - 1][j - weight_array[i]] + value_array[i]; // 拿走第 i - 1件商品
				int value2 = result[i - 1][j]; // 不拿走第 i - 1 件商品
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
		//cout << "please input products count and knapsack's capacity: " << endl; // 输入商品数量和背包容量
		//cin >> products_count >> capacity;
		srand((int)time(0)); 	//随机数种子  
		capacity = products_count * 25;
		//cout << "please input weight array for " << products_count << " products" << endl;
		for (int i = 1; i <= products_count; ++i) // 循环输入每件商品的重量
		{
			int tmp;
			//cin >> tmp;
			tmp = ((unsigned) rand()) % 100 + 1; //随机生成重量1~100
			weight_array.push_back(tmp);
		}
		//cout << "please input value array for " << products_count << " products" << endl;
		for (int i = 1; i <= products_count; ++i) // 循环输入每件商品的价格
		{
			int tmp;
			//cin >> tmp;
			tmp = ((unsigned) rand()) % 100 + 1;	//随机生成价格 
			value_array.push_back(tmp);
		}
		vector<vector<int>> result(products_count + 1, vector<int>(capacity + 1, 0)); // 结果数组
		clock_t start, end;
		start = clock();
		knapsack(products_count, capacity, weight_array, value_array, result); // 调用动态规划算法
		end = clock();
		double endtime=(double)(end-start)/CLOCKS_PER_SEC;
		//cout << "knapsack result is " << result[products_count][capacity] << endl;
		//cout << "time cost is " << endtime << endl;
		cout << products_count << '\t' << endtime << endl;	//打印规模和用时 
	}
 
	return 0;
}
