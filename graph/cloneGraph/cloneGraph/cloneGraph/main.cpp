#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using std::unordered_map;
using std::vector;
using std::queue;
using std::cout;
using std::endl;
struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode*>neighbors;
	UndirectedGraphNode(int x) :label(x) {};
};
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return nullptr;
		queue<UndirectedGraphNode *> q;
		UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
		_mp[node] = copy;
		q.push(node);
		while (!q.empty())
		{
			UndirectedGraphNode * tmp = q.front();
			q.pop();
			for (auto n : tmp->neighbors)
			{
				if (_mp.find(n) == _mp.end()) {
					UndirectedGraphNode *neigh_copy = new UndirectedGraphNode(n->label);
					_mp[n] = neigh_copy;
					q.push(n);
				}
				_mp[tmp]->neighbors.push_back(_mp[n]);
			}
		}
		return copy;
	}
private:
	unordered_map<UndirectedGraphNode *, UndirectedGraphNode *>_mp;
};
int main(int argc, char **argv)
{
	UndirectedGraphNode * test = new UndirectedGraphNode(0);
	for(int i=1;i<3;++i)
		test->neighbors.push_back(new UndirectedGraphNode(i));
	Solution s;
	UndirectedGraphNode *p=s.cloneGraph(test);

	return 0;
}