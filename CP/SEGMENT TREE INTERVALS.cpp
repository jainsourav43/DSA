struct Node {
		int data;
		int best;
		int pri;
		int size;
		struct Node *left;
		struct Node *rig;
};

struct Node arr[400000];
struct Node *dummy;
struct Node *ptr = arr;
struct Node *root;

class Solution{
    public:	

	void init()
	{

        srand(time(NULL));
		ptr ->left = ptr ->rig = dummy;
		ptr ->pri = -1;
		ptr ->size = 0;
		ptr ->data = -1e9;
		ptr ->best = -1e9;
		root = dummy = ptr;
		ptr++;
	}

	void update(struct Node *A)
	{
		A ->size = A ->left ->size + A ->rig ->size + 1;
		A ->best = max(A ->data, max(A ->left ->best, A ->rig ->best));
	}

	struct Node *rot(struct Node *A, struct Node *B)
	{
		if(A ->left == B) {
			A ->left = B ->rig;
			B ->rig = A;
		} else {
			A ->rig = B ->left;
			B ->left = A;
		}
	
		update(A);
		update(B);
	
		return B;
	}

	struct Node *insert_tree(struct Node *root, int data)
	{
		if(root == dummy) {
			ptr ->data = data;
			ptr ->best = data;
			ptr ->pri = rand();
			ptr ->size = 1;
			ptr ->left = ptr ->rig = dummy;
			return ptr++;
		} else if(root ->data < data) {
			root ->rig = insert_tree(root ->rig, data);
			if(root ->rig ->pri > root ->pri) { //Need Rotation
				root = rot(root, root ->rig);
			}
		} else {
			root ->left = insert_tree(root ->left, data);
			if(root ->left ->pri > root ->pri) {//Need rotation
				root = rot(root, root ->left);
			}
		}
	
		update(root);
		return root;	
	}

	struct Node *remove(struct Node *root, int data) 
	{
		if(root != dummy) {
			if(root ->data > data) {

				root ->left = remove(root ->left, data);
			
			} else if(root ->data < data) {

				root ->rig = remove(root ->rig, data);
			
			} else {
			
				if(root ->left == dummy && root ->rig == dummy) {
					root = dummy;
					return root;
				}
			
				if(root ->left ->pri > root ->rig ->pri) {
					root = rot(root, root ->left);
				} else {
					root = rot(root, root ->rig);
				}
			
				if(root != dummy) {
					root = remove(root, data);
				} else {
					root ->left = dummy;
				}
			}
		}
		update(root);
		return root;
	}

	int Find(struct Node *root, int K)
	{
		if(root ->left ->size > K) 
			return Find(root ->left, K);
		else if(root ->left ->size < K)
			return Find(root ->rig, K - root ->left ->size - 1);
		return root ->data;
	}

	int Count(struct Node *root, int data)
	{
		if(root == dummy)
			return 0;
		
		if(root ->data > data) {
			return Count(root ->left, data);
		} else if(root ->data < data) {
			return root ->left ->size + Count(root ->rig, data) + 1;
		}
		return root ->left ->size;
	}

	bool find(struct Node *root, int data)
	{
		if(root == dummy)
			return false;
	
		if(root ->data > data) {
			return find(root ->left, data);
		} else if(root ->data < data) {
			return find(root ->rig, data);
		} else
			return root ->data == data;
	}

	void insert(int data)
	{
		root = insert_tree(root, data);
	}

	void delet(int data)
	{
		root = remove(root, data);
	}

	int FindKth(int K)
	{
		if(root ->size <= K) {
			return -1;
		} else {
			return Find(root, K);
		}
	}

	int Count_Element(int x)
	{
		return Count(root, x);
	}
	
    vector<int> order(vector<int> Heights, vector<int> InFronts) {
           
	    init();
            
	    int sz = Heights.size();
	   
            for(int i = 0; i < sz; ++i) {
	    	insert(i);
	    }
		
            vector<pair<int, int> > vec;
            for(int i = 0; i < sz; ++i) {
                vec.push_back(mpa(Heights[i], InFronts[i]));
            }
            sort(vec.begin(), vec.end());
            
            vector<int> Ans(sz, 0);

            for(int i = 0; i < sz; ++i) {
                int idx = FindKth(vec[i].second);
                Ans[idx] = vec[i].first;
                delet(idx);
            }

            return Ans;
    }
};
