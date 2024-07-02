// print all k window size element

void display(queue<int> q)
{
  while(!q.empty())
    {
      cout<<q.front()<<' ';
      q.pop();
    }
  cout<<endl;
}

void kWindow(vector<int> &arr,int k)
{
  queue<int> q;

  for(int i = 0 ; i<k-1;i++)
  {
     q.push(arr[i]); 
  }

  for(int i = k ; i<arr.size();i++)
  {
    q.push(arr[i]);
    display(q);
    q.pop();
  }
  
}
