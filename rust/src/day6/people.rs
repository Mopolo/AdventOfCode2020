use std::str::Chars;
use std::collections::HashMap;
use std::ops::Add;

pub struct Group {
    pub people: Vec<Vec<char>>,
}

impl Group {
    pub fn parse(input: Vec<String>) -> Group {
        let mut people: Vec<Vec<char>> = Vec::new();

        for p in input {
            let mut chars: Vec<char> = Vec::new();

            for c in p.chars() {
                if !chars.contains(&c) {
                    chars.push(c.clone());
                }
            }

            people.push(chars);
        }

        Group {
            people
        }
    }

    pub fn yeses(&self) -> usize {
        let mut unique_chars: Vec<char> = Vec::new();

        for person in self.people.clone() {
            for c in person {
                if !unique_chars.contains(&c) {
                    unique_chars.push(c.clone());
                }
            }
        }

        unique_chars.len()
    }

    pub fn all_yeses(&self) -> usize {
        let mut chars: HashMap<char, usize> = HashMap::new();

        let people_quantity = self.people.clone().len();

        for person in self.people.clone() {
            for c in person {
                if !chars.contains_key(&c) {
                    chars.insert(c, 1);
                } else {
                    chars.insert(c, chars[&c] + 1);
                }

                // println!("Char {} : {}/{}", c, chars[&c], people_quantity);
            }
        }

        let mut quantity: usize = 0;

        for (c, q) in chars {
            println!("Char {} : {}/{}", c, q, people_quantity);

            if q == people_quantity {
                quantity += 1;
            }
        }

        quantity
    }
}
