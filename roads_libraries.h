// just to check 
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    unordered_set<int> seen;
    stack<int> q;
    int road_cost = 0;
    int lib_cost = 0;
    int start = 1;
    vector<int> *adj = new vector<int>[n+1];
    for(vector<int> x: cities)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    for (int i=1;i<=n;i++)
    {
        if(seen.find(i) == seen.end())
            {
            q.push(i);
            lib_cost += c_lib;
            }
        else 
            continue;
        while(!q.empty())
        {
            start = q.top();
            seen.insert(start);
            q.pop();
            for(int j : adj[start])
            {
                if(seen.find(j) == seen.end())
                {
                    seen.insert(j);
                    road_cost += c_road;
                    // cout<<"road"<<" "<<j<<endl;;
                    q.push(j);
                }
            }
        }
    }
    if (road_cost >= n*c_lib)
        {
            // cout<<long(n*c_lib);
        return long(n*c_lib);}
        // cout<<long(road_cost+lib_cost);
    return long(road_cost+lib_cost);

}