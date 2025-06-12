/*
 * @lc app=leetcode.cn id=13 lang=rust
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
impl Solution {
    pub fn char_to_int(c: char) -> i32{
        match(c){
            'I' => {return 1;},
            'V' => {return 5;},
            'X' => {return 10;},
            'L' => {return 50;},
            'C' => {return 100;},
            'D' => {return 500;},
            'M' => {return 1000;},
            _ => {return 0;}

        }
    }

    pub fn roman_to_int(s: String) -> i32 {
        let mut ans = 0;
        let len = s.len();

        for i in 0..len {
            if(i < len - 1){
                let (char1, char2) = (s.chars().nth(i).unwrap(), s.chars().nth(i+1).unwrap());
                if Self::char_to_int(char1) < Self::char_to_int(char2){
                    ans -= Self::char_to_int(char1);
                } else {
                    ans += Self::char_to_int(char1);
                }
            } else{
                ans += Self::char_to_int(s.chars().nth(i).unwrap());
            }
        }
            
        ans
    }
}
// @lc code=end

