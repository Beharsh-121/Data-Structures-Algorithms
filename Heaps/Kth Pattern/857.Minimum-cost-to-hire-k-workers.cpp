//brute force time complexity - O(), 
//space complexity - O()
 double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
       int n = quality.size();

       double result = DBL_MAX; 

       for(int manager = 0; manager < n; manager++){//O(n)
          double managerRatio = 1.0 * min_wage[manager]/quality[manager];
          vector<double> group;
          for(int worker = 0; worker < n; worker++){//O(n)
            double worker_wage = managerRatio * quality[worker];
            if(worker_wage >= min_wage[worker]) group.push_back(worker_wage);;
          }
          if(group.size() < k) continue;
          priority_queue<double, vector<double>> pq;
          double sum_wage = 0;
          for(double &wage: group){//O(k * logk)
            sum_wage += wage;
            pq.push(wage);
            if(pq.size() > k){
                sum_wage -= pq.top();
                pq.pop();
            }
          }
          result = min(result, sum_wage);
       }
    return result;
    }
//Improved brute force time complexity same as before in worst case scenario
  double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();
        double result = DBL_MAX;

        vector<pair<double,int>> worker_ratio(n);
        for(int worker = 0; worker < n; worker++) worker_ratio[worker] = make_pair((double) min_wage[worker]/quality[worker], quality[worker]);

        sort(worker_ratio.begin(), worker_ratio.end());//O(nlogn)

        for(int manager = k-1; manager < n; manager++){//O(n)
            double managerRatio = worker_ratio[manager].first;
            vector<double> group;
            for(int worker = 0; worker <= manager; worker++){//O(n)
                double worker_wage = managerRatio * worker_ratio[worker].second;
                group.push_back(worker_wage);
            }
            priority_queue<double, vector<double>> pq;
            double sum_wage = 0;

            for(double &wage: group){//O(k*logk)
                sum_wage += wage;
                pq.push(wage);

                if(pq.size() > k){
                    sum_wage -= pq.top();
                    pq.pop();
                }
            }
            result = min(result, sum_wage);
        }
        return result;
  }

//Optimal Approach
//Time complexity calculate yourself
double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();

        vector<pair<double, int>> worker_ratio(n);
        for(int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair((double)min_wage[worker]/quality[worker], quality[worker]);
        }
        sort(begin(worker_ratio), end(worker_ratio));

        priority_queue<int, vector<int>> pq;
        
        double sum_quality = 0;
        for(int i = 0; i < k; i++) { //O(klogk)
            pq.push(worker_ratio[i].second); //push all qualities in max-heap
            sum_quality += worker_ratio[i].second; //Find sum of qualities
        }

        double managerRatio = worker_ratio[k-1].first; 
        double result       = managerRatio * sum_quality;

        for(int manager = k; manager < n; manager++) {//O(n)
            
            managerRatio = worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second); //push all qualities in max-heap
            sum_quality += worker_ratio[manager].second; //Find sum of qualities

            if(pq.size() > k) {//log(k)
                sum_quality -= pq.top();
                pq.pop();
            }

            result = min(result, managerRatio*sum_quality);

        }

        return result;
    }