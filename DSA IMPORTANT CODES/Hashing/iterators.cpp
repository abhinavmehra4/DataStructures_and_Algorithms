 #include<iostream>
 #include<string>
 #include<unordered_map>
 #include<vector>
 using namespace std;

 int main()
 {
    unordered_map<string,int> ourmap;

    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;
    ourmap["abc6"] = 7;

    unordered_map<string,int>::iterator it = ourmap.begin();
    while(it!=ourmap.end())
    {
        cout<<"Key:"<<it->first<<" Value:"<<it->second<<endl;
        it++;
    }
    //sicne we used an unordered map, the values will get printed in a random order

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int>:: iterator it1 = v.begin();
    while(it1!=v.end())
    {
        cout<<*it1<<endl; //how to use iterators of vector datatype. Unlike unordered maps, thesse arent random, but from start to end
        it1++;
    }
    return 0;
 }