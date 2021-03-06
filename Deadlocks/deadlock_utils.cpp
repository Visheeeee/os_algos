#include "deadlock_utils.h"

void read_vec(std::vector<int>& v, int n)
{
    int temp;
    for(int i=0; i<n; ++i)
    {
        std::cin>>temp;
        v.push_back(temp);
    }
}

void read_2D(std::vector<std::vector<int>>& v, int r, int c)
{
    std::vector<int> temp1;
    int temp;
    for(int i=0; i<r; ++i)
    {
        for(int j=0; j<c; ++j)
        {
            std::cin>>temp;
            temp1.push_back(temp);
        }
        v.push_back(temp1);
        temp1.clear();
    }
}

void add_vecs(std::vector<int>& v1, std::vector<int>& v2)
{
    for(int i=0; i<v1.size(); ++i)
        v1[i] += v2[i];
}

void subt_vecs(std::vector<int>& v1, std::vector<int>& v2)
{
    for(int i=0; i<v1.size(); ++i)
        v1[i] -= v2[i];
}

bool iszero(std::vector<int>& v)
{
    for(int i=0; i<v.size(); ++i)
    {
        if(v[i] != 0)
            return false;
    }
    return true;
}

bool compare_vec(std::vector<int>& v1, std::vector<int>& v2)
{
    int n = v1.size();
    //int flag = 0;
    for(int i=0; i<n; ++i)
    {
        if(v1[i] > v2[i])
            return false;
    }
    return true;
}

std::vector<int> find_index(std::vector<bool>& finish, std::vector<std::vector<int>>& vec, std::vector<int>& work)
{
    std::set<int> s1, s2;
    for(int i=0; i<vec.size(); ++i)
    {
        if(compare_vec(vec[i], work))
            s1.insert(i);
    }
    for(int i=0; i<finish.size(); ++i)
    {
        if(finish[i] == false)
           s2.insert(i);
    }
    std::vector<int> result(work.size());
    std::vector<int>::iterator it = std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), result.begin());
    result.resize(it - result.begin());
    return result;
}