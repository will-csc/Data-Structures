class HashTable:
    def __init__(self,size: int):
        self.nodes = [[] for i in range(size)]
        self.size = size
    
    def hash(self,key: str):
        hash_value = 0
        for c in key:
            hash_value = hash_value * 31 + ord(c)
        return hash_value % self.size

    def put(self,key: str, value: int):
        idx = self.hash(key)

        for i, (k,v) in enumerate(self.nodes[idx]):
            if k == key:
                self.nodes[idx][i] = (key,value)
                return
        self.nodes[idx].append((key,value))
    
    def get(self,key: str):
        idx = self.hash(key)

        for (k,v) in self.nodes[idx]:
            if k == key:
                return v
        
        print(f"Key {key} not found")
        return None

    def remove(self,key: str):
        idx = self.hash(key)

        for i,(k,v) in enumerate(self.nodes[idx]):
            if k == key:
                del self.nodes[idx][i]
    
    def print(self):
        for j, bucket in enumerate(self.nodes):
            print(f"Bucket {j+1}: [",end="")
            for k,v in bucket:
                print(f"({k}:{v}) -> ",end="")
            print("NULL ]")

Hash_Table = HashTable(5)
Hash_Table.put("William",21)
Hash_Table.put("Cesar",26)
Hash_Table.put("Silva",30)
Hash_Table.put("de",34)
Hash_Table.put("Carvalho",90)

Hash_Table.print()

