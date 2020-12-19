use std::fmt;
use std::fmt::Formatter;

use crate::day5::range::Range;
use crate::day5::seat::Seat;
use crate::file::read_lines;
use std::collections::{HashMap, BTreeMap};

mod range;
mod seat;

pub fn run() {
    if let Ok(lines) = read_lines("./inputs/day5.txt") {
        let mut id: u16 = 0;
        let mut seats: Vec<u16> = Vec::new();

        for line in lines {
            if let Ok(val) = line {
                let s = Seat::find(val);

                seats.push(s.id());

                println!("Seat: {}", s.id());

                let new_id = s.id();

                if new_id > id {
                    id = new_id;
                }
            }
        }

        seats.sort();

        let min = seats.first().expect("No min ID") + 1;
        let max = seats.last().expect("No max ID") - 1;

        let mut my_id: u16 = 0;

        for number in min..max {
            if !seats.contains(&number)
                && seats.contains(&(number - 1))
                && seats.contains(&(number + 1))
            {
                my_id = number;
            }
        }

        println!("Id: {}", my_id);
    }
}
