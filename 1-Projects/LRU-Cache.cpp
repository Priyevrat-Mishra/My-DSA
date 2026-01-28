#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll; 
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        int value = it->second;

        // Move accessed node to front
        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        } 
        else if (dll.size() == capacity) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        dll.push_front({key, value});
        mp[key] = dll.begin();
    }

    void display() {
        cout << "Cache (MRU -> LRU): ";
        for (auto &p : dll) {
            cout << "[" << p.first << ":" << p.second << "] ";
        }
        cout << endl;
    }
};

int main() {
    int cap;
    cout << "Enter cache capacity: ";
    cin >> cap;

    LRUCache cache(cap);

    while (true) {
        cout << "\n1. Put\n2. Get\n3. Display Cache\n4. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int key, value;
            cout << "Enter key and value: ";
            cin >> key >> value;
            cache.put(key, value);
            cout << "Inserted (" << key << ", " << value << ")\n";
        }
        else if (choice == 2) {
            int key;
            cout << "Enter key: ";
            cin >> key;
            int res = cache.get(key);
            if (res == -1)
                cout << "Key not found\n";
            else
                cout << "Value = " << res << endl;
        }
        else if (choice == 3) {
            cache.display();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
