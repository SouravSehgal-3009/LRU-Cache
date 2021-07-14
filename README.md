# LRU-Cache
LRU Cache is a data structure which supports cache operations and uses Least Recently Used policy for working. 
It is implemented with STL containers- list (implementing Doubly Linked List) and unordered_map (implementing hash table).

**LRU Cache** supports following three operations in O(1) time.
1. Inserting key value pair in Cache implemented by function **insert_key_value(key, value)**
2. Get value of the key from cache implemented by function **getValue(key)**
3. Get Most Recently Used key implemented by function **most_recent_key()**

First, **LRU Cache instance** is created with a maximum size **maxSize**.
**Working of LRU Cache Operations**

**1. insert_key_value(key,pair)**

**Case 1: Given key is already present in the cache.** In this case function updates the value of key in the cache.

**Case 2: Given key is not present in the cache before** The new key is inserted in the front of list. If the cache size is already equal to maxSize, then the key which was not used recently i.e. key at last position of the list is removed from cache and then, new key is inserted in the front of list.

**2. getValue(key):**
The node address of key is returned if it exists in the cache otherwise NULL is returned.

**3. most_recent_key():**
Returns the Most Recently Used key from cache

