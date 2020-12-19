use std::fmt;
use std::fmt::Formatter;

pub struct Range {
    min: f32,
    max: f32,
}

impl Range {
    pub fn new(min: f32, max: f32) -> Range {
        Range {min, max}
    }

    pub fn lower_half(&self) -> Range {
        Range {
            min: self.min,
            max: self.max - self.middle(),
        }
    }

    pub fn upper_half(&self) -> Range {
        Range {
            min: self.min + self.middle(),
            max: self.max,
        }
    }

    pub fn result(&self) -> f32 {
        if self.min != self.max {
            panic!("Range {} is not over", self)
        }

        self.min
    }

    fn middle(&self) -> f32 {
        ((self.max - self.min) / 2.0).ceil()
    }
}

impl fmt::Display for Range {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        write!(f, "{};{}", self.min, self.max)
    }
}
