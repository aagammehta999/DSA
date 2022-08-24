#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;

    // insert
    // pehla tarika
    pair<string, int> p = make_pair("aagam", 3);
    m.insert(p);

    // dusra tarika
    pair<string, int> pair2("Love", 2);
    m.insert(pair2);

    // teesra tarika
    m["mera"] = 1;
    m["mera"] = 2; // yha pr update hojayega
    // kisi bhi key ke liye duplicate entry nh hogi

    // count function use krte hai check krne ke liye koi key padhi hai ya nahi
    // agr key padhi hai toh return 1
    // agr key nh padhi hai toh return 0

    cout << m.count("love") << endl;

    // erase functioon se wo key erase hojati hai

    cout << m["mera"] << endl;
    cout << m.at("aagam") << endl;

    cout << m["unkonwnkey"] << endl; // ek entry ban jati hai 0 se initialize hoti hjai
    cout << m.at("unkonwnkey") << endl;

    // pura map kese access krna hai

    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    // iterator ka usee krte hai

    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())

    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
}
//unordered_map map lkoi order nh rehta tc:- O(1)
//map same order mai aata jese insert kara ho:-O(log(n))