use std::collections::LinkedList;

#[derive(Clone)] // Implementa o Clone para Entry
struct Entry {
    key: String,
    value: i32,
}

struct HashTable {
    buckets: Vec<LinkedList<Entry>>,
    size: usize,
}

impl HashTable {
    fn new(size_table: usize) -> Self {
        // Inicializa com listas vazias, não clonáveis
        Self {
            buckets: vec![LinkedList::new(); size_table],
            size: size_table,
        }
    }

    fn hash(&self, key: &str) -> usize {
        let mut hash_value: usize = 0;
        for c in key.chars() {
            hash_value = hash_value.wrapping_mul(31).wrapping_add(c as usize);
        }
        hash_value % self.size
    }

    fn put(&mut self, key: &str, value: i32) {
        let idx = self.hash(key);
        let bucket = &mut self.buckets[idx];

        for entry in bucket.iter_mut() {
            if entry.key == key {
                entry.value = value;
                return;
            }
        }

        bucket.push_back(Entry {
            key: key.to_string(),
            value,
        });
    }

    fn get(&self, key: &str) -> Option<i32> {
        let idx = self.hash(key);
        let bucket = &self.buckets[idx];

        for entry in bucket {
            if entry.key == key {
                return Some(entry.value);
            }
        }
        None
    }

    fn remove(&mut self, key: &str) {
        let idx = self.hash(key);
        let bucket = &mut self.buckets[idx];

        // Remoção manual do item
        let mut prev: Option<&mut Entry> = None;
        let mut to_remove = None;

        for entry in bucket.iter_mut() {
            if entry.key == key {
                to_remove = Some(entry);
                break;
            }
            prev = Some(entry);
        }

        if let Some(entry) = to_remove {
            if let Some(prev_entry) = prev {
                // Remover o item da lista
                *prev_entry = entry.clone(); // Agora Entry é clonável
            } else {
                // Se for o primeiro item, remove diretamente
                bucket.pop_front();
            }
        }
    }

    fn print(&self) {
        for (i, bucket) in self.buckets.iter().enumerate() {
            print!("Bucket {}: ", i + 1);
            for entry in bucket {
                print!("({}: {}) -> ", entry.key, entry.value);
            }
            println!("NULL");
        }
    }
}

fn main() {
    let mut table = HashTable::new(10);

    table.put("William", 21);
    table.put("Cesar", 26);
    table.put("Silva", 30);
    table.put("De", 34);
    table.put("Carvalho", 90);

    table.print();

    println!("\nBuscando valores:");
    println!("William: {:?}", table.get("William"));
    println!("Cesar: {:?}", table.get("Cesar"));
    println!("Silva: {:?}", table.get("Silva"));

    println!("\nRemovendo 'De'...");
    table.remove("De");

    table.print();
}
