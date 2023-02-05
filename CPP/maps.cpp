/*
 * Given two string list -> stringList, queries
 * Return a vector showing number of occurences of queries in stringList
 *
 * */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> findStrMatches(vector<string> stringList, vector<string> queries)
{
    vector<int> result;
    map<string, int> matchDict;
    unsigned int vecSize = stringList.size();
    unsigned int querySize = queries.size();

    for(int i=0; i <vecSize; i++) 
    {
        if (matchDict.count(stringList[i]) == 0)
        {
            matchDict[stringList[i]] = 1;
        }
        else
        {
            matchDict.at(stringList[i]) ++;
        }
    }

    // Map iterator
    map<string,int>::iterator itr;
    for(itr=matchDict.begin();itr!=matchDict.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }

    for(int i=0; i< querySize; i++)
    {
        if(matchDict.count(queries[i]) == 0)
        {
            result.push_back(0);
        }
        else
        {
            result.push_back(matchDict[queries[i]]);
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    
    vector<string> stringList;
    vector<string> queries;
    vector<int> numOfMatches;

    stringList.push_back("ab");
    stringList.push_back("ab");
    stringList.push_back("abc");

    queries.push_back("ab");
    queries.push_back("abc");
    queries.push_back("bc");

    vector<int> numofMatches = findStrMatches(stringList,queries);
    int vecSize = numofMatches.size();
    for (int i=0; i < vecSize; i++)
    {
        cout << numofMatches[i] << "\t";
    }
    cout << endl;

    return 0;
}

