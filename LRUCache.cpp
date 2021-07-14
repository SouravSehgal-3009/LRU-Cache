/*Implementation of LRU Cache with help of STL */

#include <bits/stdc++.h>
using namespace std;

class Node       //Class Node has been created
{
public:
    string key;
    int value;
    Node (string key, int value)
    {
        this->key=key;
        this->value=value;
    }
};

class LRUCache
{
private:
    int maxSize=1;
    list<Node> table;
    unordered_map<string, list<Node>::iterator> hashtable;
public:
    LRUCache(int maxSize)
    {
        if (maxSize>=1) this->maxSize=maxSize;
    }

    void insert_Key_Value(string key,int value)  //Insertion in Cache
    {
        if (hashtable.count(key)!=0)
        {
            auto it=hashtable[key];
            it->value=value;
            cout<<"Cache Hit...."<<endl;
        }
        else
        {
            if (table.size()==maxSize)
            {
                Node it=table.back();
                hashtable.erase(it.key);
                table.pop_back();
            }
            Node n(key, value);
            table.push_front(n);
            hashtable[key]=table.begin();
            cout<<"Cache Miss...."<<endl;
            
        }
    }

    int *getValue(string key)     //To get value of key from cache
    {
        if (hashtable.count(key)!=0)
        {
            auto it=hashtable[key];
            table.push_front(*it);
            table.erase(it);
            hashtable[key]=table.begin();
            cout<<"Cache Hit...."<<endl;
            return &table.begin()->value;
        }
        return NULL;
    }

    string most_recent_key()      //To get most recently used key from cache
    {
        return table.front().key;
    }

};

int main()
{
    cout<<"Welcome, You are going to see implementation of my Data Structure LRU Cache"<<endl;
    int cacheSize, choice, value;
    string key;
    int *result;
    cout<<"Please enter the maximum size of Cache you want to set (It should be non negative and greater than 0): ";
    cin>>cacheSize;
    LRUCache Cache1(cacheSize);
    cout<<"***Welocome to cache memory Cache1***"<<endl;
    do
    {
        cout<<"\tSelect one option below "<<endl;
        cout<<"\t1.) Insert a key value pair in Cache1"<<endl;
        cout<<"\t2.) Get value of a key from Cache1"<<endl;
        cout<<"\t3.) Display the most recently used key from Cache1"<<endl;
        cout<<"\t4.) Quit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter the key. (string): ";
                cin>>key;
                cout<<"Enter the value (integer) ";
                cin>>value;
                Cache1.insert_Key_Value(key,value);
                cout<<endl;
                break;
            case 2:
                cout<<"\nEnter the key whose value you want (string): ";
                cin>>key;
                result=Cache1.getValue(key);
                if (result==NULL)
                {
                    cout<<key<<" does not exist in Cache1"<<endl;
                }
                else
                {
                    cout<<"Value of "<<key<<" is: "<<*result<<endl;
                }
                cout<<endl;
                break;
            case 3:
                cout<<"\nMost Recently Used Key is: "<<Cache1.most_recent_key()<<endl;
                cout<<endl;
                break;
            case 4:
                break;
            default:
                cout<<"\nEnter a valid choice"<<endl;
                exit(0);
        }
    } while (choice!=4);
}