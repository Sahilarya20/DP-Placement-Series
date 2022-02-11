// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// memoization
int f(int day,int last,vector<vector<int> >&points,vector<vector<int> >&dp ){
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last)
                maxi=max(maxi,points[0][task]);
        	}
       return maxi;
    }
    if(dp[day][last]!=-1)return dp[day][last];
    int maxi=0;
     for(int task=0;task<3;task++){
            if(task!=last)
              { int p=points[day][task]+f(day-1,task,points,dp);
        		 maxi=max(maxi,p);}
        	}
    return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int> >dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}

//......................................tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int> >dp(n,vector<int>(4,0));
//     return f(n-1,3,points,dp);
    	  dp[0][0] = max(points[0][1], points[0][2]);
          dp[0][1] = max(points[0][0], points[0][2]);
          dp[0][2] = max(points[0][0], points[0][1]);
          dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    	for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                dp[day][last]=0;
                for(int task=0;task<3;task++){
                    if(task!=last){
                        int p=points[day][task]+dp[day-1][task];
                        dp[day][last]=max(dp[day][last],p);
                    } 
                }
            }
        }
    return dp[n-1][3];
        }

        //.................................Space optimization

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>prev(4,0);
//     return f(n-1,3,points,dp);
    	  prev[0] = max(points[0][1], points[0][2]);
          prev[1] = max(points[0][0], points[0][2]);
          prev[2] = max(points[0][0], points[0][1]);
          prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    	for(int day=1;day<n;day++){
            vector<int> temp(4,0);
            for(int last=0;last<4;last++){
                temp[last]=0;
                for(int task=0;task<3;task++){
                    if(task!=last){
                       temp[last]=max(temp[last],points[day][task]+prev[task]);
                    } 
                }
            }
            prev=temp;
        }
    return prev[3];
        }
    
