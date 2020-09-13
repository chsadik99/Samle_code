// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to obtain the
// middle index of the range
int getMid(int s, int e)
{
	return s + (e - s) / 2;
}

/* Recursive function to get the sum of 
values in the given range from the array. 
The following are parameters for this 
function. 

	st	 -> Pointer to segment tree 

	node	 -> Index of current node in 
				the segment tree

	ss & se -> Starting and ending indexes 
			of the segment represented 
			by current node, i.e., st[node] 

	l & r -> Starting and ending indexes 
			of range query */
int MaxUtil(int* st, int ss, int se, int l,
			int r, int node)
{
	// If the segment of this node lies
	// completely within the given range
	if (l <= ss && r >= se)

		// Return maximum in the segment
		return st[node];

	// If the segment of this node lies
	// outside the given range
	if (se < l || ss > r)
		return -1;

	// If segment of this node lies
	// partially in the given range
	int mid = getMid(ss, se);

	return max(MaxUtil(st, ss, mid, l, r,
					2 * node + 1),
			MaxUtil(st, mid + 1, se, l,
					r, 2 * node + 2));
}

// Function to return the maximum in the
// range from [l, r]
int getMax(int* st, int n, int l, int r)
{
	// Check for erroneous input values
	if (l < 0 || r > n - 1 || l > r) {
		printf("Invalid Input");
		return -1;
	}

	return MaxUtil(st, 0, n - 1, l, r, 0);
}

// Function to construct Segment Tree
// for the subarray [ss..se]
int constructSTUtil(int arr[], int ss, int se,
					int* st, int si)
{
	// For a single element
	if (ss == se) {
		st[si] = arr[ss];
		return arr[ss];
	}

	// Otherwise
	int mid = getMid(ss, se);

	// Recur for left subtree
	st[si] = max(constructSTUtil(arr, ss, mid, st,
								si * 2 + 1),

				// Recur for right subtree
				constructSTUtil(arr, mid + 1, se,
								st, si * 2 + 2));

	return st[si];
}

// Function to construct Segment Tree from
// the given array
int* constructST(int arr[], int n)
{
	// Height of Segment Tree
	int x = (int)(ceil(log2(n)));

	// Maximum size of Segment Tree
	int max_size = 2 * (int)pow(2, x) - 1;

	// Allocate memory
	int* st = new int[max_size];

	// Fill the allocated memory
	constructSTUtil(arr, 0, n - 1, st, 0);

	// Return the constructed Segment Tree
	return st;
}

// Driver Code
int main()
{
	int arr[] = { 5, 2, 3, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Build the Segment Tree
	// from the given array
	int* st = constructST(arr, n);

	vector<vector<int> > Q = { { 1, 3 }, { 0, 2 } };
	for (int i = 0; i < Q.size(); i++) {

		int max = getMax(st, n, Q[i][0], Q[i][1]);
		int ok = 0;
		for (int i = 30; i >= 0; i--) {
			if ((max & (1 << i)) != 0)
				ok = 1;

			if (!ok)
				continue;

			max |= (1 << i);
		}

		cout << max << " ";
	}

	return 0;
}
