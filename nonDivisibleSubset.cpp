// Thomas Parker, April 27th, 2018
// "Non-Divisible Subeset" challenge
// https://www.hackerrank.com/challenges/non-divisible-subset/problem


//PRECONDITION:
//	Inputs: -Vector S containing distinct integers
// 		-Integer k
//   	Include: <vector>
//POSTCONDITION:
// 	Output:	-Size of the largest subset of S possible
// 		such that the sum of any two elements is not
//		divisible by k.
int nonDivisibleSubset(int k, std::vector<int> S){
	int *a = new int[k];			// a[i] holds amount of elements with %k = i
	int max(0);				// returned value

	for(int i = 0; i < k; i++){		// Initialize a[]
		a[i] = 0;
	}
	for(int j = 0; j < S.size(); j++){ 	// Compute and count all %k values
		a[S[j] % k]++;
	}

	if(a[0] > 0) max++;			// At most one element with %k=0 is allowed
	if(k%2 == 0 && a[k/2] > 0){		// At most one element with %k=k/2 if k is even
		a[k/2] = 1;
	}

	for(int p = 1; p <= k/2; p++){		// for "bad" pairs of %k, choose whichever
		if(a[p] > a[k-p]){		// is more popular to add to subset
			max+= a[p];
		}
		else{
			max+= a[k-p];
		}
	}
	delete [] a;			
	return max;
}
