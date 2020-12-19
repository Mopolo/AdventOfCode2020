use std::fmt;
use std::fmt::Formatter;
use crate::day5::range::Range;

pub struct Seat {
    pub row: i8,
    pub column: i8,
}

impl fmt::Display for Seat {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        write!(f, "R{};C{};I{}", self.row, self.column, self.id())
    }
}

impl Seat {
    pub fn id(&self) -> u128 {
        let a = self.row as u128;
        let b = self.column as u128;

        a * 8 + b
    }

    pub fn find(input: String) -> Seat {
        let row_input: String = input.chars().take(7).collect();
        let column_input: String = input.chars().skip(7).collect();

        // println!("{} {} {}", input, row_input, column_input);

        let row = Seat::find_value(row_input, 0.0, 127.0, 'B');
        let column = Seat::find_value(column_input, 0.0, 7.0, 'R');

        Seat {
            row,
            column,
        }
    }

    fn find_value(input: String, mut min: f32, mut max: f32, up: char) -> i8 {
        let mut range = Range::new(min, max);

        for instruction in input.chars() {
            if instruction == up {
                range = range.upper_half();
            } else {
                range = range.lower_half();
            }

            // println!("{}: {} {}", input, instruction, range);
        }

        range.result() as i8
    }
}
