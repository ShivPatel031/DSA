// Covid Spread GFG

// Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
// Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
// 0: Empty ward
// 1: Cells have uninfected patients
// 2: Cells have infected patients

// An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

// Example 1:

// Input:
// 3 5
// 2 1 0 2 1
// 1 0 1 2 1
// 1 0 0 2 1 
// Output:
// 2
// Explanation:
// Patients at positions {0,0}, {0, 3}, {1, 3}
// and {2, 3} will infect patient at {0, 1}, 
// {1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
// unit time. And, during 2nd unit time, patient at 
// {1, 0} will get infected and will infect patient 
// at {2, 0}. Hence, total 2 unit of time is
// required to infect all patients.

// Example 2:

// Input:
// 3 5
// 2 1 0 2 1
// 0 0 1 2 1
// 1 0 0 2 1
// Output:
// -1
// Explanation:
// All patients will not be infected.
 
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function helpaterp() which takes a 2-D Matrix hospital as input parameter and returns the minimum units of time in which all patients will be infected or -1 if it is impossible.

// Constraints:
// 1 ≤ R,C ≤ 1000
// 0 ≤ mat[i][j] ≤ 2

int row[4]={-1,1,0,0};
int column[4] = {0,0,-1,1};
int r;
int c;

bool valid(int i,int j)
{
    return i>=0 && i<r && j>=0 && j<c;
}

int helpaterp(vector<vector<int>> hospital)
{
    queue<pair<int,int> > q;
    
    for(int i=0; i < hospital.size(); i++)
    {
        for(int j=0; j<hospital[i].size(); j++)
        {
            if(hospital[i][j]==2) q.push(make_pair(i,j));
        }
    }
    
    int count,t=0;
    r=hospital.size();
    c=hospital[0].size();
    
    while(!q.empty())
    {
        count = q.size();
        t++;
        
        while(count--)
        {
            pair<int,int> location=q.front();
            q.pop();
         
            // if(location.first-1>=0 and hospital[location.first-1][location.second]==1)
            // {
            //     hospital[location.first-1][location.second]=2;
            //     q.push(make_pair(location.first-1,location.second));
            // }
            
            // if(location.first+1<hospital.size() and hospital[location.first+1][location.second]==1)
            // {
            //     hospital[location.first+1][location.second]=2;
            //     q.push(make_pair(location.first+1,location.second));
            // }
            
            // if(location.second-1>=0 and hospital[location.first][location.second-1]==1)
            // {
            //     hospital[location.first][location.second-1]=2;
            //     q.push(make_pair(location.first,location.second-1));
            // }
            
            // if(location.second+1<hospital[location.first].size() and hospital[location.first][location.second+1]==1)
            // {
            //     hospital[location.first][location.second+1]=2;
            //     q.push(make_pair(location.first,location.second+1));
            // }

         // we can use this code instend of above 4 condition
             for(int i= 0 ; i <4;i++)
            {
                if(valid(location.first + row[i],location.second+column[i]) && hospital[location.first+row[i]][location.second+column[i]]==1)
                {
                    hospital[location.first+row[i]][location.second+column[i]]=2;
                    q.push(make_pair(location.first+row[i],location.second+column[i]));
                }
            }
        }
    }
    
    for(int i=0; i < hospital.size(); i++)
    {
        for(int j=0; j<hospital[i].size(); j++)
        {
            if(hospital[i][j]==1) return -1;
        }
    }
    
    return t-1;
}
