use std::str::Chars;

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
}
