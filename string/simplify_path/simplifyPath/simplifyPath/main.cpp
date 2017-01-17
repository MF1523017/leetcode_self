#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;
class Solution {
public:
	void split(string path)
	{
		string tmp;
		for (int i = 1; i<path.size(); ++i)
		{
			if ('/' == path[i])
			{
				if(!tmp.empty())
					_splitStrings.push_back(tmp);
				tmp.clear();
			}
			else
			{
				tmp += path[i];
			}
		}
		if (!tmp.empty())
			_splitStrings.push_back(tmp);
	}
	string simplifyPath(string path) {
		split(path);
		vector<string> _result;
		_result.push_back("/");
		for (auto folder : _splitStrings)
		{
			if (folder==".")
			{
				;//cout<<"nothing"<<endl;
			}
			else if (".." == folder)
			{
				if (_result.size()!=1) {
					_result.pop_back();
					_result.pop_back();
				}
			}
			else
			{
				_result.push_back(folder);
				_result.push_back("/");
			}
		}
		if(_result.size()!=1)
			_result.pop_back();
		string re;
		for (auto r : _result)
			re += r;
		return re;
	}
private:
	vector<string> _splitStrings;
};


int main(int argc, char **argv)
{

	Solution test;
	cout << test.simplifyPath("/...") << endl;
	return 0;
}