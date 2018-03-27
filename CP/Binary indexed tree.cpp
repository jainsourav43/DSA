void update(vector<int>& BIT,int index,int delta){
    while(index <= BIT.size()){
        BIT[index] += delta;
        index += (index & (-index));
    }
    return;
}
int findEmptyPosition(vector<int>& BIT,int index){
    int sum = 0;
    while(index > 0){
        sum += BIT[index];
        index -= (index & (-index));
    }
    return sum;
}
vector<int> Solution::order(vector<int> &h, vector<int> &f) {
    vector<pair<int,int>> arr;
    for(int i = 0; i < h.size(); i++){
        pair<int,int> temp(h[i],f[i]);
        arr.push_back(temp);
    }
    
    sort(arr.begin(),arr.end());
    
    vector<int> BIT(h.size()+1,0);
    for(int i = 1; i <= BIT.size();i++){
        update(BIT,i,1);
    }
    vector<int> res(h.size(),INT_MIN);
    //cout<<findEmptyPosition(BIT,4);
    for(int i = 0; i < arr.size(); i++){
        int low = 0,high = h.size()-1;
        int pos = arr[i].second+1;
        int mid = low + (high-low)/2;
        int avilable = findEmptyPosition(BIT,mid+1);//cout<<arr[i].first << " " <<mid <<" " << pos<<" "<<avilable<<"|";
        while(low <= high){
            if(pos == avilable && res[mid] == INT_MIN){
                res[mid] = arr[i].first;
                update(BIT,mid+1,-1);
                break;
            }
            else if(pos <= avilable){
                high = mid-1;
            }
            else{
                low = mid +1;
                //pos = pos - avilable;
            }
            mid = low + (high - low) / 2;
            avilable = findEmptyPosition(BIT,mid+1);//cout<<arr[i].first << " "<<mid<<" "<<pos<<" "<<avilable<<"|";
        }
    }
   //BIT.clear();
    return res;
}

