/*
 * @lc app=leetcode id=419 lang=java
 *
 * [419] Battleships in a Board
 */

// @lc code=start
class Solution {
    public int countBattleships(char[][] board) {
        int count = 0;
        
        // traverse from left to right, top to bottom and look at each cell
        for(int row = 0; row < board.length; row++) {
            for(int col = 0; col < board[row].length; col++) {
                // only process cells that contains 'X' - a battleship
                if(board[row][col] == 'X') {
                    count += removeShip(board, row, col);
                }
            }
        }
        return count;
    }
    
	// This is a helper class that overwrite the cell that has 'X' with '.'
	// so that we won't see the battleship again.
    private int removeShip(char[][] board, int row, int col) {
        // get our constrains 
        int maxR = board.length;
        int maxC = board[0].length;
        
        // if the cell is valid 
        // i.e., it's within the boundary of the board
        if(row < maxR && col < maxC && row >= 0 && col >= 0) {
            // Now we check to see if it's a ship
            if(board[row][col] == 'X') {
			    System.out.print("[" + row + ", " + col + "] "); // Added print statement
                // if the cell is 'X', then we set it to '.' 
                // to indicate that we already saw it, and won't process it again
                board[row][col] = '.'; // set it to empty
                
                // check adjacent cells
                removeShip(board, row, col - 1);    // left cell
                removeShip(board, row, col + 1);    // right cell                
                removeShip(board, row + 1, col);    // top cell
                removeShip(board, row - 1, col);    // bottom cell
				
				System.out.println(); // Added print statement
				// Each ship's coordinate will be displayed in 1 line
				
                // once setting all cells to empty '.', we can return 1,
                // as there are no adjacent battleships per the problem description
                return 1;
            }
        }        
        // if it's out of bound, or not a battleShip spot
        return 0;        
    }
}
// @lc code=end

