#include<vector>
#include<utility>
typedef std::vector<std::vector<int> > Table;
typedef std::pair<int, std::vector<int> > Result;       //A pair of an optimal value and its corrisponding solution vector

Result changeslow(const int &A, const std::vector<int> &coins);
Result changegreedy(const int &A, const std::vector<int> &coins);
Result changedp(const int &A, const std::vector<int> &coins);

template<typename T>
void printVector(std::vector<T> v, const char *sep){
    copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, sep));
    std::cout<<"\n";
}
