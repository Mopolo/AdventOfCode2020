use crate::day6::people::Group;
use crate::common::file::read_lines;
use std::io::{Lines, BufReader};
use std::fs::File;

mod people;

fn handle(lines: Lines<BufReader<File>>) {
    let mut group_strings: Vec<String> = Vec::new();

    let mut total: usize = 0;

    for line_result in lines {
        let line = line_result.unwrap();

        println!("Line: {}", line);

        if line.len().gt(&0) {
            group_strings.push(line.clone());
        } else {
            total += Group::parse(group_strings.clone()).all_yeses();

            group_strings.clear();
        }
    }

    if group_strings.len() > 0 {
        total += Group::parse(group_strings.clone()).all_yeses();
    }

    println!("Total: {}", total);
}

pub fn run() {
    if let Ok(lines) = read_lines("./inputs/day6.txt") {
        handle(lines);
    }
}
