#include <iostream>
#include <stack>

#define maxK 10010
#define Testcase 5

using namespace std;

void Flip(int arr[], int left, int right)
{
	stack <int> s;
	
	for (int i = left; i <= right; i++)
	{
		int k = -1 * arr[i];
		s.push(k);
	}
	
	while (!s.empty())
	{
		arr[left++] = s.top();
		s.pop();
	}
}

int Bungeo_ppang(int arr[], int begin, int end, int flip_count)
{
	int left = 0;
	for (int i = begin; i <= end; i++)
	{
		if (arr[i] != i)
		{
			left = i;
			break;
		}
	}
	
	int right = 0;
	for (int i = end; i >= begin; i--)
	{
		if (arr[i] != i)
		{
			right = i;
			break;
		}
	}
	
	if (left == 0 || right == 0) 
		return flip_count;
	
	if (left == right) 
		return flip_count + 1;
	
	
	for (int i = left; i <= right; i++)
	{
		if (arr[i] == (left * -1))
		{
			Flip(arr, left, i);
			return Bungeo_ppang(arr, left, right, flip_count + 1);
		}
		
		if (arr[i] == (right * -1))
		{
			Flip(arr, i, right);
			return Bungeo_ppang(arr, left, right, flip_count + 1);
		}
	}
	
	return 3;
}

int main(void)
{
	int K;
	int arr[maxK];
	
	scanf("%d", &K);
	
	for (int t = 0; t < Testcase; t++)
	{
		for (int i = 1; i <= K; i++)
			scanf("%d", &arr[i]);
		
		int ans = Bungeo_ppang(arr, 1, K, 0);
		
		if (ans == 1) cout << "one" << endl;
		if (ans == 2) cout << "two" << endl;
		if (ans >= 3) cout << "over" << endl;
	}
	
 	return 0;
}

