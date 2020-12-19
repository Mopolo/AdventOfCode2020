use std::fmt;
use std::fmt::Formatter;

use crate::day5::range::Range;
use crate::day5::seat::Seat;
use crate::file::read_lines;

mod range;
mod seat;

pub fn run() {
    if let Ok(lines) = read_lines("./inputs/day5.txt") {
        let mut id: u128 = 0;

        for line in lines {
            if let Ok(val) = line {
                let s = Seat::find(val);

                println!("Seat: {}", s);

                let new_id = s.id();

                if new_id > id {
                    id = new_id;
                }
            }
        }

        println!("Id: {}", id);
    }
}
