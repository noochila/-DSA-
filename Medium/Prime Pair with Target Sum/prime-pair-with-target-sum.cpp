//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> prime(n + 1, true); // Create a boolean array "prime[0..n]" and initialize all entries as true
    prime[0] = prime[1] = false; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= n; ++p) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p]) {
            // Updating all multiples of p to false as they are not primes
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Collecting all prime numbers
    vector<int> prime_numbers;
    for (int p = 2; p <= n; ++p) {
        if (prime[p]) {
            prime_numbers.push_back(p);
        }
    }

    return prime_numbers;
}
    vector<int> getPrimes(int n) {
       
        vector<int> primes=sieve_of_eratosthenes(n);
        
        int i=0;
        int j=primes.size()-1;
        
        while(i<=j)
        {
            if(primes[i]+primes[j]<n)
            {
                i++;
            }else if(primes[i]+primes[j]>n)
            j--;
            else return {primes[i],primes[j]};
            
        }
        
        return {-1,-1};

        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends