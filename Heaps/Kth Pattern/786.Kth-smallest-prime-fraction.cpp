//Brute force with lambda Time Complexity - O(N^2 + NlogN)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       vector<vector<int>> pairs;
       int n = arr.size();
       
       for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            pairs.push_back({arr[i], arr[j]});
        }
       }

        sort(pairs.begin(), pairs.end(), [&](vector<int>& a, vector<int>& b) {
        double adouble = a[0]*1.0/a[1]*1.0;
        double bdouble = b[0]*1.0/b[1]*1.0;
        return adouble < bdouble;
      });

       return pairs[k-1];
    }
};

//Brute Force with separate comparator function
class Solution {
public:
// In this case, defining the compare function as static bool inside the class serves the purpose of encapsulating it within the class scope and making it accessible without needing an instance of the class. Here's why it's done this way:

// Encapsulation: By defining compare as a static member function inside the class, it is encapsulated within the class scope. This helps in organizing related functions and data members together, which is a fundamental principle of object-oriented programming.

// Access without an Instance: Since compare is a static member function, it can be accessed without needing an instance of the class. This can be beneficial in scenarios where you want to use the comparison function independently of any particular instance of the class.

// Compatibility with Standard Library Algorithms: When using std::sort, you need to provide a function pointer, function object, or lambda that defines the comparison logic. By defining compare as a static member function, it can be passed directly to std::sort without needing any additional context or instance.

// So, defining compare as a static bool member function inside the class provides encapsulation, accessibility without an instance, and compatibility with standard library algorithms like std::sort.

    static bool compare(vector<int>& a, vector<int>& b){
        double adouble = a[0]*1.0/a[1]*1.0;
        double bdouble = b[0]*1.0/b[1]*1.0;
        return adouble < bdouble;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       vector<vector<int>> pairs;
       int n = arr.size();
       
       for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            pairs.push_back({arr[i], arr[j]});
        }
       }

        sort(pairs.begin(), pairs.end(), compare);
//if there was no static prefix in compare function above line would look something like this

//  sort(pairs.begin(), pairs.end(),  [this](vector<int>& a, vector<int>& b) {
//             return compare(a, b);
//         });

// In the lambda expression [this](vector<int>& a, vector<int>& b) {...}, the [this] part captures the current instance of the class. This is done because the compare function is a non-static member function of the Solution class, and non-static member functions require an instance of the class to be called.

// Here's why [this] is used:

// Access to Member Functions and Variables: Since compare is a member function of the Solution class, it may need access to other member functions or variables of the class. By capturing this in the lambda, the lambda has access to all member functions and variables of the current instance of the class.

// Scope and Lifetime: By capturing this, the lambda ensures that it has access to the correct instance of the class even if it is used outside the context of the current member function (kthSmallestPrimeFraction). This is particularly useful if you plan to use the lambda in other member functions or store it for later use.

// Compatibility with Member Functions: Since compare is a member function of Solution, it needs to be called on an instance of Solution. Capturing this allows the lambda to call compare correctly on the current instance.

// So, capturing this in the lambda allows the lambda to use the compare function as if it were a regular member function of the class, maintaining access to the class's context and member variables.

       return pairs[k-1];
    }
};

//Heap Approach time complexity - O(N^2*log(k))
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double>> pq;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i+1; j < arr.size(); j++) {
                double div = (double) arr[i] / arr[j];
                pq.push({div, (double)arr[i], (double)arr[j]});
                if(pq.size() > k)
                    pq.pop();
            }
        }

        auto vec  = pq.top();
        vector<int> result(2);
        result[0] = vec[1], result[1] = vec[2];
        return result;
    }
};

//Min heap approach
//time complexity = N*logN + K*Logn, Space complexity = O(N)
typedef vector<double> V;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<V, vector<V>, greater<V>> pq;

        for(int i = 0; i < n; i++) pq.push({ 1.0 * arr[i]/arr[n-1], (double)i, (double)n-1});

        int smallest = 1;
        while(smallest < k){
            V vec = pq.top();
            pq.pop();

            int i = vec[1];
            int j = vec[2] - 1;
            pq.push({1.0 * arr[i]/arr[j], (double)i, (double)j});
            smallest++;
        }

        V vec = pq.top();
        int i = vec[1], j = vec[2];
        return {arr[i], arr[j]};
    }