#include <iostream>
#include <unordered_set>
#include <unordered_map>


using namespace std;

int main()
{
    srand(time(nullptr));
    unordered_set<char> hset;
    unordered_map<char, char> hmap;

    for (int i = 0; i < 50; i++)
    {
        char r = 97 + rand() % (122 - 98);
        hset.insert(r);
        hmap.emplace(r, r);
        cout << r << " ";
    }  
    cout << "\n===================\n";
        

    cout << hset.bucket_count() << "\n";

    auto hashfn = hmap.hash_function();

    for (auto it = hmap.begin(); it != hmap.end(); it++)
        cout << it->first << " "
             << it->second << " -> "
             << hmap.bucket(it->first)
             << hashfn(it->first)
             << "\n";

    cout << "\n\n";

    for (int i = 0; i < hmap.bucket_count(); i++)
    {
        cout << i << " backet:\n";
        for (auto it = hmap.begin(i); it != hmap.end(i); it++)
            cout << "\t[" << it->first<< ":" << it->second << "] hash: " << hmap.hash_function()(it->first) << " ";
        cout << "\n---------\n";
    }

}
